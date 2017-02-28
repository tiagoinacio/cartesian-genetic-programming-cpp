/* Copyright 2017 Tiago Inácio */

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_

#include <cstring>
#include <map>

#include "./include/configuration.h"

namespace cgp {

class cgp {
 public:
    explicit cgp(configuration config);

    void setRows(int rows);

 private:
    const configuration _configuration;
};

};  // namespace cgp

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
