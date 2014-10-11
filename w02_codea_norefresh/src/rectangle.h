#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle : public ofPoint {

	public:

        rectangle();

		void	draw();
		void	xenoToPoint(ofPoint _target, ofPoint _location);

		ofPoint		target;
		ofPoint diff;
		ofPoint pCatch;
		ofPoint location;
		float		catchUpSpeed;
		float angle;
		float prevY;
		float offsetY;

        float distToCatch;
        float bodySize;
        float stretchFactor;
       // float tailSpeed;
        //float tailAmp;
        //float stretchFactor = ofMap(float(diff),0,ofGetWidth(),1,2,false);


				// take this pct of where I want to be, and 1-catchUpSpeed of my pos
        vector < ofPoint > tail;

};

#endif // RECTANGLE_H
