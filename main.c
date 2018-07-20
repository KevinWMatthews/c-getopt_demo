#include <unistd.h>     // getopt is provided by <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    while (1)
    {
        int opt;

        // Follow an argument with a colon to require an argument
        opt = getopt(argc, argv, "ab:c");
        if (opt == -1)
        {
            break;
        }

        switch (opt)
        {
            case 'a':
                printf("Detected 'a'\n");
                break;
            case 'b':
                printf("Detected 'b': %s\n", optarg);
                break;
            case 'c':
                printf("Detected 'c'\n");
                break;
            case '?':
            case ':':
            default:
                fprintf(stderr, "Usage: %s [-ac] [-b val]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}
