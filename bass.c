#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/bass/"
#define base "epiphone_1_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "bass";
char *PROGRAM_VERSION = "0.03";

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
    setAmplitude(0.3);

    openOutput("bass.rra",0,0);

    for (i = 0; i < 4; i++)
        riff(instrument, octave);

    closeOutput();

    return 0;
}

void riff(int instrument, int octave)
{
    /*n(1,Q,instrument,octave,5);
    n(1,Q,instrument,octave,5);
    n(1,Q,instrument,octave,5);
    n(1,Q,instrument,octave,2);

    n(1,Q,instrument,octave+1,1);
    n(1,Q,instrument,octave+1,0);
    n(1,I,instrument,octave,6);
    n(1,I,instrument,octave,6);
    n(1,Q,instrument,octave,4);*/

    n(1,Hd-I,instrument,octave-1,5);
    n(1,I,instrument,octave,1);
    n(1,I,instrument,octave,2);
    n(1,Qd,instrument,octave,3);
    n(1,Q,instrument,octave,2);
    n(1,I,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    n(1,Hd,instrument,octave-1,4);
    b(1,Qd,instrument,octave-1, "-x-", "--x", SX);
}
