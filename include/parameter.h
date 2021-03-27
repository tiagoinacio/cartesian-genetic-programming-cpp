// Copyright 2017
// Tiago Inácio

#ifndef INCLUDE_PARAMETER_H_
#define INCLUDE_PARAMETER_H_

#include <memory>
#include <stdexcept>

namespace cgp {

class ParameterInterface {
 public:
    virtual ~ParameterInterface() {
    }
    virtual void mutation() = 0;
};

template <typename T>
class Parameter : public ParameterInterface {
 public:
    Parameter() : isMutationFnSet_(false), isValueSet_(false) {
    }

    explicit Parameter(T value, T (*mutationFn)(T))
        : isMutationFnSet_(true),
          isValueSet_(true),
          mutationFn_(mutationFn),
          value_(value) {
    }

    explicit Parameter(T value)
        : isMutationFnSet_(false), isValueSet_(true), value_(value) {
    }

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

template <typename T, typename... Args>
std::shared_ptr<cgp::Parameter<T> > createParameter(Args... as) {
    std::shared_ptr<cgp::Parameter<T> > pointer(new cgp::Parameter<T>(as...));

    return pointer;
}

}   // namespace cgp

#endif   // INCLUDE_PARAMETER_H_
