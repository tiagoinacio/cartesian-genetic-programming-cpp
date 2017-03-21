// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_ALGORITHM_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_ALGORITHM_H_

namespace cgp {

class Algorithm {
 public:
    virtual ~Algorithm() {
    }
    virtual void run() = 0;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_ALGORITHM_H_
