
//
//  Particle.cpp
//  myFlocking
//
//  Created by Regina Flores on 9/25/14.
//
//

#include "Particle.h"
#include "Tail.h"


Particle::Particle(){

    radius = ofRandomuf()*5;

}

void Particle::init(){

    //defining the position and velocity of the particles
    //pos = ofPoint(ofGetWidth()/2,ofGetHeight()/2, -30);
    //using easy cam changes (0,0) to middle of screen
    pos = ofPoint(ofRandomWidth(),ofRandomHeight());
    //pos = ofPoint(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),ofRandom(-ofGetHeight()/2, ofGetHeight()/2));//, ofRandom(-200, 200));
//    vel = ofPoint(ofRandom(-10, 10), ofRandom(-10, 10), ofRandom(-10, 10));
    vel = ofPoint(ofRandomf(), ofRandomf());//, ofRandom(-1, 1));

   // for (int i; i<6; i++){
       //      float col=ofRandomuf();
        //float col=_colMults[i];
      //  cols.push_back(col);
   // }

}

void Particle::bounding(){

    //keeping the particles inside the screen
    //note: the new screen width is (-w/2,w/2), same for height
    if(pos.y > ofGetHeight()){
        vel = -vel;
    }
    if(pos.y < 0){
        vel = -vel;
    }

    if(pos.x > ofGetWidth()){
        vel = -vel;
    }
    if(pos.x < 0){
        vel = -vel;
    }
    /*
    if(pos.y > ofGetHeight()/2){
        vel = -vel;
    }
    if(pos.y < -ofGetHeight()/2){
        vel = -vel;
    }

    if(pos.x > ofGetWidth()/2){
        vel = -vel;
    }
    if(pos.x < -ofGetWidth()/2){
        vel = -vel;
    }*/
    //if(pos.z < -200){
      //  vel = -vel;
    //}
    //if(pos.z > 200){
      //  vel = -vel;
    //}
    //
}

//NOTE: Flocking Rules
// each particle compares his state (i.e position and vel) to others to change velocity
//we pass the vector of particles into the update function
//http://www.kfish.org/boids/pseudocode.html

ofPoint Particle::cohesion(vector<Particle> &particles){

    //RULE 1
    //finding the center of mass of the system
    ofPoint centerMass;
    for(int i = 0; i < particles.size(); i++){
        //determining if the particle in the loop is itself
        //to avoid itself
        if (&particles[i] == this) {
            continue;
        }

        centerMass += particles[i].pos;

    }

    centerMass = centerMass/(particles.size()-1);

    ofPoint cohesion_velocity;
    cohesion_velocity = (centerMass-pos)/100.0f;
    return cohesion_velocity;
}

ofPoint Particle::separation(vector<Particle> &particles){
    //RULE 2
    //particles keep a small distance from each other

    ofPoint displace;
    for(int i = 0; i < particles.size(); i++){
        //determining if the particle in the loop is itself
        //to avoid itself
        if (&particles[i] == this) {
            continue;
        }

        // distance between me and particles[i]
        float dist = pow(particles[i].pos.x - pos.x, 2) + pow(particles[i].pos.y - pos.y, 2);// + pow(particles[i].pos.z - pos.z, 2);
        dist = sqrt(dist);

        if (dist < 10+sin(ofGetFrameNum()*0.1)*ofRandom(8,10)) {
            displace  = displace - (particles[i].pos - pos);
        }

    }

    ofPoint separation_velocity;
    separation_velocity = displace;
    return separation_velocity;
}

ofPoint Particle::allignment(vector<Particle> &particles){

    //RULE 3
    //match velocity

    ofPoint aveVel;
    for(int i = 0; i < particles.size(); i++){
        //determining if the particle in the loop is itself
        //to avoid itself
        if (&particles[i] == this) {
            continue;
        }

        aveVel += particles[i].vel;

    }

    aveVel = aveVel/(particles.size()-1);

    ofPoint allignment_velocity;
    allignment_velocity = (aveVel - vel)/8.0f;
    return allignment_velocity;

}

void Particle:: update( vector<Particle> &particles ){
    //& pointer notation (ref of the array)

    ofPoint v1 = cohesion(particles);
    ofPoint v2 = separation(particles);
    ofPoint v3 = allignment(particles);

    vel = vel + v1 + v2 + v3;
    pos = pos + vel;

    Tail newTail;
    newTail.setInit(ofPoint(pos.x,pos.y));

    tail.push_back(newTail);

    if (tail.size() > 10) {
        tail.erase(tail.begin());
    }

}


void Particle::draw(){

    for (int i = 0; i < tail.size(); i++){
        ofSetColor(255/(i+1),255/((i+1)*(i+1)*0.8),50/(i+1),100);
        //tail[i].update();
               // int r = colorMap-(i*cols[1]);
               // int g = (colorMap*cols[2])-((tail.size()-i)*cols[3]);
               // int b = (colorMap*cols[4])-((tail.size()-i)*cols[0]);

        tail[i].draw(radius*(i+1));
    }

    int rad = radius*2;

    for (int j = 0; j < rad; j++){
    ofSetColor(255-(j*5),255-(j*5),255/(rad-j),100);
    ofCircle(pos.x, pos.y, (rad-j)*(rad-j)*0.1); //pos.z, radius);
    }

}

