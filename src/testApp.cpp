#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0);
	ofSetFrameRate(60);
	gameManager = new wlaGameManager();
	deltaTime = 0.0f;
}

//--------------------------------------------------------------
void testApp::update(){
	//deltaTime = ofGetElapsedTimef();
	gameManager->update(0.006);
	//ofResetElapsedTimeCounter();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	gameManager->draw();
	ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), ofPoint(20,20));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}