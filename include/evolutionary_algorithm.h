// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_

#include <iostream>
#include <memory>
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
    }

    virtual void run() {
        evolutionaryLoop_();
    }

 private:
    EvolutionaryAlgorithm();

    void evolutionaryLoop_() {
        genotype_.create(state_, configuration_, size_, gene_type_,
            instruction_set_, parameters_, fitness_function_);

        genotype_.toString();
        genotype_.toString(true);

        while (state_->run() < size_->runs()) {
            while (state_->generation() < size_->generations()) {
                state_->setGeneration(state_->generation() + 1);
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
