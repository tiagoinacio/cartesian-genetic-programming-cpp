#ifndef CONST__CONSTANTS_H_INCLUDED__
#define CONST__CONSTANTS_H_INCLUDED__

#include <cstring>

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
            const std::string COMPARISON_OPERATOR = ">=";
        }
    }
}

#endif
