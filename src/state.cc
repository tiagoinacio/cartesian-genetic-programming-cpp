// Copyright 2017
// Tiago Inácio

#include "include/state.h"
#include <iostream>

cgp::State::State() : generation_(0) {
}

void cgp::State::setGeneration(unsigned int generation) {
    generation_ = generation;
}

unsigned int cgp::State::getGeneration() const {
    return generation_;
}
