#include "ofApp.h"

void ofApp::setup()
{
    ofSetWindowShape(windowWidth, windowHeight);
    ofSetWindowPosition(screenWidth/2 - windowWidth/2, 0);
    
    width = screenWidth/5;
    theme = new ofxDatGuiThemeMidnight();
    
    /* Create the event view bar */
        // Create a header to indicate what this portion is
        eventHeader = new ofxDatGuiLabel("List of bookmarked Events");
        eventHeader->setWidth(width);
        eventHeader->setPosition(0, 0);
        eventHeader->setLabelAlignment(ofxDatGuiAlignment::LEFT);
        eventHeader->setLabelColor(ofColor(255, 255, 0));
    
        myEventListView.eventViewSetup(width, posn(0, eventHeader->getY() + eventHeader->getHeight() + 1));
    
        // create an input field to set the name of the next event to be added //
        eventNameInput = new ofxDatGuiTextInput("Event name: ", "");
        eventNameInput->setWidth(width, width/3);
        eventNameInput->setPosition(0, myEventListView.getY() + myEventListView.getHeight() + 1);
        eventNameInput->onTextInputEvent(this, &ofApp::onEventNamedInput);
    
        // create a button to attach items to the scroll view //
        addEventMark = new ofxDatGuiButton("Click to add Event at current time");
        addEventMark->setStripeVisible(false);
        addEventMark->setWidth(width);
        addEventMark->setPosition(0, eventNameInput->getY() + eventNameInput->getHeight() + 1);
        addEventMark->setLabelAlignment(ofxDatGuiAlignment::CENTER);
        addEventMark->onButtonEvent(this, &ofApp::onAddNewItemButtonClick);
    
        // Simulate a break point //
        breakLabel = new ofxDatGuiLabel("Edit Event Buttons");
        breakLabel->setWidth(width);
        breakLabel->setPosition(0, addEventMark->getY() + addEventMark->getHeight() + 1);
        breakLabel->setLabelColor(ofColor(255, 255, 0));
    
        // Create a button to set the next event click to delete //
        deleteMode = new ofxDatGuiButton("Click to enter delete event mode");
        deleteMode->setStripeVisible(false);
        deleteMode->setWidth(width);
        deleteMode->setPosition(0, breakLabel->getY() + breakLabel->getHeight() + 1);
        deleteMode->setLabelAlignment(ofxDatGuiAlignment::CENTER);
        deleteMode->onButtonEvent(this, &ofApp::onDeleteModeButtonClick);
    
        // add a button to allow us to clear the scroll view out //
        clearAll = new ofxDatGuiButton("Click to clear all Events");
        clearAll->setStripeVisible(false);
        clearAll->setWidth(width);
        clearAll->setPosition(0, deleteMode->getY() + deleteMode->getHeight() + 1);
        clearAll->setLabelAlignment(ofxDatGuiAlignment::CENTER);
        clearAll->onButtonEvent(this, &ofApp::onClearAllButtonClick);
    
        // add a few items for testing //
        // for(int i=0; i<12; i++) {
        //  myEventListView.addItem("Event: " + ofToString(myEventListView.getNumItems() + 1), "red", myVideo.getFrame());
        // }
    /* End event view bar creation */
    
    
    /* Create the vieo viewer bar */
        myVideo.videoSetup();
    
        videoSlider = new ofxDatGuiSlider("Video Frame", 0, myVideo.getTotalNumFrames());
        videoSlider->setStripeVisible(false);
        videoSlider->setWidth(myVideo.getPlayerWidth(), myVideo.getPlayerWidth()/5);
        videoSlider->setPosition(screenWidth/5, myVideo.getPlayerHeight() + 1);
        videoSlider->onSliderEvent(this, &ofApp::onSliderEvent);
    /* End video viewer bar creation */
}

void ofApp::update()
{
    eventHeader->update();
    eventNameInput->update();
    addEventMark->update();
    breakLabel->update();
    deleteMode->update();
    clearAll->update();
    myEventListView.listUpdate();
    
    videoSlider->setValue(myVideo.getFrame());
    videoSlider->update();
    
    myVideo.videoUpdate();
}

void ofApp::draw()
{
    eventHeader->draw();
    eventNameInput->draw();
    addEventMark->draw();
    breakLabel->draw();
    deleteMode->draw();
    clearAll->draw();
    myEventListView.listDraw();
    
    myVideo.setFrame(myEventListView.setVideoFrame);
    myVideo.videoDraw();
    myEventListView.setVideoFrame = -1;
    
    videoSlider->draw();
}

/* Event view events -------------------------------------------------------- */
void ofApp::onEventNamedInput(ofxDatGuiTextInputEvent e)
{
    eventName = e.text;
}

void ofApp::onAddNewItemButtonClick(ofxDatGuiButtonEvent e)
{
    myEventListView.addItem("Event: " + eventName, "red", myVideo.getFrame());
}

void ofApp::onDeleteModeButtonClick(ofxDatGuiButtonEvent e)
{
    if(!deleteModeState){
        deleteMode->setLabel("Click to exit delete mode");
        deleteModeState = true;
    }else{
        deleteMode->setLabel("Click to enter delete event mode");
        deleteModeState = false;
    }
    myEventListView.deleteModeState = deleteModeState;
}

void ofApp::onClearAllButtonClick(ofxDatGuiButtonEvent e)
{
    myEventListView.clear();
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    myVideo.setFrame(e.value);
    videoSlider->setValue(e.value);
}

/* Video events ------------------------------------------------------------- */

void ofApp::keyPressed (int key){
    myVideo.videoKeyPress(key);
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){
    myVideo.videoCheckClick(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){
    
}

void ofApp::mouseExited(int x, int y){
    
}

void ofApp::windowResized(int w, int h){
    
}
