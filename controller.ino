// Déclaration des broches
#define bouton_A 2
#define bouton_B 3
#define bouton_C 4  
#define bouton_D 5
#define bouton_E 6
#define bouton_F 7
#define bouton_joystick 8   
#define joystick_X A0
#define joystick_Y A1                           

void setup()
{
  for (int i=2; i <= 8; i++)
  {
      pinMode(i, INPUT_PULLUP); // Déclaration des broches 2 à 8 en entrée avec une résistance de tirage
  }
  
  Serial.begin(9600); // Initialisation du moniteur série
}

void loop()
{
  if(digitalRead(bouton_A) == LOW)
  {
    Serial.println("A");
  }
  if(digitalRead(bouton_B) == LOW)
  {
    Serial.println("B");
  }
  if(digitalRead(bouton_C) == LOW)
  {
    Serial.println("C");
  }
  if(digitalRead(bouton_D) == LOW)
  {
    Serial.println("D");
  }
  if(digitalRead(bouton_E) == LOW)
  {
    Serial.println("E");
  }
  if(digitalRead(bouton_F) == LOW)
  {
    Serial.println("F");
  }
  if(digitalRead(bouton_joystick) == LOW)
  {
    Serial.println("J");
  }
  
  Serial.print("X");
  Serial.println(analogRead(joystick_X));
  Serial.print("Y");
  Serial.println(analogRead(joystick_Y));
}
