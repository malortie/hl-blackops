@setlocal
@prompt $
@echo off

echo Setup starting...

:: Copy mp3 sound files to media folder.
xcopy /f /i /y /s sound\mp3\*.mp3 media\

echo Setup successfully completed

endlocal
