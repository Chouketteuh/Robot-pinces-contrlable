#include <SoftwareSerial.h>

//Attribution de noms aux PIN
#define RX_PIN 8
#define TX_PIN 9

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
  if (UART.available() > 0) 
  {
    for(int i=0;i<4;i++) //fois 4
      {
        Data[i] = UART.read();
        Serial.print(Data[i]);
      }
    if (UART.read() == 'P')
    {
      
      if (UART.read() == 'B')
      {
        
      }
      else if (UART.read() == 'X')
      {
        
      }
      else if (UART.read() == 'Y')
      {
        
      }
    }
  }
  delay(200);
}
