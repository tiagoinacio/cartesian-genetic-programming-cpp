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

    // setters
    void isNodeOutputTheLastOne(bool isNodeOutputTheLastOne);
    void setColumns(unsigned int columns);
    void setComparisonOperator(std::string comparisonOperator);
    void setFitnessThreshold(double fitnessThreshold);
    void setGenerations(unsigned int generations);
    void setLevelsBack(unsigned int levelsBack);
    void setMutationProbability(double mutationProbability);
    void setOffspring(unsigned int offspring);
    void setOutputs(unsigned int outputs);
    void setRows(unsigned int rows);
    void setRuns(unsigned int runs);

    // getters
    unsigned int columns();
    unsigned int generations();
    unsigned int levelsBack();
    unsigned int offspring();
    unsigned int outputs();
    unsigned int rows();
    unsigned int runs();

    void toString() const;

 private:
    unsigned int _columns;
    std::string _comparisonOperator;
    double _fitnessThreshold;
    unsigned int _generations;
    unsigned int _levelsBack;
    double _mutationProbability;
    unsigned int _offspring;
    unsigned int _outputs;
    unsigned int _rows;
    unsigned int _runs;
    bool _isNodeOutputTheLastOne;
};

};  // namespace cgp

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_CONFIGURATION_H_
