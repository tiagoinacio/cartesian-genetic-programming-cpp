// Copyright 2017
// Tiago Inácio

#include "include/state.h"

std::shared_ptr<cgp::State> cgp::State::create() {
    std::shared_ptr<cgp::State> pointer(new cgp::State());
    return pointer;
}

void cgp::State::setGeneration(unsigned int generation) {
    generation_ = generation;
}

unsigned int cgp::State::getGeneration() const {
    return generation_;
}
