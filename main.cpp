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

double fn1(double a, double b) {
    return a * b;
}

double fn2(double a, double b) {
    return a + b;
}

std::string changeText(std::string x) {
    return "new text";
}

void callbackOnInit(std::shared_ptr<cgp::State> state) {
    std::cout << state->getGeneration() << std::endl;
}

int main() {
    // Configuration
    cgp::Configuration configuration;

    configuration.isNodeOutputTheLastOne(false);
    configuration.setColumns(1);
    configuration.setComparisonOperator(">=");
    configuration.setFitnessThreshold(0.1);
    configuration.setGenerations(1);
    configuration.setLevelsBack(1);
    configuration.setMutationProbability(0.1);
    configuration.setOffspring(1);
    configuration.setOutputs(1);
    configuration.setRows(1);
    configuration.setRows(5);
    configuration.setRuns(1);

    configuration.toString();
    cgp::CGP<double> cgp(configuration);

    // Parameters
    std::shared_ptr<cgp::Parameter<int> > firstParam =
        cgp::createParameter<int>(2, &plus);
    std::shared_ptr<cgp::Parameter<std::string> > secondParam =
        cgp::createParameter<std::string>();

    secondParam->setValue("old text");
    secondParam->setMutationFn(changeText);

    cgp.setParameter(firstParam);
    cgp.setParameter(secondParam);

    std::cout << firstParam->getValue() << std::endl;
    std::cout << secondParam->getValue() << std::endl;

    cgp.setCallback("on_init", callbackOnInit);

    cgp.pushToInstructionSet(fn1);
    cgp.pushToInstructionSet(fn2);

    // Run
    cgp.run();

    return 0;
}
