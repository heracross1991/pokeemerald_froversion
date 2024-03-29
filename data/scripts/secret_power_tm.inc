Route111_Text_MakingRoomUseTMToMakeYourOwn: @ 82762C9
	.string "What's that?\n"
	.string "What am I doing?\p"
	.string "I'm thinking about building a\n"
	.string "barrier using a Pokémon move.\p"
	.string "I know! I'll give you this TM.\n"
	.string "Will you use it build a barrier?$"

Route111_Text_ExplainSecretPower: @ 827636E
	.string "This TM04 Contains Calm Mind.\p"
	.string "It raises your Pokémon's SpAtk\n"
	.string "and SpDef.\p"
	.string "It's really good for Pokémon with\n"
	.string "a strong constitution.$"

Route111_Text_DontWantThis: @ 827655C
	.string "Oh, you don't want this?\n"
	.string "If you change your mind, tell me, okay?$"

Route111_Text_DontHaveAnyRoom: @ 827659D
	.string "Oh, you don't have any room for this.\p"
	.string "I'll hold on to it, so come back for it\n"
	.string "another time, okay?$"

Route111_EventScript_SecretPowerMan:: @ 82765FF
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower:: @ 827661E
	giveitem ITEM_TM04
	compare VAR_RESULT, FALSE
	goto_if_eq Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	compare VAR_FACING, DIR_WEST
	call_if_eq Route111_EventScript_SecretPowerManExit
	compare VAR_FACING, DIR_EAST
	call_if_eq Route111_EventScript_SecretPowerManExit
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit:: @ 827666A
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth:: @ 8276675
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower:: @ 8276680
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit: @ 827668A
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth: @ 8276696
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
