// copyright Tiago Inácio

#include "include/configuration.h"
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

cgp::Configuration::Configuration()
    : columns_(1),
      comparisonOperator_("<="),
      connections_(2),
      fitnessThreshold_(0.01),
      functions_(1),
      generations_(10),
      isNodeOutputTheLastOne_(true),
      levelsBack_(10),
      mutationProbability_(0.1),
      offspring_(4),
      parameters_(0),
      program_inputs_(1),
      program_outputs_(1),
      rows_(1),
      debug_(true),
      runs_(5) {
}

void cgp::Configuration::setRows(unsigned int rows) {
    rows_ = rows;
}

void cgp::Configuration::setDebug(bool debug) {
    debug_ = debug;
}

void cgp::Configuration::setFunctions(unsigned int functions) {
    functions_ = functions;
}

void cgp::Configuration::setParameters(unsigned int parameters) {
    parameters_ = parameters;
}

void cgp::Configuration::setConnections(unsigned int connections) {
    connections_ = connections;
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

void cgp::Configuration::setProgramInputs(unsigned int programInputs) {
    program_inputs_ = programInputs;
}

void cgp::Configuration::setProgramOutputs(unsigned int programOutputs) {
    program_outputs_ = programOutputs;
}

void cgp::Configuration::setGenerations(unsigned int generations) {
    generations_ = generations;
}

void cgp::Configuration::setOffspring(unsigned int offspring) {
    offspring_ = offspring;
}

void cgp::Configuration::setMutationProbability(double mutationProbability) {
    if (mutationProbability < 0) {
        throw std::out_of_range("Mutation probability must be superior to 0.");
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

unsigned int cgp::Configuration::rows() const {
    return rows_;
}

unsigned int cgp::Configuration::columns() const {
    return columns_;
}

unsigned int cgp::Configuration::functions() const {
    return functions_;
}

bool cgp::Configuration::debug() const {
    return debug_;
}

unsigned int cgp::Configuration::parameters() const {
    return parameters_;
}

unsigned int cgp::Configuration::levelsBack() const {
    return levelsBack_;
}

std::string cgp::Configuration::comparisonOperator() const {
    return comparisonOperator_;
}

unsigned int cgp::Configuration::programInputs() const {
    return program_inputs_;
}

double cgp::Configuration::fitnessThreshold() const {
    return fitnessThreshold_;
}

bool cgp::Configuration::isNodeOutputTheLastOne() const {
    return isNodeOutputTheLastOne_;
}

double cgp::Configuration::mutationProbability() const {
    return mutationProbability_;
}

unsigned int cgp::Configuration::runs() const {
    return runs_;
}

unsigned int cgp::Configuration::programOutputs() const {
    return program_outputs_;
}

unsigned int cgp::Configuration::generations() const {
    return generations_;
}

unsigned int cgp::Configuration::connections() const {
    return connections_;
}

unsigned int cgp::Configuration::offspring() const {
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
    std::cout << "connections: " << connections_ << std::endl;
    std::cout << "parameters: " << parameters_ << std::endl;
    std::cout << "offspring: " << offspring_ << std::endl;
    std::cout << "programInputs: " << program_inputs_ << std::endl;
    std::cout << "programOutputs: " << program_outputs_ << std::endl;
    std::cout << "rows: " << rows_ << std::endl;
    std::cout << "runs: " << runs_ << std::endl;
    std::cout << "comparisonOperator: " << comparisonOperator_ << std::endl;
    std::cout << "*******************************" << std::endl;
}
