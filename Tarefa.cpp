#include <iostream>
#include <cmath>

int determinant(int a[], int n, int e){

// Caso base da recursão: Matriz de tamanho 1 (sua determinante é o próprio valor)
    if (n == 1){
        return a[0];
    }

// Passos da recursão

    int sum = 0;
    int flag = 0;
    int new_n = n-1;
    int ma[(new_n)*(new_n)];

    // Reduz a matriz para uma matriz[n-1][n-1]
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n; j++){
            if (j != e){
                if (flag ==1){
                    ma[(i-1)*new_n+(j-1)] = a[i*n+j];

                }
                else{
                    ma[(i-1)*new_n+j] = a[i*n+j];
                } 
            }
            else{
                flag=1;
            } 
        }
        flag=0;
    }

    
    // Calcula novamente a determinante para a matriz reduzida
    for(int r =0; r < new_n; r++ ){
        sum += a[0+e] * std::pow((-1), (1 + (e+1))) * determinant(ma, new_n, r);
    }

    
    return sum;
}

int main(int argc, char **argv) {

    int n = 5;
    int sum = 0;

    int matrix[n*n] = {3,  1, -2,  1, 1,
                       5,  2,  2,  3, 2,
                       7,  4, -5,  0, 3,
                       1, -1, 11,  2, 4,
                       1,  2,  3,  4, 5};

    // Determinante por Laplace
    for (int e = 0; e<n; e++){
        sum+=determinant(matrix, n, e);
    }

    std::cout << sum << std::endl;
    
    return 0;
}