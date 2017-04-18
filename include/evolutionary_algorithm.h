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
#include "include/logger.h"
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
          fitness_function_(fitness_function),
          LOG(&std::cout, false, configuration->debug()) {
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

    void new_generation() {
        for (int i = 0; i <= size_->offspring() - 1; ++i) {
            cgp::Genotype<T> m_genotype_;
            m_genotype_.create(state_, configuration_, size_, gene_type_,
                instruction_set_, parameters_, fitness_function_);
            if (compareSolutions(m_genotype_.fitness(), f_genotype_.fitness(),
                    configuration_->comparisonOperator())) {
                f_genotype_ = m_genotype_;
            }
        }
    }

    void evolutionaryLoop_() {
        f_genotype_.create(state_, configuration_, size_, gene_type_,
            instruction_set_, parameters_, fitness_function_);

        new_generation();

        LOG << "# starting evolutionary loop\n";
        while (state_->run() < size_->runs()) {
            LOG << "# starting run " << state_->run() << "\n";
            while (state_->generation() < size_->generations()) {
                for (int i = 0; i < size_->offspring(); ++i) {
                    cgp::Genotype<T> m_genotype_;
                    m_genotype_ = f_genotype_;
                    m_genotype_.mutation();
                    if (compareSolutions(m_genotype_.fitness(),
                            f_genotype_.fitness(),
                            configuration_->comparisonOperator())) {
                        f_genotype_ = m_genotype_;
                    }
                }
                LOG << "# generation " << state_->generation() << " score "
                    << f_genotype_.fitness() << "\n";
                state_->setGeneration(state_->generation() + 1);
            }
            state_->setGeneration(0);
            state_->setRun(state_->run() + 1);
        }
    }

    cgp::Genotype<T> f_genotype_;
    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::State> state_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::GeneType> gene_type_;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::vector<std::function<T(std::vector<T>)> > instruction_set_;
    std::function<double(cgp::FitnessArgs<T>)> fitness_function_;
    cgp::Logger LOG;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_
