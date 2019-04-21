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
    double height;
    double width;
}Node;

typedef struct _Node2{
    int index1;
    int index2;
    struct _Node3 * rightof;
    struct _Node3 * above;
    struct _Node3 * leftof; //Dont Need
    struct _Node3 * below;  //Dont Need
    double height;
    double width;
    double x;
    double y;
}Hash;

typedef struct _Node3{
    struct _Node3 * next;
    int value;
}HolderNode;

int main(int argc, char ** argv);
Node * loadFromFile(FILE * infile, int * numpoints);
int * loadSEQ(FILE * INFILE, int numpoints);
Hash ** Create_Hash(int * seqPair1, int * seqPair2, int numpoints);
void Create_AdjList(Node * Head, Hash ** HashTable, int numpoints);
void Find_Location(Hash ** HashTable, int * seqPair1, int * seqPair2, int numpoints);

#endif