// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVENT_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVENT_H_

#include <memory>

#include "include/size.h"
#include "include/state.h"

namespace cgp {

class Event {
 public:
    Event();

    std::shared_ptr<cgp::State> state() const {
        return pState_;
    }

    std::shared_ptr<cgp::Size> size() const {
        return pSize_;
    }

    void setStatePtr(std::shared_ptr<cgp::State> pState);
    void setSizePtr(std::shared_ptr<cgp::Size> pSize);

 private:
    std::shared_ptr<cgp::State> pState_;
    std::shared_ptr<cgp::Size> pSize_;
};

}   // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_EVENT_H_
