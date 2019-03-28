//
//  collider.cpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#include "collider.hpp"

Collider::Entry::Entry(GameObject* obj1,
                       GameObject* obj2,
                       std::string n,
                       void (*onCollide)(GameObject* a, GameObject* b, std::string name))
{
    a = obj1;
    b = obj2;
    name = n;
}

unsigned char Collider::Entry::getBuffer_A(){
    return buffer_A;
}

unsigned char Collider::Entry::getBuffer_B(){
    return buffer_B;
}

Collider::Collider(){
    entries.reserve(50);
}
void Collider::add(GameObject* obj1, GameObject* obj2, std::string name, void (*onCollision)(GameObject* a, GameObject* b, std::string name))
{
    if(obj1==nullptr || obj2==NULL)
        throw "First object can't be null";
    
    entries.push_back(*(new Entry(obj1, obj2, name, onCollision)));
}

void Collider::processCollisions(){
    
}
