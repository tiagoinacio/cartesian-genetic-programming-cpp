// copyright Tiago Inácio

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include "include/configuration.h"

cgp::Configuration::Configuration()
    : columns_(10),
    comparisonOperator_("<="),
    fitnessThreshold_(0.01),
    generations_(10),
    levelsBack_(10),
    mutationProbability_(0.1),
    offspring_(4),
    outputs_(1),
    rows_(1),
    runs_(5),
    isNodeOutputTheLastOne_(true)
{}

void cgp::Configuration::setRows(unsigned int rows) {
    rows_ = rows;
}

void cgp::Configuration::setColumns(unsigned int columns) {
    columns_ = columns;
}

void cgp::Configuration::setLevelsBack(unsigned int levelsBack) {
    levelsBack_ = levelsBack;
}

void cgp::Configuration::setRuns(unsigned int runs) {
    runs_ = runs;
}

void cgp::Configuration::setInputs(unsigned int inputs) {
    inputs_ = inputs;
}

void cgp::Configuration::setOutputs(unsigned int outputs) {
    outputs_ = outputs;
}

void cgp::Configuration::setGenerations(unsigned int generations) {
    generations_ = generations;
}

void cgp::Configuration::setOffspring(unsigned int offspring) {
    offspring_ = offspring;
}

void cgp::Configuration::setMutationProbability(double mutationProbability) {
    if (mutationProbability < 0) {
        throw std::out_of_range(
                "Mutation probability must be superior to 0.");
    }

    if (mutationProbability > 1) {
        throw std::out_of_range(
                "Mutation probability must be inferior or equal to 1.");
    }

    mutationProbability_ = mutationProbability;
}

void cgp::Configuration::setFitnessThreshold(double fitnessThreshold) {
    fitnessThreshold_ = fitnessThreshold;
}

void cgp::Configuration::setComparisonOperator(std::string comparisonOperator) {
    comparisonOperator_ = comparisonOperator;
}

void cgp::Configuration::isNodeOutputTheLastOne(bool isNodeOutputTheLastOne) {
    isNodeOutputTheLastOne_ = isNodeOutputTheLastOne;
}

unsigned int cgp::Configuration::rows() {
    return rows_;
}

unsigned int cgp::Configuration::columns() {
    return columns_;
}

unsigned int cgp::Configuration::levelsBack() {
    return levelsBack_;
}

std::string cgp::Configuration::comparisonOperator() {
    return comparisonOperator_;
}

unsigned int cgp::Configuration::inputs() {
    return inputs_;
}

double cgp::Configuration::fitnessThreshold() {
    return fitnessThreshold_;
}

bool cgp::Configuration::isNodeOutputTheLastOne() {
    return isNodeOutputTheLastOne_;
}

double cgp::Configuration::mutationProbability() {
    return mutationProbability_;
}

unsigned int cgp::Configuration::runs() {
    return runs_;
}

unsigned int cgp::Configuration::outputs() {
    return outputs_;
}

unsigned int cgp::Configuration::generations() {
    return generations_;
}

unsigned int cgp::Configuration::offspring() {
    return offspring_;
}

void cgp::Configuration::toString() const {
    std::cout << "*******************************" << std::endl;
    std::cout << "isNodeOutputTheLastOne: " << isNodeOutputTheLastOne_
        << std::endl;
    std::cout << "fitnessThreshold: " << fitnessThreshold_ << std::endl;
    std::cout << "mutationProbability: " << mutationProbability_ << std::endl;
    std::cout << "columns: " << columns_ << std::endl;
    std::cout << "generations: " << generations_ << std::endl;
    std::cout << "levelsBack: " << levelsBack_ << std::endl;
    std::cout << "offspring: " << offspring_ << std::endl;
    std::cout << "inputs: " << inputs_ << std::endl;
    std::cout << "outputs: " << outputs_ << std::endl;
    std::cout << "rows: " << rows_ << std::endl;
    std::cout << "runs: " << runs_ << std::endl;
    std::cout << "comparisonOperator: " << comparisonOperator_ << std::endl;
    std::cout << "*******************************" << std::endl;
}
