/*
 *  wlaBullet.h
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 07/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "wlaFlyingObject.h"

class wlaBullet : public wlaFlyingObject
{
public:
	
	wlaBullet(ofPoint _size);
	~wlaBullet(void);
	
	virtual void draw() const;
	virtual void update(float deltaTime);
	virtual void checkBounds();
	
	void startPositionSetup(ofPoint shipCoord, ofPoint shipDirection,ofPoint shipSize);
	bool getMaxFireDistanceReached() const;
	float getDistanceBetweenShipAndBullet() const;
	
	float fireDistance;
	float lifeTime;
	ofPoint tempStartPosition;
	
};