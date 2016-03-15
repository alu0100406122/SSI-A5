#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void desplazamiento(vector<bool> &x, bool res_xor){
    bool i;
    for (int i=0; i<x.size(); i++){
        x[i] = x[i + 1];
        if (i==x.size() - 1){
            x[i] = res_xor;
        }
    }
}


bool mayoria(vector<bool> a_, vector<bool> b_, vector<bool> c_){
    int contador1=0;
    int contador2=0;
    int i=0;
    vector<bool> aux;
    aux.resize(3);
    //Introducimos en el vector auxiliar el valor de la posición de reloj.
    aux[0] = a_[8];
    aux[1] = a_[10];
    aux[2] = a_[10];
    
    while (i < aux.size()){
        if (aux[i] == 1){
            contador1++;
        }
        else{
            contador2++;
        }
        i++;
    }
    
    if (contador1 > contador2){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimir(vector<bool> x, char nombre){
    cout << "Vector " << nombre << ": " << endl;

    for (int i=0; i<x.size(); i++){
        cout << x[i];
    }
    cout << endl;
}

//Función para rellenar el vector con el binario (string)
vector<bool> rellenado(string semilla){
    vector<bool> x;
    //cout << "Semilla: " << semilla << endl;
    x.resize(semilla.size());
    int i=0;
    while(i <= semilla.size()-1){
        x[i] = semilla[i];   
        if((int)semilla[i] == 48){
            x[i] = 0;
        }
        else{
            if((int)semilla[i] == 49){
                x[i] = 1;
            }
        }
        i++;
    }
    cout << endl;
    return x;
}


int main(){
    
    vector<bool> a;
    vector<bool> b;
    vector<bool> c;
    
    vector<bool> k;
    a.resize(19);
    b.resize(22);
    c.resize(23);
    k.resize(64);
    bool resultado;
    int indice_z=0;
    cout << "-----------------------------------------------" << endl;
    cout << "                  CIFRADO A5                   " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    //Rellenamos los vectores con los semillaes del enunciado.
    string a_semilla = "0000000000000000000";
    a = rellenado(a_semilla);
    imprimir(a, 'a');
    string b_semilla = "0000000000000000000000";
    b = rellenado(b_semilla);
    imprimir(b, 'b');
    string c_semilla = "00000000000000000000000";
    c = rellenado(c_semilla);
    imprimir(c, 'c');
    
    string k_semilla = "1000101100010001001010110010001111001101011110000111101100111101";
    k = rellenado(k_semilla);
    imprimir(k, 'k');

    //Xor entre los elementos que indica el polinomio.
    // f(x1)= x19 + x18 + x17 + x14 + 1
    // f(x2)= x22 + x21 + 1
    // f(x3)= x23 + x22 + x21 + x8 +1
    int numero = 0;
    int cont_k = 0;
    cout << endl;
    cout << "Introduzca el número de iteraciones: " << endl;
    cin >> numero;
    
    while(numero > 0){
        cin.get();
        bool xor_a, xor_b, xor_c;
        cout << "-----------------------------------------------" << endl;
        cout << "---------------- Operación XOR ----------------" << endl;
        cout << endl;
        cout << "a[19]: " << a[0] << ", a[18]: " << a[1] << ", a[17]: " << a[2] << ", a[14]: " << a[5] << ", k[i]: " << k[cont_k] << endl;
        xor_a = a[0] ^ a[1] ^ a[2] ^ a[5] ^ k[cont_k];
        cout << endl;
        cout << "XOR vector a: " << xor_a << endl;
        cout << endl;
        cout << "b[22]: " << b[0] << ", b[21]: " << b[1] << ", k[i]: " << k[cont_k] << endl;
        xor_b = b[0] ^ b[1] ^ k[cont_k];
        cout << endl;
        cout << "XOR vector b: " << xor_b << endl;
        cout << endl;
        cout << "c[23]: " << c[0] << ", c[22]: " << c[1] << ", c[21]: " << c[2] << ", c[8]: " << c[15] << ", k[i]: " << k[cont_k] << endl;
        xor_c = c[0] ^ c[1] ^ c[2] ^ c[15] ^ k[cont_k];
        cout << endl;
        cout << "XOR vector c: " << xor_c << endl;
        cout << endl;


        //Desplazamiento del vector.

        desplazamiento(a, xor_a);
        desplazamiento(b, xor_b);
        desplazamiento(c, xor_c);
        
        //Imprimo los vectores después de desplazar.
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "--------------- Desplazamiento  ---------------" << endl;
        imprimir(a, 'a');
        imprimir(b, 'b');
        imprimir(c, 'c');


        cont_k++;
        numero--;
        cout << endl;
        cout << "Siguiente iteración... " << endl;   
    }
    cout << endl;
    
    return 0;
}