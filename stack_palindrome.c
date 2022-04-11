/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>


struct stack {
char str[10];
int tos;


};
 void push (struct stack* p, char c)
 {
      p->tos = p->tos+1;
      p->str[p->tos]=c;
      return;

 }
 char pop(struct stack* p)
 {
     char x = p->str[p->tos];
     p->tos=p->tos-1;
     return x;
 }


 int main()
 {
     struct stack s;
     int i;
     s.tos = -1;
     char string [10];
      printf("\n Enter a string :");
      scanf("%s",string);
     // printf("%s",string);

         int count =0;
         char var,var1;
     for(i=0; string[i] != '\0'; i++)
     {
         var =string[i];
         push(&s, var);
         //printf("\n");


     }
     for(i=0; string[i] != '\0'; i++)
     {
          var1 =pop(&s);
     }

   if(count == i)
   {
       printf("\npalindrome");


   }
   else{
       printf("Not palindrome");
   }


     return 0;
 }

