// Solar Exploration Sim
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// Text
//      Contains data for a single text object, including texture and rendering 
//		method.
#pragma once


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include "Graphic.h"
#include "Sentence.h"
#include "Font.h"


// |----------------------------------------------------------------------------|
// |                               Class: Text			                        |
// |----------------------------------------------------------------------------|
class Text : public Graphic
{

public:

    //|-------------------------------Public Functions--------------------------|
    
    // Constructors and Destructors
    Text();
    Text(const Text&);
    virtual ~Text();
    
    // Initialization and shutdown
    virtual bool Initialize();
    virtual void Shutdown();

    // Renders the graphic to the supplied context
    virtual void Render();

	// Getter and Setter functions
	char* GetText();
	void SetText(char*); // Rebuilds the buffer from Font.
	void SetColor(float r, float g, float b);

protected:

    //|------------------------------Protected Functions------------------------|

protected:

    //|----------------------------Protected Data Members-----------------------|

	// Screen location information
	Coord m_previousPosition;

	// String to be rendered
	char* m_string;

};