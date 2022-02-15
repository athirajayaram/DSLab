/*
  Program Name : Student details using singly linked list
  Author Name  : Athira Jayaram
  roll no      : 224
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    char name[30];
    int rollno;
    int mark;
    struct Node *link;
};

struct Node *head = NULL;

void input(char *op){
    fflush(stdin);
    fgets(op, 30, stdin);
    int len;
    while(op[++len] != '\n');
    op[len] = '\0';
}

void frontinsert(){
    struct Node *new = malloc(sizeof(struct Node));
    new->link=head;
    printf("Enter the name of the student :");
    input(new->name);
    printf("Enter the rollno. of the student :");
    scanf("%d",&new->rollno);
    printf("Enter mark :");
    scanf("%d",&new->mark);
    head = new;
}

void endinsert(){
    struct Node *new = malloc(sizeof(struct Node));
    if(head==NULL){
        new->link=head;
        head=new;    
    }
    else{
        struct Node *ptr;
        for(ptr=head; ptr->link != NULL; ptr=ptr->link);
        ptr->link = new;
        new->link = NULL;
    }
    printf("Enter the name of the student :");
    input(new->name);
    printf("Enter the rollno. of the student :");
    scanf("%d",&new->rollno);
    printf("Enter mark :");
    scanf("%d",&new->mark);
}

 void randominsert(){
     struct Node *new = malloc(sizeof(struct Node));
     int key;
     if(head==NULL)
         printf("Empty list!!!\n");
         
    else{
        printf("Enter the rollno just before the rollno going to add :");
        scanf("%d",&key);
        printf("Enter the name of the student :");
        input(new->name);
        printf("Enter the rollno. of the student :");
        scanf("%d",&new->rollno);
        printf("Enter mark :");
        scanf("%d",&new->mark);
        struct Node *ptr;
        for(ptr=head;ptr->rollno != key && ptr != NULL;ptr=ptr->link);
        if(ptr==NULL)
            printf("Rollno not found !!!");
        else{    
            new->link = ptr->link;
            ptr->link = new;
        }
    }
 }

 void frontdelete(){
     if(head==NULL)
         printf("Empty list!!!\n");
     else{
         struct Node *temp = head->link;
         free(head);    // to delete node
         head = temp;
     }
 }

 void enddelete(){
     if(head==NULL)
         printf("Empty list!!!\n");
     else{
        struct Node *ptr;
        for(ptr=head;ptr->link->link!=NULL;ptr=ptr->link);
        free(ptr->link);
        ptr->link=NULL;
     }
 }

 void randomdelete(){
     int key;
     if(head==NULL)
         printf("Empty list!!!");
     else{
        printf("Enter the rollno to be deleted :");
        scanf("%d",&key);
        struct Node *ptr, *prevptr = NULL;
        
        for(ptr=head; ptr->rollno != key; ptr=ptr->link)
            prevptr = ptr;
        // If prevptr = NULL: XX --> [ptr] --> []
        if(prevptr == NULL)
            frontdelete();
        // [prevptr] --> [ptr] --> []
        // [prevptr] --> []
        else{
            prevptr->link = ptr->link;
            free(ptr);
        }
     }
 }

void display(){
    if(head == NULL){
        printf("Empty List!!\n");
        return;
    }
    printf("Roll\tName\tMarks\n");
    for(struct Node *ptr=head; ptr != NULL; ptr=ptr->link)
        printf("%d\t%s\t%d\n", ptr->rollno, ptr->name, ptr->mark);
}

 int main(){
     int choose=1;
    
    while(choose!=0){
         printf("Choose \n0)To stop\n1)To insert at beginning\n2)To insert at end\n3)To insert after a roll no.\n4)To delete from front\n5)To delete end\n6)To delete a roll no.\n7)To display student details\n");
         scanf("%d",&choose);

     switch(choose){
         case 0:
            break;
         case 1:
            frontinsert();
            break;
         
         case 2:
             endinsert();
             break;
         
         case 3:
             randominsert();
             break;
         
         case 4:
             frontdelete();
             break;
         
         case 5:
             enddelete();
             break;
         
         case 6:
             randomdelete();
             break;
         
         case 7:
             display();
             break;
         
         default :
            printf("Enter valid input");
     }
    }
     return 0;
     
 }