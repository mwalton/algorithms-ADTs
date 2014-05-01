#include "util.h"

String mutCLR = KCYN;
String accCLR = KMAG;
String arrCLR = KYEL;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void accessorTest(String fname, int expected, int actual) {
    String statusColor;
    String status;

    if (expected == actual) {
        statusColor = KGRN;
        status = "OK";
    } else {
        statusColor = KRED;
        status = "ERROR";
    }

    printf("%s[ACCESSOR]%s\t%s\t\t\t{ target =  %d | f(x) = %d }\t%s%s%s\n", 
            accCLR, KNRM, fname, expected, actual, statusColor, status, KNRM);
}

void mutatorTest(String format, ... ) {
    va_list arglist;

    printf("%s[MUTATOR]%s\t", mutCLR, KNRM);
    va_start( arglist, format );
    vprintf( format, arglist );
    va_end( arglist );
    printf("\t\t\t\t\t%sOK%s\n", KGRN, KNRM);
}

void arrayTest(int *a, int *b, int size, String labelA, String labelB, int lnW) {
    String statusColor;
    String status;
    String equals;
    int i;
    int charCount;
    bool valid;

    statusColor = KGRN;
    status = "OK";
    charCount = 0;

    printf("%s[ARRAY]%s\t\t{ %s : %s } :\n{ ", arrCLR, KNRM, labelA, labelB);

    for (i = 0; i < size; ++i) {
        if ( a[i] == b[i] ) {
            statusColor = KGRN;
        } else {
            statusColor = KRED;
            valid = false;
        }

        charCount += printf("%s%d:%d%s ", statusColor, a[i], b[i], KNRM);
        charCount -= strlen(statusColor) + strlen(KNRM);
        if (charCount > lnW) {
            printf("\n");
            charCount = 0;
        }
    }

    if (valid) {
        statusColor = KGRN;
        status = "OK";
        equals = "==";
    } else {
        statusColor = KRED;
        status = "ERROR";
        equals = "!=";
    }

    printf("}\n%s[ARRAY_TEST]%s\t{%s} %s {%s}\t\t\t\t\t%s%s%s\n", arrCLR, KNRM, labelA, equals, labelB, statusColor, status, KNRM);
}

void printHeading(String h, char pad, int width) {
    int sizeH = strlen( h );
    int padding = (width - sizeH) / 2;
    int i;

    for (i = 0; i < padding; ++i) { printf("%c", pad); }
    printf("%s", h);
    for (i = 0; i < padding; ++i) { printf("%c", pad); }

    printf("\n");
}

