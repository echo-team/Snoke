#ifndef SHARED_H
#define SHARED_H

#include <gtest/gtest.h>

constexpr bool TRAVIS = 0;

extern "C" {
#include "common.h"
}

int changeStream(FILE* file) {
    int oldstdOut = dup(1);
    close(1);
    dup2(fileno(file), 1);

    return oldstdOut;
}

void returnStream(FILE* file, int oldstdOut) {
    fflush(stdout);
    fclose(file);
    dup2(oldstdOut, 1);
}

int executeTest(FILE* expectedData, FILE* outputData) {
    if (expectedData == NULL) {
        printf("Cannot open expected file \n");
        return 0;
    }
    if (outputData == NULL) {
        printf("Cannot open output file \n");
        return 0;
    }

    char expectedLine[MAXLINE];
    char outputLine[MAXLINE];

    while ((fgets(expectedLine, MAXLINE, expectedData) != NULL) | (fgets(outputLine, MAXLINE, outputData) != NULL)) {
        expectedLine[strlen(expectedLine) - 1] = '\0';
        outputLine[strlen(outputLine) - 1] = '\0';
        printf("Expected line: \"%s\", output line: \"%s\" \n", expectedLine, outputLine);
        if (strcmp(expectedLine, outputLine) != 0) return 0;
    }

    return 1;
}

#endif // SHARED_H
