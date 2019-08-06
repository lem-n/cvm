CC = gcc
CFLAGS = -g -Wall -std=c99

BIN_DIR = bin
TARGET = cvm

SOURCES_VM = $(wildcard vm/*.c)
OBJECTS_VM = $(patsubst vm/%.c, $(BIN_DIR)/%.o, $(SOURCES_VM))

SOURCES_PRSR = $(wildcard parser/*.c)
OBJECTS_PRSR = $(patsubst parser/%.c, $(BIN_DIR)/%.o, $(SOURCES_PRSR))

OBJECTS = $(OBJECTS_VM) $(OBJECTS_PRSR)

all: ensure_bin $(BIN_DIR)/$(TARGET)

ensure_bin:
	if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

$(BIN_DIR)/%.o: vm/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: parser/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN_DIR)/*

.PHONY: ensure_bin clean
