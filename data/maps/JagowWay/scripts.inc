JagowWay_MapScripts::
	.byte 0


//Need to code an event that will stop player from going south near walmore town until after pokedex is recived in tilyous lab in lake mead village.
//At this point the variables will be VAR_LITTLEROOT_TOWN_STATE 5, VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 5 or 6 depending on if special dialouge was unlocked and VAR_OLDALE_TOWN_STATE 2
//FLAG_SYS_POKEMON_GET will also need to be set for this event to take place

//Scripts

Script_JagowWay_SignpostSouth::
	lock
	msgbox T_JagowWay_SignPostForWalmore, MSGBOX_SIGN
	release
	end

Script_JagowWay_TrainTracks_Right::
	lock
	msgbox T_JagowWay_TrainTracks, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_TrainTracks_Right
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	release
	end

Script_JagowWay_TrainTracks_Left::
	lock
	msgbox T_JagowWay_TrainTracks, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_TrainTracks_Left
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	release
	end


Script_JagowWay_StarterBattle:: 
	lock
	addobject 1
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	applymovement 1, M_JagowWay_JohnChallengesFro
	waitmovement 1
	msgbox T_JagowWay_JohnBattleDialouge, MSGBOX_DEFAULT
	closemessage
	msgbox T_JagowWay_JohnBattleDialouge2, MSGBOX_DEFAULT
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	switch VAR_STARTER_MON
	case 0, Script_JagowWay_StarterBattleRascaloot
	case 1, Script_JagowWay_StarterBattleFlobra
	case 2, Script_JagowWay_StarterBattleEmboryps
	end
	
Script_JagowWay_StarterBattleRascaloot:
	setvar VAR_MUGSHOT_ID, MUGSHOT_JOHNM
	trainerbattle_no_intro TRAINER_JOHN_JAGOW_WAY_MUDKIP, T_JagowWay_JohnDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_JagowWay_AfterJohnBattleLost
	goto Script_JagowWay_AfterJohnBattle
	end

Script_JagowWay_StarterBattleFlobra:
	setvar VAR_MUGSHOT_ID, MUGSHOT_JOHNM
	trainerbattle_no_intro TRAINER_JOHN_JAGOW_WAY_TREECKO, T_JagowWay_JohnDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_JagowWay_AfterJohnBattleLost
	goto Script_JagowWay_AfterJohnBattle
	end

Script_JagowWay_StarterBattleEmboryps:
	setvar VAR_MUGSHOT_ID, MUGSHOT_JOHNM
	trainerbattle_no_intro TRAINER_JOHN_JAGOW_WAY_TORCHIC, T_JagowWay_JohnDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_JagowWay_AfterJohnBattleLost
	goto Script_JagowWay_AfterJohnBattle
	end	
	
Script_JagowWay_StarterBattle2:: 
	lock
	addobject 1
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	applymovement 1, M_JagowWay_JohnChallengesFro2
	waitmovement 1
	msgbox T_JagowWay_JohnBattleDialouge, MSGBOX_DEFAULT
	closemessage
	msgbox T_JagowWay_JohnBattleDialouge2, MSGBOX_DEFAULT
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	switch VAR_STARTER_MON
	case 0, Script_JagowWay_StarterBattleRascaloot
	case 1, Script_JagowWay_StarterBattleFlobra
	case 2, Script_JagowWay_StarterBattleEmboryps
	end
	
Script_JagowWay_AfterJohnBattle:
setvar VAR_LITTLEROOT_TOWN_STATE, 5
msgbox T_JohnAfterBattle MSGBOX_DEFAULT
special HealPlayerParty
msgbox T_JW_JagowWoodsClosed, MSGBOX_DEFAULT
closemessage
fadedefaultbgm
applymovement 1, M_JagowWay_JohnLeaves
waitmovement 1
removeobject 1
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
release
end

Script_JagowWay_AfterJohnBattleLost:
setvar VAR_LITTLEROOT_TOWN_STATE, 5
msgbox T_JohnAfterBattleLost MSGBOX_DEFAULT
special HealPlayerParty
msgbox T_JW_JagowWoodsClosed, MSGBOX_DEFAULT
closemessage
fadedefaultbgm
applymovement 1, M_JagowWay_JohnLeaves
waitmovement 1
removeobject 1
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
release
end


release
end


Script_JagowWay_NorthSignPost::
msgbox T_JagowWay_SignPostForLakeMead, MSGBOX_SIGN
release
end

//Movements

M_TrainTracks_Left:
walk_right
step_end

M_TrainTracks_Right:
walk_left
step_end

M_JagowWay_JohnLeaves:
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_JagowWay_JohnChallengesFro:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

M_JagowWay_JohnChallengesFro2:
walk_down
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

//Text

T_JagowWay_SignPostForLakeMead:
	.string "{DOWN_ARROW} Walmore Town \n{UP_ARROW} Sy Pathway$"
	

T_JagowWay_JohnBattleDialouge:
	.string "John: Hey Fro, before you go out \ninto the wild why don't I show you \lhow to battle with your new \lPokemon?\p"
	.string "Fro: How hard can it be? Is this \nreally necessary?$"
	
T_JagowWay_JohnBattleDialouge2: 
	.string "John: Experience is a valuable \nteacher. Now let's battle!$"

T_JagowWay_JohnDefeated:
	.string "John: You're a natural, Fro!$"
	
T_JohnAfterBattle:
	.string "John: Great job Fro. I look forward \nto seeing you grow as a trainer. \pLet me heal your Pokemon.\p$"

T_JohnAfterBattleLost:
	.string "John: Great try Fro.\p You're kinda trash right now tbh though\nlol. \pI look forward \nto seeing you grow as a trainer. \pLet me heal your Pokemon.\p$"

T_JagowWay_TrainTracks:
	.string "Mom always says to stay of the \ntrain tracks. You could get hurt.$"

T_JW_JagowWoodsClosed:
	.string "As a Trainer, the easiest way to test\n"
	.string "yourself is to take the Gym Challenge.\p"
	.string "A lot of our friends have embraced this\n"
	.string "new world we live in, and either taken\l"
	.string "the challenge, or became gym leaders\l"
	.string "of this region themselves.\p"
	.string "I'm going to head home to Walmore Town\n"
	.string "quickly before making my way to Summit\l"
	.string "City to challenge the gym leaders there.\p"
	.string "I'll see you around Fro, good luck!$"

T_JagowWay_SignPostForWalmore:
	.string "{UP_ARROW} Lake Mead\n {RIGHT_ARROW} Walmore Town$"