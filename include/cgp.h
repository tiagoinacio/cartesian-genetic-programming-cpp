// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "include/configuration.h"
#include "include/event.h"
#include "include/gene_type.h"
#include "include/parameter.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

template <typename T>
class CGP {
 public:
    explicit CGP(const Configuration configuration)
        : configuration_(configuration),
          size_(new cgp::Size(configuration)),
          state_(new cgp::State()) {
        state_->setGeneration(1);
        events_.push_back("on_init");
    }

    void pushParameter(std::shared_ptr<cgp::ParameterInterface> parameter) {
        parameters_.push_back(parameter);
    }

    void setCallback(std::string event, void (*callback)(const cgp::Event&)) {
        if (std::find(events_.begin(), events_.end(), event) == events_.end()) {
            throw std::out_of_range("Not a valid event callback.");
        }
        callbacks_.insert(std::make_pair(event, callback));
    }

    void pushFunction(std::function<T(std::vector<T>)> fn) {
        instructionSet_.push_back(fn);
    }

    void addFitnessFunction(std::function<double(void)> fitnessFunction) {
        fitnessFunction_ = fitnessFunction;
    }

    void run() {
        event_.setStatePtr(state_);
        event_.setSizePtr(size_);
        size_->setNumberOfParameters(parameters_.size());
        callbacks_["on_init"](event_);
        connections_.push_back(2);
        connections_.push_back(3);
        std::cout << "instruction set: " << instructionSet_[0](connections_)
                  << std::endl;
    }

 private:
    const Configuration configuration_;
    std::shared_ptr<cgp::State> state_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::GeneType> geneType_;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::map<std::string, std::function<void(const cgp::Event&)> > callbacks_;
    std::vector<std::string> events_;
    std::vector<std::function<T(std::vector<T>)> > instructionSet_;
    std::vector<T> connections_;
    std::function<double(void)> fitnessFunction_;
    cgp::Event event_;
};

};   // namespace cgp

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
