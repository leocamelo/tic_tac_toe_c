CC=gcc

MAIN=src/main.c
SOURCES=$(filter-out $(MAIN), $(wildcard src/*.c))
CFLAGS=-Wall -O3
TARGET=tic_tac_toe

TEST_MAIN=test/main.c
TEST_SOURCES=$(wildcard test/check_*.c)
TEST_CFLAGS=-Wno-variadic-macros
TEST_TARGET=$(TARGET)_test
TEST_LINKS=-lcheck

all: $(TARGET)

$(TARGET): $(MAIN)
	mkdir -p bin
	$(CC) $(SOURCES) $(MAIN) $(CFLAGS) -o bin/$(TARGET)

run: $(MAIN)
	make $(TARGET)
	./bin/$(TARGET)

test: $(TEST_MAIN)
	make $(TARGET)
	$(CC) $(SOURCES) $(TEST_SOURCES) $(TEST_MAIN) $(CFLAGS) $(TEST_CFLAGS) $(TEST_LINKS) -o bin/$(TEST_TARGET)
	./bin/$(TEST_TARGET)

clean:
	rm -rf bin

.PHONY: all clean test
