#include <iostream>
#include <chrono>
#include <vector> /*Biblioteca ultilizada para gerar vetores */
#include <random> /*Biblioteca ultilizada para contagem do tempo */

using namespace std;
using namespace std::chrono;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

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
//v_quickSort

int partition(vector<int> &v, int low, int high){
	int pivot = v[high];
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot) {
		    
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i + 1], &v[high]);
	
	return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
	if (low < high) { 
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
}
int main()
{
    vector<int> vetor(50);
    //Preenchendo o vetor com valores aleatórios
    
    for (int i = 0; i < vetor.size(); i++) {
        vetor[i] = rand() % 100 + 1; // Limitando os valores somente de 1 - 500
    }
    
    // Gerando cópias do vetor para serem testadas em cada algorítmo de ordenação
    
    vector<int> v_bubbleSort = vetor;
    vector<int> v_insertionSort = vetor;
    vector<int> v_selectionSort = vetor;
    vector<int> v_mergeSort = vetor;
    vector<int> v_quickSort = vetor;
    vector<int> v_shellSort = vetor;

    /*Tempo (bubbleSort)*/
    auto inicio_bubble = high_resolution_clock::now();
    bubbleSort(v_bubbleSort);
    auto fim_bubble = high_resolution_clock::now();
    duration<double> tempo_bubble = fim_bubble - inicio_bubble;
    
    /*Tempo (insertionSort)*/
    auto inicio_insertion = high_resolution_clock::now();
    insertionSort(v_insertionSort);
    auto fim_insertion = high_resolution_clock::now();
    duration<double> tempo_insertion = fim_insertion - inicio_insertion;
    
    /*Tempo (selectionSort)*/
    auto inicio_selection = high_resolution_clock::now();
    selectionSort(v_selectionSort);
    auto fim_selection = high_resolution_clock::now();
    duration<double> tempo_selection = fim_selection - inicio_selection;
    
    /*Tempo (mergeSortSort)*/
    auto inicio_mergin = high_resolution_clock::now();
    mergeSort(v_mergeSort, 0, v_mergeSort.size() - 1);
    auto fim_mergin = high_resolution_clock::now();
    duration<double> tempo_merge = fim_mergin - inicio_mergin;
    
    /*Tempo (quickSort)*/
    auto inicio_quick = high_resolution_clock::now();
    quickSort(v_quickSort, 0, v_mergeSort.size() - 1);
    auto fim_quick = high_resolution_clock::now();
    duration<double> tempo_quick = fim_quick - inicio_quick;
    
    /*Tempo (shellSort)*/

    cout << "Tempo (bubbleSort): " << fixed << tempo_bubble.count() << "s" << endl;
    cout << "Tempo (insertionSort): " << fixed << tempo_insertion.count() << "s" << endl;
    cout << "Tempo (selectionSort): " << fixed << tempo_selection.count() << "s" << endl;
    cout << "Tempo (mergeSort): " << fixed << tempo_merge.count() << "s" << endl;
    cout << "Tempo (quickSort): " << fixed << tempo_quick.count() << "s" << endl;
    // cout << "Tempo (shellSort): " << fixed << .count() << "s" << endl;

    return 0;
}
