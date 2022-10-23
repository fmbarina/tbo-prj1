#ifndef TIMER_H
#define TIMER_H

/**
 * @brief returns the value of function clock() in timer.h
 * 
 * @return double 
 */
double timer_clock();

/**
 * @brief Prints a message of the difference(in milliseconds) 
 *          between end and start
 * 
 * @param start 
 * @param end 
 * @param message 
 */
void timer_print(double start, double end, char* message);
#endif
