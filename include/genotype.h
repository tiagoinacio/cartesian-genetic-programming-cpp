// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENOTYPE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENOTYPE_H_

#include <memory>
#include <vector>

#include "include/gene_type.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

class Genotype {
 public:
    void create(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type);

    std::vector<unsigned int> genes() {
        return genes_;
    }

    void insertFunctionGenes(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type);

    void insertConnectionGenes(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type);

    void insertParameterGenes(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type);

 private:
    std::vector<unsigned int> genes_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENOTYPE_H_
