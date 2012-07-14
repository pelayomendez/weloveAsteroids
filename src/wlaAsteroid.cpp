/*
 *  wlaAsteroid.cpp
 *  weloveAsteroids
 *
 *  Created by Pelayo M. on 07/04/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "wlaAsteroid.h"

wlaAsteroid::wlaAsteroid(void)
{
	angle = PI / 2;
	checkAndSetIsBreakable();
	
	int forma = round(ofRandom(3));
	
	// Asteroide forma 1:
	if(forma == 0) {
	vertices.push_back(ofPoint(20,0));
	vertices.push_back(ofPoint(80,0));
	vertices.push_back(ofPoint(100,20));
	vertices.push_back(ofPoint(100,50));
	vertices.push_back(ofPoint(60,100));
	vertices.push_back(ofPoint(40,100));
	vertices.push_back(ofPoint(50,70));
	vertices.push_back(ofPoint(25,90));
	vertices.push_back(ofPoint(0,70));
	vertices.push_back(ofPoint(20,40));
	vertices.push_back(ofPoint(0,20));
	vertices.push_back(ofPoint(20,0));
	for (int i = 0 ; i < vertices.size() ; i++)
		ofVec2f(vertices[i].x,vertices[i].y);
	}	
		
	// Asteroide forma 2:
	if(forma == 1) {
	vertices.push_back(ofPoint(20,0));
	vertices.push_back(ofPoint(50,0));
	vertices.push_back(ofPoint(100,20));
	vertices.push_back(ofPoint(100,30));
	vertices.push_back(ofPoint(50,50));
	vertices.push_back(ofPoint(100,60));
	vertices.push_back(ofPoint(75,100));
	vertices.push_back(ofPoint(50,80));
	vertices.push_back(ofPoint(20,100));
	vertices.push_back(ofPoint(0,60));
	vertices.push_back(ofPoint(0,30));
	vertices.push_back(ofPoint(20,0));
	for (int i = 0 ; i < vertices.size() ; i++)
		ofVec2f(vertices[i].x,vertices[i].y);
	}
	
	if(forma == 2) {
		vertices.push_back(ofPoint(25,0));
		vertices.push_back(ofPoint(50,10));
		vertices.push_back(ofPoint(75,0));
		vertices.push_back(ofPoint(100,20));
		vertices.push_back(ofPoint(70,45));
		vertices.push_back(ofPoint(100,60));
		vertices.push_back(ofPoint(65,100));
		vertices.push_back(ofPoint(30,90));
		vertices.push_back(ofPoint(20,100));
		vertices.push_back(ofPoint(0,75));
		vertices.push_back(ofPoint(10,50));
		vertices.push_back(ofPoint(0,20));
		vertices.push_back(ofPoint(25,0));
		for (int i = 0 ; i < vertices.size() ; i++)
			ofVec2f(vertices[i].x,vertices[i].y);
	}
	
	if(forma == 3) {
		vertices.push_back(ofPoint(30,0));
		vertices.push_back(ofPoint(50,20));
		vertices.push_back(ofPoint(75,0));
		vertices.push_back(ofPoint(100,20));
		vertices.push_back(ofPoint(80,50));
		vertices.push_back(ofPoint(100,70));
		vertices.push_back(ofPoint(75,100));
		vertices.push_back(ofPoint(30,100));
		vertices.push_back(ofPoint(0,70));
		vertices.push_back(ofPoint(0,20));
		vertices.push_back(ofPoint(30,0));
		for (int i = 0 ; i < vertices.size() ; i++)
			ofVec2f(vertices[i].x,vertices[i].y);
	}

	
}

wlaAsteroid::~wlaAsteroid(void)
{
}

void wlaAsteroid::setup(ofPoint _size, float _speed, ofPoint _position, ofPoint _direction)
{
	size = _size;
	speed = _speed;
	position = _position;
	direction = _direction;
}

void wlaAsteroid::update(float deltaTime)
{
	addRotation(rotationSpeed/100);
	position += direction * speed * deltaTime;
	checkBounds();
}

void wlaAsteroid::draw() const
{
	
	ofPolyline p;
	p.addVertexes(vertices);
	ofPushMatrix();
	//ofBeginShape();
	glTranslatef(position.x, position.y, 0);
	glRotatef(angle / PI * 180, 0,0,1);

	
	//ofCircle(position.x, position.y, size.x);
	//ofNoFill();
	//ofCircle(0, 0, size.x);
	//ofFill();
	//ofRect(0, 0, 1, 1);
	
	
	ofScale(size.x/60,size.y/60,0);
	glTranslatef(-50, -50, 0);
	
	p.draw();
	//ofEndShape(true);
	ofPopMatrix();
}

void wlaAsteroid::checkAndSetIsBreakable()
{
	if ( size.x > 20 && size.y > 20 )
		isBreakable = true;
	else
		isBreakable = false;
}
