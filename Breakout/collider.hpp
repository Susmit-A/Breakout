//
//  collider.hpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#ifndef collider_hpp
#define collider_hpp

#include "game_object.hpp"
#include <iostream>
#include <vector>

class Collider {
private:
    class Entry{
    public:
        unsigned char buffer_A = 0;
        unsigned char buffer_B = 0;
        
        const unsigned char TOP_EDGE_A = 1;
        const unsigned char BOTTOM_EDGE_A = 2;
        const unsigned char LEFT_EDGE_A = 4;
        const unsigned char RIGHT_EDGE_A = 8;
        
        const unsigned char TOP_EDGE_B = 16;
        const unsigned char BOTTOM_EDGE_B = 32;
        const unsigned char LEFT_EDGE_B = 64;
        const unsigned char RIGHT_EDGE_B = 128;
        
        GameObject *a, *b;
        std::string name;

        unsigned char getBuffer_A();
        unsigned char getBuffer_B();
        
        Entry(GameObject* obj1, GameObject* obj2, std::string n="", void (*onCollision)(GameObject* a, GameObject* b, std::string name) = nullptr);
    };
    std::vector<Entry> entries;
    
public:
    Collider();
    void add(GameObject* obj1, GameObject* obj2, std::string name="", void (*onCollision)(GameObject* a, GameObject* b, std::string name) = nullptr);
    
    void processCollisions();
};
#endif /* collider_hpp */
