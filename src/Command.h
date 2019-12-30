//
// Created by Dawid Osuchowski on 30/12/2019.
//

#ifndef ARKEKNOID_CPP_COMMAND_H
#define ARKEKNOID_CPP_COMMAND_H


class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};


#endif //ARKEKNOID_CPP_COMMAND_H
