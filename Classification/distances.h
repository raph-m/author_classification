#ifndef DISTANCES_H
#define DISTANCES_H

//--------------
#include <vector>
#include <cmath>

using namespace std;
//  ----------------------------------
//  Abstract Class contains all types
//  of distances may be used in
//  ANN Algorithms
// -----------------------------------

 class Distances
{
public:
        Distances();
        // I have overloaded () operator to look like a function that calcules
        // the distance between two given vectors
        virtual double operator()(const vector<int>& X1, const vector<int>& X2) const = 0;
        virtual ~Distances(){}

};


#endif // DISTANCES_H
