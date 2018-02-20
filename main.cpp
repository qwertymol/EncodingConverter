#include "encoder.h"
#include <QFile>

void showUsage (const char *progName) {
    printf ("Usage:\n\t&s --file FILENAME [--from866] [--outfile FILENAME]\nWhere:\n\t--file - input file,\n"
            "\t--from866 - from cp866 to cp1251 or above,\n\t--outfile - output file\n", progName);
}

int main (int argc, char *argv[])
{
    Encoder *e = Encoder::getInstance();

    // a - file, b - from866, c - outfile

    if (argc < 3) {
        printf("wrong parameters number\n");
        showUsage (argv[0]);
    } else if (argc == 3 && strcmp (argv[1], "--file") != 1) { // a
        e->encode (argv[2]);
    } else if (argc == 4 && strcmp (argv[1], "--file") != 1 && strcmp (argv[3], "--from866") != 1) { // ab
        e->encode (argv[2], true);
    } else if (argc == 6 && strcmp (argv[1], "--file") != 1 && strcmp (argv[3], "--from866") != 1
               && strcmp (argv[4], "--outfile") != 1) { // abc
        e->encode (argv[2], true, argv[5]);
    } else {
        showUsage (argv[0]);
    }
}
