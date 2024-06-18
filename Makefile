COMPILER=g++

COMPILE_FLAGS=-c -Wall

all: main.o player.o round.o game.o figureMatcher.o display.o deck.o card.o bettingCycle.o
	$(COMPILER) main.o player.o round.o game.o figureMatcher.o display.o deck.o card.o bettingCycle.o -o poker-game
main.o: src/main.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/main.cpp
player.o: src/Player.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/Player.cpp
round.o: src/Round.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/Round.cpp
game.o: src/Game.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/Game.cpp
figureMatcher.o: src/FigureMatcher.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/FigureMatcher.cpp
display.o: src/Display:cpp
	$(COMPILER) $(COMPILE_FLAGS) src/Display.cpp
deck.o: src/Deck.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/Deck.cpp
card.o: src/Card.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/Card.cpp
bettingCycle.o: src/BettingCycle.cpp
	$(COMPILER) $(COMPILE_FLAGS) src/BettingCycle.cpp
