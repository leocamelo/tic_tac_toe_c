CC=gcc
CFLAGS=-Wall -O3

MAIN=src/main.c
SOURCES=$(filter-out $(MAIN), $(wildcard src/*.c))
TARGET=tic_tac_toe

TEST_MAIN=test/main.c
TEST_SOURCES=$(wildcard test/check_*.c)
TEST_TARGET=$(TARGET)_test
TEST_LINKS=-lm -lcheck

all: $(TARGET)

$(TARGET): $(MAIN)
	mkdir -p bin
	$(CC) $(SOURCES) $(MAIN) $(CFLAGS) -o bin/$(TARGET)

run: $(MAIN)
	make $(TARGET)
	./bin/$(TARGET)

test: $(TEST_MAIN)
	make $(TARGET)
	$(CC) $(SOURCES) $(TEST_SOURCES) $(TEST_MAIN) $(CFLAGS) $(TEST_LINKS) -o bin/$(TEST_TARGET)
	./bin/$(TEST_TARGET)

clean:
	rm -rf bin

.PHONY: all clean test
