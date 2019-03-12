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
    ofSoundPlayer c1;
    ofSoundPlayer c1s;
    ofSoundPlayer d1;
    ofSoundPlayer d1s;
    ofSoundPlayer e1;
    ofSoundPlayer f1;
    ofSoundPlayer f1s;
    ofSoundPlayer g1;
    ofSoundPlayer g1s;
    ofSoundPlayer a1;
    ofSoundPlayer a1s;
    ofSoundPlayer b1;
    ofSoundPlayer c2;
};
