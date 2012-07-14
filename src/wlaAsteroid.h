/*
 *  wlaAsteroid.h
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 07/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "wlaFlyingObject.h"

class wlaAsteroid : public wlaFlyingObject
{
public:
	
	wlaAsteroid(void);
	~wlaAsteroid(void);
	
	virtual void setup(ofPoint _size, float _speed, ofPoint _position, ofPoint _direction);
	virtual void draw() const;
	virtual void update(float deltaTime);
	void checkAndSetIsBreakable();
	
	bool isBreakable;
	float rotationSpeed;
	
	vector<ofPoint> vertices;


};
