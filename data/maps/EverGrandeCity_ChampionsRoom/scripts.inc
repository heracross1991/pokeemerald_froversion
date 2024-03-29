.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts:: @ 82289EF
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition: @ 82289FF
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp: @ 8228A05
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth:: @ 8228A0F
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame: @ 8228A14
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom:: @ 8228A1E
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
    releaseall
    end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace: @ 8228A42
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace:: @ 8228A45
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	switch VAR_STARTER_MON
	case 0, ChampionsHall_EventScript_BattleJohnTreecko
	case 1, ChampionsHall_EventScript_BattleJohnMudkip
	case 2, ChampionsHall_EventScript_BattleJohnTorchic
	end
	
ChampionsHall_EventScript_BattleJohnTreecko:
	trainerbattle_no_intro TRAINER_JOHN_CHAMPIONS_HALL_TREECKO, Text_ChampionsHall_JohnDefeated
	goto EverGrandeCity_ChampionsRoom_EventScript_NotRealChampion
	end

ChampionsHall_EventScript_BattleJohnMudkip:
	trainerbattle_no_intro TRAINER_JOHN_CHAMPIONS_HALL_MUDKIP, Text_ChampionsHall_JohnDefeated
	goto EverGrandeCity_ChampionsRoom_EventScript_NotRealChampion
	end

ChampionsHall_EventScript_BattleJohnTorchic:
	trainerbattle_no_intro TRAINER_JOHN_CHAMPIONS_HALL_TORCHIC, Text_ChampionsHall_JohnDefeated
	goto EverGrandeCity_ChampionsRoom_EventScript_NotRealChampion
	end

EverGrandeCity_ChampionsRoom_EventScript_NotRealChampion:
	msgbox Text_ChampionsHall_NotRealChampion, MSGBOX_DEFAULT
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	msgbox Text_ChampionsHall_BobbyRevealChampion, MSGBOX_DEFAULT
	special HealPlayerParty
	switch VAR_STARTER_MON
	case 0, Script_ChampionsHall_WasulaBattleFlobra //fros starter is rascaloot
	case 1, Script_ChampionsHall_WasulaBattleEmboryps //fros starter is flobra
	case 2, Script_ChampionsHall_WasulaBattleRascaloot //fros starter is emboryps
	//trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	//goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

Script_ChampionsHall_WasulaBattleFlobra:
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Text_SummitCave_BobbyDefeated
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

Script_ChampionsHall_WasulaBattleRascaloot:
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Text_SummitCave_BobbyDefeated
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

Script_ChampionsHall_WasulaBattleEmboryps:
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Text_SummitCave_BobbyDefeated
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated:: @ 8228A61
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, 0
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
//	addobject LOCALID_RIVAL
//f	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	compare VAR_RESULT, FEMALE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic:: @ 8228ABC
	playbgm MUS_ENCOUNTER_MAY, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic:: @ 8228AC1
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice:: @ 8228AC6
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice:: @ 8228AFB
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF:: @ 8228B30
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	compare VAR_RESULT, FEMALE
	call_if_eq EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_MATTS_ROOM, 255, 9, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations:: @ 8228BEB
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations:: @ 8228BF4
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer:: @ 8228BFD
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth:: @ 8228C12
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart: @ 8228C1D
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit: @ 8228C20
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer: @ 8228C26
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_fastest_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth: @ 8228C2F
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows: @ 8228C38
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart: @ 8228C3B
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit: @ 8228C3F
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives: @ 8228C43
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech: @ 8228C4C
	.string "John: Welcome, {PLAYER}{KUN}.\p"
	.string "That incident in Homestead Town…\n"
	.string "That was superb work, putting an end\l"
	.string "to that crisis all by yourself.\p"
	.string "Oops!\p"
	.string "It wouldn't be fair to say that you\n"
	.string "alone ended the crisis.\p"
	.string "You overcame that difficult situation\n"
	.string "by working as one with your Pokémon.\p"
	.string "We Trainers raise Pokémon by giving\n"
	.string "them items and by teaching them new\l"
	.string "techniques for battle.\p"
	.string "But we ourselves also learn many\n"
	.string "things from Pokémon.\p"
	.string "And this is where your achievements\n"
	.string "are put to the test against what\l"
	.string "others like you have achieved.\p"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their Pokémon in Niagara?\p"
	.string "Show me right here and now!$"

EverGrandeCity_ChampionsRoom_Text_Defeat: @ 8228EAC
	.string "I, the Champion, fall in defeat…\p"
	.string "That was wonderful work.\n"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a truly noble Pokémon\n"
	.string "Trainer!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech: @ 8228F66
	.string "John: The Pokémon you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your Pokémon.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You now stand at the glorious peak\n"
	.string "of the Pokémon League.\p"
	.string "I now proclaim you to be the new\n"
	.string "Niagara region…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice: @ 82290CA
	.string "Bobby: {PLAYER}{KUN}!\p"
	.string "That was impressive.\p"
	.string "You battled with such heart…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver: @ 822910B
	.string "Could it be that…\n"
	.string "It's already over?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice: @ 8229152
	.string "BRENDAN: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the Champion?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon: @ 82291A2
	.string "BRENDAN: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the Champion?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex: @ 82291E6
	.string "Prof. Tilyou: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the Lynch Park,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the Champion!\p"
	.string "Ah, yes!\p"
	.string "What became of your Pokédex?\n"
	.string "Here, let me see.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations: @ 822934D
	.string "Prof. Tilyou: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe: @ 8229399
	.string "John: {PLAYER}{KUN}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new Champion!\p"
	.string "Come with me.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside: @ 82293EB
	.string "John: I'm sorry, but…\p"
	.string "From here on, only the current\n"
	.string "Champion and I may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "Prof. Tilyou.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations: @ 8229479
	.string "Bobby: Groan…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I'm just joking! That's okay!\n"
	.string "That's the rule!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Honestly, congratulations!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations: @ 82294F5
	.string "BRENDAN: Whaaaat?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "It can't be helped if that's the rule.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"

Text_ChampionsHall_JohnDefeated:
	.string "Wtf!?$"

Text_ChampionsHall_NotRealChampion:
	.string "Woah, nice battle {PLAYER}!\p"
	.string "I'd love to tell you that you\n"
	.string "are now League Champion but...$"

Text_ChampionsHall_BobbyRevealChampion:
	.string "Bobby: Fro! Look at how far you\n"
	.string "have come!\p"
	.string "You beat the Champion. Or rather,\n"
	.string "the previous Champion!\p"
	.string "I beat John right before you got\n"
	.string "here to claim the title for myself.\p"
	.string "I know you haven't come this far to\n"
	.string "turn back, may the best trainer win!$"
