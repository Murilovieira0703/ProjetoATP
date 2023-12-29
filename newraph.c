#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "polinomio.h"

float newton_raphson(polinomio p, float x_0, float epsilon, int t_max)
/*
    Método de Newton-Raphson para raízes de polinômios.
    x_0: condição inicial do método
    epsilon: precisão desejada
    t_max: número máximo de iterações.
*/
{
    if (!polinomio_is_null(p))
    {
        polinomio drv = deriva_polinomio(p);
        if (!polinomio_is_null(drv))
        {
            //Inicializa número de iterações
            int t = 0;
            //Inicializa precisão para um valor maior que epsilon
            float delta = 1+epsilon;

            //Variáveis do método
            float x = 0; //valor de saída
            float aux = x_0; //Para armazenar valor anterior

            while(t<t_max && delta>epsilon)
            {
                float valor_drv = valor_polinomio(drv,aux);
                if (valor_drv!=0)
                {
                    //Atualiza x
                    x = aux-valor_polinomio(p,aux)/valor_drv;
                    //Calcula variação entre iterações
                    delta = fabsf(x-aux);
                    //Atualiza aux com último valor de x
                    aux = x;
                    //Incrementa t
                    t++;
                }
                else
                {
                    printf("[newton_raphson] Derivada é nula.");
                    free_polinomio(&drv);
                    return 0;
                }
            }
            free_polinomio(&drv);
            return x;
        }
        printf("[newton_raphson] Falha na alocação.");
        return 0;
    }
    printf("[newton_raphson] Polinômio de entrada é NULL.");
    return 0;
}