//
//  paddle.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include "paddle.hpp"

Paddle::Paddle(){
    x = 200;
    y = 20;
    len = 100;
    wid = 10;
    color = new Color(255, 0, 0);
}

int Paddle::getX1(){
    return getX();
}

int Paddle::getY1(){
    return getY();
}

int Paddle::getX2(){
    return getX() + getLength();
}

int Paddle::getY2(){
    return getY() + getWidth();
}
int Paddle::getX(){
    return x;
}

int Paddle::getY(){
    return y;
}

int Paddle::getMidX() {
    return (getX1() + getX2())/2;
}

int Paddle::getMidY() {
    return (getY1() + getY2())/2;
}

void Paddle::setX(int X){
    x = X;
}

void Paddle::setY(int Y){
    y = Y;
}

void Paddle::getBoundingBox(int *X1,  int *X2, int *Y1, int *Y2){
    *X1 = getX1();
    *X2 = getX2();
    *Y1 = getY1();
    *Y2 = getY2();
}

int Paddle::getLength(){
    return len;
}

int Paddle::getWidth(){
    return wid;
}

void Paddle::setLength(int l){
    len = l;
}

void Paddle::moveTo(int X, int Y){
    x = X;
    y = Y;
}

void Paddle::draw(){
    glColor3f(color->getRed(), color->getGreen(), color->getBlue());
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+len, y);
    glVertex2f(x+len, y+wid);
    glVertex2f(x, y+wid);
    glEnd();
}
