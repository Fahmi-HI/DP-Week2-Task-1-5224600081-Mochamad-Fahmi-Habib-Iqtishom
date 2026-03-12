#ifndef INPUT_GENERATOR_H
#define INPUT_GENERATOR_H
#include <cstdlib>

class IInputGenerator {
public:
    virtual int GenerateInput() = 0;
};

class FixedInputGenerator : public IInputGenerator {
public:
    int GenerateInput() override {
        return 3;
    }
};

#endif