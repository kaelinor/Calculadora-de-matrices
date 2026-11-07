/* Examen Parcial 2 de Programacion Basica

Proyecto: Calculadora de Matrices

*/

#include <stdio.h>

// Declaracion de matrices precargadas
float matriz1[2][2] = {{2.0, 5.0}, {3.0, 1.0}};
float matriz2[2][2] = {{1.0, 2.0}, {4.0, 3.0}};
float matriz3[2][2] = {{9.0, 8.0}, {7.0, 6.0}};
float matriz4[3][3] = {{5.0, 4.0, 3.0}, {2.0, 1.0, 0.0}, {6.0, 7.0, 8.0}};
float matriz5[3][3] = {{5.0, 4.0, 3.0}, {2.0, -1.0, 0.0}, {2.0, 1.0, 9.0}};

void sumaMatrices(void)
{
    int filasU, columnasU, filasV, columnasV;
    int opcionSuma = 0;
    
    printf("¿Desea ingresar sus propias matrices o elegir matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionSuma);
    while(opcionSuma != 1 && opcionSuma != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionSuma);
    }
    
    if(opcionSuma == 1) {
        //Ingresar matrices manualmente

        //Ingresar dimensiones de las matrices
        printf("Ingrese las filas de las matrices (Hasta 3 filas):\n");
        scanf("%d", &filasU);
        while(filasU < 1 || filasU > 3) {
            printf("Número de filas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &filasU);
        }
        printf("Ingrese las columnas de las matrices (Hasta 3 columnas):\n");
        scanf("%d", &columnasU);
        while(columnasU < 1 || columnasU > 3) {
            printf("Número de columnas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &columnasU);
        }

        //Asignar dimensiones de la segunda matriz iguales a la primera
        filasV = filasU;
        columnasV = columnasU;
        
        //Declarar matrices
        float matrizU1[filasU][columnasU];
        float matrizV1[filasV][columnasV];
        float matrizResU[filasU][columnasU];

        //Ingresar datos de las matrices
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                printf("Ingrese el elemento [%d][%d] de la primera matriz: ", i, j);
                scanf("%f", &matrizU1[i][j]);
            }
        }

        printf("\n");

        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                printf("Ingrese el elemento [%d][%d] de la segunda matriz: ", i, j);
                scanf("%f", &matrizV1[i][j]);
            }
        }

        //Suma de matrices
        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                matrizResU[i][j] = matrizU1[i][j] + matrizV1[i][j];
            }
        }

        printf("Resultado de la suma de matrices:\n");
        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                printf("%.2f ", matrizResU[i][j]);
            }
            printf("\n");
        }



    } else if (opcionSuma == 2) {
        // Lógica para elegir matrices precargadas

        
    }

}

int main(){
    //Menu de opciones
    int opcion = 0;

    printf("Calculadora de Matrices 1.0\n");
    printf("¿Que desea hacer?\n");
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
            sumaMatrices();

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