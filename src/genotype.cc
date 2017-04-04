// Copyright 2017
// Tiago Inácio

#include "include/genotype.h"

void cgp::Genotype::create(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type,
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters) {
    srand(time(NULL));
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
        genes_[function_genes[i]] = cgp::Gene::function(size->functions());
    }
}

void cgp::Genotype::insertConnectionGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    std::vector<unsigned int> connection_genes = gene_type->connectionGenes();
    for (unsigned int i = 0; i < connection_genes.size(); i++) {
        genes_[connection_genes[i]] = cgp::Gene::connection(connection_genes[i],
            size->genesPerNode(), size->levelsBack(), size->programInputs());
    }
}

void cgp::Genotype::insertParameterGenes(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type) {
    std::vector<unsigned int> parameter_genes = gene_type->parameterGenes();
    unsigned int j = 0;
    unsigned int max_parameters = size->parameters();
    for (unsigned int i = 0; i < parameter_genes.size(); i++) {
        genes_[parameter_genes[i]] = j++;
        if (j == max_parameters) {
            j = 0;
        }
    }
}

void cgp::Genotype::insertProgramOutputs(std::shared_ptr<cgp::Size> size) {
    for (unsigned int i = size->genes() - size->programOutputs();
         i < size->genes(); ++i) {
        genes_[i] = i;
    }
}

void cgp::Genotype::toString(bool isToShowReference) {
    int j = 0;
    int f = 0;
    int g = 0;

    std::cout << "**********************************************" << std::endl
              << "* node | function | connections | parameters *" << std::endl
              << "**********************************************" << std::endl;

    for (unsigned int a = 0; a < size_->programInputs(); ++a) {
        std::cout << "  i" << std::setfill('0') << std::setw(3) << a
                  << std::endl;
    }
    int ii = size_->programInputs();
    for (std::vector<int>::const_iterator i = genes_.begin(); i != genes_.end();
         ++i) {
        if (j % size_->genesPerNode() == 0) {
            unsigned int node_index = cgp::GeneType::findWhichNodeBelongsTo(
                j, size_->genesPerNode(), size_->programInputs());
            if (node_index != size_->programInputs()) {
                std::cout << std::endl;
            }

            std::cout << "   " << std::setfill('0') << std::setw(3);
            if (isToShowReference) {
                std::cout << "        ";
            } else {
                std::cout << node_index << "     ";
            }
        }
        f = (j - size_->parameters() - size_->connections() + 1);
        if (f >= 0 && f % size_->genesPerNode() == 0) {
            std::cout << "       ";
        }
        g = (j - size_->parameters() + 1);
        if (g >= 0 && g % size_->genesPerNode() == 0) {
            std::cout << "     ";
        }
        std::cout << std::setfill('0') << std::setw(3);
       if (isToShowReference) {
           std::cout << ii << ' ';
       } else {
           std::cout << *i << ' ';
       }

        j++;
        ii++;
    }
    for (unsigned int a = 0; a < size_->programOutputs(); ++a) {
        std::cout << std::endl
            << "  o" << std::setfill('0') << std::setw(3);
        if (isToShowReference) {
            std::cout << ii;
        } else {
            std::cout << a;
        }
        std::cout << std::endl;
        ii++;
    }
    std::cout << std::endl
              << "**********************************************" << std::endl;
}
