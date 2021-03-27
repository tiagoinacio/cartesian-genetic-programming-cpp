// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_CONFIGURATION_H_
#define INCLUDE_CONFIGURATION_H_

#include <map>
#include <string>

namespace cgp {

class Configuration {
 public:
    Configuration();

    void isNodeOutputTheLastOne(bool isNodeOutputTheLastOne);
    void setDebug(bool debug);
    void setConnections(unsigned int connections);
    void setParameters(unsigned int parameters);
    void setColumns(unsigned int columns);
    void setComparisonOperator(std::string comparisonOperator);
    void setFitnessThreshold(double fitnessThreshold);
    void setGenerations(unsigned int generations);
    void setProgramInputs(unsigned int programInputs);
    void setLevelsBack(unsigned int levelsBack);
    void setMutationProbability(double mutationProbability);
    void setOffspring(unsigned int offspring);
    void setFunctions(unsigned int functions);
    void setProgramOutputs(unsigned int programOutputs);
    void setRows(unsigned int rows);
    void setRuns(unsigned int runs);

    bool isNodeOutputTheLastOne() const;
    bool debug() const;
    unsigned int columns() const;
    unsigned int connections() const;
    std::string comparisonOperator() const;
    double fitnessThreshold() const;
    unsigned int generations() const;
    unsigned int programInputs() const;
    unsigned int functions() const;
    unsigned int levelsBack() const;
    double mutationProbability() const;
    unsigned int offspring() const;
    unsigned int programOutputs() const;
    unsigned int rows() const;
    unsigned int runs() const;
    unsigned int parameters() const;

    void toString() const;

 private:
    unsigned int columns_;
    std::string comparisonOperator_;
    unsigned int connections_;
    double fitnessThreshold_;
    unsigned int functions_;
    unsigned int generations_;
    bool debug_;
    bool isNodeOutputTheLastOne_;
    unsigned int levelsBack_;
    double mutationProbability_;
    unsigned int offspring_;
    unsigned int parameters_;
    unsigned int program_inputs_;
    unsigned int program_outputs_;
    unsigned int rows_;
    unsigned int runs_;
};

};   // namespace cgp

#endif   // INCLUDE_CONFIGURATION_H_
