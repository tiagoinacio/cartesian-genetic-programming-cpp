// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FUNCTION_GENE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FUNCTION_GENE_H_

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

namespace cgp {

class FunctionGene {
 public:
    static unsigned int create(size_t max_number_of_functions) {
        srand(time(NULL));
        return rand() % max_number_of_functions;
    }
};
}

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FUNCTION_GENE_H_
