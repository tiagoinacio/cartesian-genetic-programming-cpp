// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FITNESS_ARGS_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FITNESS_ARGS_H_

#include <memory>
#include <set>
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
        instruction_set_ = instructionSet;
    }

    void setActiveNodes(std::set<int> active_nodes) {
        active_nodes_ = active_nodes;
    }

    std::vector<std::function<T(std::vector<T>)> > instructionSet() {
        return instruction_set_;
    }

    std::set<int> activeNodes() {
        return active_nodes_;
    }

    std::shared_ptr<cgp::State> state() {
        return state_;
    }

    std::shared_ptr<cgp::Configuration> configuration() {
        return configuration_;
    }

    std::shared_ptr<cgp::Size> size() {
        return size_;
    }

 private:
    std::set<int> active_nodes_;
    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::State> state_;
    std::vector<std::function<T(std::vector<T>)> > instruction_set_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_FITNESS_ARGS_H_
