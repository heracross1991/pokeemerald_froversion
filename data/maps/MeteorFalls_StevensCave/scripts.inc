.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts:: @ 823B181
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven:: @ 823B182
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	setflag FLAG_BATTLE_TYPE_WEATHER
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	msgbox MeteorFalls_StevensCave_Text_TakeThese, MSGBOX_DEFAULT
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	clearflag FLAG_BATTLE_TYPE_WEATHER
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated:: @ 823B1CD
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	clearflag FLAG_BATTLE_TYPE_WEATHER
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst: @ 823B1E1
	.string "Mike: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"

MeteorFalls_StevensCave_Text_StevenDefeat: @ 823B32D
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue: @ 823B358
	.string "Mike: Come to think of it, ever since\n"
	.string "our paths first crossed in Granite\l"
	.string "Cave in Raintree, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the Champion.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"

MeteorFalls_StevensCave_Text_TakeThese:
	.string "Here, let me give you a little something.\n"
	.string "These steel tips attach to the end of\l"
	.string "your Running Shoes. You should be able\l"
	.string "Do some damage with them.$"

