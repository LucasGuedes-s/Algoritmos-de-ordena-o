#include <iostream>
#include <vector> /*Biblioteca ultilizada para gerar vetores */
#include <random> /*Biblioteca ultilizada para contagem do tempo */

using namespace std;

int main()
{
    vector<int> vetor(10);
    
    
    //Preenchendo o vetor com valores aleatórios
    for (int i = 0; i < vetor.size(); i++) {
        vetor[i] = rand() % 500 + 1; /* Limitando os valores somente de 1 - 500 */
    }
    
    // Gerando cópias do vetor para serem testadas em cada algorítmo de ordenação
    vector<int> bubbleSort = vetor;
    vector<int> selectionSort = vetor;
    vector<int> insertionSort = vetor;
    vector<int> shellSort = vetor;
    vector<int> quickSort = vetor;
    vector<int> mergeSort = vetor;
    
    /* Mostrar os valores do vetor
    for(int j = 0; j < vetor.size(); j++){
        cout<<vetor[j]<<endl;
    } */
    
    return 0;
}
