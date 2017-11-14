#ifndef DISTANCES_H
#define DISTANCES_H

//--------------
#include <vector>

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

// ----------------------------------
// Eucliden Distance
// ----------------------------------

class Euclidean : public Distances {

public:
        Euclidean(int p_);
        virtual double operator()(const vector<long>& X1, const vector<long>& X2) const;
        virtual ~Euclidean();

private:
        int p;
};

// ----------------------------------
// Cosine Similarity (this is not a
// distance but represents a usefual
// tool to calculate similarity bet-
// ween two vectors
// ----------------------------------

class Cosine :public Distance {

public:
        Cosine();
        virtual double operator()(const vector<long>& X1, const vector<long>& X2) const;
        virtual ~Cosine();

private:
};

#endif // DISTANCES_H
