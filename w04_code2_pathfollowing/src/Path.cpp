#include "Path.h"

Path::Path() {

    //start = (0,0,0);
    //finish = (0,0,0);
    radius = 0;





    //ctor
}

void Path::setInit(float _startY, float _finishY, float _radius) {
    radius = _radius;

    start = ofPoint(0,_startY);
    finish = ofPoint(ofGetWidth(),_finishY);

    cout << "height: " << ofGetHeight() << endl;

    cout << "Start: " << _startY << endl;
    cout << "End: " << _finishY << endl;


}

void Path::addPoint(ofPoint _pos) {
    ofPoint pathPoint = _pos;
    pathPoints.push_back(pathPoint);
}

ofPoint Path::getStart(){
    return start;
}

ofPoint Path::getFinish(){
    return finish;
}

void Path::draw () {
    //ofSetColor(200,130,70);

    ofNoFill();

    ofSetColor(240,170,100);
    ofSetLineWidth(radius*2);
    ofLine(start,finish);

    ofSetColor(200,130,70);
    ofSetLineWidth(10);
    ofLine(start,finish);

	//ofBeginShape();
	//for (int i = 0; i < pathPoints.size(); i++){
		//ofVertex(pathPoints[i].x, pathPoints[i].y);
		//ofVertex(pathPoints[i]);
	//}
	//ofEndShape(false);
}



Path::~Path() {

    //dtor
}
