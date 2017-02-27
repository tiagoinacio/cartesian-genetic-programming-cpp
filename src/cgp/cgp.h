#ifndef CGP__CGP_H_INCLUDED__
#define CGP__CGP_H_INCLUDED__

#include <cstring>
#include <map>

#include "configuration.h"

namespace cgp {

    class cgp {
        public:
            cgp(configuration config);

            // setters
            void setRows(int rows);
        private:
            const configuration _configuration;
    };

};

#endif
