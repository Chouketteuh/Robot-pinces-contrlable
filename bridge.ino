// Bibliothèques
#include <stdio.h>
#include <SoftwareSerial.h>
#include <Wire.h>

// Attribution de noms aux PIN
#define RX_PIN 8
#define TX_PIN 9

// Variables de stockage
int DataX;
int DataY;
char Data;

SoftwareSerial UART = SoftwareSerial(RX_PIN, TX_PIN); //Création du nouveau port serie

void setup()
{ 
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);

  //Demarrage des ports serie + vitesse de transmission
  UART.begin(19200);
  Serial.begin(9600);

  Wire.begin(); // Bus I2C (Pas besoin d'adresse pour le maitre)

  delay(2000);
}

void loop()
{
  while(UART.available() > 0) // Lecture de la file d'attente (buffer) du port série, 0 si aucun caractère n'est disponible.
  {
    do
    {
      Data = UART.read();
      if(Data == 0x58) // Si égal à X
      {
        DataX = UART.parseInt(); // Lit le premier entier disponible dans le buffer série
        Serial.print(DataX);     // Affiche l'entier stocker dans DataX (Position Potentiomètre X)
        Serial.println(":X");
      }
      Data = UART.read();
      if(Data == 0x59) // Si égal à Y
      {
        DataY = UART.parseInt(); // Lit le premier entier disponible dans le buffer série
        Serial.print(DataY);     // Affiche l'entier stocker dans DataY (Position Potentiomètre Y)
        Serial.println(":Y");
      }
    }while(Data == 0x58 || Data == 0x59); // Tant que c'est égal à X ou Y
    
    Data = UART.read();
    if(Data == 0x41)     // Si égal à A
    {
      Serial.println(Data);
    }
    else if(Data == 0x42) // Si égal à B
    {
      Serial.println(Data);
    }
    else if(Data == 0x43) // Si égal à C
    {
      Serial.println(Data);
    }
    else if(Data == 0x44) // Si égal à D
    {
      Serial.println(Data);
    }
    else if(Data == 0x45) // Si égal à E
    {
      Serial.println(Data);
    }
    else if(Data == 0x46) // Si égal à F
    {
      Serial.println(Data);
    }
    else if(Data == 0x4A) // Si égal à J
    {
      Serial.println(Data);
    } 
  }
}
