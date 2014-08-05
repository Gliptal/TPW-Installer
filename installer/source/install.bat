@echo off

set thisDir=%~dp0
pushd %thisDir%

REM --------------------------------------
REM              REGISTRY KEY
REM --------------------------------------
:registry

reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\bohemia interactive\arma 3" /v "main" 2>nul
if %errorlevel%==0 goto 64bitSystem
reg query "HKEY_LOCAL_MACHINE\SOFTWARE\bohemia interactive\arma 3" /v "main" 2>nul
if %errorlevel%==0 (goto 32bitSystem) else (goto registryError)

:64bitSystem
for /f "skip=2 tokens=2,*" %%A in (
  'reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\bohemia interactive\arma 3" /v "main"'
) do (
  set ArmaPath=%%B
)
goto install

:32bitSystem
for /f "skip=2 tokens=2,*" %%A in (
  'reg query "HKEY_LOCAL_MACHINE\SOFTWARE\bohemia interactive\arma 3" /v "main"'
) do (
  set ArmaPath=%%B
)
goto install


REM --------------------------------------
REM              INSTALL
REM --------------------------------------
:install

echo.
echo WELCOME TO THE INSTALLER FOR 'TPW MODS PACKAGE': THIS WILL AUTOMATICALLY COPY
echo ALL REQUIRED FILES TO THE CORRECT FOLDERS, AS WELL AS UPDATE TPW_MODS.HPP AND
echo ANY EXISTING SAVED PRESETS WITH ADDED, REMOVED, OR CHANGED VARIABLES (IF
echo NEEDED).
echo.

pause


REM --------------------------------------
REM              MAIN FOLDER
REM --------------------------------------
:mainFolder

echo.
echo PHASE 1/4: UPDATING TPW MODS

xcopy "@TPW_MODS" "%ArmaPath%\@TPW_MODS\" /s /e /y /q
if %errorlevel% gtr 0 goto mainFolderError

echo SUCCESS
echo.

pause


REM --------------------------------------
REM              USERCONFIG
REM --------------------------------------
:userconfig

echo.
echo PHASE 2/4: MANAGING USERCONFIG

xcopy "@TPW_MODS\userconfig\TPW_MODS\hudicons_key.png" "%ArmaPath%\userconfig\TPW_MODS\*" /y /q
if %errorlevel% gtr 0 goto userconfigError
xcopy "@TPW_MODS\userconfig\TPW_MODS\TPW Settings.jar" "%ArmaPath%\userconfig\TPW_MODS\*" /y /q
if %errorlevel% gtr 0 goto userconfigError

if not exist "%ArmaPath%\userconfig\TPW_MODS\TPW_MODS.hpp" (
  xcopy "@TPW_MODS\userconfig\TPW_MODS\TPW_MODS.hpp" "%ArmaPath%\userconfig\TPW_MODS\*" /y /q
  if %errorlevel% gtr 0 goto userconfigError
) else (
  xcopy "%ArmaPath%\userconfig\TPW_MODS\*.hpp" "*.hpp" /y /q
  xcopy "%ArmaPath%\userconfig\TPW_MODS\*.PRST" "*.PRST" /y /q 2>nul
  for %%f in (*.hpp *.PRST) do (
    update "%%~nxf" "%%~nxfNEW"
    if not exist "TPW_MODS.hppNEW" goto updaterError
  )
  xcopy "*.hppNEW" "%ArmaPath%\userconfig\TPW_MODS\*.hpp" /y /q
  xcopy "*.PRSTNEW" "%ArmaPath%\userconfig\TPW_MODS\*.PRST" /y /q 2>nul
  del "*.hpp" /q
  del "*.PRST" /q 2>nul
  del "*.PRSTNEW" /q 2>nul
  del "temp*.txt" /q 2>nul
)

echo SUCCESS
echo.

pause


REM --------------------------------------
REM              SHORTCUT
REM --------------------------------------
:shortcut

echo.
echo PHASE 3/4: CREATING DESKTOP SHORTCUT

shortcut /a:c /F:"%USERPROFILE%\Desktop\Configure TPW Mods.lnk" /t:"%ArmaPath%\userconfig\TPW_MODS\TPW Settings.jar" /w:"%ArmaPath%\userconfig\TPW_MODS" /d:"Configure TPW Mods with a graphical GUI." 1>nul
if %errorlevel% gtr 0 goto shortcutWarning
:backFromShortcutWarning

echo SUCCESS
echo.

pause


REM --------------------------------------
REM              CLEAN
REM --------------------------------------
:clean

echo.
echo PHASE 4/4: DELETING DOWNLOADED FILES

rmdir "@TPW_MODS" /s /q || rem
if %errorlevel% gtr 0 goto cleanWarning
:backFromCleanWarning

echo SUCCESS
echo.

pause

echo.
echo INSTALLATION COMPLETED SUCCESSFULLY
echo.
goto quit


REM --------------------------------------
REM              ERRORS
REM --------------------------------------

:registryError
echo.
echo ERROR: INSTALLATION FAILED
echo EITHER ARMA III IS NOT INSTALLED, OR IT WAS NOT STARTED AT LEAST ONCE
echo.
goto quit

:mainFolderError
echo.
echo ERROR: INSTALLATION FAILED
echo THE INSTALLER IS NOT IN THE SAME FOLDER AS THE DOWNLOADED 'TPW MODS PACKAGE'
echo.
goto quit

:userconfigError
echo.
echo ERROR: INSTALLATION FAILED
echo SOME REQUIRED FILES ARE MISSING FROM THE DOWNLOADED 'TPW MODS PACKAGE'
echo.
goto quit

:updaterError
echo.
echo ERROR: INSTALLATION FAILED
echo SOMETHING WENT WRONG WHILE RUNNING THE UPDATER
echo.
goto quit

:shortcutWarning
echo.
echo WARNING: INSTALLATION PARTIALLY SUCCESSFUL
echo EITHER SHORTCUT.EXE IS MISSING, OR YOUR DESKTOP DIRECTORY IS MISCONFIGURED
echo.
goto backFromShortcutWarning

:cleanWarning
echo.
echo WARNING: INSTALLATION PARTIALLY SUCCESSFUL
echo DOWNLOADED 'TPW MODS PACKAGE' WAS ALREADY DELETED
echo.
goto backFromCleanWarning

:quit
pause
exit /b