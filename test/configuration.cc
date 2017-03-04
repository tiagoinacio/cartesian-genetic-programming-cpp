/* copyright Tiago Inácio 2017 */

#include <limits.h>
#include "gtest/gtest.h"
#include "configuration.h"

class ConfigurationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
};

// Default Properties
// Test number of rows
TEST_F(ConfigurationTest, rows){
    cgp::Configuration configuration;
    EXPECT_EQ(1, configuration.rows());
}

// Test number of columns
TEST_F(ConfigurationTest, columns){
    cgp::Configuration configuration;
    EXPECT_EQ(10, configuration.columns());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
