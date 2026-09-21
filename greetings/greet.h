#include <stdio.h>
#include <time.h>

/**
 * @brief fetch *mostly* accurate moon phase.
 * @returns a number 0-7 which can used to read an *almost* accurate moon phase
 * using `g_phases` array.
 *
 * @param[in] year year to check moon phase for.
 * @param[in] month month to check moon phase for.
 * @param[in] day day to check moon phase for.
 *
 * @param[out] moon_phase - ranging from 0-7.
 *
 * @attention IT'S NOT THE MOST ACCURATE PHASE OF THE MOON!!
 */
int get_moon_phase(int year, int month, int day);

/**
 * @brief greet the user in a formatted string.
 * The formatting is highly specific & cannot be modified on-the-fly.
 *
 * @returns a number; 0 indicates no error.should be refactored to return the
 * greeting.
 *
 * @param[in] argc count of the arguments being passed; minimum is 1.
 * @param[in] argv the list of arguments.
 *
 * @warning TO BE REFACTORED SOON TO RETURN THE FORMATTED STRING!!
 */
int greet(int argc, char **argv);
