//
//  videoLogic.hpp
//  videoMarker1_0
//
//  Created by Cristian David on 2016-04-20.
//
//

#ifndef videoLogic_hpp
#define videoLogic_hpp

#include "ofMain.h"
#include "posn.hpp"

class videoLogic {
    
public:
    videoLogic():windowHeight(ofGetHeight()), windowWidth(ofGetWidth()),
                screenHeight(ofGetScreenHeight()), screenWidth(ofGetScreenWidth()),
                vidTopLeft(0,0), vidBottomRight(0,0){}
    
    void videoSetup();
    void videoUpdate();
    void videoDraw();
    void videoCheckClick(int x, int y, int button);
    void videoKeyPress(int key);
    void setFrame(int frame);
    int getFrame(){return fingerMovie.getCurrentFrame();};
    int getTotalNumFrames(){return fingerMovie.getTotalNumFrames();};
    int getPlayerWidth(){return fingerMovie.getWidth();};
    int getPlayerHeight(){return fingerMovie.getHeight();};
    int getPlayerXPos(){return vidTopLeft.x;};
    
private:
    ofVideoPlayer fingerMovie;
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void togglePause(bool forcedState = NULL);
    bool pausedState = false;
    
    int windowHeight;
    int windowWidth;
    int screenHeight;
    int screenWidth;
    posn vidTopLeft;
    posn vidBottomRight;
    
};

#endif /* videoLogic_hpp */
