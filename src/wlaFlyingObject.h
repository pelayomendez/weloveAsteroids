/*
 *  wlaFlyingObject.h
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 06/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"

class wlaFlyingObject
{
	
public:
	
	wlaFlyingObject();
	~wlaFlyingObject();
	
	virtual void update(float deltaTime);
	virtual void draw();
	virtual bool checkCollision(wlaFlyingObject* obj) const;
	virtual void checkBounds();
	virtual void addRotation(float _angle);
	
	ofPoint position, direction, size;
	float angle, speed;
	
};