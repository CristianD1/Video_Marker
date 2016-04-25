#pragma once

#include "ofxDatGui.h"
#include "videoLogic.hpp"
#include "eventListView.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    /* event view settings ---------------------------------- */
    int width;
    ofxDatGuiTheme* theme;
    ofxDatGuiLabel* eventHeader;
    ofxDatGuiTextInput* eventNameInput;
    ofxDatGuiButton* addEventMark;
    ofxDatGuiLabel* breakLabel;
    ofxDatGuiButton* deleteMode;
    ofxDatGuiButton* clearAll;
    ofxDatGuiSlider* videoSlider;
    
    void onEventNamedInput(ofxDatGuiTextInputEvent e);
    void onAddNewItemButtonClick(ofxDatGuiButtonEvent e);
    void onDeleteModeButtonClick(ofxDatGuiButtonEvent e);
    void onClearAllButtonClick(ofxDatGuiButtonEvent e);
    void onSliderEvent(ofxDatGuiSliderEvent e);
    
    /* general events --------------------------------------- */
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    
    /* OBJECT GENERATORS ------------------------------------- */
    videoLogic myVideo;
    eventListView myEventListView;
    
    // Global Settings
    int windowHeight = ofGetHeight();
    int windowWidth = ofGetWidth();
    int screenHeight = ofGetScreenHeight();
    int screenWidth = ofGetScreenWidth();
    bool deleteModeState;
    string eventName;
    
};