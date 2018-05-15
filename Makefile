CC=gcc
CFLAGS=-Wall -O3

MAIN=src/main.c
HEADERS=$(wildcard src/*.h)
SOURCES=$(filter-out $(MAIN), $(wildcard src/*.c))
TARGET=tic_tac_toe

TEST=test/unity/unity
TEST_SOURCES=$(wildcard test/*.c)
TEST_TARGET=$(TARGET)_test

INITBIN=mkdir -p bin

all: $(TARGET)

$(TARGET): $(MAIN)
	$(INITBIN)
	$(CC) $(SOURCES) $(MAIN) $(CFLAGS) -o bin/$(TARGET)

run: $(MAIN)
	make $(TARGET)
	./bin/$(TARGET)

test: $(MAIN) test/main.c $(TEST).h
	$(INITBIN)
	$(CC) $(TEST).c $(SOURCES) $(TEST_SOURCES) $(CFLAGS) -o bin/$(TEST_TARGET)
	./bin/$(TEST_TARGET)

clean:
	rm -rf bin

.PHONY: all clean test
