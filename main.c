#include "greetings/greet.h"
#include "reed/reed.h"

int main(int argc, char **argv)
{
    // avoid handling errors from these APIs for now.
    greet(argc, argv);
    printf("\n");
    reed();

    return 0;
}
