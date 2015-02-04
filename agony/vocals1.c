#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "grand_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "vocals1";
char *PROGRAM_VERSION = "0.01";

int
main()
    {
    int instrument;
    int octave = 4;

    songInit();

    instrument = readScale(dir,base);

    setTempo(139);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);
    setKey(E);

    openOutput("vocals1.rra",0,0);

    /* intro */
    rest(Hd);

    rest(Hd);
    /* intro */

    play(Id,instrument,octave,Gs);
    play(S,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,B);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,Cs);

    play(Id,instrument,octave,Gs);
    play(S,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(Qd,instrument,octave,B);

    play(Id,instrument,octave,Gs);
    play(S,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,B);
    play(I,instrument,octave,Gs);
    play(H,instrument,octave,Cs);
    rest(Qd);

    play(Id,instrument,octave,Gs);
    play(S,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,B);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,Cs);

    play(I,instrument,octave,Gs);
    play(I,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(Q,instrument,octave,B);
    play(I,instrument,octave,B);

    play(I,instrument,octave,A);
    play(I,instrument,octave,B);
    play(I,instrument,octave,A);
    play(Id,instrument,octave,B);
    play(S,instrument,octave,Gs);
    play(H,instrument,octave,Cs);
    rest(Qd);

    play(Id,instrument,octave+1,E);
    play(S,instrument,octave+1,E);
    play(Q,instrument,octave+1,E);
    rest(Q);

    rest(I);
    play(I,instrument,octave+1,Ds);
    play(I,instrument,octave+1,E);
    play(I,instrument,octave+1,Ds);
    play(I,instrument,octave+1,Cs);
    play(I,instrument,octave,B);

    play(Qd,instrument,octave,B);
    rest(Qd);

    rest(I);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,A);
    play(I,instrument,octave,B);
    play(I,instrument,octave,A);
    play(I,instrument,octave,Gs);

    play(Qd,instrument,octave,B);
    rest(Qd);

    rest(I);
    play(I,instrument,octave,Fs);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,Fs);

    setTime(9,8);

    play(I,instrument,octave,A);
    play(I,instrument,octave,Gs);
    play(I,instrument,octave,Fs);
    play(Hd,instrument,octave,Gs);

    setTime(6,8);

    closeOutput();

    return 0;
    }
