// Copyright 2017
// Tiago Inácio

#include "include/gene_type.h"
#include <iostream>

cgp::GeneType::GeneType(std::shared_ptr<cgp::Size> size)
    : size_(size),
      connection_genes_(),
      parameter_genes_(),
      program_output_genes_(),
      program_input_genes_() {
    calculateConnectionGenes();
}

// 1           2             3
//
// 1           7             13
// 2, 3, 4     8, 9, 10,     14, 15, 16
// 5, 6        11, 12        17, 18
void cgp::GeneType::calculateConnectionGenes() {
    for (unsigned int i = 1; i <= size_->nodes(); ++i) {
        for (unsigned int e = 1; e <= size_->connections(); e++) {
            connection_genes_.push_back((i * size_->genesPerNode()) -
                                        size_->parameters() -
                                        size_->connections() + e - 1);
        }
    }
}
