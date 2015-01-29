#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "riff";
char *PROGRAM_VERSION = "0.01";

int main()
{
    int instrument;
    int octave = 4;

    songInit();

    instrument = readScale(dir,base);

    setTempo(132);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("riff.rra",0,0);

    c(6, Hd, instrument, octave);
    b(6, Q, instrument, octave, "--x", "-x-", "x--", SX);
    c(4, Q, instrument, octave);
    b(4, Q, instrument, octave, "x--", "-x-", SX);
    c(1, H, instrument, octave);
    c(5, H, instrument, octave);
    b(5, H, instrument, octave, "--x", "----x", "---x", SX);

    closeOutput();

    return 0;
}
