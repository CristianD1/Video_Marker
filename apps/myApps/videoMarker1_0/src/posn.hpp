//
//  posn.hpp
//  videoMarker1_0
//
//  Created by Cristian David on 2016-04-20.
//
//

#ifndef posn_hpp
#define posn_hpp

#include <stdio.h>

class posn{
public:
    posn(int x, int y):x(x),y(y){}
    void operator=(const posn &p){
        x = p.x;
        y = p.y;
    }
    
    int x;
    int y;
    
    bool isWithinRectangle(posn posTopLeft, posn posBottomRight){
        if(x >= posTopLeft.x && x <= posBottomRight.x &&
           y >= posTopLeft.y && y <= posBottomRight.y){
            return true;
        }
        return false;
    }
};

#endif /* posn_hpp */
