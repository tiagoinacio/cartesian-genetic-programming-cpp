// Copyright 2017
// Tiago Inácio

#include "include/size.h"

const unsigned int kFunctionPerNode = 1;

cgp::Size::Size(std::shared_ptr<cgp::Configuration> configuration)
    : columns_(configuration->columns()),
      connections_(configuration->connections()),
      functions_(configuration->functions()),
      generations_(configuration->generations()),
      levels_back_(configuration->levelsBack()),
      offspring_(configuration->offspring()),
      parameters_(configuration->parameters()),
      program_inputs_(configuration->programInputs()),
      program_outputs_(configuration->programOutputs()),
      rows_(configuration->rows()),
      runs_(configuration->runs()) {
    nodes_ = rows_ * columns_;
    genes_per_node_ = kFunctionPerNode + connections_ + parameters_;
    genes_in_nodes_ = nodes_ * genes_per_node_;
    genes_ = genes_in_nodes_ + configuration->programInputs() +
             configuration->programOutputs();
}

unsigned int cgp::Size::genes() const {
    return genes_;
}

unsigned int cgp::Size::functions() const {
    return functions_;
}

unsigned int cgp::Size::genesPerNode() const {
    return genes_per_node_;
}

unsigned int cgp::Size::genesInNodes() const {
    return genes_in_nodes_;
}

unsigned int cgp::Size::columns() const {
    return columns_;
}

unsigned int cgp::Size::programInputs() const {
    return program_inputs_;
}

unsigned int cgp::Size::nodes() const {
    return nodes_;
}

unsigned int cgp::Size::connections() const {
    return connections_;
}

unsigned int cgp::Size::generations() const {
    return generations_;
}

unsigned int cgp::Size::levelsBack() const {
    return levels_back_;
}

unsigned int cgp::Size::offspring() const {
    return offspring_;
}

unsigned int cgp::Size::programOutputs() const {
    return program_outputs_;
}

unsigned int cgp::Size::parameters() const {
    return parameters_;
}

unsigned int cgp::Size::rows() const {
    return rows_;
}

unsigned int cgp::Size::runs() const {
    return runs_;
}
