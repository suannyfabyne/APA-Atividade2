#include <iostream> 
#include <fstream>
#include <stdlib.h>
using namespace std;

void Printsort(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
	}

}

void Group(int arr[], int inicio, int meio, int fim, int aux[]) {
    int inf = inicio;
    int sup = meio;
    for (int i = inicio; i < fim; ++i) {
        if ((inf < meio) && ((sup >= fim) || (arr[inf] < arr[sup]))) {
            aux[i] = arr[inf];
            ++inf;
        }
        else {
            aux[i] = arr[sup];
            ++sup;
        }
    }
    for (int i = inicio; i < fim; ++i) {
        arr[i] = aux[i];
    }
}

void MergeSort(int arr[], int inicio, int fim, int aux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    MergeSort(arr, inicio, meio, aux);
    MergeSort(arr, meio, fim, aux);
    Group(arr, inicio, meio, fim, aux);
}


int main() {

	char casodeteste[20]; 
	cout << "Digite um caso de teste: " << endl;
	cin >> casodeteste;

	int array[100000]; 
	int linhas = 0; 

	 ifstream myReadFile;
	 myReadFile.open(casodeteste);
	 char output[1000];
	 if (myReadFile.is_open()) {
	 while (!myReadFile.eof()) {


	    myReadFile >> output;
	    array[linhas] = atoi(output);
	   	linhas++;

	 }
	}
	myReadFile.close();

	int aux[linhas];
	MergeSort(array, 0, linhas, aux);
	Printsort(array, linhas);
	return 0;
}