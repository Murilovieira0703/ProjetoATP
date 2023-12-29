#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"

polinomio deriva_polinomio(polinomio p)
/*
    Retorna a derivada de um polinomio.
*/
{
    if (!polinomio_is_null(p))
    {
        /*Caso particular: derivada do polinomio de grau zero é um polinomio
        de grau zero com coeficiente nulo.*/
        if (p.n==0)
        {
            return new_polinomio(0);
        }
        else
        {
            //Derivada do polinomio é um polinomio de grau p.n-1
            polinomio drv = new_polinomio(p.n-1);
            if (!polinomio_is_null(drv))
            {
                //Cálculo da derivada
                for (int i=1; i<=p.n; i++)
                {
                    drv.coef[i-1] = i*p.coef[i];
                }
                return drv;
            }
            printf("[deriva_polinomio] Falha na alocação.");
            return new_polinomio(-1);
        }
    }
    printf("[deriva_polinomio] Polinomio de entrada é NULL.");
    return new_polinomio(-1);
}

polinomio integra_polinomio(polinomio p, float C)
/*
    Retorna a integral indefinida de um polinomio.
    C: constante de integração
*/
{
    if (!polinomio_is_null(p))
    {
        //Integral do polinomio é um polinomio de grau p.n+1
        polinomio integ = new_polinomio(p.n+1);
        if (!polinomio_is_null(integ))
        {
            //Constante de integração é o coeficiente de ordem 0
            integ.coef[0] = C;
            for (int i=0; i<=p.n; i++)
            {
                integ.coef[i+1] = p.coef[i]/(i+1);
            }
            return integ;
        }
        printf("[integra_polinomio] Falha na alocação.");
        return new_polinomio(-1);
    }
    printf("[integra_polinomio] Polinomio de entrada é NULL.");
    return new_polinomio(-1);
}

float integraldef_polinomio(polinomio p, float a, float b)
/*
    Integral definida de a até b. 
*/
{
    if (!polinomio_is_null(p))
    {
        polinomio integ = integra_polinomio(p,0);
        if (!polinomio_is_null(integ))
        {   
            float valor = valor_polinomio(integ,b)-valor_polinomio(integ,a);
            free_polinomio(&integ);
            return valor;
        }
        printf("[integraldef_polinomio] Falha na alocação.");
        return 0;
    }
    printf("[integraldef_polinomio] Polinomio de entrada é NULL.");
    return 0;
}