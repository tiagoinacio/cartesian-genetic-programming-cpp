// Copyright 2017
// Tiago Inácio

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

#include "include/cgp.h"

cgp::CGP::CGP(const Configuration configuration)
    : _configuration(configuration), state_(cgp::State::create()) {
    events_.push_back("on_init");
    state_->setGeneration(1);
}

void cgp::CGP::setParameter(
    std::shared_ptr<cgp::ParameterInterface> parameter) {
    parameters_.push_back(parameter);
}

void cgp::CGP::setCallback(
    std::string event, void (*callback)(std::shared_ptr<cgp::State>)) {
    if (std::find(events_.begin(), events_.end(), event) == events_.end()) {
        throw std::out_of_range("Not a valid event.");
    }
    callbacks_.insert(std::make_pair(event, callback));
}

void cgp::CGP::addFunctionSetFromPath() {
}

void cgp::CGP::run() {
    callbacks_["on_init"](state_);
}
