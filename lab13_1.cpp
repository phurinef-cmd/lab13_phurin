#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0.0;
    int i = 0;
    double sum_std = 0.0;
    double sum_geo = 1.0;
    double sum_Har = 0.0;
    long double max = A[0],min = A[0];
    while(i < N){
        sum += A[i];
        i++;
    }
    for(int j = 0;j<N ;j++){
        sum_std += pow(A[j] - sum/N,2);
        sum_geo *= A[j];
        sum_Har += 1/A[j];
        if(A[j] > max) max=A[j];
        if(A[j] < min) min=A[j]; 
    }
    
    
    B[0] = sum/N;
    B[1] = sqrt(sum_std/N);
    B[2] = pow(sum_geo,1.0/N);
    B[3] = N/sum_Har;
    B[4] = max;
    B[5] = min;
}
