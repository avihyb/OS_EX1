CC := g++
CFLAGS := -Wall -Wextra -std=c++11
LDFLAGS := -shared -fPIC

LIBRARY := libpoisson.so
SOURCE_FILES := Poissonlib.cpp
MAIN_FILE := q3.cpp
OUTPUT := q3

all: $(OUTPUT)

$(OUTPUT): $(MAIN_FILE) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $< -L. -lpoisson

$(LIBRARY): $(SOURCE_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(OUTPUT) $(LIBRARY) 