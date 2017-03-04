// Copyright 2017
// Tiago Inácio

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include "include/configuration.h"

// constructors
cgp::Configuration::Configuration()
    : _columns(10),
    _comparisonOperator(">="),
    _fitnessThreshold(0.01),
    _generations(10),
    _levelsBack(10),
    _mutationProbability(0.1),
    _offspring(4),
    _outputs(1),
    _rows(1),
    _runs(5),
    _isNodeOutputTheLastOne(true)
{}

void cgp::Configuration::setRows(unsigned int rows) {
    _rows = rows;
}

void cgp::Configuration::setColumns(unsigned int columns) {
    _columns = columns;
}

void cgp::Configuration::setLevelsBack(unsigned int levelsBack) {
    _levelsBack = levelsBack;
}

void cgp::Configuration::setRuns(unsigned int runs) {
    _runs = runs;
}

void cgp::Configuration::setOutputs(unsigned int outputs) {
    _outputs = outputs;
}

void cgp::Configuration::setGenerations(unsigned int generations) {
    _generations = generations;
}

void cgp::Configuration::setOffspring(unsigned int offspring) {
    _offspring = offspring;
}

void cgp::Configuration::setMutationProbability(double mutationProbability) {
    if (_mutationProbability < 0) {
        throw std::invalid_argument(
                "Invalid argument for mutationProbability. Mutation probability"
                " must be superior to 0.");
    }

    if (_mutationProbability > 100) {
        throw std::invalid_argument(
                "Invalid argument for mutationProbability. Mutation probability"
                " must be inferior or equal to 100.");
    }

    _mutationProbability = mutationProbability;
}

void cgp::Configuration::setFitnessThreshold(double fitnessThreshold) {
    _fitnessThreshold = fitnessThreshold;
}

void cgp::Configuration::setComparisonOperator(std::string comparisonOperator) {
    _comparisonOperator = comparisonOperator;
}

void cgp::Configuration::isNodeOutputTheLastOne(bool isNodeOutputTheLastOne) {
    _isNodeOutputTheLastOne = isNodeOutputTheLastOne;
}

unsigned int cgp::Configuration::rows() {
    return _rows;
}

unsigned int cgp::Configuration::columns() {
    return _columns;
}

unsigned int cgp::Configuration::levelsBack() {
    return _levelsBack;
}

unsigned int cgp::Configuration::runs() {
    return _runs;
}

unsigned int cgp::Configuration::outputs() {
    return _outputs;
}

unsigned int cgp::Configuration::generations() {
    return _generations;
}

unsigned int cgp::Configuration::offspring() {
    return _offspring;
}

void cgp::Configuration::toString() const {
    std::cout << "_isNodeOutputTheLastOne: " << _isNodeOutputTheLastOne
        << std::endl;
    std::cout << "_fitnessThreshold: " << _fitnessThreshold << std::endl;
    std::cout << "_mutationProbability: " << _mutationProbability << std::endl;
    std::cout << "_columns: " << _columns << std::endl;
    std::cout << "_generations: " << _generations << std::endl;
    std::cout << "_levelsBack: " << _levelsBack << std::endl;
    std::cout << "_offspring: " << _offspring << std::endl;
    std::cout << "_outputs: " << _outputs << std::endl;
    std::cout << "_rows: " << _rows << std::endl;
    std::cout << "_runs: " << _runs << std::endl;
    std::cout << "_comparisonOperator: " << _comparisonOperator << std::endl;
}
