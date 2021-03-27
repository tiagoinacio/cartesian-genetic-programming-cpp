// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_EVENT_H_
#define INCLUDE_EVENT_H_

#include <memory>

#include "include/size.h"
#include "include/state.h"

namespace cgp {

class Event {
 public:
    Event();

    Event(std::shared_ptr<cgp::State> state, std::shared_ptr<cgp::Size> size);

    std::shared_ptr<cgp::State> state() const {
        return pState_;
    }

    std::shared_ptr<cgp::Size> size() const {
        return pSize_;
    }

 private:
    std::shared_ptr<cgp::State> pState_;
    std::shared_ptr<cgp::Size> pSize_;
};

}   // namespace cgp
#endif   // INCLUDE_EVENT_H_
