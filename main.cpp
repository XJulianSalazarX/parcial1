#include <iostream>
#include <math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
float TiempoDeImpactoBalaO(float *,float *, float,float &);
float pi=3.14159265358979323846, g=9.81;

int main()
{
    float *Cdefensivo = NULL, *Cofensivo = NULL,tiempo=0, angulo=0;
    int opc = 0;
    cout << sin(45*pi/180) << endl;
    cout << "Seliccione:" << endl;
    cout << "1. Probar caso 1." << endl;
    cout << "2. Probar caso 2." << endl;
    cout << "3. Probar caso 3." << endl;
    cout << "4. Probar caso 4." << endl;
    cout << "0. salir." << endl;
    cout << "Eliga una opcion: ";cin >> opc;

    switch (opc) {
    case 1:{
        srand(time(NULL));
        //Posicion canion ofensivo
        Cofensivo = new float[2];
        Cofensivo[0] = 0;
        Cofensivo[1] = 0;
        //posicion canion defensivo
        Cdefensivo = new float[2];
        Cdefensivo[0] = 500;
        Cdefensivo[1] = 100;

        for(int i=0;i<3;){
            float Vo = 0;
            angulo = 1 + rand() % ((90) - 1); //generar valores aleatorios entre 1 y 90;
            angulo = angulo*pi/180;
            tiempo = TiempoDeImpactoBalaO(Cofensivo,Cdefensivo,angulo,Vo);
            if(tiempo!=0){

                cout << endl;
                cout << "cordenadas canion ofensivo: ("<<Cofensivo[0]<<","<<Cofensivo[1]<<")"<<endl;
                cout << "cordenadas canion defensivo: ("<<Cdefensivo[0]<<","<<Cdefensivo[1]<<")"<<endl;
                cout << "Velocidad inical de la bala: "<<Vo<<" m/s"<<endl;
                cout << "angulo de disparo:" << angulo*180/pi << endl;
                cout << "tiempo en el que la bala detona: "<<tiempo<<" seg."<<endl;
                cout << endl;
                i++;
                tiempo=0;
            }
        }
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
    return 0;
}

float TiempoDeImpactoBalaO(float *Cofensivo,float *Cdefensivo, float angulo,float &inicial)
{
    float Vx=0,Vy=0,x=0,y=0,dist=0,radio=0; //= Cdefensivo[0]*0.05;
    radio = Cdefensivo[0]*0.05;
    for(int Vo=0;Vo<1000;Vo++){
        Vx = Vo*cos(angulo);
        Vy =Vo*sin(angulo);
        for(float t=0;t<100;t++){
            x = Vx * t;
            y = Cofensivo[0] + Vy*t - (0.5*g*t*t);
            dist = sqrt(pow(x-Cdefensivo[0],2)+pow(y-Cdefensivo[1],2));
            if(dist <= radio){
                cout << "v inicial:" << Vo;
                inicial = Vo;
                return t;
            }
        }
    }
    return 0;
}


