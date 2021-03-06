#ifndef MATCH_H
#define MATCH_H
#include "Delegation.h"
using namespace std;
class Match
{   friend class Groupe;
    friend class Competition;
    friend class Delegation;
    private:
        Delegation equipe1,equipe2;
        int information[6]; /*case1 pour les buts de l'equipe1 case 2 nbr carton jaune de l'equipe1 case 3 nbr carton rouge de l'equipe1
                            case4 pour les buts de l'equipe2 case 5 nbr carton jaune de l'equipe2 case 6 nbr carton rouge de l'equipe2*/
    public:
        Match();
        Match(Delegation,Delegation);
        void jouer();
        void jouer_phase2();
        void afficher_information();
        Delegation resultat();
        void enregistrer_match();
        void download_match();
        void enregistrer_match_de_groupe();
        void download_match_de_groupe();
        Delegation perdant();


};

#endif // MATCH_H
