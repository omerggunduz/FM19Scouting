#pragma once
#include <Windows.h>
#include <string>

struct CurrentMemory
{
	DWORD_PTR currentAddress;
	DWORD_PTR currentValue;
};

class Util
{
public:
	Util();
	~Util();

	static HANDLE LoadGame();
	static std::string getString32(DWORD_PTR playerBaseAddress, int offset, const std::initializer_list<DWORD_PTR> &offsets);
	static std::string getString64(DWORD_PTR playerBaseAddress, int offset, const std::initializer_list<DWORD_PTR> &offsets);

	template<typename T>
	static T readValueFromMemoryDMA(DWORD_PTR playerBaseAddress, int offset, const std::initializer_list<DWORD_PTR> &offsets)
	{
		CurrentMemory memory = FindDmaAddy((playerBaseAddress + offset - 0x1CC), (DWORD_PTR*)offsets.begin(), offsets.size());
		return (T)memory.currentValue;
	}

	template<typename T>
	static T readValueFromMemory(DWORD_PTR address, int offset)
	{
		T value;
		ReadProcessMemory(mHandle, (LPVOID)(address + offset - 0x1CC), &value, sizeof(T), NULL);
		return value;
	}
private:
	static CurrentMemory FindDmaAddy(DWORD_PTR BaseAddress, DWORD_PTR offsets[], int PointerLevel);
	template<int Size>
	static std::string readBuffer(DWORD64 address);
	
private:
	static HANDLE mHandle;
};

