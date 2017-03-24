// Copyright 2017
// Tiago Inácio

#include "include/genotype.h"

void cgp::Genotype::create(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    genes_.resize(size->genes());
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
        genes_[function_genes[i]] =
            cgp::FunctionGene::create(size->functions());
    }
}

void cgp::Genotype::insertConnectionGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    std::vector<unsigned int> connection_genes = gene_type->connectionGenes();
    for (unsigned int i = 0; i < connection_genes.size(); i++) {
        genes_[connection_genes[i]] = 2;
    }
}

void cgp::Genotype::insertParameterGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    std::vector<unsigned int> parameter_genes = gene_type->parameterGenes();
    for (unsigned int i = 0; i < parameter_genes.size(); i++) {
        genes_[parameter_genes[i]] = 3;
    }
}
