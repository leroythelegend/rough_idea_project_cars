ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
  detected_OS := Windows
else
  detected_OS := $(shell uname)  # same as "uname -s"
  #$(info $$detected_OS is [${detected_OS}])
endif

CC       = g++
ifeq (${detected_OS}, Linux  )
  CFLAGS   = -m64 -fPIC -I./ -std=c++14 -Wall -Wextra 
else
  #CFLAGS   = -g -m64 -std=c++11 -Wall -Wextra 
  CFLAGS   = -m64 -std=c++11 -Wall -Wextra 
endif

INCLUDES = -I./

ifeq (${detected_OS}, Linux  )
  LFLAGS   = -m64 -shared 
else
  #LFLAGS   = -g -m64 -shared -lpthread -Wl,-install_name,
  LFLAGS   = -m64 -shared -lpthread -Wl,-install_name,
endif

SRCS     = $(wildcard *.cpp)
OBJDIR   = ../obj
ifeq (${detected_OS}, Linux  )
  OBJS     = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS)) -lpthread
else
  OBJS     = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))
endif
MAJOR    = 0
MINOR    = 0
VERSION  = $(MAJOR).$(MINOR)
NAME     = rough_idea_pcars

ifeq (${detected_OS}, Linux  )
  MAIN     = ../lib/lib$(NAME).so
else
  MAIN     = ../lib/lib$(NAME).dylib
endif

.PHONY: depend clean 

all: $(MAIN)
	@echo *****COMPILED*****

$(MAIN): $(OBJS)
ifeq (${detected_OS}, Linux  )
	$(CC) $(LFLAGS) $(OBJS) -o $(MAIN)
else
	$(CC) $(LFLAGS)$(MAIN)  $(OBJS) -o $(MAIN) 
endif

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

install:
	mkdir -p ../obj

clean:
	$(RM) $(OBJDIR)/*.o *~ $(MAIN)

depend: $(SRCS)	
	makedepend $(INCLUDES) $^
