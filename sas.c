
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct gestion
{
	char Nom[20];
    char Prenom[20];
	char CIN[20];
	double  Montant;
};
int nb = 0;
struct gestion compte[100];
int a;

// fonction Recherche par CIN.
void    Recherche(struct gestion compte[],char ab[],int nb)
{
        system("cls");
        int i;

        for(i=0; i<nb; i++)
        {
            //comparition in two string
            if(strcmp(ab, compte[i].CIN) == 0)
            {
                printf("Nom: %s \n",compte[i].Nom);
                printf("Prenom: %s \n",compte[i].Prenom);
                printf("CIN: %s \n",compte[i].CIN);
                printf("Montant: %f\n",compte[i].Montant);
                break;
            }
        }

        if(i == nb)
            printf("Cette CIN no existe pas\n\n");
}
// fonction afficher votre compt
void    afficher(struct gestion compte[],int nb)
{
        system("cls");
        int i;

        for(i=0; i<nb; i++)
        {
            {
                printf("Nom: %s \n",compte[i].Nom);
                printf("Prenom: %s \n",compte[i].Prenom);
                printf("CIN: %s \n",compte[i].CIN);
                printf("Montant: %f\n",compte[i].Montant);
            }
        }
}
// fonction depot et retrait.
int    depot_retrait(struct gestion compte[],int nb,char ab[])
{
        int i;

        for(i=0; i<nb; i++)
        {
            //comparition in two string
            if(strcmp(ab, compte[i].CIN) == 0)
            {
            	return i;
            }
        }
	return -1;
}

// fonction tri Ascendant.
void	tri_Ascendant(struct gestion compte[],int nb)
{
    struct gestion temp;
	int i;
	int j;

        i = 0;
        while( i < nb)
        {
            j = i+1;
            while(j < nb)
            {
                if(compte[i].Montant > compte[j].Montant)
                {
                    //swap
                    temp = compte[i];
                    compte[i] = compte[j];
                    compte[j] = temp;
                }
            j++;
            }
        i++;
        }
}
// fonction tri_Descendant.
void	tri_Descendant(struct gestion compte[],int nb)
{
	struct gestion temp;
	int i;
	int j;

        i = 0;
        while( i < nb)
        {
            j = i+1;
            while(j < nb)
            {
                if(compte[i].Montant < compte[j].Montant)
                {
                    temp = compte[i];
                    compte[i] = compte[j];
                    compte[j] = temp;
                }
            j++;
            }
        i++;
        }
}

//fonction montant supérieur Ascendant.
void	montant_superieur_Ascendant(struct gestion compte[],double x, int nb)
{
	int i;
    tri_Ascendant(compte, nb);
    printf("\n");
    for(i = 0; i<nb; i++)
        {
            if(compte[i].Montant > x)
                printf("%lf \t ",compte[i].Montant);
        }
}

//fonction montant supérieur Descendant.
void	montant_superieur_Descendant(struct gestion compte[],double x, int nb)
{
	int i;
    tri_Descendant(compte, nb);
    printf("\n");
    for(i = 0; i<nb; i++)
        {
            if(compte[i].Montant > x)
                printf("%lf \t ",compte[i].Montant);
        }
}

// Fidélisation
void  Fidelisation(struct gestion compte[],int nb)
{
    tri_Ascendant(compte, nb);
    for(int c=nb-3 ;c<nb; c++)
    {
        if(c >= 0)
        {
            compte[c].Montant += compte[c].Montant * 0.013;
            printf("%lf \t ",compte[c].Montant);
        }
    }

}


int main()
{
    system("color 3");
    struct gestion compte[100];
	int choice; // clien operation
	int x; // nombre de compte
	int z; // depot_retrait
	int i; // cont
	int ch; // choi de case 3
	char ab[20]; // recherch de CIN case 3 ,2
	double a; // nombre de  montant case 3 ,5-6
	double d; // nombre de depot_retrait


	do
    {
        printf("\n\t\t\t\t\[Menu_Principal]\n\n");
        printf("Nombre De Compte: %d\n\n",nb);
        printf("1:Introduire un compte:\n");
        printf("2:Introduire plusieurs comptes:\n");
        printf("3:Affichage:\n");
        printf("4:Depot:\n");
        printf("5:Retrait:\n");
        printf("6:Fidelisation:\n\n");
        printf("0: Quitter\n\n");
        printf("se il vous plait choice votre Operations:=>");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("entre votre Nom:\n");
                scanf("%s", compte[nb].Nom);

                printf("entre votre Prenom:\n");
                scanf("%s", compte[nb].Prenom);

                printf("entre votre CIN:\n");
                scanf("%s", compte[nb].CIN);

                printf("entre votre Montant");
                scanf("%lf",&compte[nb].Montant);

                nb+=1;
            break;

            case 2:
                printf("combien de compte voulez vous!:");
                scanf("%d",&x);

                for(i=nb; i<nb+x; i++)
                {
                    printf("entre votre Nom:\n");
                    scanf("%s", compte[i].Nom);

                    printf("entre votre Prenom:\n");
                    scanf("%s", compte[i].Prenom);

                    printf("entre votre CIN:\n");
                    scanf("%s", compte[i].CIN);

                    printf("entre votre Montant");
                    scanf("%lf",&compte[i].Montant);
                }
                nb+=x;
                break;

            case 3:
               system("cls");
                while(1){
                printf("\n");
                printf("\t\t\t\t[Mune_Affichage]\n\n");
                printf("1: recherche ou CIN:\n");
                printf("2:afficher Par Ordre Ascendant:\n");
                printf("3:afficher Par Ordre Descendant:\n");
                printf("4:montant supérieur Ascendant:\n");
                printf("5:montant supérieur Descendant:\n\n");
                printf("0: Retour au mune principal:\n\n");

                printf("se il vous plait choice votre operation:=>");
                scanf("%d",&ch);
                if(ch == 0)
                    {
                    system("cls");
                    break;
                    }
                switch(ch)
                {
                    case 1:
                        printf("entre votre CIN:");
                        scanf("%s",ab);
                        Recherche(compte,ab,nb);
                        break;
                    case 2:
                        tri_Ascendant(compte,nb);
                        afficher(compte,nb);
                        break;
                    case 3:
                        tri_Descendant(compte,nb);
                        afficher(compte,nb);
                        break;
                    case 4:
                        system("cls");
                        printf("entre votre nombre:");
                        scanf("%lf",&a);
                        montant_superieur_Ascendant(compte, a, nb);
                        printf("\n\n");
                        break;
                    case 5:
                        system("cls");
                        printf("entre votre nombre:");
                        scanf("%lf",&a);
                        montant_superieur_Descendant(compte, a, nb);
                        printf("\n\n");
                        break;
                }
                }
                break;
            case 4:
                //Depot
                printf("entre votre CIN:");
                scanf("%s",ab);
                z =  depot_retrait(compte,nb,ab);
                printf("entre lo nombre de depot:");
                scanf("%lf",&d);
                compte[z].Montant += d;
                break;
            case 5:
                //Retrait
                printf("entre votre CIN:");
                scanf("%s",ab);
                z =  depot_retrait(compte,nb,ab);
                printf("entre lo nombre de Retrait:");
                scanf("%lf",&d);
                compte[z].Montant -= d;
                break;
            case 6:
                system("cls");
                //Fidélisation
                Fidelisation(compte,nb);

                break;
            default:
                    break;
        }

        }while(choice != 0);
}
