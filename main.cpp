#include <iostream>
#include <string>
#include <fstream>
#include "Joueur.h"
#include "Staff.h"
#include "Delegation.h"
#include "Match.h"
#include "Groupe.h"
#include "Competition.h"
using namespace std;

int main()
{
    int x,y,y1,y2,n;
    Competition c;
    cout<<"voulez vous "<<endl;
    cout<<"1) commencer une nouvelle competition avec des nation par defaut"<<endl;
    cout<<"2) terminer votre derniere competition"<<endl;
    cout<<"3) commencer une nouvelle competiton avec vos propre nations de choix"<<endl;
    cin>>n;
    switch (n)
    {
    case 1 :

        c.download_competition_par_defaut();
        break;
    case 2:

        c.download_competition();
        break;

    case 3 :
        int i;
        Competition c(i);
        break;
    }

 do
 {
     cout<<"********************COUPE_Du_MONDE********************"<<endl;
     cout<<"      1)Les delegations"<<endl;
     cout<<"      2)Jouer un match"<<endl;
     cout<<"      3)informations"<<endl;
     cout<<"      4)meilleur joueur de la competition"<<endl;
     cout<<"      5)Nombre de points dans les poules"<<endl;
     cout<<"      6)Classement finale des equipes"<<endl;
     cout<<"      0)quitter"<<endl;
     cout<<"******************************************************"<<endl;
     cout<<"entrez votre choix: ";
     cin>>x;
     if (x==1)
     {
         do
         {   cout<<endl;
             c.afficher();
             cout<<" 33)quitter"<<endl;
             cout<<" 0)Retour"<<endl;
             cout<<endl;
             cout<<"entrez votre choix: ";
             cin>>y;
             if ((y>=1)&&(y<=32))
             {   do
                 {

                 cout<<endl;
                 cout<<"1)  les joueurs "<<endl;
                 cout<<"2)  les staff"<<endl;
                 cout<<"3)  quitter"<<endl;
                 cout<<"0)  Retour"<<endl;
                 cout<<"entrez votre choix: ";
                 cin>>y1;
                 if (y1==3)
                   { c.enregistrer_competition();
                     return 0;}
                 if (y1==1)
                 { do
                      {
                      cout<<endl;
                      cout<<" 1)  Ajouter "<<endl;
                      cout<<" 2)  Modifier"<<endl;
                      cout<<" 3)  quitter"<<endl;
                      cout<<" 0)  Retour"<<endl;
                      cout<<"entrez votre choix: ";
                      cin>>y2;
                      if(y2==1)
                      {
                          c.ajouter_joueur(y-1);
                          c.enregistrer_competition();


                      }
                      if(y2==2)
                      {
                          c.modifier_joueur(y-1);
                          c.enregistrer_competition();

                      }
                      if(y2==3)
                      {
                          c.enregistrer_competition();
                          return 0;
                      }
                    }while(y2!=0);
                 }
                 if(y1==2)
                  {do
                     {
                      cout<<endl;
                      cout<<" 1)  Ajouter "<<endl;
                      cout<<" 2)  Modifier"<<endl;
                      cout<<" 3)  quitter"<<endl;
                      cout<<" 0)  Retour"<<endl;
                      cout<<"entrez votre choix: ";
                      cin>>y2;
                      if (y2==1)
                      {
                          c.ajouter_staff(y-1);
                          c.enregistrer_competition();

                      }
                      if(y2==2)
                        {
                          c.modifier_staff(y-1);
                          c.enregistrer_competition();

                        }
                      if(y2==3)
                        {
                          c.enregistrer_competition();

                          return 0;
                        }
                      }while(y2!=0);
                  }
              }while(y1!=0);
             }
             if (y==33)
                {c.enregistrer_competition();
                return 0;}

         }while (y!=0);
     }
     if (x==2)
     {
         do
         {   cout<<endl;
             cout<<" 1)Phase de poule"<<endl;
             cout<<" 2)Phase d'elimination"<<endl;
             cout<<" 3)quitter"<<endl;
             cout<<" 0)Retour"<<endl;
             cout<<endl;
             cout<<"entrez votre choix: ";
             cin>>y;
             if (y==1)
             {do
              {
               cout<<endl;
               c.afficherresgroupe();
               cout<<" 0)retour "<<endl;
               cout<<"entrez votre choix: ";
               cin>>y1;
               if (y1==1)
               {  do
                   {cout<<endl;
                    c.afficher_match_poule(0);
                   cout<<"0) retour"<<endl;
                   cout<<"entrez votre choix: ";
                   cin>>y2;
                   if (y2==1)
                   {
                     c.jouer_match(0,0);
                     c.enregistrer_competition();

                   }
                   if (y2==2)
                   {
                     c.jouer_match(0,1);
                     c.enregistrer_competition();

                   }
                    if (y2==3)
                   {
                     c.jouer_match(0,2);
                     c.enregistrer_competition();

                   }
                   if (y2==4)
                   {
                     c.jouer_match(0,3);
                     c.enregistrer_competition();

                   }
                   if (y2==5)
                   {
                     c.jouer_match(0,4);
                     c.enregistrer_competition();

                   }
                   if (y2==6)
                   {
                     c.jouer_match(0,5);
                     c.enregistrer_competition();

                   }
                   }while (y2!=0);
               }
               if (y1==2)
               {
                    do

                   {cout<<endl;
                    c.afficher_match_poule(1);
                   cout<<"0) retour"<<endl;
                   cout<<"entrez votre choix: ";
                   cin>>y2;
                   if (y2==1)
                   {
                     c.jouer_match(1,0);
                     c.enregistrer_competition();

                   }
                   if (y2==2)
                   {
                     c.jouer_match(1,1);
                     c.enregistrer_competition();

                   }
                   if (y2==3)
                   {
                     c.jouer_match(1,2);
                     c.enregistrer_competition();

                   }
                   if (y2==4)
                   {
                     c.jouer_match(1,3);
                     c.enregistrer_competition();

                   }
                   if (y2==5)
                   {
                     c.jouer_match(1,4);
                     c.enregistrer_competition();

                   }
                   if (y2==6)
                   {
                     c.jouer_match(1,5);
                     c.enregistrer_competition();

                   }
                   }while (y2!=0);
               }
               if (y1==3)
               {
                    do
                   {cout<<endl;
                    c.afficher_match_poule(2);
                   cout<<"0) retour"<<endl;
                   cout<<"entrez votre choix: ";
                   cin>>y2;
                   if (y2==1)
                   {
                     c.jouer_match(2,0);
                     c.enregistrer_competition();

                   }
                   if (y2==2)
                   {
                     c.jouer_match(2,1);
                     c.enregistrer_competition();

                   }
                   if (y2==3)
                   {
                     c.jouer_match(2,2);
                     c.enregistrer_competition();

                   }
                   if (y2==4)
                   {
                     c.jouer_match(2,3);
                     c.enregistrer_competition();

                   }
                   if (y2==5)
                   {
                     c.jouer_match(2,4);
                     c.enregistrer_competition();

                   }
                   if (y2==6)
                   {
                     c.jouer_match(2,5);
                     c.enregistrer_competition();

                   }
                   }while (y2!=0);
               }
               if (y1==4)
               {
                   do
                   { cout<<endl;
                     c.afficher_match_poule(3);
                     cout<<"0) retour"<<endl;
                     cout<<"entrez votre choix: ";
                     cin>>y2;
                   if (y2==1)
                   {
                     c.jouer_match(3,0);
                     c.enregistrer_competition();

                   }
                   if (y2==2)
                   {
                     c.jouer_match(3,1);
                     c.enregistrer_competition();

                   }
                   if (y2==3)
                   {
                     c.jouer_match(3,2);
                     c.enregistrer_competition();

                   }
                   if (y2==4)
                   {
                     c.jouer_match(3,3);
                     c.enregistrer_competition();

                   }
                   if (y2==5)
                   {
                     c.jouer_match(3,4);
                     c.enregistrer_competition();

                   }
                   if (y2==6)
                   {
                     c.jouer_match(3,5);
                     c.enregistrer_competition();

                   }
                   }while (y2!=0);
               }
               if (y1==5)
               {
                    do
                     {cout<<endl;
                      c.afficher_match_poule(4);
                     cout<<"0) retour"<<endl;
                     cout<<"entrez votre choix: ";
                     cin>>y2;
                     if (y2==1)
                     {
                     c.jouer_match(4,0);
                     c.enregistrer_competition();
                     }
                     if (y2==2)
                     {
                     c.jouer_match(4,1);
                     c.enregistrer_competition();
                     }
                     if (y2==3)
                     {
                     c.jouer_match(4,2);
                     c.enregistrer_competition();
                     }
                     if (y2==4)
                     {
                     c.jouer_match(4,3);
                     c.enregistrer_competition();
                     }
                     if (y2==5)
                     {
                     c.jouer_match(4,4);
                     c.enregistrer_competition();
                     }
                     if (y2==6)
                     {
                     c.jouer_match(4,5);
                     c.enregistrer_competition();
                     }
                    }while (y2!=0);
               }
               if (y1==6)
               {
                    do
                     {cout<<endl;
                     c.afficher_match_poule(5);
                     cout<<"0) retour"<<endl;
                     cout<<"entrez votre choix: ";
                     cin>>y2;
                     if (y2==1)
                      {
                        c.jouer_match(5,0);
                        c.enregistrer_competition();
                      }
                     if (y2==2)
                      {
                        c.jouer_match(5,1);
                        c.enregistrer_competition();
                      }
                     if (y2==3)
                      {
                        c.jouer_match(5,2);
                        c.enregistrer_competition();
                      }
                     if (y2==4)
                      {
                        c.jouer_match(5,3);
                        c.enregistrer_competition();
                      }
                     if (y2==5)
                      {
                        c.jouer_match(5,4);
                        c.enregistrer_competition();
                      }
                     if (y2==6)
                      {
                        c.jouer_match(5,5);
                        c.enregistrer_competition();
                      }
                   }while (y2!=0);
               }
               if (y1==7)
               {
                    do
                     { cout<<endl;
                       c.afficher_match_poule(6);
                      cout<<"0) retour"<<endl;
                      cout<<"entrez votre choix: ";
                      cin>>y2;
                      if (y2==1)
                       {
                        c.jouer_match(6,0);
                        c.enregistrer_competition();
                       }
                      if (y2==2)
                       {
                        c.jouer_match(6,1);
                        c.enregistrer_competition();
                       }
                      if (y2==3)
                       {
                        c.jouer_match(6,2);
                        c.enregistrer_competition();
                       }
                      if (y2==4)
                       {
                        c.jouer_match(6,3);
                        c.enregistrer_competition();
                       }
                      if (y2==5)
                       {
                        c.jouer_match(6,4);
                        c.enregistrer_competition();
                       }
                      if (y2==6)
                       {
                        c.jouer_match(6,5);
                        c.enregistrer_competition();
                       }
                     }while (y2!=0);
               }
               if (y1==8)
               {
                    do
                      {cout<<endl;
                      c.afficher_match_poule(7);
                      cout<<"0) retour"<<endl;
                      cout<<"entrez votre choix: ";
                      cin>>y2;
                      if (y2==1)
                        {
                        c.jouer_match(7,0);
                        c.enregistrer_competition();
                        }
                      if (y2==2)
                        {
                         c.jouer_match(7,1);
                         c.enregistrer_competition();
                        }
                      if (y2==3)
                        {
                         c.jouer_match(7,2);
                         c.enregistrer_competition();
                        }
                      if (y2==4)
                        {
                         c.jouer_match(7,3);
                         c.enregistrer_competition();
                        }
                      if (y2==5)
                        {
                         c.jouer_match(7,4);
                         c.enregistrer_competition();
                        }
                      if (y2==6)
                        {
                         c.jouer_match(7,5);
                         c.enregistrer_competition();
                        }
                     }while (y2!=0);
               }
              }while(y1!=0);

             }
             if(y==2)
             {
                 do
                 {cout<<endl;
                  cout<<"1) huitieme de finale "<<endl;
                  cout<<"2) quart de finale "<<endl;
                  cout<<"3) demi-finale "<<endl;
                  cout<<"4) finale "<<endl;
                  cout<<"5) quitter "<<endl;
                  cout<<"0) retour "<<endl;
                  cout<<"entrez votre choix: ";
                  cin>>y1;
                  if(y1==5)
                  {
                      c.enregistrer_competition();
                      return 0;
                  }
                  if(y1==1)
                  {
                     if(c.get_nb_Match_poule()==48)
                       {do
                         {cout<<endl;
                          c.huitiemefinales();
                          cout<<"9) quitter "<<endl;
                          cout<<"0) retour "<<endl;
                          cout<<"entrez votre choix: ";
                          cin>>y2;
                          if(y2==9)
                          {
                              c.enregistrer_competition();
                              return 0;
                          }
                          if(y2==1)
                          {
                              c.jouer_match_huitieme(0);
                              c.enregistrer_competition();
                          }
                          if(y2==2)
                          {
                              c.jouer_match_huitieme(1);
                              c.enregistrer_competition();
                          }
                          if(y2==3)
                          {
                              c.jouer_match_huitieme(2);
                              c.enregistrer_competition();
                          }
                          if(y2==4)
                          {
                              c.jouer_match_huitieme(3);
                              c.enregistrer_competition();
                          }
                          if(y2==5)
                          {
                              c.jouer_match_huitieme(4);
                              c.enregistrer_competition();
                          }
                          if(y2==6)
                          {
                              c.jouer_match_huitieme(5);
                              c.enregistrer_competition();
                          }
                          if(y2==7)
                          {
                              c.jouer_match_huitieme(6);
                              c.enregistrer_competition();
                          }
                          if(y2==8)
                          {
                              c.jouer_match_huitieme(7);
                              c.enregistrer_competition();
                          }
                         }while(y2!=0);}
                     else
                        cout<<"veuillez jouer d'abord tout les matchs de la phase poule "<<endl;
                  }
                  if(y1==2)
                  {
                    if(c.get_nb_Match_huitiemef()==8)
                    {do
                        {cout<<endl;
                        c.quartfinales();
                        cout<<"5 quitter "<<endl;
                        cout<<"0 retour "<<endl;
                        cout<<"entrez votre choix: ";
                        cin>>y2;
                        if(y2==1)
                        {
                           c.jouer_match_quart(0);
                           c.enregistrer_competition();
                        }
                        if(y2==2)
                        {
                           c.jouer_match_quart(1);
                           c.enregistrer_competition();
                        }
                        if(y2==3)
                        {
                           c.jouer_match_quart(2);
                           c.enregistrer_competition();
                        }
                        if(y2==4)
                        {
                           c.jouer_match_quart(3);
                           c.enregistrer_competition();
                        }
                        if(y2==5)
                        {
                           c.enregistrer_competition();
                           return 0;
                        }

                     }while(y2!=0); }

                    else
                        cout<<" veuillez jouer d'abord tout les matchs de la huitieme de finale "<<endl;

                  }
                  if(y1==3)
                  {
                    if(c.get_nb_Match_quartf()==4)
                    {
                        do
                        {cout<<endl;
                         c.demi_finales();
                         cout<<"3 quitter "<<endl;
                         cout<<"0 retour "<<endl;
                         cout<<"entrez votre choix: ";
                         cin>>y2;
                         if(y2==3)
                         {
                             c.enregistrer_competition();
                             return 0;
                         }
                         if(y2==1)
                         {
                             c.jouer_match_demi(0);
                             c.enregistrer_competition();
                         }
                         if(y2==2)
                         {
                             c.jouer_match_demi(1);
                             c.enregistrer_competition();
                         }
                        }while(y2!=0); }

                    else
                        cout<<" veuillez jouer d'abord tout les matchs de la quart de finale "<<endl;
                  }
                  if(y1==4)
                  {
                      if(c.get_nb_Match_demif()==2)
                      {
                          do
                          {cout<<endl;
                           c.finales();
                           cout<<"2 quitter "<<endl;
                           cout<<"0 retour "<<endl;
                           cout<<"entrez votre choix: ";
                           cin>>y2;
                           if(y2==2)
                           {
                               c.enregistrer_competition();
                               return 0;
                           }
                           if(y2==1)
                           {
                               c.jouer_match_f();
                               c.enregistrer_competition();
                           }
                          }while(y2!=0);}

                      else
                        cout<<" veuillez jouer d'abord tout les matchs de la demi finale "<<endl;

                  }
                 }while(y1!=0);

             }
             if (y==3)
                {c.enregistrer_competition();
                return 0;}
         }while (y!=0);

    }
     if (x==3)
     {
         do
         {   cout<<endl;
             cout<<" 1)Delegation"<<endl;
             cout<<" 2)Match"<<endl;
             cout<<" 3)quitter"<<endl;
             cout<<" 0)Retour"<<endl;
             cout<<endl;
             cout<<"entrez votre choix: ";
             cin>>y;
             if (y==3)
                {c.enregistrer_competition();
                return 0;}
             if(y==1)
             {
                 do
                 { cout<<endl;
                   c.afficher();
                   cout<<"33)quitter"<<endl;
                   cout<<"0)retour"<<endl;
                   cout<<"entrez votre choix: ";
                   cin>>y1;
                   if(y1==33)
                   {
                       c.enregistrer_competition();
                       return 0;
                   }
                   if((y1>=1)&&(y1<=32))
                   {
                       c.afficher_info(y1-1);

                   }
                 }while(y1!=0);
             }
             if(y==2)
             {  do
                  { cout<<endl;
                    cout<<" 1)Phase de poule"<<endl;
                    cout<<" 2)Phase d'elimination"<<endl;
                    cout<<" 3)quitter"<<endl;
                    cout<<" 0)Retour"<<endl;
                    cout<<"entrez votre choix: ";
                    cin>>y1;
                    if(y1==3)
                    {
                        c.enregistrer_competition();
                       return 0;
                    }
                    if(y1==1)
                    {
                        c.afficher_resMatch_poule();
                    }
                    if(y1==2)
                    {
                        do
                        {cout<<endl;
                         cout<<"1) huitieme de finale "<<endl;
                         cout<<"2) quart de finale "<<endl;
                         cout<<"3) demi-finale "<<endl;
                         cout<<"4) finale "<<endl;
                         cout<<"5) quitter "<<endl;
                         cout<<"0) retour "<<endl;
                         cout<<"entrez votre choix: ";
                         cin>>y2;
                         if(y2==5)
                         {
                             c.enregistrer_competition();
                             return 0;
                         }
                         if(y2==1)
                         {
                             c.reshuitiemedefinale();
                         }
                         if(y2==2)
                         {
                             c.resquartdefinale();
                         }
                         if(y2==3)
                         {
                             c.resdemifinale();
                         }
                         if(y2==4)
                         {
                             c.resfinale();
                         }
                        }while(y2!=0);
                    }
                  }while(y1!=0);

             }
         }while (y!=0);
     }
     if (x==4)
     {if(c.get_nb_Match_f()==1)
         {do
           {
             cout<<endl;
             c.mjoueur();
             cout<<" 1)quitter"<<endl;
             cout<<" 0)Retour"<<endl;
             cout<<endl;
             cout<<"entrez votre choix: ";
             cin>>y;
             if (y==1)
                {c.enregistrer_competition();
                return 0;}
          }while (y!=0);}
      else
        cout<<"la competition n'est pas encore fini "<<endl;
     }
     if (x==5)
     {
         do
         {   cout<<endl;
             c.afficherresgroupe();
             cout<<" 1)quitter"<<endl;
             cout<<" 0)Retour"<<endl;
             cout<<endl;
             cout<<"entrez votre choix: ";
             cin>>y;
             if (y==1)
                {c.enregistrer_competition();
                return 0;}
         }while (y!=0);
     }
     if (x==6)
     {
         do
         {   cout<<endl;
             cout<<" 1)resultat final "<<endl;
             cout<<" 2)quitter"<<endl;
             cout<<" 0)Retour"<<endl;
             cout<<endl;
             cout<<"entrez votre choix: ";
             cin>>y;
             if (y==2)
                {c.enregistrer_competition();
                return 0;}
             if(y==1)
             {
                 if(c.get_nb_Match_f()==1)
                   {c.classement_final();}
                 else
                 {cout<<"la competition n'est pa encore termine "<<endl;}
             }
         }while (y!=0);
     }
}while (x!=0);


c.enregistrer_competition();
return 0;
}

