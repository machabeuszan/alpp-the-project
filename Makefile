#####################################################
#
#  Name: Makefile
#  Project: alpp
#  Author: Adrian Ciesielski
#  Creation Date: 2012-08-31
#  Copyright: (c) 2012 by Adrian Ciesielski
#  License: GNU LGPL v3 (see COPYING)
#  Version: 0.0.1
#
#####################################################

# Configuration

# uC parameters
DEVICE	= atmega8
F_CPU	= 16000000


# paths definitions
AVR_INCLUDE	= /usr/local/avr/include/
AVR_LIBS	= /usr/local/avr/lib


# internal configuration - DO NOT modify anything beyond this point
SRCPREFIX = src
OBJS	  = obj
RELEASEDIR   = ../release

OBJECTNAMES = utils/simulSerial hal/preg8 hal/pgpopin hal/pgpipin sys/pled
HDRSTOCOPYR = hal/gpio utils/simulSerial hal/preg8 hal/preg16 hal/pgpopin hal/pgpipin sys/pled

# compile flags
CFLAGS	 = -Iinclude -DDEBUG_LEVEL=0 --std=c99 -I$(AVR_INCLUDE)
CXXFLAGS = -Iinclude -DDEBUG_LEVEL=0 -I$(AVR_INCLUDE) -g

# list of object to build

PREOBJS	 = $(addsuffix .o, $(OBJECTNAMES) )
OBJECTS	 = $(addprefix $(SRCPREFIX)/, $(PREOBJS) )


HDRSPRERELASE = $(addsprefix include, $(HDRSTOCOPYR))
HDRSRELEASE = $(addsuffix .h, $(HDRSPRERELASE))

# command to compile .c objects
COMPILEC = avr-gcc -c -Wall -Os -DF_CPU=$(F_CPU) $(CFLAGS) -mmcu=$(DEVICE)
# command to compile .cpp objects
COMPILE	 = avr-g++ -c -Wall -Os -DF_CPU=$(F_CPU) $(CXXFLAGS) -mmcu=$(DEVICE)

help:
	@echo "Jak używać:"
	@echo "make lib .... aby zbudować bibliotekę"

clean:
	rm -fR *.o *.a $(OBJECTS)
	find -iname *~ -delete

rclean:
	rm -fR $(RELEASEDIR)/

docclean:
	rm -fR doc/*

doc:
	@doxygen


lib: libalpp.a
	avr-size $< -t

#-C --mcu=$(DEVICE)



release: libalpp.a | $(RELEASEDIR)
	@cp -v libalpp.a $(RELEASEDIR)/
	@cp -Rv include/$(HDRSRELEASE) $(RELEASEDIR)

$(RELEASEDIR):
	mkdir $(RELEASEDIR)
dirs:
	@if [ ! -d obj ]; then mkdir obj; fi;

%.o: %.cpp
	$(COMPILE) $< -o $@

.o.c:
	$(COMPILEC) $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@



libalpp.a: $(OBJECTS)
	avr-ar rsc $@ $^




