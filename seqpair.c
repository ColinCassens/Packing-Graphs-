#include "seqpair.h"

Hash ** Create_Hash(int * seqPair1, int * seqPair2, int numpoints)
{
    Hash ** HashTable = calloc(numpoints+1, sizeof(Hash));
    int x = 0;
    for(x = 0; x < numpoints; x++){
        int value = seqPair1[x];
        Hash * tempHash = calloc(1,sizeof(Hash));
        tempHash->index1 = x;
        int i = 0;
        for(i = 0; i < numpoints; i++){
            if(seqPair2[i] == value) {
                tempHash->index2 = i;
            }
        }
        HashTable[value] = tempHash;
        tempHash = NULL;
    }
    return HashTable;
}

void Create_AdjList(Node * Head, Hash ** HashTable, int numpoints)
{
    int value;
    for(value = 1; value <= numpoints; value++){
        int comp;
        HashTable[value]->rightof = NULL;
        HashTable[value]->above = NULL;
        for(comp = 1; comp <= numpoints; comp++){
            if(HashTable[value]->index1 < HashTable[comp]->index1 && HashTable[value]->index2 < HashTable[comp]->index2){
                //The Comp is to the right of Value
                HolderNode * temp = calloc(1,sizeof(HolderNode));
                temp->value = comp;
                temp->next = HashTable[value]->rightof;
                HashTable[value]->rightof = temp;
            }
            if(HashTable[value]->index1 > HashTable[comp]->index1 && HashTable[value]->index2 < HashTable[comp]->index2){
                //The Comp is above Value
                HolderNode * temp = calloc(1,sizeof(HolderNode));
                temp->value = comp;
                temp->next = HashTable[value]->above;
                HashTable[value]->above = temp;
            }

        }
    }
}