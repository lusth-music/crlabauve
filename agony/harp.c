#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "grand_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "harp";
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
    setAmplitude(0.1);
    setKey(E);

    openOutput("harp.rra",0,0);

    /* intro */
    for (i = 0; i < 2; i++)
    {
        n(1,Q,instrument,octave,1);
        n(1,I,instrument,octave,1);
        n(1,Q,instrument,octave,0);
        n(1,I,instrument,octave,0);
    }
    /* end intro */

    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);

    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);

    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);
    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);

    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);
    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);

    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);

    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);

    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);
    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);

    n(1,Q,instrument,octave,0);
    n(1,I,instrument,octave,0);
    n(1,Q,instrument,octave,1);
    n(1,I,instrument,octave,1);

    closeOutput();

    return 0;
    }
