// Copyright 2017
// Tiago Inácio

#include "include/state.h"

cgp::State& cgp::State::getInstance() {
    static cgp::State instance;

    return instance;
}

void cgp::State::setGeneration(unsigned int generation) {
    generation_ = generation;
}

unsigned int cgp::State::getGeneration() const {
    return generation_;
}
