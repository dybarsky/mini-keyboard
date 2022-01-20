
DIR = src/main
CLEAR = \e[0m
HIGHLIGHT = \e[0;33m

CC = arduino-cli
CFLAGS = compile
UFLAGS = upload

BOARD = --fqbn arduino:avr:micro
PORT = -p /dev/ttyACM0

all: | clean build flash
	figlet success
	
clean:
	@echo "$(HIGHLIGHT)=> Cleaning$(CLEAR)"
	$(CC) cache clean

build:
	@echo "$(HIGHLIGHT)=> Compiling$(CLEAR)"
	$(CC) $(CFLAGS) $(BOARD) $(DIR)/main.ino

flash:
	@echo "$(HIGHLIGHT)=> Flashing$(CLEAR)"
	$(CC) $(UFLAGS) $(PORT) $(BOARD) $(DIR)/main.ino

.SILENT: all	
.PHONY: clean build flash
