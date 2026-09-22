/*
    Version 1.0 of this file.  We plan to do something like 'fortune' in
    Linux.  Read the "database" of pithy texts and print one of them, randomly.

    I realize that, generally speaking, I've never really written much file I/O
    code myself... so, I'll be using this opportunity to make myself better
    at it.  For this activity, we'll be going from statically allocated
    hard-coded buffers and such.  And gradually move to using memory on the
    heap, dynamically, so that we can allocate buffer sizes on-the-fly.
*/

#include <stdio.h>
#include <stdlib.h>

/*
    the size of the buffer, used for reading a chunk of the file at a time.
*/
#define BSIZE 16

int main()
{
    const char filename[] = "pithy.txt";

    /*
        At this point we have nothing, so we start by having a filepointer,
        a buffer (static) to read a chunk of the file at once, and a char
        pointer - not much use apart from checking for errors while reading
        from the file.
    */

    FILE *fp;
    char buffer[BSIZE];
    char *r;

    /*
        Open the file in read-only mode.  Proceed only if there are no errors
        encountered while doing so!
    */

    fp = fopen(filename, "r");

    if (NULL == fp) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    /*
        Now that we have the file open, read the contents of it - one
        "size of the buffer" at a time.
        When you encounter the EOF, quit reading the file.  Until then, keep
        reading the contents of the file (size-of-the-buffer characters at a
        time) into the buffer and print it - otherwise you'll lose it when
        you move forward in the file.

        If you store it somewhere, you're kind of loading the entire file in
        the memory, which isn't a good idea... what if the file's a large one?
        It's also not the point of this program, we're not building a text
        editor or anything, it's enough for now if we keep printing on the
        characters read once in the buffer and then move on in the file.
    */

    while (!feof(fp)) {
        r = fgets(buffer, BSIZE, fp);

        if (NULL == r) {
            break;
        }

        printf("%s", buffer);
    }

    /* At last, like any good boi, close the file! ;p */

    fclose(fp);

    return 0;
}
