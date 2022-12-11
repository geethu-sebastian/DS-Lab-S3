#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100
typedef struct{
    float coeff;
    int expo;
}poly;
poly terms[MAX_TERMS];
int avail;
void attach(float coefficient,int exponent)
{
  if(avail>=MAX_TERMS)
  {
    printf("Too many terms\n");
  }
  terms[avail].coeff=coefficient;
  terms[avail].expo=exponent;
  avail++;
}
int COMPARE(int a,int b)
{
    if(a>b)
      return -1;
    if(a==b)
      return 0;
    if(b>a)
      return 1;
}
void add(int STARTA,int FINISHA, int STARTB,int FINISHB,int *STARTD,int *FINISHD)
{   
    float coefficient;
    *STARTD=avail;
    while((STARTA<=FINISHA)&&(STARTB<=FINISHB))
    {
        switch(COMPARE(terms[STARTA].expo,terms[STARTB].expo))
        {
            case -1:
            {
                attach(terms[STARTB].coeff,terms[STARTB].expo);
                STARTB++;
                break;
            }
            case 0:
            {   
                coefficient=terms[STARTA].coeff+terms[STARTB].coeff;
                if(coefficient)
                {
                  attach(coefficient,terms[STARTA].expo);
                  STARTA++;
                  STARTB++;
                }
                break;
            }
            case 1:
            {
                attach(terms[STARTA].coeff,terms[FINISHA].expo);
                STARTA++;
            }
        }
    }
    for(;STARTA<=FINISHA;STARTA++)
      attach(terms[STARTA].coeff,terms[STARTA].expo);
    for(;STARTB<=FINISHB;STARTB++)
      attach(terms[STARTB].coeff,terms[STARTB].expo);
    *FINISHD=avail-1;
}
void polyprint(int start,int finish)
{
    printf("\n%fx^%d ",terms[start].coeff,terms[start].expo);
    for(int i=start+1;i<finish;i++)
    {
      if(terms[i].expo==0)
        printf("%d",terms[i].coeff);
      else
        printf("%fx^%d",terms[i].coeff,terms[i].expo);
    }
}
void main()
{
 int n1,n2,STARTA,FINISHA,STARTB,FINISHB,STARTD,FINISHD;
 printf("Enter number of terms of polynomial1\n");
 scanf("%d",&n1);
 printf("Enter number of terms of polynomial2\n");
 scanf("%d",&n2);
 STARTA=0;
 FINISHA=n1-1;
 STARTB=n1;
 FINISHB=n1+n2-1;
 avail=n1+n2;
 printf("Enter terms of polynomial1\n");
 for(int i=STARTA;i<FINISHA;i++)
 {
    printf("Enter coefficient");
    scanf("%f",&terms[i].coeff);
    printf("Enter exponent");
    scanf("%d",&terms[i].expo);
}
printf("Enter terms of polynomial2\n");
 for(int i=STARTB;i<FINISHB;i++)
 {
    printf("Enter coefficient");
    scanf("%f",&terms[i].coeff);
    printf("Enter exponent");
    scanf("%d",&terms[i].expo);
}
printf("Polynomial1");
polyprint(STARTA,FINISHA);
printf("Polynomial2");
polyprint(STARTB,FINISHB);

printf("Sum of polynomials:\n");
add(STARTA,FINISHA,STARTB,FINISHB,&STARTD,&FINISHD);
polyprint(STARTD,FINISHD);

}