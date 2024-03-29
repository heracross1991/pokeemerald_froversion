.set LOCALID_NURSE, 1

LavaridgeTown_PokemonCenter_1F_MapScripts:: @ 81FFAFA
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_PokemonCenter_1F_OnLoad
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition: @ 81FFB05
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_PokemonCenter_1F_SetMarriottRespawn
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_PokemonCenter_1F_SetFroRespawn
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_SetMarriottRespawn:
	setrespawn HEAL_LOCATION_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT
	return

LavaridgeTown_PokemonCenter_1F_SetFroRespawn:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	return


LavaridgeTown_PokemonCenter_1F_OnLoad:
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_PokemonCenter_1F_EventScript_SetDynamicWarpMarriottVersion
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_PokemonCenter_1F_EventScript_SetDynamicWarpFroVersion
end

LavaridgeTown_PokemonCenter_1F_EventScript_SetDynamicWarpMarriottVersion:
	setdynamicwarp MAP_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT, 255, 9, 6
end

LavaridgeTown_PokemonCenter_1F_EventScript_SetDynamicWarpFroVersion:
	setdynamicwarp MAP_LAVARIDGE_TOWN, 255, 9, 6
end


LavaridgeTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FFB0E
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster:: @ 81FFB1C
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman:: @ 81FFB25
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FFB2E
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether: @ 81FFB37
	.string "I think Pokémon get closer to their\n"
	.string "Trainers if they spend time together.\p"
	.string "The longer the better.\n"
	.string "That's what I think.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate: @ 81FFBAD
	.string "It's sort of magical how just sitting\n"
	.string "in a hot-spring pool can invigorate.\p"
	.string "I wish I could let my Pokémon\n"
	.string "soak, too.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo: @ 81FFC21
	.string "Hohoho! Hey, kid, you can reach\n"
	.string "the hot springs from here.\p"
	.string "If Pokémon are getting rest, so too\n"
	.string "should their Trainers.$"

