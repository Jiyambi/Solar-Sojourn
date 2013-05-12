// Solar Exploration Sim
// Developed a coursework for Abertay University
// Based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2013, all rights reserved.
//
// MouseLookCamera
//      GameObject class that mouse look, and adjusts the main camera if set to active.


// |----------------------------------------------------------------------------|
// |                                Includes                                    |
// |----------------------------------------------------------------------------|
#include "MouseLookCamera.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
MouseLookCamera::MouseLookCamera() :
    m_active(true),
    m_mouseSensitivity(10.0f),
	m_speed(100.0f),
    GameObject()
{
	DebugLog ("MouseLookCamera: object instantiated.");
}
     

// |----------------------------------------------------------------------------|
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
MouseLookCamera::MouseLookCamera(const MouseLookCamera&) {
	DebugLog ("MouseLookCamera: object copied.");
}


// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
MouseLookCamera::~MouseLookCamera() {
	DebugLog ("MouseLookCamera: object destroyed.");
}


// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool MouseLookCamera::Initialize() {
    GameObject::Initialize();
	DebugLog ("MouseLookCamera: object initialized.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool MouseLookCamera::Shutdown() {
    GameObject::Shutdown();
	DebugLog ("MouseLookCamera: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							     Logic()									|
// |----------------------------------------------------------------------------|
bool MouseLookCamera::Logic() {
	DebugLog ("MouseLookCamera: Logic() called.", DB_LOGIC, 10);

    // Get time for this frame
    float time = TimerManager::GetRef()->GetTime() / 1000;

    // Exit if the camera is not active
    if (!m_active) return true;

    // Get mouse input for orientation
    int mouseX, mouseY;
    InputManager::GetRef()->GetMouseChange(mouseX, mouseY);
    m_orientation.x += m_mouseSensitivity * mouseY * time;
    m_orientation.y += m_mouseSensitivity * mouseX * time;

    // Clamp x orientation to -90 to 90 range
    if(m_orientation.x > 90)
        m_orientation.x = 90;
    if(m_orientation.x < -90)
        m_orientation.x = -90;
    // Cycle y orientation within 0 to 360 range
    if(m_orientation.y > 360)
        m_orientation.y -=360;
    if(m_orientation.y < 0)
        m_orientation.y += 360;
	
    // Get keyboard input for movement
	int forward(0), right(0), up(0);
	if(InputManager::GetRef()->GetButtonDown(BUTTON_FORWARD))
		forward = 1;
	else if(InputManager::GetRef()->GetButtonDown(BUTTON_BACKWARD))
		forward = -1;
	if(InputManager::GetRef()->GetButtonDown(BUTTON_STRAFE_RIGHT))
		right = 1;
	else if(InputManager::GetRef()->GetButtonDown(BUTTON_STRAFE_LEFT))
		right = -1;
	if(InputManager::GetRef()->GetButtonDown(BUTTON_ASCEND))
		up = 1;
	else if(InputManager::GetRef()->GetButtonDown(BUTTON_DESCEND))
		up = -1;
	
    Coord vel = Coord(
		forward * sin(m_orientation.y * PI / 180) 
            + right * sin(PI / 2 + m_orientation.y * PI / 180),
		forward * -1 * sin(m_orientation.x * PI / 180)
            + up,
		forward * cos(m_orientation.y * PI / 180) * cos(m_orientation.x * PI / 180)
            + right * cos(PI / 2 + m_orientation.y * PI / 180) );
    vel *= m_speed * time;
	m_linearVelocity = vel;
	m_position += m_linearVelocity; 

    // Set camera position and orientation
    Camera* camera = GraphicsManager::GetRef()->GetCamera();
    camera->SetOrientation(m_orientation);
    camera->SetPosition(m_position);

	return true;
}


// |----------------------------------------------------------------------------|
// |							     Draw()										|
// |----------------------------------------------------------------------------|
bool MouseLookCamera::Draw() {
	DebugLog ("MouseLookCamera: Draw() called.", DB_GRAPHICS, 10);

    // Call parent draw
    GameObject::Draw();

	return true;
}

