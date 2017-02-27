/* Copyright 2017 Tiago Inácio */

#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "src/cgp/cgp.h"
#include "src/cgp/configuration.h"

cgp::cgp::cgp(const configuration configuration) :
    _configuration(configuration)
    {}

