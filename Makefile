CC := gcc
CXX := g++
CFLAGS := -g -Wall -std=c99
CXXFLAGS := -g -Wall -std=c++11
LDFLAGS := -g
CSOURCES := $(shell find src -name "*.c")
CXXSOURCES := $(shell find src -name "*.cc")
OBJECTS := $(CSOURCES:.c=.o) $(CXXSOURCES:.cc=.o)
DEPENDS := $(CSOURCES:.c=.d) $(CXXSOURCES:.cc=.d)

all: c2c

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDS)

%.o: %.c
	$(CC) -MMD -o $@ -c $< $(CFLAGS)

%.o: %.cc
	$(CXX) -MMD -o $@ -c $< $(CXXFLAGS)

c2c: $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

-include $(DEPENDS)

.PHONY: all clean
