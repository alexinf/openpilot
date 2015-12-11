

/* 
   #Fabrica de Software.
   #Alexander Fidel Marquez
   #UMSS ING Informatica
   #control openpilot.
   #frecuencia = 50 hz 
   #duty  = entre 1 ms a 1.7 ms 
   
*/
#include <Servo.h> 
 
//int pot = 72;  
Servo picht;
Servo roll;
Servo yaw;
Servo flight;
Servo accesorio;
Servo throttle; 
//int pos = 0;     
int lectura=0;
int outputValue_throttle=56;
int outputValue_picht=95;
int outputValue_roll=95;
int outputValue_yaw=95;
int outputValue_flight=95;
int outputValue_accesorio=95;

void setup() 
{ 
  throttle.attach(6);  
  picht.attach(9);
  roll.attach(10);
  yaw.attach(11);
  flight.attach(3);
  accesorio.attach(5);
  Serial.begin(9600);
  Serial.println("conectado");
  throttle.write(outputValue_throttle);
  picht.write(outputValue_picht);
  roll.write(outputValue_roll);
  yaw.write(outputValue_yaw);
  flight.write(outputValue_flight);
  accesorio.write(outputValue_accesorio);
} 
 
void loop() 
{ 
  


  if(Serial.available()>0)
  {
    lectura = Serial.read();
     if(lectura == 't')
     {
       lectura = Serial.parseInt();
       outputValue_throttle = map(lectura, 0, 100, 56, 130);
       throttle.write(outputValue_throttle);
       //Serial.print(outputValue_throttle); 
            
     }
    
    if(lectura == 'p')
    {
          lectura = Serial.parseInt();
          outputValue_picht = map(lectura, 0, 100, 72, 119);
          picht.write(outputValue_picht);              
          //delay(15);
          //Serial.println(outputValue); */    
    }
     
    if(lectura == 'r')
    {
       lectura = Serial.parseInt();
       outputValue_roll = map(lectura, 0, 100, 72, 119);
       roll.write(outputValue_roll);             
       //delay(15);
       //Serial.println(outputValue);   
    }
    if(lectura == 'y')
    {
       lectura = Serial.parseInt();
       outputValue_yaw = map(lectura, 0, 100, 72, 119);
       yaw.write(outputValue_yaw);              
       //delay(15);
       //Serial.println(outputValue);  

    }     
  
    if(lectura== 'f')
    {
       lectura = Serial.parseInt();
       outputValue_flight = map(lectura, 0, 100, 72, 119);
       yaw.write(outputValue_flight);  
    }
    if(lectura== 'a')
    {
       lectura = Serial.parseInt();
       outputValue_accesorio = map(lectura, 0, 100, 72, 119);
       yaw.write(outputValue_accesorio);  
    }
    if(lectura = 's')
    {
      armar();
    }

  }// lectura del  serial
    throttle.write(outputValue_throttle);
    picht.write(outputValue_picht);
    roll.write(outputValue_roll);
    yaw.write(outputValue_yaw);
    flight.write(outputValue_flight);
    accesorio.write(outputValue_accesorio);
} 
void armar()
{
  for(int i = 95; i<= 119; i++)
  {
     yaw.write(i);
     delay(10);
  }
  
  yaw.write(119);
  delay(10000);
  for(int j = 119;j>95;j--)
  {
    yaw.write(j);
  }
  yaw.write(95);
  //delay(10000);

}
