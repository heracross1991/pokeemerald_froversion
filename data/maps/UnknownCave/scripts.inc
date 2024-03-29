UnknownCave_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UnknownCave_OnFrame
	.byte 0

UnknownCave_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 7, Script_UnknownCave_PostGameEvent //Froversion Script
	map_script_2 VAR_ROUTE101_STATE, 0, Script_UnknownCave_BossBattleTestSetup //Script for boss battle
	.2byte 0
	
Script_UnknownCave_PostGameEvent:
	lock
	msgbox UnknownCave_Text_PlayerWokeUpInCave, MSGBOX_DEFAULT
	setvar VAR_ROUTE101_STATE, 8
	release
	end

Script_UnknownCave_BossBattleTestSetup:
	setflag FLAG_SYS_POKEMON_GET
	msgbox PleaseBePatient, MSGBOX_DEFAULT
	givecustommon SPECIES_LUTRADOR, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_FLING, MOVE_AQUA_JET, MOVE_COVET, MOVE_REVENGE, 0
	givecustommon SPECIES_CLEFABLE, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_MOONBLAST, MOVE_MOONLIGHT, MOVE_COSMIC_POWER, MOVE_STORED_POWER, 0 
	givecustommon SPECIES_ARIADOS, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_POISON_JAB, MOVE_PSYCHIC, MOVE_PIN_MISSILE, MOVE_AGILITY, 0 
	givecustommon SPECIES_MACHAMP, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_CROSS_CHOP, MOVE_BULK_UP, MOVE_DUAL_CHOP, MOVE_SUBMISSION, 0 
	givecustommon SPECIES_GOLEM, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_DOUBLE_EDGE, MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, 0 
	givecustommon SPECIES_MAROWAK, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_STOMPING_TANTRUM, MOVE_DOUBLE_EDGE, MOVE_FLING, MOVE_THRASH, 0 
	givecustommon SPECIES_CRADILY, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_GRASSY_TERRAIN, MOVE_ENERGY_BALL, MOVE_AMNESIA, MOVE_GASTRO_ACID, 0
	givecustommon SPECIES_LUNATONE, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_MAGIC_ROOM, MOVE_EXPLOSION, MOVE_PSYCHIC_TERRAIN, MOVE_FUTURE_SIGHT, 0 
	givecustommon SPECIES_SOLROCK, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_WONDER_ROOM, MOVE_EXPLOSION, MOVE_SOLAR_BEAM, MOVE_STONE_EDGE, 0 
	givecustommon SPECIES_AZUMARILL, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_SUPERPOWER, MOVE_DOUBLE_EDGE, MOVE_RAIN_DANCE, MOVE_AQUA_RING, 0 
	givecustommon SPECIES_POLIWRATH, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_HYDRO_PUMP, MOVE_WAKE_UP_SLAP, MOVE_BELLY_DRUM, MOVE_MUD_SHOT, 0 
	givecustommon SPECIES_MILOTIC, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_COIL, MOVE_SAFEGUARD, 0 
	givecustommon SPECIES_SANDSLASH, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_SANDSTORM, MOVE_GYRO_BALL, MOVE_SWORDS_DANCE, MOVE_DIG, 0 
	givecustommon SPECIES_WARTHAAG, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_EARTHQUAKE, MOVE_THRASH, MOVE_SAND_TOMB, MOVE_CRUNCH, 0 
	givecustommon SPECIES_SCYTHER, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_AIR_SLASH, MOVE_NIGHT_SLASH, MOVE_DOUBLE_HIT, MOVE_X_SCISSOR, 0 
	givecustommon SPECIES_SCIZOR, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_IRON_HEAD, MOVE_NIGHT_SLASH, MOVE_DOUBLE_HIT, MOVE_X_SCISSOR, 0 
	givecustommon SPECIES_CRACKTUSS, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_SPIKES, MOVE_ROCK_BLAST, MOVE_GROWTH, MOVE_INGRAIN, 0 
	givecustommon SPECIES_HOUNDOOM, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_FLAMETHROWER, MOVE_FOUL_PLAY, MOVE_SUNNY_DAY, MOVE_WILL_O_WISP, 0 
	givecustommon SPECIES_UMBREON, 50, ITEM_NONE , ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_ELECTRIC_TERRAIN, MOVE_ASSURANCE, MOVE_SCREECH, MOVE_LAST_RESORT, 0 
	givecustommon SPECIES_GLALIE, 50, ITEM_NONE, ITEM_POKE_BALL, NATURE_HARDY, 1, 84, 84, 84, 84, 84, 84, 15, 15, 15, 15, 15, 15, MOVE_HAIL, MOVE_BLIZZARD, MOVE_CRUNCH, MOVE_FROST_BREATH, 0
	setvar VAR_ROUTE101_STATE, 1
	release
	end
		

UnknownCave_Text_PlayerWokeUpInCave:
	.string "After the events on Cinnabar\n"
	.string "{PLAYER} woke up in a cave\l"
	.string "with no recollection of what\l"
	.string "happened or how he ended up here.$"

PleaseBePatient:
	.string "Please be Patient, loading Pokémon\n"
	.string "into party and pc.$"
	