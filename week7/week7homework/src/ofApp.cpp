#include "ofApp.h"

bool sortVertically(basicSprite*a, basicSprite*b){
    return  a->pos.y > b->pos.y;
}

int ofApp::getTileName(int x, int y){
    return backgrounds[y*gridW +x ]->tileName;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    
    spriteRenderer = new ofxSpriteSheetRenderer(2, 10000, 0 ,16);
    
    spriteRenderer->loadTexture("spritesheet.png", 64, GL_NEAREST);
    
    player = new basicSprite();
    player->pos.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    player->speed = 0.1;
    player->animation = walkAnimation;
    
//    player -> animation.index = 6;
    
    //loop through the grid size that we want, make a new sprite for each background tile we want,
    //then set its position based on the grid and our scale, then push it to the vector to hold it.
    //we'll be looping through the vector to access these sprites' values.
    for (int i = 0; i < gridH; i++) {
        for (int j = 0; j < gridW; j++) {
            basicSprite * newSprite = new basicSprite();
            newSprite->pos.set(j*spriteRenderer->getTileSize()*scale, i*spriteRenderer->getTileSize()*scale);
            newSprite->tileName = (int)ofRandom(12,15);
            backgrounds.push_back(newSprite);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //updates renderer
    spriteRenderer->clear();
    spriteRenderer->update(ofGetElapsedTimeMillis());
    
   
    spriteRenderer->addCenteredTile(&player->animation, player->pos.x - cameraCenter.x, player->pos.y - cameraCenter.y, 1, F_NONE, scale);
    
    //if there are backgrounds, loop through it and add each one to the renderer.
    if (backgrounds.size() > 0) {
        for (int i = backgrounds.size()-1; i>=0; i--) {
           
            if (backgrounds[i]->pos.x > 0 && backgrounds[i]->pos.x < ofGetWindowWidth() && backgrounds[i]->pos.y > 0 && backgrounds[i]->pos.y < ofGetWindowHeight()) {
            spriteRenderer->addCenteredTile(backgrounds[i]->tileName, 0, backgrounds[i]->pos.x, backgrounds[i]->pos.y, 0, 1, 1, F_NONE, scale);
                if(backgrounds[i]->tileName == 14){
                    onYellow =true;
                    cout<< onYellow << endl;
                }else{
                    onYellow = false;
                }
            }
        }
    }
    
    //moves background tiles based on where camera is
    for (int i = 0; i < gridH; i++) {
        for (int j = 0; j < gridW; j++) {
            backgrounds[i * gridW + j]->pos.set(j*spriteRenderer->getTileSize()*scale - cameraCenter.x, i*spriteRenderer->getTileSize()*scale - cameraCenter.y);
        }
    }
    
    //update the player's position and animation index based on key presses.
//    if(onYellow==true){
    if (leftKeyPressed) {
        player->pos.x -= player->speed * spriteRenderer->getTileSize()*scale;
        player->animation.index = 8;
    }
    if (rightKeyPressed) {
        player->pos.x += player->speed * spriteRenderer->getTileSize()*scale;
        player->animation.index = 6;
    }
    if (upKeyPressed) {
        player->pos.y -= player->speed * spriteRenderer->getTileSize()*scale;
        player->animation.index = 4;
    }
    if (downKeyPressed) {
        player->pos.y += player->speed * spriteRenderer->getTileSize()*scale;
        player->animation.index = 1;
    }
   // }
    
   //doesnt loop if not key pressed; loops infinitely if key pressed
    if (!leftKeyPressed && !rightKeyPressed && !upKeyPressed && !downKeyPressed) {
        
        player->animation.loops = 0;
    } else {
        player->animation.loops = -1;
        
        //this is an application of how we could check the player's position against the tiles.
        //we could use this approach to do collision detection for example.
        
        int tilePosX = floor((player->pos.x + (spriteRenderer->getTileSize() * scale)/2) / (spriteRenderer->getTileSize() * scale));
        int tilePosY = floor((player->pos.y + (spriteRenderer->getTileSize() * scale)/2) / (spriteRenderer->getTileSize() * scale));
        
        cout << "pos.x relative to tiles: " <<  tilePosX << ", pos.y relative to tiles: " <<  tilePosY << endl;
        
        cout << "background sprite index: " << getTileName(tilePosX, tilePosY) << endl;
    }
    
    //update the camera position to focus on the player's position.
    cameraCenter.x = player->pos.x - ofGetWindowWidth()/2;
    cameraCenter.y = player->pos.y - ofGetWindowHeight()/2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    spriteRenderer->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT) {
        leftKeyPressed = true;
    }
    if (key == OF_KEY_RIGHT) {
        rightKeyPressed = true;
    }
    if (key == OF_KEY_UP) {
        upKeyPressed = true;
    }
    if (key == OF_KEY_DOWN) {
        downKeyPressed = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_LEFT) {
        leftKeyPressed = false;
    }
    if (key == OF_KEY_RIGHT) {
        rightKeyPressed = false;
    }
    if (key == OF_KEY_UP) {
        upKeyPressed = false;
    }
    if (key == OF_KEY_DOWN) {
        downKeyPressed = false;
    }
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
