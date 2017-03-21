// Copyright 2017
// Tiago Inácio

#include "include/event.h"

cgp::Event::Event() : pState_(0), pSize_(0) {
}

cgp::Event::Event(
    std::shared_ptr<cgp::State> state, std::shared_ptr<cgp::Size> size)
    : pState_(state), pSize_(size) {
}
