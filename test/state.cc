// copyright Tiago Inácio

#include <limits.h>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/state.h"

using testing::HasSubstr;

class StateClass : public ::testing::Test {
 protected:
    cgp::State state;
};

TEST_F(StateClass, DefaultValues) {
    EXPECT_EQ(0, state.generation());
    EXPECT_EQ(0, state.run());
}

TEST_F(StateClass, setGeneration) {
    EXPECT_EQ(0, state.generation());

    state.setGeneration(5);
    EXPECT_EQ(5, state.generation());

    state.setGeneration(9);
    EXPECT_EQ(9, state.generation());
}

TEST_F(StateClass, setRun) {
    EXPECT_EQ(0, state.run());

    state.setRun(5);
    EXPECT_EQ(5, state.run());

    state.setRun(9);
    EXPECT_EQ(9, state.run());
}
