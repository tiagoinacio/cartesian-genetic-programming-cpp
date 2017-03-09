// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_PARAMETER_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_PARAMETER_H_

#include <stdexcept>

namespace cgp {

class ParameterBase {
};

template <class T>
class Parameter : public ParameterBase {
 public:
    Parameter() :
        isMutationFnSet_(false),
        isValueSet_(false)
        {}

    Parameter(T value, T (*mutationFn)(T)) :
        isMutationFnSet_(true),
        isValueSet_(true),
        mutationFn_(mutationFn),
        value_(value)
        {}

    void setValue(T newValue) {
        isValueSet_ = true;
        value_ = newValue;
    }

    T getValue() {
        return value_;
    }

    void setMutationFn(T (*mutationFn)(T)) {
        isMutationFnSet_ = true;
        mutationFn_ = mutationFn;
    }

    void mutation() {
        if (!isValueSet_ || !isMutationFnSet_) {
            throw std::runtime_error(
                "Parameter<T> should have a value and a function pointer.");
        }
        value_ = mutationFn_(value_);
    }

 private:
    bool isMutationFnSet_;
    bool isValueSet_;
    T (*mutationFn_)(T);
    T value_;
};

}  // namespace cgp

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_PARAMETER_H_
