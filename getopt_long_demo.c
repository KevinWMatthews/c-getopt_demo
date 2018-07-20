#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int opt4;

    while (1)
    {
        int this_optind = optind;       // Index for all options, 1-based
        int long_option_index = -1;     // Index for long options only, 0-based?
        int opt;

        static struct option long_options[] = {
            // flag controls how an option's argument is returned
            //  NULL    return val
            //  int *   fill with val or leave unchanged
            //
            // name,    has_arg,            flag, val
            {"opt1",    no_argument,        0, 0},
            {"opt2",    optional_argument,  0, 0},
            {"opt3",    required_argument,  0, 0},
            {"opt4",    optional_argument,  0, 4},
        };

        long_options[3].flag = &opt4;
        // If not a long option, the index is unchanged?
        opt = getopt_long(argc, argv, "ab:c", long_options, &long_option_index);
        if (opt == -1)
            break;

        switch (opt)
        {
            case 0:
            {
                struct option *long_option = &long_options[long_option_index];
                printf("Long option: %s", long_option->name);
                if (optarg)
                {
                    printf(" with arg %s", optarg);
                }
                printf("\n");
                break;
            }
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

    if (optind < argc)
    {
        printf("Positional arguments: ");
        do
        {
            printf("%s ", argv[optind++]);
        } while (optind < argc);
        printf("\n");
    }
    exit(EXIT_SUCCESS);
}
