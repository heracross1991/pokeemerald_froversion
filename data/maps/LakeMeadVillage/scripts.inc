.set LOCALID_WASULA, 8

LakeMeadVillage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeMeadVillage_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LakeMeadVillage_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeMeadVillage_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LakeMeadVillage_OnWarp	
	.byte 0

//Variables
// VAR_LITTLEROOT_INTRO_STATE 0 = Intro state which triggers intro event when warping to starting map. sets var to 1 after initial cutscene
// VAR_LITTLEROOT_INTRO_STATE 1 = In this state the player must speak to angelina to trigger event which allows player to enter the basement. sets var to 2 when complete
// VAR_LITTLEROOT_INTRO_STATE 2 = In this state the player must go to their room and go to sleep, ending the prolouge event and setting the var to 3
// VAR_LITTLEROOT_INTRO_STATE 3 = Player must enter Isiahs house; when set to 3 isiahs mom event will trigger promting you to return home and setting var to 4
// VAR_LITTLEROOT_INTRO_STATE 4 = Upon returning home mom event occurs; sets VAR_LITTLEROOT_INTRO_STATE to 5 and VAR_LITTLEROOT_TOWN_STATE 1, allowing professor give pokemon event to trigger
// VAR_LITTLEROOT_INTRO_STATE 5 =  as of now this serves as the final variable currently coded no special events (except 6 which offers one special dialouge option)
// VAR_LITTLEROOT_INTRO_STATE 6 = Unlocks special dialouge option for Isiah in village


// VAR_LITTLEROOT_TOWN_STATE 0 = Default Town State, preventrs player from leaving town befoe finding professor and picking pokemon
// VAR_LITTLEROOT_TOWN_STATE 1 = Mom has told you Isiah was just here looking for you. Now you can try to leave town and professor will stop you and take you to his lab
// VAR_LITTLEROOT_TOWN_STATE 2 = Set after professor takes you to his lab. 
// VAR_LITTLEROOT_TOWN_STATE 3 = Set after dialouge telling you to pick pokemon inside lab. also prevents player from leaving lab without picking pokemon
// VAR_LITTLEROOT_TOWN_STATE 4 = set after you pick pokemon. You can now leave the lab. Triggers battle with john when leaving Lake mead village going to Jagow Way for the first time
// VAR_LITTLEROOT_TOWN_STATE 5 = set after battle with john. Final state as of now.


// VAR_OLDALE_TOWN_STATE 1 = this will be set to 1 in walmore town by visiting the pokemart. When set to 1 professor will give pokedex then set VAR_OLDALE_TOWN_STATE to 2.
// VAR_OLDALE_TOWN_STATE 2 = Set to this after recieved pokedex. Final state as of right now.



//Mapscripts

LakeMeadVillage_OnTransition: @ 81E7DDB
	setflag FLAG_VISITED_LITTLEROOT_TOWN
end

LakeMeadVillage_OnFrame:
map_script_2 VAR_OLDALE_TOWN_STATE, 2, Script_LMV_SilentWarpToCutscene
map_script_2 VAR_OLDALE_TOWN_STATE, 3, Script_LMV_IsiahCaught
.2byte 0

LakeMeadVillage_OnLoad:
	removeobject 2
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq Script_LakeMeadVillage_MoveLittleBoyRemoveIsiah
	compare VAR_OLDALE_TOWN_STATE, 3
	goto_if_eq Script_LMV_MoveIsiah
	compare VAR_OLDALE_TOWN_STATE, 4
	goto_if_eq Script_LMV_IsiahAndCaptainPosition
	compare VAR_OLDALE_TOWN_STATE, 5
	goto_if_eq Script_LMV_RemoveSoldiersAndIsiah
	end

LakeMeadVillage_OnWarp:
	map_script_2 VAR_OLDALE_TOWN_STATE, 3, Script_LMV_HidePlayersForIsiahCaughtCutscene
	.2byte 0
	

Script_LakeMeadVillage_MoveLittleBoyRemoveIsiah:
	setobjectxyperm 1, 27, 16
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH
	end

//Scripts

Script_LakeMeadVillage_KidStopsYouFromLeaving::
	lock
	applymovement 1, M_KidStopsYou
	waitmovement 1
	playSE SE_PIN
	waitse
	msgbox T_KidStopsYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_FroStoppedByKid
	applymovement 1, M_KidFaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end


Script_LakeMeadVillage_TilyouStopsYouFromLeaving1::
	lock
	playSE MUS_RG_OAK
	msgbox T_TilyouHeyWait, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerStopsAndTurns
	playSE SE_PIN
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 2
	applymovement 2, M_TilyouStopsPlayer1
	waitmovement 2
	msgbox T_TilyouTakesYouToLab, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyouWalksToLab1
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerWalksToLab1
	waitmovement OBJ_EVENT_ID_PLAYER
	opendoor 15 16
	waitdooranim
	applymovement 2, M_TilyouEntersLab
	waitmovement 2
	removeobject 2
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerEntersLab
	waitmovement OBJ_EVENT_ID_PLAYER
	closedoor 15 16
	waitdooranim
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	warp MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 0, 6, 12
	waitstate
	release
	end
	
Script_LakeMeadVillage_TilyouStopsYouFromLeaving2::
	lock
	playSE MUS_RG_OAK
	msgbox T_TilyouHeyWait, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerStopsAndTurns
	playSE SE_PIN
	waitmovement OBJ_EVENT_ID_PLAYER
	addobject 2
	applymovement 2, M_TilyouStopsPlayer2
	waitmovement 2
	msgbox T_TilyouTakesYouToLab, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyouWalksToLab2
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerWalksToLab2
	waitmovement OBJ_EVENT_ID_PLAYER
	opendoor 15 16
	waitdooranim
	applymovement 2, M_TilyouEntersLab
	waitmovement 2
	removeobject 2
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	applymovement OBJ_EVENT_ID_PLAYER, M_PlayerEntersLab
	waitmovement OBJ_EVENT_ID_PLAYER
	closedoor 15 16
	waitdooranim
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	warp MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 0, 6, 12
	waitstate
	release
	end

Script_LMV_HidePlayersForIsiahCaughtCutscene::
hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LAKE_MEAD_VILLAGE
hideobjectat  4, MAP_LAKE_MEAD_VILLAGE
hideobjectat  7, MAP_LAKE_MEAD_VILLAGE
release
end 

Script_LMV_SilentWarpToCutscene::
lockall
setvar VAR_OLDALE_TOWN_STATE, 3
warpsilent MAP_LAKE_MEAD_VILLAGE, 255, 9, 5
releaseall
end

Script_LMV_MoveIsiah::
setobjectxyperm 4, 9, 0
setobjectmovementtype 4, MOVEMENT_TYPE_NONE
setobjectxyperm 7, 8, 0
setobjectmovementtype 7, MOVEMENT_TYPE_NONE
end

Script_LMV_IsiahAndCaptainPosition:
setobjectxyperm 4, 9, 4
setobjectmovementtype 4, MOVEMENT_TYPE_NONE
setobjectxyperm 7, 8, 0
//setobjectxyperm 5, 9, 3
setobjectmovementtype 7, MOVEMENT_TYPE_NONE
setobjectmovementtype 5, MOVEMENT_TYPE_NONE
setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
end

Script_LMV_RemoveSoldiersAndIsiah:
removeobject 5
removeobject 6
removeobject 7
removeobject 4
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_SOLDIERS
end

Script_LMV_IsiahCaught:
lockall
delay 30
playbgm MUS_FV_TEAM_MAGA, 0
msgbox T_LMV_TwoSoldiersTalking, MSGBOX_DEFAULT
applymovement 5, M_LookUp
applymovement 6, M_LookUp
waitmovement 6
showobjectat 4, MAP_LAKE_MEAD_VILLAGE
showobjectat 7, MAP_LAKE_MEAD_VILLAGE
applymovement 4, M_LMV_IsiahCaught
applymovement 7, M_LMV_Soldier1CaughtIsiah
waitmovement 7
msgbox T_LMV_Soldier3CaughtIsiah, MSGBOX_DEFAULT
applymovement 7, M_LMV_CaptainExits
applymovement 5 M_LMV_StoneDetainsIsiah
waitmovement 7
delay 30
warpsilent MAP_LAKE_MEAD_VILLAGE, 255, 22, 23
setvar VAR_OLDALE_TOWN_STATE, 4
end

Script_LMV_SaveIsiahGrunt1::
lockall
msgbox T_LMV_StartBattleSequence, MSGBOX_NPC
msgbox T_LMV_SoldierBattleStart, MSGBOX_NPC
clearflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
addobject LOCALID_WASULA, MAP_LAKE_MEAD_VILLAGE
applymovement LOCALID_WASULA, M_LMV_WasulaHelpsFro1
waitmovement LOCALID_WASULA
msgbox T_LMV_WasulaHelpsFro,
switch VAR_STARTER_MON
case 0, Script_LMV_InitiateBobbyBattleFlobra  //fro grass
case 1, Script_LMV_InitiateBobbyBattleEmboryps //fro water
case 2, Script_LMV_InitiateBobbyBattleRascaloot	//fro fire
release
end

Script_LMV_InitiateBobbyBattleFlobra::
	multi_fixed_2_vs_1 TRAINER_JOHN_AND_JAY_1, T_LMV_JohnDefeat, TRAINER_BRENDAN_ROUTE_119_MUDKIP, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY
	setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_LMV_PlayerLoseDoubleBattle
	msgbox T_LMV_IsiahSaved, MSGBOX_DEFAULT
	applymovement 5, M_LMV_StoneRetreat
	applymovement 6, M_LMV_BudRetreat
	waitmovement 6
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_SOLDIERS
	applymovement 4, M_LMV_IsiahToFro
	waitmovement 4
	msgbox T_LMV_IsiahThanksFroAndBob, MSGBOX_DEFAULT
	setvar VAR_OLDALE_TOWN_STATE, 5
	delay 30
	warpsilent MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 255, 6, 6
	releaseall
	end

Script_LMV_InitiateBobbyBattleEmboryps:
	multi_fixed_2_vs_1 TRAINER_JOHN_AND_JAY_1, T_LMV_JohnDefeat, TRAINER_BRENDAN_ROUTE_119_TORCHIC, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY
	setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_LMV_PlayerLoseDoubleBattle
	msgbox T_LMV_IsiahSaved, MSGBOX_DEFAULT
	applymovement 5, M_LMV_StoneRetreat
	applymovement 6, M_LMV_BudRetreat
	waitmovement 6
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_SOLDIERS
	applymovement 4, M_LMV_IsiahToFro
	waitmovement 4
	msgbox T_LMV_IsiahThanksFroAndBob, MSGBOX_DEFAULT
	setvar VAR_OLDALE_TOWN_STATE, 5
	delay 30
	warpsilent MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 255, 6, 6
	releaseall
	end

Script_LMV_InitiateBobbyBattleRascaloot:
	multi_fixed_2_vs_1 TRAINER_JOHN_AND_JAY_1, T_LMV_JohnDefeat, TRAINER_BRENDAN_ROUTE_119_TREECKO, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY
	setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_LMV_PlayerLoseDoubleBattle
	msgbox T_LMV_IsiahSaved, MSGBOX_DEFAULT
	applymovement 5, M_LMV_StoneRetreat
	applymovement 6, M_LMV_BudRetreat
	waitmovement 6
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_SOLDIERS
	applymovement 4, M_LMV_IsiahToFro
	waitmovement 4
	msgbox T_LMV_IsiahThanksFroAndBob, MSGBOX_DEFAULT
	setvar VAR_OLDALE_TOWN_STATE, 5
	delay 30
	warpsilent MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 255, 6, 6
	releaseall
	end



Script_LMV_SaveIsiahGrunt2::
lockall
msgbox T_LMV_StartBattleSequence, MSGBOX_NPC
msgbox T_LMV_SoldierBattleStart, MSGBOX_NPC
clearflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
addobject LOCALID_WASULA
applymovement LOCALID_WASULA, M_LMV_WasulaHelpsFro2
waitmovement LOCALID_WASULA
msgbox T_LMV_WasulaHelpsFro, MSGBOX_NPC
switch VAR_STARTER_MON
case 0, Script_LMV_InitiateBobbyBattleFlobra  //fro grass
case 1, Script_LMV_InitiateBobbyBattleEmboryps //fro water
case 2, Script_LMV_InitiateBobbyBattleRascaloot	//fro fire
release
end

Script_LMV_IsiahSaved:
msgbox T_LMV_IsiahSaved, MSGBOX_DEFAULT
applymovement 5, M_LMV_StoneRetreat
applymovement 6, M_LMV_BudRetreat
waitmovement 6
setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_SOLDIERS
applymovement 4, M_LMV_IsiahToFro
waitmovement 4
msgbox T_LMV_IsiahThanksFroAndBob, MSGBOX_DEFAULT
setvar VAR_OLDALE_TOWN_STATE, 5
delay 30
warpsilent MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 255, 6, 6
releaseall
end

Script_LMV_PlayerLoseDoubleBattle::
msgbox T_LMV_IsiahNotSaved, MSGBOX_DEFAULT
applymovement 5, M_LMV_StoneRetreat
applymovement 6, M_LMV_BudRetreat
waitmovement 6
setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_SOLDIERS
applymovement 4, M_LMV_IsiahToFro
waitmovement 4
msgbox T_LMV_IsiahThanksFroAndBob, MSGBOX_DEFAULT
setvar VAR_OLDALE_TOWN_STATE, 5
delay 30
warpsilent MAP_LAKE_MEAD_VILLAGE_TILYOUS_LAB, 255, 6, 6
releaseall
end

//NPCs
Script_LakeMeadVillage_NPC_LittleBoy::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq Script_LakeMeadVillage_NPC_LittleBoyTilyouDialouge
	goto_if_gt Script_LakeMeadVillage_NPC_LittleBoyStandardDialouge
	release
	end
	
Script_LakeMeadVillage_NPC_LittleBoyTilyouDialouge:
	msgbox T_KidStopsYou, MSGBOX_NPC
	end

Script_LakeMeadVillage_NPC_LittleBoyStandardDialouge:
	msgbox T_NPC_LittleBoyDialouge, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_Boy1::
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq Script_LakeMeadVillage_NPC_Boy1Dialouge1
	goto_if_gt Script_LakeMeadVillage_NPC_Boy1Dialouge2
	end
	
Script_LakeMeadVillage_NPC_Boy1Dialouge1:
	msgbox T_NPC_Boy1_BeforeRecievedPokemon, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_Boy1Dialouge2:
	msgbox T_NPC_Boy1_AfterRecievedPokemon, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_Isiah::
	goto_if_set FLAG_SYS_GAME_CLEAR, Script_LakeMeadVillage_IsiahBattle
	compare VAR_LITTLEROOT_TOWN_STATE, 2
	goto_if_lt Script_LakeMeadVillage_NPC_IsiahBeforeRecievedPoke
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahAfterRecievedPoke
	end
	
Script_LakeMeadVillage_NPC_IsiahBeforeRecievedPoke:
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_ge Script_LakeMeadVillage_IsiahBeforeRecievedPokeDesserChecked
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotion1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOut, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_IsiahBattle:
	lock
	faceplayer
	goto_if_defeated TRAINER_ISIAH_NALLS, Script_LakeMeadVillage_IsiahPostBattle
	msgbox T_LakeMeadVillage_Isiah_WoahYoureChampion, MSGBOX_DEFAULT
	msgbox T_LakeMeadVillage_Isiah_HowAboutABattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Script_LakeMeadVillage_StartIsiahBattle
	msgbox T_LakeMeadVillage_Isiah_ComeBackWhenReady, MSGBOX_DEFAULT
	release
end

Script_LakeMeadVillage_StartIsiahBattle:
	trainerbattle_no_intro TRAINER_ISIAH_NALLS, LakeMeadVillage_Isiah_Text_Defeat
	goto Script_LakeMeadVillage_IsiahDefeated
	end

Script_LakeMeadVillage_IsiahDefeated:
	msgbox T_LakeMeadVillage_Isiah_WowYouWonHaveThese
	giveitem ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE, 1
	goto Script_LakeMeadVillage_IsiahPostBattle
	release
end

Script_LakeMeadVillage_IsiahPostBattle:
	msgbox T_LakeMeadVillage_Isiah_YouAreAStrongChampion, MSGBOX_DEFAULT
	release
end

T_LakeMeadVillage_Isiah_WoahYoureChampion:
	.string "Look at how far you've come\n"
	.string "Frito!\p"
	.string "Champion of the Niagara Region!\p"
	.string "That's awesome, I'm so happy for\n"
	.string "you buddy!$"

T_LakeMeadVillage_Isiah_HowAboutABattle:
	.string "How about a friendly battle with your\n"
	.string "best bud, me!?$"

T_LakeMeadVillage_Isiah_ComeBackWhenReady:
	.string "Scared, huh? That's okay, chicken!$"

LakeMeadVillage_Isiah_Text_Defeat:
	.string "Phew lad! No wonder you are champion!$"

T_LakeMeadVillage_Isiah_WowYouWonHaveThese:
	.string "Oh man, please take it easy on me\n"
	.string "pal!\p"
	.string "Here, take your Yu-Gi-Oh cards back!$"

T_LakeMeadVillage_Isiah_YouAreAStrongChampion:
	.string "You really are the strongest\n"
	.string "trainer I've ever seen.\p"
	.string "I'll leave my life of crime behind.\n"
	.string "No more stealing Yu-Gi-Oh cards\l"
	.string "for me, just please don't hurt\l"
	.string "me Mr. Champion Ferlito!$"


Script_LakeMeadVillage_IsiahBeforeRecievedPokeDesserChecked:
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOutDresserChecked, MSGBOX_NPC
	end
		

Script_LakeMeadVillage_NPC_IsiahTakePotion1:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOutTakePotion, MSGBOX_NPC
	end

Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked1:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_ProfIsOutTakePotionDresserchecked, MSGBOX_NPC
	end


Script_LakeMeadVillage_NPC_IsiahAfterRecievedPoke:
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_ge Script_LakeMeadVillage_IsiahAfterRecievedPokeDesserChecked
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotion2
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThem, MSGBOX_NPC
	end

Script_LakeMeadVillage_IsiahAfterRecievedPokeDesserChecked:
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked2
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThemDresserChecked, MSGBOX_NPC
	end
	
Script_LakeMeadVillage_NPC_IsiahTakePotion2:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThemTakePotion, MSGBOX_NPC
	end

Script_LakeMeadVillage_NPC_IsiahTakePotionDresserChecked2:
	removeitem ITEM_POTION, 1
	msgbox T_LakeMeadVillage_Isiah_HaventSeenThemTakePotionDresserChecked, MSGBOX_NPC
	end

Script_LMV_NPC_SoLGrunt1::
compare VAR_OLDALE_TOWN_STATE, 4
goto_if_eq Script_LMV_SaveIsiahGrunt1
msgbox T_LMV_SoLGrunt1, MSGBOX_NPC
end

Script_LMV_NPC_SoLGrunt2::
compare VAR_OLDALE_TOWN_STATE, 4
goto_if_eq Script_LMV_SaveIsiahGrunt2
msgbox T_LMV_SoLGrunt2, MSGBOX_NPC
end

//Movements

M_LMV_WasulaHelpsFro1:
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_up
walk_fastest_up
step_end


M_LMV_WasulaHelpsFro2:
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_up
walk_fastest_up
step_end

M_LMV_IsiahToFro:
walk_fastest_down
step_end

M_LMV_FroToBattlePosition:
walk_fastest_down
walk_fastest_right
face_up
step_end


M_LMV_StoneRetreat:
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
step_end

M_LMV_BudRetreat:
walk_left
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
step_end

M_LMV_CaptainExits:
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
walk_fastest_up
step_end


M_LMV_StoneDetainsIsiah:
walk_up
walk_up
walk_right
face_down
step_end



M_LMV_Soldier1CaughtIsiah:
walk_down
walk_down
walk_down
walk_down
step_end

M_LookUp:
face_up
step_end

M_LMV_IsiahCaught:
walk_down
walk_down
walk_down
walk_down
step_end


M_KidFaceLeft:
face_left
step_end

M_FroStoppedByKid:
walk_left
step_end

M_KidStopsYou:
emote_exclamation_mark
face_up
step_end

M_PlayerStopsAndTurns:
emote_question_mark
face_left
step_end

M_TilyouStopsPlayer1:
walk_up
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_TilyouWalksToLab1:
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
walk_left
face_up
step_end

M_PlayerWalksToLab1:
walk_left
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
step_end

M_TilyouStopsPlayer2:
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_TilyouWalksToLab2:
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
walk_left
face_up
step_end

M_PlayerWalksToLab2:
walk_left
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_left
walk_left
walk_left
step_end

M_TilyouEntersLab:
walk_up
step_end

M_PlayerEntersLab:
walk_left
walk_up
step_end
	
//Signposts

Script_LakeMeadVillage_FerlitoHouseholdSign::
msgbox Text_LakeMeadVillage_FerlitoHouseholdSign, MSGBOX_SIGN
end

Script_LakeMeadVillage_TilyouLabSign::
msgbox Text_LakeMeadVillage_TilyouLabSign, MSGBOX_SIGN
end

Script_LakeMeadVillage_NallsResidenceSign::
msgbox Text_LakeMeadVillage_NallsResidenceSign, MSGBOX_SIGN
end

//Text


Text_LakeMeadVillage_TilyouLabSign:
	.string "Professor Tilyou's Lab$"
	
Text_LakeMeadVillage_FerlitoHouseholdSign:
	.string "Ferlito Household$"
	
Text_LakeMeadVillage_NallsResidenceSign:
	.string "Nalls Residence$"
	
T_KidStopsYou:
	.string "Hey!\p"
	.string "Professor Tilyou is looking for \nyou.$"
	
T_NPC_LittleBoyDialouge:
	.string "I want to grow up to be the Pokémon \nChampion. \pToo bad I can't have a Pokémon \nuntil I turn 10.$" 
	
	
T_NPC_Boy1_BeforeRecievedPokemon:
	.string "Professor Tilyou has been leading \nthe field in PokéResearch. \pI'm so glad he moved here for his \nstudies. \pHe has really helped all the \naspiring young trainers get ready \lfor their journeys.$"

T_NPC_Boy1_AfterRecievedPokemon: 
	.string "It's amazing how fast the world has \nadapated to Pokémon. \pWe use them for all kinds of \nthings now like travel, law \lenforcement, and even nursing!$"
	
T_LakeMeadVillage_Isiah_ProfIsOut:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \ldoing field research and to look \lfor him on Jagow Way.$"
	
T_LakeMeadVillage_Isiah_ProfIsOutTakePotion:
	.string "Sup Fro, I came by your house to \ntell you the professor is out and \llook for him on Jagow Way.\p"
	.string "Isiah stole a potion from your bag.$"

T_LakeMeadVillage_Isiah_HaventSeenThem:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.$"
	
T_LakeMeadVillage_Isiah_HaventSeenThemTakePotion:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.\p"
	.string "Isiah stole a potion from your bag.$"
	
T_TilyouHeyWait:
	.string "Hey! Wait don't go out there!$"
	
T_TilyouTakesYouToLab:
	.string "Prof. Tilyou: You can't just go \nbee-bopping all over the place \lwithout a Pokemon.\p"
	.string "You could seriously hurt yourself.\p"
	.string "Since Pokemon were discovered \nyou're not prepared to travel in \lthe wild like you used to.\p"
	.string "Why don't you come to my lab?\n"
	.string "I have some Pokemon \lto give to aspiring trainers.\p"
	.string "Bobby and John are waiting for you \nthere so you can start your \ljourneys together.$"
	
T_LakeMeadVillage_Isiah_ProfIsOutTakePotionDresserchecked:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \llook for him on Jagow Way.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.\p" 
	.string "Isiah stole a potion from your bag.$"
	
T_LakeMeadVillage_Isiah_ProfIsOutDresserChecked:
	.string "Sup Fro, I came by your house to \ntell you the professor is out in \llook for him on Jagow Way.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.$" 
	
T_LakeMeadVillage_Isiah_HaventSeenThemDresserChecked:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.$" 
	
T_LakeMeadVillage_Isiah_HaventSeenThemTakePotionDresserChecked:
	.string "Sup Fro, glad to see \nyou found the Professor. \pI like your Pokémon.\p"
	.string "No Frodo, I haven't seen your \nYu-Gi-Oh cards.\p" 
	.string "Isiah stole a potion from your bag.$"

T_LMV_SoLGrunt1:
	.string "Hey kid, {COLOR RED}stop {COLOR DARK_GREY}bothering me. We're in\n"
	.string "the middle of very important\lresearch.$"

T_LMV_SoLGrunt2:
	.string "We're on strict orders not to let\n"
	.string "anyone into the lake are right now.\p"
	.string "We will be done soon. Please move along.$"

T_LMV_TwoSoldiersTalking:
	.string "Soldier 1: This is so boring. I wish \nwe could be doing something with a\llittle more action!\p"
	.string "Soldier 2: It might not be the most \nfun, but we can't let anyone from town\lsee what we are doing, or it could \lruin our plans.\p"
	.string "Soldier 1: Yea but this town only has \nlike 10 residents, who is going to try \lto sneak in? Besides it's not like \lthere has to be two of us here to be \lon lookout.\p"
	.string "Soldier 2: Quiet down, captain is \ncoming back.$"

T_LMV_Soldier3CaughtIsiah:
	.string "Captain: I caught this hooligan\nsneaking around. He saw the prototype.\lWhat good are you two doing guarding\lthe entrance if some kid snuck by you?\p"
	.string "Soldier 1: Sir, I... We...\p"
	.string "Captian: I don't want to hear any \nexcuses. It doesn't matter now, we \lwill just have to detain him \lindefinitely.\p"
	.string "Isiah: You can't do that! You have \nto let me go!\p"
	.string "Captain: Quiet vermin!\pStone, Bud, you're relieved of \nyour lookout duties as we are \ldone in this area anyway. \pI want you to take this child back \nto headquarters and have him locked \laway, he can't tell anyone about \lwhat he has seen. \pI'm going to go grab the rest of the \ngear and I'll meet you back at \lheadquarters.\pOh, and don't mess up this time!\p"
	.string "Stone, Granger: Yes sir, Captain\n"
	.string "Zendano!$"

T_LMV_StartBattleSequence:
	.string "Granger: Hey kid get out of the way!\nWe are in the middle of something very\limportant!\p...$"

T_LMV_SoldierBattleStart:
	.string "You can't stop us from detaining \nyour friend, he was tresspassing and \lmust be punished accordingly. \pFine, you don't want to move?\n Then we will have to make you!$"

T_LMV_JohnNotEnoughMons:
	.string "You're to weak to stop us any. \nYou don't even have two pokemon!\pNow run along and play hero somewhere else$"

T_LMV_IsiahSaved:
	.string "I can't believe we lost to a child. \nHow embarassing. \pLet's retreat back to headquarters. \nThis isn't the last you've seen of\lTeam MAGA.$"

T_LMV_JohnDefeat:
	.string "Oh, Captain is going to be so mad!$"

T_LMV_IsiahThanksFroAndBob:
	.string "Thanks Guys, you saved me! \pThat was really scary! \pYou wouldn't believe what I saw. \nI think that Team MAGA is up to \lsomething. \pMeet me at the lab, I want to tell \nProf. Tilyou about this!$"

T_LMV_IsiahNotSaved:
	.string "Bud: You're no match for team MAGA! \nHow embarassing for you. \pBobby: You think we were trying to win? \nWe were just stalling.\p"
	.string "Now your Pokemon are too weak to battle \nand I've brought 10 max revives, \lso I could quite literally do this \lall day.\p"
	.string "I also happen to know Isiah stole all \nyour healing items while we had you \ldistracted in battle, so I suggest \lyou leave unless you think you can do \lthat 10 more times without healing. \pStone: He's right, I don't have any \nhealing items! \pBud: Grrrr, Let's retreat back to \nheadquarters. \pThis isn't the last you've seen of\nTeam MAGA.$"

T_LMV_WasulaHelpsFro:
	.string "Bobby: What's going on here?\p"
	.string "Are these thugs trying to kidnap \nIsiah?\p"
	.string "Come on Fro, let's show these clowns \nwhat's up!$"
