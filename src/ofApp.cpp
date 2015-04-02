#include "ofApp.h"

/* Haley Van Camp
    04/01/2015
    Polyline Seaweed quiz
 */

//--------------------------------------------------------------
void ofApp::setup(){
    frameNum = 0; // counter for each frame
    darkBlue.r = 3;  // dark blue color
    darkBlue.g = 28;
    darkBlue.b = 126;
    limeGreen.r = 46; // lime green color
    limeGreen.g = 252;
    limeGreen.b = 35;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);
    // five vertices
    middle = 550 + 150 * sin(frameNum/122); // x point + the distance of movement multiplied by the sin of
    // the frame number divided by a larger number so it moves quicker
    top = middle + 75 * sin(frameNum/50); // uses 'middle' for location + a smaller distance of movement mulitplied by the sin of the frame number divided by a smaller number so it moves less quickly
    curvedSegmentPolyline.clear(); // clears polyline
    curvedSegmentPolyline.curveTo(top, 100); // declaring vertices
    curvedSegmentPolyline.curveTo(top, 100);
    curvedSegmentPolyline.curveTo(middle, 235);
    curvedSegmentPolyline.curveTo(550, 500);
    curvedSegmentPolyline.curveTo(550, 768);
    curvedSegmentPolyline.curveTo(550, 768);
    
    frameNum++; // increases as each frame runs

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(10, 200, 50); // green color for polyline

    curvedSegmentPolyline.draw(); // draws the polyline
    
    
        float normalLength = 200; 
        float numPoints = curvedSegmentPolyline.size(); //number of points based on the size of the polyline's points
   

    for(int p=0; p<100; p+=1) {
            ofVec3f point = curvedSegmentPolyline.getPointAtPercent(p/100.0); // returns a point at a percentage along the polyline
        float floatIndex = p/100.0 * (numPoints-1);
        ofVec3f normal = curvedSegmentPolyline.getNormalAtIndexInterpolated(floatIndex) * normalLength * p/100.0; // normalLength multiplied by p/100.0 for the increasing line length
        currentColor = limeGreen; // stores the limeGreen color into current color
        currentColor.lerp(darkBlue, p/100.0); // finds a color between lime green and dark blue based on the percentage (p/100.00)
        ofSetColor(currentColor); // sets the lines at the current color
        ofLine(point-normal/2, point+normal/2); // draws the lines along the polyline
      
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
