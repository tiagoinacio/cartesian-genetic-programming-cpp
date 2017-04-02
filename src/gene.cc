// Copyright 2017
// Tiago Inácio

#include "include/gene.h"

unsigned int cgp::Gene::function(size_t max_number_of_functions) {
    return rand() % max_number_of_functions;
}

unsigned int cgp::Gene::connection(
    unsigned int gene_index, unsigned int genes_per_node) {
    unsigned int node_from_gene =
        cgp::GeneType::findWhichNodeBelongsTo(gene_index, genes_per_node);
    return node_from_gene;
}

unsigned int cgp::Gene::parameter() {
    return 3;
}
