/* Examen Parcial 2 de Programacion Basica

Proyecto: Calculadora de Matrices

*/

#include <stdio.h>

int main(){
    int opcion = 0;
    printf("Calculadora de Matrices 1.0\n");
    printf("Que desea hacer?\n");
    printf("1. Sumar matrices\n");
    printf("2. Restar matrices\n");
    printf("3. Multiplicar por un escalar\n");
    printf("4. Multiplicar matrices\n");
    printf("5. Determinante de una matriz\n");
    printf("6. Transpuesta de una matriz\n");
    printf("7. Inversa de una matriz\n");

    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 7){
        printf("Opcion invalida, por favor ingrese una opcion valida: ");
        scanf("%d", &opcion);
    }

    switch(opcion){
        case 1:
            printf("Suma de matrices\n");
            break;
        case 2:
            printf("Resta de matrices\n");
            break;
        case 3:
            printf("Multiplicacion por un escalar\n");
            break;
        case 4:
            printf("Multiplicacion de matrices\n");
            break;
        case 5:
            printf("Determinante de una matriz\n");
            break;
        case 6:
            printf("Transpuesta de una matriz\n");
            break;
        case 7:
            printf("Inversa de una matriz\n");
            break;
    }
    
    
    
    
    
    
    return 0;
}