#include <iostream>
#include <vector> /*Biblioteca ultilizada para gerar vetores */
#include <random> /*Biblioteca ultilizada para preencher vetor */

using namespace std;

//BubbleSort
void bubbleSort(vector<int> &v){
	
	int n=v.size();
	
	for(int i=0; i<n-1; i++){
		for (int j=0; j<n-i-1; j++){
			if(v[j] > v[j+1]){
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			} 
		}
	}
}

//insertionSort
void insertionSort(vector<int> &v){

	int n = v.size();
	
	int i, key, j;
	
	for(i=1; i < n; i++){
		key = v[i];
		j = i-1;
		
		while(j >= 0 && v[j] > key){
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = key;
	}
}

//selectionSort
void selectionSort(vector<int> &v){
	
	int min_idx;
	int n=v.size();
	for(int i=0; i<n-1; i++){
		min_idx=i;
		for(int j=i+1; j<n; j++){
			if(v[j] < v[min_idx])
				min_idx=j;
		}
		if(min_idx!=i){
			int temp = v[min_idx];
			v[min_idx] = v[i];
			v[i] = temp;
		}
	}
}

//MerginSort
void merge(vector<int> &v, int low, int high, int mid){
	int i, j, k, c[50];
	
	i = low;
	k = low;
	j = mid + 1;
	
    while (i <= mid && j <= high){
    	if (v[i] < v[j]){
        		c[k] = v[i];
        		k++;
        		i++;
    	}
    	else{
        		c[k] = v[j];
        		k++;
        		j++;
    	}
	}
	while (i <= mid){
    	c[k] = v[i];
    	k++;
    	i++;
	}
	while (j <= high){
    	c[k] = v[j];
    	k++;
    	j++;
	}
	for (i = low; i < k; i++){
    	v[i] = c[i];
	}
}

void mergeSort(vector<int> &v, int low, int high){
	if(low < high){
	    
	    int mid;
		mid = (low+high)/2;
		
		mergeSort(v, low, mid);
		
		mergeSort(v, mid+1, high);
		
		merge(v,low,high,mid);
	}

}

int main()
{
    vector<int> vetor(10);
    
    //Preenchendo o vetor com valores aleatórios
    
    for (int i = 0; i < vetor.size(); i++) {
        vetor[i] = rand() % 100 + 1; // Limitando os valores somente de 1 - 500
    }
    
    // Gerando cópias do vetor para serem testadas em cada algorítmo de ordenação
    
    vector<int> v_bubbleSort = vetor;
    vector<int> v_selectionSort = vetor;
    vector<int> v_insertionSort = vetor;
    vector<int> v_shellSort = vetor;
    vector<int> v_quickSort = vetor;
    vector<int> v_mergeSort = vetor;

    insertionSort(v_insertionSort);
    mergeSort(v_mergeSort, 0, v_mergeSort.size() - 1);
	bubbleSort(v_bubbleSort);
	selectionSort(v_selectionSort);
    
    //Mostrar os valores do vetor desordenado

    for(int j = 0; j < vetor.size(); j++){
        cout<<vetor[j]<<endl;
    }
    
    //Mostrar os valores do vetor já ordenado! Esse for serve para confirmar se o vetor esta sendo ordenado
    cout<< "---------insertionSort---------"<<endl;

    for(int j = 0; j < v_insertionSort.size(); j++){
        cout<<v_insertionSort[j]<<endl;
    }
    
    cout<< "---------MergeSort---------"<<endl;

    for(int j = 0; j < v_mergeSort.size(); j++){
        cout<<v_mergeSort[j]<<endl;
    }
    return 0;
}
