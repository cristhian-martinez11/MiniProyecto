# KICKBOXING LEGEND – Sistema de gestión de inventario 😎

Programa en C++ para consola que administra el inventario de una tienda de implementos de kickboxing (guantes, vendas, protectores, costales, etc.).

## Datos que administra 📊

Hasta **20 productos**, guardados en arreglos paralelos:

| Dato | Tipo | Límite válido |
|---|---|---|
| Nombre del producto | `string` (una palabra) | – |
| Precio en dólares | `double` | 0.01 a 500 |
| Stock (unidades) | `int` | 0 a 200 |

Una variable `cantidad` controla cuántos productos hay registrados. Al iniciar, el programa carga 10 productos de ejemplo con stock 10.

## Funcionalidades del menú

1. **Registrar producto**: valida precio y stock y respeta el máximo de 20.
2. **Mostrar todos los productos**: lista numerada con precio y stock.
3. **Buscar producto**: búsqueda secuencial por nombre; avisa si no existe.
4. **Reporte general**: valor total del inventario, unidades totales, producto más caro y más barato.# KICKBOXING LEGEND – Sistema de gestión de inventario

Programa en C++ para consola que administra el inventario de una tienda de implementos de kickboxing (guantes, vendas, protectores, costales, etc.).

## Datos que administra

Hasta **20 productos**, guardados en arreglos paralelos:

| Dato | Tipo | Límite válido |
|---|---|---|
| Nombre del producto | `string` (una palabra) | – |
| Precio en dólares | `double` | 0.01 a 500 |
| Stock (unidades) | `int` | 0 a 200 |

Una variable `cantidad` controla cuántos productos hay registrados. Al iniciar, el programa carga 10 productos de ejemplo con stock 10.

## Funcionalidades del menú

1. **Registrar producto**: valida precio y stock y respeta el máximo de 20.
2. **Mostrar todos los productos**: lista numerada con precio y stock.
3. **Buscar producto**: búsqueda secuencial por nombre; avisa si no existe.
4. **Reporte general**: valor total del inventario, unidades totales, producto más caro y más barato.
5. **Alerta de stock bajo** (componente creativo).
6. **Salir**.

El menú se repite hasta elegir la opción 6. Si no hay datos, las opciones 2 a 5 muestran un mensaje claro.

## Componente creativo: alerta de stock bajo

Recorre el inventario y detecta los productos con **5 unidades o menos**. Para cada uno indica cuántas unidades hay que reponer para llegar a un stock ideal de 10, y al final muestra el total de productos en alerta y de unidades a reponer.

## Compilar y ejecutar

Requiere un compilador de C++ (por ejemplo, g++).

```bash
g++ main.cpp -o kickboxing
./kickboxing        # en Windows: kickboxing.exe
```

## Autor

Cristhian Martinez Vargas
5. **Alerta de stock bajo** (componente creativo).
6. **Salir**.

El menú se repite hasta elegir la opción 6. Si no hay datos, las opciones 2 a 5 muestran un mensaje claro.

## Componente creativo: alerta de stock bajo

Recorre el inventario y detecta los productos con **5 unidades o menos**. Para cada uno indica cuántas unidades hay que reponer para llegar a un stock ideal de 10, y al final muestra el total de productos en alerta y de unidades a reponer.

## Compilar y ejecutar

Requiere un compilador de C++ (por ejemplo, g++).

```bash
g++ main.cpp -o kickboxing
./kickboxing        # en Windows: kickboxing.exe
```

## Autor y Fecha

Cristhian Martinez Vargas
25 de Octubre del 2026

