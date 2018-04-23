#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 6
char key1='0';
int i=0;
int j=0;
int k=0;  
int a=0,b=0;  //control the loop for sorting
int temp=0;
int flag=0;
int in=1;  //for storing the number of user's input
int searchwordoutput=0;
int n=0;    //to tag the order
int order[100]={'0'};
char input[7]={'0'};
char key2='0';
int search=0;  //to search the node for output
typedef struct node *listpointer;   //data struct
typedef  struct node{
    int count;
    listpointer link;
    char data[7];
}node;
listpointer nodeptr[1000];
listpointer array[26];
listpointer output[1000];
listpointer searchpointer=NULL;
int main()
{
     while(1)
    {    
  
     flag=0;
     scanf("%c%*c",&key1);
     if(array[key1]==NULL)
     {
       
       printf("no search resault!Input the full name to store:\n");
       scanf("%s%*c",input);
       //fgets(input,7,stdin);
       listpointer temp1=NULL;
       temp1=(node*)malloc(sizeof(node));
       temp1->count=1;
       strcpy(temp1->data,input);
       temp1->link=NULL;
       array[input[0]]=temp1;
       if(array[input[0]]!=NULL)
       printf("123");
       free(temp1);
       printf("the input has stored in the memory!\n");
       flag=1;  
     }
    if((array[key1]!=NULL)&&(flag!=1))
    { 
        printf("123");
        j=0;
        memset(order,0,sizeof(int));
        while(1) 
        {
         listpointer ptr=array[key1];  //assign the count to array
         if(ptr==NULL)
         {
         order[j]=99999;
         break;
         } 
         order[j]=ptr->count;
         j++;
         ptr=ptr->link;   
        }
         while(order[a]!=99999)    //sort the array
       {
         b=a+1;
         while(order[b]!=99999)
          {
          if(order[a]<order[b])
            {
             temp=order[b];
             order[a]=order[b];
             order[b]=temp;
            }
            b++;
          }
         a++;
       }
       search=0;
       n=0;
        while(order[search]!=99999)    //the part of making the mark
       {
         searchpointer=array[key1];
         while(1)
        { 
          if(searchpointer==NULL)
          break;
          if(order[search]==searchpointer->count)   //print the resualt according to the key word
         {
          output[n]=searchpointer;    //to mark the output
          printf("%d. %s\n",n,searchpointer->data);
          n++;
          break;
         }
          searchpointer=searchpointer->link;
        }
        search++;
       }
     printf("if no search resault input 0,or input the number of the name : \n");
     scanf("%d%*c",&in);
     i=1;
     j=0;
      if(in==0)    //no correspond resault continue to the second keyword
     { 
       while(i!=6)
      {
       printf("\033c");
        for(k=0;k<i;k++)
        {
        printf("%c\n",input[k]);
        }
        memset(order,0,sizeof(int));
        scanf("%c%*c",&key2);
        input[i]=key2;
        searchpointer=array[key2];
        while(searchpointer!=NULL)
       {
         if(i==1)
         {
           if(searchpointer->data[1]==input[1])
           {
           order[j]=searchpointer->count;
           j++;
           }
           searchpointer=searchpointer->link;
         }
             if(i==2)
         {
            if((searchpointer->data[1]==input[1])&&(searchpointer->data[2]==input[2]))
           {
           order[j]=searchpointer->count;
           j++;
           }
           searchpointer=searchpointer->link;
         }
            if(i==3)
         {
            if((searchpointer->data[1]==input[1])&&(searchpointer->data[2]==input[2])&&(searchpointer->data[3]==input[3]))
           {
           order[j]=searchpointer->count;
           j++;
           }
           searchpointer=searchpointer->link;
         }
            if(i==4)
         {
            if((searchpointer->data[1]==input[1])&&(searchpointer->data[2]==input[2])&&(searchpointer->data[3]==input[3])&&(searchpointer->data[4]==input[4]))
           {
           order[j]=searchpointer->count;
           j++;
           }
           searchpointer=searchpointer->link;
         }
         if(i==5)
         {
            if((searchpointer->data[1]==input[1])&&(searchpointer->data[2]==input[2])&&(searchpointer->data[3]==input[3])&&(searchpointer->data[4]==input[4])&&(searchpointer->data[5]&&input[5]))
           {
           order[j]=searchpointer->count;
           j++;
           }
           searchpointer=searchpointer->link;   
         } 
       }
       order[j]=99999;
        a=0;
        b=0;
         while(order[a]!=99999)    //sort the array
       {
         b=a+1;
         while(order[b]!=99999)
          {
          if(order[a]<order[b])
            {
             temp=order[b];
             order[a]=order[b];
             order[b]=temp;
            }
            b++;
          }
         a++;
       }
       search=0;
       n=0;
        while(order[search]!=99999)    //the part of making the mark
       {
         searchpointer=array[key1];
         while(1)
        {
          if(searchpointer==NULL)
          break;
          if(order[search]==searchpointer->count)   //print the resualt according to the key word
         {
          output[n]=searchpointer;    //to mark the output
          printf("%d. %s\n",n,searchpointer->data);
          n++;
          break;
         }
          searchpointer=searchpointer->link;
        }
        search++;
       }
        i++;
        printf("if no search resault input 0,or input the number of the name : \n");
        scanf("%d%*c",&in);
        if(in!=0)
        break;
       }  //while!=6 
     }  //in==0
     printf("the data has inputed\n");
     (output[n]->count)++;
   }
}
}

