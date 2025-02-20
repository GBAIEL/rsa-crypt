#include <stdio.h>

int modInverse(int a, int m) //Função para encontrar o segundo numero da Chave Privada(inverso modular).
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x;
}

int descriptografar(int d, int k, int i, int codigo[]) //Função que recebe a Chave Privada e o Codigo criptografado e descriptografa.
{
    int n;
    int resultado, pot;
    n = codigo[i];
    pot = n % d;
    resultado = 1;
    for( ; k > 0; k /= 2)
    {
        if (k % 2 == 1)
        {
            resultado = (resultado * pot) % d;
        }
            pot = (pot * pot) % d;
        
    }
    return resultado;
}

int main()
{
    int k, d;
    int p, q, e;
    int res;
    int aux;
    int n = 0;
    char alfabeto[28] = " abcdefghijklmnopqrstuvwxyz "; //Alfabeto que o professor pediu. A = 2, B = 3... Z = 27, espaço = 28.
    scanf("%d %d", &p, &q);
    scanf("%d", &e);
    
    int codigo[2000];

    for(aux = 0; aux < 2000; aux++) // for para definir todos os elementos do array codigo como -555.
    {
        codigo[aux] = -555;
    }

    for(aux = 0; aux < 2000; aux++)  // for para substituir os elementos do array codigo pelo codigo criptografado.
    {
        if(scanf("%d", &codigo[aux])==EOF){aux+=2000;}
    }

    for(aux = 0; aux != 2000; aux++) // for para contar quantos elementos o array tem até encontrar o primeiro -555.
    {
        if(codigo[aux]!=-555)
        {
            n++;
        }
    }
  
    d = p*q;                          // d = primeiro numero da chave privada.
    k = modInverse(e, ((p-1)*(q-1))); // k = segundo numero da chave privada.

    for(int i = 1; i <= n; i++)       // ultimo for, rodar a função descriptografar n vezes.
    {
        res = descriptografar(d, k, i-1, codigo);
        printf("%c", alfabeto[res-1]); 
    }

    printf("\n");
    return 0;
}
//formato de entrada por arquivo:
// p q e
// codigo criptografado
