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

void quicksort(int a[], int esq, int dir) {
    int i = esq, j = dir;
    int pivo = a[(dir+esq)/2];
    while (i <= j) {
        while (a[i] < pivo) i++;
        while (a[j] > pivo) j--;
        if (i <= j) {
            swap(a, i, j);
            i++;
            j--;
        }
    }

    if (esq < j) quicksort(a, esq, j);
    if (i < dir) quicksort(a, i, dir);
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

    quicksort(a, 0, n-1);

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
