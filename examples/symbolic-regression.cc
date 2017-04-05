/* Copyright 2017 Tiago Inácio */

#include <iostream>
#include <memory>
#include <string>

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

double fitnessFunction(cgp::FitnessArgs<double> args) {
    std::cout << "calling fitness function: " << args.state()->generation()
              << std::endl;
    return 1;
}

class Fitness {
 public:
    static double fn(cgp::FitnessArgs<double> args) {
        return 2;
    }
};

class ProgramInputs {
 public:
    ProgramInputs() {
    }
};

class Configuration {
 public:
    static std::shared_ptr<cgp::Configuration> create() {
        std::shared_ptr<cgp::Configuration> configuration(new cgp::Configuration());

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
        configuration->setProgramInputs(2);
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

    return 0;
}
