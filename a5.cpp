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
    vector<bool> z;
    a.resize(19);
    b.resize(22);
    c.resize(23);
    bool resultado;
    int indice_z=0;
    cout << "-----------------------------------------------" << endl;
    cout << "                  CIFRADO A5                   " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    //Rellenamos los vectores con los semillaes del enunciado.
    string a_semilla = "1001000100011010001";
    a = rellenado(a_semilla);
    imprimir(a, 'a');
    string b_semilla = "0101100111100010011010";
    b = rellenado(b_semilla);
    imprimir(b, 'b');
    string c_semilla = "10111100110111100001111";
    c = rellenado(c_semilla);
    imprimir(c, 'c');

    //Xor entre los elementos que indica el polinomio.
    // f(x1)= x19 + x18 + x17 + x14 + 1
    // f(x2)= x22 + x21 + 1
    // f(x3)= x23 + x22 + x21 + x8 +1
    int numero;
    cout << endl;
    cout << "Introduzca el número de iteraciones: " << endl;
    cin >> numero;
    
    while(numero > 0){
        cin.get();
        bool xor_a, xor_b, xor_c;
        cout << "-----------------------------------------------" << endl;
        cout << "---------------- Operación XOR ----------------" << endl;
        cout << endl;
        cout << "a[19]: " << a[0] << ", a[18]: " << a[1] << ", a[17]: " << a[2] << ", a[14]: " << a[5] << endl;
        xor_a = a[0] ^ a[1] ^ a[2] ^ a[5];
        cout << endl;
        cout << "XOR vector a: " << xor_a << endl;
        cout << endl;
        cout << "b[22]: " << b[0] << ", b[21]: " << b[1] << endl;
        xor_b = b[0] ^ b[1];
        cout << endl;
        cout << "XOR vector b: " << xor_b << endl;
        cout << endl;
        cout << "c[23]: " << c[0] << ", c[22]: " << c[1] << ", c[21]: " << c[2] << ", c[8]: " << c[15] << endl;
        xor_c = c[0] ^ c[1] ^ c[2] ^ c[15];
        cout << endl;
        cout << "XOR vector c: " << xor_c << endl;
        cout << endl;
        //Función mayoría (con el elemento en la posición de reloj).
        
        bool mayor = mayoria(a, b, c);
        cout << "-----------------------------------------------" << endl;
        cout << "--------------- Función Mayoría ---------------" << endl;
        cout << endl;
        cout << "a[8]: " << a[10] << ", b[10]: " << b[11] << ", c[10]: " << c[12] << endl;
        cout << endl;
        cout << "Mayoría: " << mayor << endl;
        
        
        // z(t)= a(t) + b(t) + c(t)

        z.resize(z.size()+ 1);
        resultado = (a[0] ^ b[0] ^ c[0]);
        z[indice_z]= resultado;

        //Desplazamiento del vector.

        if(mayor == a[10]){
            desplazamiento(a, xor_a);
        } 
        if(mayor == b[11]){
            desplazamiento(b, xor_b);
        }
        if(mayor == c[12]){
            desplazamiento(c, xor_c);
        } 
        
        //Imprimo los vectores después de desplazar.
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "--------------- Desplazamiento  ---------------" << endl;
        imprimir(a, 'a');
        imprimir(b, 'b');
        imprimir(c, 'c');

        cout << endl;
        cout << "z(t): ";
        for (int i=0; i<z.size();i++){
            cout << z[i];
        }
        cout << endl;


        indice_z++;
        numero--;
        cout << endl;
        cout << "Siguiente iteración... " << endl;   
    }
    cout << endl;
    
    return 0;
}