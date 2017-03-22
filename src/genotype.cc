// Copyright 2017
// Tiago Inácio

#include "include/genotype.h"
#include <iostream>

void cgp::Genotype::create(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    genes_.reserve(size->genes());

    insertFunctionGenes(state, size, gene_type);
    insertConnectionGenes(state, size, gene_type);
    insertParameterGenes(state, size, gene_type);
}

void cgp::Genotype::insertFunctionGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    for (unsigned int i = 0; i <= gene_type->functionGenes().size(); i++) {
        std::cout << genes_[i] << std::endl;
        genes_[i] = 5;
        std::cout << genes_[i] << std::endl;
    }
}

void cgp::Genotype::insertConnectionGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
}

void cgp::Genotype::insertParameterGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
}
