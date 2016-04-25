//
//  videoLogic.cpp
//  videoMarker1_0
//
//  Created by Cristian David on 2016-04-20.
//
//

#include "videoLogic.hpp"

void videoLogic::videoSetup(){
    ofBackground(255,255,255);
    ofSetVerticalSync(true);
    
    fingerMovie.load("movies/penguins.mov");
    fingerMovie.setLoopState(OF_LOOP_NORMAL);
    fingerMovie.play();
}

void videoLogic::videoUpdate(){
    fingerMovie.update();
}

void videoLogic::videoDraw(){
    int videoPosX = screenWidth/5;
    int videoPosY = 0;
    
    // Draw video
    ofSetHexColor(0xFFFFFF);
    
    fingerMovie.draw(videoPosX,videoPosY);
    ofSetHexColor(0x000000);
    ofPixels & pixels = fingerMovie.getPixels();
    
    int vidWidth = pixels.getWidth();
    int vidHeight = pixels.getHeight();
    int nChannels = pixels.getNumChannels();
    
    if(fingerMovie.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",videoPosX,440);
    }
    
    // Determine the position after the pixels have been assigned
    vidTopLeft = posn(videoPosX, videoPosY);
    vidBottomRight = posn(fingerMovie.getWidth()+videoPosX, fingerMovie.getHeight()+videoPosY);
}

void videoLogic::videoKeyPress(int key){
    switch(key){
//        case 'p':
//            togglePause();
//            break;
        case OF_KEY_LEFT:
            fingerMovie.previousFrame();
            break;
        case OF_KEY_RIGHT:
            fingerMovie.nextFrame();
            break;
        case '0':
            fingerMovie.firstFrame();
            break;
    }
}

void videoLogic::videoCheckClick(int x, int y, int button){
    posn clickPos(x, y);
    if(clickPos.isWithinRectangle(vidTopLeft, vidBottomRight)){
        togglePause();
    }
}

void videoLogic::setFrame(int frame){
    if(frame != -1){
        std::cout << "set frame: "<<frame<<" and " <<fingerMovie.getTotalNumFrames()<< " and "<<fingerMovie.getCurrentFrame() << endl;
        fingerMovie.setFrame(frame);
    }
}

/* Private functions */
void videoLogic::togglePause(bool forcedState){
    if(forcedState != NULL){
        pausedState = forcedState;
    }else{
        pausedState = !pausedState;
    }
    fingerMovie.setPaused(pausedState);
}