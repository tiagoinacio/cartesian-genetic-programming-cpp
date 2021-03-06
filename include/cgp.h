// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_CGP_H_
#define INCLUDE_CGP_H_

#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "include/configuration.h"
#include "include/event.h"
#include "include/evolutionary_algorithm.h"
#include "include/fitness_args.h"
#include "include/gene_type.h"
#include "include/parameter.h"
#include "include/size.h"
#include "include/state.h"

namespace cgp {

template <typename T>
class CGP {
 public:
    explicit CGP(std::shared_ptr<cgp::Configuration> configuration)
        : configuration_(configuration),
          state_(new cgp::State()),
          size_(new cgp::Size(configuration)),
          gene_type_(new cgp::GeneType(size_)) {
        state_->setGeneration(1);
        events_.push_back("on_init");
    }

    void pushParameter(std::shared_ptr<cgp::ParameterInterface> parameter) {
        parameters_.push_back(parameter);
    }

    void subscribe(std::string event, void (*callback)(const cgp::Event&)) {
        if (std::find(events_.begin(), events_.end(), event) == events_.end()) {
            throw std::out_of_range("Not a valid event callback.");
        }
        callbacks_.insert(std::make_pair(event, callback));
    }

    void pushFunction(std::function<T(std::vector<T>)> fn) {
        instruction_set_.push_back(fn);
    }

    void setDebug(bool isDebugActive) {
        debug_ = isDebugActive;
    }

    void addFitnessFunction(
        std::function<double(cgp::FitnessArgs<T>)> fitnessFunction) {
        fitness_function_ = fitnessFunction;
    }

    void run() {
        if (configurationIsValid_()) {
            cgp::Event event_ = cgp::Event(state_, size_);
            callbacks_["on_init"](event_);

            cgp::EvolutionaryAlgorithm<T> ea_ = cgp::EvolutionaryAlgorithm<T>(
                configuration_, state_, size_, gene_type_, parameters_,
                instruction_set_, fitness_function_);
            ea_.run();
        } else {
            std::cout << "You configured " << configuration_->parameters()
                      << " parameters, but only " << parameters_.size()
                      << " parameters were provided." << std::endl;
        }
    }

 private:
    bool configurationIsValid_() throw(std::invalid_argument) {
        if (parameters_.size() != configuration_->parameters()) {
            return false;
        }
        return true;
    }

    std::shared_ptr<cgp::Configuration> configuration_;
    std::shared_ptr<cgp::State> state_;
    std::shared_ptr<cgp::Size> size_;
    std::shared_ptr<cgp::GeneType> gene_type_;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters_;
    std::map<std::string, std::function<void(const cgp::Event&)> > callbacks_;
    std::vector<std::string> events_;
    std::vector<std::function<T(std::vector<T>)> > instruction_set_;
    std::vector<T> connections_;
    std::function<double(cgp::FitnessArgs<T>)> fitness_function_;
    cgp::Event event_;
    bool debug_;
};

};   // namespace cgp

#endif   // INCLUDE_CGP_H_
