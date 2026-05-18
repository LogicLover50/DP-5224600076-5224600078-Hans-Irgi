@echo off
cd /d "%~dp0"
echo Compiling Chain of Responsibility...
g++ -std=c++17 main.cpp BlindRule.cpp RewardRule.cpp ScoringRule.cpp GameManager.cpp HandGenerator.cpp HandPlayer.cpp PokerHandChecker.cpp -o CoR.exe
if %ERRORLEVEL% EQU 0 (
    echo Running Chain of Responsibility...
    CoR.exe
) else (
    echo Compilation failed.
)
pause