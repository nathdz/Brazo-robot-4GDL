//Diseño de mecanismos de precisión
//Brazo robot con 4 GDL
//Natalia Herández Ramos

// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo hombro;// SERVO 1
Servo codo;// SERVO 2
Servo muneca;// SERVO 3
Servo pinza;// SERVO 4
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
int motorPin1 = 8; // PIN-es del Motor
int IN1 = 8;      // pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 11;      // pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 12;     // pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 13;     // pin digital 11 de Arduino a IN4 de modulo controlador
int demora = 10;      // demora entre pasos, no debe ser menor a 10 ms.
// medio paso
int piston = 7;
int boton = 2;
int paso [8][4] =   // matriz (array bidimensional) con la secuencia de pasos
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  hombro.attach(10);
  codo.attach(5);
  muneca.attach(9);
  pinza.attach(6);
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
   pinMode(IN1, OUTPUT);   // todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(piston, OUTPUT);
  pinMode(boton, INPUT);
}
 
void loop() {
   long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
  // Desplazamos a la posición 0º

 if (d==4)
 {
    //-------------------------PRIMER PASO--------------------------------------
  for (int i = 0; i < 4; i++) // 512*8 = 4096 pasos //dependiendo de los pasos a poner sera el grado de movimiento 
  {
    for (int i = 0; i < 8; i++)   // bucle recorre la matriz de a una fila por vez
    {         // para obtener los valores logicos a aplicar
      digitalWrite(IN1, paso[i][0]);  // a IN1, IN2, IN3 e IN4
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  digitalWrite(IN1, LOW); // detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  hombro.write(45); //grados de movimiento del servo 1
  delay(500);
  codo.write(30);//grados de movimiento del servo 2
  delay(500);
  muneca.write(25);//grados de movimiento del servo 3
  delay(500);
  digitalWrite(piston,HIGH);
  pinza.write(15);//grados de movimiento del servo 4
  delay(500);
  //-------------------------SSEGUNDO PASO--------------------------------------
  for (int i = 0; i < 2; i++) // 512*8 = 4096 pasos //dependiendo de los pasos a poner sera el grado de movimiento 
  {
    for (int i = 0; i < 8; i++)   // bucle recorre la matriz de a una fila por vez
    {         // para obtener los valores logicos a aplicar
      digitalWrite(IN1, paso[i][0]);  // a IN1, IN2, IN3 e IN4
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  digitalWrite(IN1, LOW); // detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  hombro.write(90); //grados de movimiento del servo 1
  delay(500);
  codo.write(35);//grados de movimiento del servo 2
  delay(500);
  muneca.write(25);//grados de movimiento del servo 3
  delay(500);
  digitalWrite(piston,LOW);
  pinza.write(19);//grados de movimiento del servo 4
  delay(500);
  //-------------------------TERCER PASO--------------------------------------
  for (int i = 0; i < 1; i++) // 512*8 = 4096 pasos //dependiendo de los pasos a poner sera el grado de movimiento 
  {
    for (int i = 0; i < 8; i++)   // bucle recorre la matriz de a una fila por vez
    {         // para obtener los valores logicos a aplicar
      digitalWrite(IN1, paso[i][0]);  // a IN1, IN2, IN3 e IN4
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  digitalWrite(IN1, LOW); // detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  hombro.write(90); //grados de movimiento del servo 1
  delay(500);
  codo.write(90);//grados de movimiento del servo 2
  delay(500);
  muneca.write(90);//grados de movimiento del servo 3
  delay(500);
  digitalWrite(piston,HIGH);
  pinza.write(90);//grados de movimiento del servo 4
  delay(500);
  //------------------------- CUARTO PASO--------------------------------------
  //MOTOR A PASOS
  for (int i = 0; i < 1; i++) // 512*8 = 4096 pasos //dependiendo de los pasos a poner sera el grado de movimiento 
  {
    for (int i = 0; i < 8; i++)   // bucle recorre la matriz de a una fila por vez
    {         // para obtener los valores logicos a aplicar
      digitalWrite(IN1, paso[i][0]);  // a IN1, IN2, IN3 e IN4
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  digitalWrite(IN1, LOW); // detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  hombro.write(0); //grados de movimiento del servo 1
  delay(500);
  codo.write(0);//grados de movimiento del servo 2
  delay(500);
  muneca.write(0);//grados de movimiento del servo 3
  delay(500);
  digitalWrite(piston,LOW);
  pinza.write(0);//grados de movimiento del servo 4
  delay(500);
 }
}
