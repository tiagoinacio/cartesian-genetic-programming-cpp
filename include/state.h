// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_

namespace cgp {

class State {
 public:
    State();
    unsigned int generation() const;
    unsigned int run() const;

    void setGeneration(unsigned int generation);
    void setRun(unsigned int run);

 private:
    unsigned int generation_;
    unsigned int run_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_STATE_H_
