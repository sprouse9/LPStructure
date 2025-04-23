# Lost Planet Weapons Audit & Teleport Tool

This C++ project is a reverse engineering utility designed for the game **Lost Planet Colonies Ver 1.0.1.0 for DirectX 9**. The tool connects to the game process, reads and writes memory, and provides debugging functions such as player teleportation to in-world objects.

## 🧠 Features

- Locates and attaches to the Lost Planet Colonies DX9 game window
- Accesses game memory using Windows API calls (`ReadProcessMemory`, `WriteProcessMemory`)
- Traverses in-game object structures using known base addresses and offsets
- Implements basic vector math to work with 3D world coordinates
- Teleports the player to the object currently targeted by the in-game camera
- Demonstrates use of custom C++ classes for game world abstraction (`LPBase`, `World`, `Player`, `Camera`)

## 🧱 Structure

- `LPBase.cpp/h`: Entry point and wrapper for world and camera structures
- `World.cpp/h`: Represents the world object and retrieves the player
- `Player.cpp/h`: Provides access to player health, coordinates, and teleport functions
- `Camera.cpp/h`: Used to retrieve the coordinates of pointed objects
- `LostPlanet Weapons Audit.cpp`: Main program logic and process attachment

## 🛠️ Technologies

- C++ (Visual Studio project)
- Windows API (`FindWindow`, `OpenProcess`, `CreateToolhelp32Snapshot`, etc.)
- x64 debugging tools: `x64dbg`, `IDA Pro`
- Manual memory inspection and manipulation
- Reverse-engineered in-game addresses and offsets

## 🚀 How It Works

1. Attempts to find the game window with title:  
   `"Lost Planet Colonies Ver 1.0.1.0 for Dx9"`
2. Retrieves the base address of the `LostPlanetColoniesDX9.exe` module.
3. Reads memory from known offsets to find player and camera data.
4. Allows teleporting the player to the object being aimed at by the camera.
5. Includes placeholder functionality for health editing and future extensions.

## ⚠️ Legal Disclaimer

This tool is intended for **educational and research purposes only**. Modifying game memory may violate software terms of service and can result in bans or other penalties in multiplayer or commercial settings. Use responsibly and only with games you own.

## 📁 Example Use Cases

- Debugging level geometry
- Exploring internal game mechanics
- Creating single-player mods or automation tools
- Learning how memory manipulation works at a systems level

## 📌 Requirements

- Windows OS
- Lost Planet Colonies DX9 (Version 1.0.1.0)
- Visual Studio (or any C++11-compatible compiler)
- Administrative privileges to access process memory

## 📄 License

No restrictions.
