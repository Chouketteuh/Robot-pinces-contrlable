#include <stdio.h>
#include <string.h>
#include <SoftwareSerial.h>

//Attribution de noms aux PIN
#define RX_PIN 8
#define TX_PIN 9

char i;
char Data[4];

SoftwareSerial UART = SoftwareSerial(RX_PIN, TX_PIN); //Création du nouveau port serie

void setup()
{ 
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);

  //Demarrage des ports serie + vitesse de transmission
  UART.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  if (UART.available() > 0) 
  {
    for(i=0;i<5;i++) //fois 5
    {
      Data[i] = 0;
    }
    Data[0] = UART.read();
    if(Data[0] == 'X')
    {
      i = 0;
      Serial.print("Data X: ");
      do
      {
        Data[i] = UART.read();
        Serial.print(Data[i]);
        i = i+1;
      }while((Serial.available() > 0) && (Data[i] != 'X') && (Data[i] != 'Y'));
    }
    if(Data[0] == 'Y')
    {
      i = 0;
      Serial.print("Data Y: ");
      while(Serial.available() > 0 && Data[i] != 'X' && Data[i] != 'Y');
      {
        Data[i] = UART.read();
        Serial.print(Data[i]);
        i = i+1;
      }
    }
    if(Data[0] != 'X' || Data[0] != 'Y')
    {
      Serial.print("Data: ");
      Serial.print(Data[0]);
    }
    Serial.println("");
    delay(200);
  }
}
