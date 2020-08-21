//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: JULIMAR 

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
 
//Define os pinos para o trigger e echo
#define pino_trigger 7
#define pino_echo 6
#define pino_led 10
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  //TEMPO DE COMUNICAO COM PORTA SERIAL
  Serial.begin(9600);  
  Serial.println("Lendo dados do sensor...");
  
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  //Buzzer
  pinMode(9,OUTPUT);
  //Led
  pinMode(10, OUTPUT);
}
 
void loop()
{
  //Le as informacoes do sensor em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  
  //Limpa a tela
  lcd.clear();
  
  //Posiciona o cursor na coluna 2, linha 0;
  lcd.setCursor(2, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("JADMJR - 4I4");
  //Posiciona o cursor na coluna 2, linha 1;
  lcd.setCursor(0, 1);
  //Envia o texto entre aspas para o LCD
  lcd.print("DIST: ");
  
  if ( cmMsec < 20 )
  {
    lcd.setCursor(6, 1);
    //Envia o texto entre aspas para o LCD
    lcd.print(cmMsec);
    tone(9,5000,150);
     //Acende o led
    digitalWrite(pino_led, HIGH);
    //Aguarda intervalo de tempo em milissegundos
     digitalWrite(pino_led, LOW);
    //Aguarda intervalo de tempo em milissegundos

  }
  lcd.setCursor(6, 1);
  //Envia o texto entre aspas para o LCD
  lcd.print(cmMsec);

  
 


}
