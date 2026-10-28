@echo off
cd /d "%~dp0"
if not exist build mkdir build
g++ -std=c++11 -Wall -Wextra -pedantic src\ActionACT.cpp src\Bestiaire.cpp src\Boss.cpp src\CatalogueACT.cpp src\Console.cpp src\Entite.cpp src\Inventaire.cpp src\Jeu.cpp src\Joueur.cpp src\MiniBoss.cpp src\Monstre.cpp src\MonstreNormal.cpp src\Objet.cpp src\main.cpp -o build\alterdune.exe
if %errorlevel% == 0 (
  echo Build OK
) else (
  echo Build FAILED
)
