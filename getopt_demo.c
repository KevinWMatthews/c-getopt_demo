#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    while (1)
    {
        int opt;

        // Follow an argument with a colon to require an argument
        // The argument will be placed in optarg
        opt = getopt(argc, argv, "ab:c");
        if (opt == -1)
        {
            break;
        }

        switch (opt)
        {
            case 'a':
                printf("Option 'a'\n");
                break;
            case 'b':
                printf("Option 'b': %s\n", optarg);
                break;
            case 'c':
                printf("Option 'c'\n");
                break;
            case '?':       // Unrecognized option
            case ':':       // Missing argument
            default:
                fprintf(stderr, "Usage: %s [-ac] [-b val] [ARG]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Adjust this logic if multiple positional arguments are required
    if (optind >= argc)
    {
        fprintf(stderr, "Expected argument after options\n");
        fprintf(stderr, "Usage: %s [-ac] [-b val]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    do
    {
        printf("%s ", argv[optind++]);
    } while (optind < argc);
    printf("\n");

    return 0;
}
