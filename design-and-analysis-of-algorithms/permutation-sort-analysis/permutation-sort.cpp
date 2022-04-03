#include <iostream>

using namespace std;

void printArr(int a[], int n) {
    cout << "Arr = { ";

    for (int i = 0; i < n; i++) {
        cout << a[i];
        cout << " ";
    }

    cout << "}";
    cout << "\n";
}

bool isSorted(int a[], int n) {
    bool resp = true;

    while ( --n >= 1 ) {
        if (a[n] < a[n-1]) {
            resp = false;
        }   
    }

    return resp;
}

void swap(int a[], int i, int j) {
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        swap(a, i, rand()%n);
    }

    printArr(a, n);
}

void permutationSort(int a[], int n) {
    while(!isSorted(a, n)) {
        sort(a, n);
    }
}

int main() {
    time_t start, end;

    int a[] = {1, 20, 1, 34, 2, 10, 25, 552, 44, 6465, 100, 1};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "Initial: \n";
    printArr(a, n);
    cout << "\n";

    time(&start);
    ios_base::sync_with_stdio(false);

    permutationSort(a, n);

    time(&end);

    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken;
    cout << " sec " << endl;

    cout << "\n";
    cout << "Resp: \n";
    printArr(a, n);

    return 0;
}
