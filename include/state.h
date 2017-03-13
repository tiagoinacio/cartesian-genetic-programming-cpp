// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_

#include <memory>

namespace cgp {

class State {
    // friend class CGP<T>;

 public:
    State() : generation_(0) {
    }
    unsigned int getGeneration() const;

//  protected:
    static std::shared_ptr<State> create();
    void setGeneration(unsigned int generation);

 private:
    unsigned int generation_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
