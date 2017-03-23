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
    cgp::Configuration configuration;
    configuration.setRows(rows);
    configuration.setColumns(columns);
    configuration.setConnections(connections);
    configuration.setParameters(parameters);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    return size;
}

TEST(TC01, 1R_1C_1C_1P) {
    cgp::GeneType gene_type(createMock(1, 1, 1, 1));

    const int functionGenes[] = {0};
    const int connectionGenes[] = {1};
    const int parameterGenes[] = {2};

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

    const int functionGenes[] = {0};
    const int connectionGenes[] = {1};
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

    const int functionGenes[] = {0};
    const int connectionGenes[] = {1, 2, 3};
    const int parameterGenes[] = {4, 5};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC04, 1R_2C_2C_3P) {
    cgp::GeneType gene_type(createMock(1, 2, 2, 3));

    int functionGenes[] = {0, 6};
    int connectionGenes[] = {1, 2, 7, 8};
    int parameterGenes[] = {3, 4, 5, 9, 10, 11};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC05, 5R_1C_2C_3P) {
    cgp::GeneType gene_type(createMock(5, 1, 2, 3));

    int functionGenes[] = {0, 6, 12, 18, 24};
    int connectionGenes[] = {1, 2, 7, 8, 13, 14, 19, 20, 25, 26};
    int parameterGenes[] = {
        3, 4, 5, 9, 10, 11, 15, 16, 17, 21, 22, 23, 27, 28, 29};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC05, 10R_1C_2C_3P) {
    cgp::GeneType gene_type(createMock(10, 1, 2, 3));

    int functionGenes[] = {0, 6, 12, 18, 24, 30, 36, 42, 48, 54};
    int connectionGenes[] = {1, 2, 7, 8, 13, 14, 19, 20, 25, 26, 31, 32, 37, 38,
        43, 44, 49, 50, 55, 56};
    int parameterGenes[] = {3, 4, 5, 9, 10, 11, 15, 16, 17, 21, 22, 23, 27, 28,
        29, 33, 34, 35, 39, 40, 41, 45, 46, 47, 51, 52, 53, 57, 58, 59};

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
        0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42};
    int connectionGenes[] = {};
    int parameterGenes[] = {1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20,
        22, 23, 25, 26, 28, 29, 31, 32, 34, 35, 37, 38, 40, 41, 43, 44};

    EXPECT_EQ(toVec(functionGenes, gene_type.functionGenes().size()),
        gene_type.functionGenes());
    EXPECT_EQ(toVec(connectionGenes, gene_type.connectionGenes().size()),
        gene_type.connectionGenes());
    EXPECT_EQ(toVec(parameterGenes, gene_type.parameterGenes().size()),
        gene_type.parameterGenes());
}

TEST(TC07, 3_6_4_3) {
    cgp::GeneType gene_type(createMock(3, 6, 4, 3));

    int functionGenes[] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,
        104, 112, 120, 128, 136};
    int connectionGenes[] = {1, 2, 3, 4, 9, 10, 11, 12, 17, 18, 19, 20, 25, 26,
        27, 28, 33, 34, 35, 36, 41, 42, 43, 44, 49, 50, 51, 52, 57, 58, 59, 60,
        65, 66, 67, 68, 73, 74, 75, 76, 81, 82, 83, 84, 89, 90, 91, 92, 97, 98,
        99, 100, 105, 106, 107, 108, 113, 114, 115, 116, 121, 122, 123, 124,
        129, 130, 131, 132, 137, 138, 139, 140};
    int parameterGenes[] = {5, 6, 7, 13, 14, 15, 21, 22, 23, 29, 30, 31, 37, 38,
        39, 45, 46, 47, 53, 54, 55, 61, 62, 63, 69, 70, 71, 77, 78, 79, 85, 86,
        87, 93, 94, 95, 101, 102, 103, 109, 110, 111, 117, 118, 119, 125, 126,
        127, 133, 134, 135, 141, 142, 143};

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
