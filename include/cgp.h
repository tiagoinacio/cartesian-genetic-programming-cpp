// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "include/configuration.h"
#include "include/parameter.h"

namespace cgp {

class CGP {
 public:
    explicit CGP(Configuration config);
    void addParameter(std::shared_ptr<cgp::ParameterBase> parameter);
 private:
    const Configuration _configuration;
    std::vector<std::shared_ptr<cgp::ParameterBase> > parameters_;
};

};  // namespace cgp

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
