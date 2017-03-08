// copyright Tiago Inácio

#include <limits.h>
#include <stdexcept>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "parameter.h"

int intMutationFnPlus(int x) { return x + 2; }

int intMutationFnMinus(int x) { return x - 2; }

std::string stringMutationFnNew(std::string x) { return "new text"; }

std::string stringMutationFnOld(std::string x) { return "old text"; }

class TemplateParameterClass : public ::testing::Test {};

TEST_F(TemplateParameterClass, constructor_with_args) {
    cgp::Parameter<int> intParam(5, intMutationFnPlus);

    EXPECT_EQ(5, intParam.getValue());
}

TEST_F(TemplateParameterClass, default_constructor) {
    cgp::Parameter<int> intParam;

    intParam.setValue(2);

    EXPECT_EQ(2, intParam.getValue());
}

TEST_F(TemplateParameterClass, setValue_getValue) {
    cgp::Parameter<int> intParam;
    cgp::Parameter<std::string> stringParam;

    intParam.setValue(2);
    EXPECT_EQ(2, intParam.getValue());

    intParam.setValue(4);
    EXPECT_EQ(4, intParam.getValue());

    stringParam.setValue("first value");
    EXPECT_EQ("first value", stringParam.getValue());

    stringParam.setValue("second value");
    EXPECT_EQ("second value", stringParam.getValue());
}

TEST_F(TemplateParameterClass, setMutationFn) {
    cgp::Parameter<int> intParam(2, intMutationFnPlus);
    cgp::Parameter<std::string> stringParam("some value", stringMutationFnNew);

    EXPECT_EQ(2, intParam.getValue());
    EXPECT_EQ("some value", stringParam.getValue());

    intParam.mutation();
    stringParam.mutation();

    EXPECT_EQ(4, intParam.getValue());
    EXPECT_EQ("new text", stringParam.getValue());

    intParam.setMutationFn(intMutationFnMinus);
    stringParam.setMutationFn(stringMutationFnOld);

    intParam.mutation();
    stringParam.mutation();

    EXPECT_EQ(2, intParam.getValue());
    EXPECT_EQ("old text", stringParam.getValue());
}

TEST_F(TemplateParameterClass, mutation_valid) {
    cgp::Parameter<int> intParam;
    cgp::Parameter<std::string> stringParam;

    intParam.setValue(2);
    intParam.setMutationFn(intMutationFnPlus);

    EXPECT_EQ(2, intParam.getValue());
    intParam.mutation();
    EXPECT_EQ(4, intParam.getValue());

    stringParam.setValue("first value");
    stringParam.setMutationFn(stringMutationFnNew);

    EXPECT_EQ("first value", stringParam.getValue());
    stringParam.mutation();
    EXPECT_EQ("new text", stringParam.getValue());
}

TEST_F(TemplateParameterClass, mutation_out_of_range) {
    cgp::Parameter<int> intParam;

    try {
        intParam.mutation();
        FAIL() << "Expected std::runtime_error";
    } catch (std::runtime_error const &err) {
        EXPECT_EQ(
            err.what(),
            std::string(
                "Parameter<T> should have a value and a function pointer."));
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }

    cgp::Parameter<std::string> stringParam;

    stringParam.setMutationFn(stringMutationFnOld);

    try {
        stringParam.mutation();
        FAIL() << "Expected std::runtime_error";
    } catch (std::runtime_error const &err) {
        EXPECT_EQ(
            err.what(),
            std::string(
                "Parameter<T> should have a value and a function pointer."));
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}
