/*
 *  wlaFlyingObject.cpp
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 06/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "wlaFlyingObject.h"

wlaFlyingObject::wlaFlyingObject()
{
	

	
}

wlaFlyingObject::~wlaFlyingObject()
{
	
}

void wlaFlyingObject::draw(){
	
}

void wlaFlyingObject::update(float deltaTime){
	
	position += direction * speed * deltaTime;
	checkBounds();
	
}

void wlaFlyingObject::addRotation(float _angle)
{
	angle += _angle;
}

bool wlaFlyingObject::checkCollision(wlaFlyingObject *obj) const
{
	
	if(ofDist(position.x, position.y, obj->position.x, obj->position.y) <= obj->size.x) {
		return true;
	}
	
	/*
	if ( (position.x + size.x) > obj->position.x &&
		(position.y + size.y) > obj->position.y ) {
		if ( position.x < (obj->position.x + obj->size.x) &&
			position.y < (obj->position.y + obj->size.y)) {
			return true;
		}
	}
	*/
	
	return false;
}


void wlaFlyingObject::checkBounds()
{
	if ( position.x - size.x > (float)ofGetWidth() )
		position.x =  -size.x;
	if ( position.y - size.y > (float)ofGetHeight() )
		position.y = -size.y;
	if ( position.x + size.x < 0 )
		position.x = ofGetWidth();
	if ( position.y + size.y < 0 )
		position.y = ofGetHeight();
	
}