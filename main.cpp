#include <iostream>
#include <vector> /*Biblioteca ultilizada para gerar vetores */
#include <random> /*Biblioteca ultilizada para contagem do tempo */

using namespace std;


void insertionSort(vector<int> &v){

	int n = v.size();
	int i, key, j;
	
	for(i=1; i<n; i++){
		key = v[i];
		j = i-1;
		
		while(j>=0 && v[j] > key){
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = key;
	}
}


int main()
{
    vector<int> vetor(10);
    
    
    //Preenchendo o vetor com valores aleatórios
    
    for (int i = 0; i < vetor.size(); i++) {
        vetor[i] = rand() % 500 + 1; // Limitando os valores somente de 1 - 500
    }
    
    // Gerando cópias do vetor para serem testadas em cada algorítmo de ordenação
    
    vector<int> v_bubbleSort = vetor;
    vector<int> v_selectionSort = vetor;
    vector<int> v_insertionSort = vetor;
    vector<int> v_shellSort = vetor;
    vector<int> v_quickSort = vetor;
    vector<int> v_mergeSort = vetor;
    
    insertionSort(v_insertionSort);
    
    
    //Mostrar os valores do vetor desordenado

    for(int j = 0; j < vetor.size(); j++){
        cout<<vetor[j]<<endl;
    }
    cout<< "------------------"<<endl;
    
    //Mostrar os valores do vetor já ordenado! Esse for serve para confirmar se o vetor esta sendo ordenado
    
    for(int j = 0; j < v_insertionSort.size(); j++){
        cout<<vetor[j]<<endl;
    }
    
    return 0;
}
