//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define buzzer 10
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
 
}
 
void loop()
{

  
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);  

  if (cmMsec < 30)
  {
    tone(buzzer,261);
    delay(500);        
    tone(buzzer,293); 
      delay(500);   
    tone(buzzer,329);     
      delay(500);      
    tone(buzzer,349);
      delay(500);   
    
    Serial.print("Distancia em cm: ");
    Serial.println(cmMsec);
    
    tone(buzzer,2500);   
    delay(500);  
     
  }
  
  delay(200);
}
