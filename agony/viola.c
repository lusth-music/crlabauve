#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/viola/"
#define base "iowa-1_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "viola";
char *PROGRAM_VERSION = "0.01";

int
main()
    {
    int instrument;
    int octave = 3;

    songInit();

    instrument = readScale(dir,base);

    setTempo(139);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.6);
    setKey(E);

    openOutput("viola.rra",0,0);

    /* intro */
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    /* intro */

    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);

    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);

    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);
    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);

    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);
    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);

    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);

    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,Gs);
    play(I,instrument,octave,Gs);

    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);
    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);

    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);
    play(Q,instrument,octave,A);
    play(I,instrument,octave,A);

    closeOutput();

    return 0;
    }
