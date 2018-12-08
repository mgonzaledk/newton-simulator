#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class BadArgumentException : public std::exception {
    virtual const char *what() const throw() {
        return "Argumento inesperado";
    }
} BadArgumentException;

#endif
