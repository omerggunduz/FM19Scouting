#include "Util.h"
#include <iostream>

HANDLE Util::mHandle = 0;

Util::Util()
{
}


Util::~Util()
{
}

HANDLE Util::LoadGame()
{
	const std::string windowName = "Football Manager 2019";

	DWORD procID;
	HWND hwnd = FindWindowA(NULL, windowName.c_str());
	if (hwnd == NULL) 
	{
		std::cerr << "You should launch the game before launching FM19 Scouting program." << std::endl;
		getchar();
		exit(-1);
	}

	GetWindowThreadProcessId(hwnd, &procID);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, false, procID);
	if ((procID == NULL) || handle == NULL)
	{
		std::cerr << "Cannot obtain the process! Make sure that you have admin privileges" << std::endl;
		getchar();
		exit(-1);
	}

	mHandle = handle;
	return handle;
}

std::string Util::getString32(DWORD_PTR playerBaseAddress, int offset, const std::initializer_list<DWORD_PTR> &offsets)
{
	CurrentMemory memory = FindDmaAddy((playerBaseAddress + offset), (DWORD_PTR*)offsets.begin(), offsets.size());
	return readBuffer<32>(memory.currentAddress);
}

std::string Util::getString64(DWORD_PTR playerBaseAddress, int offset, const std::initializer_list<DWORD_PTR> &offsets)
{
	CurrentMemory memory = FindDmaAddy((playerBaseAddress + offset - 0x1CC), (DWORD_PTR*)offsets.begin(), offsets.size());
	return readBuffer<64>(memory.currentAddress);
}

CurrentMemory Util::FindDmaAddy(DWORD_PTR BaseAddress, DWORD_PTR offsets[], int PointerLevel)
{
	DWORD_PTR pointer = BaseAddress;
	DWORD_PTR pTemp;
	DWORD_PTR pointerAddr;
	CurrentMemory currentMemory;
	for (int c = 0; c < PointerLevel; c++)
	{
		if (c == 0)
		{
			ReadProcessMemory(mHandle, (LPCVOID)pointer, &pTemp, sizeof(pTemp), NULL);
		}

		pointerAddr = pTemp + offsets[c];
		ReadProcessMemory(mHandle, (LPCVOID)pointerAddr, &pTemp, sizeof(pTemp), NULL);
	}
	currentMemory.currentAddress = pointerAddr;
	currentMemory.currentValue = pTemp;
	return currentMemory;
}

template<int Size>
std::string Util::readBuffer(DWORD64 address) {
	char buffer[Size] = { 0 };
	ReadProcessMemory(mHandle, (LPVOID)address, buffer, Size, NULL);
	return std::string(buffer);
}
