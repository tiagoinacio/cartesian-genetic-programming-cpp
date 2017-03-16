// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_SIZE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_SIZE_H_

#include "include/configuration.h"

namespace cgp {

class Size {
 public:
    explicit Size(const cgp::Configuration& configuration);

    unsigned int columns() const;
    unsigned int computationalNodes() const;
    unsigned int connections() const;
    unsigned int generations() const;
    unsigned int genes() const;
    unsigned int genesPerNode() const;
    unsigned int inputs() const;
    unsigned int levelsBack() const;
    unsigned int nodes() const;
    unsigned int offspring() const;
    unsigned int outputs() const;
    unsigned int parameters() const;
    unsigned int rows() const;
    unsigned int runs() const;

    void setNumberOfParameters(unsigned int parameters) {
        parameters_ = parameters;
    }

 private:
    unsigned int columns_;
    unsigned int computationalNodes_;
    unsigned int connections_;
    unsigned int generations_;
    unsigned int genesPerNode_;
    unsigned int genes_;
    unsigned int inputs_;
    unsigned int levelsBack_;
    unsigned int nodes_;
    unsigned int offspring_;
    unsigned int outputs_;
    unsigned int parameters_;
    unsigned int rows_;
    unsigned int runs_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_SIZE_H_
