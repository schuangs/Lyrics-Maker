CC = g++

MAIN = ./src/main
BIN = ./bin
INCLUDE = ./include
SRC = ./src

SRCS = $(wildcard $(SRC)/*.cpp)
INCLUDES  = $(wildcard $(INCLUDE)/*.hpp)

PLAY = $(BIN)/play
TAP = $(BIN)/tap
PLAY_SOURCE = $(MAIN)/play.cpp
TAP_SOURCE = $(MAIN)/tap.cpp

all: $(PLAY) $(TAP)

$(PLAY): $(SRCS) $(INCLUDES) $(PLAY_SOURCE)
	$(CC) -o $@ $(PLAY_SOURCE) $(SRCS)

$(TAP): $(SRCS) $(INCLUDES) $(TAP_SOURCE)
	$(CC) -o $@ $(TAP_SOURCE) $(SRCS)