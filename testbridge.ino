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
  // check if data is available
  if (Serial.available() > 0) 
  {
    // read the incoming bytes:
    int rlen = Serial.readBytesUntil('\n', Data, 4);

    // prints the received data
    Serial.print("I received: ");
    for(i = 0; i < rlen; i++)
      Serial.print(Data[i]);
  }
}
