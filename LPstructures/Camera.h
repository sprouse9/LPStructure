#pragma once
#ifndef Camera_h
	#define Camera_h
	#include <Windows.h>
#endif // !Camera_h

#include "Player.h"




//struct Vector3 { float x, y, z; };


class Camera
{
public:
	DWORD cameraAddress = NULL;

	HANDLE LostPlanetProcessHandle;

	Camera(HANDLE LostPlanetProcessHandle, DWORD baseAddress);

	Vector3 getObjectCoord();	// the object we are pointing to (could be nothing)

};

