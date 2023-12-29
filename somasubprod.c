#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"

polinomio soma_polinomio(polinomio p, polinomio q)
/*
    Retorna a soma de dois polinomios
*/
{
    if (!polinomio_is_null(p) && !polinomio_is_null(q))
    {
        //grau do polinomio de saída é o maior grau entre p e q
        int grau;
        if (p.n<q.n)
        {
            grau = q.n;
        }
        else
        {
            grau = p.n;
        }
        polinomio soma = new_polinomio(grau);

        //Checa se soma é null
        if (!polinomio_is_null(soma))
        {
            for (int i=0; i<=grau; i++)
            {
                if (i<=p.n)
                {
                    soma.coef[i] += p.coef[i];
                }
                if (i<=q.n)
                {
                    soma.coef[i] += q.coef[i];
                }
            }
            return soma;
        }
        printf("[soma_polinomio] Falha na alocação.\n");
        return new_polinomio(-1); //polinomio null

    }
    printf("[soma_polinomio] Polinômio de entrada é NULL.\n");
    return new_polinomio(-1); //polinomio null
}

polinomio sub_polinomio(polinomio p, polinomio q)
/*
    Retorna a subtração de dois polinomios (p-q) 
*/
{
    if (!polinomio_is_null(p) && !polinomio_is_null(q))
    {
        //grau do polinomio de saída é o maior grau entre p e q
        int grau;
        if (p.n<q.n)
        {
            grau = q.n;
        }
        else
        {
            grau = p.n;
        }
        polinomio sub = new_polinomio(grau);

        //Checa se sub é null
        if (!polinomio_is_null(sub))
        {
            //Cálculo da subtração
            for (int i=0; i<=grau; i++)
            {
                if (i<=p.n)
                {
                    sub.coef[i] += p.coef[i];
                }
                if (i<=q.n)
                {
                    sub.coef[i] -= q.coef[i];
                }
            }
            return sub;
        }
        printf("[sub_polinomio] Falha na alocação.\n");
        return new_polinomio(-1); //polinomio null
    }
    printf("[sub_polinomio] Polinômio de entrada é NULL.\n");
    return new_polinomio(-1); //polinomio null
}

polinomio prod_polinomio(polinomio p, polinomio q)
/*
    Retorna o produto de dois polinomios
*/
{
    if (!polinomio_is_null(p) && !polinomio_is_null(q))
    {
        //grau do polinomio de saída é a soma dos graus de p e q
        int grau = p.n+q.n;
        polinomio prod = new_polinomio(grau);

        //Checa se prod é null
        if (!polinomio_is_null(prod))
        {
            //Calcula produto iterando sobre os dois conjuntos de coeficientes
            for (int i=0; i<=p.n; i++)
                for (int j=0; j<=q.n; j++)
                {
                    /*Grau do produto de dois coeficientes é a soma de seus
                    índices: propriedade da soma de expoentes.*/
                    prod.coef[i+j] += p.coef[i]*q.coef[j];
                }
            return prod;
        }
        printf("[prod_polinomio] Falha na alocação.\n");
        return new_polinomio(-1); //polinomio null

    }
    printf("[prod_polinomio] Polinômio de entrada é NULL.\n");
    return new_polinomio(-1); //polinomio null
}