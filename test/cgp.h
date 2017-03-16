// copyright Tiago Inácio

#include <limits.h>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/cgp.h"
#include "include/configuration.h"

using testing::ElementsAre;

cgp::State state;

void onInitCallback(const cgp::State& stateCb) {
    state = stateCb;
}

double plus(std::vector<double> args) {
    return args[0] * args[1];
}

class CGPClass : public ::testing::Test {
 public:
    CGPClass() : configuration_(), cgp(configuration_) {
        cgp.pushFunction(plus);
    }
    cgp::Configuration configuration_;
    cgp::CGP<double> cgp;
};

TEST_F(CGPClass, setCallback_valid) {
    cgp.setCallback("on_init", &onInitCallback);
    EXPECT_EQ(0, state.generation());

    cgp.run();
    EXPECT_EQ(1, state.generation());
}

TEST_F(CGPClass, setCallback_invalid) {
    try {
        cgp.setCallback("on_fake_callback", &onInitCallback);
        FAIL() << "Not a valid event callback.";
    } catch (std::out_of_range const &err) {
        EXPECT_EQ(err.what(),
            std::string(
                "Not a valid event callback."));
    } catch (...) {
        FAIL() << "Expected std::out_of_range";
    }
}
