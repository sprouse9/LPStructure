#pragma once
#include <Windows.h>
#include "World.h"
#include "Camera.h"


class LPBase
{
public:
	LPBase();

	World* world;
	Camera* camera;

	DWORD GetModuleBaseAddress(LPCWSTR lpszModuleName, DWORD pID);

	HWND hGameWindow;

	DWORD gameBaseAddress = NULL;
	DWORD LostPlanetColoniesDX9_928318 = NULL;
	DWORD pLostPlanetProcessID = NULL;
	HANDLE LostPlanetProcessHandle = NULL;
	BOOL foundGame = TRUE;
	
};