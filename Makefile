CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
INCLUDE = -Iinclude
TARGET = bin/debug/game

# Hier holen wir uns automatisch die richtigen Flags von sdl2-config
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LIBS = $(shell sdl2-config --libs) -lSDL2_image

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin/debug
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJ) -o $@ $(SDL_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SDL_CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

run: all
	SDL_VIDEODRIVER=x11 ./$(TARGET)
