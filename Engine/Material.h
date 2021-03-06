// Solar Sojourn
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// Material
//      Wraps information about what shader and shader settings to use.
#pragma once

// TODO: Material settings for alpha blending, back face culling, and z buffer


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11async.h>
#include "Util.h"
#include "GraphicsManager.h"


// |----------------------------------------------------------------------------|
// |                            Forward Declarations                            |
// |----------------------------------------------------------------------------|
class Shader;


// |----------------------------------------------------------------------------|
// |                              Class: Material                               |
// |----------------------------------------------------------------------------|
class Material
{

public:

    Material() : 
        m_shader(0),
        m_renderTarget(0),
        m_glowTexture(0),
        m_renderToBackBuffer(true),
        m_reflectiveness(0.0f),
        m_tintR(1.0f),
        m_tintG(1.0f),
        m_tintB(1.0f),
        m_alpha(1.0f),
        m_glowStrength(1.0f),
        m_alphaBlend(false),
        m_particleBlend(false),
        m_backfaceCull(true),
        m_zBuffer(true),
        m_baseView(false),
        m_ortho(false),
        m_reBlur(false),
        m_texOrtho(false)
    {}

    // Getters
    Shader* GetShader() {return m_shader; }
    Texture* GetRenderTarget() {return m_renderTarget; }
    Texture* GetGlowTexture() {return m_glowTexture; }
    bool GetRenderToBackBuffer() {return m_renderToBackBuffer; }
    float GetReflectiveness() {return m_reflectiveness; }
    float GetTintR() {return m_tintR; }
    float GetTintG() {return m_tintG; }
    float GetTintB() {return m_tintB; }
    float GetAlpha() {return m_alpha; }
    float GetGlowStrength() {return m_glowStrength; }
    bool GetAlphaBlend() {return m_alphaBlend; }
    bool GetParticleBlend() {return m_particleBlend; }
    bool GetBackfaceCull() {return m_backfaceCull; }
    bool GetZBuffer() {return m_zBuffer; }
    bool GetBaseView() {return m_baseView; }
    bool GetOrtho() {return m_ortho; }
    bool GetReBlur() {return m_reBlur; }
    bool GetTexOrtho() {return m_texOrtho; }

    // Setters
    void SetShader(Shader* shader) {m_shader = shader;}
    void SetShader(std::string name) {m_shader = GraphicsManager::GetRef()->GetShader(name);}
    void SetRenderTarget(Texture* value) {m_renderTarget = value;}
    void SetGlowTexture(Texture* value) {m_glowTexture = value;}
    void SetRenderToBackBuffer(bool value) {m_renderToBackBuffer = value;}
    void SetReflectiveness(float value) {m_reflectiveness = Clamp(value,0.0f,1.0f);}
    void SetTint(float r, float g, float b, float a = 1.0f) {
        m_tintR = r;
        m_tintG = g;
        m_tintB = b;
        m_alpha = a;
    }
    void SetAlphaBlend(bool value){m_alphaBlend = value;}
    void SetGlowStrength(bool value){m_glowStrength = value;}
    void SetParticleBlend(bool value){m_particleBlend = value;}
    void SetBackfaceCull(bool value){m_backfaceCull = value;}
    void SetZBuffer(bool value){m_zBuffer = value;}
    void SetBaseView(bool value){m_baseView = value;}
    void SetOrtho(bool value){m_ortho = value;}
    void SetReBlur(bool value){m_reBlur = value;}
    void SetTexOrtho(bool value){m_texOrtho = value;}

protected:

    Shader* m_shader;
    Texture* m_renderTarget;
    Texture* m_glowTexture;
    bool m_renderToBackBuffer;
    float m_reflectiveness;
    float m_tintR, m_tintG, m_tintB;
    float m_alpha;
    float m_glowStrength;
    bool m_alphaBlend;
    bool m_particleBlend;
    bool m_backfaceCull;
    bool m_zBuffer;
    bool m_baseView;
    bool m_ortho;
    bool m_reBlur;
    bool m_texOrtho;

};