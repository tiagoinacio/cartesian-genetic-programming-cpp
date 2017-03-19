// copyright Tiago Inácio

// #include <limits.h>
// #include <memory>
// #include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/state.h"
#include "include/size.h"
#include "include/event.h"

using testing::ElementsAre;

TEST(Constructor, default) {
    cgp::Event event;

    EXPECT_EQ(event.state(), 0);
    EXPECT_EQ(event.size(), 0);
}

TEST(setStatePtr, it_should_set_State_pointer) {
    cgp::Event event;
    std::shared_ptr<cgp::State> state(new cgp::State);

    EXPECT_EQ(event.state(), 0);

    event.setStatePtr(state);
    EXPECT_EQ(event.state()->generation(), 0);
}

TEST(setSizePtr, default) {
    cgp::Event event;
    cgp::Configuration configuration;
    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));

    EXPECT_EQ(event.size(), 0);

    event.setSizePtr(size);
    EXPECT_EQ(event.size()->columns(), 1);
}

