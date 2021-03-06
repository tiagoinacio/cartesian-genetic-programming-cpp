// copyright Tiago Inácio

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <utility>
#include <vector>

#include "include/configuration.h"
#include "include/fitness_args.h"
#include "include/gene.h"
#include "include/gene_type.h"
#include "include/genotype.h"
#include "include/size.h"
#include "include/state.h"
#include "test/to_vec.h"

using testing::ElementsAre;
using testing::Ge;
using testing::Le;
using testing::AllOf;

double mockFitnessFunction(cgp::FitnessArgs<int> args) {
    return 2;
}

TEST(genotype_constructor, function_genes_3_elements) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setConnections(0);
    configuration->setParameters(0);
    configuration->setFunctions(3);

    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    std::shared_ptr<cgp::GeneType> gene_type(new cgp::GeneType(size));
    std::shared_ptr<cgp::State> state(new cgp::State);
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters;
    std::vector<std::function<int(std::vector<int>)> > instruction_set;
    std::function<double(cgp::FitnessArgs<int>)> fitness_function = mockFitnessFunction;
    cgp::Genotype<int> genotype;

    genotype.create(state, configuration, size, gene_type, instruction_set,
        parameters, fitness_function);

    EXPECT_THAT(genotype.genes()[0], AllOf(Ge(0), Le(3)));
}

TEST(genotype_constructor, function_genes_1_element) {
    std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());
    configuration->setConnections(0);
    configuration->setParameters(0);
    configuration->setFunctions(1);
    std::shared_ptr<cgp::Size> size(new cgp::Size(configuration));
    std::shared_ptr<cgp::GeneType> gene_type(new cgp::GeneType(size));
    std::shared_ptr<cgp::State> state(new cgp::State);
    std::vector<std::function<int(std::vector<int>)> > instruction_set;
    std::vector<std::shared_ptr<cgp::ParameterInterface> > parameters;
    std::function<double(cgp::FitnessArgs<int>)> fitness_function = mockFitnessFunction;
    cgp::Genotype<int> genotype;

    genotype.create(state, configuration, size, gene_type, instruction_set,
        parameters, fitness_function);

    // first and only function
    EXPECT_THAT(genotype.genes()[0], 0);
}
