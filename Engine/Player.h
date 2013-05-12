// Solar Exploration Sim
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// Player
//      Managers graphics and functionality for the player ship
#pragma once


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "GameObject.h"
#include "ParticleSystem.h"
#include "Billboard.h"
#include "Camera.h"


// |----------------------------------------------------------------------------|
// |                         Class Definition: Player		                    |
// |----------------------------------------------------------------------------|
class Player : public GameObject {

public:
    
    //|-------------------------------Public Functions--------------------------|
    
	// Constructors and Destructors
	Player();
	Player(const Player&);
	virtual ~Player();

    // Initialization and shutdown
	virtual bool  Initialize();
	virtual bool  Shutdown();
    
    // Performs logic functions for the object
    virtual bool  Logic();
    
    // Renders camera
    bool virtual Draw();
	
    // Setter functions
    void virtual SetPosition(Coord position);
    void virtual SetOrientation(Coord orientation);

protected:
   
    //|----------------------------Protected Functions-------------------------|


protected:
    
    //|---------------------------Protected Data Members-----------------------|
	GameObject* m_ship;
	ParticleSystem* m_leftThruster;
	ParticleSystem* m_rightThruster;

	// Player parameters
	Coord m_direction;
	float m_speed;
};