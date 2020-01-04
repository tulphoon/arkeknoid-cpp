//
// Created by Dawid Osuchowski on 30/12/2019.
//

#include "GameObject.h"

#ifndef ARKEKNOID_CPP_COMMAND_H
#define ARKEKNOID_CPP_COMMAND_H


class Command {
public:
    virtual ~Command() {}
    virtual void execute(GameObject& object) = 0;
};




#endif //ARKEKNOID_CPP_COMMAND_H
