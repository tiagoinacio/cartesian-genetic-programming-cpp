// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CONFIGURATION_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CONFIGURATION_H_

#include <map>
#include <string>

namespace cgp {

class Configuration {
 public:
    Configuration();

    void isNodeOutputTheLastOne(bool isNodeOutputTheLastOne);
    void setConnections(unsigned int connections);
    void setColumns(unsigned int columns);
    void setComparisonOperator(std::string comparisonOperator);
    void setFitnessThreshold(double fitnessThreshold);
    void setGenerations(unsigned int generations);
    void setInputs(unsigned int inputs);
    void setLevelsBack(unsigned int levelsBack);
    void setMutationProbability(double mutationProbability);
    void setOffspring(unsigned int offspring);
    void setOutputs(unsigned int outputs);
    void setRows(unsigned int rows);
    void setRuns(unsigned int runs);

    bool isNodeOutputTheLastOne();
    unsigned int columns();
    unsigned int connections();
    std::string comparisonOperator();
    double fitnessThreshold();
    unsigned int generations();
    unsigned int inputs();
    unsigned int levelsBack();
    double mutationProbability();
    unsigned int offspring();
    unsigned int outputs();
    unsigned int rows();
    unsigned int runs();

    void toString() const;

 private:
    unsigned int columns_;
    unsigned int connections_;
    std::string comparisonOperator_;
    double fitnessThreshold_;
    unsigned int generations_;
    unsigned int inputs_;
    unsigned int levelsBack_;
    double mutationProbability_;
    unsigned int offspring_;
    unsigned int outputs_;
    unsigned int rows_;
    unsigned int runs_;
    bool isNodeOutputTheLastOne_;
};

};   // namespace cgp

#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CONFIGURATION_H_
