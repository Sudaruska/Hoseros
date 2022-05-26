/*************/
/*  SEMAFORO */
/*************/
#include <Servo.h>
Servo Myservo;
//** Definiciones **//
int rojo=2;      //definimos el valor del pin para el led rojo
int verde=7;     //definimos el valor del pin para el led verde
Servo barrera;    //definimos la barrera
int pos=0;

//** Programa **//

void setup() {
  barrera.attach(5);
  pinMode(verde,OUTPUT);   //declaramos el pin verde como salida  
  pinMode(rojo,OUTPUT);    //declaramos el pin rojo como salida  
}

void loop() {
 digitalWrite(verde,HIGH);//encendemos el led verde
  barrera.write(180);     //movemos la barrera
 delay(5000);             //esperamos 5 segundos
 digitalWrite(verde,LOW);  //apagamos el led verde
 delay(500);              //esperamos medio segundo
 
 
 digitalWrite(rojo,HIGH); //encendemos el led rojo
  barrera.write(0);        //movemos la barrera
 delay(5000);              //esperamos 5 segundos
 digitalWrite(rojo,LOW);  //apagamos el led rojo
 delay(500);               //esperamos medio segundo
}
