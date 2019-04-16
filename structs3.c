#include <stdio.h>
#include <stdlib.h>

struct cell{
    int fish;
    int peng;

};
int main ()
{
    struct cell cellno[100];

    int row,col,b,cno,cnof,cnop,cellc;
    printf("What is row\n");
    scanf("%d",&row);
    printf("What is col\n");
    scanf("%d",&col);
    int a= row * col;
    for (int i = 0; i < a; i++)
    {


            cellno[i+1].fish=0;
            cellno[i+1].peng=0;



    }
    printf("What cell to print (Just shows initial values = 0 \n");
    scanf("%d",&b);
    printf("Fish = %d, Peng = %d\n",cellno[b].fish,cellno[b].peng );
    for (int i = 0; i < a+1; i++)
    {

     printf("Which cell to modify, Enter cell no: (To finish data entry enter any number greater than r*c )\n");
     scanf("%d",&cno);
     if (cno<a+1)
         {
            printf("Enter Fish No:\n");
            scanf("%d",&cnof);
            printf("Enter Penguin No: \n");
            scanf("%d",&cnop);




            cellno[cno].fish=cnof;
            cellno[cno].peng=cnop;

         }
     else
         {
            printf("Finished Data entry\n");
            break;
         }

    }
    printf("Enter Cell no to see its values:\n");
    scanf("%d",&cellc);
    printf("For cellno %d, Fish:%d, Penguin:%d\n",cellc,cellno[cellc].fish,cellno[cellc].peng);

}
