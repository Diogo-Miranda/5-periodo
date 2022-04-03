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

void swap(int a[], int i, int j) {
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if(i != min) {
            swap(a, i, min);
        }
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

    selectionSort(a, n);

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
