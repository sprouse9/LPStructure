#include "LPBase.h"
#include <tchar.h>
#include <exception>
#include <TlHelp32.h>
#include <iostream>

using namespace std;


LPBase::LPBase()
{

	// Get the base address of LostPlanetColoniesDX9_928318
	hGameWindow = FindWindow(NULL, _T("Lost Planet Colonies Ver 1.0.1.0 for Dx9"));
	if (hGameWindow == NULL)
	{
		foundGame = FALSE;
		throw exception();
	}


	if (GetWindowThreadProcessId(hGameWindow, &pLostPlanetProcessID) > 0) {
		//MessageBox(NULL, _T("FOUND!"), _T("Lost Planet Trainer DX9"), NULL);

		LostPlanetProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pLostPlanetProcessID);

		if (LostPlanetProcessHandle != INVALID_HANDLE_VALUE && LostPlanetProcessHandle != NULL)
			gameBaseAddress = GetModuleBaseAddress(_T("LostPlanetColoniesDX9.exe"), pLostPlanetProcessID);
		else
			throw exception();
	}

	// At this point the game was found
	// Get value of: LostPlanetColoniesDX9.exe + 928318;
	ReadProcessMemory(LostPlanetProcessHandle, (LPCVOID)(gameBaseAddress + 0x928318), &LostPlanetColoniesDX9_928318, 4, NULL);

	// Now that we have the base address, create a World object
	world = new World(LostPlanetProcessHandle, LostPlanetColoniesDX9_928318);

	// Create the camera object
	camera = new Camera(LostPlanetProcessHandle, LostPlanetColoniesDX9_928318);

	//cout << "WORLD OBJECT: " << &world << endl << endl << endl;



}

DWORD LPBase::GetModuleBaseAddress(LPCWSTR lpszModuleName, DWORD pID)
{
	DWORD dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
	MODULEENTRY32 ModuleEntry32 = { 0 };
	ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

	/*	TCHAR typedef explained:
			TCHAR --> WCHAR
			WCHAR --> wchar_t

			_tcscmp(const wchar_t*, const wchar_t*);
	*/

	if (Module32First(hSnapshot, &ModuleEntry32)) {
		do {

			if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) {

				dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
				break;
			}

		} while (Module32Next(hSnapshot, &ModuleEntry32));
	}

	CloseHandle(hSnapshot);

	return dwModuleBaseAddress;
}

