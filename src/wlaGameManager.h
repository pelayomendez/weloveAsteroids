/*
 *  wlaGameManager.h
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 06/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"
#include "wlaShip.h"
#include "wlaAsteroid.h"

class wlaGameManager 
{
	public:
		
		wlaGameManager();
		~wlaGameManager();
		void update(float deltaTime	);
		void draw();
		
		void handleKey(int key, bool value);
		void keyPressed(ofKeyEventArgs& arg);
		void keyReleased(ofKeyEventArgs& arg);
	
	private:
		
		// Esto deberia ir en el data Manager:
		
		wlaShip* spaceShip;
	
		void generateAsteroids(int numAsteroids);
		void normalizeOfPoint(ofPoint& point);
		vector<wlaAsteroid *> asteroids;
	
		void checkCollisions();
		void splitAsteroid(int which);
	
};