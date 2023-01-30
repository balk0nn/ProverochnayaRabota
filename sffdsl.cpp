#include <iostream>
#include <math.h>
using namespace std;
#include <experimental/random>

void fullfillment(int **array, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++) {
            array[i][j] = experimental::randint(1,100);
        }
    }
}

void output(int **array, int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int sumOfElementsOnTheMainDiagonal(int **array, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += array[i][i];
    }
    return sum;
}

int main() {

    //Задача 3

    //ВВод размерности матрицы
    cout << "Input the number of rows and columns" << endl;
    int n;
    cin >> n;

    int **array = new int*[n];
    fullfillment(array, n, n);
    output(array, n);

    cout << sumOfElementsOnTheMainDiagonal(array, n) << endl;

    for(int j = 0; j < n; ++j){
        delete []array[j];
    }
    delete []array;

    //Задача 4
    int size;
    cout << "Input the size of array" << endl;
    cin >> size;

    int *massiv = new int[size];

    for(int i = 0; i < size; i++){
        cin >> massiv[i];
    }

    cout << "ENter k" << endl;
    int k;
    cin >> k;

    double minAvg;

    for (int i = 0; i < size - k; i++){
        int sum = 0;
        double minAvgTemp;
        for (int j = i; j < i + k; j++){
            sum += massiv[j];
        }
        minAvgTemp = sum / k;
        if(minAvgTemp < minAvg){
            minAvg = minAvgTemp;
        }
    }

    cout << minAvg << endl;
    return 0;
}
