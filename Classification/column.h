#pragma once

// Défini un array d'entier
class IntegerCol
{
  public:

    /*constructeur
     * affecte la valeurs rows à notre champ rows
     * et crée data
     */
    IntegerCol( const unsigned int rows ) :
      rows(rows)

    {
      // allocation de la colonne de données
      data = new unsigned int[rows];

      /* rempli les sizeof(*data)*rows
       * blocs mémoire de taille nécessaire
       * pour stocker un unisgned int en commençant
       * à l'emplacement mémoire de data (pointeur sur
       * la première valeur du tableau)
       * par la valeur 0 interprétée comme un unsigned char
       */
      memset( data, 0, sizeof(*data)*rows );
    }

    // Destructeur
    ~IntegerCol( void )
    {
      delete [] data;
    }

    // redimensionne la colonne
    void resize( const unsigned int rows2 )
    {
      // ne fait rien si c'est la même taille
      if ( rows2 != rows )
      {
        unsigned int *data2 = new unsigned int[rows2];
        unsigned int copy_size = (rows < rows2) ? rows : rows2;

        /* copie les données sur les sizeof(*data)*copy_size
         * octets suivant l'emplacement mémoire data
         * dans l'emplacement mémoire new_data
         */
        memcpy( data2, data, sizeof(*data)*copy_size );

        // et on remplit le reste si la nouvelle colonne est plus longue
        if ( rows2 > rows )
        {
          memset( &data2[rows], 0, sizeof(*data2)*(rows2 - rows) );
        }

        delete [] data;
        data = data2;
        rows = rows2;
      }
    }

    // détermine si value est dans la colonne
    bool contains( const unsigned int value ) const
    {
      for ( unsigned int row = 0; row < rows; ++row )
      {
        if ( data[row] == value )
        {
          return true;
        }
      }
      return false;
    }

    // retourne rows
    unsigned int get_row( void ) const
    {
      return rows;
    }

    //pour manipuler les colonnes naturellement
    const unsigned int & operator[]( const unsigned int row ) const
    {
      return data[row];
    }
    unsigned int & operator[]( const unsigned int row )
    {
      return data[row];
    }

  private:
    unsigned int rows;
    unsigned int *data;
};
