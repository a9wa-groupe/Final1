#include <iostream>
#include "Competition.h"
#include "Match.h"
#include <string.h>
#include <cstring>
#include <fstream>
#include "Delegation.h"
#include <string>
using namespace std;

void Competition::afficher_resMatch_poule()
{ for(int i=0;i<8;i++)
        {
             cout<<"********************"<<i+1<<" groupe *****************************"<<endl;
              phasedegroupe[i].afficher_resMatch();

        }
}
void Competition::afficher_info(int i)
{
    participant[i].afficher_info();
}
void Competition::afficher_match_poule(int i)
{
    phasedegroupe[i].afficher_matchs();
}
void Competition::jouer_match(int i,int k)
{
  phasedegroupe[i].matchs[k].jouer();
  phasedegroupe[i].matchs[k].enregistrer_match();
  nb_de_match_de_groupe_jouer+=1;

  phasedegroupe[i].classer();
}
void Competition::ajouter_joueur(int i)
{
    participant[i].ajouter_joueur();
    participant[i].enregistrer_delegation();

}
void Competition::modifier_joueur(int i)
{
     participant[i].modifier_joueur();
     participant[i].enregistrer_delegation();
}
void Competition::ajouter_staff(int i)
{
    participant[i].ajouter_staff();
    participant[i].enregistrer_delegation();
}
void Competition::modifier_staff(int i)
{
     participant[i].modifier_staff();
     participant[i].enregistrer_delegation();
}
void Competition::mjoueur()
{ Joueur j,m;
  for (int i=0;i<32;i++)
    {
       j=participant[i].meilleur_joueur();
       cout<<"meilleur joueur de l'equipe "<<participant[i].nom<<" :"<<endl;
       j.afficher_info();

    }
   m=participant[0].meilleur_joueur();
   for (int i=0;i<32;i++)
   {
       if(participant[i].meilleur_joueur().note_total()>participant[i-1].meilleur_joueur().note_total())
            m=participant[i].meilleur_joueur();
   }

}

Competition::Competition()
{

}
Competition::Competition(int i) : nb_de_match_de_groupe_jouer(0),nb_de_match_de_huitieme_final_jouer(0),nb_de_match_de_quart_final_jouer(0),nb_de_match_de_demi_final_jouer(0),nb_de_match_de_final_jouer(0)

{

    cout<<"donner 32 delegation"<<endl;
    int t[4];
    t[0]=t[1]=t[2]=t[3]=0;

    for( int i=0 ;i<32;i++)
    {
        Delegation d(t,4);
        participant[i]=d;

    }
    int j=0;
    for (int i=0;i<32;i+=4)
    {
        participant[i].setgrp(j+1);
        participant[i+1].setgrp(j+1);
        participant[i+2].setgrp(j+1);
        participant[i+3].setgrp(j+1);
        Groupe g(participant[i],participant[i+1],participant[i+2],participant[i+3],j+1);

        phasedegroupe[j]=g;
        j++;
    }



}
void Competition::download_competition()
{
     Delegation t1[4],t2[4],t3[4],t4[4],t5[4],t6[4],t7[4],t8[4];
    char nomfich[50];
    string s="competition",nom;
	strcpy(nomfich,s.c_str());
	ifstream entree ( nomfich , ios::in);


	for ( int i=0;i<32;i++)
    {
        entree >> nom ;
		Delegation d;
		d.download_delegation(nom);
		participant[i]=d;

    }

    int k=1;
    Delegation t[4];
    do
    {
        int j=0;
        for ( int i=0;i<32 ;i++)
        {

            if (participant[i].get_groupe()==k)
            {
                t[j]=participant[i];
                cout<<t[j].getnom()<<endl;
                j++;
            }

        }
        Groupe g;
        g.download_groupe(t[0],t[1],t[2],t[3]);
        phasedegroupe[k-1]=g;
        phasedegroupe[k-1].afficherleclassment();
        k++;
        cout<<k<<endl;
    }while(k<9);


 }

void Competition::download_competition_par_defaut()
{
    char nomfich[50];
    string s="competition par defaut",nom;
	strcpy(nomfich,s.c_str());
	ifstream entree ( nomfich , ios::in);


	for ( int i=0;i<32;i++)
    {
        entree >> nom ;
		Delegation d;
		d.download_delegation_par_defaut(nom);
		participant[i]=d;
    }
    int k=1;
    Delegation t[4];
    do
    {
        for ( int i=0;i<32 ;i++)
        {
            int j=0;
            if (participant[i].get_groupe()==k)
            {
                t[j]=participant[i];
                j+=1;
            }
        Groupe g;
        g.download_groupe(participant[0],participant[1],participant[2],participant[3]);
        phasedegroupe[k]=g;
        k++;
        }
    }while(k<9);
    entree >> nb_de_match_de_groupe_jouer;

	entree >> nb_de_match_de_huitieme_final_jouer;

	entree >> nb_de_match_de_quart_final_jouer;

	entree >> nb_de_match_de_demi_final_jouer;

	entree >> nb_de_match_de_final_jouer;
 }

void Competition::enregistrer_competition()
{
    char nomfich[20];
    string s;
    s= "Competition";
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<32 ;i++)
    {

		sortie << participant[i].getnom() << endl;
        participant[i].enregistrer_delegation();
    }
    for ( int i=0;i<8;i++)
    {
        phasedegroupe[i].enregistrer_groupe();
    }
    sortie << nb_de_match_de_groupe_jouer<<endl;
	sortie << nb_de_match_de_huitieme_final_jouer<<endl;
	sortie << nb_de_match_de_quart_final_jouer<<endl;
	sortie << nb_de_match_de_demi_final_jouer<<endl;
	sortie << nb_de_match_de_final_jouer<<endl;
    sortie.close();
}



void Competition::huitiemefinales()
{   for (int i ; i<8;i++)
        {phasedegroupe[i].Groupe::classer() ; }

    huitiemedefinale[0]=Match(phasedegroupe[0].classement[0],phasedegroupe[1].classement[1]);
    huitiemedefinale[1]=Match(phasedegroupe[0].classement[1],phasedegroupe[1].classement[0]);
    huitiemedefinale[2]=Match(phasedegroupe[2].classement[0],phasedegroupe[3].classement[1]);
    huitiemedefinale[3]=Match(phasedegroupe[2].classement[1],phasedegroupe[3].classement[0]);
    huitiemedefinale[4]=Match(phasedegroupe[4].classement[0],phasedegroupe[5].classement[1]);
    huitiemedefinale[5]=Match(phasedegroupe[4].classement[1],phasedegroupe[5].classement[0]);
    huitiemedefinale[6]=Match(phasedegroupe[6].classement[0],phasedegroupe[7].classement[1]);
    huitiemedefinale[7]=Match(phasedegroupe[6].classement[1],phasedegroupe[7].classement[0]);
    for (int i ; i<8;i++)
    {
       cout<<i+1<<" "<<huitiemedefinale[i].equipe1.nom<<" - "<<huitiemedefinale[i].equipe2.nom<<endl;
    }
}
void Competition::jouer_match_huitieme(int i)
{
    huitiemedefinale[i].jouer();
    nb_de_match_de_huitieme_final_jouer+=1;
}
void Competition::quartfinales()
{
    quartdefinale[0]=Match(huitiemedefinale[0].Match::resultat(), huitiemedefinale[1].Match::resultat());
    quartdefinale[1]=Match(huitiemedefinale[2].Match::resultat(), huitiemedefinale[3].Match::resultat());
    quartdefinale[2]=Match(huitiemedefinale[4].Match::resultat(), huitiemedefinale[5].Match::resultat());
    quartdefinale[3]=Match(huitiemedefinale[6].Match::resultat(), huitiemedefinale[7].Match::resultat());
    for (int i ; i<4;i++)
    {
       cout<<i+1<<" "<<quartdefinale[i].equipe1.nom<<" - "<<quartdefinale[i].equipe2.nom<<endl;
    }
}
void Competition::jouer_match_quart(int i)
{
    quartdefinale[i].jouer();
    nb_de_match_de_quart_final_jouer+=1;
}
void Competition::demi_finales()
{  demifinale[0]=Match(quartdefinale[1].Match::resultat(),quartdefinale[0].Match::resultat());
   demifinale[1]=Match(quartdefinale[2].Match::resultat(),quartdefinale[3].Match::resultat());
   for (int i ; i<2;i++)
    {
       cout<<i+1<<" "<<demifinale[i].equipe1.nom<<" - "<<demifinale[i].equipe2.nom<<endl;
    }
}
void Competition::jouer_match_demi(int i)
{
    demifinale[i].jouer();
    demifinale[i].enregistrer_match();
    nb_de_match_de_demi_final_jouer+=1;
}

void Competition::finales ()
{
    finale=Match(demifinale[0].Match::resultat(),demifinale[1].Match::resultat()) ;
    cout<<1<<" "<<finale.equipe1.nom<<" - "<<finale.equipe2.nom<<endl;

}
void Competition::jouer_match_f()
{
    finale.jouer();
    finale.enregistrer_match();
}
void Competition::afficherresgroupe()
{
    for (int i ;i<8;i++)
        {cout<<" gourpe n:"<<i+1<<endl;
         for (int j=0;j<4;j++)
               cout<<j+1<<" equipe : " <<phasedegroupe[i].classement[j].nom<<" point= "<<phasedegroupe[i].classement[j].points<<endl;
        }
}
void Competition::reshuitiemedefinale()
 { for (int i ; i<8 ; i++)
     { cout<<"resultat de huitieme de finale n:"<<i<<endl ;
       huitiemedefinale[i].Match::afficher_information();
       cout<<"-----------------------------------------"<<endl;
     }

 }
void Competition::resquartdefinale()
{ for (int i ; i<4 ; i++)
     { cout<<"resultat de quart de finale n:"<<i<<endl ;
       quartdefinale[i].Match::afficher_information();
       cout<<"-----------------------------------------"<<endl;
     }

 }
void Competition::resdemifinale()
{ for (int i ; i<2 ; i++)
     { cout<<"resultat de demi  finale n:"<<i<<endl ;
       demifinale[i].Match::afficher_information();
       cout<<"-----------------------------------------"<<endl;
     }

 }
void Competition::resfinale()
{

    finale.Match::afficher_information();

}
void Competition::afficher()
{ for(int i=0;i<32;i++)
    cout<<i+1<<") "<<participant[i].nom<<endl;
}
void Competition::classement_final()
{
    Delegation eq1;
    Delegation eq2;
    Delegation eq3;
    Delegation eq4;
    eq1=finale.resultat();
    eq2=finale.perdant();
    cout<<"veuillez jouer un match pour la 3eme place "<<endl;
    eq3=demifinale[0].perdant();
    eq4=demifinale[1].perdant();
    Match m(eq3,eq4);
    m.jouer_phase2();
    eq3=m.resultat();
    eq4=m.perdant();
    cout<<"       LA COUPE DU MONDE EST REMPORTE PAR ===========> "<<eq1.nom<<endl;
    cout<<"       2eme place                         ===========> "<<eq2.nom<<endl;
    cout<<"       3eme place                         ===========> "<<eq3.nom<<endl;
    cout<<"       4eme place                         ===========> "<<eq4.nom<<endl;
}
