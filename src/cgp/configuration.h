#ifndef CGP__CONFIGURATION_H_INCLUDED__
#define CGP__CONFIGURATION_H_INCLUDED__

#include <cstring>
#include <map>

namespace cgp {

    class configuration {
        public:
            configuration();

            // setters
            void columns(unsigned int columns);
            void comparisonFitnessOperator(std::string comparisonFitnessOperator);
            void generations(unsigned int generations);
            void levelsBack(unsigned int levelsBack);
            void minimumFitnessSolution(double minimumFitnessSolution);
            void mutationProbability(double mutationProbability);
            void offspring(unsigned int offspring);
            void isOutputLastNode(bool isOutputLastNode);
            void outputs(unsigned int outputs);
            void rows(unsigned int rows);
            void runs(unsigned int runs);

            // getters
            unsigned int rows();
            unsigned int columns();
            unsigned int levelsBack();
            unsigned int runs();
            unsigned int outputs();
            unsigned int generations();
            unsigned int offspring();

            void toString() const;

        private:
            bool _isOutputLastNode;
            double _minimumFitnessSolution;
            double _mutationProbability;
            unsigned int _columns;
            unsigned int _generations;
            unsigned int _levelsBack;
            unsigned int _offspring;
            unsigned int _outputs;
            unsigned int _rows;
            unsigned int _runs;
            std::string _comparisonFitnessOperator;
    };

};

#endif
