NCC_Underground_East_1B_MapScripts::
	.byte 0


@--------------------------------------------------------------------------------
@-------------------------------------Events-------------------------------------
@--------------------------------------------------------------------------------

NCC_Underground_East_1B_ScientistNidokindAndQueenBattle::
	@@NOTDONEYET 
	@@ THIS WILL BE AN EVENT WHERE THE PLAYER FIGHTS SHADOW DUGTRIO AND OBTAINS HM STRENGTH REQUIRED FOR PROGRESSING THROUGH DUNGEON
	lockall
		faceplayer
		trainerbattle_double TRAINER_WINSTON_4, NCC_Underground_East_1B_1F_Text_GruntIntro, NCC_Underground_East_1B_1F_Text_GruntDefeat, Route104_Text_GinaNotEnoughMons, NCC_Underground_East_1B_ScientistDefeat
		msgbox NCC_Underground_East_1B_1F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

NCC_Underground_East_1B_ScientistDefeat:
		goto_if_set FLAG_RECEIVED_SS_TICKET, NCC_Underground_West_1F_Eventscript_GruntPostBattle
		goto_if_defeated TRAINER_WINSTON_2, NCC_Underground_East_1B_GiveKey
	releaseall
	end

NCC_Underground_East_1B_GiveKey:
		msgbox NCC_Underground_East_1B_1F_Text_GruntPostGiveKey, MSGBOX_AUTOCLOSE
		giveitem ITEM_LAB_KEY, 1
		setflag FLAG_RECEIVED_SS_TICKET
	releaseall
	end

NCC_Underground_West_1F_Eventscript_GruntPostBattle:
		msgbox NCC_Underground_East_1B_1F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	releaseall
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

NCC_Underground_East_1B_1F_Text_GruntIntro:
	.string "You shouldn't be messing around\n"
	.string "here. You could get hurt.$"

NCC_Underground_East_1B_1F_Text_GruntDefeat:
	.string "Looks like I'm the one who shouldn't\n"
	.string "be messing around.$"

NCC_Underground_East_1B_1F_Text_GruntPostBattleGiveStrength:
	.string "Don't hurt me. Take this!$"

NCC_Underground_East_1B_1F_Text_GruntPostBattle:
	.string "I messed around and found out the\n"
	.string "meaning of embarassment.$"

NCC_Underground_East_1B_1F_Text_GruntPostGiveKey:
	.string "I can't stand up to you, please\n"
	.string "take this key and leave me alone.$"
