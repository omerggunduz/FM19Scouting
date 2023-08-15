#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Util.h"
#include "PlayerManager.h"
#include "Player.h"

static const std::vector<std::string> columnNames = {
	// general - 19
	"rowId", "uniqueId", "firstname", "lastname", "nationality", "birthYear",
	"ethnicity", "hairColour", "hairLength", "skinTone", "height", "weight", "morale",
	"declaredForNation", "internationalAppearances", "internationalGoals", "generalOptions", "bans", "injuries",

	// positions - 17
	"roleUsedToFillEmptyAttributes", "preferredCentralPosition", "goalkeeper(GK)", "sweeper(SW)", "leftBack(DL)", 
	"centerBack(DC)", "rightBack(DR)", "wingBackLeft(WBL)", "wingBackRight(WBR)", "defensiveMidfielder(DM)", 
	"leftMidfielder(ML)", "centerMidfielder(MC)", "rightMidfielder(MC)", "attackingMidfielderRight(AML)",
	"attackingMidfielderCenter(AMC)", "attackingMidfielderRight(AMR)", "striker(ST)",

	// mental - 14
	"aggression", "anticipation", "bravery", "composure", "concentration", "decision", "determination", "flair", 
	"leadership", "offTheBall", "positioning", "teamwork", "vision", "workRate",

	// physical - 8
	"acceleration", "agility", "balance", "jumpingReach", "naturalFitness", "pace", "stamina", "strength",

	// hidden - 5
	"dirtiness", "consistency", "impMatches", "injuryProneness", "versatility",

	// personality - 8
	"adaptability", "ambition", "controvery", "loyalty", "pressure", "professionalism", "sportmanship", "temperament",

	// technical - 14
	"corners", "crossing", "dribbling", "finishing", "firstTouch", "freekickTaking", "heading", "longShots", "longThrows",
	"marking", "passing", "penaltyTaking", "tackling", "technique",

	// goalkeeping - 11
	"aerialReach", "commandOfArea", "communication", "eccentricity",  "handling", "kicking", "oneOnOnes", "reflexes", "rushingOut",
	"tendencyToPunch", "throwing",

	// abilities - 6
	"currentAbility", "potentialAbility", "leftFoot", "rightFoot", "matchSharpness", "matchExercise",

	// contract - 16
	"clubUniqueID", "clubName", "type", "jobType", "value", "askingPrice", "weeklyWage", 
	"startDayOfYear", "startYear", "endDayOfYear", "endYear",
	"joinDayOfYear", "joinYear", "loyaltyBonus", "squadStatus" ,"squadNumber"
};

void exportCsv(std::string name, const std::vector<std::shared_ptr<Player>> &players);

int main() 
{
	SetConsoleTitle("FM19 Scouting - Zirkt");
	
	HANDLE handle = Util::LoadGame();

	auto playerMgr = std::make_unique<PlayerManager>(handle);
	auto players = playerMgr->getAllPlayers();

	std::cout << "\nExporting started!" << std::endl;

	exportCsv("test", players);

	CloseHandle(handle);
	std::cout << "Done!" << std::endl;
	system("pause");
	return 0;

}

void exportCsv(std::string name, const std::vector<std::shared_ptr<Player>> &players)
{
	std::ofstream out;
	out.open(name + ".csv");

	// write headers
	for (std::string columnName : columnNames)
	{
		if (columnName != "squadNumber")
		{
			out << columnName << ",";
		}
		else
		{
			out << columnName << "\n";
		}
	}

	for (int i = 0; i < players.size(); i++)
	{
		if (i % 1000 == 0)
		{
			std::cout << "\r" << "Exporting... (" << (float)i / (float)players.size() * 100.0f << ")" << std::flush;
		}

		auto p = players[i];

		out << p->general.rowId << ","
			<< p->general.uniqueId << ","
			<< p->general.firstName << ","
			<< p->general.lastName << ","
			<< p->general.nationality << ","
			<< p->general.birthYear << ","
			<< p->general.ethnicity << ","
			<< p->general.hairColour << ","
			<< p->general.hairLength << ","
			<< p->general.skinTone << ","
			<< p->general.height << ","
			<< p->general.weight << ","
			<< p->general.morale << ","
			<< p->general.declaredForNation << ","
			<< p->general.internationalAppearances << ","
			<< p->general.internationalGoals << ","
			<< p->general.generalOptions << ","
			<< p->general.bans << ","
			<< p->general.injuries << ","
			<< p->positions.roleUsedToFillEmptyAttributes << ","
			<< p->positions.preferredCentralPosition << ","
			<< p->positions.goalkeeper << ","
			<< p->positions.sweeper << ","
			<< p->positions.defenseLeft << ","
			<< p->positions.defenseCenter << ","
			<< p->positions.defenseRight << ","
			<< p->positions.wingBackLeft << ","
			<< p->positions.wingBackRight << ","
			<< p->positions.defensiveMidfielder << ","
			<< p->positions.midfielderLeft << ","
			<< p->positions.midfielderCenter << ","
			<< p->positions.midfielderRight << ","
			<< p->positions.attackingMidfielderLeft << ","
			<< p->positions.attackingMidfielderCenter << ","
			<< p->positions.attackingMidfielderRight << ","
			<< p->positions.striker << ","
			<< p->mental.aggression << ","
			<< p->mental.anticipation << ","
			<< p->mental.bravery << ","
			<< p->mental.composure << ","
			<< p->mental.concentration << ","
			<< p->mental.decision << ","
			<< p->mental.determination << ","
			<< p->mental.flair << ","
			<< p->mental.leadership << ","
			<< p->mental.offTheBall << ","
			<< p->mental.positioning << ","
			<< p->mental.teamwork << ","
			<< p->mental.vision << ","
			<< p->mental.workRate << ","
			<< p->physical.acceleration << ","
			<< p->physical.agility << ","
			<< p->physical.balance << ","
			<< p->physical.jumpingReach << ","
			<< p->physical.naturalFitness << ","
			<< p->physical.pace << ","
			<< p->physical.stamina << ","
			<< p->physical.strength << ","
			<< p->hidden.dirtiness << ","
			<< p->hidden.consistency << ","
			<< p->hidden.impMatches << ","
			<< p->hidden.injuryProneness << ","
			<< p->hidden.versatility << ","
			<< p->personality.adaptability << ","
			<< p->personality.ambition << ","
			<< p->personality.controversy << ","
			<< p->personality.loyalty << ","
			<< p->personality.pressure << ","
			<< p->personality.professionalism << ","
			<< p->personality.sportmanship << ","
			<< p->personality.temperament << ","
			<< p->technical.corners << ","
			<< p->technical.crossing << ","
			<< p->technical.dribbling << ","
			<< p->technical.finishing << ","
			<< p->technical.firstTouch << ","
			<< p->technical.freeKickTaking << ","
			<< p->technical.heading << ","
			<< p->technical.longShots << ","
			<< p->technical.longThrows << ","
			<< p->technical.marking << ","
			<< p->technical.passing << ","
			<< p->technical.penaltyTaking << ","
			<< p->technical.tackling << ","
			<< p->technical.technique << ","
			<< p->goalkeeping.aerialReach << ","
			<< p->goalkeeping.commandOfArea << ","
			<< p->goalkeeping.communication << ","
			<< p->goalkeeping.eccentricity << ","
			<< p->goalkeeping.handling << ","
			<< p->goalkeeping.kicking << ","
			<< p->goalkeeping.oneOnOnes << ","
			<< p->goalkeeping.reflexes << ","
			<< p->goalkeeping.rushingOut << ","
			<< p->goalkeeping.tendencyToPunch << ","
			<< p->goalkeeping.throwing << ","
			<< p->abilities.currentAbility << ","
			<< p->abilities.potentialAbility << ","
			<< p->abilities.leftFoot << ","
			<< p->abilities.rightFoot << ","
			<< p->abilities.matchSharpness << ","
			<< p->abilities.matchExercise << ","
			<< p->contract.clubUniqueID << ","
			<< p->contract.clubName << ","
			<< p->contract.type << ","
			<< p->contract.jobType << ","
			<< p->contract.value << ","
			<< p->contract.askingPrice << ","
			<< p->contract.weeklyWage << ","
			<< p->contract.startDayOfYear << ","
			<< p->contract.startYear << ","
			<< p->contract.endDayOfYear << ","
			<< p->contract.endYear << ","
			<< p->contract.joinDayOfYear << ","
			<< p->contract.joinYear << ","
			<< p->contract.loyaltyBonus << ","
			<< p->contract.squadStatus << ","
			<< p->contract.squadNumber << "\n";
	}

	out.close();
}