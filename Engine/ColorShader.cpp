// Solar Exploration Sim
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// ColorShader
//      Wraps and interacts with vertex and pixel shader.


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include "ColorShader.h"
#include "Graphic.h"


// |----------------------------------------------------------------------------|
// |                           Default Constructor                              |
// |----------------------------------------------------------------------------|
bool ColorShader::Initialize()
{
    // Set up the shader files
    return Shader::Initialize("ColorVertexShader", "ColorPixelShader", L"../Engine/color.vs", L"../Engine/color.ps");
}


// |----------------------------------------------------------------------------|
// |                               SetVSBuffer                                  |
// |----------------------------------------------------------------------------|
bool ColorShader::SetVSBuffer(ID3D11DeviceContext* deviceContext, 
        D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, 
        D3DXMATRIX projectionMatrix, Graphic* graphic)
{
	DebugLog ("ColorShader::SetVSBuffer() called.", DB_GRAPHICS, 10);
    HRESULT result;
    D3D11_MAPPED_SUBRESOURCE mappedResource;
    unsigned int bufferNumber;
    VSBufferType* t_vsbuffer;

    // Transpose the matrices to prepare them for the shader.
    D3DXMatrixTranspose(&worldMatrix, &worldMatrix);
    D3DXMatrixTranspose(&viewMatrix, &viewMatrix);
    D3DXMatrixTranspose(&projectionMatrix, &projectionMatrix);

    // Lock the matrix constant buffer so it can be written to.
    result = deviceContext->Map(m_vsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
    if(FAILED(result))
    {
        return false;
    }

    // Get a pointer to the data in the constant buffer.
    t_vsbuffer = (VSBufferType*)mappedResource.pData;

    // Copy the matrices into the constant buffer.
    t_vsbuffer->world = worldMatrix;
    t_vsbuffer->view = viewMatrix;
    t_vsbuffer->projection = projectionMatrix;

    // Unlock the constant buffer.
    deviceContext->Unmap(m_vsBuffer, 0);

    // Set the position of the constant buffer in the vertex shader.
    bufferNumber = 0;

    // Now set the constant buffer in the vertex shader with the updated values.
    deviceContext->VSSetConstantBuffers(bufferNumber, 1, &m_vsBuffer);

    return true;
}

// |----------------------------------------------------------------------------|
// |                               SetPSBuffer                                  |
// |----------------------------------------------------------------------------|
bool ColorShader::SetPSBuffer(ID3D11DeviceContext* deviceContext,
        Graphic* graphic)
{
	DebugLog ("ColorShader::SetPSBuffer() called.", DB_GRAPHICS, 10);
    HRESULT result;
    D3D11_MAPPED_SUBRESOURCE mappedResource;
    unsigned int bufferNumber;
    PSBufferType* t_psbuffer;

    // Lock the light constant buffer so it can be written to.
	result = deviceContext->Map(m_psBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if(FAILED(result))
	{
		return false;
	}

	// Get a pointer to the data in the constant buffer.
	t_psbuffer = (PSBufferType*)mappedResource.pData;

	// Copy the color into the constant buffer.
    t_psbuffer->color = D3DXVECTOR4(graphic->GetTintR(), graphic->GetTintG(), graphic->GetTintB(), graphic->GetAlpha());
    
	// Unlock the constant buffer.
	deviceContext->Unmap(m_psBuffer, 0);

	// Set the position of the light constant buffer in the pixel shader.
	bufferNumber = 0;

	// Finally set the light constant buffer in the pixel shader with the updated values.
	deviceContext->PSSetConstantBuffers(bufferNumber, 1, &m_psBuffer);

    return true;
}