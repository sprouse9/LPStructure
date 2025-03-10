#pragma once
#include <Windows.h>
#include "Player.h"



class World
{
public:
	DWORD worldAddress = NULL;
	Player* player;

	World(HANDLE LostPlanetProcessHandle, DWORD baseAddress);
	Vector3 test();
};