#include "rithmic_engine.h"

#include <iostream>

void init(af::rithmic::RithmicEngine* rithmicEngine) {
    std::cout << "GetCrashed = " << rithmicEngine->getCrashed() << std::endl;
}

