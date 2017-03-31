// Copyright 2017
// Tiago Inácio

#include "include/genotype.h"

void cgp::Genotype::create(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type,
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters) {
    genes_.resize(size->genes());

    for (int i = 0; i < size->genes(); ++i) {
        genes_[i] = 0;
    }

    parameters_ = parameters;
    insertFunctionGenes(state, size, gene_type);
    insertConnectionGenes(state, size, gene_type);
    insertParameterGenes(state, size, gene_type);

    size_ = size;
}

std::vector<int> cgp::Genotype::genes() {
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
        genes_[connection_genes[i]] = cgp::ConnectionGene::create();
    }
}

void cgp::Genotype::insertParameterGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    std::vector<unsigned int> parameter_genes = gene_type->parameterGenes();
    for (unsigned int i = 0; i < parameter_genes.size(); i++) {
        genes_[parameter_genes[i]] = 4;
    }
}

void cgp::Genotype::toString() {
    int j = 0;
    int f = 0;
    int g = 0;

    std::cout << "***************************************" << std::endl;
    std::cout << "* function | connections | parameters *" << std::endl;
    std::cout << "***************************************";
    for (std::vector<int>::const_iterator i = genes_.begin(); i != genes_.end();
         ++i) {
        if (j % size_->genesPerNode() == 0) {
            std::cout << std::endl;
            std::cout << "     ";
        }
        f = (j - size_->parameters() - size_->connections() + 1);
        if (f >= 0 && f % size_->genesPerNode() == 0) {
            std::cout << "          ";
        }
        g = (j - size_->parameters() + 1);
        if (g >= 0 && g % size_->genesPerNode() == 0) {
            std::cout << "        ";
        }
        std::cout << *i << ' ';
        j++;
    }
}
