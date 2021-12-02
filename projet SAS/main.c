#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nb_compt=0;
void tri_comptes_des(char T_NP[50][20],char T_cin[50][20],double T_Montant[50],int nb_compt);

void tri_comptes_des(char T_NP[50][20],char T_cin[50][20],double T_Montant[50],int nb_compt)
{
    int i,j;
    double temp_montant;
    char tempcin[20],tempnp[20];
    for(i=0; i<nb_compt-1; i++)
    {
        for(j=i+1; j<nb_compt; j++)
        {
            if(T_Montant[i]<T_Montant[j])
            {
                temp_montant=T_Montant[j];
                T_Montant[j]=T_Montant[i];
                T_Montant[i]=temp_montant;

                strcpy (tempcin,T_cin[j]);
                strcpy(T_cin[j],T_cin[i]);
                strcpy(T_cin[i],tempcin);

                strcpy(tempnp,T_NP[j]);
                strcpy(T_NP[j],T_NP[i]);
                strcpy(T_NP[i],tempnp);


            }
        }
    }
}
int main()
{
    int choix_compt,choix_argent,i,a,nombre_cb,loop,choix_affichage,j,Z;
    int R=0;
    char recherche [20];
    double T_Montant[50],re,dep,temp_montant,chiffre;
    char T_cin[50][20],T_NP[50][20];

    do
    {
        do
        {
            system("cls");

            printf("                                   Aplication Gestion Bancaire\n");
            printf("                            Tu peut choisir un des operation suivants : \n\n\n");
start:
            printf("________________________________\n");
            printf("1 :Introduire un compte bancaire \n");
            printf("2 :Introduire plusieurs comptes bancaires\n");
            printf("3 :Operations \n");
            printf("4 :Affichage \n");
            printf("5 :Fidelisation \n");
            printf("6 :Quitter l’application\n");
            printf("________________________________\n");
            scanf("%d",&choix_compt);

        }
        while(choix_compt<1 || choix_compt >6);
        //choix 1 : un seul compte________________________________
        switch (choix_compt)
        {
        case 1:
        {
            system("cls");
            printf("                                Introduire un compte bancaire\n\n");
            printf("                         ______\n");
            printf("SVP entre le NOM :");
            scanf("%s",T_NP[nb_compt]);
            printf("SVP entre le CIN :");
            scanf("%s",T_cin[nb_compt]);
            printf("SVP entre le Montant :");
            scanf("%lf",&T_Montant[nb_compt]);
            nb_compt++;
            system("cls");

            goto start;
        }
        //choix 2 : plusieur comptes________________________
        case 2 :
        {
            {
                system("cls");
                printf("Introduire plusieur compte bancaire\n\nCombien du comptes tu va cree :\n");
                scanf("%d",&nombre_cb);
            }
            loop = nb_compt;//avoid boucle infinie
            for(i=loop; i<loop+nombre_cb; i++)
            {
                printf("ndonner le nom du compte %d :",i+1);
                scanf("%s",T_NP[nb_compt]);
                printf("donner cin du compte %d :",i+1);
                scanf("%s",T_cin[nb_compt]);
                printf("donner le montent du  compte :");
                scanf("%lf",&T_Montant[nb_compt]);
                nb_compt++;
            }
            system("cls");
            goto start;
        }

        case 3 : // les operation_________________________
        {
            system("cls");
            if(nb_compt==0)
            {
                printf("svp cree un compt pour affecte une operation  !!!\n\n\n");
                goto start;
            }
            else
            {
start2:
                printf("Entre le CIN pour affecte un operation :\n");
                scanf("%s",recherche);
                for(i=0; i<nb_compt; i++)
                {
                    if(strcmp(recherche,T_cin[i])==0)
                    {
                        Z=i;
                        break;
                    }
                    else if(strcmp(recherche,T_cin[i])!=0)
                        Z=-1;
                }
                if (Z==-1)
                {
                    printf("le compte est introuvable!!!!!\n");
                    goto start2;
                }
                else
                {
                    printf("le compte tu es choisi est : %s %s %lf dh \n\n",T_NP[Z],T_cin[Z],T_Montant[Z]);
                    do
                    {
                        printf("press 1 pour retirer de l’argent. \npress 2 pour deposer de l'argent \n");
                        scanf("%d",&choix_argent);
                    }
                    while(choix_argent<1 || choix_argent>2);
                    switch(choix_argent)
                    {
                    case 1 :

                        printf("combien de l'argent tu va retirer du compte de %s\n",T_NP[Z]);
                        scanf("%lf",&re);
                        while(re>T_Montant[Z])
                        {
                            printf("vous pouver retirer moins que votre Montant \n votre Montant est :%lf ",T_Montant[Z]);
                            scanf("%lf",&re);
                        };

                        T_Montant[Z]=T_Montant[Z]-re;
                        printf("le montant actuel de %s est %lf dh\n",T_NP[Z],T_Montant[Z]);
                        system("pause");
                        system("cls");
                        goto start;


                    case 2 :

                        printf("combien de l'argent tu va deposer ");
                        scanf("%lf",&dep);
                        T_Montant[Z]=T_Montant[Z]+dep;
                        printf("le nouveau montrant est %lf dh\n",T_Montant[Z]);
                        system("pause");
                        system("cls");
                        goto start;



                    }
                }
            }
        }//choix 4 afichage________________________
        case 4 :
        {
            system("cls");
            if(nb_compt==0)
            {
                printf("svp cree un compt pour afficher une operation !!!\n\n\n");
                goto start;
            }
            else
                system("cls");
            printf("1: Par Ordre Ascendant \n");
            printf("2: Par Ordre Descendant \n");
            printf("3: Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit)\n");
            printf("4: Par Ordre Descendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit)\n");
            printf("5: Recherche par CIN\n");
            do
            {
                printf("*\n veillier choisir un type d'affichage de la liste ci dessus \n");
                scanf("%d",&choix_affichage);
            }
            while(choix_affichage <1 || choix_affichage>5);
            switch(choix_affichage)
            {
            //les choix d'affichage
            case 1 :

                printf("affichage des comptes par Ordre Ascendant \n");
                //fonction de trie
                tri_comptes_des(T_NP,T_cin,T_Montant,nb_compt);
                for(i=nb_compt-1; i>=0; i--)
                {
                    printf("%s____:%lf dh\n",T_NP[i],T_Montant[i]);

                }
                system("pause");
                system("cls");
                goto start;


            case 2 :
                printf("affichage des comptes par Ordre descendant \n");

                tri_comptes_des(T_NP,T_cin,T_Montant,nb_compt);

                for(i=0; i<nb_compt; i++)
                {
                    printf("%s____:%lf dh\n",T_NP[i],T_Montant[i]);
                }
                system("pause");
                system("cls");
                goto start;


            case 3 :

                printf("svp entre un chiffre \n");
                scanf("%lf",&chiffre);
                printf("les comptes ayont un montant plus grand que %lf par Ordre Ascendant :\n",chiffre);

                tri_comptes_des(T_NP,T_cin,T_Montant,nb_compt);

                for(i=nb_compt-1; i>=0; i--)
                {
                    if (T_Montant[i] > chiffre)
                    {
                        printf("%s____:%lf dh\n",T_NP[i],T_Montant[i]);
                    }
                }
                system("pause");
                system("cls");
                goto start;

            case 4 :
                printf("svp entre un chiffre \n");
                scanf("%lf",&chiffre);
                printf("les comptes ayont un montant plus grand que %lf par Ordre descendant :\n",chiffre);

                tri_comptes_des(T_NP,T_cin,T_Montant,nb_compt);


                for(i=0; i<nb_compt; i++)
                {
                    if (T_Montant[i] > chiffre)
                    {
                        printf("%s____:%lf dh\n",T_NP[i],T_Montant[i]);
                    }
                }
                system("pause");
                system("cls");
                goto start;


            case 5 :
                printf("Entre le CIN pour chercher un compte :\n");
                scanf("%s",recherche);
                for(i=0; i<nb_compt; i++)
                {
                    if(strcmp(recherche,T_cin[i])==0)
                    {
                        Z=i;
                        break;
                    }
                    else if(strcmp(recherche,T_cin[i])!=0)
                        Z=-1;
                }
                if(Z!=-1)
                    printf("%s %s %lf dh \n\n",T_NP[Z],T_cin[Z],T_Montant[Z]);
                else if (Z=-1)
                    printf("ce compte est introuvale \n\n");
                system("pause");
                system("cls");
                goto start;

            }//switch choix d'affichage

        }//affichage switch
        case 5 :
            //fidelisation__________
            while(nb_compt==0)
            {
                system("cls");
                printf("svp cree des comptes pour affecter la fidelisation !!!!\n ");
                goto start ;
            }
            printf("la fidelisation est affectue \n");

            tri_comptes_des(T_NP,T_cin,T_Montant,nb_compt);
            if(nb_compt<3)
                i=nb_compt-1;
            else
            {
                for(i=0; i<nb_compt; i++)
                {
                    if (T_Montant[i]==T_Montant[i+1])
                    {
                        continue;
                    }
                    if(T_Montant[i]>T_Montant[i+1])
                        R++;
                    if (R==3)
                        break;
                }
            }
            system("cls");


            for(j=0; j<=i; j++)
            {
                printf("%s  __:%lf dh+ %lf dh = %f dh\n",T_NP[j],T_Montant[j],T_Montant[j]*1.3/100,T_Montant[j]+T_Montant[j]*1.3/100);
            }
            system("pause");
            system("cls");
            goto start;

        }//first switch menu select

    }
    while(choix_compt!=6);
    return 0;

}
