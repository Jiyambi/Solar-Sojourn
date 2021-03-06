// Solar Sojourn
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// Shader
//      Abstract class for shaders. Wraps and interacts with vertex and pixel 
//      shaders.
#pragma once

// TODO: Move color-specific code to color shader
// TODO: Finish setting up color buffer
// TODO: Set color buffer on render
// TODO: Render using correct vertex buffer format
// TODO: Check over render function to be sure it's correct.

// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11async.h>
#include <fstream>
#include "Util.h"
#include "D3DManager.h"
using namespace std;


// |----------------------------------------------------------------------------|
// |                            Forward Declarations                            |
// |----------------------------------------------------------------------------|
class Graphic;


// |----------------------------------------------------------------------------|
// |                              Class: Shader                                 |
// |----------------------------------------------------------------------------|
class Shader
{

protected:

    //|-------------------------------Type Definitions--------------------------|

    virtual struct VSBufferType
    {
		D3DXVECTOR4 filler;
    };

    virtual struct PSBufferType
    {
		D3DXVECTOR4 filler;
    };

public:

    //|-------------------------------Public Functions--------------------------|
    
    // Constructors and Destructors
    Shader();
    Shader(const Shader&);
    virtual ~Shader();
    
    // Initialization and shutdown
    virtual bool Initialize(const char*, const char*, WCHAR*, WCHAR*);
    virtual void Shutdown();

    // Renders the provided matrices to the DX device
    virtual bool Render(ID3D11DeviceContext*, int, D3DXMATRIX, D3DXMATRIX, 
        D3DXMATRIX, Graphic* graphic);
    
protected:

    //|-----------------------------Protected Functions------------------------|

    // Initializes shaders
    virtual bool InitializeShader(ID3D11Device*, WCHAR*, WCHAR*);

    // Initialize input layout
    virtual bool InitializeInputLayout(ID3D11Device* device, ID3D10Blob* vertexShaderBuffer);

    // Initialize the buffers to be used with the shaders
    virtual bool InitializeVertexShaderBuffers(ID3D11Device* device);
    virtual bool InitializePixelShaderBuffers(ID3D11Device* device);
    
    // Performs shutdown, deallocation, and cleanup for shaders
    virtual void ShutdownShader();

    // Relays messages from shaders
    virtual void OutputShaderErrorMessage(ID3D10Blob*, WCHAR*);

    // Renders shader to device
    virtual void RenderShader(ID3D11DeviceContext*, int);

    // Passes information to shaders
    virtual bool SetShaderParameters(ID3D11DeviceContext* deviceContext, 
        D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix,
        Graphic* graphic);
    virtual bool SetVSBuffer(ID3D11DeviceContext* deviceContext, 
        D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix,
        Graphic* graphic) = 0;
    virtual bool SetPSBuffer(ID3D11DeviceContext* deviceContext,
        Graphic* graphic) = 0;

protected:

    //|---------------------------Protected Data Members-----------------------|

    // Shaders
    ID3D11VertexShader* m_vertexShader;
    ID3D11PixelShader* m_pixelShader;

    // Shader names
    const char* m_vertexShaderName;
    const char* m_pixelShaderName;

    // Shader files
    WCHAR* m_vertexShaderFile;
    WCHAR* m_pixelShaderFile;

    // Layout
    ID3D11InputLayout* m_layout;

    // Buffers
    ID3D11Buffer* m_vsBuffer;
    ID3D11Buffer* m_psBuffer;

};