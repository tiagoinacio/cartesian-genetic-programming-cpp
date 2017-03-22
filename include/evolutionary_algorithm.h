// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_

#include <iostream>
#include <memory>

#include "include/algorithm.h"
#include "include/gene_type.h"
#include "include/genotype.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

class EvolutionaryAlgorithm : public Algorithm {
 public:
    virtual ~EvolutionaryAlgorithm() {
    }

    EvolutionaryAlgorithm(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type);

    virtual void run() {
        evolutionaryLoop_();
        std::cout << "class EvolutionaryAlgorithm" << std::endl;
    }

 private:
    EvolutionaryAlgorithm();
    void evolutionaryLoop_();

    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::GeneType> gene_type_;
    std::shared_ptr<cgp::State> state_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVOLUTIONARY_ALGORITHM_H_
