//
//  paddle.hpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#ifndef paddle_hpp
#define paddle_hpp

#include "colors.h"

#ifdef _WIN32
#include <GL/glut.h>

#elif __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#elif __linux__

#include <glut.h>

#endif

#include "game_object.hpp"

class Paddle : public GameObject{
private:
    int x, y, tx, ty;
    int len, wid;
    Color *color;
    
public:
    Paddle();
    int getX();
    int getY();
    void setX(int X);
    void setY(int Y);
    int getLength();
    int getWidth();
    void setLength(int l);
    void moveTo(int X, int Y);
    void translateBy(int x, int y);

    virtual int getX1();
    virtual int getX2();
    virtual int getY1();
    virtual int getY2();
    virtual void getBoundingBox(int *x1, int *x2, int *y1, int *y2);
    virtual void draw();
    virtual int getMidX();
    virtual int getMidY();
};





#endif /* paddle_hpp */
