//
//  eventListView.cpp
//  videoMarker1_0
//
//  Created by Cristian David on 2016-04-20.
//
//

#include "eventListView.hpp"

void eventListView::eventViewSetup(int width, posn p){
    // create a scroll view that displays eight items at a time //
    eventListViewGui = new ofxDatGuiScrollView("Event list viewer", 15);
    eventListViewGui->setWidth(width);
    eventListViewGui->setPosition(p.x, p.y);
    eventListViewGui->onScrollViewEvent(this, &eventListView::onScrollViewEvent);
}

void eventListView::addItem(string text, string color, int frame){
    eventInfo newEvent(text, color, frame);
    eventList.push_back(newEvent);
    eventListViewGui->add(text);
}

void eventListView::clear(){
    eventList.clear();
    eventListViewGui->clear();
}

void eventListView::onScrollViewEvent(ofxDatGuiScrollViewEvent e){
    int itemIndex = e.index;
    if(deleteModeState){
        eventListViewGui->remove(itemIndex);
        eventList.erase(eventList.begin()+itemIndex);
    }else{
        setVideoFrame = eventList[itemIndex].frameNumber;
    }
}