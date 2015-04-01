#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/ukulele/"
#define base "concert_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "uketest";
char *PROGRAM_VERSION = "0.01";

void riff(int, int);

int main()
{
    int instrument;
    int octave;
    int loOctave = 2;
    int hiOctave = 6;
    int i;

    songInit();

    instrument = readScale(dir,base);

    setTempo(120);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("uketest.rra",0,0);

    for (octave = loOctave; octave <= hiOctave; octave++)
        for (i = 0; i < 7; i++)
            n(1, I, instrument, octave, i);
    n(1, I, instrument, hiOctave + 1, 0);

    closeOutput();

    return 0;
}
