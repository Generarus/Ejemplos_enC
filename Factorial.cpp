/*COMENTARIOS SON PARA NOSOTROS DEL FUTURO
NOMBRE DEL PROGRAMA
AUTOR
MODIFICADO POR
QUE HACE EL PROGRAMA
NECESITA UN CIRCUITO
COLOCAR UNA IMAGEN EN EL REPOSITORIO: "AGREGAR LIGA QUE NOS LLEVA A ESE CIRCUITO"
TERMINALES QUE SE UTILIZAN, EL MODO
EJEMPLO: gpio5 salida*/

/*bibliotecas*/
#include <stdio.h>


/*declaracicion de variables con el tipo correspondiente*/

/*estructura main*/

int main() {
    unsigned long long int i, n, factorial;
    
    printf("\nHola UAM, soy Genaro\n");
    printf("\nDeme el valor de un número entero positivo menor a 66: ");
    scanf("%llu", &n);
    factorial=1;
    if (n==0 || n==1) printf("\nEl factorial de %llu es %llu\n\n", n, factorial);
    else {
        if(n>=2 && n<=65){
            for (i=2; i<=n; i++) factorial=factorial*i;
            printf("\nEl factorial de %llu es %llu\n\n", n, factorial);
        }
    }
    if(n<0 || n>65) printf("\nNúmero fuera del intervalo solicitado.\n\n");
    return 0;
}