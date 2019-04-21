#include "seqpair.h"

Hash ** Create_Hash(int * seqPair1, int * seqPair2, int numpoints, Node * head)
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

void Find_Location(Hash ** HashTable, int * seqPair1, int * seqPair2, int numpoints)
{
    //HCG FIRST NAVIGATE USING seqPair1, if nothing points to it x = 0
    //CALCULATE THIS BY USING THE SEQPAIR1, REPLACE THE NEXT NODE WITH THE MAXX OF THE NODES POINTING TOO IT PLUS THE WIDTH OF THAT NODE
    for(int x = 0; x < numpoints; x++) {
        int value = seqPair1[x];
        if (HashTable[value]->rightof != NULL) {
            double curx = HashTable[value]->x + HashTable[value]->width;
            HolderNode *temp = HashTable[value]->rightof;
            if(curx > HashTable[temp->value]->x){
                HashTable[temp->value]->x = curx;
            }
            while (temp->next != NULL) {
                temp = temp->next;
                if(curx > HashTable[temp->value]->x){
                    HashTable[temp->value]->x = curx;
                }
            }
        }
        value = seqPair2[x];
        if(HashTable[value]->above != NULL){
            double cury = HashTable[value]->y + HashTable[value]->height;
            HolderNode * temp = HashTable[value]->above;
            if(cury > HashTable[temp->value]->y){
                HashTable[temp->value]->y = cury;
            }
            while(temp->next != NULL){
                temp = temp->next;
                if(cury > HashTable[temp->value]->y){
                    HashTable[temp->value]->y = cury;
                }
            }
        }
    }
}
