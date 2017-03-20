// copyright Tiago Inácio

#include <limits.h>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"

using testing::HasSubstr;

class ConfigurationClass : public ::testing::Test {
 protected:
    cgp::Configuration configuration;
};

TEST_F(ConfigurationClass, default_configuration) {
    EXPECT_EQ(1, configuration.columns());
    EXPECT_EQ("<=", configuration.comparisonOperator());
    EXPECT_EQ(0.01, configuration.fitnessThreshold());
    EXPECT_EQ(10, configuration.generations());
    EXPECT_EQ(10, configuration.levelsBack());
    EXPECT_EQ(0.1, configuration.mutationProbability());
    EXPECT_EQ(4, configuration.offspring());
    EXPECT_EQ(1, configuration.programOutputs());
    EXPECT_EQ(1, configuration.rows());
    EXPECT_EQ(5, configuration.runs());
    EXPECT_EQ(true, configuration.isNodeOutputTheLastOne());
}

TEST_F(ConfigurationClass, isNodeOutputTheLastOne) {
    configuration.isNodeOutputTheLastOne(false);
    EXPECT_EQ(false, configuration.isNodeOutputTheLastOne());

    configuration.isNodeOutputTheLastOne(true);
    EXPECT_EQ(true, configuration.isNodeOutputTheLastOne());
}

TEST_F(ConfigurationClass, setRows) {
    configuration.setRows(5);
    EXPECT_EQ(5, configuration.rows());

    configuration.setRows(15);
    EXPECT_EQ(15, configuration.rows());
}

TEST_F(ConfigurationClass, setConnections) {
    configuration.setConnections(5);
    EXPECT_EQ(5, configuration.connections());

    configuration.setConnections(15);
    EXPECT_EQ(15, configuration.connections());
}

TEST_F(ConfigurationClass, setColumns) {
    configuration.setColumns(5);
    EXPECT_EQ(5, configuration.columns());

    configuration.setColumns(15);
    EXPECT_EQ(15, configuration.columns());
}

TEST_F(ConfigurationClass, setLevelsBack) {
    configuration.setLevelsBack(5);
    EXPECT_EQ(5, configuration.levelsBack());

    configuration.setLevelsBack(15);
    EXPECT_EQ(15, configuration.levelsBack());
}

TEST_F(ConfigurationClass, setRuns) {
    configuration.setRuns(5);
    EXPECT_EQ(5, configuration.runs());

    configuration.setRuns(15);
    EXPECT_EQ(15, configuration.runs());
}

TEST_F(ConfigurationClass, setProgramOutputs) {
    configuration.setProgramOutputs(5);
    EXPECT_EQ(5, configuration.programOutputs());

    configuration.setProgramOutputs(15);
    EXPECT_EQ(15, configuration.programOutputs());
}

TEST_F(ConfigurationClass, setGenerations) {
    configuration.setGenerations(5);
    EXPECT_EQ(5, configuration.generations());

    configuration.setGenerations(15);
    EXPECT_EQ(15, configuration.generations());
}

TEST_F(ConfigurationClass, setProgramInputs) {
    configuration.setProgramInputs(5);
    EXPECT_EQ(5, configuration.programInputs());

    configuration.setProgramInputs(15);
    EXPECT_EQ(15, configuration.programInputs());
}

TEST_F(ConfigurationClass, setOffspring) {
    configuration.setOffspring(5);
    EXPECT_EQ(5, configuration.offspring());

    configuration.setOffspring(15);
    EXPECT_EQ(15, configuration.offspring());
}

TEST_F(ConfigurationClass, setMutationProbability_validArgs) {
    configuration.setMutationProbability(0.2);
    EXPECT_EQ(0.2, configuration.mutationProbability());

    configuration.setMutationProbability(0.5);
    EXPECT_EQ(0.5, configuration.mutationProbability());
}

TEST_F(ConfigurationClass, setMutationProbability_outOfRange) {
    try {
        configuration.setMutationProbability(-1);
        FAIL() << "Expected std::out_of_range";
    } catch (std::out_of_range const &err) {
        EXPECT_EQ(err.what(),
            std::string("Mutation probability must be superior to 0."));
    } catch (...) {
        FAIL() << "Expected std::out_of_range";
    }

    try {
        configuration.setMutationProbability(1.5);
        FAIL() << "Expected std::out_of_range";
    } catch (std::out_of_range const &err) {
        EXPECT_EQ(err.what(),
            std::string(
                "Mutation probability must be inferior or equal to 1."));
    } catch (...) {
        FAIL() << "Expected std::out_of_range";
    }
}

TEST_F(ConfigurationClass, setFitnessThreshold) {
    configuration.setFitnessThreshold(1);
    EXPECT_EQ(1, configuration.fitnessThreshold());

    configuration.setFitnessThreshold(0.001);
    EXPECT_EQ(0.001, configuration.fitnessThreshold());
}

TEST_F(ConfigurationClass, setComparisonOperator_) {
    configuration.setComparisonOperator(">");
    EXPECT_EQ(">", configuration.comparisonOperator());

    configuration.setComparisonOperator("<=");
    EXPECT_EQ("<=", configuration.comparisonOperator());
}

TEST_F(ConfigurationClass, toString) {
    testing::internal::CaptureStdout();

    configuration.toString();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_THAT(output, HasSubstr("isNodeOutputTheLastOne"));
    EXPECT_THAT(output, HasSubstr("fitnessThreshold"));
    EXPECT_THAT(output, HasSubstr("mutationProbability"));
    EXPECT_THAT(output, HasSubstr("columns"));
    EXPECT_THAT(output, HasSubstr("generations"));
    EXPECT_THAT(output, HasSubstr("levelsBack"));
    EXPECT_THAT(output, HasSubstr("offspring"));
    EXPECT_THAT(output, HasSubstr("programOutputs"));
    EXPECT_THAT(output, HasSubstr("rows"));
    EXPECT_THAT(output, HasSubstr("runs"));
    EXPECT_THAT(output, HasSubstr("comparisonOperator"));
}
