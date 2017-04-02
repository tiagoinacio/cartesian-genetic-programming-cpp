/* Copyright 2017 Tiago Inácio */

#include <iostream>
#include <memory>
#include <string>

#include "include/cgp.h"
#include "include/configuration.h"
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

double fitnessFunction() {
    return 1;
}

class InstructionSet {
 public:
    static double fn2(std::vector<double> args) {
        return args[0] + args[1];
    }
};

int main() {
    // Configuration
    cgp::Configuration configuration;

    configuration.isNodeOutputTheLastOne(false);
    configuration.setColumns(10);
    configuration.setComparisonOperator("<=");
    configuration.setFitnessThreshold(0.1);
    configuration.setGenerations(100);
    configuration.setLevelsBack(10);
    configuration.setFunctions(2);
    configuration.setMutationProbability(0.1);
    configuration.setOffspring(4);
    configuration.setProgramOutputs(1);
    configuration.setConnections(2);
    configuration.setParameters(2);
    configuration.setRows(1);
    configuration.setRuns(5);

    configuration.toString();
    cgp::CGP<double> cgp(configuration);

    // Parameters
    std::shared_ptr<cgp::Parameter<int> > firstParam =
        cgp::createParameter<int>(2, &plus);
    std::shared_ptr<cgp::Parameter<std::string> > secondParam =
        cgp::createParameter<std::string>();

    secondParam->setValue("old text");
    secondParam->setMutationFn(changeText);

    cgp.pushParameter(firstParam);
    cgp.pushParameter(secondParam);

    std::cout << firstParam->getValue() << std::endl;
    std::cout << secondParam->getValue() << std::endl;

    cgp.subscribe("on_init", callbackOnInit);

    cgp.pushFunction(fn1);
    cgp.pushFunction(&InstructionSet::fn2);

    cgp.addFitnessFunction(fitnessFunction);

    // Run
    cgp.run();

    return 0;
}
