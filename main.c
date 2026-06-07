#include <stdio.h>
#include <string.h>
#include "matematica.h"

// Función 1 de interfaz: Pide los datos al usuario
void ingresarDatosPais(char nombre[], float quintiles[]) {
    printf("\n--- CALCULADORA DE INDICE DE GINI ---\n");
    printf("Ingrese el nombre del pais: ");
    scanf("%s", nombre);
    
    printf("\nIngrese los porcentajes acumulados de los 5 quintiles.\n");
    printf("(Recuerde ingresarlos en formato decimal, ej: 0.05, 0.15, etc.)\n");
    
    for(int i = 0; i < 5; i++) {
        printf("Quintil %d (20%% %d): ", i + 1, (i + 1) * 20);
        scanf("%f", &quintiles[i]);
    }
}

// Función 2 de interfaz: Clasifica el Gini según el PDF
void mostrarDiagnostico(char nombrePais[], float indiceGini) {
    printf("\n========================================\n");
    printf("RESULTADOS PARA: %s\n", nombrePais);
    printf("Indice de Gini calculado: %.4f\n", indiceGini);
    printf("Diagnostico: ");
    
    // Clasificación estricta basada en la tabla del proyecto
    if (indiceGini < 0.30) {
        printf("Muy buena distribucion del ingreso\n");
    } else if (indiceGini >= 0.30 && indiceGini < 0.35) {
        printf("Buena distribucion del ingreso\n");
    } else if (indiceGini >= 0.35 && indiceGini < 0.40) {
        printf("Distribucion regular del ingreso\n");
    } else if (indiceGini >= 0.40 && indiceGini < 0.45) {
        printf("Distribucion desigual del ingreso\n");
    } else if (indiceGini >= 0.45 && indiceGini <= 0.50) {
        printf("Mala distribucion del ingreso\n");
    } else {
        printf("Enorme desigualdad del ingreso\n");
    }
    printf("========================================\n");
}

// El Controlador de Flujo
int main() {
    char opcion;
    char nombrePais[50];
    float quintiles[5];
    
    // Ciclo principal que mantiene el programa vivo
    do {
        // 1. Pedir los datos
        ingresarDatosPais(nombrePais, quintiles);
        
        // 2. Invocar tu motor matemático
        float areaLorenz = calcularIntegralLorenz(quintiles);
        float gini = calcularIndiceGini(areaLorenz);
        
        // 3. Mostrar la salida
        mostrarDiagnostico(nombrePais, gini);
        
        // 4. Preguntar si se repite (Requisito del PDF)
        printf("\n¿Desea evaluar otro pais? (s/n): ");
        scanf(" %c", &opcion); // El espacio antes del %c evita errores de salto de linea en C
        
    } while (opcion == 's' || opcion == 'S');
    
    printf("\nCerrando programa... ¡Hasta luego!\n");
    return 0;
}

// Compilar archivos en terminal: gcc main.c matematica.c -o calculadora_gini.exe
// Ejecutar archivos: .\calculadora_gini.exe 