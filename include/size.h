// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_SIZE_H_
#define INCLUDE_SIZE_H_

#include <memory>

#include "include/configuration.h"

namespace cgp {

class Size {
 public:
    explicit Size(std::shared_ptr<cgp::Configuration> configuration);

    unsigned int columns() const;
    unsigned int computationalNodes() const;
    unsigned int connections() const;
    unsigned int generations() const;
    unsigned int genes() const;
    unsigned int genesPerNode() const;
    unsigned int genesInNodes() const;
    unsigned int programInputs() const;
    unsigned int functions() const;
    unsigned int levelsBack() const;
    unsigned int nodes() const;
    unsigned int offspring() const;
    unsigned int programOutputs() const;
    unsigned int parameters() const;
    unsigned int rows() const;
    unsigned int runs() const;

 private:
    unsigned int columns_;
    unsigned int computational_nodes_;
    unsigned int connections_;
    unsigned int functions_;
    unsigned int generations_;
    unsigned int genes_;
    unsigned int genes_in_nodes_;
    unsigned int genes_per_node_;
    unsigned int levels_back_;
    unsigned int nodes_;
    unsigned int offspring_;
    unsigned int parameters_;
    unsigned int program_inputs_;
    unsigned int program_outputs_;
    unsigned int rows_;
    unsigned int runs_;
};

}   // namespace cgp
#endif   // INCLUDE_SIZE_H_
