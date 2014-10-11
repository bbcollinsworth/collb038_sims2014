#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle : public ofPoint {

	public:

        rectangle();

		void	draw();
		void	update(ofPoint _start);


		float offsetY;


        float distToCatch;


        vector < ofPoint > tail;

};

#endif // RECTANGLE_H
