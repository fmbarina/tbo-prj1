#include "timer.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double timer_clock(){
    return clock();
}

void timer_print(double start, double end, char* message){
    printf("%s tempo eh: %.5lfms\n", message,(end-start)/CLOCKS_PER_SEC);
}