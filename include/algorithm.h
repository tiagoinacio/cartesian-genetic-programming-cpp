// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_ALGORITHM_H_
#define INCLUDE_ALGORITHM_H_

namespace cgp {

class Algorithm {
 public:
    virtual ~Algorithm() {
    }
    virtual void run() = 0;
};

}   // namespace cgp
#endif   // INCLUDE_ALGORITHM_H_
