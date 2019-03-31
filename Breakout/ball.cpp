//
//  ball.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include "ball.hpp"
#include<iostream>

Ball::Ball(){
    slope = 1;
    dx = 1;
    dy = 1;
    x = 250;
    y = 30;
    vx = 2;
    vy = 2;
}

int Ball::getX1(){
    return getX();
}

int Ball::getY1(){
    return getY();
}

int Ball::getX2(){
    return getX() + 5;
}

int Ball::getY2(){
    return getY() + 5;
}

void Ball::getBoundingBox(int *X1,  int *X2, int *Y1, int *Y2){
    *X1 = getX1();
    *X2 = getX2();
    *Y1 = getY1();
    *Y2 = getY2();
}


void Ball::draw(){
    x += vx*dx;
    y += vy*dy;
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+5, y);
    glVertex2f(x+5, y+5);
    glVertex2f(x, y+5);
    glEnd();
}

int Ball::getX(){
    return x;
}

int Ball::getY(){
    return y;
}

int Ball::getSlope(){
    return slope;
}

void Ball::setX(int X){
    x = X;
}

void Ball::setY(int Y){
    y = Y;
}

void Ball::setSlope(float s){
    slope = s;
}

void Ball::setVx(float Vx){
    vx = Vx;
}

void Ball::setVy(float Vy){
    vy = Vy;
}

void Ball::setDx(int Dx){
    dx = Dx;
}

void Ball::setDy(int Dy){
    dy = Dy;
}

int Ball::getDx(){
    return dx;
}

int Ball::getDy() {
    return dy;
}

float Ball::getVx(){
    return vx;
}

float Ball::getVy(){
    return vy;
}
