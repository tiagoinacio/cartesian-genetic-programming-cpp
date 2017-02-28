/* Copyright 2017 Tiago Inácio */

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_SRC_SHARED_CONSTANTS_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_SRC_SHARED_CONSTANTS_H_

namespace CONST {

namespace CFG {

namespace DEFAULT {

const bool IS_OUTPUT_LAST_NODE = true;
const unsigned int COLUMNS = 1;
const unsigned int GENERATIONS = 1;
const unsigned int LEVELS_BACK = 1;
const double MINIMUM_FITNESS_SOLUTION = 0.1;
const double MUTATION_PROBABILITY = 0.1;
const unsigned int OFFSPRING = 1;
const unsigned int OUTPUTS = 1;
const unsigned int ROWS = 1;
const unsigned int RUNS = 1;
const char COMPARISON_OPERATOR[] = ">=";

}  // namespace DEFAULT

}  // namespace CFG

}  // namespace CONST

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_SRC_SHARED_CONSTANTS_H_
