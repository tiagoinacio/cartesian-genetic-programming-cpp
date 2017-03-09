/* Copyright 2017 Tiago Inácio */

#include <string>
#include <iostream>

#include "include/cgp.h"
#include "include/configuration.h"
#include "include/parameter.h"

int plus(int x) {
    return x + 2;
}

std::string changeText(std::string x) {
    return "new text";
}

int main() {
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
    cgp::CGP cgp(configuration);

    std::shared_ptr<cgp::Parameter<int> > firstParam(new cgp::Parameter<int>(2, &plus));

    std::cout << firstParam->getValue() << std::endl;
    firstParam->mutation();
    std::cout << firstParam->getValue() << std::endl;

    std::shared_ptr<cgp::Parameter<std::string> > secondParam(new cgp::Parameter<std::string>());

    secondParam->setValue("old text");
    secondParam->setMutationFn(changeText);
    std::cout << secondParam->getValue() << std::endl;
    secondParam->mutation();
    std::cout << secondParam->getValue() << std::endl;

    cgp.addParameter(firstParam);
    cgp.addParameter(secondParam);

    return 0;
}
