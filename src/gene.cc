// Copyright 2017
// Tiago Inácio

#include "include/gene.h"

unsigned int cgp::Gene::function(size_t max_number_of_functions) {
    return rand() % max_number_of_functions;
}

unsigned int cgp::Gene::connection(unsigned int gene_index,
    unsigned int genes_per_node, unsigned int levels_back,
    unsigned int program_inputs) {
    int node_from_gene = cgp::GeneType::findWhichNodeBelongsTo(
        gene_index, genes_per_node, program_inputs);
    std::vector<int> possible_node_connections;

    unsigned int count = 1;
    for (int i = node_from_gene - program_inputs - 1; i >= 0; i--) {
        if (count > levels_back) {
            break;
        }
        possible_node_connections.push_back(i);
        count++;
    }

    if (possible_node_connections.size() == 0) {
        return 0;
    }

    return possible_node_connections[rand() % possible_node_connections.size()];
}

unsigned int cgp::Gene::parameter() {
    return 3;
}
