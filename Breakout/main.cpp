//
//  main.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#include "paddle.hpp"
#include "block.hpp"
#include "ball.hpp"

Paddle *paddle;
Block *block_matrix[5][10];
Ball *ball;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    paddle->draw();
    ball->draw();
    for(int i=0;i<5;i++)
        for(int j=0;j<10;j++)
            block_matrix[i][j]->draw();
    
    glutSwapBuffers();
    glutPostRedisplay();
}

void init() {
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

void keyPressed(unsigned char key, int x, int y){
    int px = paddle->getX();
    int len = paddle->getLength();
    if(key=='a' && px > 10){
        paddle->moveTo(px - 10, paddle->getY());
    }
    else if(key=='d' && px+len < 590){
        paddle->moveTo(px + 10, paddle->getY());
    }
}

int main(int argc, char **argv) {
    srand(0);
    paddle = new Paddle();
    ball = new Ball();

    for(int i=0;i<5;i++)
        for(int j=0;j<10;j++)
            block_matrix[i][j] = new Block(60*j, 550-(20*i));

    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Breakout");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    init();
    glutMainLoop();
    return 0;
}
