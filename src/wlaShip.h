/*
 *  wlaShip.h
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 06/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "wlaFlyingObject.h"
#include "wlaBullet.h"

class wlaShip : public wlaFlyingObject
{

	public:
	
		wlaShip();
		~wlaShip();
		
		virtual void update(float deltaTime);
		virtual void draw();
		virtual void addRotation(float _angle);
		virtual void addThrust(float _thrust);	
		virtual void checkBounds();
	
		void reintializeShip();
	
		// Bullets:
	
		void drawBullets() const;
		void createBullet();
		void fireBullet(float deltaTime);
	
		vector<wlaBullet *> bullets;
		ofPoint bulletdirection;
		int bulletCount;
	
		// Controls:
		
		bool turnLeft, turnRight, thrust, backthrust, isFiring;
	
};