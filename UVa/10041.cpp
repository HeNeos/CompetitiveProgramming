#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int n;
int dist=0;
int parts;
int posic[501];
int vito;
int absol(int x, int y){
    return sqrt((x-y)*(x-y));
}
int dividir(int *array, int inicio, int fin) {
    int izq;
    int der;
    int pivot;
    int aux;
    pivot = array[inicio];
    izq = inicio;
    der = fin;
    while (izq < der) {
        while (array[der] > pivot) {
            der--;
        }
        while ((izq < der) && (array[izq] <= pivot)) {
            izq++;
        }
        if (izq < der) {
            aux = array[izq];
            array[izq] = array[der];
            array[der] = aux;
        }
    }
    aux = array[der];
    array[der] = array[inicio];
    array[inicio] = aux;
    return der;
}
void quicksort(int *array, int inicio, int fin)
{
    int pivot;
    if (inicio < fin) {
        pivot = dividir(array, inicio, fin);
        quicksort(array, inicio, pivot - 1);
        quicksort(array, pivot + 1, fin);
    }
}

int main(){
cin>>n;
    for(int i=0; i<=n-1; i++){
        cin>>parts;
        for(int i=0; i<=parts-1; i++){
            cin>>posic[i];
        }
    quicksort(posic, 0, parts - 1);
    vito=posic[(parts-1)/2];
        for(int i=0; i<=parts-1; i++){
            dist=dist+absol(vito,posic[i]);
        }
    cout<<dist<<endl;
    dist=0;    
    }
}
