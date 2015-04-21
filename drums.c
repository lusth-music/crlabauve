#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.02";

void riff(int, int);

int main()
{
    int instrument;
    int octave = 2;
    int i;

    songInit();

    instrument = readScale(dir,base);

    setTempo(110);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("drums.rra",0,0);

    rest(3*W);
    for (i = 0; i < 11; i++)
        riff(instrument, octave);

    closeOutput();

    return 0;
}

void riff(int instrument, int octave)
{
    int spot = getLocation();
    drumkitHHClosed(1,1,"--x---x-",SX);setLocation(spot);
    drumkitKick(1,1,    "x-x-x-x-",SX);setLocation(spot);
    drumkitSnare(1,1,   "xx-x-x-x",SX);
}
