#include "seqpair.h"
///
/// \param head : the head of the linked list
/// \param numpoints : the number of nodes
/// \param seqPair1 : the horizontal sequence pair
/// \param seqPair2 : the vertical sequence pair
void create_Graphs(Node * head, int numpoints, int * seqPair1, int * seqPair2)
{
    //arrHoriz[0] is the top horizontal row
    //arrHoriz[1] is the bottom horizontal row
    Node * arrHoriz [2];
    int i = 1;
    Node * temp = head;
    while(temp->ID != seqPair1[i] && temp->next != NULL){
        temp = temp->next;
    }
    arrHoriz[0] = calloc(1,sizeof(Node));
    arrHoriz[0]->height = temp->height;
    arrHoriz[0]->width = temp->width;
    arrHoriz[0]->ID = temp->ID;
    Node * zeroEnd = arrHoriz[0];
    i++;
    temp = head;
    while(temp->ID != seqPair1[i] && temp->next != NULL){
        temp = temp->next;
    }
    arrHoriz[1] = calloc(1,sizeof(Node));
    arrHoriz[1]->height = temp->height;
    arrHoriz[1]->width = temp->width;
    arrHoriz[1]->ID = temp->ID;
    Node * oneEnd = arrHoriz[1];
    i++;
    while(i < numpoints - 1){
        temp = head;
        while(temp->ID != seqPair1[i] && temp->next != NULL){
            temp = temp->next;
        }
        Node * newNode = calloc(1,sizeof(Node));
        newNode->height = temp->height;
        newNode->width = temp->width;
        newNode->ID = temp->ID;
        zeroEnd->next = newNode;
        zeroEnd = newNode;
        i++;
        temp = head;
        while(temp->ID != seqPair1[i] && temp->next != NULL){
            temp = temp->next;
        }
        Node * new2 = calloc(1,sizeof(Node));
        new2->height = temp->height;
        new2->width = temp->width;
        new2->ID = temp->ID;
        oneEnd->next = new2;
        oneEnd = new2;
        i++;
    }


    //CREATE THE VERTICAL ARRAY
    Node ** arrVert = calloc((numpoints-2)/2, sizeof(Node));
    i = 1;
    int x = 0;
    while(x < (numpoints - 2)/2){
        temp = head;
        while(temp->ID != seqPair2[i] && temp->next != NULL){
            temp = temp->next;
        }
        arrVert[x] = calloc(1,sizeof(Node));
        arrVert[x]->height = temp->height;
        arrVert[x]->width = temp->width;
        arrVert[x]->ID = temp->ID;
        //arrVert[x] = temp;
        i++;
        temp = head;
        while(temp->ID != seqPair2[i] && temp->next != NULL){
            temp = temp->next;
        }
        Node * temp2 = calloc(1, sizeof(Node));
        temp2->ID = temp->ID;
        temp2->height = temp->height;
        temp2->width = temp->width;
        arrVert[x]->next = temp2;
        i++;
        x++;
    }
}