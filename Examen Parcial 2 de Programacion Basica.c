/* Examen Parcial 2 de Programacion Basica

Proyecto: Calculadora de Matrices
Integrantes: Cielo Cuatle Uriel (202631542)
             Tellez Zirate Vicente Tadeo (202629158)

*/

#include <stdio.h>
#include <math.h>

// Declaracion de matrices precargadas
float matriz1[2][2] = {{2.0, 5.0}, {3.0, 1.0}};
float matriz2[2][2] = {{1.0, 2.0}, {4.0, 3.0}};
float matriz3[2][2] = {{9.0, 8.0}, {7.0, 6.0}};
float matriz4[3][3] = {{5.0, 4.0, 3.0}, {2.0, 1.0, 0.0}, {6.0, 7.0, 8.0}};
float matriz5[3][3] = {{5.0, 4.0, 3.0}, {2.0, -1.0, 0.0}, {2.0, 1.0, 9.0}};
int seguir = 1;

void preguntarContinuar(void)
{
    printf("\n¿Desea volver al menu o salir? (1 = Volver al menu, 2 = Salir): ");
    scanf("%d", &seguir);
    while(seguir != 1 && seguir != 2) {
        printf("Opcion invalida. Por favor, elija 1 o 2: ");
        scanf("%d", &seguir);
    }
}

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

    preguntarContinuar();
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

        preguntarContinuar();
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
        int opcionmatriz;
    
        printf("\nMatrices precargadas:\n");
        printf("1. Matriz 1 (2x2)\n");
        printf("2. Matriz 2 (2x2)\n");
        printf("3. Matriz 3 (2x2)\n");
        printf("4. Matriz 4 (3x3)\n");
        printf("5. Matriz 5 (3x3)\n");
    
        printf("Seleccione la matriz a multiplicar por un escalar: ");
        scanf("%d", &opcionmatriz);
  
        while(opcionmatriz < 1 || opcionmatriz > 5)
        {
            printf("Opcion invalida. Elija entre 1 y 5: ");
            scanf("%d", &opcionmatriz);
        }

        printf("Ingrese el escalar K: ");
        scanf("%f", &escalar);

        if(opcionmatriz >= 1 && opcionmatriz <= 3)
        {
            printf("\nResultado:\n");

            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    float valor;

                    if(opcionmatriz == 1)
                        valor = matriz1[i][j];
                    else if(opcionmatriz == 2)
                        valor = matriz2[i][j];
                    else
                        valor = matriz3[i][j];

                    printf("%.2f ", valor * escalar);
                }
                printf("\n");
            }
        }
        else
        {
            printf("\nResultado:\n");

            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    float valor;

                    if(opcionmatriz == 4)
                        valor = matriz4[i][j];
                    else
                        valor = matriz5[i][j];

                    printf("%.2f ", valor * escalar);
                }
                printf("\n");
            }
        }
    }

    preguntarContinuar();

}

//Logica de la multiplicacion de matrices
void multiplicacionMatrices(void)
{
    int filasU, columnasU, filasV, columnasV;
    int opcionMulti = 0;
    
    printf("¿Desea ingresar sus propias matrices o elegir matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionMulti);
    while(opcionMulti != 1 && opcionMulti != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionMulti);
    }
    
    //Ingresar matrices manualmente
    if(opcionMulti == 1) {
        //Ingresar dimensiones de las matrices
        printf("Ingrese las filas de la primera matriz (Hasta 3 filas):\n");
        scanf("%d", &filasU);
        while(filasU < 1 || filasU > 3) {
            printf("Número de filas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &filasU);
        }
        printf("Ingrese las columnas de la primera matriz (Hasta 3 columnas):\n");
        scanf("%d", &columnasU);
        while(columnasU < 1 || columnasU > 3) {
            printf("Número de columnas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &columnasU);
        }

        //Asignar dimensiones de la segunda matriz
        filasV = columnasU; // Para multiplicación, filas de la segunda matriz deben ser iguales a columnas de la primera
        printf("Ingrese las columnas de la segunda matriz (Hasta 3 columnas):\n");
        scanf("%d", &columnasV);
        while(columnasV < 1 || columnasV > 3) {
            printf("Número de columnas inválido. Por favor, ingrese un número entre 1 y 3: ");
            scanf("%d", &columnasV);
        }
        
        
        //Declarar matrices
        float matrizU1[filasU][columnasU];
        float matrizV1[filasV][columnasV];
        float matrizResU[filasU][columnasV];

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

        //Multiplicación de matrices
        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                for(int k = 0; k < columnasU; k++) {
                    matrizResU[i][j] += matrizU1[i][k] * matrizV1[k][j];
                }
            }
        }

        printf("Resultado de la multiplicación de matrices:\n");
        for(int i = 0; i < filasV; i++) {
            for(int j = 0; j < columnasV; j++) {
                printf("%.2f ", matrizResU[i][j]);
            }
            printf("\n");
        }
    } else if (opcionMulti == 2) {
        // Lógica para elegir matrices precargadas
        int matrizA, matrizB;

    // Mostrar matrices disponibles
    printf("\nMatrices precargadas:\n");
    printf("1. Matriz 1 (2x2)\n");
    printf("2. Matriz 2 (2x2)\n");
    printf("3. Matriz 3 (2x2)\n");
    printf("4. Matriz 4 (3x3)\n");
    printf("5. Matriz 5 (3x3)\n");

    printf("\nSeleccione la primera matriz: ");
    scanf("%d", &matrizA);

    printf("Seleccione la segunda matriz: ");
    scanf("%d", &matrizB);

    // Caso matrices 2x2
    if(matrizA == 1 && matrizB == 2)
    {
        float resultado[2][2];

        resultado[0][0] = (2*1) + (5*4);
        resultado[0][1] = (2*2) + (5*3);
        resultado[1][0] = (3*1) + (1*4);
        resultado[1][1] = (3*2) + (1*3);

        printf("\nResultado:\n");

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                printf("%.2f ", resultado[i][j]);
            }
            printf("\n");
        }
    }

    // Caso matrices 3x3
    else if(matrizA == 4 && matrizB == 5)
    {
        float resultado[3][3];

        resultado[0][0]=(5*5)+(4*2)+(3*2);
        resultado[0][1]=(5*4)+(4*-1)+(3*1);
        resultado[0][2]=(5*3)+(4*0)+(3*9);

        resultado[1][0]=(2*5)+(1*2)+(0*2);
        resultado[1][1]=(2*4)+(1*-1)+(0*1);
        resultado[1][2]=(2*3)+(1*0)+(0*9);

        resultado[2][0]=(6*5)+(7*2)+(8*2);
        resultado[2][1]=(6*4)+(7*-1)+(8*1);
        resultado[2][2]=(6*3)+(7*0)+(8*9);

        printf("\nResultado:\n");

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("%.2f ", resultado[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nSolo estan implementadas las combinaciones Matriz1 x Matriz2 y Matriz4 x Matriz5.\n");
    }

    }

    preguntarContinuar();
}

//Logica de la determinante de una matriz
void determinanteMatriz(void)
{
    int filasU, columnasU;
    int opcionDet = 0;
    int determinante = 0;
    printf("¿Desea ingresar su propias matriz o elegir una de las matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionDet);
    while(opcionDet != 1 && opcionDet != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionDet);
    }
    
    //Ingresar matrices manualmente
    if(opcionDet == 1) {
        //Ingresar dimensiones de las matrices
        printf("Ingrese la matriz cuadrada hasta 3x3 (2=2x2, 3=3x3):\n");
        scanf("%d", &filasU);
        while(filasU != 2 && filasU != 3) {
            printf("Número inválido. Por favor, ingrese 2 o 3: ");
            scanf("%d", &filasU);
        }

        
        //Ajustar columnas para que sea cuadrada
        columnasU = filasU;
        
        //Declarar matrices
        float matrizU1[filasU][columnasU];

        //Ingresar datos de la matriz
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                printf("Ingrese el elemento [%d][%d] de la matriz: ", i, j);
                scanf("%f", &matrizU1[i][j]);
            }
        }

        printf("\n");

        //Obteniendo el determinante
        if(filasU == 2) {
            determinante = (matrizU1[0][0] * matrizU1[1][1]) - (matrizU1[0][1] * matrizU1[1][0]);
        } else if(filasU == 3) {
            determinante = (matrizU1[0][0] * ((matrizU1[1][1] * matrizU1[2][2]) - (matrizU1[1][2] * matrizU1[2][1]))) -
                           (matrizU1[0][1] * ((matrizU1[1][0] * matrizU1[2][2]) - (matrizU1[1][2] * matrizU1[2][0]))) +
                           (matrizU1[0][2] * ((matrizU1[1][0] * matrizU1[2][1]) - (matrizU1[1][1] * matrizU1[2][0])));
        }

        printf("El determinante de la matriz es: %d\n", determinante);

    } else if (opcionDet == 2) {
        // Logica para elegir matrices precargadas y calcular su determinante
           int opcionMatriz;

    printf("\nMatrices precargadas:\n");
    printf("1. Matriz 1 (2x2)\n");
    printf("2. Matriz 2 (2x2)\n");
    printf("3. Matriz 3 (2x2)\n");
    printf("4. Matriz 4 (3x3)\n");
    printf("5. Matriz 5 (3x3)\n");

    printf("\nSeleccione una matriz: ");
    scanf("%d", &opcionMatriz);

    while(opcionMatriz < 1 || opcionMatriz > 5)
    {
        printf("Opcion invalida. Elija entre 1 y 5: ");
        scanf("%d", &opcionMatriz);
    }

    // Determinantes de matrices 2x2
    if(opcionMatriz == 1)
    {
        determinante = (2*1) - (5*3);
    }
    else if(opcionMatriz == 2)
    {
        determinante = (1*3) - (2*4);
    }
    else if(opcionMatriz == 3)
    {
        determinante = (9*6) - (8*7);
    }

    // Determinantes de matrices 3x3
    else if(opcionMatriz == 4)
    {
        determinante =
        (5*((1*8)-(0*7)))
        - (4*((2*8)-(0*6)))
        + (3*((2*7)-(1*6)));
    }
    else if(opcionMatriz == 5)
    {
        determinante =
        (5*((-1*9)-(0*1)))
        - (4*((2*9)-(0*2)))
        + (3*((2*1)-(-1*2)));
    }

    // Mostrar resultado
    printf("\nEl determinante de la matriz es: %d\n", determinante);

    }

    preguntarContinuar();
    
}

//Logica de la transpuesta de una matriz
void transpuestaMatriz(void)
{
    int filasU, columnasU;
    int opcionTransp = 0;
    
    printf("¿Desea ingresar su propia matriz o elegir una de las matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionTransp);
    while(opcionTransp != 1 && opcionTransp != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionTransp);
    }
    
    //Ingresar matrices manualmente
    if(opcionTransp == 1) {
        //Ingresar dimensiones de las matrices
        printf("Ingrese las filas de la matriz (Hasta 3 filas):\n");
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
                printf("Ingrese el elemento [%d][%d] de la matriz: ", i, j);
                scanf("%f", &matrizU1[i][j]);
            }
        }

        printf("\n");

        //Transpuesta de la matriz
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                matrizResU[j][i] = matrizU1[i][j];
            }
        }

        printf("Resultado de la transpuesta de la matriz:\n");
        for(int i = 0; i < columnasU; i++) {
            for(int j = 0; j < filasU; j++) {
                printf("%.2f ", matrizResU[i][j]);
            }
            printf("\n");
        }

    } else if (opcionTransp == 2) {
        // Lógica para elegir matrices precargadas
    }

    preguntarContinuar();

}

//Logica de la inversa de una matriz
void inversaMatriz(void)
{
    int filasU, columnasU = 0;
    int opcionInv = 0;
    int matrizElegida;
    float matrizU1[3][3] = {0};
    float matrizInversa[3][3] = {0};
    float determinante;
    
    printf("¿Desea ingresar su propia matriz o elegir una de las matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionInv);
    while(opcionInv != 1 && opcionInv != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionInv);
    }
    
    //Ingresar matrices manualmente
    if(opcionInv == 1) {
        //Ingresar dimensiones de las matrices
        printf("Ingrese la matriz cuadrada hasta 3x3 (2=2x2, 3=3x3):\n");
        scanf("%d", &filasU);
        while(filasU != 2 && filasU != 3) {
            printf("Número inválido. Por favor, ingrese 2 o 3: ");
            scanf("%d", &filasU);
        }

        
        //Ajustar columnas para que sea cuadrada
        columnasU = filasU;
        
        //Ingresar datos de la matriz
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                printf("Ingrese el elemento [%d][%d] de la matriz: ", i, j);
                scanf("%f", &matrizU1[i][j]);
            }
        }

        printf("\n");

        
        //Calcular la inversa de la matriz
        if(filasU == 2) {
            determinante = (matrizU1[0][0] * matrizU1[1][1]) -
                           (matrizU1[0][1] * matrizU1[1][0]);

            if(fabsf(determinante) < 0.000001f) {
                printf("Error: la matriz no tiene inversa porque su determinante es cero.\n");
                preguntarContinuar();
                return;
            }

            matrizInversa[0][0] = matrizU1[1][1] / determinante;
            matrizInversa[0][1] = -matrizU1[0][1] / determinante;
            matrizInversa[1][0] = -matrizU1[1][0] / determinante;
            matrizInversa[1][1] = matrizU1[0][0] / determinante;
        } else {
            determinante = matrizU1[0][0] *
                           ((matrizU1[1][1] * matrizU1[2][2]) -
                            (matrizU1[1][2] * matrizU1[2][1])) -
                           matrizU1[0][1] *
                           ((matrizU1[1][0] * matrizU1[2][2]) -
                            (matrizU1[1][2] * matrizU1[2][0])) +
                           matrizU1[0][2] *
                           ((matrizU1[1][0] * matrizU1[2][1]) -
                            (matrizU1[1][1] * matrizU1[2][0]));

            if(fabsf(determinante) < 0.000001f) {
                printf("Error: la matriz no tiene inversa porque su determinante es cero.\n");
                preguntarContinuar();
                return;
            }

            matrizInversa[0][0] = ((matrizU1[1][1] * matrizU1[2][2]) -
                                  (matrizU1[1][2] * matrizU1[2][1])) / determinante;
            matrizInversa[0][1] = ((matrizU1[0][2] * matrizU1[2][1]) -
                                  (matrizU1[0][1] * matrizU1[2][2])) / determinante;
            matrizInversa[0][2] = ((matrizU1[0][1] * matrizU1[1][2]) -
                                  (matrizU1[0][2] * matrizU1[1][1])) / determinante;
            matrizInversa[1][0] = ((matrizU1[1][2] * matrizU1[2][0]) -
                                  (matrizU1[1][0] * matrizU1[2][2])) / determinante;
            matrizInversa[1][1] = ((matrizU1[0][0] * matrizU1[2][2]) -
                                  (matrizU1[0][2] * matrizU1[2][0])) / determinante;
            matrizInversa[1][2] = ((matrizU1[0][2] * matrizU1[1][0]) -
                                  (matrizU1[0][0] * matrizU1[1][2])) / determinante;
            matrizInversa[2][0] = ((matrizU1[1][0] * matrizU1[2][1]) -
                                  (matrizU1[1][1] * matrizU1[2][0])) / determinante;
            matrizInversa[2][1] = ((matrizU1[0][1] * matrizU1[2][0]) -
                                  (matrizU1[0][0] * matrizU1[2][1])) / determinante;
            matrizInversa[2][2] = ((matrizU1[0][0] * matrizU1[1][1]) -
                                  (matrizU1[0][1] * matrizU1[1][0])) / determinante;
        }

    } else if (opcionInv == 2) {
        printf("\nMatrices precargadas:\n");
        printf("1. Matriz 1 (2x2)\n");
        printf("2. Matriz 2 (2x2)\n");
        printf("3. Matriz 3 (2x2)\n");
        printf("4. Matriz 4 (3x3)\n");
        printf("5. Matriz 5 (3x3)\n");
        printf("\nSeleccione la matriz: ");
        scanf("%d", &matrizElegida);

        while(matrizElegida < 1 || matrizElegida > 5) {
            printf("Opcion invalida. Elija entre 1 y 5: ");
            scanf("%d", &matrizElegida);
        }

        if(matrizElegida <= 3) {
            filasU = 2;
            columnasU = 2;
        } else {
            filasU = 3;
            columnasU = 3;
        }

        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                if(matrizElegida == 1)
                    matrizU1[i][j] = matriz1[i][j];
                else if(matrizElegida == 2)
                    matrizU1[i][j] = matriz2[i][j];
                else if(matrizElegida == 3)
                    matrizU1[i][j] = matriz3[i][j];
                else if(matrizElegida == 4)
                    matrizU1[i][j] = matriz4[i][j];
                else
                    matrizU1[i][j] = matriz5[i][j];
            }
        }

        if(filasU == 2) {
            determinante = (matrizU1[0][0] * matrizU1[1][1]) -
                           (matrizU1[0][1] * matrizU1[1][0]);
            if(fabsf(determinante) < 0.000001f) {
                printf("Error: la matriz no tiene inversa porque su determinante es cero.\n");
                preguntarContinuar();
                return;
            }
            matrizInversa[0][0] = matrizU1[1][1] / determinante;
            matrizInversa[0][1] = -matrizU1[0][1] / determinante;
            matrizInversa[1][0] = -matrizU1[1][0] / determinante;
            matrizInversa[1][1] = matrizU1[0][0] / determinante;
        } else {
            determinante = matrizU1[0][0] *
                           ((matrizU1[1][1] * matrizU1[2][2]) -
                            (matrizU1[1][2] * matrizU1[2][1])) -
                           matrizU1[0][1] *
                           ((matrizU1[1][0] * matrizU1[2][2]) -
                            (matrizU1[1][2] * matrizU1[2][0])) +
                           matrizU1[0][2] *
                           ((matrizU1[1][0] * matrizU1[2][1]) -
                            (matrizU1[1][1] * matrizU1[2][0]));
            if(fabsf(determinante) < 0.000001f) {
                printf("Error: la matriz no tiene inversa porque su determinante es cero.\n");
                preguntarContinuar();
                return;
            }
            matrizInversa[0][0] = ((matrizU1[1][1] * matrizU1[2][2]) -
                                  (matrizU1[1][2] * matrizU1[2][1])) / determinante;
            matrizInversa[0][1] = ((matrizU1[0][2] * matrizU1[2][1]) -
                                  (matrizU1[0][1] * matrizU1[2][2])) / determinante;
            matrizInversa[0][2] = ((matrizU1[0][1] * matrizU1[1][2]) -
                                  (matrizU1[0][2] * matrizU1[1][1])) / determinante;
            matrizInversa[1][0] = ((matrizU1[1][2] * matrizU1[2][0]) -
                                  (matrizU1[1][0] * matrizU1[2][2])) / determinante;
            matrizInversa[1][1] = ((matrizU1[0][0] * matrizU1[2][2]) -
                                  (matrizU1[0][2] * matrizU1[2][0])) / determinante;
            matrizInversa[1][2] = ((matrizU1[0][2] * matrizU1[1][0]) -
                                  (matrizU1[0][0] * matrizU1[1][2])) / determinante;
            matrizInversa[2][0] = ((matrizU1[1][0] * matrizU1[2][1]) -
                                  (matrizU1[1][1] * matrizU1[2][0])) / determinante;
            matrizInversa[2][1] = ((matrizU1[0][1] * matrizU1[2][0]) -
                                  (matrizU1[0][0] * matrizU1[2][1])) / determinante;
            matrizInversa[2][2] = ((matrizU1[0][0] * matrizU1[1][1]) -
                                  (matrizU1[0][1] * matrizU1[1][0])) / determinante;
        }
    }

    printf("La matriz inversa es:\n");
    for(int i = 0; i < filasU; i++) {
        for(int j = 0; j < columnasU; j++) {
            printf("%.2f ", matrizInversa[i][j]);
        }
        printf("\n");

    }

    preguntarContinuar();
}

//Logica de la suma de los elementos de una matriz
void sumaElementosMatriz(void)
{   
    int filasU, columnasU;
    int opcionSumaM = 0;
    float resultadoSuma = 0;
    printf("¿Desea ingresar sus propias matrices o elegir matrices precargadas? (1 = Ingresar, 2 = Elegir): ");
    scanf("%d", &opcionSumaM);
    while(opcionSumaM != 1 && opcionSumaM != 2) {
        printf("Opción inválida. Por favor, elija 1 o 2.\n");
        scanf("%d", &opcionSumaM);
    }
    
    //Ingresar matrices manualmente
    if(opcionSumaM == 1) {
        //Ingresar dimensiones de las matrices
        printf("Ingrese las filas de la matriz (Hasta 3 filas):\n");
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

        //Ingresar datos de la matriz
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                printf("Ingrese el elemento [%d][%d] de la matriz: ", i, j);
                scanf("%f", &matrizU1[i][j]);
            }
        }

        printf("\n");

        //Suma de elementos de la matriz
        for(int i = 0; i < filasU; i++) {
            for(int j = 0; j < columnasU; j++) {
                resultadoSuma += matrizU1[i][j];
            }
        }
        printf("Resultado de la suma de elementos de la matriz: %.2f\n", resultadoSuma);

    } else if (opcionSumaM == 2) 
    {
        // Lógica para elegir matrices precargadas

    }

    preguntarContinuar();

}

int main(void)
{
    //Menu de opciones
    int opcion = 0;

    do {
        printf("\nCalculadora de Matrices v1.0\n");
        printf("¿Que operacion desea hacer?\n");
        printf("1. Sumar matrices\n");
        printf("2. Restar matrices\n");
        printf("3. Multiplicar por un escalar\n");
        printf("4. Multiplicar matrices\n");
        printf("5. Determinante de una matriz\n");
        printf("6. Transpuesta de una matriz\n");
        printf("7. Inversa de una matriz\n");
        printf("8. Suma de los elementos de una matriz\n");
        printf("9. Salir\n");

        scanf("%d", &opcion);

        while(opcion < 1 || opcion > 9)
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
                multiplicacionMatrices();
                break;
            case 5:
                printf("Determinante de una matriz\n");
                determinanteMatriz();
                break;
            case 6:
                printf("Transpuesta de una matriz\n");
                transpuestaMatriz();
                break;
            case 7:
                printf("Inversa de una matriz\n");
                inversaMatriz();
                break;
            case 8:
                printf("Suma de los elementos de una matriz\n");
                sumaElementosMatriz();
                break;
            case 9:
                seguir = 2;
                break;
        }
    } while(seguir == 1);

    printf("\n¡Gracias por usar la Calculadora de Matrices v1.0!\n");
    
    return 0;
}