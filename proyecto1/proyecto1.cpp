/*
 KICKBOXING LEGEND - Sistema de gestion de inventario
Autor: Cristhian Martinez Vargas
Mini-Proyecto Integrador C++ (consola)
*/

#include <iostream>
#include <string>
using namespace std;

// CONSTANTES 
const int MAX_PRODUCTOS = 20;      // limite de registros
const double PRECIO_MIN = 0.01;    // limites de validacion
const double PRECIO_MAX = 500.0;
const int STOCK_MIN = 0;
const int STOCK_MAX = 200;
const int STOCK_BAJO = 5;          // 5 unidades o menos = alerta
const int STOCK_IDEAL = 10;        // stock al que se quiere reponer

// true  = el programa inicia con 10 productos de ejemplo
// false = el programa inicia vacio (para probar el caso "sin registros")
const bool CARGAR_INICIALES = true;

// FUNCIONES DE LECTURA CON VALIDACION 

// Pide un entero y repite hasta que este entre minimo y maximo
int leerEntero(string mensaje, int minimo, int maximo) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {                 // el usuario escribio letras
            cin.clear();                  // limpia el error
            cin.ignore(10000, '\n');      // descarta lo escrito
            cout << "  Error: debes escribir un numero entero.\n";
        } else if (valor < minimo || valor > maximo) {
            cout << "  Error: el valor debe estar entre " << minimo
                 << " y " << maximo << ".\n";
        } else {
            return valor;
        }
    }
}

// Pide un decimal y repite hasta que este entre minimo y maximo
double leerDecimal(string mensaje, double minimo, double maximo) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "  Error: debes escribir un numero.\n";
        } else if (valor < minimo || valor > maximo) {
            cout << "  Error: el valor debe estar entre " << minimo
                 << " y " << maximo << ".\n";
        } else {
            return valor;
        }
    }
}

// FUNCIONES DEL PROGRAMA 

void mostrarMenu() {
    cout << "\n==============================\n";
    cout << "     KICKBOXING LEGEND\n";
    cout << "==============================\n";
    cout << "1. Registrar producto\n";
    cout << "2. Mostrar todos los productos\n";
    cout << "3. Buscar producto\n";
    cout << "4. Reporte general\n";
    cout << "5. Alerta de stock bajo\n";
    cout << "6. Salir\n";
    cout << "------------------------------\n";
}

// Carga 10 productos de ejemplo, cada uno con stock 10. Devuelve cuantos cargo.
int cargarProductosIniciales(string nombres[], double precios[], int stocks[]) {
    string n[10] = {"Guantes", "Inguinal", "Vendas", "Bucal", "Rodilleras",
                    "Canilleras", "Coderas", "Cabezal", "Costal", "Manoplas"};
    double p[10] = {45.00, 25.00, 8.00, 6.50, 22.00,
                    35.00, 20.00, 55.00, 120.00, 40.00};
    for (int i = 0; i < 10; i++) {
        nombres[i] = n[i];
        precios[i] = p[i];
        stocks[i] = 10;
    }
    return 10;
}

// Registra un producto nuevo y devuelve la nueva cantidad de registros
int registrarProducto(string nombres[], double precios[], int stocks[], int cantidad) {
    if (cantidad >= MAX_PRODUCTOS) {
        cout << "\nEl inventario esta lleno (maximo " << MAX_PRODUCTOS << " productos).\n";
        return cantidad;
    }

    cout << "\n--- Registrar producto ---\n";
    cout << "Nombre (una sola palabra, sin espacios): ";
    cin >> nombres[cantidad];
    precios[cantidad] = leerDecimal("Precio en dolares (0.01 a 500): ", PRECIO_MIN, PRECIO_MAX);
    stocks[cantidad] = leerEntero("Stock disponible (0 a 200): ", STOCK_MIN, STOCK_MAX);

    cout << "Producto registrado correctamente.\n";
    return cantidad + 1;
}

// Muestra todos los productos en forma de lista
void mostrarProductos(string nombres[], double precios[], int stocks[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nTodavia no hay productos registrados.\n";
        return;
    }

    cout << "\n--- Lista de productos ---\n";
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << nombres[i]
             << " | Precio: $" << precios[i]
             << " | Stock: " << stocks[i] << "\n";
    }
}

// Busqueda secuencial por nombre
void buscarProducto(string nombres[], double precios[], int stocks[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nTodavia no hay productos registrados.\n";
        return;
    }

    string buscado;
    cout << "\nNombre del producto a buscar: ";
    cin >> buscado;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == buscado) {
            cout << "\nProducto encontrado:\n";
            cout << "  Nombre: " << nombres[i] << "\n";
            cout << "  Precio: $" << precios[i] << "\n";
            cout << "  Stock:  " << stocks[i] << "\n";
            encontrado = true;
            break;  // ya lo encontramos, dejamos de buscar
        }
    }

    if (!encontrado) {
        cout << "\nNo existe ningun producto llamado \"" << buscado << "\".\n";
    }
}

// Reporte: valor total, unidades totales, producto mas caro y mas barato
void reporteGeneral(string nombres[], double precios[], int stocks[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nTodavia no hay productos registrados.\n";
        return;
    }

    double valorTotal = 0;
    int unidadesTotales = 0;
    int posMasCaro = 0;
    int posMasBarato = 0;

    for (int i = 0; i < cantidad; i++) {
        valorTotal += precios[i] * stocks[i];   // precio x stock
        unidadesTotales += stocks[i];
        if (precios[i] > precios[posMasCaro]) {
            posMasCaro = i;
        }
        if (precios[i] < precios[posMasBarato]) {
            posMasBarato = i;
        }
    }

    cout << "\n--- Reporte general ---\n";
    cout << "Productos registrados: " << cantidad << "\n";
    cout << "Valor total del inventario: $" << valorTotal << "\n";
    cout << "Unidades totales en stock: " << unidadesTotales << "\n";
    cout << "Producto mas caro: " << nombres[posMasCaro]
         << " ($" << precios[posMasCaro] << ")\n";
    cout << "Producto mas barato: " << nombres[posMasBarato]
         << " ($" << precios[posMasBarato] << ")\n";
}

// COMPONENTE CREATIVO: alerta de stock bajo + cuantas unidades reponer
void alertaStockBajo(string nombres[], int stocks[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nTodavia no hay productos registrados.\n";
        return;
    }

    cout << "\n--- Alerta de stock bajo (" << STOCK_BAJO << " unidades o menos) ---\n";
    int productosEnAlerta = 0;
    int totalAReponer = 0;

    for (int i = 0; i < cantidad; i++) {
        if (stocks[i] <= STOCK_BAJO) {
            int reponer = STOCK_IDEAL - stocks[i];   // para llegar al stock ideal
            cout << "! " << nombres[i] << " -> quedan " << stocks[i]
                 << ". Reponer " << reponer << " unidades.\n";
            productosEnAlerta++;
            totalAReponer += reponer;
        }
    }

    if (productosEnAlerta == 0) {
        cout << "Todo en orden: ningun producto tiene stock bajo.\n";
    } else {
        cout << "\nProductos en alerta: " << productosEnAlerta << "\n";
        cout << "Total de unidades a reponer: " << totalAReponer << "\n";
    }
}

// ---------------- PROGRAMA PRINCIPAL ----------------

int main() {
    // Arreglos paralelos: la misma posicion = el mismo producto
    string nombres[MAX_PRODUCTOS];
    double precios[MAX_PRODUCTOS];
    int stocks[MAX_PRODUCTOS];
    int cantidad = 0;   // cuantos productos hay guardados

    if (CARGAR_INICIALES) {
        cantidad = cargarProductosIniciales(nombres, precios, stocks);
    }

    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Elige una opcion (1-6): ", 1, 6);

        switch (opcion) {
            case 1:
                cantidad = registrarProducto(nombres, precios, stocks, cantidad);
                break;
            case 2:
                mostrarProductos(nombres, precios, stocks, cantidad);
                break;
            case 3:
                buscarProducto(nombres, precios, stocks, cantidad);
                break;
            case 4:
                reporteGeneral(nombres, precios, stocks, cantidad);
                break;
            case 5:
                alertaStockBajo(nombres, stocks, cantidad);
                break;
            case 6:
                cout << "\nGracias por usar KICKBOXING LEGEND. Hasta pronto!\n";
                break;
        }
    } while (opcion != 6);

    return 0;
}