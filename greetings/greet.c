#include "greet.h"

/**
 * array of moon phase descriptions; used by `get_moon_phase` fn.
 */
const char *g_phases[8] = {
    "waxing crescent 🌒", "at first quarter 🌓", "waxing gibbous 🌔",  "full 🌕",
    "waning gibbous 🌖",  "at last quarter 🌗",  "waning crescent 🌘", "new 🌑"};

int get_moon_phase(int year, int month, int day)
{
    int d, g, e;

    d = day;

    if (month == 2) {
        d += 31;
    } else if (month > 2) {
        d += 59 + (month - 3) * 30.6 + 0.5;
    }

    g = (year - 1900) % 19;
    e = (11 * g + 29) % 30;

    if (e == 25 || e == 24) {
        e++;
    }

    return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

int greet(int argc, char **argv)
{
    time_t now;
    struct tm *clock;
    char date_string[32];
    char time_string[32];

    time(&now);
    clock = localtime(&now);

    strftime(date_string, 32, "%nToday is %a, %b %d, %Y%n", clock);

    printf("%s", date_string);

    int moon_phase =
        get_moon_phase((clock->tm_year + 1900), clock->tm_mon, clock->tm_mday);
    printf("[Moon Phase] %s\n", g_phases[moon_phase]);

    strftime(time_string, 32, "%nIt is %r right now.%n", clock);

    printf("%s", time_string);

    printf("Good ");

    if (clock->tm_hour < 12) {
        printf("morning, ");
    } else if (clock->tm_hour < 18) {
        printf("afternoon, ");
    } else {
        printf("evening, ");
    }

    if (argc > 1) {
        printf("%s.\n", argv[1]);
    } else {
        printf("stranger.\n");
    }

    if (clock->tm_hour >= 5 && clock->tm_hour <= 7) {
        printf("You're up early today!\n");
    } else if (clock->tm_hour == 23 ||
               (clock->tm_hour >= 0 && clock->tm_hour <= 2)) {
        printf("Working late, huh?\n");
    }

    return 0;
}
