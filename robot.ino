#include <stdio.h>
#include <Servo.h>

int cmd;                    // Variable de stockage de la commande
int ServoPin = 9;           // Servo PIN
int temps = 1500;           // Variable de l'inclinaison du servo - Valeur du milieu 1500
int SRH = 2400, SRAH = 700; // Valeur de rotation max (horaire & anti-horaire)
Servo ServoMoteur;

void setup()
{
  Serial.begin(9600);
  ServoMoteur.attach(ServoPin);         // Déclaration la broche de contrôle du servo
  ServoMoteur.writeMicroseconds(temps); // Démarre à la une valeur de la moitié
}

void loop()
{
  cmd = Serial.read();
  //Serial.println(temps);             // Retour sur la console pour savoir où on est rendu
  if(cmd == '0')             // Si la valeur du capteur gauche est en dessous de celui de droite
  {
    if(temps > SRAH)             // Si n'est pas à la valeur max anti-horaire (600)
    {
      temps -= 100;             // Retire 50 à la valeur "temps"
      Serial.print(temps);      // Affiche la valeur actuelle du servo-moteur 
      Serial.print(" | Sens anti-horaire\n"); // Affiche que la servo-moteur tourne dans le sens anti-horaire
      ServoMoteur.writeMicroseconds(temps);   // On modifie la consigne du servo (temps)
    }
    else // Sinon
    {
      Serial.print("Rotation max atteinte\n"); // Affiche que la valeur max est atteinte
    }
  }
  else if(cmd == '1')         // Si la valeur du capteur gauche est au dessus de celui de droite
  {
    if(temps < SRH)               // Si n'est pas à la valeur max horaire (2400)
    {
      temps += 100;              // Ajoute 50 à la valeur "temps"
      Serial.print(temps);       // Affiche la valeur actuelle du servo-moteur 
      Serial.print(" | Sens horaire\n");    // Affiche que la servo-moteur tourne dans le sens horaire
      ServoMoteur.writeMicroseconds(temps); // On modifie la consigne du servo (temps)
    }
    else // Sinon
    {
      Serial.print("Rotation max atteinte\n"); // Affiche que la valeur max est atteinte
    }
  }
  //delay(300); // Attente de 300 millisecondes
}
