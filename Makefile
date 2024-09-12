CC = g++
EXEC = game

SRC = \
	  src/Main.cpp\
	  src/Button.cpp\
	  src/ButtonHandler.cpp\
	  src/StartButtonHandler.cpp\
	  src/ScoreButtonHandler.cpp\
	  src/ExitButtonHandler.cpp\
	  src/BackButtonHandler.cpp\
	  src/Engine.cpp\
	  src/Screen.cpp\
	  src/StartScreen.cpp\
	  src/PlayScreen.cpp\
	  src/HighscoreScreen.cpp\
	  src/Player.cpp\
	  src/Bullet.cpp\
	  src/EnemyShip.cpp\
	  src/Music.cpp\
	  src/SoundEffect.cpp\
	  src/HealthBar.cpp\
	  src/ScoreDB.cpp\
	  src/ScoreField.cpp
OBJ = $(patsubst src/%.cpp,obj/%.o,$(SRC))

SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LIBS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lsqlite3

.PHONY: all
all: $(OBJ)
	$(CC) $^ -o $(EXEC) $(SDL_LIBS)

.PHONY: run
run: all
	@./$(EXEC)

.PHONY: clean
clean:
	rm -r obj $(EXEC)

$(OBJ): obj/%.o : src/%.cpp
	@mkdir -p obj
	$(CC) $(SDL_CFLAGS) -c $< -o $@