MarriottIntroFrame5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame5_OnFrame
	.byte 0

MarriottIntroFrame5_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MarriottIntroFrame5_EventScript_MarriottStudies
	.2byte 0

MarriottIntroFrame5_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame5_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_MARRIOTT_INTRO_FRAME6, 255, 7, 5 
	release
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''
MarriottIntroFrame5_Text_MarriottStudies:
	.string "As he traveled the world he got further\n"
	.string "from his Hometown of Linwood.\p"
	.string "He eventually came across the Town of\n"
	.string "Grand Island.$"
