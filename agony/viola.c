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
    unsigned int i;
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
    for (i = 0; i < 2; i++)
    {
        n(1,Q,instrument,octave,2);
        n(1,I,instrument,octave,2);
        n(1,Q,instrument,octave,2);
        n(1,I,instrument,octave,2);
    }
    /* end intro */

    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);
    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);

    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);
    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);

    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);
    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);

    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);
    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);

    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);
    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);

    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);
    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,2);

    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);
    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);

    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);
    n(1,Q,instrument,octave,3);
    n(1,I,instrument,octave,3);

    closeOutput();

    return 0;
    }
