#include <stdio.h>ªª
//DEFINICIONES GLOBALES
int area(int b, int h);


//MAIN
int main (void){
    int base1 = 5;
    int altura1 = 10;
    // invocar procedimiento de bienvenida 
    bienvenida ();

    int area_rectangulo1 =area(base*altura);
    int perimetro_rectangulo = (2*base1) + (2*base2); 

    return 0;
}
//IMPLEMENTACIÓN DE PROCEDIMIENTOS 
void bienvenida (){
    printf ("Ingrese su nombre");
    char nombre[];
    int n1 = 1;
    int n2 = 100; 
    scanf ("%s", &nombre);
    printf ("Bienvenido %s\n", nombre);
} 

void base (){
    printf ("Ingrese la base del rectangulo");
    int base;
    scanf (%d, &base);
}
// IMPLEMENTACIÓN DE FUNCIONES 
int area(int b, int h){
    int area_rectangulo = b*h;
    return area_fectangulo; 
}