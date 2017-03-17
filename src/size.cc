// Copyright 2017
// Tiago Inácio

#include "include/size.h"

const unsigned int kFunctionPerNode = 1;

cgp::Size::Size(const cgp::Configuration& configuration)
    : connections_(configuration.connections()),
      generations_(configuration.generations()),
      inputs_(configuration.inputs()),
      levels_back_(configuration.levelsBack()),
      offspring_(configuration.offspring()),
      outputs_(configuration.outputs()),
      rows_(configuration.rows()),
      parameters_(configuration.parameters()),
      runs_(configuration.runs()),
      columns_(configuration.columns()) {
    nodes_ = rows_ * columns_;
    genes_per_node_ = kFunctionPerNode + connections_ + parameters_;
    genes_ = nodes_ * genes_per_node_ + outputs_;
}

unsigned int cgp::Size::genes() const {
    return genes_;
}

unsigned int cgp::Size::genesPerNode() const {
    return genes_per_node_;
}

unsigned int cgp::Size::columns() const {
    return columns_;
}

unsigned int cgp::Size::inputs() const {
    return inputs_;
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
