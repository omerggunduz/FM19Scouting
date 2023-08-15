#pragma once

#include <string>

struct GeneralAttributes
{
	int rowId;
	int uniqueId;
	std::string firstName;
	std::string lastName;
	std::string nationality;
	short birthYear;
	short ethnicity;
	short hairColour;
	short hairLength;
	short skinTone;
	short height;
	short weight;
	short morale;
	short declaredForNation;
	short internationalAppearances;
	short internationalGoals;
	short generalOptions;
	short bans;
	short injuries;
};

struct TechnicalAttributes
{
	short corners;
	short crossing;
	short dribbling;
	short finishing;
	short firstTouch;
	short freeKickTaking;
	short heading;
	short longShots;
	short longThrows;
	short marking;
	short passing;
	short penaltyTaking;
	short tackling;
	short technique;
};

struct GoalKeepingAttributes
{
	short aerialReach;
	short commandOfArea;
	short communication;
	short eccentricity;
	short handling;
	short kicking;
	short oneOnOnes;
	short reflexes;
	short rushingOut;
	short tendencyToPunch;
	short throwing;
};

struct MentalAttributes
{
	short aggression;
	short anticipation;
	short bravery;
	short composure;
	short concentration;
	short decision;
	short determination;
	short flair;
	short leadership;
	short offTheBall;
	short positioning;
	short teamwork;
	short vision;
	short workRate;
};

struct PhysicalAttributes
{
	short acceleration;
	short agility;
	short balance;
	short jumpingReach;
	short naturalFitness;
	short pace;
	short stamina;
	short strength;
};

struct HiddenAttributes
{
	short dirtiness;
	short consistency;
	short impMatches;
	short injuryProneness;
	short versatility;
};

struct Positions
{
	short roleUsedToFillEmptyAttributes;
	short preferredCentralPosition;
	short goalkeeper;
	short sweeper;
	short defenseLeft;
	short defenseCenter;
	short defenseRight;
	short wingBackLeft;
	short wingBackRight;
	short defensiveMidfielder;
	short midfielderLeft;
	short midfielderCenter;
	short midfielderRight;
	short attackingMidfielderLeft;
	short attackingMidfielderCenter;
	short attackingMidfielderRight;
	short striker;
};

struct Abilities
{
	short currentAbility;
	short potentialAbility;
	short leftFoot;
	short rightFoot;
	short matchSharpness;
	short matchExercise;
};

struct Personality 
{
	short adaptability;
	short ambition;
	short controversy;
	short loyalty;
	short pressure;
	short professionalism;
	short sportmanship;
	short temperament;

};

struct Contract 
{
	int clubUniqueID;
	std::string clubName;
	short type;
	short jobType;
	int value;
	int askingPrice;
	int weeklyWage;
	short startDayOfYear;
	short startYear;
	short endDayOfYear;
	short endYear;
	short joinDayOfYear;
	short joinYear;
	int loyaltyBonus;
	short squadStatus;
	short squadNumber;
};