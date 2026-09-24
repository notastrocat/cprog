#include "greetings/greet.h"
#include "randsay/randsay.h"

int main(int argc, char **argv)
{
    // avoid handling errors from these APIs for now.
    greet(argc, argv);
    printf("\n");
    randsay();

    return 0;
}
