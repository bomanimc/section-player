#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        ofColor getAverageColorOfSection(ofImage section);
        string getNotesForColorAndPlay(int colorVal);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber cam;
    ofImage frame;
    string noteString;
    
    // Sounds
    ofSoundPlayer as3;
    ofSoundPlayer as4;
    ofSoundPlayer as5;
    ofSoundPlayer cs3;
    ofSoundPlayer cs4;
    ofSoundPlayer cs5;
    ofSoundPlayer ds3;
    ofSoundPlayer ds4;
    ofSoundPlayer ds5;
    ofSoundPlayer fs3;
    ofSoundPlayer fs4;
    ofSoundPlayer fs5;
    ofSoundPlayer gs3;
    ofSoundPlayer gs4;
    ofSoundPlayer gs5;
};
