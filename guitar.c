#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/guitar-electric/"
#define base "clean_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "guitar";
char *PROGRAM_VERSION = "0.03";

void intro(int, int, double, double);
void verse(int, int, double, double);
void refrain(int, int, double, double);
void bridge(int, int, double, double);
void outro(int, int, double, double);

int main()
{
    int instrument;
    int octave = 3;

    songInit();

    instrument = readScale(dir,base);

    setTempo(300);
    //setTempo(160);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.1);

    openOutput("guitar.rra",0,0);

    intro(instrument, octave, 0.08, 0.08);
    verse(instrument, octave, 0.08, 0.08);
    verse(instrument, octave, 0.08, 0.08);
    refrain(instrument, octave, 0.05, 0.07);
    verse(instrument, octave, 0.08, 0.08);
    bridge(instrument, octave, 0.04, 0.05);
    refrain(instrument, octave, 0.05, 0.05);
    refrain(instrument, octave, 0.05, 0.07);
    outro(instrument, octave, 0.08, 0.08);

    closeOutput();

    return 0;
}

void intro(int instrument, int octave, double startAmplitude, double endAmplitude)
{
    int i;
    setAmplitude(startAmplitude);
    for (i = 0; i < 3; i++)
    {
        cpower(1, Q, instrument, octave);
        cpower(1, I, instrument, octave);
        cpower(1, Qd, instrument, octave);

        cpower(6, Q, instrument, octave-1);
        cpower(6, I, instrument, octave-1);
        cpower(6, Qd, instrument, octave-1);

        cpower(4, Q, instrument, octave-1);
        cpower(4, I, instrument, octave-1);
        cpower(4, Qd, instrument, octave-1);

        cpower(5, Q, instrument, octave-1);
        cpower(5, I, instrument, octave-1);
        cpower(5, Qd, instrument, octave-1);
    }
    setAmplitude(endAmplitude);
}

void verse(int instrument, int octave, double startAmplitude, double endAmplitude)
{
    int i;
    setAmplitude(startAmplitude);
    cpower(4, Q, instrument, octave-1);
    cpower(4, I, instrument, octave-1);
    cpower(4, Qd, instrument, octave-1);

    cpower(5, Q, instrument, octave-1);
    cpower(5, I, instrument, octave-1);
    cpower(5, Qd, instrument, octave-1);
    for (i = 0; i < 3; i++)
    {
        cpower(1, Hd, instrument, octave);
        cpower(6, Hd, instrument, octave);
        cpower(4, Hd, instrument, octave);
        cpower(5, Hd, instrument, octave);
    }
    cpower(1, I, instrument, octave);
    cpower(1, I, instrument, octave);
    cpower(1, I, instrument, octave);
    cpower(1, I, instrument, octave);
    rest(Q);

    cpower(6, I, instrument, octave-1);
    cpower(6, I, instrument, octave-1);
    cpower(6, I, instrument, octave-1);
    cpower(6, I, instrument, octave-1);
    rest(Q);

    cpower(4, I, instrument, octave-1);
    cpower(4, I, instrument, octave-1);
    cpower(4, I, instrument, octave-1);
    cpower(4, I, instrument, octave-1);
    rest(Q);

    cpower(5, I, instrument, octave-1);
    cpower(5, I, instrument, octave-1);
    cpower(5, I, instrument, octave-1);
    cpower(5, I, instrument, octave-1);
    rest(Q);

    cpower(4, Q, instrument, octave-1);
    cpower(4, I, instrument, octave-1);
    cpower(4, Qd, instrument, octave-1);

    cpower(5, Q, instrument, octave-1);
    cpower(5, I, instrument, octave-1);
    cpower(5, Qd, instrument, octave-1);
    setAmplitude(endAmplitude);
}

void refrain(int instrument, int octave, double startAmplitude, double endAmplitude)
{
    int i;
    double difference = endAmplitude - startAmplitude;
    setAmplitude(startAmplitude);
    for (i = 0; i < 3; i++)
    {
        cpower(1, Q, instrument, octave);
        cpower(1, I, instrument, octave);
        cpower(1, Qd, instrument, octave);

        cpower(6, Q, instrument, octave-1);
        cpower(6, I, instrument, octave-1);
        cpower(6, Qd, instrument, octave-1);

        cpower(4, Q, instrument, octave-1);
        cpower(4, I, instrument, octave-1);
        cpower(4, Qd, instrument, octave-1);

        cpower(5, Q, instrument, octave-1);
        cpower(5, I, instrument, octave-1);
        cpower(5, Qd, instrument, octave-1);
    }
    setAmplitude(startAmplitude + difference * .25);
    cpower(1, Q, instrument, octave);
    cpower(1, I, instrument, octave);
    cpower(1, Qd, instrument, octave);

    setAmplitude(startAmplitude + difference * .5);
    cpower(6, Q, instrument, octave-1);
    cpower(6, I, instrument, octave-1);
    cpower(6, Qd, instrument, octave-1);

    setAmplitude(startAmplitude + difference * .75);
    cpower(4, Q, instrument, octave-1);
    cpower(4, I, instrument, octave-1);
    cpower(4, Qd, instrument, octave-1);

    setAmplitude(startAmplitude + difference);
    cpower(5, Q, instrument, octave-1);
    cpower(5, I, instrument, octave-1);
    cpower(5, Qd, instrument, octave-1);
}

void bridge(int instrument, int octave, double startAmplitude, double endAmplitude)
{
    int i;
    cpower(5, Hd, instrument, octave-1);

    setAmplitude(startAmplitude);

    for (i = 0; i < 2; i++)
        b(1, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    b(3, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    n(1, I, instrument, octave-1, 6);
    n(1, I, instrument, octave-1, 5);
    n(1, I, instrument, octave-1, 4);
    for (i = 0; i < 2; i++)
        b(5, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);

    for (i = 0; i < 6; i++)
        b(1, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    for (i = 0; i < 6; i++)
        b(5, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    for (i = 0; i < 6; i++)
        b(4, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    for (i = 0; i < 6; i++)
        b(3, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    for (i = 0; i < 6; i++)
        b(4, Qd, instrument, octave-1, "-x-", "--x", "O--", SX);
    cpower(4, Hd*2, instrument, octave-1);
    setAmplitude(endAmplitude);
}

void outro(int instrument, int octave, double startAmplitude, double endAmplitude)
{
    setAmplitude(startAmplitude);
    cpower(6, Q, instrument, octave-1);
    cpower(6, Q, instrument, octave-1);
    cpower(5, Q, instrument, octave-1);
    cpower(1, Hd, instrument, octave);

    cpower(6, Q, instrument, octave-1);
    cpower(6, Q, instrument, octave-1);
    cpower(5, Q, instrument, octave-1);
    cpower(1, Hd, instrument, octave);

    cpower(6, Q, instrument, octave-1);
    cpower(6, Q, instrument, octave-1);
    cpower(5, Q, instrument, octave-1);
    cpower(1, 2*Hd, instrument, octave);

    rest(Hd);
    setAmplitude(endAmplitude);
}