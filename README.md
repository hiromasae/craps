# Craps

A simplified version of the craps game.

## Description

This game of craps give you a starting balance of $100 and allows you to play against a bot to <br />
potentially win money (or lose money). The game rules, current balance, transaction history, and roll <br/>
history can each be viewed through the menu selection.

## Execution

Enter the following into the terminal to run the program: <br/>
```
./build.sh && ./buildfiles/main
```

## Stages of Development

### Completed:
- Menu creation
- Craps game mechanic
- The game mechanic integrated with the player and bot
- Betting integrated, completing the game loop
- Create linked list template for transaction history and roll history
- Implement transaction history using template and print to screen
- Implement roll history using template and print to screen
- Game rules read from file then print to screen
- Print transaction history and roll history to respective txt files after exiting game
- Made player and bot subclasses of gamemember
- Error messages for wrong input

### Future Stages:
- Search algorithm to find largest gain and loss from transactions 
- Unit tests for each class
