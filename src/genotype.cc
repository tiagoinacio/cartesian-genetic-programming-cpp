// Copyright 2017
// Tiago Inácio

#include "include/genotype.h"
#include <iostream>

void cgp::Genotype::create(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    genes_.resize(size->genes());

    std::cout << "GENOTYPE_CREATE " << size->genes() << " "
              << gene_type->functionGenes().size() << std::endl;
    insertFunctionGenes(state, size, gene_type);
    insertConnectionGenes(state, size, gene_type);
    insertParameterGenes(state, size, gene_type);
}

std::vector<unsigned int> cgp::Genotype::genes() {
    return genes_;
}

void cgp::Genotype::insertFunctionGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    std::vector<unsigned int> function_genes = gene_type->functionGenes();
    for (unsigned int i = 0; i < function_genes.size(); i++) {
        genes_[function_genes[i]] = 5;
    }
}

void cgp::Genotype::insertConnectionGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
}

void cgp::Genotype::insertParameterGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
}
