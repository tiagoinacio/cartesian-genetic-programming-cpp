// Copyright 2017
// Tiago Inácio

#include "include/evolutionary_algorithm.h"

cgp::EvolutionaryAlgorithm::EvolutionaryAlgorithm()
    : state_(0), size_(0), gene_type_(0) {
}

cgp::EvolutionaryAlgorithm::EvolutionaryAlgorithm(
    std::shared_ptr<cgp::State> state, std::shared_ptr<cgp::Size> size,
    std::shared_ptr<cgp::GeneType> gene_type)
    : state_(state), size_(size), gene_type_(gene_type) {
}

void cgp::EvolutionaryAlgorithm::evolutionaryLoop_() {
    cgp::Genotype genotype;

    genotype.create(state_, size_, gene_type_);

    while (state_->run() < size_->runs()) {
        while (state_->generation() < size_->generations()) {
            state_->setGeneration(state_->generation() + 1);
        }
        state_->setGeneration(0);
        state_->setRun(state_->run() + 1);
    }
}
