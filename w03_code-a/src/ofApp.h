#pragma once

#include "ofMain.h"

#include "MyClass.h"
#include "Boom.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void sparkSet(float _startX, float _startY);
		void sparkUpdate();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		float boomCount;

		vector <MyClass> shells;
		vector <Boom> sparks;
};
