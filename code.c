// code for normal linkedlist
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node n={.val = 0};

void display(node* list){
    while(list != NULL){
        printf("%d ",list->val);
        list = list->next;
    }
    printf("\n");
    //Print space separated integers from the linked list
    //list is the pointer pointing to the beginning of the linked list

}

node* createnod(){
    node *n = (node*)malloc(sizeof(node));
    return n;
}

node* insertAtBeginning(node* list,int val){
    node *n = createnod();
    n->val = val;
    if(list == NULL){
        list = n;
        list->next = NULL;
        return n;
    }
    n->next = list;
    return n;    //Write function to insert val at the beginning of the list and return a pointer pointing to beginning of the list

}

node* insertAtEnd(node* list,int val){
    node *n = createnod();
    n->val = val;
    if(list == NULL){
        list = n;
        list->next = NULL;
        return n;
    }
    node *first = list;
    while(list->next != NULL){
        list = list->next;
    }
    list->next = n;
    return first;
    //Write function to insert val at the end of the list and return a pointer pointing to beginning of the list

}

node* insertAtPosition(node* list,int val,int pos){
    //Write function to insert "val" at "pos" in the list and return a pointer pointing to beginning of the list

    node *n = createnod();
    n->val = val;
    if(pos==0){
        n->next = list;
        return n;
    }
    node *first = list;
    for(int i=1;i<pos;i++){
        list = list->next;
    }
    node *temp = list->next;
    list->next = n;
    n->next = temp;
    return first;
}

node* deleteFromBeginning(node* list,int* flag){
    //Delete from the beginning of the list and return pointer pointing to the beginning of the list
    //If deletion not possible set flag as -1 and return pointer to beginning of list
   if(list == NULL){
    *flag = -1;
    return list;
   }
    node *temp = list->next;
    list->next = NULL;
    return temp;
}

node* deleteFromEnd(node* list,int* flag){
    //Delete from the end of the list and return pointer to the beginning of the list
    //If deletion not possible set flag as -1 and return pointer to beginning of list
    if(list == NULL){
        *flag = -1;
        return list;
    }
    node *prev = list;
    node *temp = list->next;
    if(list->next == NULL){
        list = NULL;
        return list;
    }
    while(temp->next != NULL){
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = NULL;
    return list;
}

node* deleteFromPosition(node* list,int pos,int* flag){
    //Delete from the "pos" of the list and return pointer to the beginning of the list
    //If deletion not possible set flag as -1 and return pointer to beginning of list
    if(pos == 0){
        list = list->next;
        return list;
    }
    node *temp = list;
    for(int i=1;i<pos;i++){
        if(list == NULL){
            *flag = -1;
            return list;
        }
        list = list->next;
    }
    node *nxt;
    nxt = list->next;
    list->next = nxt->next;
    return temp;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    node* first = NULL;
    int opt,pos,val;
    scanf("%d",&opt);
    while(opt != 8){
        int flag = 0;
        switch(opt){
        case 1: display(first);
                break;
        case 2: scanf("%d",&val);
                first = insertAtBeginning(first,val);
                break;
        case 3: scanf("%d",&val);
                first = insertAtEnd(first,val);
                break;
        case 4: scanf("%d %d",&val,&pos);
                first = insertAtPosition(first,val,pos);
                break;
        case 5: first = deleteFromBeginning(first,&flag);
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        case 6: first = deleteFromEnd(first,&flag);
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        case 7: scanf("%d",&pos);
                first = deleteFromPosition(first,pos,&flag);
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        }
       scanf("%d",&opt);
    }


    return 0;
}
