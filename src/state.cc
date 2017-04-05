// Copyright 2017
// Tiago Inácio

#include "include/state.h"

cgp::State::State() : generation_(0), run_(0) {
}

void cgp::State::setGeneration(unsigned int generation) {
    generation_ = generation;
}

void cgp::State::setRun(unsigned int run) {
    run_ = run;
}

void cgp::State::setActiveNodes(std::vector<int> activeNodes) {
    activeNodes_ = activeNodes;
}

void cgp::State::setGenes(std::vector<int> genes) {
    genes_ = genes;
}

unsigned int cgp::State::generation() const {
    return generation_;
}

unsigned int cgp::State::run() const {
    return run_;
}

std::vector<int> cgp::State::activeNodes() const {
    return activeNodes_;
}

std::vector<int> cgp::State::genes() const {
    return genes_;
}
