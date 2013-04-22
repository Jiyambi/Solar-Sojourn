// Solar Exploration Sim
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// Image
//      Contains data for a single 2D image, including texture and rendering method.
#pragma once


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include "Graphic.h"
#include "Quad.h"

// |----------------------------------------------------------------------------|
// |                              Class: Graphic                                |
// |----------------------------------------------------------------------------|
class Image : public Graphic
{

public:

    //|-------------------------------Public Functions--------------------------|
    
    // Constructors and Destructors
    Image();
    Image(const Image&);
    virtual ~Image();
    
    // Initialization and shutdown
    virtual bool Initialize();
    virtual void Shutdown();

    // Renders the graphic to the supplied context
    virtual void Render();

protected:

    //|----------------------------Protected Data Members-----------------------|

	// Model and texture data members
	// Change these to a model? (quad)
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

};