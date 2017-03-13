// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_

#include <memory>

namespace cgp {

class State {
 public:
    static State& getInstance();
    unsigned int getGeneration() const;
    void setGeneration(unsigned int generation);

 private:
    State() {
    }
    State(State const&);
    void operator=(State const&);

    unsigned int generation_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
