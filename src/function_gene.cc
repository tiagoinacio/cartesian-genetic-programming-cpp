// Copyright 2017
// Tiago Inácio

#include "include/function_gene.h";

unsigned int cgp::FunctionGene::create(size_t max_number_of_functions) {
    srand(time(NULL));
    return rand() % max_number_of_functions;
}
