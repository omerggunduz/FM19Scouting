#include "PlayerManager.h"
#include "Player.h"
#include "Util.h"
#include <iostream>
#include <string>

PlayerManager::~PlayerManager()
{
}

std::vector<std::shared_ptr<Player>> PlayerManager::getAllPlayers()
{
	std::vector<std::shared_ptr<Player>> players;
	SYSTEM_INFO sysInfo = { 0 };
	GetSystemInfo(&sysInfo);

	DWORD_PTR startAddress = (DWORD_PTR)sysInfo.lpMinimumApplicationAddress;
	DWORD_PTR endAddress = (DWORD_PTR)sysInfo.lpMaximumApplicationAddress;

	uint64_t progressIndex = 0;
	DWORD_PTR diffAddresses = endAddress - startAddress;
	while (startAddress < endAddress)
	{
		MEMORY_BASIC_INFORMATION mbi = { 0 };
		if (VirtualQueryEx(mHandle, (LPCVOID)startAddress, &mbi, sizeof(mbi)) != 0) 
		{           
			if (mbi.State == MEM_COMMIT && ((mbi.Protect & PAGE_GUARD) == 0) && ((mbi.Protect & PAGE_NOACCESS) == 0)) 
			{
				auto dump = new unsigned char[mbi.RegionSize + 1];
				memset(dump, 0x00, mbi.RegionSize + 1);

				ReadProcessMemory(mHandle, (LPCVOID*)mbi.BaseAddress, dump, mbi.RegionSize, NULL);

				for (size_t x = 0; x < mbi.RegionSize - 4; x += 4) 
				{
					if (*(DWORD*)(dump + x) == Player::GUIDING_ID)
					{
						DWORD_PTR uniqueId;
						DWORD_PTR uniqueIdLow;
						DWORD_PTR playerUIDaddress;

						playerUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x - 0x1C);

						ReadProcessMemory(mHandle, (LPCVOID*)playerUIDaddress, &uniqueId, sizeof(DWORD_PTR), NULL);
						ReadProcessMemory(mHandle, (LPCVOID*)(playerUIDaddress + 0x4), &uniqueIdLow, sizeof(DWORD_PTR), NULL);

						if ((int)uniqueId == (int)uniqueIdLow) 
						{
							if (progressIndex % 1000 == 0)
							{
								std::cout << "\r" << "Fetching from memory: " << ((float)progressIndex / ((float)diffAddresses / 60))  * 10000.0f << std::flush;
							}

							players.emplace_back(fetchPlayerFromMemory(playerUIDaddress));
							players.back()->general.uniqueId = uniqueId;
							progressIndex++;
						}

					}
				}
				delete[] dump;
			}
			startAddress += mbi.RegionSize;
		}
	}

	return players;
}

std::unique_ptr<Player> PlayerManager::fetchPlayerFromMemory(DWORD_PTR address)
{
	auto player = std::make_unique<Player>();
	player->fetchFromMemory(address);

	return std::move(player);
}
