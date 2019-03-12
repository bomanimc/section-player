#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(500, 500);
    
    as3.load("as3.mp3");
    as4.load("as4.mp3");
    as5.load("as5.mp3");
    cs3.load("cs3.mp3");
    cs4.load("cs4.mp3");
    cs5.load("cs5.mp3");
    ds3.load("ds3.mp3");
    ds4.load("ds4.mp3");
    ds5.load("ds5.mp3");
    fs3.load("fs3.mp3");
    fs4.load("fs4.mp3");
    fs5.load("fs5.mp3");
    gs3.load("gs3.mp3");
    gs4.load("gs4.mp3");
    gs5.load("gs5.mp3");
    
    as3.setVolume(0.9f);
    as4.setVolume(0.9f);
    as5.setVolume(0.9f);
    cs3.setVolume(0.9f);
    cs4.setVolume(0.9f);
    cs5.setVolume(0.9f);
    ds3.setVolume(0.9f);
    ds4.setVolume(0.9f);
    ds5.setVolume(0.9f);
    fs3.setVolume(0.9f);
    fs4.setVolume(0.9f);
    fs5.setVolume(0.9f);
    gs3.setVolume(0.9f);
    gs4.setVolume(0.9f);
    gs5.setVolume(0.9f);
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
    
    // Skip the rest if we haven't loaded a frame yet
    if (frame.getImageType() == OF_IMAGE_UNDEFINED) {
        return;
    }
    
    int currentSectionIdx = (ofGetFrameNum() / 30) % (numRows * numCols);
    ofVec2f currentImagePos = sectionPositions[currentSectionIdx];
    ofImage currentSection = sections[currentSectionIdx];

    // Draw the average color of the current section
    ofColor avgColor = ofApp::getAverageColorOfSection(currentSection);
    ofSetColor(avgColor);
    ofDrawRectangle(740, (ofGetHeight() / 2) - 125, 250, 250);
    ofSetColor(255, 255, 255);
    string rbgString = "rgb(" + ofToString((int)avgColor.r) + ", " + ofToString((int)avgColor.g) + ", " + ofToString((int)avgColor.b) + ")";
    ofDrawBitmapString(rbgString, 740, (ofGetHeight() / 2) + 145);
    
    // Play sound
    if (ofGetFrameNum() % 30 == 0) {
        string rNote = ofApp::getNotesForColorAndPlay((int)avgColor.r);
        string gNote = ofApp::getNotesForColorAndPlay((int)avgColor.g);
        string bNote = ofApp::getNotesForColorAndPlay((int)avgColor.b);
        noteString = rNote + " - " + gNote + " - " + bNote;
    }
    ofDrawBitmapString(noteString, 740, (ofGetHeight() / 2) + 165);
    
    // Highlight the currently selected section. Default FPS is 60.
    ofEnableAlphaBlending();
    ofSetColor(250, 237, 39, 127);
    ofDrawRectangle(currentImagePos[0], currentImagePos[1], stepSize, stepSize);
    ofSetColor(255, 255, 255, 127);
    ofDisableAlphaBlending();
}

string ofApp::getNotesForColorAndPlay(int colorVal) {
    string note;
    
    int colorDivision = ((float)colorVal / 255) * 15;
    
    switch (colorDivision)
    {
        case 0:
        case 1:
            note = "C#3";
            cs3.play();
            break;
        case 2:
            note = "D#3";
            ds3.play();
            break;
        case 3:
            note = "F#3";
            fs3.play();
            break;
        case 4:
            note = "G#3";
            gs3.play();
            break;
        case 5:
            note = "A#3";
            as3.play();
            break;
        case 6:
            note = "C#4";
            cs4.play();
            break;
        case 7:
            note = "D#4";
            ds4.play();
            break;
        case 8:
            note = "F#4";
            fs4.play();
            break;
        case 9:
            note = "G#4";
            gs4.play();
            break;
        case 10:
            note = "A#4";
            as4.play();
            break;
        case 11:
            note = "C#5";
            cs5.play();
            break;
        case 12:
            note = "D#5";
            ds5.play();
            break;
        case 13:
            note = "F#5";
            fs5.play();
            break;
        case 14:
            note = "G#5";
            gs5.play();
            break;
        case 15:
            note = "A#5";
            as5.play();
            break;
        default:
            note = "?";
            cs3.play();
    }
    
    return note;
}

ofColor ofApp::getAverageColorOfSection(ofImage section) {
    ofColor avgColor;
    
    ofPixels pixels = section.getPixels();
    int numPixelsHoriz = section.getWidth();
    int numPixelsVert = section.getHeight();
    int samples = numPixelsHoriz * numPixelsVert;
    
    // Set up variables to calculate the sum of the r, g and b channels
    int rSum = 0;
    int gSum = 0;
    int bSum = 0;

    for(int x = 0; x < numPixelsHoriz; x++) {
        for(int y = 0; y < numPixelsVert; y++) {
            ofColor pixelColor = pixels.getColor(x, y);
            rSum += pixelColor.r;
            gSum += pixelColor.g;
            bSum += pixelColor.b;
        }
    }
    
    avgColor.r = rSum / samples;
    avgColor.b = bSum / samples;
    avgColor.g = gSum / samples;
    
    return avgColor;
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
