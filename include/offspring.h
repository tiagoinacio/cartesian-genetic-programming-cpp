// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_OFFSPRING_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_OFFSPRING_H_

#include <memory>

#include "include/gene_type.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

class Offspring {
 public:
    Offspring(std::shared_ptr<cgp::State> state,
        std::shared_ptr<cgp::Size> size,
        std::shared_ptr<cgp::GeneType> gene_type);

 private:
    Offspring();   // disallow default constructor
    std::shared_ptr<cgp::State> state_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::GeneType> gene_type_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_OFFSPRING_H_
