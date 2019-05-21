//
// Created by susmit on 21/5/19.
//

#ifndef LEVELS_H
#define LEVELS_H


#include "block.hpp"

class Level {
    Block ***blocks;
    int rows, cols;
public:
    Level(int , int);
    Block*** getBlockMatrix();

    int getRowCount();
    int getColumnCount();
};


#endif
