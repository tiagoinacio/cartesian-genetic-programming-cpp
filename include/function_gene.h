// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FUNCTION_GENE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FUNCTION_GENE_H_

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdexcept>

namespace cgp {

class FunctionGene {
 public:
    static unsigned int create(size_t max_number_of_functions);
};
}

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FUNCTION_GENE_H_
