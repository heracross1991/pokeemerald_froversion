FallarborTown_TrainerHouse_MapScripts::
	.byte 0


FallarborTown_TrainerHouse_EventScript_RichBoy::
	lock
	goto_if_set FLAG_SYS_GAME_CLEAR, FallarborTown_TrainerHouse_EventScript_RichBoy_ChampionBattle
	goto_if_set FLAG_BADGE08_GET, FallarborTown_TrainerHouse_EventScript_RichBoy_8_BadgeBattle
	goto_if_set FLAG_BADGE07_GET, FallarborTown_TrainerHouse_EventScript_RichBoy_7_BadgeBattle
	goto_if_set FLAG_BADGE06_GET, FallarborTown_TrainerHouse_EventScript_RichBoy_6_BadgeBattle
	goto_if_set FLAG_BADGE05_GET, FallarborTown_TrainerHouse_EventScript_RichBoy_5_BadgeBattle
	goto_if_set FLAG_BADGE04_GET, FallarborTown_TrainerHouse_EventScript_RichBoy_4_BadgeBattle
	goto_if_set FLAG_BADGE03_GET, FallarborTown_TrainerHouse_EventScript_RichBoy_3_BadgeBattle
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_ChampionBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_CHAMPION, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_8_BadgeBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_8_BADGES, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_7_BadgeBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_7_BADGES, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_6_BadgeBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_6_BADGES, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_5_BadgeBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_5_BADGES, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_4_BadgeBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_4_BADGES, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_RichBoy_3_BadgeBattle::
	trainerbattle_single TRAINER_RICH_BOY_TRAINERS_HALL_3_BADGES, FallarborTown_Text_RichBoyIntro, FallarborTown_Text_RichBoyDefeat
	msgbox FallarborTown_Text_RichBoyPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass::
	lock
	goto_if_set FLAG_SYS_GAME_CLEAR, FallarborTown_TrainerHouse_EventScript_Lass_ChampionBattle
	goto_if_set FLAG_BADGE08_GET, FallarborTown_TrainerHouse_EventScript_Lass_8_BadgeBattle
	goto_if_set FLAG_BADGE07_GET, FallarborTown_TrainerHouse_EventScript_Lass_7_BadgeBattle
	goto_if_set FLAG_BADGE06_GET, FallarborTown_TrainerHouse_EventScript_Lass_6_BadgeBattle
	goto_if_set FLAG_BADGE05_GET, FallarborTown_TrainerHouse_EventScript_Lass_5_BadgeBattle
	goto_if_set FLAG_BADGE04_GET, FallarborTown_TrainerHouse_EventScript_Lass_4_BadgeBattle
	goto_if_set FLAG_BADGE03_GET, FallarborTown_TrainerHouse_EventScript_Lass_3_BadgeBattle
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_ChampionBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_CHAMPION, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_8_BadgeBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_8_BADGES, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_7_BadgeBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_7_BADGES, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_6_BadgeBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_6_BADGES, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_5_BadgeBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_5_BADGES, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_4_BadgeBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_4_BADGES, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Lass_3_BadgeBattle::
	trainerbattle_single TRAINER_LASS_TRAINERS_HALL_3_BADGES, FallarborTown_Text_LassIntro, FallarborTown_Text_LassDefeat
	msgbox FallarborTown_Text_LassPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman::
	lock
	goto_if_set FLAG_SYS_GAME_CLEAR, FallarborTown_TrainerHouse_EventScript_Gentleman_ChampionBattle
	goto_if_set FLAG_BADGE08_GET, FallarborTown_TrainerHouse_EventScript_Gentleman_8_BadgeBattle
	goto_if_set FLAG_BADGE07_GET, FallarborTown_TrainerHouse_EventScript_Gentleman_7_BadgeBattle
	goto_if_set FLAG_BADGE06_GET, FallarborTown_TrainerHouse_EventScript_Gentleman_6_BadgeBattle
	goto_if_set FLAG_BADGE05_GET, FallarborTown_TrainerHouse_EventScript_Gentleman_5_BadgeBattle
	goto_if_set FLAG_BADGE04_GET, FallarborTown_TrainerHouse_EventScript_Gentleman_4_BadgeBattle
	goto_if_set FLAG_BADGE03_GET, FallarborTown_TrainerHouse_EventScript_Gentleman_3_BadgeBattle
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_ChampionBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_CHAMPION, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_8_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_8_BADGES, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_7_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_7_BADGES, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_6_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_6_BADGES, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_5_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_5_BADGES, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_4_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_4_BADGES, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman_3_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_TRAINERS_HALL_3_BADGES, FallarborTown_Text_GentlemanIntro, FallarborTown_Text_GentlemanDefeat
	msgbox FallarborTown_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2::
	lock
	goto_if_set FLAG_SYS_GAME_CLEAR, FallarborTown_TrainerHouse_EventScript_Gentleman2_ChampionBattle
	goto_if_set FLAG_BADGE08_GET, FallarborTown_TrainerHouse_EventScript_Gentleman2_8_BadgeBattle
	goto_if_set FLAG_BADGE07_GET, FallarborTown_TrainerHouse_EventScript_Gentleman2_7_BadgeBattle
	goto_if_set FLAG_BADGE06_GET, FallarborTown_TrainerHouse_EventScript_Gentleman2_6_BadgeBattle
	goto_if_set FLAG_BADGE05_GET, FallarborTown_TrainerHouse_EventScript_Gentleman2_5_BadgeBattle
	goto_if_set FLAG_BADGE04_GET, FallarborTown_TrainerHouse_EventScript_Gentleman2_4_BadgeBattle
	goto_if_set FLAG_BADGE03_GET, FallarborTown_TrainerHouse_EventScript_Gentleman2_3_BadgeBattle
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_ChampionBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_CHAMPION, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_8_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_8_BADGES, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_7_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_7_BADGES, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_6_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_6_BADGES, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_5_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_5_BADGES, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_4_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_4_BADGES, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

FallarborTown_TrainerHouse_EventScript_Gentleman2_3_BadgeBattle::
	trainerbattle_single TRAINER_GENTLEMAN_2_TRAINERS_HALL_3_BADGES, FallarborTown_Text_Gentleman2Intro, FallarborTown_Text_Gentleman2Defeat
	msgbox FallarborTown_Text_Gentleman2PostBattle, MSGBOX_AUTOCLOSE
	release
end

////////////////////////////////////////////
////////////////////Texts///////////////////
////////////////////////////////////////////

FallarborTown_Text_RichBoyIntro:	
	.string "I'm an exclusive member!$"

FallarborTown_Text_RichBoyDefeat:
	.string "My family bought my membership...$"

FallarborTown_Text_RichBoyPostBattle:
	.string "If you leave and come back I'll\n"
	.string "rematch you!$"

FallarborTown_Text_LassIntro:
	.string "My looks compensate for my brians.$"

FallarborTown_Text_LassDefeat:
	.string "Or is it brains?$"

FallarborTown_Text_LassPostBattle:
	.string "I should really taking grammer lessons.$"

FallarborTown_Text_GentlemanIntro:
	.string "You look like my Grandson.$"

FallarborTown_Text_GentlemanDefeat:
	.string "Well, when I put my glasses on\n"
	.string "you look less like my grandson\l"
	.string "and more like my Son!$"

FallarborTown_Text_GentlemanPostBattle:
	.string "That's all the juice I've got now\n"
	.string "Sonny!$"

FallarborTown_Text_Gentleman2Intro:
	.string "I run this house.\n"
	.string "Lets see what you are capable\l"
	.string "of.\p"
	.string "Bitch.$"

FallarborTown_Text_Gentleman2Defeat:
	.string "You must have cheated. I do\n"
	.string "not condone cheating.\p"
	.string "Leave my house at once!$"

FallarborTown_Text_Gentleman2PostBattle:
	.string "GET OUT!!!!!!!$"
