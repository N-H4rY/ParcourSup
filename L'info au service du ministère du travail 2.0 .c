#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* *********************************************
        DECLARATION DES CONSTANTES SYMBOLIQUES
********************************************* */
#define SOULIGNEMENT printf("\n\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
#define ENCADREMENT_HAUT printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
#define ENCADREMENT_BAS printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
#define CLS system("cls");


/* *********************************************
        DECLARATION DES STRUCTURES
********************************************* */
struct enreg_activite
{
    char *type ;
    long revenu_an ;
};

struct enreg_actif
{
    char *diplome ;
    unsigned short nb_an_trav ;
    struct enreg_activite activite ;
};



/** ********************************************
        DECLARATION DES VARIABLES GLOBALES
********************************************** */
unsigned short count, u ;
struct enreg_actif tab_actif[30] ;



/** ********************************************
        PROTOTYPES DES FONCTIONS UTILISEES
******************************************** */
void saisie(void);
void continuer_saisie(void);
void q3_nb_fonctionnaire(void);
void q4_nb_fonctionnaire(void) ;
void menu(void) ;
void continuer(void);





/** ********************************************
        FONCTIONS PRINCIPALES
********************************************* */
void main ()
{
    menu() ;
}








/** ************************************************
        DEFINITONS DES FONCTIONS
************************************************** */

/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : menu()
    Objectifs : Menu pour voir les différentes options
    Valeur retournée : aucune
--------------------------------------------------------*/
void menu()
{
    /* Variable locale */
    unsigned short choix ;

    CLS
    ENCADREMENT_HAUT
    printf("\t\t\t%c   M  E  N  U       S  U  R       L  E  S       A  C  T  I  F  S    %c",186,186);
    ENCADREMENT_BAS

    puts("\n\t\t1 - Saisie des actifs .");
    puts("\t\t2 - Affichage des actifs.");
    printf("\t\t3 - Nombre de fonctionnaires selon le nombre d'ann%ces sur le marche du travail.\n",130);
    printf("\t\t4 - Type d'activite ( Fonctionnaire ou prive ) dominant selon un dipl%cme .\n",147);
    puts("\n\t\t5 - Sortir du programmme.");
    SOULIGNEMENT
    printf("\n\t\tEntrez votre choix --> ");
    scanf("%u" , &choix);

    /* Vérification du choix et message d'erreur si érroné */
    while ( choix < 1 || choix > 5)
    {
        puts("\a\a\a\n\n\t\t!! ERREUR !! Ce numero ne correspond a aucun choix du menu ");
        printf("\t\tEntrez un numero (de 1 a 5) --> ");
        scanf( "%u" , &choix );
    }

    switch (choix)
    {
        case 1 : saisie() ;
            break ;
        case 2 : affichage() ;
            break ;
        case 3 : q3_nb_fonctionnaire();
            break;
        case 4 : q4_nb_fonctionnaire();
            break ;
        case 5 : fin_du_programme();
        break ;
    }

}







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : saisie()
    Objectifs : Entrer les informations sur chaque actif
    Valeur retournée : aucune
--------------------------------------------------------*/
void saisie(void)
{
    /* *****************************************************
                        AFFICHAGE TITRE
    ***************************************************** */
    CLS
    ENCADREMENT_HAUT
    printf("\t\t\t%c   R E N S E I G N E M E N T S     S U R     L E S     A C T I F S  %c",186,186);
    ENCADREMENT_BAS


    printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t%c %c Actif n%c %2u : %c",179, 207, 167, count + 1 ,179);
    printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\n\t\t  %c%c%c> Titre du dipl%cme le plus %clev%c : <%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,147,130,130,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t  %c\t1-CEPE\t\t2-BEPC\t\t3-BACC\t\t4-DTS            %c\n\t\t  %c\t5-LICENSE\t\t6-MASTER\t\t7-DOCTORAT       %c",179,179,179,179 );
    printf("\n\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t   Entrez le num%cro correspondant --> ",130);
    scanf( "%u" , &u );

     /* Vérification de la réponse de l'utilisateur
        et message d'erreur en l'occurence */
     while ( u < 1 || u > 7)
    {
        printf("\a\a\a\n\t\t!! ERREUR : Ce numero ne correspond a aucun dipl%cme de la liste !!\n",147);
        printf("\t\t   Entrez un autre num%cro (de 1 a 7) --> ",130);
        scanf( "%u" , &u );
    }

    /* Assignation de diplôme avec uniformité sur l'orthographe */
    switch (u)
    {
        case 1 : tab_actif[count].diplome = "CEPE    " ; break ;
        case 2 : tab_actif[count].diplome = "BEPC    " ; break ;
        case 3 : tab_actif[count].diplome = "BACC    " ; break ;
        case 4 : tab_actif[count].diplome = "DTS     " ; break ;
        case 5 : tab_actif[count].diplome = "LICENSE " ; break ;
        case 6 : tab_actif[count].diplome = "MASTER  " ; break ;
        case 7 : tab_actif[count].diplome = "DOCTORAT" ; break ;
    }

    printf("\n\n\t\t    -> Le %s est en possession depuis ? <-\n" , tab_actif[count].diplome );
    printf("\t\t    ( en nombre d'ann%ces ) --> ",130);
    scanf("%u", &tab_actif[count].nb_an_trav );

    printf("\n\n\t\t  %c%c%c> Type d'activit%c %cxerc%ce : <%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,130,130,130,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t  %c     1-FONCTIONNAIRE     2-SALARI%c DU PRIV%c     3-PROFESSION LIB%cRALE %c",179,144,144,144,179);
    printf("\n\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t   Entrez le num%cro correspondant --> ",130);
    scanf( "%u" , &u );

    /* Vérification de la réponse de l'utilisateur
        et message d'erreur en l'occurence */
    while ( u < 1 || u > 3)
    {
        puts("\a\a\a\n\t\t!! ERREUR : Ce numero ne correspond a aucun type d'activite de la liste !!");
        printf("\t\t   Entrez un numero (de 1 a 3) --> ");
        scanf( "%u" , &u );
    }
    /* Assignation du type d'activité avec uniformité de l'orthographe */
    switch (u)
    {
        case 1 : tab_actif[count].activite.type = "FONCTIONNAIRE      " ;
                break ;
        case 2 : tab_actif[count].activite.type = "SALARIE DU PRIVE   " ;
                break ;
        case 3 : tab_actif[count].activite.type = "PROFESSION LIBERALE" ;
                break ;
    }

    puts("\n\n\t\t    -> Revenu annuel brut ? <-");
    printf("\t\t  ( en Ariary ) --> ") ;
    scanf("%ld" , &tab_actif[count].activite.revenu_an);

    count++ ;

    SOULIGNEMENT

    continuer_saisie();
}







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : continuer_saisie()
    Objectifs : Demanderà l'utilisateur s'il veut
                ajouter un autre actif ou non
    Valeur retournée : aucune
--------------------------------------------------------*/
 void continuer_saisie(void)
 {
     unsigned short rep ;

     puts("\t\t -- Voulez-vous ajouter d'autres actifs");
     puts("\t\tou aller vers le menu ? (1=Ajout d'actif / 0=menu) --");
     printf("\t\t --> ");
     scanf("%u" , &rep ) ;

     /* Vérification de la réponse de l'utilisateur
        et affichage de message d'erreur en l'occurence */
     while( rep < 0 || rep > 1 )
     {
         CLS
         puts("\a\a\a\n\n\n\n\n\t\t\t\t-------------!!! ERREUR !!!-------------\n");
         puts("\t\t\t\t  Entrez 1 pour ajouter un autre actif ");
         puts("\t\t\t\t\t 0 pour ouvrir le menu.");
         printf("\n\t\t\t\tVotre choix --> ");
         scanf("%u" , &rep );
    }

     if (rep == 1) saisie();
        else menu() ;
 }







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : affichage()
    Objectifs : Afficher les différents actifs précédement saisis
    Valeur retournée : aucune
--------------------------------------------------------*/
void affichage(void)
{
    /* Variables locales */
    unsigned short i ;
    /* Titre*/
    CLS
    ENCADREMENT_HAUT
    printf("\t\t\t%c B A S E   D E   D O N N %c E S   A C T U E L L E S : %2u  A C T I F S%c",186,144, count,186);
    ENCADREMENT_BAS


    puts("\n Actif N \tDiplome \t        Depuis \t\t\tType d'activite \t\t        Revenu annuel ");
    puts(  " ======= \t======= \t        ====== \t\t\t================== \t\t        =============");

    //Parcourir tous les enregistrements
    for ( i=0 ; i < count ; i++)
        printf("\n    %u\t\t%s \t\t%u ans\t\t\t%s\t\t\t%u Ar\t\n", i+1, tab_actif[i].diplome, tab_actif[i].nb_an_trav, tab_actif[i].activite.type, tab_actif[i].activite.revenu_an);

    continuer() ;
}







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : q3_nb_fonctionnaire()
    Objectifs : Afficher le nombre de fonctionnaires ayant fini leurs
            études depuis un nombre d'années défini par l'utilisateur
    Valeur retournée : aucune
-----------------------------------------------------------------------------------------------------------------------------------------------*/
 void q3_nb_fonctionnaire()
 {
    /* *****************************************************
                        AFFICHAGE TITRE
    ***************************************************** */
    CLS
    ENCADREMENT_HAUT
    printf("\t\t\t%c         N O M B R E     D E     F O N C T I O N N A I R E S        %c",186,186);
    ENCADREMENT_BAS

    /* Variables locales */
    int i, N ;
    unsigned short result ;

    /* Briève explication */
    printf("\n\t\t    %c%c%c N O T E %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t    %c Le programme va vous demander d'entrer un nombre N (nombre d'ann%ces).         %c",179,130,179);
    printf("\n\t\t    %c Et affichera par la suite, le nombre de fonctionnaires ayant fini leurs %ctudes%c",179,130,179);
    printf("\n\t\t    %c depuis plus de N ann%ces.                                                      %c",179,130,179);
    printf("\n\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\n\t\t      Entrez le nombre N (nombre d'ann%ces) --> ",130);
    scanf("%d" , &N );

    /** Vérification de la valeur si positif et éventuel message d'erreur */
    while ( N < 0 )
    {
        printf("\a\a\a\n\t\t\t!! ERREUR !!\n\t\t     Entrez une valeur positive (nombre d'ann%ces) --> ",130);
        scanf( "%d" , &N );
    }

    for ( i = 0 ; i <= count ; i++ )
    {   //Compter fonctionnaire + N années de travail
        if ( (tab_actif[i].activite.type == "FONCTIONNAIRE      ") && (tab_actif[i].nb_an_trav >= N) )
            result += 1 ;
    }

    printf("\n\n\n\n\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n\t\t\t %c Parmis les actifs entres, on compte %2u Fonctionnaires %c" , 186,result,186 ) ;
    printf("\n\t\t\t %c\tayant fini les etudes depuis plus de %2d ans.\t %c\n" ,186, N ,186);
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    continuer();
}







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : q4_nb_fonctionnaire()
    Objectifs : Afficher "Vrai" si le nombre de fonctionnaires
            est supérieur à ceux qui ne le sont pas pour
            un diplôme défini par l'utilisateur
    Valeur retournée : aucune
--------------------------------------------------------*/
void q4_nb_fonctionnaire()
{
     /* *****************************************************
                        AFFICHAGE TITRE
    ***************************************************** */
    CLS
    ENCADREMENT_HAUT
    printf("\t\t\t%c\t     T  Y  P  E         D'  A  C  T  I  V  I  T  %c           %c",186,144,186);
    ENCADREMENT_BAS

    /* VAriables locales */
    unsigned short a, result ;
    int i ;
    char *D ;

    /* Briève explication */
    printf("\n\t\t    %c%c%c%c%c%c%c%c N O T E %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t    %c   Le programme vous demande de choisir un dipl%cme.                            %c",179,147,179);
    printf("\n\t\t    %c   Puis affiche \"VRAI\" si le nombre de fonctionnaires est sup%crieur %c ceux     %c",179,130,133,179);
    printf("\n\t\t    %c   qui ne le sont pas, parmis la liste d'actifs entr%cs pr%cc%cdement.            %c",179,130,130,130,179);
    printf("\n\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);

    /* Choix du diplôme par l'utilisateur */
    printf("\n\t\t    %c%c%c Choisissez un dipl%cme parmis la liste suivante : %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,147,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t    %c\t1-CEPE\t\t2-BEPC\t\t3-BACC\t\t4-DTS              %c\n\t\t    %c\t5-LICENSE\t\t6-MASTER\t\t7-DOCTORAT         %c",179,179,179,179 );
    printf("\n\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t     Entrez le num%cro du dipl%cme --> ",130,147);
    scanf("%u" , &a );

    /* Vérification de la valeur entrée par l'utilisateur
        et message d'erreur en l'occurence */
     while ( a < 1 || a > 7)
    {
        printf("\a\a\a\n\n\t\t\t\t----!! ERREUR !!----\n \t\t\tCe num%cro ne correspond %c aucun dipl%cme de la liste\n",130,133,147);
        printf("\n\t\t\t  Entrez un num%cro (de 1 %c 7) --> ",130,133);
        scanf( "%u" , &a );
    }

    /* Assignation de diplôme avec uniformité sur l'orthographe */
    switch (a)
    {
        case 1 : D = "CEPE    " ; break ;
        case 2 : D = "BEPC    " ; break ;
        case 3 : D = "BACC    " ; break ;
        case 4 : D = "DTS     " ; break ;
        case 5 : D = "LICENSE " ; break ;
        case 6 : D = "MASTER  " ; break ;
        case 7 : D = "DOCTORAT" ; break ;
    }

    for ( i = 0 ; i < count ; i++)
    {   //compter le nombre de fonctionnaires
        if ( ( tab_actif[i].activite.type == "FONCTIONNAIRE      " ) && ( tab_actif[i].diplome == D ) )
            result += 1 ;
    }

    if ( 2 * result > count )   // nb_fonctionnaire > nb_non_fonctionnaire  ==>  result > count - result  ==>  2*result > count
    {   //Plus de fonctionnaires
        puts("\n\n\n\t\t\t\t-------- ^-^ VRAI ^-^ --------\n");
        printf("\t\t====> Pour le diplome %s, on compte plus des fonctionnaires que ceux travaillant\n", D);
        puts("\t\tdans le secteur concurentiel dans la liste d'actifs actuelle. ");
    }

    else
    {
        if (2*result < count )
        {   //Moins de fonctionnaires
        puts("\n\n\n\t\t\t\t-------- *o* FAUX *o* --------\n");
        printf("\t\t====> Pour le diplome %s, on compte moins des fonctionnaires que ceux travaillant\n", D);
        puts("\t\tdans le secteur concurentiel dans la liste d'actifs actuelle. ");
        }
        else
        {   //autant de fonctionnairesque de privés
        puts("\n\n\n\t\t\t\t-------- *o* VRAI *o* --------\n");
        printf("\t\t====> Pour le diplome %s, on compte autant de fonctionnaires que travailleurs\n", D);
        puts("\t\tdans le secteur prive dans la liste d'actifs actuelle. ");
        }
    }

    continuer();
}







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction : continuer()
    Objectifs : Choix entre menu ou quitter le programme
    Valeur retournée : aucune
--------------------------------------------------------*/
void continuer(void)
{
    /* Variables locales */
     unsigned short rep ;

    printf("\n\n\t\t\t%c%c%c%c C O N T I N U E R ? %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    printf("\n\t\t\t%c  Voulez-vous retourner vers le menu ou quitter ? %c",179,179);
    printf("\n\t\t\t%c\t(1=Menu / 0=Fermer le programme) \t   %c",179,179);
    printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf("\t\t\t  Votre r%cponse ici --> ",130);
     scanf("%u" , &rep ) ;

     /* Vérification de la réponse de l'utilisateur
        et affichage de message d'erreur en l'occurence */
     while( rep < 0 || rep > 1 )
     {
         CLS
         puts("\a\a\a\n\n\n\n\n\t\t\t\t-------------!!! ERREUR  !!!---------------");
         puts("\n\t\t\t\t\tEntrez   1 pour ouvrir le menu ");
         puts("\t\t\t\t\t\t 0 pour quitter");
         printf("\n\t\t\t\t\tVotre choix --> ");
         scanf("%u" , &rep );
     }

     if (rep == 1 ) menu();
        else fin_du_programme() ;
 }







/** -----------------------------------------------------------------------------------------------------------------------------------------
    Fonction        : fin_du_programme()
    Objectifs       : Affichage quand on quitte le programme
    Valeur retournée : aucune
-----------------------------------------------------------------*/
void fin_du_programme(void)
{
            system("cls"); system("color 0c");
            printf("\a\t\t\t  %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c  \n",207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207);
            //printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t        %c\n",207,201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,207);
            printf("\t\t\t%c\t\t     %c   F I N   D U   P R O G R A M M E   %c\t\t        %c\n",207,186,186,207);
            printf("\t\t\t%c\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t        %c\n",207,200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c   - Nom du programme  : %c Population_Active %c                                 %c\n",207,174,175,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c                                                                               %c\n",207,207);
            printf("\t\t\t%c   - Objectif          : Le minist%cre du travail veut %ctudier la population    %c\n",207,138,130,207);
            printf("\t\t\t%c                       active %c l'aide d'un syst%cme d'information ( Le dipl%cme %c\n",207,133,138,147,207);
            printf("\t\t\t%c                       le plus %clev%c, dur%ce de travail, l'activit%c ) .         %c\n",207,130,130,130,130,207);
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
