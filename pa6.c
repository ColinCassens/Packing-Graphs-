#include "seqpair.h"

int main(int argc, char ** argv)
{
    //CHECK FOR A VALID NUMBER OF INPUTS
    if(argc != 3){
        return EXIT_FAILURE;
    }

    //Load the input from the file
    FILE * infile = fopen(argv[1], "r");
    int numpoints;
    Node * head = loadFromFile(infile, &numpoints);
    int * seqPair1 = loadSEQ(infile, numpoints);
    int * seqPair2 = loadSEQ(infile, numpoints);
    Hash ** HashTable = Create_Hash(seqPair1, seqPair2, numpoints, head);
    Create_AdjList(head, HashTable, numpoints);
    Find_Location(HashTable, seqPair1, seqPair2, numpoints);
    FILE * outfile = fopen(argv[2], "w");
    writeToFile(outfile, HashTable, numpoints);
    freeAll(head, HashTable, seqPair1, seqPair2, numpoints);
    fclose(outfile);
    fclose(infile);
    return EXIT_SUCCESS;
}

Node * loadFromFile(FILE * infile, int * num_points) {
    //Read in the number of points
    int num = fscanf(infile, "%d\n", num_points);
    if (num == 0) {
        return NULL;
    }
    //Read in all of the nodes and add them to the linked list
    int i = 1;
    Node * head;
    Node * temp;
    while (i <= *num_points) {
        if (i == 1) {
            head = calloc(1, sizeof(Node));
            fscanf(infile, "%d(%le,%le)\n", &head->ID, &head->width, &head->height);
            temp = calloc(1, sizeof(Node));
            fscanf(infile, "%d(%le,%le)\n", &temp->ID, &temp->width, &temp->height);
            head->next = temp;
            i++;
        } else {
            Node *next = calloc(1, sizeof(Node));
            fscanf(infile, "%d(%le,%le)\n", &next->ID, &next->width, &next->height);
            temp->next = next;
            temp = next;
        }
        i++;
    }
    return head;
}

int * loadSEQ(FILE * infile, int numpoints)
{
    //READ IN PART 3
    int i = 0;
    int * seqPair = calloc(numpoints, sizeof(int));
    while(i < numpoints){
        if(i == 0){
            fscanf(infile, "\n%d", &seqPair[i]);
            i++;
        }
        fscanf(infile, "%d", &seqPair[i]);
        i++;
    }
    return seqPair;
}

void writeToFile(FILE * outfile, Hash ** HashTable, int numpoints)
{
    for(int i = 1; i<=numpoints; i++){
        fprintf(outfile,"%d(%le,%le)\n", i, HashTable[i]->x, HashTable[i]->y);
    }
}

void freeAll(Node * head, Hash ** HashTable, int * seqPair1, int * seqPair2, int numpoints)
{
    free(seqPair1);
    free(seqPair2);
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        free(head);
        head = temp;
    }
    free(head);

    free(HashTable[0]);
    for(int x = 1; x<= numpoints; x++){
        if(HashTable[x]->rightof != NULL){
            HolderNode * temp1 = HashTable[x]->rightof;
            HashTable[x]->rightof = NULL;
            HolderNode * temp2 = temp1;
            while(temp1 != NULL){
                temp2 = temp1;
                temp1 = temp1->next;
                free(temp2);
            }
        }
        if(HashTable[x]->above != NULL){
            HolderNode * temp1 = HashTable[x]->above;
            HashTable[x]->above = NULL;
            HolderNode * temp2 = temp1;
            while(temp1 != NULL){
                temp2 = temp1;
                temp1 = temp1->next;
                free(temp2);
            }
        }
        free(HashTable[x]);
    }
    free(HashTable);
}