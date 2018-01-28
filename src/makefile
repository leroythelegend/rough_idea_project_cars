CC       = g++
CFLAGS   = -g -m64 -std=c++11 -Wall -Wextra 
INCLUDES = -I./
LFLAGS   = -g -m64 -shared -lpthread -Wl,-install_name,
SRCS     = $(wildcard *.cpp)
OBJDIR   = ../obj
OBJS     = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))
MAJOR    = 0
MINOR    = 0
VERSION  = $(MAJOR).$(MINOR)
NAME     = rough_idea_pcars
MAIN     = ../lib/lib$(NAME).dylib

.PHONY: depend clean 

all: $(MAIN)
	@echo *****COMPILED*****

$(MAIN): $(OBJS)
	$(CC) $(LFLAGS)$(MAIN)  $(OBJS) -o $(MAIN)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

install:
	mkdir -p ../obj

clean:
	$(RM) $(OBJDIR)/*.o *~ $(MAIN)

depend: $(SRCS)	
	makedepend $(INCLUDES) $^
