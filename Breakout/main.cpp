//
//  main.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <GL/glut.h>

#elif __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#elif __linux__

#include <glut.h>

#endif

#include "paddle.hpp"
#include "block.hpp"
#include "ball.hpp"
#include "collider.hpp"
#include "game_object.hpp"
#include "levels.h"
#include "prototypes.h"

#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

Paddle *paddle;
Block ***block_matrix;
Ball *ball;
Collider *mainCollider;
Level *level;

char *fname = NULL;

bool gameOver = false;

void text()
{
    char txt[10];
    
    glBegin(GL_POLYGON);
    glColor3f(0.4,0,0.8);
    glVertex2f(0, 200.0f);
    glColor3f(0.4,0,0.8);
    glVertex2f(599, 200.0f);
    glColor3f(0.6,0,0.6);
    glVertex2f(599, 400);
    glColor3f(0.6,0,0.6);
    glVertex2f(0, 400);
    glEnd();
    
    strcpy(txt,"Game Over");
    int len;
    len = strlen(txt);
    
    glColor3f(1,1,1);
    
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    
    gluOrtho2D( 0, 600, 0, 600 );
    
    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    
    glLoadIdentity();
    
    glRasterPos2i(190, 300);
    
    
    for ( int i = 0; i < len; ++i )
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[i]);
    }
    
    glPopMatrix();
    
    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}

void display(){
    if(gameOver){
        text();
        return;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    
    paddle->draw();
    ball->draw();
    
    for(int i=0;i<level->getRowCount();i++)
        for(int j=0;j<level->getColumnCount();j++)
            block_matrix[i][j]->draw();
    
    glutSwapBuffers();
}

void onTimerTick(int flag){
    mainCollider->processCollisions();

    glutPostRedisplay();
    glutTimerFunc(1000/120, onTimerTick, 0);
}

void init() {
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

void reset(){
    gameOver = false;
    *ball = Ball();
    *paddle = Paddle();
    if(fname)
        loadLayoutFromFile(fname);
    else
        loadDefaultLayout();
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
    else if(key=='r'){
        reset();
    }
}

void specialKeyPressed(int key, int x, int y){
    int px = paddle->getX();
    int len = paddle->getLength();
    if(key==GLUT_KEY_LEFT && px > 10){
        paddle->translateBy(-10, 0);
    }
    else if(key==GLUT_KEY_RIGHT && px+len < 590){
        paddle->translateBy(10, 0);
    }
}

void ballWallCollider(GameObject *obj1, GameObject *obj2, std::string name, unsigned char code){
    if(code==Collider::TOP_EDGE_A){
        ball->setAngle(ball->getAngle()+90);
    }
    else if(code==Collider::BOTTOM_EDGE_A){
        gameOver = true;
        text();
        glutPostRedisplay();
        glutSwapBuffers();
    }
    if(code==Collider::RIGHT_EDGE_A) {
        ball->setDx(-1);
    }
    else if(code==Collider::LEFT_EDGE_A){
        ball->setDx(1);
    }
}

void ballBlockCollider(GameObject *obj1, GameObject *obj2, std::string name, unsigned char code){

    if(code==0)
        return;

    if(!((Block*)obj2)->exists())
        return;
    
    // Collision along Y-axis
    if(std::min(abs(obj1->getX1() - obj2->getX2()), abs(obj1->getX2() - obj2->getX1()))
       >
       std::min(abs(obj1->getY1() - obj2->getY2()), abs(obj1->getY2() - obj2->getY1()))) {
        
        
        // If collision along Y-axis, ball from bottom
        if((code&(Collider::TOP_EDGE_A | Collider::BOTTOM_EDGE_B))
           ==
           (Collider::TOP_EDGE_A | Collider::BOTTOM_EDGE_B)) {
        
            // Any overlap along X-axis
            if((code & (~(Collider::TOP_EDGE_A | Collider::BOTTOM_EDGE_B))) !=0) {
                ball->setAngle(-90);
                ((Block*)obj2)->destroy();
            }
        }
    
        // If collision along Y-axis, ball from top
        else if((code&(Collider::BOTTOM_EDGE_A | Collider::TOP_EDGE_B))
                ==
                (Collider::BOTTOM_EDGE_A | Collider::TOP_EDGE_B)) {
        
            // Any overlap along X-axis
            if((code & (~(Collider::BOTTOM_EDGE_A | Collider::TOP_EDGE_B))) !=0) {
                ball->setAngle(90);
                ((Block*)obj2)->destroy();
            }
        }
    }
    
    // Collision along X-axis
    else {
        // If collision along X-axis, ball from left
        if((code&(Collider::LEFT_EDGE_A | Collider::RIGHT_EDGE_B))
                ==
                (Collider::LEFT_EDGE_A | Collider::RIGHT_EDGE_B)) {
        
            // Any overlap along Y-axis
            if((code & (~(Collider::LEFT_EDGE_A | Collider::RIGHT_EDGE_B))) !=0) {
                ball->setDx(1);
                ((Block*)obj2)->destroy();
            }
        }
    
        // If collision along X-axis, ball from right
        else if((code&(Collider::RIGHT_EDGE_A | Collider::LEFT_EDGE_B))
                ==
                (Collider::RIGHT_EDGE_A | Collider::LEFT_EDGE_B)) {
        
            // Any overlap along Y-axis
            if((code & (~(Collider::RIGHT_EDGE_A | Collider::LEFT_EDGE_B))) !=0) {
                ball->setDx(-1);
                ((Block*)obj2)->destroy();
            }
        }
    }
}

void ballPaddleCollider(GameObject *obj1, GameObject *obj2, std::string name, unsigned char code){
    
    // If collision along Y-axis
    if((code&(Collider::BOTTOM_EDGE_A | Collider::TOP_EDGE_B))
       ==
       (Collider::BOTTOM_EDGE_A | Collider::TOP_EDGE_B)) {
        
        // Any overlap along X-axis
        if((code & (~(Collider::BOTTOM_EDGE_A | Collider::TOP_EDGE_B))) !=0) {
            ball->setAngle(90.0f - abs(obj2->getMidX() - obj1->getMidX())/(obj2->getMidX() - obj2->getX1()));
            if(obj1->getMidX() < obj2->getMidX()){
                ball->setDx(-1);
            }
            else{
                ball->setDx(1);
            }
        }
    }
}

void loadDefaultLayout() {
    level = new Level(4, 10);
    block_matrix = level->getBlockMatrix();

    for(int i = 0; i < level->getRowCount() ; i++) {
        for (int j = 0; j < level->getColumnCount(); j++) {
            mainCollider->add(ball, block_matrix[i][j], "ball_block", ballBlockCollider);
        }
    }
}

void loadLayoutFromFile(const char* path) {
    string colorMode;
    fname = (char *)path;
    int rows;
    int cols;
    ifstream fin(path, ios::in);
    if(!fin) {
        cout<<"Error opening file";
        exit(0);
    }
    fin >> rows;
    fin >> cols;
    fin >> Block::len;
    fin >> Block::wid;
    fin >> colorMode;

    level = new Level(rows, cols);
    block_matrix = level->getBlockMatrix();

    for(int i = 0; i < level->getRowCount() ; i++) {
        for (int j = 0; j < level->getColumnCount(); j++) {
            if(strcmp(colorMode.c_str(), "fixed")==0) {
                int color;
                fin >> hex >> color;
                // Black - block doesn't exist
                if(color==0)
                    block_matrix[i][j]->destroy();

                block_matrix[i][j]->setColor(new Color(color>>16 & 0xFF, color>>8 & 0xFF, color & 0xFF));
            }

            mainCollider->add(ball, block_matrix[i][j], "ball_block", ballBlockCollider);
        }
    }
    fin.close();
}

int main(int argc, char **argv) {
    srand(0);

    paddle = new Paddle();
    ball = new Ball();
    mainCollider = new Collider();
    
    mainCollider->add(ball, nullptr, "ball_wall", ballWallCollider);
    mainCollider->add(ball, paddle, "ball_paddle", ballPaddleCollider);

    // loadDefaultLayout();
    loadLayoutFromFile("/home/susmit/gitprojects/Breakout/Breakout/levels/basic.conf");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Breakout");
    glutTimerFunc(1000/120, onTimerTick, 0);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKeyPressed);
    init();
    glutMainLoop();
    return 0;
}
