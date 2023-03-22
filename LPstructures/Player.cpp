#include "Player.h"
//struct Vector3 { float x, y, z; };


Player::Player(HANDLE gameProcessHandle, DWORD baseAddress)
{
	LostPlanetProcessHandle = gameProcessHandle;

	// Get the Player Address
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(baseAddress + 0x30), &playerAddress, 4, NULL);

	// point back to the world object
	

}

void
Player::setMaxHealth()
{
	// set health to 9999
	float maxHealth = 9999;
	WriteProcessMemory(LostPlanetProcessHandle, (LPVOID)(playerAddress + 0x1224), &maxHealth, 4, NULL);



	//WriteProcessMemory(LostPlanetProcessHandle, (LPVOID)(weaponsList.at(i) + 0x0030),		&playerXcoord, 4, NULL)

}

Vector3 
Player::getPlayerCoord()
{
	Vector3 playerCoord{};

	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(playerAddress + 0x30), &playerCoord.x, 4, NULL);
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(playerAddress + 0x34), &playerCoord.z, 4, NULL);
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(playerAddress + 0x38), &playerCoord.y, 4, NULL);

	return playerCoord;
}

void Player::setPlayerCoord(Vector3 newPlayerCoord)
{
	WriteProcessMemory(LostPlanetProcessHandle, (LPVOID)(playerAddress + 0x0030), &newPlayerCoord.x, 4, NULL);
	WriteProcessMemory(LostPlanetProcessHandle, (LPVOID)(playerAddress + 0x0034), &newPlayerCoord.z, 4, NULL);
	WriteProcessMemory(LostPlanetProcessHandle, (LPVOID)(playerAddress + 0x0038), &newPlayerCoord.y, 4, NULL);

	
}

void
Player::teleportToPointedObject(Vector3 objCoord)
{


	if (objCoord.x!= 0)
	{
		// set player coordinates to objCoord
		setPlayerCoord(objCoord);



		//WriteProcessMemory(LostPlanetProcessHandle, (LPVOID)(playerObj + 0x0030), &objCoord.x, 4, NULL);
		


	}



}


