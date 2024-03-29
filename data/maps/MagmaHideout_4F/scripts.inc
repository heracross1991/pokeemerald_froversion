.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts:: @ 823A55F
	.byte 0

MagmaHideout_4F_EventScript_Maxie:: @ 823A560
	lockall
	setrespawn HEAL_LOCATION_MAGMA_HIDEOUT_4F
	playbgm MUS_ENCOUNTER_MAGMA, 0
	goto_if_set FLAG_RED_EYES_FLY_AWAY, MagmaHideout_4F_EventScript_ZendanoBattle
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_MUGSHOT_ID, MUGSHOT_ZENDANO
	setflag FLAG_RED_EYES_FLY_AWAY
	goto MagmaHideout_4F_EventScript_ZendanoBattle
	releaseall
	end

MagmaHideout_4F_EventScript_ZendanoBattle:
	goto_if_defeated TRAINER_MAXIE_MAGMA_HIDEOUT MagmaHideout_4F_EventScript_ZendanoBattle2
	trainerbattle_double TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieOhItWasYou, MagmaHideout_4F_Text_MaxieDefeat, Route104_Text_GinaNotEnoughMons, MagmaHideout_4F_EventScript_ZendanoBattle2
	end

MagmaHideout_4F_EventScript_ZendanoBattle2:
	special HealPlayerParty
	trainerbattle_double TRAINER_MAGMA_HIDEOUT_MEGA_GENGAR, MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MagmaHideout_4F_Text_MaxieDefeat, Route104_Text_GinaNotEnoughMons, MagmaHideout_4F_EventScript_ZendanoBattle3
	end
	
MagmaHideout_4F_EventScript_ZendanoBattle3:
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach: @ 823A672
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit: @ 823A67D
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround: @ 823A680
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11:: @ 823A68C
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12:: @ 823A6A3
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13:: @ 823A6BA
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha:: @ 823A6D1
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro: @ 823A6E8
	.string "I want to see Voeyedra, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about Voeyedra!$"

MagmaHideout_4F_Text_Grunt11Defeat: @ 823A775
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle: @ 823A7B5
	.string "I wonder if Voeyedra even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro: @ 823A7DA
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat: @ 823A81B
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_Grunt12PostBattle: @ 823A841
	.string "Zendano, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro: @ 823A86D
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_Grunt13Defeat: @ 823A8A7
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle: @ 823A8C6
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_TabithaIntro: @ 823A8E1
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, Voeyedra is sleeping!\p"
	.string "Zendano went to Voeyedra just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat: @ 823A994
	.string "Taken down again…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle: @ 823A9AC
	.string "…And while you wasted time with me,\n"
	.string "Zendano should have awakened Voeyedra…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon: @ 823A9F4
	.string "Zendano: Voeyedra…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This Blue Orb is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the Blue Orb.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong: @ 823AADA
	.string "Zendano: Voeyedra!\n"
	.string "What's wrong?\p"
	.string "Wasn't the Blue Orb the key?\p"
	.string "Voeyedra!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_MaxieOhItWasYou: @ 823AB33
	.string "Zendano: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"

MagmaHideout_4F_Text_MaxieDefeat: @ 823ABB5
	.string "What makes you so adept at handling\n"
	.string "Pokémon?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon: @ 823ABE2
	.string "Zendano: There has to be some reason\n"
	.string "why Voeyedra fled…\p"
	.string "That's what you're trying to say,\n"
	.string "aren't you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "You think I didn't know that?\p"
	.string "With Voeyedra gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after Voeyedra, so this\n"
	.string "is where we part!$"

///////////FROVERSION//////////////

MagmaHideout_EventScript_Amneet::
	lock
	faceplayer
	pokemart MagmaHideout_Pokemart_Amneet
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MagmaHideout_Pokemart_Amneet:
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

MagmaHideout_EventScript_Porygon::
	lock
	playmoncry SPECIES_PORYGON, 0
	scrollingmultichoice 9, 2, 3, 3, TRUE
	compare VAR_RESULT, 0
	goto_if_eq Eventscript_Porygon_PCMainMenu
	compare VAR_RESULT, 1
	goto_if_eq MagmaHideout_EventScript_Amneet
	compare VAR_RESULT, 2
	goto_if_eq BossBattleMoveRelearner
	release
	end

MagmaHideout_EventScript_ChanseyHeal::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, 0
	setrespawn HEAL_LOCATION_MAGMA_HIDEOUT_4F
	msgbox SummitCaverns_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCaverns_EventScript_Rest
	closemessage
	release
	end