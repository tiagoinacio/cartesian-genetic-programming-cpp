/* Copyright 2017 Tiago Inácio */

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "src/cgp/configuration.h"
#include "src/shared/constants.h"

// constructors
cgp::configuration::configuration()
    : _isOutputLastNode(CONST::CFG::DEFAULT::IS_OUTPUT_LAST_NODE),
      _columns(CONST::CFG::DEFAULT::COLUMNS),
      _comparisonFitnessOperator(CONST::CFG::DEFAULT::COMPARISON_OPERATOR),
      _generations(CONST::CFG::DEFAULT::GENERATIONS),
      _levelsBack(CONST::CFG::DEFAULT::LEVELS_BACK),
      _minimumFitnessSolution(CONST::CFG::DEFAULT::MINIMUM_FITNESS_SOLUTION),
      _mutationProbability(CONST::CFG::DEFAULT::MUTATION_PROBABILITY),
      _offspring(CONST::CFG::DEFAULT::OFFSPRING),
      _outputs(CONST::CFG::DEFAULT::OUTPUTS),
      _rows(CONST::CFG::DEFAULT::ROWS),
      _runs(CONST::CFG::DEFAULT::RUNS) {}

void cgp::configuration::rows(unsigned int rows) { _rows = rows; }

void cgp::configuration::columns(unsigned int columns) { _columns = columns; }

void cgp::configuration::levelsBack(unsigned int levelsBack) {
    _levelsBack = levelsBack;
}

void cgp::configuration::runs(unsigned int runs) { _runs = runs; }

void cgp::configuration::outputs(unsigned int outputs) { _outputs = outputs; }

void cgp::configuration::generations(unsigned int generations) {
    _generations = generations;
}

void cgp::configuration::offspring(unsigned int offspring) {
    _offspring = offspring;
}

void cgp::configuration::mutationProbability(double mutationProbability) {
    if (_mutationProbability < 0) {
        throw std::invalid_argument(
            "Invalid argument for mutationProbability. Mutation probability "
            "must be superior to 0.");
    }

    _mutationProbability = mutationProbability;
}

void cgp::configuration::minimumFitnessSolution(double minimumFitnessSolution) {
    if (_minimumFitnessSolution < 0) {
        throw std::invalid_argument(
            "Invalid argument for minimumFitnessSolution. Minimum fitness "
            "solution must be superior to 0.");
    }

    _minimumFitnessSolution = minimumFitnessSolution;
}

void cgp::configuration::comparisonFitnessOperator(
    std::string comparisonFitnessOperator) {
    _comparisonFitnessOperator = comparisonFitnessOperator;
}

void cgp::configuration::isOutputLastNode(bool isOutputLastNode) {
    _isOutputLastNode = isOutputLastNode;
}

unsigned int cgp::configuration::rows() { return _rows; }

unsigned int cgp::configuration::columns() { return _columns; }

unsigned int cgp::configuration::levelsBack() { return _levelsBack; }

unsigned int cgp::configuration::runs() { return _runs; }

unsigned int cgp::configuration::outputs() { return _outputs; }

unsigned int cgp::configuration::generations() { return _generations; }

unsigned int cgp::configuration::offspring() { return _offspring; }

void cgp::configuration::toString() const {
    std::cout << "_isOutputLastNode: " << _isOutputLastNode << std::endl;
    std::cout << "_minimumFitnessSolution: " << _minimumFitnessSolution
              << std::endl;
    std::cout << "_mutationProbability: " << _mutationProbability << std::endl;
    std::cout << "_columns: " << _columns << std::endl;
    std::cout << "_generations: " << _generations << std::endl;
    std::cout << "_levelsBack: " << _levelsBack << std::endl;
    std::cout << "_offspring: " << _offspring << std::endl;
    std::cout << "_outputs: " << _outputs << std::endl;
    std::cout << "_rows: " << _rows << std::endl;
    std::cout << "_runs: " << _runs << std::endl;
    std::cout << "_comparisonFitnessOperator: " << _comparisonFitnessOperator
              << std::endl;
}
