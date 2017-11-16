#pragma once

#include "column.h"



// défini matrice réelle
class RealMatrix
{
  public:

    // constructeur
    RealMatrix( const unsigned int rows, const unsigned int columns ) :
      rows(rows), columns(columns)
    {
      // allocation de la matrice des données
      data = new double[rows*columns];
      memset( data, 0, sizeof(*data)*rows*columns );
    }

    // destructeur
    ~RealMatrix( void )
    {
      delete [] data;
    }

    // retourne rows
    unsigned int get_row( void ) const
    {
      return rows;
    }

    // retourne colonne
    unsigned int column_count( void ) const
    {
      return columns;
    }

    /* pour rendre utilisation plus naturelle
     * retourne un pointeur au début de la ligne row
     */
    const double * const operator[]( const unsigned int row ) const
    {
      return &data[row*columns];
    }
    double * const operator[]( const unsigned int row )
    {
      return &data[row*columns];
    }

  private:
    unsigned int rows;
    unsigned int columns;
    double * data;
};

