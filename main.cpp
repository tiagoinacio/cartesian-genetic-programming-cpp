/* Copyright 2017 Tiago Inácio */

#include <cstring>
#include <map>
#include <iostream>

#include "include/cgp.h"
#include "include/configuration.h"

int main() {
    cgp::configuration configuration;

    configuration.rows(5);
    configuration.isOutputLastNode(false);
    configuration.columns(1);
    configuration.comparisonFitnessOperator(">=");
    configuration.generations(1);
    configuration.levelsBack(1);
    configuration.minimumFitnessSolution(0.1);
    configuration.mutationProbability(0.1);
    configuration.offspring(1);
    configuration.outputs(1);
    configuration.rows(1);
    configuration.runs(1);

    configuration.toString();

    cgp::cgp cgp(configuration);

    return 0;
}
