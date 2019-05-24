#include <mpi.h>
#include <string.h>
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

    MPI_Init(&argc, &argv);
    int world_rank; MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size; MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int r = world_rank;
    int w = world_size;

    int n = 5;
    int sum = 0;
    int sum_tmp = 0;

    int matrix[n*n] = {3,  1, -2,  1, 1,
                       5,  2,  2,  3, 2,
                       7,  4, -5,  0, 3,
                       1, -1, 11,  2, 4,
                       1,  2,  3,  4, 5};

    if (world_rank==0){

        MPI_Bcast(matrix, n*n, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

        MPI_Reduce(&sum_tmp, &sum, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        std::cout << sum << std::endl;
    }
    else{  //processos = 3

        MPI_Bcast(matrix, n*n, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

        //divide em apenas dois processos
        for (int e = (r-1)*((n/w)+1); e < ((r+1)*((n/w)+1)>n?n:(r)*((n/w)+1)); e++){
            // Determinante por Laplace
            std::cout << "RANK " << r << " FAZENDO " << e << std::endl;
            sum_tmp+=determinant(matrix, n, e);
        }
        
        MPI_Reduce(&sum_tmp, &sum, 1,  MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    }
    MPI_Finalize();
    
    return 0;
}