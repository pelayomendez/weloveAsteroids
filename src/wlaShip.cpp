/*
 *  wlaShip.cpp
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 06/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "wlaShip.h"

wlaShip::wlaShip()
{
	
		
	size.x = 30;
	size.y = 20;

	
	position.x = ofGetWidth()/2 - size.x / 2;
	position.y = ofGetHeight()/2 - size.y / 2;
	
		
	angle = PI/2;
	speed = 0;
	
	bulletCount = 0;
	
	turnLeft = turnRight = thrust = backthrust = isFiring = false;
	
}

wlaShip::~wlaShip()
{
	
}

void wlaShip::reintializeShip()
{
	position.x = ofGetWidth()/2 - size.x / 2;
	position.y = ofGetHeight()/2 - size.y / 2;
	angle = PI/2;
	speed = 0;
	bulletCount = 0;
	turnLeft = turnRight = thrust = backthrust = isFiring = false;
}



void wlaShip::update(float deltaTime)
{
	
	if (turnLeft) addRotation(-0.030);
	if (turnRight) addRotation(0.030);
	if ( thrust ) {
		addThrust(5);
	} else {
		addThrust(-2);
	}
	if (backthrust) addThrust(-1.5);
	
	if (thrust) {
		direction.x = cos(angle);
		direction.y = sin(angle);
	}
	
	bulletdirection.x = cos(angle);
	bulletdirection.y = sin(angle);
	if ( isFiring )
		createBullet();
	
	fireBullet(deltaTime);
	
	position += -(direction) * speed * deltaTime;
	
	checkBounds();
	
}

void wlaShip::draw(){
	
	ofPushStyle();
	ofPushMatrix();
		ofSetColor(255,0,0);
		ofTranslate(position.x,position.y,0);
		ofRotate((angle - PI/2) / PI * 180, 0,0,1);
		ofRotate(-90); // Corrección del dibujo:
		ofTranslate(-size.x/2, -size.y/2);
		ofLine(0,0,size.x,size.y/2);
		ofLine(size.x,size.y/2,0,size.y);
		ofLine(size.x*0.1,size.y*0.1,size.x*0.1,size.y-size.y*0.1);
		if (thrust || backthrust) {
			ofLine(size.x * 0.1, size.y * 0.1 + 2, size.x*0.1 - size.x*0.2, (size.y - size.y*0.1) / 2);
			ofLine(size.x * 0.1 - size.x*0.2, (size.y - size.y*0.1) / 2, size.x*0.1, size.y - size.y*0.1 - 2);
		}
	ofPopMatrix();
	ofPopStyle();
	
	drawBullets();
	
	
}

void wlaShip::addRotation(float _angle)
{
	angle += _angle;
}

void wlaShip::addThrust(float _thrust)
{
	speed += _thrust;
	if ( speed > 600 )
		speed = 600;
	else if ( speed < 0.0 && !backthrust )
		speed = 0.0;
	
	if ( backthrust ) {
		speed += thrust;
		if ( speed < 0.0 )
			speed = 0.0;
	}
	
	
	
}

// SCREEN LIMITS

void wlaShip::checkBounds()
{
	if ( position.x > (float)ofGetWidth() )
		position.x =  -size.x;
	if ( position.y > (float)ofGetHeight() )
		position.y = -size.y;
	if ( position.x + size.x < 0 )
		position.x = ofGetWidth();
	if ( position.y + size.y < 0 )
		position.y = ofGetHeight();
}

// BULLETS

void wlaShip::drawBullets() const
{
	if (bullets.size() > 0) {
		for ( unsigned int i = 0; i < bullets.size(); i++ ) {
			bullets[i]->draw();
		}
	}
}

void wlaShip::createBullet()
{
	if ( bulletCount < 1 ) {
		wlaBullet* newBullet = new wlaBullet(ofPoint(2,2));
		newBullet->startPositionSetup(this->position, this->bulletdirection, this->size);
		//newBullet->setup(ofPoint(10,10));
		newBullet->speed = 1200;
		newBullet->lifeTime = 60;
		bullets.push_back(newBullet);
		bulletCount++;
	}
}

void wlaShip::fireBullet(float deltaTime)
{
	if ( bullets.size() > 0 ) {
		for ( unsigned int i = 0; i < bullets.size(); i++ ) {
			bullets[i]->update(deltaTime);
			if ( bullets[i]->getMaxFireDistanceReached() )
				bullets.erase(bullets.begin() + i);
		}
	}
}


