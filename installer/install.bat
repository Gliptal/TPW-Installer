@echo off

set thisDir=%~dp0
pushd %thisDir%

for /f "skip=2 tokens=2,*" %%A in (
  'reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\bohemia interactive\arma 3" /v "main"'
) do (
  set "ArmaPath=%%B"
)
if  %errorlevel% gtr 0 (
  for /f "skip=2 tokens=2,*" %%A in (
    'reg query "HKEY_LOCAL_MACHINE\SOFTWARE\bohemia interactive\arma 3" /v "main"'
  ) do (
    set "ArmaPath=%%B"
  )
  if  %errorlevel% gtr 0 (
    echo.
    echo AN ERROR HAS OCCURED: INSTALLATION FAILED
    echo EITHER ARMA III IS NOT INSTALLED, OR YOU HAVEN'T STARTED IT AT LEAST ONCE
    echo.
    pause
    exit /b
  )
)

echo.
echo WELCOME TO TPW MODS PACKAGE INSTALLER: IF UPDATING ALL USER CONFIGURED FILES
echo WILL BE KEPT
echo.

pause

echo.
echo PHASE 1/4: COPYING UPDATED TPW MODS
xcopy "@TPW_MODS" "%ArmaPath%\@TPW_MODS\" /s /e /y /q
if %errorlevel%==0 (
  echo SUCCESS
) else (
  echo.
  echo AN ERROR HAS OCCURED: INSTALLATION FAILED
  echo THE INSTALLER IS NOT IN THE SAME FOLDER AS THE DOWNLOADED TPW MODS PACKAGE
  echo.
  pause
  exit /b
)
echo.

pause

echo.
echo PHASE 2/4: MANAGING USERCONFIG
xcopy "@TPW_MODS\userconfig\TPW_MODS\hudicons_key.png" "%ArmaPath%\userconfig\TPW_MODS\*" /y /q
if %errorlevel% gtr 0 goto errorHandling
xcopy "@TPW_MODS\userconfig\TPW_MODS\TPW Settings.jar" "%ArmaPath%\userconfig\TPW_MODS\*" /y /q
if %errorlevel% gtr 0 goto errorHandling
if not exist "%ArmaPath%\userconfig\TPW_MODS\TPW_MODS.hpp" (
  xcopy "@TPW_MODS\userconfig\TPW_MODS\TPW_MODS.hpp" "%ArmaPath%\userconfig\TPW_MODS\*" /y /q
)
:errorHandling
if %errorlevel%==0 (
  echo SUCCESS
) else (
  echo.
  echo AN ERROR HAS OCCURED: INSTALLATION FAILED
  echo THE DOWNLOADED TPW MODS PACKAGE IS MISSING SOME REQUIRED FILES
  echo.
  pause
  exit /b
)
echo.

pause

echo.
echo PHASE 3/4: CREATING DESKTOP SHORTCUT
shortcut /a:c /F:"%USERPROFILE%\Desktop\Configure TPW Mods.lnk" /t:"%ArmaPath%\userconfig\TPW_MODS\TPW Settings.jar" /w:"%ArmaPath%\userconfig\TPW_MODS" /d:"Configure TPW Mods with a graphical GUI."
if %errorlevel%==0 (
  echo SUCCESS
) else (
  echo.
  echo AN ERROR HAS OCCURED: INSTALLATION PARTIALLY SUCCESSFUL
  echo EITHER SHORTCUT.EXE IS MISSING, OR YOUR DESKTOP DIRECTORY IS MISCONFIGURED
  echo.
  pause
  exit /b
)
echo.

pause

echo.
echo PHASE 4/4: DELETING DOWNLOADED FILES
rmdir "@TPW_MODS" /s /q || rem
if %errorlevel%==0 (
  echo SUCCESS
) else (
  echo.
  echo AN ERROR HAS OCCURED: INSTALLATION PARTIALLY SUCCESSFUL
  echo THE DOWNLOADED TPW MODS PACKAGE HAS ALREADY BE DELETED
  echo.
  pause
  exit /b
)
echo.

echo INSTALLATION COMPLETED SUCCESSFULLY
echo.

pause