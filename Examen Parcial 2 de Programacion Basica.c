/* Examen Parcial 2 de Programacion Basica

Proyecto: Calculadora de Matrices
Integrantes: Cielo Cuatle Uriel (202631542)
             Tellez Zirate Vicente Tadeo (202629158)

*/

#include <stdio.h>

// Declaracion de matrices precargadas
float matriz1[2][2] = {{2.0, 5.0}, {3.0, 1.0}};
float matriz2[2][2] = {{1.0, 2.0}, {4.0, 3.0}};
float matriz3[2][2] = {{9.0, 8.0}, {7.0, 6.0}};
float matriz4[3][3] = {{5.0, 4.0, 3.0}, {2.0, 1.0, 0.0}, {6.0, 7.0, 8.0}};
float matriz5[3][3] = {{5.0, 4.0, 3.0}, {2.0, -1.0, 0.0}, {2.0, 1.0, 9.0}};

//Logica de la suma  
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
    
    //Ingresar matrices manualmente
    if(opcionSuma == 1) {
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
        int matrizA, matrizB;

        printf("\nMatrices precargadas:\n");
        printf("1. Matriz 1 (2x2)\n");
        printf("2. Matriz 2 (2x2)\n");
        printf("3. Matriz 3 (2x2)\n");
        printf("4. Matriz 4 (3x3)\n");
        printf("5. Matriz 5 (3x3)\n");

        printf("\nSeleccione la primera matriz: ");
        scanf("%d", &matrizA);

        while(matrizA < 1 || matrizA > 5)
        {
            printf("Opcion invalida. Elija entre 1 y 5: ");
            scanf("%d", &matrizA);
        }

        printf("Seleccione la segunda matriz: ");
        scanf("%d", &matrizB);

        while(matrizB < 1 || matrizB > 5)
        {
            printf("Opcion invalida. Elija entre 1 y 5: ");
            scanf("%d", &matrizB);
        }

        // Verificar que las dimensiones sean iguales
        if((matrizA <= 3 && matrizB <= 3) || (matrizA >= 4 && matrizB >= 4))
        {
            int tamanio;

            if(matrizA <= 3)
                tamanio = 2;
            else
                tamanio = 3;
            printf("\nResultado de la suma:\n");

            for(int i = 0; i < tamanio; i++)
            {
                for(int j = 0; j < tamanio; j++)
                {
                    float valorA, valorB;

                    if(matrizA == 1)
                        valorA = matriz1[i][j];
                    else if(matrizA == 2)
                        valorA = matriz2[i][j];
                    else if(matrizA == 3)
                        valorA = matriz3[i][j];
                    else if(matrizA == 4)
                        valorA = matriz4[i][j];
                    else
                        valorA = matriz5[i][j];

                    if(matrizB == 1)
                        valorB = matriz1[i][j];
                    else if(matrizB == 2)
                        valorB = matriz2[i][j];
                    else if(matrizB == 3)
                        valorB = matriz3[i][j];
                    else if(matrizB == 4)
                        valorB = matriz4[i][j];
                    else
                        valorB = matriz5[i][j];

                    printf("%.2f ", valorA + valorB);
                }
                printf("\n");
            }
        }
        else
        {
            printf("\nError: No se pueden sumar matrices de diferentes dimensiones.\n");
        }
    }
    
}

//Logica de la resta
void restaMatrices(void)
{
    int filasU, columnasU, filasV, columnasV;
    int opcionResta = 0;
    
    printf("¿Desea ingresar sus propias matrices o elegir matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionResta);
    while(opcionResta != 1 && opcionResta != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionResta);
    }
    
    //Ingresar matrices manualmente
    if(opcionResta == 1) {
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

        //Resta de matrices
        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                matrizResU[i][j] = matrizU1[i][j] - matrizV1[i][j];
            }
        }

        printf("Resultado de la resta de matrices:\n");
        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                printf("%.2f ", matrizResU[i][j]);
            }
            printf("\n");
        }

    } else if (opcionResta == 2) {
        // Lógica para elegir matrices precargadas

        int matrizA, matrizB;
        float valorA, valorB;
        printf("\nMatrices precargadas:\n");
        printf("1. Matriz 1 (2x2)\n");
        printf("2. Matriz 2 (2x2)\n");
        printf("3. Matriz 3 (2x2)\n");
        printf("4. Matriz 4 (3x3)\n");
        printf("5. Matriz 5 (3x3)\n");

        printf("\nSeleccione la primera matriz: ");
        scanf("%d", &matrizA);

        while(matrizA < 1 || matrizA > 5)
        {
            printf("Opcion invalida. Elija entre 1 y 5: ");
            scanf("%d", &matrizA);
        }

        printf("Seleccione la segunda matriz: ");
        scanf("%d", &matrizB);

        while(matrizB < 1 || matrizB > 5)
        {
            printf("Opcion invalida. Elija entre 1 y 5: ");
            scanf("%d", &matrizB);
        }

        // Verificar que las dimensiones sean iguales
        if((matrizA <= 3 && matrizB <= 3) ||
           (matrizA >= 4 && matrizB >= 4))
        {
            int tamanio;

            if(matrizA <= 3)
                tamanio = 2;
            else
                tamanio = 3;
            printf("\nResultado de la resta:\n");
            for(int i = 0; i < tamanio; i++)
            {
                for(int j = 0; j < tamanio; j++)
                {
                    // Obtener valor de la primera matriz
                    if(matrizA == 1)
                        valorA = matriz1[i][j];
                    else if(matrizA == 2)
                        valorA = matriz2[i][j];
                    else if(matrizA == 3)
                        valorA = matriz3[i][j];
                    else if(matrizA == 4)
                        valorA = matriz4[i][j];
                    else
                        valorA = matriz5[i][j];
                    // Obtener valor de la segunda matriz
                    if(matrizB == 1)
                        valorB = matriz1[i][j];
                    else if(matrizB == 2)
                        valorB = matriz2[i][j];
                    else if(matrizB == 3)
                        valorB = matriz3[i][j];
                    else if(matrizB == 4)
                        valorB = matriz4[i][j];
                    else
                        valorB = matriz5[i][j];
                    printf("%.2f ", valorA - valorB);
                }
                printf("\n");
            }
        }
        else
        {
            printf("\nError: No se pueden restar matrices de diferentes dimensiones.\n");
        }

    }

}

//Logica de la multiplicacion por un escalar
void multiplicacionEscalar(void)
{
    int filasU, columnasU;
    float escalar = 0.0;
    int opcionEscalar = 0;

    printf("¿Desea ingresar sus propias matrices o elegir matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionEscalar);
    while(opcionEscalar != 1 && opcionEscalar != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionEscalar);
    }

    //Ingresar matrices manualmente
    if(opcionEscalar == 1) {
        //Ingresar dimensiones de las matrices
        printf("Ingrese las filas de la matricez (Hasta 3 filas):\n");
        scanf("%d", &filasU);
        while(filasU < 1 || filasU > 3) {
            printf("Número de filas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &filasU);
        }
        printf("Ingrese las columnas de la matriz (Hasta 3 columnas):\n");
        scanf("%d", &columnasU);
        while(columnasU < 1 || columnasU > 3) {
            printf("Número de columnas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &columnasU);
        }

        
        //Declarar matrices
        float matrizU1[filasU][columnasU];
        float matrizResU[filasU][columnasU];

        //Ingresar datos de las matrices
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                printf("Ingrese el elemento [%d][%d] de la primera matriz: ", i, j);
                scanf("%f", &matrizU1[i][j]);
            }
        }

        printf("\n");

        //Ingresar escalar K
        printf("Ingrese el escalar K: ");
        scanf("%f", &escalar);
        
        //Multiplicación por escalar
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                matrizResU[i][j] = matrizU1[i][j] * escalar;
            }
        }

        printf("Resultado de la multiplicación por escalar:\n");
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                printf("%.2f ", matrizResU[i][j]);
            }
            printf("\n");
        }

    } else if (opcionEscalar == 2) {
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
    while(opcion < 1 || opcion > 7)
    {
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
            restaMatrices();

            break;
        case 3:
            printf("Multiplicacion por un escalar\n");
            multiplicacionEscalar();

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