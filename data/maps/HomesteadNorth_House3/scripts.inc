HomesteadNorth_House3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Script_HomesteadNorth_House3_OnLoad
	.byte 0

Script_HomesteadNorth_House3_OnLoad:
	goto_if_set FLAG_MAGEE_VERSION, Script_HomesteadNorth_House3_SetDynamicWarpMageeVersion
	setdynamicwarp MAP_HOMESTEAD_NORTH, 255, 13, 35
	end

Script_HomesteadNorth_House3_SetDynamicWarpMageeVersion:
	setdynamicwarp MAP_MAGEE_VERSION_HOMESTEAD_TOWN_NORTH, 255, 13, 35
	end

HomesteadNorth_EventScript_StayAtHomeMan::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_WomanHaveCareerAspirations, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_WomanHaveCareerAspirations:
	.string "Last year, for Christmas, I got a\n"
	.string "framed picture of Santa Claus!\p"
	.string "My wife purchased it for me!\n"
	.string "She has always been the Career\l"
	.string "woman.\p"
	.string "Me? No, I am a stay at home dad\n"
	.string "The notion that women don't care\l"
	.string "about their career is an outdated\l"
	.string "and sexist viewpoint.$"

HomesteadNorth_EventScript_House3Woman::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_HarmfulStereotype, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_HarmfulStereotype:
	.string "I work hard so my Husband doesn't\n"
	.string "have to.\p"
	.string "It's nice to not be part of a harmful\n"
	.string "stereotype!$"

HomesteadNorth_EventScript_House3Boy::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_RebirthAndDeath, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_RebirthAndDeath:
	.string "I love Christmas as much as everyone\n"
	.string "else, but no one in this town\l"
	.string "understands its true meaning.\p"
	.string "It's about the death and rebirth of\n"
	.string "the sun!$"


