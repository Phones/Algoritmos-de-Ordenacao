#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
#define pb push_back

void imprime_vetor(vi &vetor)
{
    for (int i = 0; i < (int)vetor.size(); i++)
    {
        printf("%d ", vetor[i]);  
    }
    puts("");
}

void merge(vi &vetor, int inicio, int meio, int fim)
{
    vi vetor_final ((int)vetor.size() + 10, 0);
    int i = inicio, j = meio + 1, k = inicio;
    while(i <= meio && j <= fim)
    { 
        if (vetor[i] <= vetor[j])
        {
            vetor_final[k] = vetor[i];
            i++;
        }
        else
        {
            vetor_final[k] = vetor[j];
            j++;
        }
        k++;
    }

    while (i < meio)
    {
        vetor_final[k] = vetor[i];
        k++;
        i++;
    }

    while (j < fim)
    {
        vetor_final[k] = vetor[j];
        k++;
        j++;
    }
    
    for (int f = inicio;f < fim; f++)
        vetor[f] = vetor_final[f];
}

void mergesort(vi &vetor, int inicio, int fim)
{
    if (inicio >= fim)
        return;
 
    int meio = (inicio + fim) / 2;
    mergesort(vetor, inicio, meio);
    mergesort(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
}

int main()
{
    int N = 10;
    vi vetor = {1,9,5,7,8,10,4,2,6,3};
    puts("=====================================");
    imprime_vetor(vetor);
    puts("=====================================");
    mergesort(vetor, 0, N);
    imprime_vetor(vetor);
    puts("=====================================");
}
