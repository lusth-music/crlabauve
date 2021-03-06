#Place the names of all your tracks here (as RRA filenames)

RRA = guitar.rra drums.rra cello.rra
INCLUDE=/usr/local/include/songlib/
LIB=/usr/local/lib/

all : $(RRA)

%.rra	: %.x
		./$<

%.x	: %.c
		gcc -Wall -g -o $@ -I$(INCLUDE) $< -L$(LIB) -lsong -lm 

mix		: $(RRA)
		rrafastmixer -a0.5 $(RRA) | rplay

mix.rra		: $(RRA)
		rrafastmixer -a0.5 $(RRA) > mix.rra

playmix	: mix.rra
		rplay mix.rra

play	: $(RRA)
		rplay $(RRA)

uketest : uketest.rra
		rplay uketest.rra

.PHONY : clean

clean :
		rm -f $(RRA)
