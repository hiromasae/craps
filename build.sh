touch craps/rollhistory.txt
touch craps/transactionhistory.txt
g++ -c craps/bot/Bot.cpp -o buildfiles/Bot.o
g++ -c craps/game/Game.cpp -o buildfiles/Game.o
g++ -c craps/gamemember/GameMember.cpp -o buildfiles/GameMember.o
g++ -c craps/howtoplay/HowToPlay.cpp -o buildfiles/HowToPlay.o
g++ -c craps/menu/Menu.cpp -o buildfiles/Menu.o
g++ -c craps/player/Player.cpp -o buildfiles/Player.o
g++ -c craps/playeraccount/PlayerAccount.cpp -o buildfiles/PlayerAccount.o
g++ -c craps/returntomenu/ReturnToMenu.cpp -o buildfiles/ReturnToMenu.o
g++ -c craps/truncatefile/TruncateFile.cpp -o buildfiles/TruncateFile.o
g++ -c craps/main.cpp -o buildfiles/main.o
g++ buildfiles/Bot.o buildfiles/DiceRoll.o buildfiles/Game.o buildfiles/GameMember.o buildfiles/HowToPlay.o buildfiles/Menu.o buildfiles/Player.o buildfiles/PlayerAccount.o buildfiles/ReturnToMenu.o buildfiles/main.o buildfiles/TruncateFile.o -o buildfiles/main
