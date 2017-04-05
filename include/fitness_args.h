// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FITNESS_ARGS_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FITNESS_ARGS_H_

#include <memory>
#include <utility>
#include <vector>

#include "include/size.h"
#include "include/state.h"

namespace cgp {

template <typename T>
class FitnessArgs {
 public:
    void setConfiguration(std::shared_ptr<cgp::Configuration> configuration) {
        configuration_ = configuration;
    }

    void setSize(std::shared_ptr<cgp::Size> size) {
        size_ = size;
    }

    void setState(std::shared_ptr<cgp::State> state) {
        state_ = state;
    }

    void setInstructionSet(
        std::vector<std::function<T(std::vector<T>)> > instructionSet) {
        instructionSet_ = instructionSet;
    }

    std::vector<int> genes() {
        return genes_;
    }

 private:
    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::State> state_;
    std::vector<int> genes_;
    std::vector<std::function<T(std::vector<T>)> > instructionSet_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FITNESS_ARGS_H_
