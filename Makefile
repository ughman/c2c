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
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

%.o: %.cc
	$(C++) $(C++FLAGS) -MMD -o $@ -c $<

c2c: $(OBJECTS)
	$(C++) $(LDFLAGS) -o $@ $^

-include $(DEPENDS)

.PHONY: all clean
