#pragma once

#include <Windows.h>
#define HEALTH_OFFSET 0x1224

struct Vector3 { float x, y, z; };

class Player 
{

public:
	Player(HANDLE gameProcessHandle, DWORD baseAddress);

	void setMaxHealth();
	Vector3 getPlayerCoord();

	void setPlayerCoord(Vector3 newPlayerCoord);

	void teleportToPointedObject(Vector3 objCoord);

	HANDLE LostPlanetProcessHandle;
	DWORD playerAddress;



};