#include "Player.h"
#include "Util.h"

#define OFFSET_ROW_ID					 (0x1C8)
#define OFFSET_FIRST_NAME				 (0x4C)
#define OFFSET_LAST_NAME				 (0x54)
#define OFFSET_NATIONALITY				 (0x6C)
#define OFFSET_BIRTH_YEAR				 (0x206)
#define OFFSET_ETHNICITY				 (0x251)
#define OFFSET_HAIR_COLOR				 (0x252)
#define OFFSET_HAIR_LENGTH				 (0x253)
#define OFFSET_SKIN_TONE				 (0x254)
#define OFFSET_HEIGHT					 (0x15E)
#define OFFSET_WEIGHT					 (0x15C)
#define OFFSET_MORALE					 (0x1AB)
#define OFFSET_DECLARED_FOR_NATION       (0x1A9)
#define OFFSET_INTERNATIONAL_APPEARANCES (0x324)
#define OFFSET_INTERNATIONAL_GOALS       (0x326)
#define OFFSET_GENERAL_OPTIONS           (0xFA)
#define OFFSET_BANS						 (0x18)
#define OFFSET_INJURIES					 (0xD8)
#define OFFSET_CORNERS					 (0x18E)
#define OFFSET_CROSSING					 (0x173)
#define OFFSET_DRIBBLING				 (0x174)
#define OFFSET_FINISHING				 (0x175)
#define OFFSET_FIRST_TOUCH				 (0x189)
#define OFFSET_FREEKICK_TAKING           (0x196)
#define OFFSET_HEADING					 (0x176)
#define OFFSET_LONG_SHOTS				 (0x177)
#define OFFSET_LONG_THROWS				 (0x191)
#define OFFSET_MARKING					 (0x178)
#define OFFSET_PASSING					 (0x17A)
#define OFFSET_PENALTY_TAKING            (0x17B)
#define OFFSET_TACKLING					 (0x17C)
#define OFFSET_TECHNIQUE				 (0x18A)
#define OFFSET_AERIAL_REACH              (0x17F)
#define OFFSET_COMMAND_OF_AREA           (0x180)
#define OFFSET_COMMUNICATION             (0x181)
#define OFFSET_ECCENTRICITY              (0x192)
#define OFFSET_HANDLING					 (0x17E)
#define OFFSET_KICKING					 (0x182)
#define OFFSET_ONE_ON_ONES               (0x186)
#define OFFSET_REFLEXES					 (0x188)
#define OFFSET_RUSHING_OUT               (0x193)
#define OFFSET_TENDENCY_TO_PUNCH         (0x194)
#define OFFSET_THROWING					 (0x183)
#define OFFSET_AGGRESSION				 (0x1A0)
#define OFFSET_ANTICIPATION              (0x184)
#define OFFSET_BRAVERY					 (0x19E)
#define OFFSET_COMPOSURE				 (0x1A7)
#define OFFSET_CONCENTRATION             (0x1A8)
#define OFFSET_DECISION					 (0x185)
#define OFFSET_DETERMINATION             (0x1A6)
#define OFFSET_FLAIR					 (0x18D)
#define OFFSET_LEADERSHIP				 (0x19B)
#define OFFSET_OFF_THE_BALL              (0x179)
#define OFFSET_POSITIONING               (0x187)
#define OFFSET_TEAMWORK					 (0x18F)
#define OFFSET_VISION					 (0x17D)
#define OFFSET_WORK_RATE				 (0x190)
#define OFFSET_ACCELERATION              (0x195)
#define OFFSET_AGILITY					 (0x1A1)
#define OFFSET_BALANCE					 (0x19D)
#define OFFSET_JUMPING_REACH             (0x19A)
#define OFFSET_NATURAL_FITNESS           (0x1A5)
#define OFFSET_PACE						 (0x199)
#define OFFSET_STAMINA					 (0x198)
#define OFFSET_STRENGTH					 (0x197)
#define OFFSET_DIRTINESS				 (0x19C)
#define OFFSET_CONSISTENCY               (0x19F)
#define OFFSET_IMP_MATCHES               (0x1A2)
#define OFFSET_INJURY_PRONENESS          (0x1A3)
#define OFFSET_VERSATILITY               (0x1A4)
#define OFFSET_ROLE_USED_TO_FILL         (0x1B3)
#define OFFSET_PREFERED_CENTRAL_POSITION (0x1B2)
#define OFFSET_GOALKEEPER				 (0x164)
#define OFFSET_SWEEPER					 (0x165)
#define OFFSET_DEFENDER_LEFT             (0x166)
#define OFFSET_DEFENDER_CENTER           (0x167)
#define OFFSET_DEFENDER_RIGHT            (0x168)
#define OFFSET_WING_BACK_LEFT            (0x171)
#define OFFSET_WING_BACK_RIGHT           (0x172)
#define OFFSET_DEFENSIVE_MIDFIELDER      (0x169)
#define OFFSET_MIDFIELDER_LEFT           (0x16A)
#define OFFSET_MIDFIELDER_CENTER         (0x16B)
#define OFFSET_MIDFIELDER_RIGHT          (0x16C)
#define OFFSET_ATTACKING_MIDFIELDER_LEFT (0x16D)
#define OFFSET_ATTACKING_MIDFIELDER_CENTER (0x16E)
#define OFFSET_ATTACKING_MIDFIELDER_RIGHT  (0x16F)
#define OFFSET_STRIKER					 (0x170)
#define OFFSET_CURRENT_ABILITY           (0x158)
#define OFFSET_POTENTIONAL_ABILITY       (0x15A)
#define OFFSET_LEFT_FOOT				 (0x18B)
#define OFFSET_RIGHT_FOOT				 (0x18C)
#define OFFSET_MATCH_SHARPNESS           (0x14C)
#define OFFSET_MATCH_EXERCISE            (0x150)
#define OFFSET_ADAPTABILITY              (0x240)
#define OFFSET_AMBITION				     (0x241)
#define OFFSET_CONTROVERSY               (0x247)
#define OFFSET_LOYALTY					 (0x242)
#define OFFSET_PRESSURE					 (0x243)
#define OFFSET_PROFESSIONALISM           (0x244)
#define OFFSET_SPORTMANSHIP              (0x245)
#define OFFSET_TEMPERAMENT               (0x246)
#define OFFSET_CLUB_UNIQUE_ID            (0x288)
#define OFFSET_CLUB_NAME				 (0x288)
#define OFFSET_TYPE						 (0x288)
#define OFFSET_JOB_TYPE					 (0x288)
#define OFFSET_VALUE					 (0x128)
#define OFFSET_ASKING_PRICE              (0x12C)
#define OFFSET_WEEKLY_WAGE               (0x288)
#define OFFSET_START_DAY_OF_YEAR         (0x288)
#define OFFSET_START_YEAR                (0x288)
#define OFFSET_END_DAY_OF_YEAR           (0x288)
#define OFFSET_END_YEAR                  (0x288)
#define OFFSET_JOIN_DAY_OF_YEAR          (0x288)
#define OFFSET_JOIN_YEAR                 (0x288)
#define OFFSET_LOYALTY_BONUS             (0x288)
#define OFFSET_SQUAD_STATUS              (0x288)
#define OFFSET_SQUAD_NUMBER              (0x288)

#define DMA_OFFSET_NAME           { 0x0, 0x4 }
#define DMA_OFFSET_NATIONALITY    { 0xB8, 0x4 }
#define DMA_OFFSET_CLUB_UNIQUE_ID { 0x10, 0xC }
#define DMA_OFFSET_CLUB_NAME      { 0x10, 0x18, 0xB8, 0x4 }
#define DMA_OFFSET_TYPE           { 0x9A }
#define DMA_OFFSET_JOB_TYPE       { 0x1C }
#define DMA_OFFSET_VALUE          { 0x10, 0xC }
#define DMA_OFFSET_WEEKLY_WAGE    { 0x18 }
#define DMA_OFFSET_START_DOY      { 0x3C }
#define DMA_OFFSET_START_YEAR     { 0x3E }
#define DMA_OFFSET_END_DOY        { 0x40 }
#define DMA_OFFSET_END_YEAR       { 0x42 }
#define DMA_OFFSET_JOIN_DOY       { 0x44 }
#define DMA_OFFSET_JOIN_YEAR      { 0x46 }
#define DMA_OFFSET_LOYALTY_BONUS  { 0x90 }
#define DMA_OFFSET_SQUAD_STATUS   { 0x4C }
#define DMA_OFFSET_SQUAD_NUMBER   { 0x53 }

Player::Player()
{
}


Player::~Player()
{
}

void Player::fetchFromMemory(DWORD_PTR address)
{
	general.rowId = Util::readValueFromMemory<int32_t>(address, OFFSET_ROW_ID);
	general.firstName = Util::getString32(address, OFFSET_FIRST_NAME, DMA_OFFSET_NAME);
	general.lastName = Util::getString32(address, OFFSET_LAST_NAME, DMA_OFFSET_NAME);
	general.nationality = Util::getString32(address, OFFSET_NATIONALITY, DMA_OFFSET_NATIONALITY);
	general.birthYear = Util::readValueFromMemory<uint16_t>(address, OFFSET_BIRTH_YEAR);
	general.ethnicity = Util::readValueFromMemory<uint8_t>(address, OFFSET_ETHNICITY);
	general.hairColour = Util::readValueFromMemory<uint8_t>(address, OFFSET_HAIR_COLOR);
	general.hairLength = Util::readValueFromMemory<uint8_t>(address, OFFSET_HAIR_LENGTH);
	general.skinTone = Util::readValueFromMemory<uint8_t>(address, OFFSET_SKIN_TONE);
	general.height = Util::readValueFromMemory<uint16_t>(address, OFFSET_HEIGHT);
	general.weight = Util::readValueFromMemory<uint16_t>(address, OFFSET_WEIGHT);
	general.morale = Util::readValueFromMemory<uint8_t>(address, OFFSET_MORALE);
	general.declaredForNation = Util::readValueFromMemory<uint8_t>(address, OFFSET_DECLARED_FOR_NATION);
	general.internationalAppearances = Util::readValueFromMemory<uint8_t>(address, OFFSET_INTERNATIONAL_APPEARANCES);
	general.internationalGoals = Util::readValueFromMemory<uint8_t>(address, OFFSET_INTERNATIONAL_GOALS);
	general.generalOptions = Util::readValueFromMemory<uint8_t>(address, OFFSET_GENERAL_OPTIONS);
	general.bans = Util::readValueFromMemory<uint8_t>(address, OFFSET_BANS);
	general.injuries = Util::readValueFromMemory<uint8_t>(address, OFFSET_INJURIES);
	technical.corners = Util::readValueFromMemory<uint8_t>(address, OFFSET_CORNERS);
	technical.crossing = Util::readValueFromMemory<uint8_t>(address, OFFSET_CROSSING);
	technical.dribbling = Util::readValueFromMemory<uint8_t>(address, OFFSET_DRIBBLING);
	technical.finishing = Util::readValueFromMemory<uint8_t>(address, OFFSET_FINISHING);
	technical.firstTouch = Util::readValueFromMemory<uint8_t>(address, OFFSET_FIRST_TOUCH);
	technical.freeKickTaking = Util::readValueFromMemory<uint8_t>(address, OFFSET_FREEKICK_TAKING);
	technical.heading = Util::readValueFromMemory<uint8_t>(address, OFFSET_HEADING);
	technical.longShots = Util::readValueFromMemory<uint8_t>(address, OFFSET_LONG_SHOTS);
	technical.longThrows = Util::readValueFromMemory<uint8_t>(address, OFFSET_LONG_THROWS);
	technical.marking = Util::readValueFromMemory<uint8_t>(address, OFFSET_MARKING);
	technical.passing = Util::readValueFromMemory<uint8_t>(address, OFFSET_PASSING);
	technical.penaltyTaking = Util::readValueFromMemory<uint8_t>(address, OFFSET_PENALTY_TAKING);
	technical.tackling = Util::readValueFromMemory<uint8_t>(address, OFFSET_TACKLING);
	technical.technique = Util::readValueFromMemory<uint8_t>(address, OFFSET_TECHNIQUE);
	goalkeeping.aerialReach = Util::readValueFromMemory<uint8_t>(address, OFFSET_AERIAL_REACH);
	goalkeeping.commandOfArea = Util::readValueFromMemory<uint8_t>(address, OFFSET_COMMAND_OF_AREA);
	goalkeeping.communication = Util::readValueFromMemory<uint8_t>(address, OFFSET_COMMUNICATION);
	goalkeeping.eccentricity = Util::readValueFromMemory<uint8_t>(address, OFFSET_ECCENTRICITY);
	goalkeeping.handling = Util::readValueFromMemory<uint8_t>(address, OFFSET_HANDLING);
	goalkeeping.kicking = Util::readValueFromMemory<uint8_t>(address, OFFSET_KICKING);
	goalkeeping.oneOnOnes = Util::readValueFromMemory<uint8_t>(address, OFFSET_ONE_ON_ONES);
	goalkeeping.reflexes = Util::readValueFromMemory<uint8_t>(address, OFFSET_REFLEXES);
	goalkeeping.rushingOut = Util::readValueFromMemory<uint8_t>(address, OFFSET_RUSHING_OUT);
	goalkeeping.tendencyToPunch = Util::readValueFromMemory<uint8_t>(address, OFFSET_TENDENCY_TO_PUNCH);
	goalkeeping.throwing = Util::readValueFromMemory<uint8_t>(address, OFFSET_THROWING);
	mental.aggression = Util::readValueFromMemory<uint8_t>(address, OFFSET_AGGRESSION);
	mental.anticipation = Util::readValueFromMemory<uint8_t>(address, OFFSET_ANTICIPATION);
	mental.bravery = Util::readValueFromMemory<uint8_t>(address, OFFSET_BRAVERY);
	mental.composure = Util::readValueFromMemory<uint8_t>(address, OFFSET_COMPOSURE);
	mental.concentration = Util::readValueFromMemory<uint8_t>(address, OFFSET_CONCENTRATION);
	mental.decision = Util::readValueFromMemory<uint8_t>(address, OFFSET_DECISION);
	mental.determination = Util::readValueFromMemory<uint8_t>(address, OFFSET_DETERMINATION);
	mental.flair = Util::readValueFromMemory<uint8_t>(address, OFFSET_FLAIR);
	mental.leadership = Util::readValueFromMemory<uint8_t>(address, OFFSET_LEADERSHIP);
	mental.offTheBall = Util::readValueFromMemory<uint8_t>(address, OFFSET_OFF_THE_BALL);
	mental.positioning = Util::readValueFromMemory<uint8_t>(address, OFFSET_POSITIONING);
	mental.teamwork = Util::readValueFromMemory<uint8_t>(address, OFFSET_TEAMWORK);
	mental.vision = Util::readValueFromMemory<uint8_t>(address, OFFSET_VISION);
	mental.workRate = Util::readValueFromMemory<uint8_t>(address, OFFSET_WORK_RATE);
	physical.acceleration = Util::readValueFromMemory<uint8_t>(address, OFFSET_ACCELERATION);
	physical.agility = Util::readValueFromMemory<uint8_t>(address, OFFSET_AGILITY);
	physical.balance = Util::readValueFromMemory<uint8_t>(address, OFFSET_BALANCE);
	physical.jumpingReach = Util::readValueFromMemory<uint8_t>(address, OFFSET_JUMPING_REACH);
	physical.naturalFitness = Util::readValueFromMemory<uint8_t>(address, OFFSET_NATURAL_FITNESS);
	physical.pace = Util::readValueFromMemory<uint8_t>(address, OFFSET_PACE);
	physical.stamina = Util::readValueFromMemory<uint8_t>(address, OFFSET_STAMINA);
	physical.strength = Util::readValueFromMemory<uint8_t>(address, OFFSET_STRENGTH);
	hidden.dirtiness = Util::readValueFromMemory<uint8_t>(address, OFFSET_DIRTINESS);
	hidden.consistency = Util::readValueFromMemory<uint8_t>(address, OFFSET_CONSISTENCY);
	hidden.impMatches = Util::readValueFromMemory<uint8_t>(address, OFFSET_IMP_MATCHES);
	hidden.injuryProneness = Util::readValueFromMemory<uint8_t>(address, OFFSET_INJURY_PRONENESS);
	hidden.versatility = Util::readValueFromMemory<uint8_t>(address, OFFSET_VERSATILITY);
	positions.roleUsedToFillEmptyAttributes = Util::readValueFromMemory<uint8_t>(address, OFFSET_ROLE_USED_TO_FILL);
	positions.preferredCentralPosition = Util::readValueFromMemory<uint8_t>(address, OFFSET_PREFERED_CENTRAL_POSITION);
	positions.goalkeeper = Util::readValueFromMemory<uint8_t>(address, OFFSET_GOALKEEPER);
	positions.sweeper = Util::readValueFromMemory<uint8_t>(address, OFFSET_SWEEPER);
	positions.defenseLeft = Util::readValueFromMemory<uint8_t>(address, OFFSET_DEFENDER_LEFT);
	positions.defenseCenter = Util::readValueFromMemory<uint8_t>(address, OFFSET_DEFENDER_CENTER);
	positions.defenseRight = Util::readValueFromMemory<uint8_t>(address, OFFSET_DEFENDER_RIGHT);
	positions.wingBackLeft = Util::readValueFromMemory<uint8_t>(address, OFFSET_WING_BACK_LEFT);
	positions.wingBackRight = Util::readValueFromMemory<uint8_t>(address, OFFSET_WING_BACK_RIGHT);
	positions.defensiveMidfielder = Util::readValueFromMemory<uint8_t>(address, OFFSET_DEFENSIVE_MIDFIELDER);
	positions.midfielderLeft = Util::readValueFromMemory<uint8_t>(address, OFFSET_MIDFIELDER_LEFT);
	positions.midfielderCenter = Util::readValueFromMemory<uint8_t>(address, OFFSET_MIDFIELDER_CENTER);
	positions.midfielderRight = Util::readValueFromMemory<uint8_t>(address, OFFSET_MIDFIELDER_RIGHT);
	positions.attackingMidfielderLeft = Util::readValueFromMemory<uint8_t>(address, OFFSET_ATTACKING_MIDFIELDER_LEFT);
	positions.attackingMidfielderCenter = Util::readValueFromMemory<uint8_t>(address, OFFSET_ATTACKING_MIDFIELDER_CENTER);
	positions.attackingMidfielderRight = Util::readValueFromMemory<uint8_t>(address, OFFSET_ATTACKING_MIDFIELDER_RIGHT);
	positions.striker = Util::readValueFromMemory<uint8_t>(address, OFFSET_STRIKER);
	abilities.currentAbility = Util::readValueFromMemory<uint16_t>(address, OFFSET_CURRENT_ABILITY);
	abilities.potentialAbility = Util::readValueFromMemory<uint16_t>(address, OFFSET_POTENTIONAL_ABILITY);
	abilities.leftFoot = Util::readValueFromMemory<uint8_t>(address, OFFSET_LEFT_FOOT);
	abilities.rightFoot = Util::readValueFromMemory<uint8_t>(address, OFFSET_RIGHT_FOOT);
	abilities.matchSharpness = Util::readValueFromMemory<uint16_t>(address, OFFSET_MATCH_SHARPNESS);
	abilities.matchExercise = Util::readValueFromMemory<uint16_t>(address, OFFSET_MATCH_EXERCISE);
	personality.adaptability = Util::readValueFromMemory<uint8_t>(address, OFFSET_ADAPTABILITY);
	personality.ambition = Util::readValueFromMemory<uint8_t>(address, OFFSET_AMBITION);
	personality.controversy = Util::readValueFromMemory<uint8_t>(address, OFFSET_CONTROVERSY);
	personality.loyalty = Util::readValueFromMemory<uint8_t>(address, OFFSET_LOYALTY);
	personality.pressure = Util::readValueFromMemory<uint8_t>(address, OFFSET_PRESSURE);
	personality.professionalism = Util::readValueFromMemory<uint8_t>(address, OFFSET_PROFESSIONALISM);
	personality.sportmanship = Util::readValueFromMemory<uint8_t>(address, OFFSET_SPORTMANSHIP);
	personality.temperament = Util::readValueFromMemory<uint8_t>(address, OFFSET_TEMPERAMENT);
	contract.clubUniqueID = Util::readValueFromMemoryDMA<int>(address, OFFSET_CLUB_UNIQUE_ID, DMA_OFFSET_CLUB_UNIQUE_ID);
	contract.clubName = Util::getString64(address, OFFSET_CLUB_NAME, DMA_OFFSET_CLUB_NAME);
	contract.type = Util::readValueFromMemoryDMA<uint8_t>(address, OFFSET_TYPE, DMA_OFFSET_TYPE);
	contract.jobType = Util::readValueFromMemoryDMA<uint8_t>(address, OFFSET_JOB_TYPE, DMA_OFFSET_JOB_TYPE);
	contract.value = Util::readValueFromMemoryDMA<int>(address, OFFSET_VALUE, DMA_OFFSET_VALUE);
	contract.askingPrice = Util::readValueFromMemory<int>(address, OFFSET_ASKING_PRICE);
	contract.weeklyWage = Util::readValueFromMemoryDMA<int>(address, OFFSET_WEEKLY_WAGE, DMA_OFFSET_WEEKLY_WAGE);
	contract.startDayOfYear = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_START_DAY_OF_YEAR, DMA_OFFSET_START_DOY);
	contract.startYear = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_START_YEAR, DMA_OFFSET_START_YEAR);
	contract.endDayOfYear = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_END_DAY_OF_YEAR, DMA_OFFSET_END_DOY);
	contract.endYear = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_END_YEAR, DMA_OFFSET_END_YEAR);
	contract.joinDayOfYear = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_JOIN_DAY_OF_YEAR, DMA_OFFSET_JOIN_DOY);
	contract.joinYear = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_JOIN_YEAR, DMA_OFFSET_JOIN_YEAR);
	contract.loyaltyBonus = Util::readValueFromMemoryDMA<int>(address, OFFSET_LOYALTY_BONUS, DMA_OFFSET_LOYALTY_BONUS);
	contract.squadStatus = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_SQUAD_STATUS, DMA_OFFSET_SQUAD_STATUS);
	contract.squadNumber = Util::readValueFromMemoryDMA<int16_t>(address, OFFSET_SQUAD_NUMBER, DMA_OFFSET_SQUAD_NUMBER);
}
