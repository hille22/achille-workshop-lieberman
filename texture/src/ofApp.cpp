#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(100);
    
    
    fbo.allocate(800, 800);

    
    shader.load("", "shader.frag");
    

    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    if (ofGetFrameNum() % 60 == 0){
        shader.load("", "shader.frag");
    }

	time = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){

	float radius = 250;

	fbo.begin();
	ofEnableBlendMode(OF_BLENDMODE_DISABLED);
	ofBackground(100,40,255);

	ofEnableBlendMode(OF_BLENDMODE_ADD);

	//float duration = 
	
	ofTranslate(400,400);


	float maxOffset = 100;
	float offset = sin(time*1) * maxOffset;
	ofVec3f pos;
	ofColor col;
	float offRadius = (cos(time * 1) * radius * 0.1 )+radius;

	pos = ofVec3f(ofSignedNoise(time*0.2, 400, -200)*offset, ofSignedNoise(time*0.2, -150) * offset, 0);
	col = ofColor(100, 30, 20);
	drawCircleColor(pos, offRadius, col);
	
	pos = ofVec3f(ofSignedNoise(time*0.2, 100) * -offset, ofSignedNoise(time*0.2, 100, 400) * offset, 0);
	col = ofColor(255, 30, 0);
	drawCircleColor(pos, offRadius, col);

	pos = ofVec3f(ofSignedNoise(time*0.2, -193, 234) * offset, ofSignedNoise(time*0.02 + 40, 200, -400) * -offset, 0);
	col = ofColor(30, 255, 0);
	drawCircleColor(pos, offRadius, col);
	
	
	fbo.end();

    shader.begin();
	shader.setUniformTexture("circle", fbo.getTexture(), 0);
	shader.setUniform1f("time", time);
	ofDrawRectangle(0, 0, 800, 800);

    shader.end();


}

void ofApp::drawCircleColor(ofVec3f &center, float radius, ofColor &color, int resolution) {
	glBegin(GL_QUADS);

	float angle = ofMap(resolution-1, 0, resolution, 0, TWO_PI);
	float _x = center.x +radius * cos(angle);
	float _y = center.y + radius * sin(angle);

	for (int i = 0; i < resolution; i++) {

		angle = ofMap(i, 0, resolution, 0, TWO_PI);

		float x = center.x + radius * cos(angle);
		float y = center.y +radius * sin(angle);

		float off = ofMap(x, -radius, radius, 0, 1);

		ofColor col = color/255;
		glColor3f(0, 0, 0);
	
		glVertex3f(0, 0, 0.0f);
		glColor3f(col.r, col.g, col.b);
		glVertex3f(x, y, 0.0f);
		glVertex3f(_x, _y, 0.0f);

		_y = y;
		_x = x;
	}

	
	glEnd();
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
