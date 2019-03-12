#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(500, 500);
    
    c1.load("c1.mp3");
    c1s.load("c1s.mp3");
    d1.load("d1.mp3");
    d1s.load("d1s.mp3");
    e1.load("e1.mp3");
    f1.load("f1.mp3");
    f1s.load("f1s.mp3");
    g1.load("g1.mp3");
    g1s.load("g1s.mp3");
    a1.load("a1.mp3");
    a1s.load("a1s.mp3");
    b1.load("b1.mp3");
    c2.load("c2.mp3");
    
    c1.setVolume(0.9f);
    c1s.setVolume(0.9f);
    d1.setVolume(0.9f);
    d1s.setVolume(0.9f);
    e1.setVolume(0.9f);
    f1.setVolume(0.9f);
    f1s.setVolume(0.9f);
    g1.setVolume(0.9f);
    g1s.setVolume(0.9f);
    a1.setVolume(0.9f);
    a1s.setVolume(0.9f);
    b1.setVolume(0.9f);
    c2.setVolume(0.9f);
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
    ofSetColor(255, 255, 255, 127);
    ofDrawRectangle(currentImagePos[0], currentImagePos[1], stepSize, stepSize);
    ofDisableAlphaBlending();
}

string ofApp::getNotesForColorAndPlay(int colorVal) {
    string note;
    
    int colorDivision = ((float)colorVal / 255) * 13;
    
    switch (colorDivision)
    {
        case 0:
        case 1:
            note = "C";
            c1.play();
            break;
        case 2:
            note = "C#";
            c1s.play();
            break;
        case 3:
            note = "D";
            d1.play();
            break;
        case 4:
            note = "D#";
            d1s.play();
            break;
        case 5:
            note = "E";
            e1.play();
            break;
        case 6:
            note = "F";
            f1.play();
            break;
        case 7:
            note = "F#";
            f1s.play();
            break;
        case 8:
            note = "G";
            g1.play();
            break;
        case 9:
            note = "G#";
            g1s.play();
            break;
        case 10:
            note = "A";
            a1.play();
            break;
        case 11:
            note = "A#";
            a1s.play();
            break;
        case 12:
            note = "B";
            b1.play();
            break;
        case 13:
            note = "C2";
            c2.play();
            break;
        default:
            c2.play();
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
