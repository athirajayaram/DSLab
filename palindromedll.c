/*
  Program Name : Palindrome using doubly liked list
  Author Name  : Athira Jayaram
  roll no      : 224
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *prev,*link;
};

struct Node *head = NULL;

int palindrome(){
    struct Node *ptr, *front = head;
    int count = 0;
    for (ptr = head; ptr -> link != NULL; ptr = ptr -> link){
        count++;
    }
    count=count/2;
    int flag = 1;
    while(count!=0){
        if (front -> data != ptr ->data){
            flag = 0;
            break;
        }
        ptr = ptr -> prev;
        front = front -> link;
        count--;
    }
    if (flag == 1)
        return 1;
    else 
        return 0;
}

void insert(char c){
    struct Node *new = malloc(sizeof(struct Node));
    struct Node *ptr; 
    new -> data = c;
    new -> link = NULL;
    if (head == NULL){
        head = new;
        new -> prev = NULL;
    }
    else {
        for (ptr = head; ptr -> link != NULL; ptr = ptr -> link);
        new -> prev = ptr;
        ptr -> link = new;
    }
}

int main(){
    char c;
    printf("Enter the string :");
    scanf("%c", &c);
    while(c!='\n'){
        insert(c);
        scanf("%c",&c);
    }
    if(palindrome())
        printf("The given string is palindrome .");
    else
        printf("The given string is not a palindrome .");

    return 0;
}