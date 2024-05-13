g++ -c craps/craps/Craps.cpp -o buildfiles/Craps.o
g++ -c craps/diceroll/DiceRoll.cpp -o buildfiles/DiceRoll.o
g++ -c craps/game/Game.cpp -o buildfiles/Game.o
g++ -c craps/howtoplay/HowToPlay.cpp -o buildfiles/HowToPlay.o
g++ -c craps/menu/Menu.cpp -o buildfiles/Menu.o
g++ -c craps/player/Player.cpp -o buildfiles/Player.o
g++ -c craps/playerbalancehistory/PlayerBalanceHistory.cpp -o buildfiles/PlayerBalanceHistory.o
g++ -c craps/rollhistory/RollHistory.cpp -o buildfiles/RollHistory.o
g++ -c craps/main.cpp -o buildfiles/main.o
g++ buildfiles/Craps.o buildfiles/DiceRoll.o buildfiles/Game.o buildfiles/HowToPlay.o buildfiles/Menu.o buildfiles/Player.o buildfiles/PlayerBalanceHistory.o buildfiles/RollHistory.o buildfiles/main.o -o buildfiles/main
