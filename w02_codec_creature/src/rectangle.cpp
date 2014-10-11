#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.005f;
    bodySize = 30;



	//stretchFactor = ofMap(distToCatch,0,ofGetWidth(),1,2,false);

	//distToCatch = ofDist(rectangle.x,rectangle.y, mouseX, mouseY);
}

//------------------------------------------------------------------
void rectangle::draw() {


    ofPushMatrix();
    ofTranslate(*this); //translates 0,0 to center of ofPoint or "*this"

    //distToCatch = ofDist(0,0,pCatch.x,pCatch.y);
    stretchFactor = ofMap(distToCatch,0,ofGetWidth(),1,4,true);
    float tailSpeed = abs(ofMap(distToCatch,0,ofGetWidth(),-0.05,-0.03,true));
    float tailAmp = 0.5-abs(ofMap(distToCatch,0,ofGetWidth(),-0.47,0.47,true));


    //if (angle >= 360){

//} else {
//ofRotate(ofRadToDeg(-angle));
//}


    ofFill();
   // ofPushStyle();
    ofSetColor(100,230,255);
    //ofPushStyle();

 ofRotate(ofRadToDeg(angle)); //rotates by angle translated to degrees
    ofSetColor(200,230,255,100);
    ofEllipse(0, 0, bodySize*stretchFactor, bodySize/stretchFactor);

    ofSetColor(200,230,255,255);
    ofEllipse(0, 0, bodySize*stretchFactor*0.8, bodySize/stretchFactor*0.8); // X & Y are 0,0 because translated to center



            ofBeginShape();
            for (int i=10; i < tail.size(); i+=3) {
                //ofVertex(tail[i]);

    float tailDiff = abs(ofRadToDeg(pAngle)-ofRadToDeg(angle));
                float tailScale = ofMap(i,0,tail.size(), 1,0, true);
                float tailRot = ofMap(i,0,450, abs(359), 0, false);
                //float tailCurve = ofMap(i,3,tail.size(),0,tailDiff,true);
                float tailCurve = abs(ofMap(i,3,tail.size(),0,ofRadToDeg(angle),true));
               //float tailCurve = abs(ofMap(i,3,tail.size(),ofRadToDeg(pAngle),ofRadToDeg(angle),true));
                float curveTimer = ofMap(distToCatch,0,ofGetWidth(),0,0.2,true);

                 //ofRotate(tailCurve*curveTimer);

                   //cout << tailCurve << endl;
                //ofRotate(-tailCurve*curveTimer);
                //ofRotate(ofRadToDeg(ofLerp(tailRot, atan2(diff.y,diff.x), 0.01)));
               // ofSetRectMode(OF_RECTMODE_CENTER);

                ofSetColor(0,200,255,150);
                ofCircle(tail[i].x, (sin(tail[i].y*.05-ofGetFrameNum()*tailSpeed))*tailAmp*i,bodySize*0.2*tailScale,bodySize*0.2*tailScale);


                ofSetColor(50,255,255,250);
                ofCircle(tail[i].x, (sin(i*.05-ofGetFrameNum()*tailSpeed))*tailAmp*i,bodySize*0.1*tailScale,bodySize*0.1*tailScale);

               // ofSetColor(255,100,50,250);
                //ofRect(i+5,(sin(i*tailSpeed+ofGetFrameNum()*1))*i*tailAmp+5,bodySize*0.2-i*0.01,bodySize*0.2-i*0.01);

               // prevY[i]=(sin(i*tailSpeed+ofGetFrameNum()*1))*i*tailAmp;
                //I set the above to NEGATIVE frameNum to make the tail wag from the source.
                //WHAT ABOUT tying the frequency to an exponential framecount?
                //tie framecount multiplier to distance from target to speed up or slow down tail motion -- smaller multiplier = slower

                //cout << tail[i] << endl;

            }

    //        for (auto &it: tail) {
    //            ofVertex(it);
    //        }

            ofEndShape(false);
    //ofPopStyle();
   // ofPopMatrix();

   // ofPushMatrix();
   // ofTranslate(*this);



  ofPopMatrix();

    //cout << tailCurve << endl;
   // cout << stretchFactor << endl;
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(ofPoint _catch, ofPoint _loc){
    set(catchUpSpeed * _catch + (1-catchUpSpeed) * (*this)); //easing of difference

    //tailCatch = _catch;
    diff = *this - _catch; //gets the difference between ofPoint location and target

    //if (angle < TWO_PI) {
    angle = ofLerp(angle, atan2(diff.y,diff.x), 0.01); //calculates the angle for rotation
    //} else {
    //    angle = ofLerp(angle, -atan2(diff.y,diff.x), 0.01);
    //}

    if (angle < -PI) {
            angle += PI;
    }

    if (angle > PI) {
            angle -= PI;
    }

    //cout << atan2(diff.y,diff.x) << endl;
    //cout << angle << endl;

    tail.push_back(*this);


    if(tail.size()>200){
        tail.erase(tail.end());
    }

    distToCatch = ofDist(_loc.x,_loc.y,_catch.x,_catch.y);

    pCatch = _catch;

    offsetY = abs(prevY - _loc.y);

    prevY = _loc.y;

    pAngle = angle;




}
