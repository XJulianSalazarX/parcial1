#include <iostream>
#include <math.h>

using namespace std;
float TiempoDeImpactoBalaO(float *,float *);
float pi=3.1516, g=-9.81;

int main()
{
    float *Cdefensivo = NULL, *Cofensivo = NULL, tiempo=0;;
    Cofensivo = new float[5];// canion ofensivo
    Cdefensivo = new float[5];// canion defensivo
    int opc = 0;
    cout << "Seliccione:" << endl;
    cout << "1. Probar caso 1." << endl;
    cout << "2. Probar caso 2." << endl;
    cout << "3. Probar caso 3." << endl;
    cout << "4. Probar caso 4." << endl;
    cout << "Seleccione 0. salir." << endl;
    cout << "Eliga una opcion: ";cin >> opc;

    switch (opc) {
    case 1:{

    };
        break;
    case 2:{

    };
        break;
    case 3:{

    };
        break;
    case 4:{

    }
        break;
    default:
        cout << "Opcion no valida." << endl;

    }


    delete [] Cofensivo;
    delete [] Cdefensivo;
    return 0;
}


