// Copyright 2017
// Tiago Inácio

#include "include/evolutionary_algorithm.h"

cgp::EvolutionaryAlgorithm::EvolutionaryAlgorithm()
    : state_(0), size_(0), gene_type_(0) {
}

void cgp::EvolutionaryAlgorithm::evolutionaryLoop_() {
    cgp::Offspring offspring = cgp::Offspring(state_, size_, gene_type_);

    while (state_->run() < size_->runs()) {
        while (state_->generation() < size_->generations()) {
            state_->setGeneration(state_->generation() + 1);
        }
        state_->setGeneration(0);
        state_->setRun(state_->run() + 1);
    }
}

void cgp::EvolutionaryAlgorithm::setStatePtr(
    std::shared_ptr<cgp::State> state) {
    state_ = state;
}

void cgp::EvolutionaryAlgorithm::setGeneTypePtr(
    std::shared_ptr<cgp::GeneType> gene_type) {
    gene_type_ = gene_type;
}

void cgp::EvolutionaryAlgorithm::setSizePtr(std::shared_ptr<cgp::Size> size) {
    size_ = size;
}
