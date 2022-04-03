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

int* permutationSort(int a[], int l, int n) {
    if(l == n) {
        return a;
    } else {
        for (int i = l; i <= n; i++) {
            // fixing initial 
            swap(a, l, i);

            // call next
            a = permutationSort(a, l+1, n);

            // stop recursion if found sort set
            if (isSorted(a, n+1)) {
                return a;
            }
            
            // backtrack
            swap(a, l, i);
        }
    }

   return a;
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

    a = permutationSort(a, 0, n-1);

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
