#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <term.h>

void red (){
  printf("\033[0;31m");
}
void yellow (){
  printf("\033[0;33m");
}
void green (){
  printf ("\033[0;32m");
}
void blue (){
  printf ("\033[0;34m");
}
void reset (){
  printf ("\033[0m");
}

char nombre [15];
int main(void) {
  int opcion_usuario;
  srand (time(NULL));
  blue();
  printf("¡BIENVENIDO AL MENCOS HANGMAN!\n\n");
  
  while (1){
  menu_principal:
  //Colores
  red();
  printf("MENÚ PRINCIPAL\n");
  reset();
  printf("--------------------------------------\n");
  red();
  printf("1.Jugar\n");
  blue();
  printf("2.Ver Instrucciones\n");
  red(); 
  printf("3.Acerca de los creadores\n"); 
  blue();
  printf("4.Salir\n");
  reset();
  printf("--------------------------------------\n");
  green();
  printf("Escoja una opción: \n"); 
  scanf("%d", &opcion_usuario); 

  //Juego
  if (opcion_usuario == 1){

    juego:
    reset(); 
    printf("¿Cual es tu nombre?\n");
    scanf("%s", nombre);
    yellow();
    printf("\nBIENVENIDO %s!\n Comenzaremos el juego!\n\nTendras 10 oportunidades para descubrir la palabra oculta\n", nombre);
    

     srand (time(NULL));

      char palabrasHangman[][65] = { 
        "programacion",
        "computadora",
        "computacion",
        "laboratorio",
        "codigo",
        "ingeniero",
        "sistemas",
        "binario",
      };

      int palabrasRandom = rand() %9;
      int Vidas = 11;
      int intentosCorrectos = 0;
      int intentosAnterioresCorrectos = 0;
      int lengthPalabra = strlen(palabrasHangman[palabrasRandom]);
      int letraAdivinada[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
      int salida = 0;
      int Loop = 0;
      char adivinar[16];
      char caracterAdivinado;
      int salir; 


    //Loop del Juego
      while ( intentosCorrectos < lengthPalabra){
          
          reset(); 
          printf("---------------------------------------------------------\n");
          printf("Jugador: %s\n", nombre); 
          printf("Vidas: %d\n", Vidas);
          printf("Correctas:%d\n", intentosCorrectos);
          printf("---------------------------------------------------------\n");
          printf("\n");
          yellow(); 
          printf("La palabra que debes adivinar es:\n ");

        for ( Loop = 0; Loop < lengthPalabra; Loop++){

          if (letraAdivinada[Loop] == 1){
            printf("%c",palabrasHangman[palabrasRandom][Loop]);
          }
          else {
            printf("_ ");  
          }
        }

        printf("\n");
        printf("\nIngrese una letra para adivinar la palabra: \n");
        fgets(adivinar, 16, stdin);

        if (strncmp(adivinar, "salir", 5) == 0){
          salir = 1;
          break; 
        } 
        
        caracterAdivinado = adivinar[0];
        intentosAnterioresCorrectos = intentosCorrectos;


        for ( Loop = 0; Loop < lengthPalabra; Loop++){

          if (letraAdivinada[Loop] == 1){
            continue;
          }

          if ( caracterAdivinado == palabrasHangman[palabrasRandom][Loop]){
            letraAdivinada[Loop] = 1;
            intentosCorrectos++; 
          }
        }

        if(intentosAnterioresCorrectos == intentosCorrectos){
          Vidas--;
          red();
          printf("----------------------------------\n"); 
          printf("La palabra no contiene esa letra, intenta de nuevo\n\n");
          if(Vidas==0){
            reset();
            printf("Lo siento, perdiste todas tus vidas \n");
            break;
          }
        }

        else {
          green();
          printf("Adivinaste una letra, sigue así!!!\n");
          printf("----------------------------------\n"); 
        }

      }

      if (salida == 1){

        printf("Sesión terminada\n");
      }
     else if (Vidas == 0 ){
       printf("\n");
       printf("\n");
       printf("\n");
       red();
       printf("Te has quedado sin oportunidades! La palabra era:  %s \n",
       palabrasHangman[palabrasRandom]);
       reset();
     }
     else {
       int inicio;
       printf("\n");
       printf("\n");
       printf("Felicidades, has adivinado la palabra! La palabra es:  %s \n", palabrasHangman[palabrasRandom]);
      printf("si quieres volver a jugar presiona 1 sino presiona 0\n");
      scanf("%d", &inicio); 
      if (inicio == 1){
        goto juego; 
      } else{
        goto salir; 
      }
     }
  
     printf ("Gracias por haber jugado! Esperamos que te hayas divertido. %s!! \n", nombre);
     break;

  }
  //Instrucciones
   else if (opcion_usuario == 2) { 
    printf("Es un juego simple, yo escogeré una palabra cualquiera y tienes que adivinarla letra por letra.\t\nTendrás 10 intentos para hacerlo.\n");
    printf("\n");  
    goto menu_principal; 
  } 

  //About 
  else if(opcion_usuario == 3){
    printf("Este juego fue creado por dos estudiantes de primer año de Computer Science de la Universidad Francisco Marroquín, Esteban Samayoa y  Nickolas Nolte.\n Si desean contactarnos nuestros correos son:\n estebansamayoa@ufm.edu\n nickolasnolte@ufm.edu\n");
    printf("\n"); 
    goto menu_principal;

  }
   
  else if(opcion_usuario == 4){
    salir: 
    blue(); 
    printf("Esperamos que vuelvas pronto!\n");    
    exit(0);
  }
  else if (opcion_usuario == 5){
    printf("Numero no es valido\n");
  }
   return 0;
  }

  } 