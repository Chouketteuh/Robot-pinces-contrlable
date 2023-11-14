//Bibliothèques
#include <stdio.h>
#include <Servo.h>

// Servo PIN
#define ServoPin 9

// Moteur Gauche PINs
#define MG_1 *
#define MG_2 * 
#define MG_vit *

// Moteur Droit PINs
#define MD_1 *
#define MD_2 * 
#define MD_vit *

int cmd;                    // Variable de stockage de la commande  
int temps = 1500;           // Variable de l'inclinaison du servo - Valeur du milieu 1500
int SRH = 2400, SRAH = 700; // Valeur de rotation max (horaire & anti-horaire)
Servo ServoMoteur;          // Déclaration du ServoMoteur

void setup()
{
  Serial.begin(9600);                   // Démmarage du monieur serie
  ServoMoteur.attach(ServoPin);         // Déclaration la broche de contrôle du servo
  ServoMoteur.writeMicroseconds(temps); // Démarre à la une valeur de la moitié
}

void loop()
{
  cmd = Serial.read();     // Lecture du moniteur serie et ajout de cette valeur dans la variable
  //Serial.println(temps); // Retour sur la console pour savoir où on est rendu
  if(cmd == '0')           // Si la valeur lue du moniteur serie est égale à 0
  {
    if(temps > SRAH)       // Si n'est pas à la valeur max anti-horaire (700)
    {
      temps -= 100;        // Retire 50 à la valeur "temps"
      Serial.print(temps); // Affiche la valeur actuelle du servo-moteur 
      Serial.print(" | Sens anti-horaire\n"); // Affiche que la servo-moteur tourne dans le sens anti-horaire
      ServoMoteur.writeMicroseconds(temps);   // On modifie la consigne du servo (temps)
    }
    else // Sinon
    {
      Serial.print("Rotation max atteinte\n"); // Affiche que la valeur max est atteinte
    }
  }
  else if(cmd == '1')      // Si la valeur lue du moniteur serie est égale à 1
  {
    if(temps < SRH)        // Si n'est pas à la valeur max horaire (2400)
    {
      temps += 100;        // Ajoute 50 à la valeur "temps"
      Serial.print(temps); // Affiche la valeur actuelle du servo-moteur 
      Serial.print(" | Sens horaire\n");    // Affiche que la servo-moteur tourne dans le sens horaire
      ServoMoteur.writeMicroseconds(temps); // On modifie la consigne du servo (temps)
    }
    else // Sinon
    {
      Serial.print("Rotation max atteinte\n"); // Affiche que la valeur max est atteinte
    }
  }
  else if(cmd == '2')      // Si la valeur lue du moniteur serie est égale à 2
  {
    // Tourne vers l'avant roue gauche
    digitalWrite(MG_1, HIGH); 
    digitalWrite(MG_2, LOW);
    
    // Tourne vers l'avant roue droite
    digitalWrite(MD_1, HIGH); 
    digitalWrite(MD_2, LOW);
    
    Serial.print("Avant");
  }
  else if(cmd == '3')      // Si la valeur lue du moniteur serie est égale à 3
  {
    // Tourne vers l'arrière roue gauche
    digitalWrite(MG_1, LOW); 
    digitalWrite(MG_2, HIGH);

    // Tourne vers l'arrière roue droite
    digitalWrite(MD_1, LOW); 
    digitalWrite(MD_2, HIGH);
    
    Serial.print("Arrière");
  }
  else if(cmd == '4')      // Si la valeur lue du moniteur serie est égale à 3
  {
    // Stoppe la roue gauche
    digitalWrite(MG_1, HIGH); 
    digitalWrite(MG_2, HIGH);

    // Stoppe la roue droite
    digitalWrite(MD_1, HIGH); 
    digitalWrite(MD_2, HIGH);
    
    Serial.print("Stop");
  }
  //delay(300); // Attente de 300 millisecondes
}
