#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"

polinomio new_polinomio(int n)
/*
    Inicializa novo polinomio. Coeficientes são inicalizados para zero.
*/
{
    polinomio p;
    if (n>=0)
    {
        //Polinomio de grau n possui n+1 coeficientes
        p.coef = malloc((n+1)*sizeof(float));
        if (p.coef!=NULL)
        {
            p.n = n;
            //Inicializa coefieficientes pra 0. Isso facilita em outras funções
            for (int i=0; i<=n; i++)
            {
                p.coef[i] = 0;
            }
        }
        else //polinomio null se alocação falha
        {
            printf("[new_polinomio] Falha na alocação de memória. \n");
            p.n = -1;
        }
    }
    else //polinomio null se n<0
    {
        p.n = -1;
        p.coef = NULL;
    }
    return p;
}

void free_polinomio(polinomio *p)
/*
    Libera memoria do struct de polinomio
*/
{
    if (p->coef!=NULL)
    {   
        free(p->coef);
        p->coef = NULL;
    }
}

bool polinomio_is_null(polinomio p)
/*
    Checa se polinomio é null.
*/
{
    if (p.n<0 || p.coef==NULL)
    {
        return true;
    }
    return false;
}

float valor_polinomio(polinomio p, float x)
/*
    Retorna p(x)
*/
{
    if (!polinomio_is_null(p))
    {
        float valor = 0; //valor de retorno
        float pot = 1; //variável para armazenar potências
        for (int i=0; i<=p.n; i++)
        {
            valor += pot*p.coef[i];
            pot *= x; //incrementa potencia
        }
        return valor;
    }
    else
    {
        printf("[valor_polinomio] Polinomio de entrada é NULL.\n");
        return 0;
    }
}

polinomio polinomio_from_file(char *filename)
/*
    Função para ler os coeficientes de um polinômio de um arquivo.
*/
{
    FILE *fp = fopen(filename,"r");
    if (fp!=NULL)
    {
        //Número de linhas -1 é o grau do polinômio
        int num_lin = -1; //contador do número de linhas no arquivo
        float aux; //para ler linhas do arquivo e jogar fora
        //Contagem do número de linhas
        while (!feof(fp))
        {
            fscanf(fp,"%f",&aux); //para mover o ponteiro fp pelo arquivo
            num_lin++;
        }
        
        polinomio p = new_polinomio(num_lin);
        //Reinicia ponteiro fp para o começo do arquivo
        fseek(fp,0,SEEK_SET);
        //Armazena coeficientes do polinômio
        for (int i=0; i<=p.n; i++)
        {
            fscanf(fp,"%f",&p.coef[i]);
        }
        return p;
    }
    else
    {
        printf("[polinomio_from_file] Não foi possível abrir arquivo.");
        return new_polinomio(-1);
    }
}

void print_polinomio(polinomio p)
/*
    Imprime coeficientes do polinomio na tela. Aqui eu fiz algo um pouco mais
bonitinho pra se assemelhar à notação humana. Imprimir na tela somente os ele-
mentos de p.coef também é considerado correto.
*/
{
    if (!polinomio_is_null(p))
    {
        printf("p(x) = (%f)",p.coef[0]);
        for (int i=1; i<=p.n; i++)
        {
            printf("+(%f)x^%d",p.coef[i],i);
        }
        printf(" \n");
    }
    else
    {
        printf("[print_polinomio] Polinômio de entrada é NULL. \n");
    }
}