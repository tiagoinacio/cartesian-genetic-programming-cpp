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

TEST(genotype_constructor, function_genes) {
    cgp::Configuration configuration;
    configuration.setConnections(0);
    configuration.setParameters(0);
    configuration.setFunctions(2);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    std::shared_ptr<cgp::GeneType> gene_type(new cgp::GeneType(size));
    std::shared_ptr<cgp::State> state(new cgp::State);
    cgp::Genotype genotype;

    genotype.create(state, size, gene_type);

    const int genes_[] = {1};

    EXPECT_EQ(genotype.genes(), toVec(genes_, genotype.genes().size()));
}
