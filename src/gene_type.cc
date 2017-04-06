// Copyright 2017
// Tiago Inácio

#include "include/gene_type.h"

const unsigned int kFunctionPerNode = 1;

/*
 * Example with 3 nodes, 6 genes per node, 3 connections and 2 parameters
 * 1           2             3
 *
 * 1           7             13              function gene
 * 2, 3, 4     8, 9, 10,     14, 15, 16      connection genes
 * 5, 6        11, 12        17, 18          parameter genes
 */
cgp::GeneType::GeneType(std::shared_ptr<cgp::Size> size)
    : size_(size), connection_genes_(), parameter_genes_(), function_genes_() {
    calculateConnectionGenes();
    calculateParameterGenes();
    calculateFunctionGenes();
}

void cgp::GeneType::calculateConnectionGenes() {
    for (unsigned int i = 1; i <= size_->nodes(); ++i) {
        for (unsigned int e = 1; e <= size_->connections(); e++) {
            connection_genes_.push_back(
                (i * size_->genesPerNode()) - size_->parameters() -
                size_->connections() + e - 1 + size_->programInputs());
        }
    }
}

void cgp::GeneType::calculateParameterGenes() {
    if (size_->parameters() > 0) {
        for (unsigned int i = 1; i <= size_->nodes(); ++i) {
            for (unsigned int e = 1; e <= size_->parameters(); e++) {
                parameter_genes_.push_back((i * size_->genesPerNode()) -
                                           size_->parameters() + e - 1 +
                                           size_->programInputs());
            }
        }
    }
}

void cgp::GeneType::calculateFunctionGenes() {
    for (unsigned int i = 1; i <= size_->nodes(); ++i) {
        function_genes_.push_back(i * size_->genesPerNode() -
                                  size_->genesPerNode() + kFunctionPerNode - 1 +
                                  size_->programInputs());
    }
}
