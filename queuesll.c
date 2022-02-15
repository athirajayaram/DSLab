/*
  Program Name : Queue using singly linked list
  Author Name  : Athira Jayaram
  roll no      : 224
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *front = NULL,*rear = NULL;

void enqueue(){
    int value;  
    struct Node *new = malloc(sizeof(struct Node));   
    
        printf("Enter the value : ");  
        scanf("%d",&value);  
        if(front==NULL && rear==NULL)
            front = new;
        else 
            rear -> link = new ;
        new -> data = value;
        new -> link = NULL;
        rear = new;
}

void dequeue(){
    if(front != NULL ){
        struct Node *ptr;
        ptr = front ;
        if(front == rear)
            front=rear=NULL;
        
        else
            front = front -> link;
        int temp = ptr -> data;
        printf("Element dequeued : %d \n",temp);
        free(ptr);
    }
    else
        printf("Empty queue !!!!")   ;
}

void display(){
    struct Node *ptr = front;
    if(ptr == NULL)
        printf("Queue is empty !!!!");
    else{
        printf("Elements in queue :\n");
        while(ptr != NULL){
            printf("%d\t",ptr -> data);
            ptr = ptr -> link;
        }
    }
}

int main(){
    int choice=0;     
    
    while(choice != 4)  
    {  
        printf("\n\n1)Enqueue\n2)Dequeue\n3)Show\n4)Exit\n");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  {   
                enqueue();  
                break;  
            }  
            case 2:  {  
                dequeue();  
                break;  
            }  
            case 3:  {  
                display();  
                break;  
            }  
            case 4:   {  
                break;   
            }  
            default:  {  
                printf("Please Enter valid choice ");  
            }   
        }  
    }  
    return 0;
}
