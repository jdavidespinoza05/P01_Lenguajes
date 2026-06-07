#include <stdio.h>
#include "matematica.h"

// 1. Calcula el área de un trapecio entre dos puntos
float calcularAreaTrapecio(float x1, float y1, float x2, float y2) {
    float base = x2 - x1;
    float area = base * ((y1 + y2) / 2.0);
    return area;
}

// 2. Calcula el área total bajo la curva de Lorenz
float calcularIntegralLorenz(float quintiles[]) {
    float areaTotal = 0.0;
    
    // Punto de partida de la curva: origen (0.0, 0.0)
    float x_anterior = 0.0;
    float y_anterior = 0.0;
    
    // Recorremos los 5 quintiles
    for (int i = 0; i < 5; i++) {
        // En el eje X, cada quintil representa un avance del 20% (0.2)
        float x_actual = x_anterior + 0.2;
        
        // En el eje Y, la altura nos la da el arreglo en la posición actual
        float y_actual = quintiles[i];
        
        // Llamamos a la función del trapecio con las 4 coordenadas y sumamos el área
        areaTotal += calcularAreaTrapecio(x_anterior, y_anterior, x_actual, y_actual);
        
        // El punto actual se convierte en el "anterior" para la siguiente vuelta
        x_anterior = x_actual;
        y_anterior = y_actual;
    }
    
    return areaTotal;
}

// 3. Calcula la fórmula final de Gini
float calcularIndiceGini(float valorIntegral) {
    // La fórmula del PDF es: g = 1 - 2 * integral
    float gini = 1.0 - (2.0 * valorIntegral);
    return gini;
}