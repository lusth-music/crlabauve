#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/cello/"
#define base "drawn_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "cello";
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
    setAmplitude(0.4);
    setKey(E);

    openOutput("cello.rra",0,0);

    /* intro */
    play(Qd,instrument,octave,Ds);
    play(Qd,instrument,octave,Cs);
    
    play(Qd,instrument,octave,Ds);
    play(Qd,instrument,octave,Cs);
    /* intro */

    play(Qd,instrument,octave,Ds);
    play(Qd,instrument,octave,Cs);

    play(Qd,instrument,octave,Ds);
    play(Qd,instrument,octave,Cs);

    play(Wd,instrument,octave-1,B);

    play(Qd,instrument,octave,Ds);
    play(Qd,instrument,octave,Cs);

    play(Qd,instrument,octave,Ds);
    play(Qd,instrument,octave,Cs);
    
    play(Wd,instrument,octave-1,B);

    closeOutput();

    return 0;
    }
