#include <iostream>
#include "Fitness.hpp"
#include "Init.hpp"
#include "Helper.hpp"
using namespace std;

/* Variables initialization */

int pd=10; // Problem dimension (number of decision variables)
int n=20; // Flock (population) size
double ap=0.1; // Awareness probability
int fl=2; // Flight length (fl)
int l=-100;
int u=100;

int main(){
    double **x = init(n, pd, l, u);

    double **xn = receive2DArray(x, n, pd);
    double *ft = fitness(xn, n, pd);

    double **mem = receive2DArray(x, n, pd); // Memory initialization
    double *fit_mem = receiveArray(ft, n); // Fitness of memory positions


    int tmax = 1; // Max numuber of iterations (itermax)
    double* ffit = new double[tmax]; // Best fit of each iteration

    /* Iteration begin */

    for (int t = 0; t < tmax; t++) {

        int *num = randArray(n); // Generation of random candidate crows for following (chasing)

        srand(time(NULL));
        double** xnew = new double*[n];
        for (int i = 0; i < n; i++) {

            xnew[i] = new double[pd];
            if (((double)rand()/RAND_MAX) > ap) {
                for (int j = 0; j < pd; j++) {
                    xnew[i][j] = x[i][j]+fl*((double)rand()/RAND_MAX)*(mem[num[i]][j]-x[i][j]); // Generation of a new position for crow i (state 1)
                }
            } else{

                for (int j = 0; j < pd; j++) {
                    xnew[i][j] = l-(l-u)*((double)rand()/RAND_MAX); // Generation of a new position for crow i (state 2)
                }
            }
        }

        xn = receive2DArray(xnew, n, pd);
        ft = fitness(xn, n, pd); // Function for fitness evaluation of new solutions



        /* Update position and memory */
        for (int i = 0; i < n; i++) {
            if (betweenLowerUpper(xnew, l, u, i, pd)) {
                for (int j = 0; j < pd; j++) {
                    x[i][j] = xnew[i][j]; // Update position
                }
                if (ft[i] < fit_mem[i]) {
                    for (int j = 0; j < pd; j++) {
                        mem[i][j] = xnew[i][j]; // Update memory
                    }
                    fit_mem[i] = ft[i];
                }
            }
        }

        ffit[t] = smallestElement(fit_mem, n); // Best found value until iteration t
    }

    // Show solution of the problem


    return 0;
}
