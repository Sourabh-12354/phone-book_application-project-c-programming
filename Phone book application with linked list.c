#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person
{
    char name[40];
    char phone[40];
    struct person *next;
}per;
int n;
per *head=NULL;
per *temp;
FILE *fptr;
void insert();
void display();
void search();
void menu();
int main()
{
    menu();
}
void insert()
{
     fopen("E:\\Data Structure_Lab-PROJECT\\newprogram.txt","w");
     per * newper;
     newper=(per*)malloc(sizeof(per));
     printf("Enter Person Name:\n");
     scanf("%s",newper->name);
     printf("Enter Person Number:\n");
     scanf("%s",newper->phone);
     newper->next=NULL;
     if(head==NULL)
     {
         head=newper;
     }
     else
     {   temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newper;
     }
     printf("Contact Save Succesfully\n");
}
void display()
{
    fopen("E:\\Data Structure_Lab-PROJECT\\newprogram.txt","r");
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        printf("Friend %d\n",count);
        printf("Name:");
        printf("%s\n",temp->name);
        printf("Phone:");
        printf("%s\n",temp->phone);
        temp=temp->next;
    }
    menu();
}
void search()
{
   char data[30];
   printf("Enter name you want to search\n");
   scanf("%s",data);
   temp=head;
   while(temp!=data && strcmp(temp->name,data)!=0)
   {
       temp=temp->next;
   }
   if(temp==NULL)
   {
       printf("Contact not found\n");
   }
   else
   {
     printf("Contact found\n");
     printf("%s\n",temp->name);
     printf("%s\n",temp->phone);
   }
}
void menu()
{
    int code;
    printf("\t\t\t\t\t\tPHONEBOOK APPLICATIONS\n\n");
    printf("1.Add Contacts\n");
    printf("2.Display Contacts\n");
    printf("3.Search Contacts\n");
    scanf("%d",&code);
    switch (code)
    {
    case 1:
           insert(n);
           break;
    case 2:
           display();
           break;
    case 3:
           search();
           break;
    case 4:
        default:
        break;
    }

}
