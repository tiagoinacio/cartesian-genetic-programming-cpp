// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "include/algorithm.h"
#include "include/fitness_args.h"
#include "include/gene_type.h"
#include "include/genotype.h"
#include "include/parameter.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

template <typename T>
class EvolutionaryAlgorithm : public Algorithm {
 public:
    virtual ~EvolutionaryAlgorithm() {
    }

    EvolutionaryAlgorithm(std::shared_ptr<cgp::Configuration> configuration,
        std::shared_ptr<cgp::State> state, std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type,
        std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters,
        std::vector<std::function<T(std::vector<T>)> > instruction_set,
        std::function<double(cgp::FitnessArgs<T>)> fitness_function)
        : configuration_(configuration),
          state_(state),
          size_(size),
          gene_type_(gene_type),
          parameters_(parameters),
          instruction_set_(instruction_set),
          fitness_function_(fitness_function) {
        srand(time(NULL));
    }

    virtual void run() {
        evolutionaryLoop_();
    }

 private:
    EvolutionaryAlgorithm();

    bool compareSolutions(double a, double b, std::string fitness_operator) {
        if (fitness_operator == "<=") {
            return a <= b;
        }
        if (fitness_operator == ">=") {
            return a >= b;
        }
        if (fitness_operator == ">") {
            return a > b;
        }
        return a < b;
    }

    void generation(int limit) {
        for (int i = 0; i <= limit; ++i) {
            cgp::Genotype<T> l_genotype;
            l_genotype.create(state_, configuration_, size_, gene_type_,
                instruction_set_, parameters_, fitness_function_);
            if (compareSolutions(genotype_.fitness(), l_genotype.fitness(),
                    configuration_->comparisonOperator())) {
                genotype_ = l_genotype;
            }
        }
    }

    void evolutionaryLoop_() {
        std::vector<T> a;
        a.push_back(2);
        a.push_back(3);
        instruction_set_[0](a);
        genotype_.create(state_, configuration_, size_, gene_type_,
            instruction_set_, parameters_, fitness_function_);

        generation(size_->offspring() - 1);

        std::cout << "# starting evolutionary loop" << std::endl;
        while (state_->run() < size_->runs()) {
            std::cout << "# starting run " << state_->run() << std::endl;
            while (state_->generation() < size_->generations()) {
                std::cout << "# starting generation " << state_->generation()
                          << std::endl;
                state_->setGeneration(state_->generation() + 1);
                for (int i = 0; i < size_->offspring(); ++i) {
                    cgp::Genotype<T> l_genotype;
                    l_genotype.create(genotype_.genes(), state_, configuration_,
                        size_, gene_type_, instruction_set_, parameters_,
                        fitness_function_);
                    l_genotype.mutation();
                    if (compareSolutions(genotype_.fitness(),
                            l_genotype.fitness(),
                            configuration_->comparisonOperator())) {
                        genotype_.create(l_genotype.genes(), state_,
                            configuration_, size_, gene_type_, instruction_set_,
                            parameters_, fitness_function_);
                    }
                }
            }
            state_->setGeneration(0);
            state_->setRun(state_->run() + 1);
        }
    }

    cgp::Genotype<T> genotype_;
    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::State> state_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::GeneType> gene_type_;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::vector<std::function<T(std::vector<T>)> > instruction_set_;
    std::function<double(cgp::FitnessArgs<T>)> fitness_function_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_
