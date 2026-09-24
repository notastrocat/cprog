/*
    Version 1.0 of this file.  Read the "database" of pithy texts and print them.
*/

#include "randsay.h"

/*
    the size of the buffer, used for reading a chunk of the file at a time.
*/
#define BSIZE 127


int reed()
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
    char buffer[BSIZE];
    char *r;
    int items = 0;
    char **list_base;
    int status = 0;

    /*
        Open the file in read-only mode.  Proceed only if there are no errors
        encountered while doing so!
    */

    fp = fopen( filename, "r" );

    if ( NULL == fp ) {
        fprintf( stderr, "Unable to open file %s\n", filename );
        exit( 1 );
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

    list_base = (char **)malloc( sizeof( char * ) * 100 );
    if ( NULL == list_base ) {
        fprintf( stderr,
                 "Unable to allocate memory for list of lines in file.\n" );
        fclose( fp );
        return 1;
    }

    while ( !feof( fp ) ) {
        r = fgets( buffer, BSIZE, fp );

        if ( NULL == r ) {
            break;
        }

        char *entry = (char *)malloc( strlen( buffer ) + 1 );

        if ( NULL == entry ) {
            fprintf( stderr,
                     "Unable to allocate memory for line #%3d in file.\n",
                     items );
            status = 1;
            goto cleanup;
        }

        strcpy( entry, buffer );

        // in normal case, we can print this & free the *entry* to reuse again.
        // printf("%3d: %s", items, entry);

        *( list_base + items ) = entry;

        items++;

        if ( items % 100 == 0 ) {
            char **resized_list = (char **)realloc(
                list_base, sizeof( char * ) * ( items + 100 ) );

            if ( NULL == resized_list ) {
                fprintf( stderr, "Unable to reallocate more memory for list of "
                                 "lines in file.\n" );
                status = 1;
                goto cleanup;
            }

            list_base = resized_list;
        }
    }

    for ( int i = 0; i < items; i++ ) {
        printf( "%3d: %s", i, *( list_base + i ) );
    }

cleanup:
    for ( int i = 0; i < items; i++ ) {
        free( list_base[i] );
    }

    fclose( fp );
    free(list_base);

    return status;
}
