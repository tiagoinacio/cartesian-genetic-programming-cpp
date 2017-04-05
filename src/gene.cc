// Copyright 2017
// Tiago Inácio

#include "include/gene.h"

unsigned int cgp::Gene::function(size_t max_number_of_functions) {
    return rand() % max_number_of_functions;
}

unsigned int cgp::Gene::connection(unsigned int gene_index,
    unsigned int genes_per_node, unsigned int levels_back,
    unsigned int program_inputs) {
    unsigned int node_from_gene = cgp::GeneType::findWhichNodeBelongsTo(
        gene_index, genes_per_node, program_inputs);
    std::vector<int> possible_node_connections;

    std::cout << "possible connections to node " << node_from_gene << std::endl;

    unsigned int count = 1;
    for (unsigned int i = node_from_gene - 1; i; i--) {
        if (count > levels_back) {
            break;
        }
        possible_node_connections.push_back(i);
        std::cout << "pushing node: " << i << " to node " << node_from_gene
                  << std::endl;
        count++;
    }

    return possible_node_connections[rand() % possible_node_connections.size()];
}

unsigned int cgp::Gene::parameter() {
    return 3;
}
