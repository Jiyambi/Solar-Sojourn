// Solar Sojourn
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// Screen
//      Abstract class for screens. Contains game objects, executes their game
//      logic.
#pragma once


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include "Util.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: Screen							|
// |----------------------------------------------------------------------------|
class Screen {

public:
    
    //|-------------------------------Public Functions--------------------------|

	// Constructors and Destructors
    Screen() : m_done(0), m_nextScreen(SCREEN_QUIT) {}
    Screen(const Screen&) {}
    ~Screen() {}

    // Initialization and shutdown
	bool virtual Initialize() {return true;}
	bool virtual Shutdown() {return true;}
    
	// The logic function, which will be called by the main game loop.
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual Logic() = 0;
    
	// The draw function, which will be called by the main game loop.
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual Draw() = 0;
    
	// Called when the screen is loaded.
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual OnLoad() = 0;
    
	// Called when switching to a different screen
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual OnExit() = 0;
    
	// Returns whether the screen is done (ready to close) or not.
	bool virtual IsDone() { return m_done; }
    
	// Tells the game class what screen to load after this one
	SCREEN virtual GetNextScreen()  { return m_nextScreen; }
    
	// Sets the screen that will be loaded after this one
	void virtual SetNextScreen(SCREEN new_next) { m_nextScreen= new_next; }
    
	// Sets whether the screen will quit or not
	void virtual SetDone(bool new_done) { m_done = new_done; }
	
protected:
    
    //|----------------------------Protected Data Members-----------------------|

	bool m_done;
	SCREEN m_nextScreen;

};