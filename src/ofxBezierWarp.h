/*
 *  ofxBezierWarp.h
 *
 *  Created by Patrick Saint-Denis on 12-03-05.
 *	A Bezier Warp made of multiple homographies
 *
 *  added by Hiroshi Kanechiku 13-3-23
 */

#pragma once

#include "ofMain.h"

class ofxBezierWarp{

private:
	int mousePosX, mousePosY, rad;
	float width, height;
	int selectedSprite[4], selectedControlPoint[8], anchorControl, mouseON, spritesON;


public:

    //hk for status (debugging)
	int premousePosX, premousePosY;

    //hk for multi use of bezierWarp
    int id=0;
    string presetfname="presets.bin";
    void setPresetfilename();
	//hk for function ease of use
    bool show=true;
	bool newpoints=true;
	bool calcbezier=true;// calc bezier control point at draw
	ofPoint bezSurfPoints[100+1][100+1];
    //for easier anchor and corner handling
    void sprites(float xd, float yd, int num);
    bool cornerselected=false;
	ofPoint preanchors[8];



	ofPoint corners[4];
	ofPoint anchors[8];
	int gridRes;
	ofxBezierWarp(){}

	void setup(int grid);
	void draw(ofTexture texture);
	void sprites();
	float bezierPoint(float x0, float x1, float x2, float x3, float t);
	void defaults();
	void save();
	void recall();
	void mousePressed(int x, int y);
	void mouseDragged(int x, int y);
	void keyPressed(int clef);


};
