// Copyright 2017
// Tiago Inácio

#include "include/event.h"

cgp::Event::Event() : pState_(0), pSize_(0) {
}

void cgp::Event::setStatePtr(std::shared_ptr<cgp::State> pState) {
    pState_ = pState;
}

void cgp::Event::setSizePtr(std::shared_ptr<cgp::Size> pSize) {
    pSize_ = pSize;
}
