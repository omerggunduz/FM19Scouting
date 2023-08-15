#pragma once
#include <Windows.h>
#include <string>
#include "PlayerTypes.h"

class Player
{
public:
	Player();
	~Player();

	void fetchFromMemory(DWORD_PTR address);

public:
	GeneralAttributes general;
	TechnicalAttributes technical;
	GoalKeepingAttributes goalkeeping;
	MentalAttributes mental;
	PhysicalAttributes physical;
	HiddenAttributes hidden;
	Positions positions;
	Abilities abilities;
	Personality personality;
	Contract contract;

public:
	static const int GUIDING_ID = 1177858536;
};

