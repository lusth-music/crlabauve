#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "grand_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "piano1";
char *PROGRAM_VERSION = "0.01";

int
main()
    {
    int instrument;
    int octave = 4;

    songInit();

    instrument = readScale(dir,base);

    setTempo(139);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.1);
    setKey(E);

    openOutput("piano1.rra",0,0);

    /* intro */
    play(Q,instrument,octave,Ds);
    play(I,instrument,octave,Ds);
    play(Q,instrument,octave,Cs);
    play(I,instrument,octave,E);

    play(Q,instrument,octave,Ds);
    play(I,instrument,octave,Ds);
    play(Q,instrument,octave,Cs);
    play(I,instrument,octave,E);
    /* intro */

    play(Q,instrument,octave,Ds);
    play(I,instrument,octave,Ds);
    play(Q,instrument,octave,Cs);
    play(I,instrument,octave,E);

    play(Q,instrument,octave,Ds);
    play(I,instrument,octave,Ds);
    play(Q,instrument,octave,Cs);
    play(I,instrument,octave,Cs);

    play(Q,instrument,octave-1,B);
    play(I,instrument,octave-1,B);
    play(Q,instrument,octave-1,A);
    play(I,instrument,octave-1,A);

    play(Q,instrument,octave-1,B);
    play(I,instrument,octave-1,B);
    play(Q,instrument,octave-1,A);
    play(I,instrument,octave,E);
    
    play(Q,instrument,octave,Ds);
    play(I,instrument,octave,Ds);
    play(Q,instrument,octave,Cs);
    play(I,instrument,octave,E);

    play(Q,instrument,octave,Ds);
    play(I,instrument,octave,Ds);
    play(Q,instrument,octave,Cs);
    play(I,instrument,octave,Cs);

    play(Q,instrument,octave-1,B);
    play(I,instrument,octave-1,B);
    play(Q,instrument,octave-1,A);
    play(I,instrument,octave-1,A);

    play(Q,instrument,octave-1,B);
    play(I,instrument,octave-1,B);
    play(Q,instrument,octave-1,A);
    play(I,instrument,octave,E);

    closeOutput();

    return 0;
    }
