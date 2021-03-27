// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_GENE_H_
#define INCLUDE_GENE_H_

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "include/gene_type.h"

namespace cgp {

class Gene {
 public:
    static unsigned int function(size_t max_number_of_functions);
    static unsigned int connection(unsigned int gene_index,
        unsigned int genes_per_node, unsigned int levels_back,
        unsigned int program_inputs);
    static unsigned int parameter();
};
}   // namespace cgp

#endif   // INCLUDE_GENE_H_
