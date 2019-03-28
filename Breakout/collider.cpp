//
//  collider.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include "collider.hpp"

#include <vector>
#include <iostream>

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

Collider::Entry::Entry(GameObject* obj1,
                       GameObject* obj2,
                       std::string n,
                       void (*onCollide)(GameObject* a, GameObject* b, std::string name, unsigned char code))
{
    a = obj1;
    b = obj2;
    name = n;
    onCollision = onCollide;
}

unsigned char Collider::Entry::getBuffer_A(){
    return buffer_A;
}

unsigned char Collider::Entry::getBuffer_B(){
    return buffer_B;
}

Collider::Collider(){
    entries.reserve(60);
}
void Collider::add(GameObject* obj1, GameObject* obj2, std::string name, void (*onCollision)(GameObject* a, GameObject* b, std::string name, unsigned char code))
{
    if(obj1==nullptr || obj1==NULL)
        throw "First object can't be null";
    
    entries.push_back(*(new Entry(obj1, obj2, name, onCollision)));
}

void Collider::processCollisions(){
    for(std::vector<Entry>::iterator it = entries.begin(); it!=entries.end(); it++){
        unsigned char res = 0;
        
        // Wall collisions
        if(it->b==nullptr || it->b==NULL){
            if(it->a->getX2() >= 599) {
                res = Collider::RIGHT_EDGE_A;
                it->onCollision(it->a, it->b, it->name, res);
                return;
            }
            else if(it->a->getX1() <= 1){
                res = Collider::LEFT_EDGE_A;
                it->onCollision(it->a, it->b, it->name, res);
                return;
            }
            if(it->a->getY1() >= 599){
                res = Collider::TOP_EDGE_A;
                it->onCollision(it->a, it->b, it->name, res);
                return;
            }
            else if(it->a->getY2() <= 1){
                res = Collider::BOTTOM_EDGE_A;
                it->onCollision(it->a, it->b, it->name, res);
                return;
            }
        }
        
        /*
            The logic below is specifically for ball collision detection.
            In general, it is valid if obj1 is smaller than obj2.
            It is yet to be generalized.
         */
        else{
            // Ball bottom edge, obsticle top edge (eg. Paddle)
            if(it->a->getX1() >= it->b->getX1()
               && it->a->getX2() <= it->b->getX2()
               && it->a->getY1() <= it->b->getY2()) {
                res = Collider::BOTTOM_EDGE_A|Collider::TOP_EDGE_B;
                it->onCollision(it->a, it->b, it->name, res);
                return;
            }
            //Ball top edge, obsticle bottom edge
            else if(    it->a->getX1() >= it->b->getX1()
                    &&  it->a->getX2() <= it->b->getX2()
                    &&  it->a->getY2() >= it->b->getY1()){
                res = Collider::BOTTOM_EDGE_B|Collider::TOP_EDGE_A;
                it->onCollision(it->a, it->b, it->name, res);
                return;
            }
            
        }

        it->onCollision(it->a, it->b, it->name, res);
    }
}
