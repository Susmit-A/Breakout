//
//  block.hpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//
#pragma once
#ifndef block_hpp
#define block_hpp

#include "colors.h"
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#include "game_object.hpp"

class Block : public GameObject{
private:
    int x, y;
    int len, wid;
    Color *color;
    bool exist;
public:
    Block(int X, int Y);
    int getX();
    int getY();
    int getLength();
    bool exists();
    void destroy();
    
    virtual int getX1();
    virtual int getX2();
    virtual int getY1();
    virtual int getY2();
    virtual void getBoundingBox(int *x1, int *x2, int *y1, int *y2);
    virtual void draw();
};

#endif /* block_hpp */