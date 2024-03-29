.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

Route119_WeatherInstitute_2F_MapScripts:: @ 826FF1E
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition: @ 826FF24
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere:: @ 826FF44
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone:: @ 826FF50
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear:: @ 826FF5C
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5:: @ 826FF68
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2:: @ 826FF7F
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3:: @ 826FF96
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly:: @ 826FFAD
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated:: @ 826FFC8
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform:: @ 827004D
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 25, ITEM_EVIOLITE
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty:: @ 8270085
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC:: @ 82700AD
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare:: @ 82700DB
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_EEVEE
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform:: @ 82700EA
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather:: @ 82700F7
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather:: @ 827010A
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	compare VAR_0x8004, 2  @ Both defeated
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather:: @ 827014F
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather:: @ 8270159
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated:: @ 8270160
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather:: @ 8270166
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	goto Route119_WeatherInstitute_2F_EventScript_EeveesForSale
	release
	end

Route119_WeatherInstitute_2F_EventScript_EeveesForSale::
	lock
	msgbox Route119_WeatherInstitute_2F_Text_EeveesForSale, MSGBOX_YESNO
	compare VAR_RESULT, NO 
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_EeveeDeclined
	checkmoney 75000, 0
	compare VAR_RESULT, FALSE
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_NotEnoughMoney
	removemoney 75000, 0
	random 9
	switch VAR_RESULT
	case 0, Route119_WeatherInstitute_2F_EventScript_EeveePurchase1
	case 1, Route119_WeatherInstitute_2F_EventScript_EeveePurchase2
	case 2, Route119_WeatherInstitute_2F_EventScript_EeveePurchase3
	case 3, Route119_WeatherInstitute_2F_EventScript_EeveePurchase4
	case 4, Route119_WeatherInstitute_2F_EventScript_EeveePurchase5
	case 5, Route119_WeatherInstitute_2F_EventScript_EeveePurchase6
	case 6, Route119_WeatherInstitute_2F_EventScript_EeveePurchase7
	case 7, Route119_WeatherInstitute_2F_EventScript_EeveePurchase8
	case 8, Route119_WeatherInstitute_2F_EventScript_EeveePurchase9
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase1:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_NAUGHTY,1,252,0,252,0,0,0,31,31,31,31,31,31, MOVE_QUIVER_DANCE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 1
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase2:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_BRAVE,1,0,252,0,252,0,0,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase3:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_RASH,1,0,0,252,0,252,0,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase4:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_SASSY,1,0,0,0,252,0,252,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase5:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_HARDY,1,252,0,252,0,0,0,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase6:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_BOLD,1,0,252,252,0,0,0,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase7:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_TIMID,1,0,0,252,252,0,0,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase8:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_JOLLY,1,0,0,252,252,0,0,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveePurchase9:
	givecustommon SPECIES_EEVEE ,25, ITEM_QUICK_CLAW, ITEM_POKE_BALL, NATURE_CAREFUL,1,0,0,252,0,0,252,31,31,31,31,31,31, MOVE_TACKLE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE, 0
	msgbox Route119_WeatherInstitute_2F_Text_EeveeAccepted, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_NotEnoughMoney:
	msgbox Route119_WeatherInstitute_2F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
end

Route119_WeatherInstitute_2F_EventScript_EeveeDeclined:
	msgbox Route119_WeatherInstitute_2F_Text_EeveeDeclined, MSGBOX_DEFAULT
	release
end
	

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly: @ 8270170
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay: @ 827017C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_fastest_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition: @ 8270184
	slide_down
	walk_in_place_fastest_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer: @ 8270187
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist:: @ 827018B
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro: @ 827019C
	.string "The Institute has a special\n"
	.string "Pokémon that has something to do with\l"
	.string "Team MAGA's Plans.\p"
	.string "We're here to take them before Team\n"
	.string "MAGA can get their hands on them!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat: @ 8270208
	.string "Our plan's being spoiled by a kid?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle: @ 827022B
	.string "If the Pokémon they made here can\n"
	.string "help team MAGA, then we of\l"
	.string "Antifa definitely need it!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro: @ 8270292
	.string "We're Antifa!\n"
	.string "We appear wherever Team MAGA is\l"
	.string "snooping around!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat: @ 82702CE
	.string "You got me!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle: @ 82702DA
	.string "You don't have any idea what we of\n"
	.string "Antifa are working towards!\l"
	.string "You stay out of our way!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro: @ 8270335
	.string "Don't tell me you're looking for that\n"
	.string "special Pokémon, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat: @ 827039F
	.string "Oh, will you look at my Pokémon?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle: @ 82703C0
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro: @ 8270409
	.string "Ahahahaha!\p"
	.string "You're going to meddle in Antifa's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat: @ 82704BD
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle: @ 82704E4
	.string "It's bad enough to have Team MAGA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy: @ 8270568
	.string "We have a situation here!\p"
	.string "A Team MAGA mob just passed\n"
	.string "the Weather Institute.\p"
	.string "They appear to be headed for\n"
	.string "Mt. Pyre!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre: @ 82705DD
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to Mt. Pyre, too!\p"
	.string "Ahahahaha!\n"
	.string "Team MAGA, just you wait!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon: @ 8270650
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this Pokémon.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon: @ 82706B2
	.string "Hm? You don't seem to have any room\n"
	.string "for this Pokémon.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform: @ 82706E8
	.string "{PLAYER} received Eevee!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather: @ 82706FE
	.string "That Pokémon can evolve into many\n"
	.string "different forms. Each form has an\l"
	.string "impact to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "Institute--go ahead and take it.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous: @ 827077E
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather: @ 82707F1
	.string "I track weather patterns over\n"
	.string "the Niagara region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather: @ 8270873
	.string "I track weather patterns over\n"
	.string "the Niagara region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather: @ 82708FC
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

Route119_WeatherInstitute_2F_Text_EeveesForSale:
	.string "Now that the abnormal weather has\n"
	.string "cleared up, I have time to resume my\l"
	.string "side gig!\p"
	.string "How would you like to buy a pure bred\n"
	.string "Eevee for only 75000?$"

Route119_WeatherInstitute_2F_Text_EeveeDeclined:
	.string "Okay then... Come back if\n"
	.string "you change your mind...$"

Route119_WeatherInstitute_2F_Text_EeveeAccepted:
	.string "Excellent. Here you go! This\n"
	.string "money will go towards research!$"

Route119_WeatherInstitute_2F_Text_NotEnoughMoney:
	.string "Please don't waste my time.\n"
	.string "If you're serious, come back with\l"
	.string "enough money.$"