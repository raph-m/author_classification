// -----------------------------
#pragma once
#include "Distances.h"
#include <algorithm>  // to use transform funtion
#include <numeric>    // to use  accumulate function
#include<math.h>      // to use pow function
// ------------------------------
// Euclidean constructor
// ------------------------------
Euclidean::Euclidean(int p_) :p(p_)
{
}
// ------------------------------
// This operator returns the euclidean distance between
// X1 and X2
// ------------------------------
double Euclidean::operator()(const vector<long>& X1, const vector<long>& X2)const
{
        vector<double>	result;
        transform(X1.begin(), X1.end(), X2.begin(), back_inserter(result),
                  [&](long x, long y) {return pow(abs(x-y),p); });

        result.shrink_to_fit(); //Requests the removal of unused capacity

        return  pow(accumulate(result.begin(), result.end(), 0.0),1.0/p);
}
// ------------------------------
// This operator returns the Cosine Similarity between
// X1 and X2
// ------------------------------
double Cosine::operator()(const vector<long>& X1, const vector<long>& X2) const
{
        //vector<double>::const_iterator X1_Iter = X1.begin();
        //vector<double>::const_iterator X2_Iter = X2.begin();


        auto X1_Iter = X1.begin();
        auto X2_Iter = X2.begin();

        double current_product = 0.0;
        double d_X1 = 0.0;
        double d_X2 = 0.0;
        for (; X1_Iter != X1.end(); X1_Iter++,X2_Iter++)
        {
                current_product += *X1_Iter * *X2_Iter;
                d_X1 += *X1_Iter * *X1_Iter;
                d_X2 += *X2_Iter * *X2_Iter;
        }
        return current_product / (sqrt(d_X1) * sqrt(d_X2));
}

