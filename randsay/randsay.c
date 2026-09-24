/*
    Version 3.0, aka, final version of this file.  We plan to do something like
   'fortune' in Linux.  Read the "database" of pithy texts and print one of
   them, randomly.
*/

#include "randsay.h"

int randsay()
{
    const char filename[] = "pithy.txt";

    /*
        At this point we have nothing, so we start by having a filepointer,
        a buffer (static) to read a chunk of the file at once, and a char
        pointer - not much use apart from checking for errors while reading
        from the file.

        Now, in this version of the program, we also get ourselves a *items*
        counter (for number of lines in the file), a pointer to each line in
        the file, a pointer-pointer *list_base* to store addresses of the
        entries in the file.
    */

    FILE *fp;
    char *buffer = NULL;
    size_t buffer_size = 0;
    int line_count = 0;

    /*
        Open the file in read-only mode.  Proceed only if there are no errors
        encountered while doing so!
    */

    fp = fopen( filename, "r" );

    if ( NULL == fp ) {
        fprintf( stderr, "Unable to open file %s\n", filename );
        return 1;
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

    /*
        Before we move into the *loop* of reading file till its very end, let's
        allocate some space for our pointer-pointer list (list of all lines in
        the file).
        For now, we assume that our file doesn't have more than a hundred lines
        and each line is merely 128 characters.

        NOTE:  if the no. of lines in the file exceeds this _magic number_ of
        100, shit **will** hit the fan & the program will puke all over itself.

        Unless of course, we take care of that part as well using the glorious
        _realloc_ API in C!  And, spoiler alert!  we're going to do that.
    */

    while ( getline(&buffer, &buffer_size, fp) != -1 ) {
        line_count++;
    }

    if (ferror(fp)) {
        fprintf(stderr, "Error while reading %s\n", filename);
        free(buffer);
        fclose(fp);
        return 1;
    }

    if (line_count == 0) {
        fprintf(stderr, "Uh oh!  The database is empty.\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    rewind( fp );  // reset cursor back to the start of the file.

    srand( (unsigned)time( NULL ) );
    int selected_line = rand() % line_count;
    line_count = 0;  // reset line count

    while ( getline(&buffer, &buffer_size, fp) != -1 ) {
        if ( line_count == selected_line ) {
            printf( "%s", buffer );
            break;
        }

        line_count++;
    }


    /* At last, like any good boi, close the file! ;p */

    free(buffer);
    fclose( fp );

    return 0;
}
