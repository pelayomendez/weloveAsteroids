/*
 *  wlaBullet.cpp
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 07/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "wlaBullet.h"
#include <iostream>

wlaBullet::wlaBullet(ofPoint _size)
{
	size = _size;	
}

wlaBullet::~wlaBullet(void)
{
}

void wlaBullet::draw() const
{	
	
	ofPushStyle();
	ofPushMatrix();
	ofRect(position.x, position.y, size.x, size.y);
	ofPopMatrix();
	ofPopStyle();
	

}

void wlaBullet::startPositionSetup(ofPoint shipCoord, ofPoint shipDirection, ofPoint shipSize)
{
	position.x = shipCoord.x;
	position.y = shipCoord.y;
	direction.x = -shipDirection.x;
	direction.y = -shipDirection.y;
	
	tempStartPosition = shipCoord;
}

bool wlaBullet::getMaxFireDistanceReached() const
{
	
	if ( lifeTime <= 0) {
		return true;
	}
	else
		return false;
}

float wlaBullet::getDistanceBetweenShipAndBullet() const
{
	return ofDist(tempStartPosition.x,tempStartPosition.y, position.x, position.y);
}

void wlaBullet::update(float deltaTime){
	
	position += direction * speed * deltaTime;
	lifeTime -= 0.5;
	checkBounds();
	
}

void wlaBullet::checkBounds()
{
	
	if ( position.x > (float)ofGetWidth() )
		position.x =  0.0;
	if ( position.y > (float)ofGetHeight() )
		position.y = 0.0;
	if ( position.x + size.x < 0 )
		position.x = ofGetWidth();
	if ( position.y + size.y < 0 )
		position.y = ofGetHeight();
	
}
