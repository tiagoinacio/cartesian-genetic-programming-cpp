// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_GENOTYPE_H_
#define INCLUDE_GENOTYPE_H_

#include <stdlib.h>
#include <iomanip>
#include <memory>
#include <random>
#include <set>
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
        configuration_ = configuration;
        instruction_set_ = instructionSet;
        fitness_function_ = fitness_function;
        parameters_ = parameters;
        size_ = size;
        state_ = state;
        gene_type_ = gene_type;

        createGenotype_();
        findActiveNodes_();
        state_->setGenes(genes_);
        setupFitnessArgs_();
        calculateFitness_();
    }

    Genotype<T>& operator=(const Genotype<T>& genotype) {
        if (&genotype != this) {
            configuration_ = genotype.configuration();
            instruction_set_ = genotype.instructionSet();
            fitness_function_ = genotype.fitnessFunction();
            parameters_ = genotype.parameters();
            size_ = genotype.size();
            state_ = genotype.state();
            gene_type_ = genotype.geneType();

            genes_ = genotype.genes();
            active_nodes_ = genotype.activeNodes();
            state_->setGenes(genes_);
            setupFitnessArgs_();
            fitness_ = genotype.fitness();
        }
        return *this;
    }

    std::set<int> activeNodes() const {
        return active_nodes_;
    }

    double fitness() const {
        return fitness_;
    }

    std::shared_ptr<cgp::State> state() const {
        return state_;
    }

    std::shared_ptr<cgp::Configuration> configuration() const {
        return configuration_;
    }

    std::shared_ptr<cgp::Size> size() const {
        return size_;
    }

    std::shared_ptr<cgp::GeneType> geneType() const {
        return gene_type_;
    }

    std::vector<std::function<T(std::vector<T>)> > instructionSet() const {
        return instruction_set_;
    }

    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters() const {
        return parameters_;
    }

    std::function<double(cgp::FitnessArgs<T>)> fitnessFunction() const {
        return fitness_function_;
    }

    std::vector<int> genes() const {
        return genes_;
    }

    void setGenes(std::vector<int> genes) {
        genes_ = genes;
        findActiveNodes_();
        state_->setGenes(genes_);
        setupFitnessArgs_();
        calculateFitness_();
    }

    void insertFunctionGenes() {
        std::vector<unsigned int> function_genes = gene_type_->functionGenes();
        for (unsigned int i = 0; i < function_genes.size(); i++) {
            genes_[function_genes[i]] = cgp::Gene::function(size_->functions());
        }
    }

    void insertConnectionGenes() {
        std::vector<unsigned int> connection_genes =
            gene_type_->connectionGenes();
        for (unsigned int i = 0; i < connection_genes.size(); i++) {
            genes_[connection_genes[i]] = cgp::Gene::connection(
                connection_genes[i], size_->genesPerNode(), size_->levelsBack(),
                size_->programInputs());
        }
    }

    void insertParameterGenes() {
        std::vector<unsigned int> parameter_genes =
            gene_type_->parameterGenes();
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
                genes_[i] = cgp::Gene::connection(lastGeneOfNodes,
                    size_->genesPerNode(), size_->levelsBack(),
                    size_->programInputs());
            }
        }
    }

    void toString(bool isToShowReference = false) {
        for (std::vector<int>::const_iterator iter = genes_.begin();
             iter != genes_.end(); ++iter)
            std::cout << " " << *iter;

        std::cout << std::endl
                  << "**********************************************"
                  << std::endl;

        for (int i = 0; i < size_->programInputs(); ++i) {
            std::cout << genes_[i] << std::endl;
        }

        for (int i = size_->programInputs();
             i < size_->genesInNodes() + size_->programInputs(); ++i) {
            if ((i - size_->programInputs()) % size_->genesPerNode() == 0) {
                std::cout << std::endl;
            }
            std::cout << genes_[i] << " ";
        }
        for (int i = size_->genesInNodes() + size_->programInputs();
             i < size_->genes(); ++i) {
            std::cout << std::endl << std::endl << genes_[i] << std::endl;
        }
    }

    void mutation() {
        for (int i = size_->programInputs(); i < size_->genesInNodes(); ++i) {
            std::random_device rd;
            std::mt19937 e2(rd());
            std::uniform_real_distribution<> dist(0, 10);
            double random_number = dist(e2) / 10;
            if (random_number <= configuration_->mutationProbability()) {
                std::vector<unsigned int> connection_genes =
                    gene_type_->connectionGenes();
                if (std::find(connection_genes.begin(), connection_genes.end(),
                        i) != connection_genes.end()) {
                    genes_[i] = cgp::Gene::connection(i, size_->genesPerNode(),
                        size_->levelsBack(), size_->programInputs());
                }

                std::vector<unsigned int> function_genes =
                    gene_type_->functionGenes();
                if (std::find(function_genes.begin(), function_genes.end(),
                        i) != function_genes.end()) {
                    genes_[i] = cgp::Gene::function(size_->functions());
                }
            }
        }
        insertGenes_();
        findActiveNodes_();
        state_->setGenes(genes_);
        setupFitnessArgs_();
        calculateFitness_();
    }

 private:
    void setupFitnessArgs_() {
        fitnessArgs_.setConfiguration(configuration_);
        fitnessArgs_.setInstructionSet(instruction_set_);
        fitnessArgs_.setSize(size_);
        fitnessArgs_.setState(state_);
        fitnessArgs_.setActiveNodes(active_nodes_);
    }

    void calculateFitness_() {
        fitness_ = fitness_function_(fitnessArgs_);
    }

    void createGenotype_() {
        genes_.resize(size_->genes());

        for (int i = 0; i < size_->genes(); ++i) {
            if (i < size_->programInputs()) {
                genes_[i] = i;
            } else {
                genes_[i] = 0;
            }
        }
        insertGenes_();
    }

    void insertGenes_() {
        insertFunctionGenes();
        insertConnectionGenes();
        insertParameterGenes();
        insertProgramOutputs();
    }

    void findActiveNodes_() {
        std::set<int>::iterator iter;

        // push program outputs
        const size_t size_program_outputs = size_->programOutputs();
        const size_t size_genes = size_->genes();
        for (unsigned int i = size_program_outputs; i; --i) {
            active_nodes_.insert(genes_[size_genes - i]);
        }

        // push connections
        const size_t size_nodes = size_->nodes();
        const size_t size_program_inputs = size_->programInputs();
        for (unsigned int i =
                 size_nodes + size_program_inputs + size_->programOutputs();
             i; --i) {
            iter = active_nodes_.find(i);
            if (iter == active_nodes_.end()) {
                continue;
            }

            for (unsigned int j = 1; j <= size_->connections(); ++j) {
                unsigned int node_index =
                    genes_[(i * size_->genesPerNode()) - size_->genesPerNode() +
                           j + size_->programInputs()];
                iter = active_nodes_.find(node_index);
                if (iter == active_nodes_.end()) {
                    active_nodes_.insert(node_index);
                }
            }
        }
    }

    cgp::FitnessArgs<T> fitnessArgs_;
    double fitness_;
    std::set<int> active_nodes_;
    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::GeneType> gene_type_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::State> state_;
    std::vector<int> genes_;
    std::vector<std::function<T(std::vector<T>)> > instruction_set_;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::function<double(cgp::FitnessArgs<T>)> fitness_function_;
};

}   // namespace cgp
#endif   // INCLUDE_GENOTYPE_H_
