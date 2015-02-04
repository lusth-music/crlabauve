#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "grand_"

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
    b(5, H, instrument, octave, "x--", "--x", "-x-", SX);
    b(6, W, instrument, octave, "x---", "-x--", "--x-", "---x", SX);
    setKey(D);
    b(4, H, instrument, octave, "--x", "--x", "xx-", "--x", SX);
    b(1, H, instrument, octave, "-xx", "-xx", "x--", "-xx", SX);
    c(5, Q, instrument, octave+1);
    c(5, Q, instrument, octave+1);
    c(5, Q, instrument, octave);
    c(5, Q, instrument, octave+1);
    b(6, H, instrument, octave, "x--", "--x", "--x", "-x-", SX);
    ci1(6, Q, instrument, octave);
    b(6, Q, instrument, octave, "x-x", SX);
    b(4, H, instrument, octave, "x--", "--x", "--x", "-x-", SX);
    ci2(1, Q, instrument, octave-1);
    b(1, Q, instrument, octave, "x-x", SX);
    cpower(5, W, instrument, octave);

    closeOutput();

    return 0;
}
