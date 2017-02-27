/* Copyright 2017 Tiago Inácio */

#ifndef WORK_GITHUB_CGP_TOOLBOX_C___SRC_CGP_CGP_H_
#define WORK_GITHUB_CGP_TOOLBOX_C___SRC_CGP_CGP_H_

#include <cstring>
#include <map>

#include "./configuration.h"

namespace cgp {

class cgp {
 public:
    explicit cgp(configuration config);

    void setRows(int rows);

 private:
    const configuration _configuration;
};

};  // namespace cgp

#endif  // WORK_GITHUB_CGP_TOOLBOX_C___SRC_CGP_CGP_H_
