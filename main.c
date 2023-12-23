#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
float *fill_array(int);
float sum_num(float *, int);
float avg_num(float *, int);
float max_num(float *, int);
float min_num(float *, int);


float *fill_array(int n)
{

    float *p,*pc;
    int i;
    pc =(float *)malloc(n * sizeof(float));
     for(p=pc,i=0;i<n;i++,pc++)
   {
       printf("please enter number: %d \n", i+1);
       scanf("%f",pc);
   }
   return p;
}
float sum_num(float *p, int n)
{
     float sum =0;
     float *pc;
     int i;
     for ( pc = p, i=0;i<n;i++,pc++)
           {
               sum+=*pc;
               printf("%f+",*pc);
           }
           return (sum);
}

float avg_num(float *p, int n)
{
               float sum;
               float avg;
               sum=sum_num(p,n);
               avg=sum/n;
               return (avg);
}
float max_num(float *p, int n)
{
    float *pc;
    float max = *p;
    int i;
               for (pc=p,i=0;i<n;i++,pc++)
                {
                  if (*pc>max)
                      max = *pc;
                }
                return(max);

}

float min_num(float *p, int n)
{
    float *pc;
    float min =*p;
    int i;
               for (pc=p,i=0;i<n;i++,pc++)
                {
                  if (*pc<min)
                      min = *pc;
                }
                return(min);
}

float *sort_num_asc(float *p,int n)
{
    float *pasc; //new array with new pointer
    pasc = (float *)malloc(n * sizeof(float));
    float *pcasc ;
    float *pj;
    int i;
    for (pcasc=pasc,i=0;i<n;i++,pcasc++)
            *pcasc = p[i];
    float asc;
       for (pcasc=pasc,i=0;i<n;i++,pcasc++)
                {
                    int j;
                    for (pj=pcasc,j=i+1;j<n;j++,pj++)
                    {
                         if (*pcasc>*pj)
                         {
                              asc = *pcasc;
                              *pcasc=*pj;
                              *pj=asc;
                         }
                    }
                }
                return pasc;
}

float *sort_num_desc(float *p, int n)
{
    float *pdsc;
    pdsc = (float *)malloc(n * sizeof(float));
    float desc;
    float *pcdsc ;
    float *pj;
    int i;
    for (pcdsc=pdsc,i=0;i<n;i++,pcdsc++)
            *pcdsc = p[i];
    for (pcdsc=pdsc,i=0;i<n;i++,pcdsc++)
                {
                    int j;
                    for (pj=pcdsc,j=i+1;j<n;j++,pj++)
                    {
                         if (*pcdsc<*pj)
                         {
                              desc = *pcdsc;
                              *pcdsc=*pj;
                              *pj=desc;
                         }
                    }
                }
                return pdsc;
}

void reversed(float *p, int n)
{
float *pc;
pc = p+n-1;
int i;
    for(i=n-1;i>=0;i--,pc--)
    printf("\n %f \n",*pc);
}
int main()
{
   int n;
   float *nf;
   //float *rev_numbers = (float *)malloc(n * sizeof(float));
   //float n[SIZE];
   char choice;
   int i;
   int j;
   float sum;
   float avg;
   float max;
   float min;
   float asc;
   float desc;
   printf("please enter Size: ");
   scanf("%d",&n);
   nf= fill_array(n);

   //menu list
   printf("a- sum \n");
   printf("b- average \n");
   printf("c- max \n");
   printf("d- min \n");
   printf("s- sort ASC \n");
   printf("f- sort DESC \n");
   printf("g- Reversed order \n");
   printf("e- exist \n");
   do
   {
   choice=getche();
   switch (choice)
   {
       case'a':
       case'A':

          sum=sum_num(nf, n);
          printf("\n =%f\n",sum );
           break;
       case'b':
       case'B':
           {

               avg = avg_num(nf,n);
               printf("\n average of numbers is:%f \n", avg);
                break;
           }
       case'c':
       case'C':
           {
                     max=max_num(nf,n);
                     printf(" \n the maximum number is %f \n", max);
                break;
           }
       case'd':
       case'D':
           {
                     min=min_num(nf,n);
                     printf(" \n the minimum number is %f \n", min);
                break;
           }
       case's':
       case'S':
           {
               float *pasc;
               float *pcasc ;
               pasc=sort_num_asc(nf,n);
                for (pcasc=pasc,i=0;i<n;i++,pcasc++)
                    printf(" %f \n", *pcasc);
             break;
           }
            case'f':
            case'F':
           {

                float *pdsc;
                float *pcdsc;
                pdsc=sort_num_desc(nf,n);
                for (pcdsc=pdsc,i=0;i<n;i++,pcdsc++)
                    printf(" %f \n", *pcdsc);
            break;
           }

       case'g':
       case'G':
           {
               reversed(nf,n);
               break;
           }
       case'e':
       case'E':
           {
               exit(0);
                break;
           }
       default:
        printf("\n please enter a valid choice \n");

           }
   }while (choice != 'e');

    return 0;
}
