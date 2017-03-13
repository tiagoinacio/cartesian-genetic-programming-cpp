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
#include "include/parameter.h"
#include "include/state.h"

namespace cgp {

template <typename T>
class CGP {
 public:
    explicit CGP(const Configuration configuration)
        : _configuration(configuration) {
        cgp::State::getInstance().setGeneration(1);

        events_.push_back("on_init");
    }

    void pushParameter(std::shared_ptr<cgp::ParameterInterface> parameter) {
        parameters_.push_back(parameter);
    }

    void setCallback(std::string event, void (*callback)(const cgp::State&)) {
        if (std::find(events_.begin(), events_.end(), event) == events_.end()) {
            throw std::out_of_range("Not a valid event.");
        }
        callbacks_.insert(std::make_pair(event, callback));
    }

    void pushFunction(T (*fn)(T, T)) {
        instructionSet_.push_back(fn);
    }

    void run() {
        callbacks_["on_init"](cgp::State::getInstance());
    }

 private:
    const Configuration _configuration;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::map<std::string, void (*)(const cgp::State&)> callbacks_;
    std::vector<std::string> events_;
    std::vector<T (*)(T, T)> instructionSet_;
};

};   // namespace cgp

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
