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
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#include "game_object.hpp"

class Paddle : public GameObject{
private:
    int x, y;
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
    
    virtual int getX1();
    virtual int getX2();
    virtual int getY1();
    virtual int getY2();
    virtual void getBoundingBox(int *x1, int *x2, int *y1, int *y2);
    virtual void draw();
};





#endif /* paddle_hpp */
