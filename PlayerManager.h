#pragma once
#include <Windows.h>
#include <vector>
#include <memory>

class Player;

class PlayerManager
{
public:
	PlayerManager(HANDLE handle) : mHandle(handle)
	{
	}

	~PlayerManager();

	std::vector<std::shared_ptr<Player>> getAllPlayers();

private:
	std::unique_ptr<Player> fetchPlayerFromMemory(DWORD_PTR address);

private:
	HANDLE mHandle;
};

