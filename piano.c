#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "grand_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "piano";
char *PROGRAM_VERSION = "0.03";

void piano(int, int);

int main()
{
    int instrument;
    int octave = 4;
    int i;

    songInit();

    instrument = readScale(dir,base);

    setTempo(110);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("piano.rra",0,0);

    for (i = 0; i < 1; i++)
        piano(instrument, octave);

    closeOutput();

    return 0;
}

void piano(int instrument, int octave)
{
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 4);
    n(1, Qd, instrument, octave, 4);
    n(1, Q, instrument, octave, 2);

    n(1, I, instrument, octave, 1);
    n(1, Q, instrument, octave, 0);
    n(1, I + H, instrument, octave, 1);

    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 4);
    n(1, Qd, instrument, octave, 5);
    n(1, Q, instrument, octave, 2);

    n(1, I, instrument, octave, 1);
    n(1, Q, instrument, octave, 0);
    n(1, I + H, instrument, octave, 1);

    n(1, I, instrument, octave, 1);
    n(1, Q, instrument, octave, 2);
    n(1, Qd, instrument, octave, 3);
    n(1, Q, instrument, octave, 2);

    n(1, I, instrument, octave, 1);
    n(1, Q, instrument, octave, 0);
    n(1, I + H, instrument, octave-1, 4);
}
