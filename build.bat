@echo off
cd /d "%~dp0"

if not exist build mkdir build

g++ -std=c++11 -Wall -Wextra -pedantic ^
code\ActionACT.cpp ^
code\Bestiaire.cpp ^
code\Boss.cpp ^
code\CatalogueACT.cpp ^
code\Console.cpp ^
code\Entite.cpp ^
code\Inventaire.cpp ^
code\Jeu.cpp ^
code\Joueur.cpp ^
code\MiniBoss.cpp ^
code\Monstre.cpp ^
code\MonstreNormal.cpp ^
code\Objet.cpp ^
code\main.cpp ^
-o build\alterdune.exe

if errorlevel 1 (
    echo Build FAILED
    pause
    exit /b 1
)

echo Build OK
echo Lancement d'Alterdune...
build\alterdune.exe
pause
