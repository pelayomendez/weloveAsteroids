/*
 *  wlaGameManager.cpp
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 06/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "wlaGameManager.h"

wlaGameManager::wlaGameManager()
{
	
	spaceShip = new wlaShip();
	
	ofAddListener(ofEvents.keyPressed, this, &wlaGameManager::keyPressed );
	ofAddListener(ofEvents.keyReleased, this, &wlaGameManager::keyReleased );
	
	generateAsteroids(4);
	
}

wlaGameManager::~wlaGameManager()
{
	
}

void wlaGameManager::update(float deltaTime){
	
	spaceShip->update(deltaTime);
	for ( unsigned int i = 0; i < asteroids.size(); i++ ) {
		asteroids[i]->update(deltaTime);
		asteroids[i]->checkAndSetIsBreakable();
	}
	checkCollisions();
	
}

void wlaGameManager::draw(){
	
	spaceShip->draw();
	for ( unsigned int i = 0; i < asteroids.size(); i++ ) {
		asteroids[i]->draw();
	}
	
}


// COLISIONES

void wlaGameManager::checkCollisions()
{	
	
	for ( unsigned int i = 0; i < asteroids.size(); i++ ) {
		if ( spaceShip->checkCollision(asteroids[i]) ) {
			spaceShip->reintializeShip();
		}
	}
	
	
	// Bucle de spaceships o todas las bullets en un sitio:
	
	if (spaceShip->bullets.size() > 0) {
		
		for ( unsigned int i = 0; i < spaceShip->bullets.size(); i++ ) {
			for ( unsigned int j = 0; j < asteroids.size(); j++ ) {
				
				if ( spaceShip->bullets[i]->checkCollision(asteroids[j]) ) {
					
					
					cout << "Bullet " << i << " hit Asteroid " << j << endl;
					spaceShip->bullets[i]->lifeTime = 0;
					splitAsteroid(j);
					
					
					
				}
				
			}
		}
		
	}
}

void wlaGameManager::splitAsteroid(int which)
{
	if (asteroids[which]->size.x > 20 && asteroids[which]->size.y > 20 ) {
		
		for ( unsigned int i = 0; i < (asteroids[which]->size.x/40)+1; i++ ) {
			wlaAsteroid* newAsteroid = new wlaAsteroid();
			newAsteroid->setup(asteroids[which]->size / 2, asteroids[which]->speed, asteroids[which]->position, ofPoint(-(ofRandom(-1, 1)), ofRandom(-1, 1)));
			newAsteroid->rotationSpeed = -asteroids[which]->rotationSpeed;
			asteroids.push_back(newAsteroid);
			//asteroids[which]->size /= 2;
		}
		
	} 
	
	asteroids.erase(asteroids.begin() + which);
	
	if(asteroids.size() == 0) {
		
		generateAsteroids(ofRandom(4,6));
		
	}
	
}


// ASTEROIDS

void wlaGameManager::generateAsteroids(int numAsteroids)
{
	ofPoint randDirection, randSize;
	ofPoint randPosition;
	int randSpeed = 0;
	float randRotation = 0.0;
	float randValue = 0.0;
	for ( int i = 0; i < numAsteroids; i++ ) {
		
		randValue = ofRandom(0.0, 1.0);
		// cout << "Random size: " << i << " " << randValue << endl;
		if ( randValue > 0.8 ) {
			randSize.x = 120;
			randSize.y = 120;
		}
		else if ( randValue > 0.5 ) {
			randSize.x = 80;
			randSize.y = 80;
		}
		else {
			randSize.x = 40;
			randSize.y = 40;
		}
		
		//randSize.x = 40;
		//randSize.y = 40;
		
		randDirection.x = ofRandom(-1, 1);
		randDirection.y = ofRandom(-1, 1);
		normalizeOfPoint(randDirection);
		randRotation = ofRandom(-0.5,0.5);
		randPosition.x = ofRandom(0, ofGetWidth());
		randPosition.y = ofRandom(0, ofGetHeight());
		randSpeed = ofRandom(200, 400);
		wlaAsteroid* newObject = new wlaAsteroid();
		newObject->setup(randSize, randSpeed, randPosition, randDirection);
		newObject->rotationSpeed = randRotation;
		//DataManager::getDataManager()->addAsteroid(newObject);
		asteroids.push_back(newObject);
	}
}


void wlaGameManager::normalizeOfPoint(ofPoint &point)
{
	float length = (float)sqrt(point.x * point.x + point.y * point.y);
	if ( length > 0 ) {
		point.x /= length;
		point.y /= length;
	}
	return;
}

// KEYS


void wlaGameManager::handleKey(int key, bool value)
{
	switch( key ){
		case OF_KEY_UP:
			// std::cout << "Thrust" << endl;
			//DataManager::getDataManager()->getShip()->controls->thrust = value;
			spaceShip->thrust = value;
			break;
		case OF_KEY_LEFT:
			//std::cout << "Turn Left" << endl;
			//DataManager::getDataManager()->getShip()->controls->turnLeft = value;
			spaceShip->turnLeft = value;
			break;
		case OF_KEY_RIGHT:
			// std::cout << "Turn Right" << endl;
			//DataManager::getDataManager()->getShip()->controls->turnRight = value;
			spaceShip->turnRight = value;
			break;
		case 'a':
			//std::cout << "Fire Ze Missiles !!!" << endl;
			//DataManager::getDataManager()->getShip()->controls->fire = value;
			spaceShip->isFiring = value;
			if ( !value ) {
				spaceShip->bulletCount = 0;
			}
			break;
		case OF_KEY_DOWN:
			/*
			 if ( !value ) {
			 trackNumber++;
			 if ( trackNumber > 1 )
			 trackNumber = 0;
			 this->key = "BGMusicMain" + ofToString(trackNumber);
			 }
			 */
			//DataManager::getDataManager()->getShip()->controls->backthrust = value;
			spaceShip->backthrust = value;
			break;
	}
}

void wlaGameManager::keyPressed(ofKeyEventArgs &arg)
{
	handleKey(arg.key, true);
}

void wlaGameManager::keyReleased(ofKeyEventArgs &arg)
{
	handleKey(arg.key, false);
}



