//
//  block.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include "block.hpp"
#include <stdlib.h>

int Block::len = 60;
int Block::wid = 20;

Block::Block(int X, int Y){
    x = X;
    y = Y;
    color = new Color(rand()%255, rand()%255, rand()%255);
    exist = true;
}

int Block::getX1(){
    return getX();
}

int Block::getY1(){
    return getY();
}

int Block::getX2(){
    return getX() + 60;
}

int Block::getY2(){
    return getY() + 20;
}

void Block::getBoundingBox(int *X1,  int *X2, int *Y1, int *Y2){
    *X1 = getX1();
    *X2 = getX2();
    *Y1 = getY1();
    *Y2 = getY2();
}

int Block::getX(){
    return x;
}

int Block::getY(){
    return y;
}

int Block::getMidX() {
    return (getX1() + getX2())/2;
}

int Block::getMidY() {
    return (getY1() + getY2())/2;
}

bool Block::exists(){
    return exist;
}

void Block::destroy(){
    exist = false;
}

void Block::setColor(Color *col) {
    color = col;
}

Color *Block::getColor() {
    return color;
}

void Block::draw(){
    if(!exist)
        return;
    glColor3ub(color->getRed(), color->getGreen(), color->getBlue());
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+Block::len, y);
    glVertex2f(x+Block::len, y+Block::wid);
    glVertex2f(x, y+Block::wid);
    glEnd();
}
