// pins
int V_5 = 0;
int V_R = 2;

float C0 = 0.0000000000046853892;
float f = 0;
float C = 0;
float X =0;

float V_5max = 2.5 * 255 / 5;
float V_5min = 1 * 255 / 5;

float V_R1 = 0;
float V_R2 = 0;


void setup()
{
  pinMode(V_5, OUTPUT);
  pinMode(V_R, INPUT);
}


// the loop routine runs over and over again forever:
void loop()
{
  
  analogWrite(V_5, V_5max);
  int V_R1 = analogRead(V_R);
  delay(1000); // Wait for 1000 millisecond(s)
  
  analogWrite(V_5, V_5min);
  int V_R2 = analogRead(V_R);
  delay(1000); // Wait for 1000 millisecond(s)
  
  
  if (V_R1<V_R2)
  {
    V_5min = (V_5min+V_5max)/2;
  }
  else if(V_R1 > V_R2)
  {
    V_5max = (V_5min+V_5max)/2;
  }
  else if( V_R1 == V_R2)
  {
    f = V_R1 / 3.375 *15000;
    //C = f^2/1.72;
    //X = (C/C0-15-1)/16*10^8;
  }
  
}