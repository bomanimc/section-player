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
    
    if (cam.isFrameNew()){
        ofPixels pixels = cam.getPixels();
        frame.setFromPixels(pixels);
    }
    
    for (int i = 0; i < frame.getWidth() / stepSize; i++) {
        for (int j = 0; j < frame.getHeight() / stepSize; j++) {
            int horizInc = i * stepSize;
            int horizMargin = margin * i;
            int vertInc = j * stepSize;
            int vertMargin = margin * j;
            
            frame.drawSubsection(horizInc + horizMargin, vertInc + vertMargin, stepSize, stepSize, horizInc, vertInc);
        }
    }
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
