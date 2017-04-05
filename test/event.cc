// copyright Tiago Inácio

// #include <limits.h>
// #include <memory>
// #include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/event.h"
#include "include/size.h"
#include "include/state.h"

using testing::ElementsAre;

TEST(Constructor, default) {
    cgp::Event event;

    EXPECT_EQ(event.state(), 0);
    EXPECT_EQ(event.size(), 0);
}

TEST(constructor, it_should_set_all_pointers) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    std::shared_ptr<cgp::State> state(new cgp::State);
    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));

    cgp::Event event = cgp::Event(state, size);

    EXPECT_EQ(event.state()->generation(), 0);
    EXPECT_EQ(event.size()->columns(), 1);
}
