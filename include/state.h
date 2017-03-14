// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_

#include <memory>

namespace cgp {

class State {
 public:
    State();
    unsigned int getGeneration() const;
    void setGeneration(unsigned int generation);

 private:
    unsigned int generation_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
