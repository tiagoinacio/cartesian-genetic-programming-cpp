/* Copyright 2017 Tiago Inácio */

#include <cstring>
#include <map>
#include <iostream>

#include "include/cgp.h"
#include "include/configuration.h"

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

    return 0;
}
