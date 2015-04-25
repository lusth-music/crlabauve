#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/cello/"
#define base "drawn_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "cello";
char *PROGRAM_VERSION = "0.03";

void intro(int, int);
void verse(int, int);
void refrain(int, int);
void bridge(int, int);
void outro(int, int);

int main()
{
    int instrument;
    int octave = 4;

    songInit();

    instrument = readScale(dir,base);

    setTempo(300);
    //setTempo(160);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99990);
    setAmplitude(0.7);

    openOutput("cello.rra",0,0);
    
    intro(instrument, octave);
    verse(instrument, octave);
    verse(instrument, octave);
    refrain(instrument, octave);
    verse(instrument, octave);
    bridge(instrument, octave);
    refrain(instrument, octave);
    refrain(instrument, octave);
    outro(instrument, octave);

    closeOutput();

    return 0;
}

void intro(int instrument, int octave)
{
    rest(4*Hd);
    n(1, Hd, instrument, octave, 4);
    n(1, Hd, instrument, octave, 2);

    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 0);
    n(1, I+Hd, instrument, octave, 1);

    n(1, Qd, instrument, octave, 0);
    n(1, Qd, instrument, octave, 1);

    n(1, Qd, instrument, octave, 2);
    n(1, Qd, instrument, octave, 1);

    n(1, Q, instrument, octave, 5);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 1);
    rest(Hd);
}

void verse(int instrument, int octave)
{
    rest(20*Hd);
}

void refrain(int instrument, int octave)
{
    rest(16*Hd);
}

void bridge(int instrument, int octave)
{
    rest(Hd*4);

    n(1, Q, instrument, octave, 0);
    n(1, Q, instrument, octave, 1);
    n(1, H+Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);
    n(1, H, instrument, octave, 2);
    rest(Q);

    n(1, Q, instrument, octave, 0);
    n(1, Q, instrument, octave, 1);
    n(1, H+Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);
    n(1, H, instrument, octave, 2);
    rest(Q);

    n(1, Q, instrument, octave, 3);
    n(1, Q, instrument, octave, 4);
    n(1, H+Q, instrument, octave-1, 5);
    n(1, Hd, instrument, octave-1, 6);
    rest(Q);

    n(1, Q, instrument, octave, 3);
    n(1, Q, instrument, octave, 4);
    n(1, H+Q, instrument, octave-1, 5);
    n(1, Hd, instrument, octave, 0);
    rest(Q);

    n(1, Hd, instrument, octave, 1);
    n(1, Hd, instrument, octave, 2);
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);
    n(1, 2*Hd, instrument, octave, 2);
    rest(Q);
}

void outro(int instrument, int octave)
{
    n(1, Hd, instrument, octave+1, 0);
    n(1, Hd, instrument, octave, 0);
    n(1, Hd, instrument, octave+1, 0);
    n(1, Hd, instrument, octave, 0);
    n(1, Hd, instrument, octave+1, 0);
    n(1, Hd, instrument, octave, 0);
    n(1, Hd, instrument, octave, 4);
    n(1, 2*Hd, instrument, octave, 2);
}
