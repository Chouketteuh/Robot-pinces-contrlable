// Bibliothèques
#include <stdio.h>
/*UART*/
#include <SoftwareSerial.h>
/*IIC*/
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
  // Déclare la broche 8 en ENTREE et la broche 9 en sortie
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);

  // Demarrage des ports serie + vitesse de transmission
  UART.begin(19200); 
  Wire.begin(); // Bus IIC (Pas besoin d'adresse pour le maitre)
  Serial.begin(9600);

  delay(2000);
}

void loop()
{
  while(UART.available() > 0) // Lecture de la file d'attente (buffer) du port série, 0 si aucun caractère n'est disponible.
  {
    do // Entre dans la boucle au moins une fois
    {
      Data = UART.read(); // Lecture d'un bit dans la memoire tampon du software serial et le stocke dans une variable
      if(Data == 0x58) // Si égal à X
      {
        DataX = UART.parseInt(); // Lit le premier entier disponible dans le buffer série et le stocke dans une variable
        Serial.print(DataX);     // Affiche l'entier stocké dans DataX (Position Potentiomètre X) dans le moniteur serie
        Serial.println(":X");    // Affiche un X dans le moniteur serie
      }
      Data = UART.read();
      if(Data == 0x59) // Si égal à Y
      {
        DataY = UART.parseInt(); // Lit le premier entier disponible dans le buffer série et le stocke dans une variable
        Serial.print(DataY);     // Affiche l'entier stocké dans DataY (Position Potentiomètre Y) dans le moniteur serie
        Serial.println(":Y");    // Affiche un Y dans le moniteur serie
      }
    }while(Data == 0x58 || Data == 0x59); // Tant que c'est égal à X ou Y
    
    Data = UART.read();   // Lecture d'un bit dans la memoire tampon du software serial et le stocke dans une variable
    if(Data == 0x41)      // Si égal à A
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    }
    else if(Data == 0x42) // Si égal à B
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    }
    else if(Data == 0x43) // Si égal à C
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    }
    else if(Data == 0x44) // Si égal à D
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    }
    else if(Data == 0x45) // Si égal à E
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    }
    else if(Data == 0x46) // Si égal à F
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    }
    else if(Data == 0x4A) // Si égal à J
    {
      Serial.println(Data); // Affiche l'entier stocké dans Data (Boutons) dans le moniteur serie
    } 
  }
}
