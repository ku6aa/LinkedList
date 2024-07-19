#include <stdio.h>
#include <stdlib.h>

typedef struct  ElementOfTheList{
    int data;
    struct ElementOfTheList * next;
}ElementOfTheList_type; 

void push(ElementOfTheList_type **head, int number){
    ElementOfTheList_type *current;
    current=(ElementOfTheList_type *)malloc(sizeof(ElementOfTheList_type));

    current->data=number;
    current->next=(*head);
    *head=current;
}

void push_back(ElementOfTheList_type **head, int number){
    if (head == NULL){
        push(head, number);
    }else{
        ElementOfTheList_type *current= *head;
 
        while (current->next != NULL) {
            current = current->next;            //Searching for the last element
        }
    
        current->next = (ElementOfTheList_type *)malloc(sizeof(ElementOfTheList_type));
        current->next->data = number;
        current->next->next = NULL; 
    }

}


void printList(ElementOfTheList_type *head){
     if(head==NULL){
        printf("List is Empty   \n");
     }else{
        ElementOfTheList_type *current=head;
         while (current != NULL) {
            printf("Data: %i\n",current->data);
            current = current->next;            //Searching for the last element
        }
     } 
}


int listSize(ElementOfTheList_type *head){
    if(head==NULL){
        return 0;
    }else{
        ElementOfTheList_type *current=head;
        int counter = 0;
        while (current != NULL) {
            counter ++; 
            current = current->next;         //Searching for the last element
        }
        return counter;
     } 
}


void createListOfElements(ElementOfTheList_type **head, int numberOfElements){
    for(int i = 1; i<numberOfElements+1; i++){
        push_back(head, i);
    }
}

void pushByIndex(ElementOfTheList_type **head, int number, int index){
    if(index==0){
        push(head,number);
    }else if(index==listSize(*head)){
        push_back(head,number);
    }else{
        ElementOfTheList_type *current=*head;

        int counter = 0;
        while(counter!=index){
            counter ++;
            current = current->next; 
        }

        ElementOfTheList_type *tmp;
        tmp=current->next;
        current->next=(ElementOfTheList_type *)malloc(sizeof(ElementOfTheList_type));
        current->next->data=number;
        current->next->next=tmp;
        


    }
}


void pop_head(ElementOfTheList_type **head){
    ElementOfTheList_type *tmp = NULL;
        if (*head!=NULL) {
            tmp=(*head)->next;
            free(*head);
            *head=tmp; 
        }
}


void pop_last(ElementOfTheList_type **head){
    if((*head)->next==NULL){ 
        *head=NULL; 
    }else{
        ElementOfTheList_type *current=*head;
        while(current->next->next!= NULL) {
            current = current->next;
        }
        free(current->next);
        current->next=NULL;
    }   
}

void popByIndex(ElementOfTheList_type **head, int index){
    if(index==0){
        pop_head(head);
    }else if(index==listSize(*head)){
        pop_last(head);
    }else{
        ElementOfTheList_type *current=*head;

        int counter = 0;
        while(counter!=index){
            counter ++;
            current = current->next; 
        }

        ElementOfTheList_type *tmp;
        tmp=current->next;
        current->next= tmp->next;
        free(tmp);
        


    }    
}

int main(){

    ElementOfTheList_type *head;
    head = (ElementOfTheList_type *)malloc(sizeof(ElementOfTheList_type));
    head->data= 0;
    head->next=NULL;

    createListOfElements(&head, 20);
    printList(head);
    pushByIndex(&head, 44, 16);
    printList(head);
    printf("Number of elements: %d\n",listSize(head));
    popByIndex(&head, 9);
    printList(head);
    printf("Number of elements: %d\n",listSize(head));



    return 0;
}