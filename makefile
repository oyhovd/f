SRCS = $(wildcard src/*.cpp)
INCS = $(wildcard include/*.h)
OBJS = $(SRCS:.c=.o)
#CC = clang
CC = g++
DEBUG = 
LIBS = -lstdc++
CXXFLAGS = -Ofast -Wall $(DEBUG) -Iinclude
LFLAGS = -Wall $(LIBS) $(DEBUG)

f : $(OBJS) $(INCS)
	$(CC) $(CXXFLAGS) $(LFLAGS) $(OBJS) -o f

.PHONY: clean
clean:
	rm f

