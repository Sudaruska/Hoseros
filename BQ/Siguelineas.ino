#include <Servo.h> 

Servo servoizq ;
Servo  servoder ;
int right = 0;     
int left = 0;


const int R0 = 78; 
const int L0 = 81; 
int Rspeed = -10;
int Lspeed = 10;

void setup() {
  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  servoizq.attach(8);
  servoder.attach(9);
  Serial.begin(9600);
  
    /*
  int repeticiones = 10;
  

   for (int i = 0; i< repeticiones; i++) 
    {
        origenRight += analogRead(A0);
        origenLeft += analogRead(A1);
        if (i%2 == 0)
        {
          servoder.write(R0);
          servoizq.write(L0+(Lspeed/2));
        } else {
          servoder.write(R0+(Lspeed/2));
          servoizq.write(L0);
        }
          delay(200);
    }
    */
}  
          
          
void loop() { 
   
  // servoder.write(0);  hacia atras
  // servoder.write(180);  hacia adelante
  
  servoder.write(180);
  servoizq.write(0);
  right = digitalRead(3);
  left = digitalRead(2);
    
  if ((right == 1) && (left==0)) //GIRAR DERECHA
  {
    servoder.write(180);
    servoizq.write(90);
    Serial.println("Gira a la derecha");
    delay(20);
  }
  else if ((right == 0) && (left == 1)) //GIRAR IZQUIERDA
  {
    servoder.write(90);
    servoizq.write(0);
    Serial.println("Gira a la izquierda");
     delay(20);
  }
  else if ((right == 0) && (left == 0)) // HACIA ADELANTE
  {
    servoder.write(180); 
    servoizq.write(0); 
    Serial.println("sigue de frente");
     delay(30);
  }   
  else if ((right == 1) && (left == 1)) // HACIA ATRAS
  {
    servoder.write(0); 
    servoizq.write(180); 
    Serial.println("ir hacia atras");
     delay(20);
  }  
  
}
  


