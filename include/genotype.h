// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENOTYPE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENOTYPE_H_

#include <iomanip>
#include <memory>
#include <utility>
#include <vector>

#include "include/configuration.h"
#include "include/fitness_args.h"
#include "include/gene.h"
#include "include/gene_type.h"
#include "include/parameter.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

template <typename T>
class Genotype {
 public:
    double fitness() {
        return fitness_;
    }

    void create(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Configuration> configuration,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type,
        std::vector<std::function<T(std::vector<T>)> > instructionSet,
        std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters,
        std::function<double(cgp::FitnessArgs<T>)> fitness_function) {
        srand(time(NULL));

        configuration_ = configuration;
        instructionSet_ = instructionSet;
        fitness_function_ = fitness_function;
        parameters_ = parameters;
        size_ = size;
        state_ = state;

        createGenotype_(gene_type, state);
        calculateFitness_();
    }

    std::vector<int> genes() {
        return genes_;
    }

    void insertFunctionGenes(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::GeneType> gene_type) {
        std::vector<unsigned int> function_genes = gene_type->functionGenes();
        for (unsigned int i = 0; i < function_genes.size(); i++) {
            genes_[function_genes[i]] = cgp::Gene::function(size_->functions());
        }
    }

    void insertConnectionGenes(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::GeneType> gene_type) {
        std::vector<unsigned int> connection_genes =
            gene_type->connectionGenes();
        for (unsigned int i = 0; i < connection_genes.size(); i++) {
            genes_[connection_genes[i]] = cgp::Gene::connection(
                connection_genes[i], size_->genesPerNode(), size_->levelsBack(),
                size_->programInputs());
        }
    }

    void insertParameterGenes(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::GeneType> gene_type) {
        std::vector<unsigned int> parameter_genes = gene_type->parameterGenes();
        unsigned int j = 0;
        unsigned int max_parameters = size_->parameters();
        for (unsigned int i = 0; i < parameter_genes.size(); i++) {
            genes_[parameter_genes[i]] = j++;
            if (j == max_parameters) {
                j = 0;
            }
        }
    }

    void insertProgramOutputs() {
        if (configuration_->isNodeOutputTheLastOne()) {
            for (unsigned int i = size_->genes() - size_->programOutputs();
                 i < size_->genes(); ++i) {
                genes_[i] = i;
            }
        } else {
            unsigned int lastGeneOfNodes =
                size_->genes() - size_->programOutputs();
            for (unsigned int i = lastGeneOfNodes; i < size_->genes(); ++i) {
                std::cout << i << std::endl;
                std::cout << genes_[i] << std::endl;
                genes_[i] = cgp::Gene::connection(lastGeneOfNodes,
                    size_->genesPerNode(), size_->levelsBack(),
                    size_->programInputs());
                std::cout << genes_[i] << std::endl;
            }
        }
    }

    void toString(bool isToShowReference = false) {
        int j = 0;
        int f = 0;
        int g = 0;

        std::cout << "**********************************************"
                  << std::endl
                  << "* node | function | connections | parameters *"
                  << std::endl
                  << "**********************************************"
                  << std::endl;

        for (unsigned int a = 0; a < size_->programInputs(); ++a) {
            std::cout << "  i" << std::setfill('0') << std::setw(3) << a
                      << std::endl;
        }
        int ii = size_->programInputs();
        for (std::vector<int>::const_iterator i = genes_.begin();
             i != genes_.end(); ++i) {
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
            if (j == size_->genesInNodes()) {
                break;
            }
        }
        for (unsigned int a = 0; a < size_->programOutputs(); ++a) {
            std::cout << std::endl
                      << "  o" << std::setfill('0') << std::setw(3);
            if (isToShowReference) {
                std::cout << ii;
            } else {
                std::cout << genes_[a];
            }
            std::cout << std::endl;
            ii++;
        }
        std::cout << std::endl
                  << "**********************************************"
                  << std::endl;
    }

 private:
    void calculateFitness_() {
        fitnessArgs_.setConfiguration(configuration_);
        fitnessArgs_.setInstructionSet(instructionSet_);
        fitnessArgs_.setSize(size_);
        fitnessArgs_.setState(state_);
        fitness_function_(fitnessArgs_);
    }

    void createGenotype_(std::shared_ptr<cgp::GeneType> gene_type,
        std::shared_ptr<cgp::State> state) {
        genes_.resize(size_->genes());

        for (int i = 0; i < size_->genes(); ++i) {
            genes_[i] = 0;
        }

        insertFunctionGenes(state, gene_type);
        insertConnectionGenes(state, gene_type);
        insertParameterGenes(state, gene_type);
        insertProgramOutputs();
    }

    cgp::FitnessArgs<T> fitnessArgs_;
    double fitness_;
    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::GeneType> gene_type_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::State> state_;
    std::vector<int> genes_;
    std::vector<std::function<T(std::vector<T>)> > instructionSet_;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::function<double(cgp::FitnessArgs<T>)> fitness_function_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENOTYPE_H_
