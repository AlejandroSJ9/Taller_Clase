#include <iostream>
#include <string.h>
#include "iomanip"
using namespace std;

void memoria(string a){
    string *apunt = &a;
    cout << &apunt;
}
int contarVocales(string a){
    int vocales = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' ||
            a[i] == 'o' || a[i] == 'u' || a[i] == 'A' ||
            a[i] == 'E' || a[i] == 'I' || a[i] == 'O' ||
            a[i] == 'U')        {
            vocales++;
        }
    }
    return vocales;
}
void buscarLetra(string a, char buscar){
    string letterFounded;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == buscar){
            letterFounded = a[i];
            break;
        }
    }
    memoria(letterFounded);
}
bool verificarGanador(char tablero[3][3], char jugador){
    bool ganador;
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            if(tablero[0][0]==jugador && tablero[0][1]==jugador && tablero[0][2]==jugador){
                ganador = true;
            }else if(tablero[1][0]==jugador && tablero[1][1]==jugador && tablero[1][2]==jugador){
                ganador = true;
            }else if(tablero[2][0]==jugador && tablero[2][1]==jugador && tablero[2][2]==jugador){
                ganador = true;
            }else if(tablero[0][0]==jugador && tablero[1][0]==jugador && tablero[2][0]==jugador){
                ganador = true;
            }
            else if(tablero[0][1]==jugador && tablero[1][1]==jugador && tablero[2][1]==jugador){
                ganador = true;
            }else if(tablero[0][2]==jugador && tablero[1][2]==jugador && tablero[2][2]==jugador){
                ganador = true;
            }else if(tablero[0][0]==jugador && tablero[1][1]==jugador && tablero[2][2]==jugador){
                ganador = true;
            }else if(tablero[2][0]==jugador && tablero[1][1]==jugador && tablero[0][2]==jugador){
                ganador = true;
            }else{
                ganador = false;
            }
        }
    }
    return ganador;
}
void imprimirMatriz(char tablero[3][3]){
    for (int x = 0; x < 3; x++){
        cout << endl;
        for (int y = 0; y < 3; y++){
            cout << setw(3) << tablero[x][y];
        }
    }
}
int main(){
    char tablero[3][3];
    string palabra;
    char letra;
    int eleccion;
    int contador=0;
    char jugador1 = 'x';
    char jugador2 = 'o';
    int fila,columna;
    do{
        cout << "\n-----Menu-----\n"
             << "1.Ejercicio 1\n"
             << "2.Ejercicio 2\n"
             << "3.Ejercicio 3\n"
             << "0.Salir\n";
        cin >> eleccion;
        switch (eleccion){
        case 1:
            cout << "Ingresa una palabra: \n";
            cin.ignore();
            getline(cin, palabra);
            cout << contarVocales(palabra) << endl;
            memoria(palabra);
            break;
        case 2:
            cout << "Ingresa una palabra: \n";
            cin.ignore();
            getline(cin, palabra);
            cout << "Que letra vas a buscar: ";
            cin >> letra;
            buscarLetra(palabra, letra);
            break;
        case 3:
            for (int x = 0; x < 3; x++){
                for (int y = 0; y < 3; y++){
                    tablero[x][y] = '-';
                    cout << setw(3) << tablero[x][y];
                }
                cout << endl;
            }
            
            while (contador<9){
                cout << "\nJugador 1 ingresa la fila y la columna :\n";
                cin >> fila; cin >> columna;
                tablero[fila-1][columna-1]=jugador1;
                if(verificarGanador(tablero,jugador1)){
                    cout << "\n---Gana Jugador 1---\n";
                    imprimirMatriz(tablero);
                    break;
                }
                imprimirMatriz(tablero);

                cout << "\nJugador 2 ingresa la fila y la columna :\n";
                cin >> fila; cin >> columna;
                tablero[fila-1][columna-1]=jugador2;
                if(verificarGanador(tablero,jugador2)){
                    cout << "\n---Gana Jugador 2---\n";
                    imprimirMatriz(tablero);
                    break;
                }
                imprimirMatriz(tablero);
                contador++;
            }
            break;
        default:
            cout << "Opción inválida";
        }
    } while (eleccion != 0);
    
    return 0;
}