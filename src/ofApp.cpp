#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(500, 500);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0, 0, 0);
    
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int stepSize = 50;
    int margin = 10;
    int numRows = cam.getWidth() / stepSize;
    int numCols = cam.getHeight() / stepSize;
    vector<ofImage> sections;
    vector<ofVec2f> sectionPositions;
    
    if (cam.isFrameNew()){
        ofPixels pixels = cam.getPixels();
        frame.setFromPixels(pixels);
    }
    
    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            int horizInc = i * stepSize;
            int horizMargin = margin * i;
            int vertInc = j * stepSize;
            int vertMargin = margin * j;
            
            ofImage imgSection;
            imgSection.cropFrom(frame, horizInc, vertInc, stepSize, stepSize);
            sections.push_back(imgSection);
            imgSection.draw(horizInc + horizMargin, vertInc + vertMargin);
            sectionPositions.push_back(ofVec2f(horizInc + horizMargin, vertInc + vertMargin));
        }
    }
    
    // Highlight the currently selected section. Default FPS is 60.
    int currentSectionIdx = (ofGetFrameNum() / 60) % 25;
    ofVec2f currentImagePos = sectionPositions[currentSectionIdx];
    ofImage currentSection = sections[currentSectionIdx];
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 127);
    ofDrawRectangle(currentImagePos[0], currentImagePos[1], stepSize, stepSize);
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
