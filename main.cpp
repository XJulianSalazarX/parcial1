#include <iostream>
#include <math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

float TiempoDeImpactoBalaO(float *,float *, float,float &);
float TiempoDeImpactoBalaD(float *, float *, float, float &);

float pi=3.14159265358979323846, g=9.81;

int main()
{
    float *Cdefensivo = NULL, *Cofensivo = NULL,tiempo=0, angulo=0;
    int opc = 0;
    cout << "Seliccione:" << endl;
    cout << "1. Probar caso 1." << endl;
    cout << "2. Probar caso 2." << endl;
    cout << "3. Probar caso 3." << endl;
    cout << "4. Probar caso 4." << endl;
    cout << "0. salir." << endl;
    cout << "Eliga una opcion: ";cin >> opc;

    while(opc!=0){
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

            for(short i=0;i<3;){
                float Vo = 0;
                angulo = 1 + rand() % ((90) - 1); //generar valores aleatorios entre 1 y 89;
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
            delete [] Cdefensivo;
            delete [] Cofensivo;
        };
            break;
        case 2:{
            srand(time(NULL));
            //posicion canion ofensivo
            Cofensivo = new float[2];
            Cofensivo[0] = 0;
            Cofensivo[1] = 0;
            //posicion canion defensivo
            Cdefensivo = new float[2];
            Cdefensivo[0] = 500;
            Cdefensivo[1] = 100;

            for(short i=0;i<3; ){
                float Vo=0;
                angulo = 91 + rand() % ((180) - 91); //generar valores aleatorios entre 90 y 180;
                angulo = angulo*pi/180;
                tiempo = TiempoDeImpactoBalaD(Cofensivo,Cdefensivo,angulo,Vo);
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
            delete [] Cdefensivo;
            delete [] Cofensivo;

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
        cout << "Seliccione:" << endl;
        cout << "1. Probar caso 1." << endl;
        cout << "2. Probar caso 2." << endl;
        cout << "3. Probar caso 3." << endl;
        cout << "4. Probar caso 4." << endl;
        cout << "0. salir." << endl;
        cout << "Eliga una opcion: ";cin >> opc;
    }
    return 0;
}

float TiempoDeImpactoBalaO(float *Cofensivo,float *Cdefensivo, float angulo,float &inicial)
{
    float Vx=0,Vy=0,x=0,y=0,dist=0,radio=0; //= Cdefensivo[0]*0.05;
    radio = Cdefensivo[0]*0.05;
    for(int Vo=0;Vo<1000;Vo++){
        Vx = Vo*cos(angulo);
        Vy = Vo*sin(angulo);
        for(float t=0;t<100;t++){
            x = Vx * t;
            y = Cofensivo[1] + Vy*t - (0.5*g*t*t);
            dist = sqrt(pow(x-Cdefensivo[0],2)+pow(y-Cdefensivo[1],2));
            if(dist <= radio){
                inicial = Vo;
                return t;
            }
        }
    }
    return 0;
}

float TiempoDeImpactoBalaD(float *ofensivo, float *defensivo, float angulo, float &inicial)
{
    float Vx=0,Vy=0,x=0,y=0,dist=0,radio=0;
    radio = defensivo[0]*0.025;
    for(int Vo=0;Vo<1000;Vo++){
        Vx = Vo*cos(angulo);
        Vy = Vo*sin(angulo);
        for(float t=0;t<100;t++){
            x = defensivo[0] + Vx * t;
            y = defensivo[1] + Vy*t - (0.5*g*t*t);
            dist = sqrt(pow(x-ofensivo[0],2)+pow(y-ofensivo[1],2));
            if(dist <= radio){
                inicial = Vo;
                return t;
            }
        }
    }
    return 0;
}


