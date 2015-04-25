#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.04";

void intro();
void verse();
void refrain();
void bridge();
void outro();

int main()
{

    songInit();

    setTempo(300);
    //setTempo(160);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.2);

    openOutput("drums.rra",0,0);

    intro();
    verse();
    verse();
    refrain();
    verse();
    bridge();
    refrain();
    refrain();
    outro();

    closeOutput();

    return 0;
}

void intro()
{
    int i;
    rest(8*Hd);
    for (i = 0; i < 1; i++)
    {
        int spot = getLocation();
        drumkitKick(1,1,  "x-x--x--", "x--xx-x-", "-x--x--x", SX);setLocation(spot);
        drumkitSnare(1,1, "---x----", "-x-----x", "-----x--", SX);
    }
}

void verse()
{
    int i;
    int spot;
    for (i = 0; i < 3; i++)
    {
        spot = getLocation();
        drumkitKick(1,1,  "x-x--x--", "x--xx-x-", "-x--x--x", SX);setLocation(spot);
        drumkitSnare(1,1, "---x----", "-x-----x", "-----x--", SX);
    }
    spot = getLocation();
    drumkitKick(1,1,    "x-x--x--", "x--xx-x-", "-x--x--x", SX);setLocation(spot);
    drumkitSnare(1,1,   "---x----", "-x-----x", "-----x--", SX);setLocation(spot);
    drumkitHHOpen(1, 1, "--------", "----x--x", "--x--x--", SX); 

    spot = getLocation();
    drumkitKick(1,1,    "x-x--x--", "x--xx-x-", "-x--x--x", SX);setLocation(spot);
    drumkitSnare(1,1,   "---x----", "-x-----x", "-----x--", SX);setLocation(spot);
    drumkitHHOpen(1, 1, "x--x--x-", "-x--x--x", "--x--x--", SX); 
}

void refrain()
{
    int i;
    for (i = 0; i < 4; i++)
    {
        int spot = getLocation();
        drumkitKick(1,1,  "x-x--x--", "x--xx-x-", "-x--x--x", SX);setLocation(spot);
        drumkitSnare(1,1, "---x----", "-x-----x", "-----x--", SX);   
    }
}

void bridge()
{
    double amp = getAmplitude();
    setAmplitude(0.05);
    int i;
    for (i = 0; i < 5; i++)
        drumkitHHOpen(1,1, "-xxxxx-x", "xxxx-xxx", "xx-xxxxx", SX);   
    rest(Hd);
    setAmplitude(amp);
}

void outro()
{
    drumkitHHOpen(1,1, "-xxxxx-x", "xxxx-xxx", "xx-xxxxx", SX);  
    drumkitHHOpen(1,1, "-xxxxx-x", "xxxx-xxx", "xx-xxxxx", SX);  
}
