//Attribution de noms aux PIN
#define bouton_A 2
#define bouton_B 3
#define bouton_C 4  
#define bouton_D 5
#define bouton_E 6
#define bouton_F 7
#define bouton_joystick 8   
#define joystick_X A0
#define joystick_Y A1

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
  if(digitalRead(bouton_A) == LOW)
  {
    Serial.write(0x41); // Affiche un A dans le moniteur serie
  }
  else if(digitalRead(bouton_B) == LOW)
  {
    Serial.write(0x42); // Affiche un B dans le moniteur serie
  }
  else if(digitalRead(bouton_C) == LOW)
  {
    Serial.write(0x43); // Affiche un C dans le moniteur serie
  }
  else if(digitalRead(bouton_D) == LOW)
  {
    Serial.write(0x44); // Affiche un D dans le moniteur serie
  }
  else if(digitalRead(bouton_E) == LOW)
  {
    Serial.write(0x45); // Affiche un E dans le moniteur serie
  }
  else if(digitalRead(bouton_F) == LOW)
  {
    Serial.write(0x46); // Affiche un F dans le moniteur serie
  }
  else if(digitalRead(bouton_joystick) == LOW)
  {
    Serial.write(0x4A); // Affiche un J dans le moniteur serie
  }
  else
  {
    Serial.write(0x58); 
    DataX = analogRead(joystick_X);
    Serial.println(DataX);

    Serial.write(0x59);
    DataY = analogRead(joystick_Y);
    Serial.println(DataY);
  }
}
