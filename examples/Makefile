CC=cc
CFLAGS=-Wall -std=c99 -O3 -lbicycles
SOURCE=.
BUILD=./build
RM=rm
RMFLAGS=-rf

all: $(BUILD)/hash

$(BUILD)/hash: $(SOURCE)/hash.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	$(RM) $(RMFLAGS) $(BUILD)