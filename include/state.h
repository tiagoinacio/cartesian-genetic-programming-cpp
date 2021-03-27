// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_STATE_H_
#define INCLUDE_STATE_H_

#include <vector>

namespace cgp {

class State {
 public:
    State();
    unsigned int generation() const;
    unsigned int run() const;
    std::vector<int> activeNodes() const;
    std::vector<int> genes() const;

    void setGeneration(unsigned int generation);
    void setRun(unsigned int run);
    void setActiveNodes(std::vector<int> activeNodes);
    void setGenes(std::vector<int> genes);

 private:
    unsigned int generation_;
    unsigned int run_;
    std::vector<int> genes_;
    std::vector<int> activeNodes_;
};

}   // namespace cgp
#endif   // INCLUDE_STATE_H_
