// Copyright 2017
// Tiago Inácio

#include "include/offspring.h"

cgp::Offspring::Offspring(std::shared_ptr<cgp::State> state,
    std::shared_ptr<cgp::Size> size, std::shared_ptr<cgp::GeneType> gene_type)
    : state_(state), size_(size), gene_type_(gene_type) {
}
