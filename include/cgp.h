// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_

#include <map>
#include <string>
#include "./include/configuration.h"

namespace cgp {

class CGP {
 public:
    explicit CGP(Configuration config);

 private:
    const Configuration _configuration;
};

};  // namespace cgp

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
