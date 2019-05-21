//
//  ball.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include "ball.hpp"
#include <iostream>
#include <math.h>

Ball::Ball(){
    slope = 1;
    dx = 1;
    dy = 1;
    x = 250;
    y = 30;
    vx = 2;
    vy = 2;
    r = 3;
    tx = 0;
    ty = 0;
    angle = 45;
}

int Ball::getX1(){
    return getX();
}

int Ball::getY1(){
    return getY();
}

int Ball::getX2(){
    return getX() + r;
}

int Ball::getY2(){
    return getY() + r;
}

int Ball::getMidX() {
    return (getX1() + getX2())/2;
}

int Ball::getMidY() {
    return (getY1() + getY2())/2;
}

void Ball::getBoundingBox(int *X1,  int *X2, int *Y1, int *Y2){
    *X1 = getX1();
    *X2 = getX2();
    *Y1 = getY1();
    *Y2 = getY2();
}


void Ball::draw() {

    glColor3f(1, 1, 1);

    dy = sin((angle*3.14159265359f)/180.0f);
    tx = vx*dx;
    ty = vy*dy;
    glPushMatrix();
    glTranslatef(tx, ty, 0);

    glBegin(GL_POLYGON);
    for(int ii = 0; ii < 360; ii++)
    {
        float theta = 2.0f * 3.14159265359f * (float)ii / 360.0f;//get the current angle

        float rx = r * cosf(theta);//calculate the x component
        float ry = r * sinf(theta);//calculate the y component

        glVertex2f(x + rx, y + ry);//output vertex

    }
    glEnd();

    glPopMatrix();
    x += tx;
    y += ty;
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

float Ball::getAngle() {
    return angle;
}

void Ball::setAngle(float a) {
    angle = a;
}
