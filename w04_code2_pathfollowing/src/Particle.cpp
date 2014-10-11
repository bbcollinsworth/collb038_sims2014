#include "Particle.h"
#include "Path.h"

Particle::Particle() {
    pos.x = 0;
    pos.y = ofGetHeight()*ofRandomuf();
    pos.z = 0.0;

    vel.set(0,0,0);
    acc.set(0,0,0);

    //damp = 0.95; // de resistance!!!
    radius = 5;
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}

ofPoint Particle::getPosition(){
    return pos;
}

ofPoint Particle::getVelocity(){
    return vel;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::infiniteDrive(){
    if (pos.x > ofGetWidth()){
        pos.x=0;
        pos.y=ofGetHeight()*ofRandomuf();
    }
}

void Particle::addRepulsionForce(ofPoint _pos, float _rad, float _scale){

    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;// PRO way
        addForce(-diff*_scale);
    }
}

void Particle::seek( ofPoint dest, float _speed, float _force ) {
    maxSpeed = _speed;
    float maxForce = _force;

    //float slowDownRadius = 10.0;

    ofPoint desired = dest - pos;

    desired.normalize();
    desired.scale(maxSpeed);

    ofPoint steer = desired - vel;
    steer.limit( maxForce );

    addForce( steer );
}


void Particle::follow(ofPoint _pathStart, ofPoint _pathFinish, float _pathRad){

        ofPoint predict = getVelocity();
        predict.normalize();
        predict.scale(20);
        ofPoint predictLoc = getPosition() + predict;
        ofPoint a = _pathStart;
        ofPoint b = _pathFinish;
        normalPoint = getNormalPoint(predictLoc,a,b);

        ofPoint dir = b-a;
        dir.normalize();
        dir.scale(20);
        target = normalPoint + dir;

        //cout << "normalPt: " << normalPoint << endl;
        //cout << "target: " << target << endl;

        ofPoint distVect = predictLoc - normalPoint;
        float distance = distVect.length();
        if (distance > _pathRad) {
            seek(target,0.2+ofRandomuf(),ofRandomuf());
        }
}

ofPoint Particle::getNormalPoint(ofPoint p, ofPoint a, ofPoint b){
        ofPoint ap = p - a;
        ofPoint ab = b - a;
        ab.normalize();
        ab.scale(ap.dot(ab));
        ofPoint normalPoint = a + ab;
        return normalPoint;
}


void Particle::update() {

    vel += acc;
    //vel *= damp;
    pos += vel;
    acc *= 0.0;

}

void Particle::draw() {
    //DEBUG:
    //ofSetColor(255,0,0);
    //ofCircle(normalPoint, 10);
    //ofCircle(target, 10);

    ofSetRectMode( OF_RECTMODE_CENTER );

    ofPushMatrix();
    ofTranslate( pos );

    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + 90 );
    float stretchScale = ofMap(vel.length(), 0,maxSpeed, 0.5,1.3,true);
    //float stretchScale = 1;
    ofRect( 0,0, 20/stretchScale, 40*stretchScale);

    ofRect( 0,0, 16/stretchScale, 44*stretchScale);

    ofPopMatrix();
}

/*
void Particle::addAttractionForce(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;
        addForce(diff*_scale);
    }
}

void Particle::addClockwiseForce( ofPoint _pos, float _rad, float _scale){
	ofVec2f diff = pos - _pos;

	if (diff.length() < _rad){
		float pct = 1 - (diff.length() / _rad);
		diff.normalize();
		acc.x -= diff.y * pct * _scale;
		acc.y += diff.x * pct * _scale;
	}
}

void Particle::addCounterClockwiseForce( ofPoint _pos, float _rad, float _scale){
	ofVec2f diff = pos - _pos;

	if (diff.length() < _rad){
		float pct = 1 - (diff.length() / _rad);
		diff.normalize();
		acc.x += diff.y * pct * _scale;
		acc.y -= diff.x * pct * _scale;
	}
}
*/
