#include <iostream>
#include <chrono>
#include <vector> /*Biblioteca ultilizada para gerar vetores */
#include <random> /*Biblioteca ultilizada para contagem do tempo */

using namespace std;
using namespace std::chrono;

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
    vector<int> vetor(1000);
    cout<<"Crou o vetor"<<endl;
    //Preenchendo o vetor com valores aleatórios
    
    for (int i = 0; i < vetor.size(); i++) {
        vetor[i] = rand() % 100 + 1; // Limitando os valores somente de 1 - 500
    }
    cout<<"Preencheu o vetor"<<endl;

    // Gerando cópias do vetor para serem testadas em cada algorítmo de ordenação
    
    vector<int> v_bubbleSort = vetor;
    vector<int> v_selectionSort = vetor;
    vector<int> v_insertionSort = vetor;
    vector<int> v_shellSort = vetor;
    vector<int> v_quickSort = vetor;
    vector<int> v_mergeSort = vetor;
    
    cout<<"copias o vetor"<<endl;

    auto inicio_insertion = high_resolution_clock::now();
    insertionSort(v_insertionSort);
    auto fim_insertion = high_resolution_clock::now();
    duration<double> tempo = fim_insertion - inicio_insertion;
    
    auto inicio_bubble = high_resolution_clock::now();
    bubbleSort(v_bubbleSort);
    auto fim_bubble = high_resolution_clock::now();
    duration<double> tempo_bubble = fim_bubble - inicio_bubble;

    
    cout << "Tempo (insertionSort): " << fixed << tempo.count() << "s" << endl;
    cout << "Tempo (bubbleSort): " << fixed << tempo_bubble.count() << "s" << endl;

    return 0;
}
