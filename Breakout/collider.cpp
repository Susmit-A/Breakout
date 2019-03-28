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
        
        if(it->b==nullptr || it->b==NULL){
            if(it->a->getX2() >= 599)
                res |= Collider::RIGHT_EDGE_A;
            else if(it->a->getX1() <= 1)
                res |= Collider::LEFT_EDGE_A;
            if(it->a->getY1() >= 599)
                res |= Collider::TOP_EDGE_A;
            else if(it->a->getY2() <= 1)
                res |= Collider::BOTTOM_EDGE_A;
            it->onCollision(it->a, it->b, it->name, res);
            return;
        }
        
    }
}
