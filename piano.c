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

void intro(int, int);
void verse(int, int);
void refrain(int, int);
void bridge(int, int);
void outro(int, int);

int main()
{
    int instrument;
    int octave = 5;
    songInit();

    instrument = readScale(dir,base);

    setTempo(300);
    //setTempo(160);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.6);

    openOutput("piano.rra",0,0);
    
    // intro(instrument, octave);
    // verse(instrument, octave);
    // verse(instrument, octave);
    // refrain(instrument, octave);
    // verse(instrument, octave);
    // bridge(instrument, octave);
    // refrain(instrument, octave);
    refrain(instrument, octave);
    outro(instrument, octave);

    closeOutput();

    return 0;
}

void intro(int instrument, int octave)
{
    rest(12*Hd);
}

void verse(int instrument, int octave)
{
    rest(Hd*2);
    n(1, Qd, instrument, octave, 4);
    n(1, Q, instrument, octave, 4);
    n(1, I, instrument, octave, 5);

    n(1, Qd, instrument, octave, 2);
    rest(Q);
    n(1, I, instrument, octave, 2);

    n(1, Q, instrument, octave, 3);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 1);
    n(1, I, instrument, octave, 0);

    n(1, Qd, instrument, octave, 2);
    n(1, Qd, instrument, octave, 1);

    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 0);
    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 1);
    
    n(1, Hd, instrument, octave-1, 5);

    n(1, Q, instrument, octave, 3);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 1);
    n(1, I, instrument, octave, 0);

    n(1, Qd, instrument, octave, 2);
    n(1, Qd, instrument, octave, 1);

    n(1, Q, instrument, octave, 5);
    n(1, I, instrument, octave, 5);
    n(1, Q, instrument, octave, 5);
    n(1, I, instrument, octave, 4);

    n(1, Q, instrument, octave, 2);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 2);
    n(1, I, instrument, octave, 2);

    n(1, Q, instrument, octave, 3);
    n(1, I, instrument, octave, 0);
    n(1, Q, instrument, octave, 1);
    n(1, I, instrument, octave, 0);

    n(1, Qd, instrument, octave, 2);
    n(1, Qd, instrument, octave, 1);

    rest(Hd);

    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);

    n(1, Hd, instrument, octave, 2);

    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);

    n(1, Hd, instrument, octave, 2);

    rest(Hd);
}

void refrain(int instrument, int octave)
{
    n(1, Hd, instrument, octave, 4);
    n(1, Hd, instrument, octave, 2);

    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 0);
    n(1, I+Hd, instrument, octave, 1);

    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 0);
    n(1, Q, instrument, octave, 1);
    n(1, I, instrument, octave, 1);

    n(1, Qd, instrument, octave, 2);
    n(1, Qd, instrument, octave, 1);

    n(1, Q, instrument, octave, 5);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 0);
    n(1, I, instrument, octave, 1);

    rest(Hd);

    n(1, Q, instrument, octave-1, 4);
    n(1, I, instrument, octave-1, 4);
    n(1, Q, instrument, octave-1, 5);
    n(1, I, instrument, octave-1, 5);

    n(1, Qd, instrument, octave, 0);
    n(1, Qd, instrument, octave-1, 5);

    n(1, Q, instrument, octave, 2);
    n(1, I, instrument, octave, 2);
    n(1, Q, instrument, octave, 3);
    n(1, I, instrument, octave, 3);

    n(1, Qd, instrument, octave, 4);
    n(1, Q, instrument, octave, 2);
    n(1, I, instrument, octave, 0);

    n(1, Hd, instrument, octave, 1);

    n(1, Hd, instrument, octave-1, 4);

    rest(Hd*2);
}

void bridge(int instrument, int octave)
{
    rest(21*Hd);
}

void outro(int instrument, int octave)
{
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);
    n(1, Hd, instrument, octave, 0);

    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);
    n(1, Hd, instrument, octave, 0);

    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 5);
    n(1, Q, instrument, octave, 4);
    n(1, Hd, instrument, octave, 2);

    rest(2*Hd);
}
