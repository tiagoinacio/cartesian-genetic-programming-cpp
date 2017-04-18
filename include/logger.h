// Copyright 2017
// Tiago Inácio

#ifndef CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_LOGGER_H_
#define CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_LOGGER_H_

#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

namespace cgp {
class Logger {
    std::ostream* m_out;
    bool m_owner;

 public:
    Logger() : m_out(nullptr), m_owner(false), to_debug_(false) {
    }
    Logger(std::ostream* stream, bool owner, bool toDebug = false)
        : to_debug_(toDebug), m_owner(false), m_out(nullptr) {
        setStream(stream, owner);
    }
    virtual ~Logger() {
        setStream(0, false);
    }
    template <typename T>
    Logger& operator<<(const T& object) {
        if (to_debug_) {
            if (!m_out) {
                throw std::runtime_error("No stream set for Logger class");
            }
            (*m_out) << object;
        }
        return *this;
    }

 private:
    void setStream(std::ostream* stream, bool owner) {
        if (m_owner)
            delete m_out;
        m_out = stream;
        m_owner = owner;
    }
    bool to_debug_;
};

};       // namespace cgp
#endif   // CARTESIAN_GENETIC_PROGRAMMING_CPP_INCLUDE_LOGGER_H_
