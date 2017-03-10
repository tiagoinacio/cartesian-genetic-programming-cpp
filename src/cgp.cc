// Copyright 2017
// Tiago Inácio

#include <iostream>
#include <memory>
#include <vector>
#include "include/cgp.h"
#include "include/configuration.h"
#include "include/parameter.h"

cgp::CGP::CGP(const Configuration configuration) :
    _configuration(configuration)
    {}

void cgp::CGP::addParameter(std::shared_ptr<cgp::ParameterBase> parameter) {
    parameters_.push_back(parameter);
}

void cgp::CGP::mutateParameter(int index) {
    parameters_[index]->mutation();
}
