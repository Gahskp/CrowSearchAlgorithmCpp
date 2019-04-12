#ifndef FITNESS_HPP

#define FITNESS_HPP


double* fitness(double **xn, int n, int pd){
    double* fitness = new double[n];

    for (int i = 0; i < n; i++) {
        fitness[i] = 0.0;
        for (int j = 0; j < pd; j++) {
            fitness[i] = fitness[i] + (xn[i][j]*xn[i][j]);
        }
    }

    return fitness;
}

#endif
