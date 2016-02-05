#include <Keypad.h>
#include <Servo.h>

/////////////////////////////////////////////////////////
const byte filas = 4; 
const byte columnas = 4;
char keys[filas][columnas] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte filaPins[filas] = {5, 4, 3, 2}; 
byte colPins[columnas] = {8, 7, 6, 9};

Keypad keypad = Keypad( makeKeymap(keys),filaPins, colPins, filas, columnas );
//////////////////////////////////////////////////////////

Servo llave;
//////////////////////////////////////////////////////////
int key[4];



void setup(){
  Serial.begin(9600);
  llave.attach(10);
  
///////////////////////////////////////////////
//PARA ESTABLECER UNA CONTRASEÑA///////////////
  Serial.println("Introduce una contraseña de 4 caracteres");
  for (int i=0;i<4;i++)
  {
    key[i] = keypad.getKey();
  }
  Serial.println("Contraseña creada correctamente!");
  Serial.println("Su contraseña: ");
  for (int i=0;i<4;i++)
  {
    Serial.print(key[i]);
  }

////////////////////////////////////////////////////////
}

int keyIN[4];

int abrir = 11;
int cerrar = 12;

void loop(){
  Serial.println("Introduce la contraseña");
  for (int i=0;i<4;i++)
  {
    keyIN[i] = keypad.getKey();
  }

    if(keyIN[1] == key[1])
    {
      if(keyIN[2] == key[2])
      {
        if(keyIN[3] == key[3])
        {  
          if(keyIN[4] == key[4])
          {
            digitalWrite(abrir,1);
            digitalWrite(cerrar,0);
            delay(2000);
          }
          else
          {
            Serial.println("ERROR! Contraseña incorrecta");
          }
        }
        else
        {
          Serial.println("ERROR! Contraseña incorrecta");
        }
      }
      else
      {
        Serial.println("ERROR! Contraseña incorrecta");
      }
    }
    else
    {
      Serial.println("ERROR! Contraseña incorrecta");
    }  
  
   char keyA = keypad.getKey(); //Presione A para cerrar
   if (keyA = 'A')
   {
     digitalWrite (abrir,0);
     digitalWrite (cerrar,1);
     delay(2000);
   }
   int ppc = digitalRead(13); // ppc = Presione para cerrar
   if (ppc = 1)
   {
     digitalWrite (abrir,0);
     digitalWrite (cerrar,1);
     delay(2000);
   }
   int ppa = digitalRead(14); // ppa = Presione para abrir
   if (ppa = 1)
   {
     digitalWrite (abrir,1);
     digitalWrite (cerrar,0);
     delay(2000);
   } 
}
