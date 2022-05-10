#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node{
    int val;
    char name[20];
    char phonenumber[20];
    char emailid[20];
    struct node *next;
}node;

node n={.val = 0};

void display(node* list){
    while(list != NULL){
        printf("%s \n",list->name);
        printf("%s \n",list->phonenumber);
        printf("%s \n",list->emailid);
        list = list->next;
    }
    printf("\n");
}

node* createnod(){
    node *n = (node*)malloc(sizeof(node));
    return n;
}

node* insertAtEnd(node* list,node* n){
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
}

node* deleteFromEnd(node* list,int* flag){
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


void search(node *list){
    char phonenumber[20];
    printf("\nEnter the phonenumber to search for \n");
    scanf("%s\n",phonenumber);
    while(list != NULL){
        if(list->phonenumber == phonenumber){
            printf("Employee found with name %s\n",list->name);
            break;
        }
        list = list->next;
    }
    printf("\n");
}

int main() {
    node* first = NULL;
    int opt,pos,val;
    printf("Enter your choice 1. display 2. insert 3. delete 4.search\n");
    scanf("%d",&opt);
    node *n;
    char name[20];
    char email[20];
    char phonenumber[20];
    while(opt != 8){
        int flag = 0;
        switch(opt){
        case 1: display(first);
                break;
        case 2:
            n = createnod();
            printf("\nEnter the name of the employee\n");
            scanf("%s",n->name);
            printf("\nEnter the phonenumber of the employee\n");
            scanf("%s",n->phonenumber);
            printf("\nEnter the email of the employee\n");
            scanf("%s",n->emailid);
            first = insertAtEnd(first,n);
            break;
        case 3: first = deleteFromEnd(first,&flag);
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        case 4:
            search(first);
            break;
        }
        printf("Enter your choice 1. display 2. insert 3. delete 4.search\n");
       scanf("%d",&opt);
    }


    return 0;
}
