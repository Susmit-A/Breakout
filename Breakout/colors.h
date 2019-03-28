//
//  colors.h
//  Breakout
//
//  Created by Susmit Agrawal on 28/03/19.
//  Copyright © 2019 Susmit Agrawal. All rights reserved.
//

#pragma once
#ifndef colors_h
#define colors_h

class Color {
private:
    int r;
    int g;
    int b;
    
public:
    Color(int red, int green, int blue){
        r = red;
        g = green;
        b = blue;
    }
    
    int getRed(){
        return r;
    }
    
    int getGreen(){
        return g;
    }
    
    int getBlue(){
        return b;
    }
    
    Color* getColor(){
        return this;
    }
};
#endif /* colors_h */
