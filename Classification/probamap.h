#pragma once

/* Représente un tableau - map - associatif, où chaque élément est une paire (clé,valeur)
 * auquel on ajoute l'entropie du jeu de données
 */

// la clé est le string, la valeur double associée est la valeur

class ProbaMap : public std::map<std::string, double>
{
  public:

     // Renvoie l'entropie des données en base 10


    /* Fonction inline
     * cad le compilateur va remplacer dès la compilation tout appel
     * de fonction par la définition complète pour gagner du temps
     * d'exécution
     * il peut choisir de ne pas le faire si le temps d'exécution de
     * la fonction est trop long, bref : his call, the fastest the better
     */

    /* retourne une variable const
     * pour pouvoir la changer en valeur mais pas en mémoire
     */

    inline double entropy( void ) const
    {
      double entropy = 0.0;
      for (ProbaMap::const_iterator iter = this->begin();
        iter != this->end(); ++iter )
      {
        if ( iter->second > 0.0 )
        {
          entropy -= iter->second * log10(iter->second) / log10(2.0);
        }
      }
      return entropy;
    }
};
