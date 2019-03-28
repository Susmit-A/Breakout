//
//  ball.hpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#ifndef ball_hpp
#define ball_hpp

#include "colors.h"
#include "game_object.hpp"

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

class Ball : public GameObject{
private:
    int x, y;
    int dx, dy;
    int anim_time;
    float slope, vx, vy;

public:
    Ball();
    
    int getX();
    int getY();
    int getSlope();
    float getVx();
    float getVy();
    int getDx();
    int getDy();
    
    void setX(int X);
    void setY(int Y);
    void setSlope(float s);
    void setVx(float Vx);
    void setVy(float Vy);
    void setDx(int Dx);
    void setDy(int Dy);
        
    virtual int getX1();
    virtual int getX2();
    virtual int getY1();
    virtual int getY2();
    virtual void getBoundingBox(int *x1, int *x2, int *y1, int *y2);
    virtual void draw();
};
#endif /* ball_hpp */
