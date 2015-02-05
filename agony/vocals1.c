#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "grand_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "vocals1";
char *PROGRAM_VERSION = "0.01";

int
main()
    {
    unsigned int i;
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

    openOutput("vocals1.rra",0,0);

    /* intro */
    for (i = 0; i < 2; i++)
    {
        rest(Hd);
    }
    /* end intro */

    n(1,Id,instrument,octave,2);
    n(1,S,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,4);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave-1,5);

    n(1,Id,instrument,octave,2);
    n(1,S,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,Qd,instrument,octave,4);

    n(1,Id,instrument,octave,2);
    n(1,S,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,4);
    n(1,I,instrument,octave,2);
    n(1,H,instrument,octave-1,5);
    rest(Qd);

    n(1,Id,instrument,octave,2);
    n(1,S,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,4);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave-1,5);

    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,Q,instrument,octave,4);
    n(1,I,instrument,octave,4);

    n(1,I,instrument,octave,3);
    n(1,I,instrument,octave,4);
    n(1,I,instrument,octave,3);
    n(1,Id,instrument,octave,4);
    n(1,S,instrument,octave,2);
    n(1,H,instrument,octave-1,5);
    rest(Qd);

    n(1,Id,instrument,octave+1,0);
    n(1,S,instrument,octave+1,0);
    n(1,Q,instrument,octave+1,0);
    rest(Q);

    rest(I);
    n(1,I,instrument,octave,6);
    n(1,I,instrument,octave+1,0);
    n(1,I,instrument,octave,6);
    n(1,I,instrument,octave,5);
    n(1,I,instrument,octave,4);

    n(1,Qd,instrument,octave,4);
    rest(Qd);

    rest(I);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,3);
    n(1,I,instrument,octave,4);
    n(1,I,instrument,octave,3);
    n(1,I,instrument,octave,2);

    n(1,Qd,instrument,octave,4);
    rest(Qd);

    rest(I);
    n(1,I,instrument,octave,1);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,1);

    setTime(9,8);

    n(1,I,instrument,octave,3);
    n(1,I,instrument,octave,2);
    n(1,I,instrument,octave,1);
    n(1,Hd,instrument,octave,2);

    setTime(6,8);

    closeOutput();

    return 0;
    }
