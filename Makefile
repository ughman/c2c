CC := gcc
C++ := g++
CFLAGS := -g -Wall -std=c99
C++FLAGS := -g -Wall -std=c++11
LDFLAGS := -g
CSOURCES := $(shell find src -name "*.c")
C++SOURCES := $(shell find src -name "*.cc")
OBJECTS := $(CSOURCES:.c=.o) $(C++SOURCES:.cc=.o)
DEPENDS := $(CSOURCES:.c=.d) $(C++SOURCES:.cc=.d)

all: c2c

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDS)

%.o: %.c
	$(CC) -MMD -o $@ -c $< $(CFLAGS)

%.o: %.cc
	$(C++) -MMD -o $@ -c $< $(C++FLAGS)

c2c: $(OBJECTS)
	$(C++) -o $@ $^ $(LDFLAGS)

-include $(DEPENDS)

.PHONY: all clean
