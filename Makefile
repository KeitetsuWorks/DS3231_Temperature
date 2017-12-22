##
## Makefile for DS3231 Temperature Register Access
## Makefile
##
## Rev.     | Date       | Design     | Comment
##          | 2016/10/01 | Keitetsu   | 
##


CROSS_PREFIX =

CC           = $(CROSS_PREFIX)gcc
CXX          = $(CROSS_PREFIX)g++
LD           = $(CROSS_PREFIX)gcc
CFLAGS       = -Wall -Wextra -O3 -MMD -MP
CXXFLAGS     = -Wall -Wextra -O3 -MMD -MP
LDFLAGS      =
LIBS         =
INCLUDE      = -I./include -I./i2c/include -I./DS3231/include

DOXYGENDIR   = ./html ./latex
NOMAKEDIR    = $(DOXYGENDIR) .git%
OBJDIR       = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = .
endif
BINDIR       = ./bin
ifeq "$(strip $(BINDIR))" ""
	BINDIR = .
endif

CALLSRCS     = $(shell find * -name *.c)
CXXALLSRCS   = $(shell find * -name *.cpp)
CSRCS        = $(filter-out $(NOMAKEDIR), $(CALLSRCS))
CXXSRCS      = $(filter-out $(NOMAKEDIR), $(CXXALLSRCS))
SRCS         = $(CSRCS) $(CXXSRCS)
CSRCDIRS     = $(dir $(CSRCS))
CXXSRCDIRS   = $(dir $(CXXSRCS))
SRCDIRS      = $(CSRCDIRS) $(CXXSRCDIRS)
COBJS        = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(CSRCS)))
CXXOBJS      = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(CXXSRCS)))
OBJS         = $(COBJS) $(CXXOBJS)
COBJDIRS     = $(addprefix $(OBJDIR)/, $(CSRCDIRS))
CXXOBJDIRS   = $(addprefix $(OBJDIR)/, $(CXXSRCDIRS))
OBJDIRS      = $(COBJDIRS) $(CXXOBJDIRS)
DEPS         = $(OBJS:.o=.d)
TARGET       = $(BINDIR)/$(shell basename `readlink -f .`)

$(TARGET): $(OBJS) $(LIBS)
	-mkdir -p $(BINDIR)
	$(LD) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	-mkdir -p $(OBJDIR)
	-mkdir -p $(COBJDIRS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJDIR)/%.o: %.cpp
	-mkdir -p $(OBJDIR)
	-mkdir -p $(CXXOBJDIRS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

.PHONY: clean all

clean:
	-rm -f $(OBJS) $(TARGET)
	-rm -rf $(OBJDIR)
	-rm -rf $(BINDIR)
	-rm -rf $(DOXYGENDIR)

all: clean $(TARGET)

-include $(DEPS)

