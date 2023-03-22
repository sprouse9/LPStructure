#include "Camera.h"

Camera::Camera(HANDLE gameProcessHandle, DWORD baseAddress)
{
	LostPlanetProcessHandle = gameProcessHandle;

	// Get the Camera Address
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(baseAddress + 0xC0 + 0x2C), &cameraAddress, 4, NULL);
		
}

Vector3 
Camera::getObjectCoord()
{

	DWORD objectAddress;
	Vector3 objCoord{};

	// Get the Object Coordinates only if a valid address is in
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(cameraAddress + 0x0394), &objectAddress, 4, NULL);

	if (objectAddress != 0x00000000)
	{
		// we are pointing at a valid object, get its coordinates
		ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(objectAddress + 0x0030), &objCoord.x, 4, NULL);
		ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(objectAddress + 0x0034), &objCoord.z, 4, NULL);
		ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(objectAddress + 0x0038), &objCoord.y, 4, NULL);

		
	}

	return objCoord;
}


