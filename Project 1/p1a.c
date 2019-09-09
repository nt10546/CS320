 /**
    *  Program 1a
    *  This program calculates the time in minutes to fill a rectangular
    *   swimming pool of uniform depth (in feet).
    *  CS320
    *  9/7/2019
    *  @author  Nam Tran
    */

/* Header Files */
#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/
void getDim(float *length, float *width, float *height);
float calcTime(float volume);


int main(void){
    float length, width, height, volume;
    float inputRate = 20;

    printf("Program #1, cssc0517, Nam Tran\n");

    /*printf("Calling getDim function\n");*/
    getDim(&length, &width, &height);
    printf("The time to fill a swimming pool %.6f by %.6f by %.6f with water\n", length, width, height);
    volume = length * width * height;

    /*printf("Calling calcTime function\n");*/
    printf("input rate of %.6f gallons per minute is %.6f minutes.\n", inputRate, calcTime(volume));

    return 0;
}

/** 
    * The getDim function accepts the dimensions of the pool, and
    * reads in these values from the user with no prompt.
    */
void getDim(float *length, float *width, float *height){
    float l, w, h;
    /*printf("Please enter the length:\n");*/
    scanf("%f", &l);
    /*printf("Please enter the width:\n");*/
    scanf("%f", &w);
    /*printf("Please enter the height:\n");*/
    scanf("%f", &h);
    *length = l;
    *width = w;
    *height = h;
}

/**
    * The calcTime function receives the volume of the pool
    * and calculates the time to fill the pool with water.
    * */
float calcTime(float volume){
    return volume/20/7.8;
}
