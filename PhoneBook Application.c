#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>//use for utility function...//
#include<windows.h>
#define MAX_SIZE 100
/*structure for hold information a singel contact*/
typedef struct{
  char firstname[40];
  char lastname[40];
  char number[40];
  char email[50];
}Contact;
//enumerator for different search types
typedef enum {FIRST_NAME,LAST_NAME,MOBILE_NUMBER}src_t;
/*arry for hold contact*/
Contact Phonebook[MAX_SIZE];
//current size for phnbook array//
int currentSize = 0;
//function prototype//
void addcontact();
void viewcontact(int index); //take index for which index value we want to view//
void src(char *key,src_t type);//here we search key and if type value is 1 will search first name,2 search last name....//
void strtolower(char *str);//Utility Function use for convert string in lowercase..//
int main()
{   addcontact();//function call for add contact//
    viewcontact(0);
    //char src_for[]="sourabh";
    //src(src_for,LAST_NAME);
    return 0;
}

//create function add contact//
void addcontact()
{   if(currentSize==MAX_SIZE)
{
    puts("Contact couldn't Save: Phnebook is Full!!");
    return;
}
    Contact c;//c is a variable//
    printf("Enter First Name: ");
    gets(c.firstname);
    printf("Enter last Name: ");
    gets(c.lastname);
    printf("Enter MobileNumber: ");
    gets(c.number);
    printf("Enter Email Address: ");
    gets(c.email);
    printf("\n");
    Phonebook[currentSize] = c;
    ++currentSize;
}
//create function view contact//
void viewcontact(int index)
 {
    int i,a,A,z,Z;
    if(index<0 || index>=currentSize)
   {
       puts("Invalid Index!!");
       return;
   }
   for(i=0;i<currentSize;i++)
   {
       for(i=a ||A;i<=z||Z;i++)
       {

       }
   }
    Contact c = Phonebook[index];  //declare c for structure Contact And assign phonebook Index//
    printf("First Name = %s\n",c.firstname);
    printf("Last Name = %s\n",c.lastname);
    printf("Mobile Number = %s\n",c.number);
    printf("Email Address = %s\n",c.email);
    printf("\n");

}
//This function Modify The Given String By User..//
void strtolower(char *str)
{
    int i=0,len;
    for(i=0;i<len;i++)
    {
        str[i]=tolower(str[i]);//call functin tolower and pass arguments str[i]//
    }

}
void src(char *key,src_t type)
{   int found=0,i;
    strtolower(key);
    char content[41];

    if(type==FIRST_NAME) //search by first name//
    {
       for(i=0;i<currentSize;i++)
       {   strcpy(content,Phonebook[i].firstname);
           strtolower(content);
           if(strcmp(key, content)==0)
           {
             viewcontact(i);
             found=1;
           }
       }
    }
    else if(type==LAST_NAME)//src by last name//
    {   for(i=0;i<currentSize;i++)
       {  strcpy(content,Phonebook[i].lastname);
          strtolower(content);
          if(strcmp(key,content)==0)
           {
             viewcontact(i);
             found=1;
           }
       }
    }
    else if(type==MOBILE_NUMBER)//src by mobile number//
    {   for(i=0;i<currentSize;i++)
       { strcpy(content,Phonebook[i].number);
         strtolower(content);
         if(strcmp(key,content)==0)
           {
             viewcontact(i);
             found=1;
           }
       }
    }
    else{
    puts("Error: Invalid search type!!");
    return;
    }
    if(found=0)
    {
         puts("Error: No Results Found!!!");
    }
}
