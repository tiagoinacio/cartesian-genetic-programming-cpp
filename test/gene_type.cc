// copyright Tiago Inácio

#include <limits.h>
#include <algorithm>   // for copy
#include <iostream>
#include <iterator>   // for ostream_iterator
#include <memory>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/gene_type.h"
#include "include/size.h"
#include "test/to_vec.h"

using testing::ElementsAre;

std::shared_ptr<cgp::Size> createMock(unsigned int rows, unsigned int columns,
    unsigned int connections, unsigned int parameters) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setRows(rows);
    configuration->setColumns(columns);
    configuration->setConnections(connections);
    configuration->setParameters(parameters);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    return size;
}

TEST(TC01, 1R_1C_1C_1P) {
    cgp::GeneType gene_type(createMock(1, 1, 1, 1));

    const int functionGenes[] = {1};
    const int connectionGenes[] = {2};
    const int parameterGenes[] = {3};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC02, 1R_1C_1C_0P) {
    const unsigned int rows = 1;
    const unsigned int columns = 1;
    const unsigned int connections = 1;
    const unsigned int parameters = 0;
    cgp::GeneType gene_type(createMock(rows, columns, connections, parameters));

    const int functionGenes[] = {1};
    const int connectionGenes[] = {2};
    const int parameterGenes[] = {};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC03, 1R_1C_3C_2P) {
    const unsigned int rows = 1;
    const unsigned int columns = 1;
    const unsigned int connections = 3;
    const unsigned int parameters = 2;
    cgp::GeneType gene_type(createMock(rows, columns, connections, parameters));

    const int functionGenes[] = {1};
    const int connectionGenes[] = {2, 3, 4};
    const int parameterGenes[] = {5, 6};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC04, 1R_2C_2C_3P) {
    cgp::GeneType gene_type(createMock(1, 2, 2, 3));

    int functionGenes[] = {1, 7};
    int connectionGenes[] = {2, 3, 8, 9};
    int parameterGenes[] = {4, 5, 6, 10, 11, 12};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC05, 5R_1C_2C_3P) {
    cgp::GeneType gene_type(createMock(5, 1, 2, 3));

    int functionGenes[] = {1, 7, 13, 19, 25};
    int connectionGenes[] = {2, 3, 8, 9, 14, 15, 20, 21, 26, 27};
    int parameterGenes[] = {
        4, 5, 6, 10, 11, 12, 16, 17, 18, 22, 23, 24, 28, 29, 30};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC05, 10R_1C_2C_3P) {
    cgp::GeneType gene_type(createMock(10, 1, 2, 3));

    int functionGenes[] = {1, 7, 13, 19, 25, 31, 37, 43, 49, 55};
    int connectionGenes[] = {2, 3, 8, 9, 14, 15, 20, 21, 26, 27, 32, 33, 38, 39,
        44, 45, 50, 51, 56, 57};
    int parameterGenes[] = {4, 5, 6, 10, 11, 12, 16, 17, 18, 22, 23, 24, 28, 29,
        30, 34, 35, 36, 40, 41, 42, 46, 47, 48, 52, 53, 54, 58, 59, 60};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC06, 5_3_0_2) {
    cgp::GeneType gene_type(createMock(5, 3, 0, 2));

    int functionGenes[] = {
        1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43};
    int connectionGenes[] = {};
    int parameterGenes[] = {2, 3, 5, 6, 8, 9, 11, 12, 14, 15, 17, 18, 20, 21,
        23, 24, 26, 27, 29, 30, 32, 33, 35, 36, 38, 39, 41, 42, 44, 45};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC07, 3_6_4_3) {
    cgp::GeneType gene_type(createMock(3, 6, 4, 3));

    int functionGenes[] = {1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97,
        105, 113, 121, 129, 137};
    int connectionGenes[] = {2, 3, 4, 5, 10, 11, 12, 13, 18, 19, 20, 21, 26, 27,
        28, 29, 34, 35, 36, 37, 42, 43, 44, 45, 50, 51, 52, 53, 58, 59, 60, 61,
        66, 67, 68, 69, 74, 75, 76, 77, 82, 83, 84, 85, 90, 91, 92, 93, 98, 99,
        100, 101, 106, 107, 108, 109, 114, 115, 116, 117, 122, 123, 124, 125,
        130, 131, 132, 133, 138, 139, 140, 141};
    int parameterGenes[] = {6, 7, 8, 14, 15, 16, 22, 23, 24, 30, 31, 32, 38, 39,
        40, 46, 47, 48, 54, 55, 56, 62, 63, 64, 70, 71, 72, 78, 79, 80, 86, 87,
        88, 94, 95, 96, 102, 103, 104, 110, 111, 112, 118, 119, 120, 126, 127,
        128, 134, 135, 136, 142, 143, 144};

    std::copy(gene_type.connectionGenes().begin(),
        gene_type.connectionGenes().end(),
        std::ostream_iterator<unsigned int>(std::cout, " "));

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}
