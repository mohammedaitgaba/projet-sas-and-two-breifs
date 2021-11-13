#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*printf("Hello world!\n");
       int c ,l;

    //tableau de deux dimension
    printf("donne le nombre des etudians : ");
    scanf("%d",&l);
    printf("donne le nombre des matier :");
    scanf("%d",&c);
    int t[l][c] , i , j ,a,b;
    for(i=0;i<l;i++)
     {
        for (j=0;j<c;j++)
        {
            printf("donne la note de d'etudiant %d dans la matier %d:",i+1 ,j+1 );
            scanf("%d",&t[l][c]);
        }
     }

     for(i=0;i<l;i++)
     {
        for (j=0;j<c;j++)
        {
            printf("  %d ",t[l][c]);

        }
        printf("\n");
     }
*/
int i,t[10],c,j ;
for(i=0;i<5;i++)
   {
    printf(" t[%d] : ",i+1);
    scanf("%d",&t[i]);
   }


for(i=0;i<4;i++){

        if(t[i]>t[i+1]){
            c=t[i];
            t[i]=t[i+1];
            t[i+1]=c;
        }

}

for(i=0;i<5;i++)
{
    printf(" %d : %d \n",i+1,t[i]);
}
    return 0;
}
