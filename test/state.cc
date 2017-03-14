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
    EXPECT_EQ(0, state.getGeneration());
}

TEST_F(StateClass, setGeneration) {
    EXPECT_EQ(0, state.getGeneration());

    state.setGeneration(5);
    EXPECT_EQ(5, state.getGeneration());

    state.setGeneration(9);
    EXPECT_EQ(9, state.getGeneration());
}