/*
  Program Name : Stack using linked list
  Author Name  : Athira Jayaram
  roll no      : 224
*/
#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   {  
    int data;  
    struct node *next;  
};  
struct node *head=NULL;  
  
void main ()  {  
    int choice=0;     
    
    while(choice != 4)  {  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\n");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  {  
            case 1:  {   
                push();  
                break;  
            }  
            case 2:  {  
                pop();  
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
}  
void push ()  {  
    int value;  
    struct node *new = malloc(sizeof(struct node));   
    
        printf("Enter the value : ");  
        scanf("%d",&value);  
       
        new->data = value;  
        new->next = head;  
        head=new;  
               
        
        printf("Item pushed");            
}  
  
void pop()  {  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
     
        printf("Underflow.....\n");  
    
    else  {  
        item = head->data;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped : %d",item);  
          
    }  
}  
void display()  {  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  {  
            printf("%d\n",ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}