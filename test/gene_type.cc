// copyright Tiago Inácio

#include <limits.h>
#include <memory>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/gene_type.h"
#include "include/size.h"

using testing::ElementsAre;

std::shared_ptr<cgp::Size> createMock(unsigned int rows, unsigned int columns,
    unsigned int parameters, unsigned int connections) {
    cgp::Configuration configuration;
    configuration.setRows(rows);
    configuration.setColumns(columns);
    configuration.setParameters(parameters);
    configuration.setConnections(connections);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    return size;
}

TEST(calculateConnectionGenes, 1_1_2_3) {
    unsigned int rows = 1;
    unsigned int columns = 1;
    unsigned int parameters = 2;
    unsigned int connections = 3;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1, 2, 3};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}

TEST(calculateConnectionGenes, 1_1_0_2) {
    unsigned int rows = 1;
    unsigned int columns = 1;
    unsigned int parameters = 0;
    unsigned int connections = 2;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1, 2};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}

TEST(calculateConnectionGenes, 1_1_1_1) {
    unsigned int rows = 1;
    unsigned int columns = 1;
    unsigned int parameters = 1;
    unsigned int connections = 1;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}

TEST(calculateConnectionGenes, 1_2_2_3) {
    unsigned int rows = 1;
    unsigned int columns = 2;
    unsigned int parameters = 2;
    unsigned int connections = 3;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1, 2, 3, 7, 8, 9};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}

TEST(calculateConnectionGenes, 5_1_2_3) {
    unsigned int rows = 5;
    unsigned int columns = 1;
    unsigned int parameters = 2;
    unsigned int connections = 3;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1, 2, 3, 7, 8, 9, 13, 14, 15, 19, 20, 21, 25, 26, 27};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}

TEST(calculateConnectionGenes, 10_1_2_3) {
    unsigned int rows = 10;
    unsigned int columns = 1;
    unsigned int parameters = 2;
    unsigned int connections = 3;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1, 2, 3, 7, 8, 9, 13, 14, 15, 19, 20, 21, 25, 26, 27, 31,
        32, 33, 37, 38, 39, 43, 44, 45, 49, 50, 51, 55, 56, 57};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}

TEST(calculateConnectionGenes, 10_1_0_2) {
    unsigned int rows = 10;
    unsigned int columns = 1;
    unsigned int parameters = 0;
    unsigned int connections = 2;
    cgp::GeneType gene_type(createMock(rows, columns, parameters, connections));

    const int arr[] = {1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23,
        25, 26, 28, 29};
    std::vector<unsigned int> expected(arr, arr + sizeof(arr) / sizeof(arr[0]));

    EXPECT_EQ(expected, gene_type.connectionGenes());
}
