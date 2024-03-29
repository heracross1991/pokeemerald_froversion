.set LOCALID_NURSE, 1
.set LOCALID_AQUA_GUARD, 4


////////////////////////////////////
//////////MAP SCRIPTS//////////////
//////////////////////////////////


RaintreeIsland_Gym_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RaintreeIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RaintreeIsland_PokemonCenter_1F_OnTransition: @ 81FC52E
	setrespawn HEAL_LOCATION_RAINTREE_ISLAND
	call Common_EventScript_UpdateBrineyLocation
	end


////////////////////////////////////
//////////Scripts//////////////////
//////////////////////////////////

GymLobby_EventScript_Dwight::
	lock
	msgbox Text_Dwight, MSGBOX_DEFAULT
	release
	end

GymLobby_EventScript_Chad::
	lock
	msgbox Text_Chad, MSGBOX_DEFAULT
	release
	end

GymLobby_EventScript_Mike::
	lock
	msgbox Text_Mike, MSGBOX_DEFAULT
	release
	end

GymLobby_EventScript_John::
	lock
	msgbox Text_John, MSGBOX_DEFAULT
	release
	end

GymLobby_EventScript_GuardFrosty::
	lock
	msgbox Text_GuardFrosty, MSGBOX_DEFAULT
	release
	end

GymLobby_EventScript_GuardHot::
	lock
	msgbox Text_GuardHot, MSGBOX_DEFAULT
	release
	end


GymLobby_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

GymLobby_Mart_EventScript_BattleItemsClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GymLobby_BattleItems_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
end

.align 2
GymLobby_BattleItems_Mart_Pokemart:
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_NONE
	release
	end

GymLobby_Mart_EventScript_HealingItemsClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GymLobby_HealingItems_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
GymLobby_HealingItems_Mart_Pokemart:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_NONE
	release
	end

/////////////////////////////////////
/////////////Movements//////////////
///////////////////////////////////

/////////////////////////////////////
/////////////Texts//////////////////
///////////////////////////////////

RaintreeIsland_Text_GymEntranceRoom_GuardTellsPlayerHeCanEnter:
	.string "Are you {PLAYER}?\p"
	.string "Okay, great! You're next on the \n"
	.string "waiting list!\p"
	.string "Now at this gym, we do things a\n"
	.string "little differently...\p"
	.string "First, you can't use any of your own\n"
	.string "Pokemon.\p"
	.string "You you must speak with our rental\n"
	.string "agent, and he will let you use some\l"
	.string "of our's.\p"
	.string "Once you obtain your rental Pokemon,\n"
	.string "make whatever preperations you need,\l"
	.string "and then you may enter to begin the\l"
	.string "challenge.\p"
	.string "Good luck, stay frosty.$"

Text_GuardFrosty:
	.string "Make whatever preperations you need,\n"
	.string "and then you may enter to begin the\l"
	.string "challenge.\p"
	.string "Good luck, stay frosty.$"

Text_GuardHot:
	.string "Make whatever preperations you need,\n"
	.string "and then you may enter to begin the\l"
	.string "challenge.\p"
	.string "Good luck, stay sunny.$"

Text_John:
	.string "Did you know that you can change\n"
	.string "your Pokemon's ability right from\l"
	.string "the party menu?\p"
	.string "How cool is that?$"

Text_Chad:
	.string "I tried the Gym Challenge, but I\n"
	.string "just couldn't beat the leader.\p"
	.string "He wouldn't let me use my items\n"
	.string "in battle, it really threw me off!$"

Text_Mike:
	.string "I traveled all the way from\n"
	.string "Homestead Town.\p"
	.string "Now that they Pandemic is\n"
	.string "slowing down they are allowing\l"
	.string "people in and out!$"

Text_Dwight:
	.string "Word around town is the original\n"
	.string "plan was to constuct this gym over\l"
	.string "course of a month.\p"
	.string "However, the workers ended up\n"
	.string "procrastinating and had to do it\l"
	.string "all in the last week.\p"
	.string "Hopefully they didn't make any grave\n"
	.string "mistakes!$"
