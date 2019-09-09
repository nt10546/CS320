 /**
    *  Program 1b
    *  This program calculates the time in minutes to fill a rectangular
    *   swimming pool of uniform depth (in feet).
    *  CS320
    *  9/7/2019
    *  @author  Nam Tran cssc0517 REDID 815922231
    */

/* Header Files */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
float calcTime(float volume);

int main (int argc, char **argv){
    float length, width, height, volume;
    float inputRate = 20;

    /* If there are not exactly 3 arguments, breakpoint */
    if (argc != 4) {
        printf("Usage: p1b length width height\n");
        return 0;
    }
    

    printf("Program #1, cssc0517, Nam Tran\n");

    /* Converting char array elements to float */
    length = (float)atof(argv[1]);
    width = (float)atof(argv[2]);
    height = (float)atof(argv[3]);


    printf("The time to fill a swimming pool %.6f by %.6f by %.6f with water\n", length, width, height);
    volume = length * width * height;

    /*printf("Calling calcTime function\n");*/
    printf("input rate of %.6f gallons per minute is %.6f minutes.\n", inputRate, calcTime(volume));


    return 0;

}

/**
    * The calcTime function receives the volume of the pool
    * and calculates the time to fill the pool with water.
    * */
float calcTime(float volume){
    return volume/20/7.8;
}
