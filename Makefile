CC=cc
CFLAGS=-Wall -std=c99 -O3
SOURCE=src
BUILD=build
TESTS=tests
SO=libbicycles.so
RM=rm
RMFLAGS=-rf
PREFIX?=/usr
INCLUDE=include/bicycles
LIB=lib

all: $(BUILD)/$(SO)

install: install-headers install-so
	ldconfig

install-headers: $(SOURCE)/*.h
	mkdir -p $(PREFIX)/$(INCLUDE)
	cp $^ $(PREFIX)/$(INCLUDE)

install-so: $(BUILD)/$(SO)
	mkdir -p $(PREFIX)/$(LIB)
	cp $^ $(PREFIX)/$(LIB)

uninstall: uninstall-headers uninstall-so
	ldconfig

uninstall-headers:
	$(RM) -r $(PREFIX)/$(INCLUDE)

uninstall-so:
	$(RM) $(PREFIX)/$(LIB)/$(SO)

$(BUILD)/$(SO): $(SOURCE)/*.c $(SOURCE)/*.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ -lc

test: $(BUILD)/run_tests
	LD_LIBRARY_PATH=$(BUILD) $^

$(BUILD)/run_tests: $(TESTS)/*.c $(BUILD)/$(SO)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $(TESTS)/*.c -Lbuild -lbicycles

clean:
	$(RM) $(RMFLAGS) $(BUILD)
