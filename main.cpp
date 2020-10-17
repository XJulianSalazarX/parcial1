#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float *Cdefensivo = NULL, *Cofensivo = NULL, g = -9.8,AreaD=0, pi=3.1516;
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
        //canion defensivo
        Cofensivo[0] = 0;
        Cofensivo[1] = 0;
        Cofensivo[2] = 1000;
        Cofensivo[3] = 45;
        Cofensivo[4] = (g*Cofensivo[2])/(sin(2*Cdefensivo[3]));//
        //canion defensivo
        Cdefensivo[0] = 1000;
        Cdefensivo[1] = 0;
        Cdefensivo[2] = 1000;
        AreaD = pi*pow((1000*0,05),2);
        cout << AreaD << endl;





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
