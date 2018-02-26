CC = g++
CFLAGS = -ggdb -m64 -std=c++14 -Wall -Wextra -g
INCLUDES = -I./ -I../../src/
LFLAGS   = -v -m64 -ggdb -L../../lib -lrough_idea_pcars
SRCS     = $(wildcard *.cpp)
OBJS     = $(notdir $(SRCS:.cpp=.o))
MAIN = pcars
.PHONY: depend clean

all: $(MAIN)
	@echo compile
	@pwd

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)	
	makedepend $(INCLUDES) $^
