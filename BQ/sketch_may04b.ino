char input; 
int Trig = 2, Echo =3;
long duracion, distancia;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  DDRB=B00001111;
  
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  
}
void loop() {
 
 
    if (Serial.available()>0){
    //leeemos la opcion
    char input = Serial.read();
    //si la opcion esta entre '1' y '9'
     Motores();
    }
    
    
    Ultra();
     Serial.println(distancia);
  if(distancia<=10) {
    PORTB=B00000000;  
    delayMicroseconds(100);
    PORTB=B00000101;
    delay(500);
    PORTB=B00000000;
  }
  
  delayMicroseconds(10);
 

}


void Ultra () {
  digitalWrite(Trig,LOW);
  delayMicroseconds(4);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  
  
  duracion = pulseIn(Echo,HIGH);
  distancia = (duracion/2)/29;
  
}


void Motores() {
  
  
  if(input=='1') {
    digitalWrite(LED_BUILTIN,HIGH);
    PORTB=B00001010;
  }
  if(input=='2') {
    digitalWrite(LED_BUILTIN,HIGH);
    PORTB=B00000110;
  }
  if(input=='3') {
    digitalWrite(LED_BUILTIN,HIGH);
    PORTB=B00001001;
  }
  if(input=='4') {
    digitalWrite(LED_BUILTIN,HIGH);
    PORTB=B00000101;
  }
    if(input=='0') {
    digitalWrite(LED_BUILTIN,LOW);
    PORTB=B00000000;
  }
  
}
