#include <stdio.h>
#include <string.h>
#include <SoftwareSerial.h>

//Attribution de noms aux PIN
#define RX_PIN 8
#define TX_PIN 9

char Data[5], i, j;

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
    for(i=0;i<5;i++) //fois 5
    {
      Data[i] = UART.read();
      j = (i + 1);
      if(Data[i] == ('A' && 'B'&& 'C'&& 'D'&& 'E'&& 'F'&& 'J'&& 'X'&& 'Y')) break;
    }
    Serial.print("C'est: ");
    for(i=0;i<j;i++) //fois j
    {
      Serial.print(Data[i]);
    }
    Serial.println("");
  }
  delay(50);
}
