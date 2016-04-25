//
//  eventListView.hpp
//  videoMarker1_0
//
//  Created by Cristian David on 2016-04-20.
//
//

#ifndef eventListView_hpp
#define eventListView_hpp

#include "ofxDatGui.h"
#include "ofMain.h"
#include "posn.hpp"
#include <stdio.h>
#include <vector>

class eventInfo {
public:
    eventInfo(string eventType, string color, int frameNumber):eventType(eventType),color(color),frameNumber(frameNumber){}
    
    string eventType;
    string color;
    int frameNumber;
};

class eventListView {
    
public:
    eventListView(int width=0, posn topLeft=posn(0,0)):width(width), topLeft(topLeft){}
    
    ofxDatGuiScrollView* eventListViewGui;
    
    int width;
    posn topLeft;
    bool deleteModeState = false;
    int setVideoFrame = -1;
    std::vector<eventInfo> eventList;
    
    void eventViewSetup(int width, posn p);
    void onScrollViewEvent(ofxDatGuiScrollViewEvent e);
    void addItem(string text, string color, int frame);
    int getY(){return eventListViewGui->getY();};
    int getHeight(){return eventListViewGui->getHeight();};
    int getNumItems(){return eventListViewGui->getNumItems();};
    void listUpdate(){eventListViewGui->update();};
    void listDraw(){eventListViewGui->draw();};
    void clear();
    
    
};

#endif /* eventListView_hpp */
