/* Copyright 2017 Tiago Inácio */

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "include/cgp.h"
#include "include/configuration.h"
#include "include/fitness_args.h"
#include "include/parameter.h"
#include "include/state.h"

int plus(int x) {
    return x + 2;
}

double fn1(std::vector<double> args) {
    return args[0] * args[1];
}

std::string changeText(std::string x) {
    return "new text";
}

void callbackOnInit(const cgp::Event& event) {
    std::cout << "generations: " << event.size()->generations() << std::endl;
    std::cout << "generation: " << event.state()->generation() << std::endl;
}

std::string getFunctionString(int x) {
    switch (x) {
        case 0:
            return "+";
        case 1:
            return "-";
        case 2:
            return "*";
        case 3:
            return "/";
    }
    return "++++";
}

struct program_inputs {};

class Fitness {
 public:
    static double fn(cgp::FitnessArgs<double> args) {
        std::cout << "calling fitness function" << std::endl;
        static std::vector<double> x;
        static std::vector<double> y;
        for (double i = -1; i <= 1; i = i + 0.04) {
            std::cout << i;
            x.push_back(i);
            y.push_back(pow(i, 6) - 2 * pow(i, 4) + pow(i, 2));
        }

        double score;
        std::map<int, double> node_values;
        std::set<int> active_nodes = args.activeNodes();
        std::set<int>::iterator iterator;
        for (int i = 0; i < 50; ++i) {
            node_values[0] = x[i];

            std::cout << "active nodes: ";
            for (std::set<int>::iterator e = active_nodes.begin(); e != active_nodes.end(); ++e)
                    std::cout << *e << ' ';
            std::cout << std::endl;
            std::cout << node_values[0] << std::endl << std::endl;
            for (iterator = active_nodes.begin();
                 iterator != active_nodes.end(); ++iterator) {
                if (*iterator < args.size()->programInputs()) {
                    continue;
                }

                // get the gene index that points to the function-gene of the
                // active node
                int fn_gene_index = (*iterator) * args.size()->genesPerNode() +
                                    args.size()->programInputs() -
                                    args.size()->genesPerNode();
                std::cout << "fn_gene_index " << fn_gene_index << " of node "
                          << *iterator << std::endl;
                std::vector<double> fn_args;
                std::vector<int> genes = args.state()->genes();
                fn_args.push_back(node_values[genes[fn_gene_index + 1]]);
                fn_args.push_back(node_values[genes[fn_gene_index + 2]]);

                node_values[*iterator] =
                    args.instructionSet()[genes[fn_gene_index]](fn_args);

                std::cout << "node " << *iterator << " = "
                          << node_values[*iterator] << std::endl
                          << genes[fn_gene_index + 1] << " "
                          << getFunctionString(genes[fn_gene_index]) << " "
                          << genes[fn_gene_index + 2] << " " << std::endl
                          << node_values[genes[fn_gene_index + 1]] << " "
                          << getFunctionString(genes[fn_gene_index]) << " "
                          << node_values[genes[fn_gene_index + 2]] << " "
                          << std::endl
                          << std::endl;
            }
        }

        return 1;
    }
};

class Configuration {
 public:
    static std::shared_ptr<cgp::Configuration> create() {
        std::shared_ptr<cgp::Configuration> configuration(
            new cgp::Configuration());

        configuration->isNodeOutputTheLastOne(false);
        configuration->setRows(1);
        configuration->setColumns(10);
        configuration->setLevelsBack(10);
        configuration->setComparisonOperator("<=");
        configuration->setFitnessThreshold(0.1);
        configuration->setGenerations(1000);
        configuration->setRuns(5);
        configuration->setFunctions(4);
        configuration->setMutationProbability(0.2);
        configuration->setOffspring(4);
        configuration->setProgramOutputs(1);
        configuration->setProgramInputs(1);
        configuration->setConnections(2);
        configuration->setParameters(0);

        return configuration;
    }
};

class InstructionSet {
 public:
    static double sum(std::vector<double> args) {
        return args[0] + args[1];
    }
    static double subtract(std::vector<double> args) {
        return args[0] - args[1];
    }
    static double times(std::vector<double> args) {
        return args[0] * args[1];
    }
    static double division(std::vector<double> args) {
        if (args[1] != 0) {
            return args[0] / args[1];
        }
        return args[0];
    }
};

int main() {
    // Configuration
    cgp::CGP<double> cgp(Configuration::create());

    // Parameters
    // std::shared_ptr<cgp::Parameter<int> > firstParam =
    //     cgp::createParameter<int>(2, &plus);
    // std::shared_ptr<cgp::Parameter<std::string> > secondParam =
    //     cgp::createParameter<std::string>();
    //
    // secondParam->setValue("old text");
    // secondParam->setMutationFn(changeText);

    // cgp.pushParameter(firstParam);
    // cgp.pushParameter(secondParam);

    cgp.subscribe("on_init", callbackOnInit);

    cgp.pushFunction(&InstructionSet::sum);
    cgp.pushFunction(&InstructionSet::subtract);
    cgp.pushFunction(&InstructionSet::times);
    cgp.pushFunction(&InstructionSet::division);

    cgp.addFitnessFunction(&Fitness::fn);

    cgp.run();
    std::cout << "Symbolic regression example" << std::endl;

    return 0;
}
