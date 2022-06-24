CinnabarIslandHouse1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_House_1_OnLoad
	.byte 0

CinnabarIsland_House_1_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIsland_House_1_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIsland_House_1_EventScript_SetDynamicWarpPreSleep
	end

CinnabarIsland_House_1_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 33, 47
end

CinnabarIsland_House_1_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 33, 47
end