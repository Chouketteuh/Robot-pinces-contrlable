// Attribution de noms aux PINs
#define bouton_A 2
#define bouton_B 3
#define bouton_C 4  
#define bouton_D 5
#define bouton_E 6
#define bouton_F 7
#define bouton_joystick 8   
#define joystick_X A0
#define joystick_Y A1

// Variables de stockage
int DataX;
int DataY;

void setup()
{
  for (int i=2; i <= 8; i++) // Boucle de déclaration des broches 2 à 8 en entrée avec une résistance de tirage
  {
    pinMode(i, INPUT_PULLUP); // Déclaration de broche avec une résistance de tirage
  }
  
  Serial.begin(19200); // Initialisation du moniteur série
}

void loop()
{
  if(digitalRead(bouton_A) == LOW) // Si le bouton A est pressé
  {
    Serial.write(0x41); // Affiche un A dans le moniteur serie
  }
  else if(digitalRead(bouton_B) == LOW) // Sinon si le bouton B est pressé
  {
    Serial.write(0x42); // Affiche un B dans le moniteur serie
  }
  else if(digitalRead(bouton_C) == LOW) // Sinon si le bouton C est pressé
  {
    Serial.write(0x43); // Affiche un C dans le moniteur serie
  }
  else if(digitalRead(bouton_D) == LOW) // Sinon si le bouton D est pressé
  {
    Serial.write(0x44); // Affiche un D dans le moniteur serie
  }
  else if(digitalRead(bouton_E) == LOW) // Sinon si le bouton E est pressé
  {
    Serial.write(0x45); // Affiche un E dans le moniteur serie
  }
  else if(digitalRead(bouton_F) == LOW) // Sinon si le bouton F est pressé
  {
    Serial.write(0x46); // Affiche un F dans le moniteur serie
  }
  else if(digitalRead(bouton_joystick) == LOW) // Sinon si le bouton J est pressé
  {
    Serial.write(0x4A); // Affiche un J dans le moniteur serie
  }
  else // Sinon
  {
    Serial.write(0x58); // Affiche un X dans le moniteur serie
    DataX = analogRead(joystick_X); // Lecture de la broche du potentiomètre horizontal et le stocke dans une variable
    Serial.println(DataX); // Affiche l'entier stocké dans DataX (Position Potentiomètre X) dans le moniteur serie

    Serial.write(0x59); // Affiche un Y dans le moniteur serie
    DataY = analogRead(joystick_Y); // Lecture de la broche du potentiomètre verical et le stocke dans une variable
    Serial.println(DataY); // Affiche l'entier stocké dans DataY (Position Potentiomètre Y) dans le moniteur serie
  }
}
