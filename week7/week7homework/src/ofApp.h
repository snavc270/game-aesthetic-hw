#pragma once

#include "ofMain.h"
#include "ofxSpriteSheetRenderer.h"

static animation_t walkAnimation =
{ 0,
  0,
  2,
    1,
    1,
    90,
    0,
    -1,
    -1,
    1
};

struct basicSprite {
    animation_t animation;
    int tileName;
    ofPoint pos;
    float speed;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
    ofxSpriteSheetRenderer* spriteRenderer;
    
    basicSprite*player;
    vector<basicSprite *> backgrounds; 
    //vector for background tiles
    
    ofPoint cameraCenter;
    
    const float scale = 3;
    const int gridW= 50;
    const int gridH= 50;
    
    bool rightKeyPressed;
    bool leftKeyPressed;
    bool upKeyPressed;
    bool downKeyPressed;
    bool onYellow; 
    
    int getTileName(int x, int y);
		
};
