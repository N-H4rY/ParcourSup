#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

    /* **************************
        CONSTANTES SYMBOLIQUES
    ************************** */
#define CLS system("cls");
#define SOULIGNEMENT printf("\n\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
#define ENCADREMENT_HAUT printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
#define ENCADREMENT_BAS printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


    /* **************************
         TYPES et STRUCTURES
    *************************** */
typedef struct TypeSemaine
{
    char niv_alerte[15] ;
    unsigned short nb_infect , nb_mort ;
} TSemaine ;

typedef struct TypeVille
{
    char nom[30] ;
    unsigned long population ;
    unsigned short Nb_Semaine ;    //nombre de semaine sur lesquelles on a collecté des statistiques
    TSemaine infoSem[10] ;
} TVille ;



    /* **************************
        VARIABLES GLOBALES
    ************************** */
TVille *ville ;     // Pointeur sur un tableau de TVille
unsigned short comptVille = 0, comptSemaine = 0 ;   // Compteurs de Ville et Semaine
bool saisie_OK = false ;    //Variable booléene pour connaître si le tableau de villes est vide ou non


    /* *****************************
        PROTOTYPES DES FONCTIONS
    ******************************* */
void menu(void) ;
void saisie(void) ;
int lecture_stat_semaine(void) ;
void affichage(void) ;
void survivant(void) ;
void villeMortuaire(void) ;
int erreurReponse(int min, int max, int choix );
void afficherSaisieNulle(void) ;


    /* **************************
        FONCTIONS PRINCIPALES
    ************************** */
int main()
{
    CLS ENCADREMENT_HAUT
    printf("\t\t\t%c    S U I V I E     E T     A N A L Y S E     D U     C O R O N A   %c", 186,186);
    ENCADREMENT_BAS
    system("color 79");
    ville = malloc( sizeof(TVille) ) ; //Allocation mémoire pour une première saisie dans le tableau de villes
    menu() ;
    return(0) ;
}



/* ------------------------------------------------------
    Fonction : menu()
    Objectifs : Choix de l'utilisateur sur l'utilisation du programme
    Valeur retournée : aucune
--------------------------------------------------------*/
void menu(void)
{
    int reponse ;


    printf("\n\n\n\t\t        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\t\t    %c%c%c%c%c  M  E  N  U  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,180,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\t\t    %c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                                                         %c\n",179,192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217,179);
    printf("\t\t    %c   1 - Collecter des informations sur une ville                             %c\n",179,179);
    printf("\t\t    %c   2 - Afficher  les informations d%cj%c collect%ces                           %c\n",179 , 130, 133, 130,179);
    printf("\t\t    %c   3 - Afficher  le  nombre  de SURVIVANTS pour une ville                   %c\n" ,179,179);
    printf("\t\t    %c   4 - Conna%ctre le  TAUX de mortalit%c le plus %clev%c                        %c\n",179,140,130,130,130,179);
    printf("\t\t    %c                                                                            %c\n",179,179);
    printf("\t\t    %c   0 - Quitter le programme                                                 %c\n",179,179);
    printf("\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t      -> Entrez votre r%cponse ici : ", 130); scanf("%d", &reponse);

    reponse = erreurReponse(0 ,4 ,reponse) ;        //vérification du choix de l'utilisateur
    switch(reponse)         //Exécution d'un choix valide
    {
        case 1 :if (saisie_OK == true) comptVille++ ;                //Incrémenter le compteur de ville
                realloc( ville , (comptVille + 1)*sizeof(TVille) ) ;        //allouer une espace mémoire +importante pour le tableau de villes
                saisie() ; break ;
        case 2 : affichage() ;
                break ;
        case 3 : survivant () ;
                break;
        case 4 : villeMortuaire() ;
                break ;
        case 0 : fin_du_programme() ;  break ;
    }

}



/* ------------------------------------------------------
    Fonction : saisie()
    Objectifs : collecte des info sur chaque ville
    Valeur retournée : aucune
--------------------------------------------------------*/
void saisie(void)
{
    int reponse = 0 ;

        /// Titre pour la collecte de données
            CLS ENCADREMENT_HAUT
            printf("\t\t\t%c   COLLECTE     DES     INFORMATIONS     SUR     CHAQUE     VILLE   %c",186,186);
            ENCADREMENT_BAS

        /// Lecture nom + nb habitants de la ville en lecture
            printf("\n\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
            printf("\t\t\t\t%c INFORMATIONS SUR LA VILLE %2u : %c\n" ,179, comptVille+1, 179 ) ;
            printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
            printf("\t\t\t-> Nom        : ") ; gets(ville[comptVille].nom ); gets(ville[comptVille].nom );
            printf("\t\t\t-> Population : ") ; scanf("%lu" , &ville[comptVille].population ) ;

        saisie_OK = true ;      // Au moins une saisie a été faite

        /// Lecture des stats de chaque semaine
            do      reponse=lecture_stat_semaine();
            while (reponse==1) ;

        ///Affichage quand lecture stat terminée
            /// Titre pour la collecte de données
            CLS ENCADREMENT_HAUT
            printf("\t\t\t%c   COLLECTE     DES     INFORMATIONS     SUR     CHAQUE     VILLE   %c",186,186);
            ENCADREMENT_BAS

            ///Note
            printf("\n\n\n\a\a\a\t\t\t  Pour la ville de %c %s %c :",174, ville[comptVille].nom, 175);
            printf("\n\n\t\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196, 191);
            printf("\t\t\t\t%c%c%c%c%c N  O  T  E %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,180,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
            printf("\t\t\t\t%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c                              %c\n",179 ,192 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196, 217 ,179);
            printf("\t\t\t\t%c\tDONN%cES ENREGISTR%cES AVEC SUCC%cS\t%c\n",179,144 ,144,212,179 );
            printf("\t\t\t\t%c\t\t\t\t\t\t%c\n",179,179);
            printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217) ;

            menu() ;

}





/* ------------------------------------------------------
    Fonction : lecture_stat_semaine()
    Objectifs : collecte des statistiques sur chaque semaine
    Valeur retournée : aucune
--------------------------------------------------------*/
int lecture_stat_semaine(void)
{
  int choix = 0 ;

        ///Titre
                CLS ENCADREMENT_HAUT
                printf("\t\t\t%c   COLLECTE     DES     INFORMATIONS     SUR     CHAQUE     VILLE   %c",186,186);
                ENCADREMENT_BAS

        ///Afficher nom + nb habitants de la ville en lecture
                printf("\n\t\t\t-> Nom        : %s\n" , ville[comptVille].nom );
                printf("\t\t\t-> Population : %lu habitants\n" , ville[comptVille].population ) ;

        /// Sous-Titre
                printf("\n\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
                printf("\t\t\t\t%c STATISTIQUES DE LA SEMAINE %2u :%c\n" ,179, comptSemaine+1, 179 ) ;
                printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);

        ///Lecture Niveau Epidémique
                printf("\n\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
                printf("\t\t\t   %c %c  Niveau d'alerte %cpid%cmique possible  %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",196,196,130,130,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
                printf("\t\t\t  %c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                                 %c\n",179,192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217,179);
                printf("\t\t\t    1- D%ctection       2- Infection       3- Transmissions       4- Pand%cmie\n" ,  130, 130);
                printf("\t\t\t  %c                                                                           %c\n",179,179);
                printf("\t\t\t   %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
                printf("\n\t\t\t-> Le num%cro du niveau correspondant : ",130);scanf("%d", &choix);
                choix = erreurReponse(1 , 4 , choix );      //Verification de la reponse de l'utilisateur
                switch (choix)      //affectation du niveau d'alerte épidémique correspondant
                {
                    case 1 : strcpy(ville[comptVille].infoSem[comptSemaine].niv_alerte , "DETECTION    \0") ; break ;
                    case 2 : strcpy(ville[comptVille].infoSem[comptSemaine].niv_alerte , "INFECTION    \0") ; break ;
                    case 3 : strcpy(ville[comptVille].infoSem[comptSemaine].niv_alerte , "TRANSMISSIONS\0") ; break ;
                    case 4 : strcpy(ville[comptVille].infoSem[comptSemaine].niv_alerte , "PANDEMIE     \0") ; break ;
                }

        ///Lecture Nombres de morts et d'infectés
                printf("\t\t\t-> Le nombre d'infect%ces : " , 130) ; scanf("%lu" , &ville[comptVille].infoSem[comptSemaine].nb_infect) ;
                printf("\t\t\t-> Le nombre de morts    : ") ; scanf("%lu" , &ville[comptVille].infoSem[comptSemaine].nb_mort) ;

        ///Titre
                CLS ENCADREMENT_HAUT
                printf("\t\t\t%c   COLLECTE     DES     INFORMATIONS     SUR     CHAQUE     VILLE   %c",186,186);
                ENCADREMENT_BAS

        ///Note
            printf("\n\n\n\t\t\t  Pour la ville de %c %s %c :",174, ville[comptVille].nom, 175);
            printf("\n\n\t\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196, 191);
            printf("\t\t\t\t%c %c - N  O  T  E - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
            printf("\t\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196 ,196, 217);
            if (comptSemaine==0) printf("\t\t\t\t%c   STATISTIQUES DE LA %u%cre SEMAINE ENREGISTR%cE  %c\n\n",179,comptSemaine+1 ,138 ,144,179 );
            else printf("\t\t\t\t%c   STATISTIQUES DE LA %ui%cme SEMAINE ENREGISTR%cE %c\n\n",179,comptSemaine+1 ,138 ,144,179 );
            printf("\t\t\t\t%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c  %c %c %c %c %c %c %c %c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);

        ///Demander la suite à l'utilisateur
            printf("\n\n\n\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
            printf("\t\t\t  %c%c%c%c%c  M  E  N  U  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,180,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
            printf("\t\t\t  %c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                                         %c\n",179,192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217,179);
            printf("\t\t\t  %c   1 - Ajouter les statistiques de la %ui%cme semaine         %c\n",179,comptSemaine+2,138,179);
            printf("\t\t\t  %c   0 - Retourner au menu principal                          %c\n" ,179,179);
            printf("\t\t\t  %c\t\t\t\t\t\t\t       %c\n",179,179);
            printf("\t\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
            printf("\t\t\t    -> Entrez votre r%cponse ici : ", 130); scanf("%d",&choix);

                ville[comptVille].Nb_Semaine = comptSemaine ;
        ///Incrémenter comptSem si ajouter autre stat ,sinon remettre à 0
                comptSemaine = choix==1 ? comptSemaine+1 : 0 ;


        return (choix);
}






/* ------------------------------------------------------
    Fonction : affichage()
    Objectifs : Affichage des info collectées sur chaque ville
    Valeur retournée : aucune
--------------------------------------------------------*/
void affichage(void)
{
    int i ,j ,reponse ;

    CLS ENCADREMENT_HAUT   // Titre pour l'affichage des info des villes
    printf("\t\t\t%c   AFFICHAGE     DES     INFORMATIONS     SUR     CHAQUE     VILLE  %c",186,186);
    ENCADREMENT_BAS

    if ( saisie_OK == false ) afficherSaisieNulle() ;    //Aucune saisie n'a encore été faite au préalable
    else
    {   // Affichage des info de chaque ville
        for ( i=0 ; i <=comptVille ; i++)
        {       // Affichage des info générales sur chaque ville
                printf("\t\t\t- Nom: \"%s\"\n\t\t\t- Population: %lu habitants\n\t\t\t\n\n" ,ville[i].nom ,ville[i].population ,130 ,130 ) ;

                for ( j=0 ; j<=ville[i].Nb_Semaine ; j++ )
                {   // Affichage des données sur chaque semaine de chaque ville
                    printf("\t\t\t  SEMAINE %d :\t\t- nombre d'infect%cs : %6u personnes\n\t\t\t\t\t\t- nombre de morts   : %6u personnes\n\n" ,j+1 ,130 ,ville[i].infoSem[j].nb_infect ,ville[i].infoSem[j].nb_mort) ;
                }
                SOULIGNEMENT
        }
    }

    // Demander à l'utilisateur la suite ?
    menu();
}






/* --------------------------------------------------------
    Fonction : survivant()
    Objectifs : Afficher le nombre de survivants pour une ville
    Valeur retournée : aucune
---------------------------------------------------------- */
void survivant(void)
{
    int i=0 , j=0 , reponse =0 ,lesSurvivants=0 ;
    char villeRecherche[30] ;
    unsigned short TotalMort = 0, TotalInfecte = 0;
    bool villeTrouve = false ;

    CLS ENCADREMENT_HAUT        // Titre pour le nombre de survivants d'une ville
    printf("\t\t\t%c     NOMBRE      DE      SURVIVANTS      POUR     UNE     VILLE     %c",186,186);
    ENCADREMENT_BAS

    if ( saisie_OK == false ) afficherSaisieNulle() ;     //Aucune saisie n'a été faite au préalable
    else
    {
        printf("\n\n\t\t\tEntrez le nom de la ville %c %ctudi%ce : ",133 ,130 ,130);
        gets(villeRecherche); gets(villeRecherche);              // Lecture d'un nom de ville

        for ( i=0 ; i<=comptVille ; i++ )
        {   // Recherche dans toute la liste de ville
            if ( strcmp(villeRecherche , ville[i].nom) == 0 )
            {   // Si nom de ville correspondant
                villeTrouve = true ;
                for ( j=0 ; j<=ville[i].Nb_Semaine ; j++ )
                {   //comptage du nombre de morts et du nombre d'infectés
                    TotalInfecte += ville[i].infoSem[j].nb_infect ;
                    TotalMort += ville[i].infoSem[j].nb_mort ;
                }
            }
        }

        if ( villeTrouve == true )
        {   // Si au moins une correspondance trouvée
            lesSurvivants = TotalInfecte-TotalMort ;

            printf("\n\n\n\t\t\t----------- Ville: \" %s \" --------------------\n" , villeRecherche) ;
            printf("\t\t\tNombre d' infect%cs au total    : %6u personnes .\n" ,130 ,TotalInfecte) ;
            printf("\t\t\tNombre de morts au total       : %6u personnes .\n", TotalMort) ;

            if ( TotalInfecte<TotalMort )
            {   // Si l'on a plus de morts que d'infectés !!!!!
                printf("\n\a\a\a\t\t\tNOTE :\t<< Plus de morts que d'infect%cs !! >>\n", 130) ;
                printf("\t\t\t -> On compte %d survivants dans cette ville.\n" , lesSurvivants);
            }
            else printf("\n\t\t\tNombre de survivants au CORONA : %6d personnes" , lesSurvivants);

            puts("\n\t\t\t------------------------------------------------") ;
        }
        else
        {   //aucune correspondance
            printf("\n\a\a\a\t\t\tNOTE :\t<< Nous n'avons pas de donn%ces pour la ville \" %s \" !! >>\n", 130, villeRecherche) ;
            SOULIGNEMENT
            printf("\n\t\t\tLes villes pour lesquelles nous avons coll%cct%ces des donn%ces sont : \n", 130, 130, 130);
            for (i=0 ; i<=comptVille ; i++) printf("\t\t\t\t- %s\n", ville[i].nom) ;
        }
    }
    SOULIGNEMENT
    // Demander à l'utilisateur la suite?
    menu();
}






/* --------------------------------------------------------
    Fonction : villeMortuaire()
    Objectifs : Comparer le rapport mort/population pour chaque ville
                Afficher la ville pour laquelle ce rapport est le plus élevé
    Valeur retournée : aucune
---------------------------------------------------------- */
void villeMortuaire(void)
{
    float rapport = 0 , max = 0 , TotalMort = 0 ;
    int reponse = 0, i = 0, j = 0 , indiceVilleMax = 0;

    CLS ENCADREMENT_HAUT
    printf("\t\t\t%c    S U I V I E     E T     A N A L Y S E     D U     C O R O N A   %c",186,186);
    ENCADREMENT_BAS


    if (saisie_OK == false )
    {
                afficherSaisieNulle() ;
    }
    else
    {
        for ( i=0 ; i<=comptVille ; i++ )
        {
                TotalMort = 0 ;
                for ( j=0 ; j<=ville[i].Nb_Semaine ; j++) { TotalMort += ville[i].infoSem[j].nb_mort ; }
                rapport = TotalMort / ville[i].population ;

                if ( max<rapport )
                {   //Retenir le rapport le plus élevé et l'indice de la ville correspondante
                    max = rapport ;
                    indiceVilleMax = i ;
                }
        }

        printf("\n\n\n\t\t\t  --- Rapport de mortalit%c le plus %clev%c : %2.4f %c -----------------\n" ,130 , 130, 130, max*100, 37) ;
        printf("\n\t\t\t   - Nom de ville : \" %s \".", ville[indiceVilleMax].nom) ;
        TotalMort = 0 ;
        for ( j=0 ; j<=ville[indiceVilleMax].Nb_Semaine ; j++) {TotalMort += ville[indiceVilleMax].infoSem[j].nb_mort ;}
        printf("\n\t\t\t   - Nombre de morts par le CORONA : %.0f", TotalMort);
        printf("\n\t\t\t   - Population totale : %lu", ville[indiceVilleMax].population );
        puts("\n\t\t\t  -------------------------------------------------------------------\n\n\n");
    }

    menu();

}






/* ----------------------------------------------------------------
    Fonction : afficherSaisieNulle()
    Objectifs : Afficher une note qu'aucune lecture de donnée n'a encore été faite
                Demander à l'utilisateur ce qu'il veut faire par la suite
    Valeur retournée :Aucune
------------------------------------------------------------------ */
void afficherSaisieNulle(void)
{
    int reponse ;

    ///Note qu'on a aucune donnée
        printf("\n\n\a\a\a\n\t\t\t                  %c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,191);
        printf("\n\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c N O T E %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,180,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
        printf("\n\t\t\t      %c           %c%c%c%c%c%c%c%c%c%c%c                                   %c",179,192,196,196,196,196,196,196,196,196,196,217,179);
        printf("\n\t\t\t      %c << AUCUNE INFORMATION N'A %cT%c COLLECT%cE AU PR%cALABLE >> %c\n" ,179,144 ,144,144,144,179);
        printf("\t\t\t      %c                                                         %c\n",179,179);
        printf("\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);

        // Demander à l'utilisateur la suite?
        menu();
}






/* -------------------------------------------------------------------
    Fonction        : erreurReponse()
    Objectifs       : Afficher un messsage d'erreur jusqu'à
                        une réponse valide de l'utilisateur
    Paramètres       : 3 entiers:
                     - min, max: valeurs comprenant la réponse valide
                     - choix: réponse de l'utilisateur
    Valeur retournée : entier: une réponse valide
----------------------------------------------------------------------*/
int erreurReponse( int min, int max, int choix)
{
    while ( (choix<min) || (choix>max) )
    {
        printf("\a\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c E R R E U R %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
        printf("\t\t\t\t%c\t<<  %d  est une R%CPONSE INVALIDE!! >>        %c\n\t\t\t\t%c      Veuillez entrer un num%cro entre %d et %d       %c\n" ,179,choix ,144 ,179,179,130 ,min ,max ,179);
        printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
        printf("\t\t\t\t\t -> Entrez votre r%cponse ici : ", 130); scanf("%d", &choix);
    }
    return(choix) ;
}






/* --------------------------------------------------------------
    Fonction        : fin_du_programme()
    Objectifs       : Affichage quand on quitte le programme
    Valeur retournÚe : aucune
-----------------------------------------------------------------*/
void fin_du_programme(void)
{
            free(ville);
            system("cls"); system("color 0c");
            printf("\a\t\t\t  %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c  \n",207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207);
            //printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t        %c\n",207,201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,207);
            printf("\t\t\t%c\t\t     %c   F I N   D U   P R O G R A M M E   %c\t\t        %c\n",207,186,186,207);
            printf("\t\t\t%c\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t        %c\n",207,200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c   - Nom du programme  : %c %cpid%cmie_CORONA %c                                   %c\n",207,174,144,130,175,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c   - Objectif          : L'Organisation Mondiale de la Sant%c veut cr%cer un     %c\n",207,130,130,207);
            printf("\t\t\t%c                      programme pour suivre, analyser le CORONA(niveau de l'   %c\n",207,207);
            printf("\t\t\t%c                    %cpid%cmie, morts et infect%cs par semaine) dans chaque ville %c\n",207,130,130,130,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c   - Auteur            : ANDRIANARIMANANA  Ny  Hary  Aina  Fanilo              %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c   - Contact           : nyharyainafanilo%cgmail.com                            %c\n",207,64,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                 M E R C I...  %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t  %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c  ",207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207);
            exit(EXIT_SUCCESS);
}




/** PROBLEME 1 (--Résolu--): L'espace est une fin de le ligne pour scanf()
    SOLUTION : Utilisation d'une succession de deux fonctions gets()
    ex : Dans la chaîne "Los Angeles" ,
        La valeur stockée avec scanf() est "Los"

--------------------------------><----------------------------------

    PROBLEME 2 : type de valeur incompatible
    SOLUTION EVENTUELLE : utilisation de sscanf()
    Le programme boggue si le type de la réponse saisie par l'utilisateur diffère de
    celui attendu au clavier.

    ex: le programme attend une valeur de type int
        l'utilisateur entre un ou une suite de caractères,
        Alors le programme entre dans une boucle infinie ou
        s'arrête prématurément!
*/
