// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENE_H_

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdexcept>
#include "include/gene_type.h"

namespace cgp {

class Gene {
 public:
    static unsigned int function(size_t max_number_of_functions);
    static unsigned int connection(
        unsigned int gene_index, unsigned int genes_per_node);
    static unsigned int parameter();
};
}

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_GENE_H_
