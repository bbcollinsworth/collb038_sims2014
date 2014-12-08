#pragma once

#include "ofMain.h"
#include "Branch.h"
#include "Petal.h"
#include "Tree.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector <Tree> trees;
		vector <Branch> branches;
		vector <Petal> petals;

		bool petalMade;
		bool record;

		int recStart;

		string currentDate;



};
