//
// Created by danya on 13.05.2022.
//

#ifndef CALCULATOR_CALC_TREE_H
#define CALCULATOR_CALC_TREE_H

#include "refs/refs.h"

class CalcTree {

public:
    string equation;
    sPtr eqPtr;
    CalcTree(sPtr);
    int GetPriority(string);
    vector<string> InfixToPostfix(sLink);

};

#endif //CALCULATOR_CALC_TREE_H
