MountCinnabar_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MountCinnabar_1F_OnLoad
	.byte 0

MountCinnabar_1F_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge MountCinnabar_1F_EventScript_SetDynamicWarpPostSleep
	call_if_lt MountCinnabar_1F_EventScript_SetDynamicWarpPreSleep
	end

MountCinnabar_1F_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 42, 27
end

MountCinnabar_1F_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 42, 27
end
