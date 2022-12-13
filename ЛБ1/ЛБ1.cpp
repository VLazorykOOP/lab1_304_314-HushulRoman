#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <time.h>

using namespace std;

void task1_v1()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    int* a = (int*)malloc(n * sizeof(int));
    cout << "Input element: ";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] ";
        cin >> a[i];
        
    }
    cout << endl;
    int* b = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "]";
        cin >> b[i];
    }
    cout << "Array A: ";
    for (int i = 0; i < n; i++) {
        cout << "[ " << a[i] << " ]";
    }
    cout << endl << endl;
    cout << "Array B: ";
    for (int i = 0; i < n; i++) {
        cout << "[ " << b[i] << " ]";
    }
    cout << "\n\n Final Array: ";

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] > 0) a[i] = b[i];
        cout << a[i] << " ";
    }
    cout << endl;
    free(a);
    free(b);
}


 void task1_v3()
{
    const int N = 10;
    int A[N]{ 0 };
    int B[N]{ 0 };

    srand(time(0));
    for (size_t i = 0; i < N; i++)
    {
        A[i] = rand() % 21 - 10;;
        B[i] = rand() % 21 - 10;;
    }

    cout << "Array A: ";
    for (size_t i = 0; i < N; i++)
    {
        cout << "[" << i << "]" << A[i] << " ";
    }

    cout << endl;
    cout << "Array B: ";
    for (size_t i = 0; i < N; i++)
    {
        cout << "[" << i << "]" << B[i] << " ";
    }

    cout << endl;
    cout << "Final Array: ";

    for (size_t i = 0; i < N; i++)
    {
        if (A[i] > 0) A[i] = B[i];
        cout << A[i] << " ";
    }
    cout << "\n";
}


 void task2_v1()
 {
     int i, T1, T2, min, x, n;
     cout << "Input N: "; 
     cin >> n;
     int* A = (int*)malloc(n * sizeof(int));
     for (i = 0; i < n; i++)
     {
         cout << "A[" << i << "]";
         cin >> A[i];
     }
     cout << endl;
     cout << "Input T1: ";
     cin >> T1;
     cout << "Input T2: ";
     cin >> T2;
     x = 0;
     for (i = 0; i < n; i++) {
         if (T2 == A[i]) break;
         if (T2 == A[i]) { x = i; }
     }
     if (i == 0) {
         cout << "There is no element equal to T2 "; exit(0);
     }
     min = T1;
     for (i += 1; i < n; i++)
         if (A[i] > T1 && (min == T1 || min > A[i]))
             min = A[i];
     if (min == T1) {
         cout << "No element found greater than T1 after T2"; exit(0);
     }
     cout << "Min: " << min;
     free(A);
             
 }
 

int main(int argc, char** argv)
{
    srand(time(0));
    //task1_v1();
    //task1_v3();
    //task2_v1();
}