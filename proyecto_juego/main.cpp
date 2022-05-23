#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"
#include "windows.h"

using namespace std;
bool SonidoFondo()
{
   PlaySound(TEXT("musicaFondo.wav"), NULL, SND_LOOP);
}
int main()
{
    /* primer caracter = color de fondo
       Segundo caracter = color de letra
    */
    system("color 6F");
    /*
    0 = negro
    1 = azul
    2 = verde
    3 = aguamarina
    4 = rojo
    5 = purpura
    6 = amarillo
    7 = blanco
    8 = Azul Claro
    A = Verde Claro
    B = Aguamarina Claro
    C = Rojo claro
    D = purpura claro
    E = Amarillo Claro
    F = Blanco Brillante */

    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022
    gamemap map;
    player hero;
    map.drawPortada();



    //map.draw();
    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir "<< endl;
      hero.callInput();


      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");

        map.draw();

      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();

      }
      //map.draw();

    }

    return 0;

}
