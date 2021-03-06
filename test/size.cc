// copyright Tiago Inácio

#include <limits.h>
#include <memory>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/size.h"

using testing::HasSubstr;

TEST(SizeClass, default_configuration) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration);
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
    EXPECT_EQ(1, size.nodes());
    EXPECT_EQ(3, size.genesInNodes());
    EXPECT_EQ(5, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(1, size.rows());
}

TEST(Size, nodes_25) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(5);
    configuration->setColumns(5);
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
    EXPECT_EQ(75, size.genesInNodes());
    EXPECT_EQ(77, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(5, size.rows());
}

TEST(Size, nodes_5_rows) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(5);
    configuration->setColumns(1);
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
    EXPECT_EQ(15, size.genesInNodes());
    EXPECT_EQ(17, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(5, size.rows());
}

TEST(Size, nodes_5_columns) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(1);
    configuration->setColumns(5);
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
    EXPECT_EQ(15, size.genesInNodes());
    EXPECT_EQ(17, size.genes());
    EXPECT_EQ(3, size.genesPerNode());
    EXPECT_EQ(1, size.rows());
}

TEST(Size, nodes_10_5rows_2columns) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(5);
    configuration->setColumns(2);
    cgp::Size size(configuration);

    EXPECT_EQ(10, size.nodes());
}

TEST(Size, nodes_10_5columns_2rows) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(2);
    configuration->setColumns(5);
    cgp::Size size(configuration);

    EXPECT_EQ(10, size.nodes());
}

TEST(Size, genesPerNode_5) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setConnections(2);
    configuration->setParameters(2);
    cgp::Size size(configuration);

    EXPECT_EQ(5, size.genesPerNode());
}

TEST(Size, genesPerNode_11) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setConnections(4);
    configuration->setParameters(6);
    cgp::Size size(configuration);

    EXPECT_EQ(11, size.genesPerNode());
}

TEST(Size, genes_50) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(1);
    configuration->setColumns(10);
    configuration->setConnections(2);
    configuration->setParameters(2);
    configuration->setProgramOutputs(1);
    cgp::Size size(configuration);

    EXPECT_EQ(50, size.genesInNodes());
    EXPECT_EQ(52, size.genes());
}

TEST(Size, genes_62) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(2);
    configuration->setColumns(6);
    configuration->setConnections(3);
    configuration->setParameters(1);
    cgp::Size size(configuration);

    EXPECT_EQ(60, size.genesInNodes());
    EXPECT_EQ(62, size.genes());
}
