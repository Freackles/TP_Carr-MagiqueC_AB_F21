#include <stdio.h>
#include <stdlib.h>

//macro de la taille du carré
#define TAILLE 5

//type structuré pour les jeton de déplacement
typedef struct jeton{
    int nX;
    int nY;
} jeton;

//typedef int matrice[TAILLE][TAILLE];

//prototypes
void init (int tCarre[][TAILLE], jeton *jMoves);
void corriger (jeton *tMove);
void NordEst (jeton *jMove);
void NordOuest (jeton *jMove);
void vide(int tCarre[][TAILLE], jeton *jMove);
void afficher(int tCarre[][TAILLE]);


/** \brief Corps principal
 *
 * \param none
 * \return le carré magique
 *
 */

int main()
{
    int nCpt=2; //nombre à placer dans le carré
    jeton jMove;
    jeton *pMove = &jMove;
    int tGrille[TAILLE][TAILLE];

    printf("Programme du carre Magique\n");
    init(tGrille, pMove);
    //afficher(tGrille);

    do
    {
        NordEst(pMove);
        vide(tGrille, pMove);

        //placement du point
        tGrille[jMove.nX][jMove.nY]=nCpt;
        nCpt++;
    } while(nCpt<=TAILLE*TAILLE);

    afficher(tGrille);

    return 0;
}


/** \brief  initialisation de la matrice
 *
 * \param tCarre: matrice
 * \param tMove: jeton
 * \return 0
 *
 */

void init (int tCarre[][TAILLE], jeton *jMoves)
{
    int nI, nJ;
    for(nI=0; nI<=TAILLE-1; nI++)
    {
        for (nJ=0; nJ<=TAILLE-1; nJ++)
        {
            tCarre[nI][nJ]=0;
        }
    }

    jMoves->nX=TAILLE/2;
    jMoves->nY=TAILLE/2+1;
    tCarre[jMoves->nX][jMoves->nY]=1;
}


/** \brief Correction de la trajectoire quand on atteind les limite du tableau
 *
 * \param tMove: jeton
 * \return tMove
 *
 */

 void corriger (jeton *tMove)
 {
     if (tMove->nX<0)
     {
         tMove->nX=TAILLE-1;
     }
     if (tMove->nY>TAILLE-1)
     {
         tMove->nY=1;
     }
     if (tMove->nY<0)
     {
         tMove->nY=TAILLE-1;
     }
 }

 /** \brief deplacement vers le Nord Est
  *
  * \param jMove: jeton
  * \return jMove
  *
  */

  void NordEst (jeton *jMove)
  {
      jMove->nX-=1;
      jMove->nY+=1;
      corriger(jMove);
  }

   /** \brief deplacement vers le Nord Ouest
  *
  * \param jMove: jeton
  * \return jMove
  *
  */

  void NordOuest (jeton *jMove)
  {
      jMove->nX-=1;
      jMove->nY-=1;
      corriger(jMove);
  }

  /** \brief gestion du changement de direction en cas d'emplacement déjà utiliser
   *
   * \param tCarre: matrice
   * \param jMove: jeton
   * \return jMove: jeton
   *
   */

   void vide(int tCarre[][TAILLE], jeton *jMove)
   {
       do
       {
           NordOuest(jMove);
       } while (tCarre[jMove->nX][jMove->nY]|0);
   }

   /** \brief affichage du tableau
    *
    * \param matrice tCarre
    * \return le tableau à l'écran
    *
    */

    void afficher(int tCarre[][TAILLE])
    {
        int nI;
        int nJ;

        for (nI=0; nI<TAILLE; nI++)
        {
            for (nJ=0; nJ<TAILLE; nJ++)
            {
                printf("%d \t",tCarre[nI][nJ]);
            }
            printf("\n");
        }
    }
