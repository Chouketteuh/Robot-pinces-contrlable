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
      pinMode(i, INPUT_PULLUP);  // Les broches 2 à 8 sont déclarées en entrée avec une résistance de tirage
  }
  Serial.begin(9600); // Initialisation du moniteur série
}

void loop()
{
  if(digitalRead(bouton_A) == LOW)
  {
   Serial.println("PA");
  }
  if(digitalRead(bouton_B) == LOW)
  {
   Serial.println("PB");
  }
  if(digitalRead(bouton_C) == LOW)
  {
   Serial.println("PC");
  }
  if(digitalRead(bouton_D) == LOW)
  {
   Serial.println("PD");
  }
  if(digitalRead(bouton_E) == LOW)
  {
   Serial.println("PE");
  }
  if(digitalRead(bouton_F) == LOW)
  {
   Serial.println("PF");
  }
  if(digitalRead(bouton_joystick) == LOW)
  {
   Serial.println("PJ");
  }
  Serial.print("PX");
  Serial.println(analogRead(joystick_X));
  Serial.print("PY");
  Serial.println(analogRead(joystick_Y));
  delay(500); // on attend 500 ms
}
