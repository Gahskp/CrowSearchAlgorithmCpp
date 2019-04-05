#include <iostream>
#include "Fitness.hpp"
#include "Init.hpp"
#include "Helper.hpp"
using namespace std;

/* Inicialização de variáveis */

int pd=10; // Problem dimension (number of decision variables)
int n=20; // Flock (population) size
double ap=0.1; // Awareness probability
int fl=2; // Flight length (fl)
int l=-100;
int u=100;

int main(){
    double **x = init(n, pd, l, u);

    double **xn = x;
    double *ft = fitness(xn, n, pd);

    double **mem = x; // inicialização da memória
    double *fit_mem = ft; // memório fitness

    int tmax = 5000; // Número máximo de iteraçõeos

    /* Início das iterações */

    for (int t = 0; t < tmax; t++) {

        int *num = randArray(n); //número randomico

        srand(time(NULL));
        double** xnew = new double*[n];
        for (int i = 0; i < n; i++) {

            xnew[i] = new double[pd];
            if (((double)rand()/RAND_MAX) > ap) {

                for (int j = 0; j < pd; j++) {
                    xnew[i][j] = x[i][j]+fl*((double)rand()/RAND_MAX)*(mem[num[i]][j]-x[i][j]);
                }
            } else{

                for (int j = 0; j < pd; j++) {
                    xnew[i][j] = l-(l-u)*((double)rand()/RAND_MAX);
                }
            }
        }

        xn = xnew;
        ft = fitness(xn, n, pd);

        for (int i = 0; i < n; i++) {
            if (beetwenLowerUpper(xnew, l, u, i, pd)) {
                /* code */
            }
        }
    }




    return 0;
}
