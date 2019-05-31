/**
 * @file shared.h
 * @author Yegor Ignatov
 * @brief shared functions for testing
 * @version 0.1
 * @date 2019-05-10
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef SHARED_H
#define SHARED_H

#include <gtest/gtest.h>
#include "Common/common.h"

constexpr bool TRAVIS = 0;


/**
 * @brief redirects stdout to a file
 * @param file - desired file to output to
 * @return     - value of the old File descriptor
 */
int changeStream(FILE* file) {
    int oldstdOut = dup(1);
    close(1);
    dup2(fileno(file), 1);

    return oldstdOut;
}

/**
 * @brief returns stdout back
 * @param file      - file, where stdout is redirected
 * @param oldstdOut - the fd of old stdout
 */
void returnStream(FILE* file, int oldstdOut) {
    fflush(stdout);
    fclose(file);
    dup2(oldstdOut, 1);
}

/**
 * @brief compare files of expected and actual output and decide if test passes
 * @param expectedData - file with expected output for the test case
 * @param outputData   - file with actual program output
 * @return             - mark of whether the files are identical
 */
bool executeTest(FILE* expectedData, FILE* outputData) {
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
        if (strcmp(expectedLine, outputLine) != 0) return false;
    }

    return true;
}

#endif // SHARED_H
