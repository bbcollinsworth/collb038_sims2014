#ifndef VECTORFIELD_H
#define VECTORFIELD_H

#include "ofMain.h"

class VectorField
{
    public:
        VectorField();
        virtual ~VectorField();

        void setup(int _w, int _h, int _res);

        int width, height, depth, res;
        int cols, rows, zrows;

        ofPoint getForce(ofPoint _pos);
        void setNoise(int zloc);
        void addRepulsionForce(ofPoint _pos, float _rad, float _scale);

        void draw();
        vector < vector<ofPoint> > table;
        //vector <vector < vector<ofPoint>>> field;


    protected:
    private:
};

#endif // VECTORFIELD_H
