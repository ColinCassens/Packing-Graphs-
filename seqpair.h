#ifndef PA6_SEQPAIR_H
#define PA6_SEQPAIR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <stdarg.h>

typedef struct _Node{
    struct _Node * next;
    int ID;
    double x;
    double y;
}Node;

int main(int argc, char ** argv);
Node * loadFromFile(FILE * infile, int * numpoints);
int * loadSEQ(FILE * INFILE, int numpoints);


#endif