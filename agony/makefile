#Place the names of all your tracks here (as RRA filenames)

RRA = vocals1.rra cello.rra piano1.rra viola.rra harp.rra piano2.rra bass.rra 
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

play	: $(RRA)
		rplay $(RRA)

playmix	: mix.rra
		rplay mix.rra

rraidentity : rraidentity.c
		gcc -Wall -g -o rraidentity -I$(INCLUDE) rraidentity.c -L$(LIB) -lsong -lm 

.PHONY : clean

clean :
		rm -f $(RRA)
