// Copyright 2017
// Tiago Inácio

#include "include/size.h"

const unsigned int kFunctionPerNode = 1;

cgp::Size::Size(const cgp::Configuration& configuration)
    : connections_(configuration.connections()),
      generations_(configuration.generations()),
      inputs_(configuration.inputs()),
      levelsBack_(configuration.levelsBack()),
      offspring_(configuration.offspring()),
      outputs_(configuration.outputs()),
      rows_(configuration.rows()),
      runs_(configuration.runs()),
      columns_(configuration.columns()) {
    computationalNodes_ = rows_ * columns_;
    genesPerNode_ = kFunctionPerNode + connections_ + parameters_;
    genes_ = computationalNodes_ * genesPerNode_ + outputs_;
    nodes_ = computationalNodes_ + inputs_;
}

unsigned int cgp::Size::columns() const {
    return columns_;
}

unsigned int cgp::Size::inputs() const {
    return inputs_;
}

unsigned int cgp::Size::connections() const {
    return connections_;
}

unsigned int cgp::Size::generations() const {
    return generations_;
}

unsigned int cgp::Size::levelsBack() const {
    return levelsBack_;
}

unsigned int cgp::Size::offspring() const {
    return offspring_;
}

unsigned int cgp::Size::outputs() const {
    return outputs_;
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
