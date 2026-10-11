#include <stdio.h>
#include <string.h>

int main() {
    // Variables definidas para el producto
    char nombres[10][20];
    float precios[10];
    int cantidades[10];          
    // Variables para el menú y cálculos
    int caso, contP = 0;
    int i;
    float total, promedio, max, min;
    int posMax, posMin;
    char busqueda[20];
    int encontrado;

    do {
        // Opciones del menú
        printf("\nSeleccione una opcion:\n");
        printf("0. Salir\n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular valor total del inventario\n");
        printf("4. Producto mas caro y mas barato \n");
        printf("5. Precio promedio \n");
        printf("6. Buscar producto por nombre\n");
        printf(">> ");
        scanf("%d", &caso);

        switch (caso)
        {
        // Registro de productos
        case 1:
            if (contP < 10) {
                printf("Ingrese el nombre del producto: ");
                scanf("%s", nombres[contP]);
                printf("Ingrese el precio unitario: ");
                scanf("%f", &precios[contP]);
                printf("Ingrese la cantidad en inventario: ");
                scanf("%d", &cantidades[contP]);
                contP++;
                printf("Producto ingresado correctamente.\n");
            } else {
                printf("No se pueden ingresar mas productos (maximo 10).\n");
            }
            break;
        // Mostrar inventario
        case 2:
            if (contP == 0) {
                printf("No hay productos registrados.\n");
            } else {
                printf("\n#\tNombre\t\tPrecio\tCantidad\tValor Total\n");
                for (i = 0; i < contP; i++) {
                    printf("%d\t%s\t\t%.2f\t%d\t\t%.2f\n", 
                           i, nombres[i], precios[i], cantidades[i], 
                           precios[i] * cantidades[i]);
                }
            }
            break;
        // Calcular valor total del inventario
        case 3:
            if (contP == 0) {
                printf("No hay productos registrados.\n");
            } else {
                total = 0;
                for (i = 0; i < contP; i++) {
                    total = total + (precios[i] * cantidades[i]);
                }
                printf("Valor total del inventario: %.2f\n", total);
            }
            break;
        // Producto más caro y más barato
        case 4:
            if (contP == 0) {
                printf("No hay productos registrados.\n");
            } else {
                max = precios[0];
                min = precios[0];
                posMax = 0;
                posMin = 0;

                for (i = 1; i < contP; i++) {
                    if (precios[i] > max) {
                        max = precios[i];
                        posMax = i;
                    }
                    if (precios[i] < min) {
                        min = precios[i];
                        posMin = i;
                    }
                }

                printf("Producto mas caro: %s (%.2f) - Cantidad: %d\n", nombres[posMax], max, cantidades[posMax]);
                printf("Producto mas barato: %s (%.2f) - Cantidad: %d\n", nombres[posMin], min, cantidades[posMin]);
            }
            break;
        // Calcular precio promedio
        case 5:
            if (contP == 0) {
                printf("No hay productos registrados.\n");
            } else {
                total = 0;
                for (i = 0; i < contP; i++) {
                    total = total + precios[i];
                }
                promedio = total / contP;
                printf("Precio promedio unitario: %.2f\n", promedio);
            }
            break;
        // Buscar producto por nombre
        case 6:
            if (contP == 0) {
                printf("No hay productos registrados.\n");
            } else {
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", busqueda);

                encontrado = 0;
                for (i = 0; i < contP; i++) {
                    if (strcmp(nombres[i], busqueda) == 0) {
                        printf("\nProducto encontrado:\n");
                        printf("Nombre: %s\n", nombres[i]);
                        printf("Precio unitario: %.2f\n", precios[i]);
                        printf("Cantidad: %d\n", cantidades[i]);
                        printf("Valor total: %.2f\n", precios[i] * cantidades[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("El producto no se encuentra en el inventario.\n");
                }
            }
            break;
        // Salida
        case 0:
            return 0;
        
        default:
            printf("No existe la opcion\n");
            break;
        }

    } while (caso != 0);
    return 0;
}