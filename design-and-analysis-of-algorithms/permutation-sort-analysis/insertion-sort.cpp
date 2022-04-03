#include <iostream>

using namespace std;

int TAM_INSTANCE = 15;

void printArr(int a[], int n) {
    cout << "Arr = { ";

    for (int i = 0; i < n; i++) {
        cout << a[i];
        cout << " ";
    }

    cout << "}";
    cout << "\n";
}

int* generateInstance() {
    int *arr = (int*)malloc(sizeof(int)*TAM_INSTANCE);
    
    for (int i = 0; i < TAM_INSTANCE; i++) {
        arr[i] = rand()%TAM_INSTANCE;
    }

    return arr;
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

void insertionSort(int a[], int n) {
    for(int j = 2; j < n; j++) {
        int k = a[j];
        int i = j - 1;
        while(a[i] > k && i > 0) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = k;
    }
}

int main() {
    time_t start, end;

    int* a = generateInstance();
    int n = TAM_INSTANCE;

    cout << "Initial: \n";
    printArr(a, n);
    cout << "\n";

    time(&start);
    ios_base::sync_with_stdio(false);

    insertionSort(a, n);

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
