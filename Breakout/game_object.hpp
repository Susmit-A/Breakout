//
//  game_object.hpp
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#ifndef game_object_h
#define game_object_h

class GameObject {
public:
    virtual int getX1() = 0;
    virtual int getX2() = 0;
    virtual int getY1() = 0;
    virtual int getY2() = 0;
    virtual void getBoundingBox(int *x1, int *x2, int *y1, int *y2) = 0;
    virtual void draw() = 0;
};
#endif /* game_object_h */
