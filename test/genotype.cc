// copyright Tiago Inácio

// #include <limits.h>
// #include <memory>
// #include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "include/configuration.h"
#include "include/function_gene.h"
#include "include/gene_type.h"
#include "include/genotype.h"
#include "include/size.h"
#include "include/state.h"
#include "test/to_vec.h"

using testing::ElementsAre;
using testing::Ge;
using testing::Le;
using testing::AllOf;

TEST(genotype_constructor, function_genes_5_elements) {
    cgp::Configuration configuration;
    configuration.setConnections(0);
    configuration.setParameters(0);
    configuration.setFunctions(5);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    std::shared_ptr<cgp::GeneType> gene_type(new cgp::GeneType(size));
    std::shared_ptr<cgp::State> state(new cgp::State);
    cgp::Genotype genotype;

    genotype.create(state, size, gene_type);

    EXPECT_THAT(genotype.genes()[0], AllOf(Ge(0),Le(5)));
}

TEST(genotype_constructor, function_genes_1_element) {
    cgp::Configuration configuration;
    configuration.setConnections(0);
    configuration.setParameters(0);
    configuration.setFunctions(1);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    std::shared_ptr<cgp::GeneType> gene_type(new cgp::GeneType(size));
    std::shared_ptr<cgp::State> state(new cgp::State);
    cgp::Genotype genotype;

    genotype.create(state, size, gene_type);

    EXPECT_THAT(genotype.genes()[0], 1);
}
