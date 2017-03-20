// copyright Tiago Inácio

#include <limits.h>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/size.h"

using testing::HasSubstr;

class SizeClass : public ::testing::Test {
 public:
    SizeClass() : size(configuration) {
    }

 protected:
    const cgp::Configuration configuration;
    cgp::Size size;
};

TEST_F(SizeClass, default_configuration) {
    EXPECT_EQ(2, size.connections());
    EXPECT_EQ(10, size.generations());
    EXPECT_EQ(1, size.programInputs());
    EXPECT_EQ(10, size.levelsBack());
    EXPECT_EQ(4, size.offspring());
    EXPECT_EQ(1, size.programOutputs());
    EXPECT_EQ(0, size.parameters());
    EXPECT_EQ(1, size.columns());
    EXPECT_EQ(5, size.runs());
    EXPECT_EQ(1, size.nodes());
    EXPECT_EQ(3, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(1, size.rows());
}

TEST(Size, nodes_25) {
    cgp::Configuration configuration;
    configuration.setRows(5);
    configuration.setColumns(5);
    cgp::Size size(configuration);

    EXPECT_EQ(2, size.connections());
    EXPECT_EQ(10, size.generations());
    EXPECT_EQ(1, size.programInputs());
    EXPECT_EQ(10, size.levelsBack());
    EXPECT_EQ(4, size.offspring());
    EXPECT_EQ(1, size.programOutputs());
    EXPECT_EQ(0, size.parameters());
    EXPECT_EQ(5, size.columns());
    EXPECT_EQ(5, size.runs());
    EXPECT_EQ(25, size.nodes());
    EXPECT_EQ(75, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(5, size.rows());
}

TEST(Size, nodes_5_rows) {
    cgp::Configuration configuration;
    configuration.setRows(5);
    configuration.setColumns(1);
    cgp::Size size(configuration);

    EXPECT_EQ(2, size.connections());
    EXPECT_EQ(10, size.generations());
    EXPECT_EQ(1, size.programInputs());
    EXPECT_EQ(10, size.levelsBack());
    EXPECT_EQ(4, size.offspring());
    EXPECT_EQ(1, size.programOutputs());
    EXPECT_EQ(0, size.parameters());
    EXPECT_EQ(1, size.columns());
    EXPECT_EQ(5, size.runs());
    EXPECT_EQ(5, size.nodes());
    EXPECT_EQ(15, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(5, size.rows());
}

TEST(Size, nodes_5_columns) {
    cgp::Configuration configuration;
    configuration.setRows(1);
    configuration.setColumns(5);
    cgp::Size size(configuration);

    EXPECT_EQ(2, size.connections());
    EXPECT_EQ(10, size.generations());
    EXPECT_EQ(1, size.programInputs());
    EXPECT_EQ(10, size.levelsBack());
    EXPECT_EQ(4, size.offspring());
    EXPECT_EQ(1, size.programOutputs());
    EXPECT_EQ(0, size.parameters());
    EXPECT_EQ(5, size.columns());
    EXPECT_EQ(5, size.runs());
    EXPECT_EQ(5, size.nodes());
    EXPECT_EQ(15, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(1, size.rows());
}

TEST(Size, nodes_10_5rows_2columns) {
    cgp::Configuration configuration;
    configuration.setRows(5);
    configuration.setColumns(2);
    cgp::Size size(configuration);

    EXPECT_EQ(10, size.nodes());
}

TEST(Size, nodes_10_5columns_2rows) {
    cgp::Configuration configuration;
    configuration.setRows(2);
    configuration.setColumns(5);
    cgp::Size size(configuration);

    EXPECT_EQ(10, size.nodes());
}

TEST(Size, genesPerNode_5) {
    cgp::Configuration configuration;
    configuration.setConnections(2);
    configuration.setParameters(2);
    cgp::Size size(configuration);

    EXPECT_EQ(5, size.genesPerNode());
}

TEST(Size, genesPerNode_11) {
    cgp::Configuration configuration;
    configuration.setConnections(4);
    configuration.setParameters(6);
    cgp::Size size(configuration);

    EXPECT_EQ(11, size.genesPerNode());
}

TEST(Size, genes_50) {
    cgp::Configuration configuration;
    configuration.setRows(1);
    configuration.setColumns(10);
    configuration.setConnections(2);
    configuration.setParameters(2);
    configuration.setProgramOutputs(1);
    cgp::Size size(configuration);

    EXPECT_EQ(50, size.genes());
}

TEST(Size, genes_60) {
    cgp::Configuration configuration;
    configuration.setRows(2);
    configuration.setColumns(6);
    configuration.setConnections(3);
    configuration.setParameters(1);
    cgp::Size size(configuration);

    EXPECT_EQ(60, size.genes());
}
