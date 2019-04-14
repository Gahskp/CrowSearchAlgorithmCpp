#ifndef HELPER_HPP

#define HELPER_HPP

#include <cmath>
using namespace std;

int* randArray(int tam){

    int* rd = new int[tam];
    //srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        rd[i] = ceil(tam*((double) rand() / (RAND_MAX)))-1;
    }

    return rd;
}

bool betweenLowerUpper(double** xnew, int l, int u, int i, int pd){

    for (int j = 0; j < pd; j++) {
        if (!(xnew[i][j] >= l && xnew[i][j] <= u)) return false;
    }
    return true;
}

double smallestElement(double* array, int n){

    double temp = array[0];

    for (int i = 0; i < n; i++) {
        if (temp > array[i]){
            temp = array[i];
        }
    }
    return temp;
}

double** receive2DArray(double** var, int n, int pd){

    double** x = new double*[n];

    for (int i = 0; i < n; i++) {
        x[i] = new double[pd];
        for (int j = 0; j < pd; j++) {
            x[i][j] = var[i][j];
        }
    }

    return x;
}

double* receiveArray(double* var, int n){

    double* x = new double[n];

    for (int i = 0; i < n; i++) {
            x[i] = var[i];
    }

    return x;
}

void print2DArray(double** array, int linha, int coluna){

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cout << i << " - " << array[i][j] << " - " << j << endl;
        }
    }
    cout << endl;
}

void printArray(double* array, int tam){

  for (int i = 0; i < tam; i++) {
    cout << array[i] << endl;
  }
}

#endif
