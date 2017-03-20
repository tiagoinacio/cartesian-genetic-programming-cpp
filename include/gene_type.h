// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENE_TYPE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENE_TYPE_H_

#include <memory>
#include <vector>
#include "include/size.h"

namespace cgp {

class GeneType {
 public:
    explicit GeneType(std::shared_ptr<cgp::Size> sizes);

    std::vector<unsigned int> connectionGenes() const {
        return connection_genes_;
    }

    std::vector<unsigned int> parameterGenes() const {
        return parameter_genes_;
    }

    std::vector<unsigned int> functionGenes() const {
        return function_genes_;
    }

 private:
    void calculateConnectionGenes();
    void calculateParameterGenes();
    void calculateFunctionGenes();

    std::shared_ptr<cgp::Size> size_;
    std::vector<unsigned int> connection_genes_;
    std::vector<unsigned int> parameter_genes_;
    std::vector<unsigned int> function_genes_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENE_TYPE_H_