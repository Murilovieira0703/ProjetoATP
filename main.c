#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Uso de um único cabeçalho por praticidade
#include "polinomio.h"

int main ()
{
    printf("Entre com o arquivo do primeiro polinômio: ");
    char fname1[100];
    scanf("%s",fname1);
    polinomio p = polinomio_from_file(fname1);
    printf("Primeiro polinômio: \n");
    print_polinomio(p);
    polinomio dv_p = deriva_polinomio(p);
    printf("Derivada do primeiro polinômio: \n");
    print_polinomio(dv_p);

    printf("Entre com o arquivo do segundo polinômio: ");
    char fname2[100];
    scanf("%s",fname2);
    polinomio q = polinomio_from_file(fname2);
    printf("Segundo polinômio: \n");
    print_polinomio(q);
    polinomio dv_q = deriva_polinomio(q);
    printf("Derivada do segundo polinômio: \n");
    print_polinomio(dv_q);

    polinomio soma = soma_polinomio(p,q);
    printf("Soma dos polinômios: \n");
    print_polinomio(soma);
    free_polinomio(&soma);

    polinomio sub = sub_polinomio(p,q);
    printf("Subtração dos polinômios: ");
    print_polinomio(sub);
    free_polinomio(&sub);

    polinomio prod = prod_polinomio(p,q);
    printf("Produto dos polinômios: ");
    print_polinomio(prod);
    free_polinomio(&prod);

    printf("Digite os limites inferior e superior de integração: ");
    float a, b;
    scanf("%f %f",&a,&b);
    printf("Valor da integral definida do primeiro polinômio: %f\n",
        integraldef_polinomio(p,a,b));
    printf("Valor da integral definida do segundo polinômio: %f\n",
        integraldef_polinomio(q,a,b));
    
    printf("Digite agora os parâmetros para o método de Newton-Raphson. \n");
    float x_0;
    printf("Valor inicial de x: ");
    scanf("%f",&x_0);
    float eps;
    printf("Valor da precisão numérica epsilon: ");
    scanf("%f",&eps);
    int t_max;
    printf("Número máximo de iterações: ");
    scanf("%d",&t_max);

    printf("Uma raíz do primeiro polinômio é (aproximadamente) %f\n",
        newton_raphson(p,x_0,eps,t_max));
    printf("Uma raíz do segundo polinômio é (aproximadamente) %f\n",
        newton_raphson(q,x_0,eps,t_max));
    
    return 0;
}