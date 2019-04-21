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
        Node * temp = head;
        while(temp->ID != value){
            temp = temp->next;
        }
        HashTable[value]->height = temp->height;
        HashTable[value]->width = temp->width;
        HashTable[value]->x = 0;
        HashTable[value]->y = 0;
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

        /// Dont NEED
        HashTable[value]->leftof = NULL;
        HashTable[value]->below = NULL;
        ///

        for(comp = 1; comp <= numpoints; comp++){
            if(HashTable[value]->index1 < HashTable[comp]->index1 && HashTable[value]->index2 < HashTable[comp]->index2){
                //The Comp is to the right of Value
                HolderNode * temp = calloc(1,sizeof(HolderNode));
                temp->value = comp;
                temp->next = HashTable[value]->rightof;
                HashTable[value]->rightof = temp;
            }
            //////
            //Dont Need
            if(HashTable[value]->index1 > HashTable[comp]->index1 && HashTable[value->index2 > HashTable[comp]->index2]){
                //The Comp is to the left of Value
                HolderNode * temp = calloc(1,sizeof(HolderNode));
                temp->value = comp;
                temp->next = HashTable[value]->leftof;
                HashTable[value]->leftof = temp;
            }
            ///

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

void Find_Location(Hash ** HashTable, int * seqPair1, int * seqPair2, int numpoints)
{
    //HCG FIRST NAVIGATE USING seqPair1, if nothing points to it x = 0
    //CALCULATE THIS BY USING THE SEQPAIR1, REPLACE THE NEXT NODE WITH THE MAXX OF THE NODES POINTING TOO IT PLUS THE WIDTH OF THAT NODE
    for(int x = 0; x <= numpoints; x++) {
        value = seqPair1[x];
        if (HashTable[value]->rightof != NULL) {
            curx = HashTable[value]->x;
            HolderNode *temp = HashTable[value]->rightof;
            int maxx = HashTable[temp->value]->x;
            while (temp->next != NULL) {
                temp = temp->next;

            }

        }
    }
}
