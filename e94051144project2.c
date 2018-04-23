#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5011
FILE *fdic=NULL,*fnovel=NULL,*foutput=NULL;
char c='0';    //get the character of the dic
int value=0;    //store the sum of the ascii code
int i=0;    //control the temparray
int sumofascii=0;  //sumofascii
int searchvalue=0;   //searchvalue for search word
int e=0;
int s=0;
int y=0;
int w=0;
int a=0;     
int z=0;        //for initialize headnode
int k=0;    //control the tmporary of novel
int l=0;    //to control the hash key
char n='0';  //get the character of the novel
char temparray[1024]={'0'};  //to store the words temporary
typedef struct listnode *listpointer;
typedef struct listnode   //the structure of the data
{
   listpointer link;
   int count;
   char array1[max];
   
}listnode;
listpointer array[max];
int main(int argc ,char* argv[])
{
    for(z=0;z<5011;z++)     //initialize the headnode
   {
      array[z]=NULL;
}
    fdic=fopen(argv[1],"r");   //open the dictionary
     if(argc!=3)
    { 
      printf("error input parameter\n");
      return 0;
    }
     if(!fdic)
    {
     printf("input dic not found\n");
     return 0;
    }
    while(1)    //deal with words
     {
       i=0;
       sumofascii=0;
       a=0;
       
       while(1)  //deal with character
       {
          c=fgetc(fdic);   
          if(!(((c>='a'&&c<='z')||(c>='A'&&c<='Z'))||((c>='0'&&c<='9')||(c=='_'))))           
          break;
          if(c>='A'&&c<='Z')
          c=c+32;
          temparray[i]=c;  //to store the character
          a+=701;
          l=a*c;
          i++;
          sumofascii+=l;
         
       }  
     if(sumofascii!=0)
      {
       temparray[i]='\0';  //for using strcpy 
       value=sumofascii%5011;   //TO CALCULATE THE KEy OF HASH
       listpointer temp=NULL;   //NEWNODE
       temp=(listnode *)malloc(sizeof(listnode));  //give the memory
       temp->link=NULL;       //initialize the newnode
       temp->count=0;
       memset(temp->array1,'0',max);      
       strcpy(temp->array1,temparray);       //to store the words
       listpointer addptr=NULL;        //to add node  
       if(array[value]==NULL)    //check the word exist or not
          {
              array[value]=temp;  //add the newnode to array
              temp=NULL;
          }
       else                 //add the node for exist word
          {
              addptr=array[value];
             while(addptr->link!=NULL)
               {
                   addptr=addptr->link;
               }
               addptr->link=temp;
               temp->link=NULL;
               temp=NULL;
           }
         }
        if(c==EOF)
         break; 
    }
  fclose(fdic);
   fnovel=fopen(argv[2],"r");     //read the file of novel
     while(1)   //to search the word
     {
       
       sumofascii=0;
       k=0;
       e=0;
       while(1)       //deal with character
       {
          n=fgetc(fnovel);
          if(!(((n>='a'&&n<='z')||(n>='A'&&n<='Z'))||((n>='0'&&n<='9')||(n=='_'))))
          break;
          if(n>='A'&&n<='Z')
          n=n+32;
          temparray[k]=n;    //to store the character
          e+=701;
          s=e*n;
          k++;
          sumofascii+=s;
       }
       if(sumofascii!=0)
       {
         temparray[k]='\0';
         searchvalue=sumofascii%5011;   
         listpointer searchptr=NULL;
         searchptr=array[searchvalue];
         while(searchptr!=NULL)    //to search and calculate the word
        {
          
          if(strcmp(temparray,searchptr->array1)==0)   //if find the word and compare
           {
             (searchptr->count)++;
              break;
           }
           searchptr=searchptr->link;
        }
       }
        if(n==EOF)
        break;
       }
      fclose(fnovel);     //close the novel
      foutput=fopen("output.txt","w");   //open the output of the path
      fdic=fopen(argv[1],"r");     
     while(1)    //deal with words
     {
       
       i=0;
       sumofascii=0;
       y=0;
       while(1)  //deal with character
       {
          c=fgetc(fdic);
          if(!(((c>='a'&&c<='z')||(c>='A'&&c<='Z'))||((c>='0'&&c<='9')||(c=='_'))))
          break;
          if(c>='A'&&c<='Z')
          c=c+32;
          temparray[i]=c;  //to store the character
          y+=701;
          w=y*c;
          i++;
          sumofascii+=w;
       }
        if(sumofascii!=0)
       {
         temparray[i]='\0';
         searchvalue=sumofascii%5011;
         listpointer outputptr;
         outputptr=array[searchvalue];

         while(outputptr!=NULL)    //to search the word
        {

          if(strcmp(temparray,outputptr->array1)==0)   //if find the word
           {
              fprintf(foutput,"%d\n",outputptr->count);
              break;
           }
           outputptr=outputptr->link;
        }
        }
        if(c==EOF)
        break;
        }
        fclose(fdic);
        fclose(foutput);


        return 0;
     }







































     
           
      
       
















