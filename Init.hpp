#ifndef INIT_HPP

#define INIT_HPP
#include<iostream>
using namespace std;

double** init(int n, int pd, int l, int u){
    double** x = new double*[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        x[i] = new double[pd];
        for (int j = 0; j < pd; j++) {
            x[i][j] = (l-(l-u)*((double)rand()/RAND_MAX));
        }
    }

    return x;
}

#endif
