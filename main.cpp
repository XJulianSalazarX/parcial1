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
        //canion defensivo
        Cofensivo[0] = 0;//posicion en x
        Cofensivo[1] = 0;//posicion en y
        Cofensivo[2] = 100;//distancia al canion defensivo
        Cofensivo[3] = 45;//angulo de disparo
        Cofensivo[4] = (g*Cofensivo[2])/(sin(2*Cdefensivo[3]));//velocidad inicial
        //canion defensivo
        Cdefensivo[0] = 100;//posicion en x
        Cdefensivo[1] = 0;//posicion en y
        Cdefensivo[2] = 100;//distancia al canion defensivo;
        //AreaBalaO = pi*(pow((100*0.05),2));
        tiempo = TiempoDeImpactoBalaO(Cofensivo,Cdefensivo);
        cout << "Posicion canion ofensivo: ("<<Cofensivo[0]<<","<<Cofensivo[1]<<")\n";
        cout << "Angulo de disparo: " << Cofensivo[3] << endl;
        cout << "Velocidad inicial de la bala: "<< Cofensivo[4] << endl;
        cout << "tiempo en el cual detona la bala: " << tiempo << "s\n";






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

float TiempoDeImpactoBalaO(float *Cofensivo,float *Cdefensivo){
    int tiempo=0,x=0,y=0,r=0;
    r= Cofensivo[3] * 0.05;
    while(true){
        x = Cofensivo[0] + Cofensivo[4]*cos(Cofensivo[3]);
        y = Cofensivo[1] + (Cofensivo[4]*sin(45)+g*tiempo)+(0.5*g*pow(tiempo,2));
        if(x+pi >= Cdefensivo[0]){
            if((y+r>=Cdefensivo[1]) && (y-r<=Cdefensivo[1]))
                break;
        }
        tiempo += 0.1;
    }
    return true;


}
