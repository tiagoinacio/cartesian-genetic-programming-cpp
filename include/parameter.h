// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_PARAMETER_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_PARAMETER_H_

namespace cgp {

template <class T>
class Parameter {
 public:
    Parameter() {}

    Parameter(T value, T (*mutationFn)(T)) :
        value_(value),
        mutationFn_(mutationFn)
        {}

    void setValue(T newValue) {
        value_ = newValue;
    }

    T getValue() {
        return value_;
    }

    void setMutationFn(T (*mutationFn)(T)) {
        mutationFn_ = mutationFn;
    }

    void mutation() {
        value_ = mutationFn_(value_);
    }

 private:
    T value_;
    T (*mutationFn_)(T);
};

}  // namespace cgp

#endif  // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_PARAMETER_H_
