// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "include/configuration.h"
#include "include/parameter.h"
#include "include/state.h"

namespace cgp {

class CGP {
 public:
    explicit CGP(Configuration config);
    void setParameter(std::shared_ptr<cgp::ParameterInterface> parameter);
    void setCallback(std::string event, void (*)(std::shared_ptr<cgp::State>));
    void addFunctionSetFromPath();
    void run();
    void toString();

 private:
    const Configuration _configuration;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::map<std::string, void (*)(std::shared_ptr<cgp::State>)> callbacks_;
    std::vector<std::string> events_;
    std::shared_ptr<cgp::State> state_;
};

};   // namespace cgp

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CGP_H_
