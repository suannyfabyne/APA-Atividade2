#include <iostream> 
#include <fstream>
#include <stdlib.h>

using namespace std;

void printsort(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
		
	}

}

void quicksort(int *arr, int left, int right){
    int min = (left+right)/2;
    int i = left, j = right;
    int pivo = arr[min];
    int aux;
    while(left<j || i<right) {
        while(arr[i]<pivo) i++;
        while(arr[j]>pivo) j--;

        if(i<=j){
            aux = arr[i];
		    arr[i] = arr[j];
		    arr[j] = aux;
            i++;
            j--;
        }
        else{
            if(left<j)
                quicksort(arr, left, j);
            if(i<right)
                quicksort(arr,i,right);
            return;
        }
    }
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

	cout << linhas << "aI" ;
	    myReadFile >> output;
	    array[linhas] = atoi(output);
	   	linhas++;

	 }
	}
	myReadFile.close();

	int array2[6] = {7,4,2,9,1,3};
	cout << linhas << "OI" ;
	quicksort(array, 0, linhas-1);
	printsort(array, linhas);
	return 0;
}