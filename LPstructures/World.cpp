#include "World.h"

World::World(HANDLE LostPlanetProcessHandle, DWORD baseAddress)
{
	// Get the World Address
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(baseAddress + 0xBC), &worldAddress, 4, NULL);

	player = new Player(LostPlanetProcessHandle, worldAddress);

}

Vector3 World::test()
{
	return Vector3();
}
