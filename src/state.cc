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

unsigned int cgp::State::generation() const {
    return generation_;
}

unsigned int cgp::State::run() const {
    return run_;
}
