int state=LOW;
int lastState=LOW;
int count=0;
float weight=60;                       //change weight(kg)
float height=165;                      //change height(cm)
float step_length;
float calories=0;
float calories_burned_per_km;
float steps_in_a_mile;
float calories_burned;
char option;
float t;
float velocity;
float distance;


void setup()
{
Serial.begin(9600);
pinMode(12, INPUT);
state=digitalRead(12); 
step_length=0.41*height;                             //height in cm
calories_burned_per_km=(0.57*weight*1.6)/0.453;      //weight in kg                  //weight in kg
steps_in_a_mile=160000.0/step_length;                //160000.0 is a km in cm
Serial.println("Arduino is ready");
Serial.println("Pedometer");
}
void loop()
{
  if (state==HIGH && lastState==LOW)
 {
  count++;
  Serial.print("Steps : ");
  Serial.println(count);
 }
calories_burned=count*(count/steps_in_a_mile);
option=Serial.read();
if(option=='c')
{
Serial.print("Calories burned : ");
Serial.println(calories_burned);          
}
if(option=='d')
{
  distance=(step_length*count)/100;         //distance in m 
  Serial.print("Distance : ");
  Serial.println(distance);
}
if(option=='s')
{
  t=millis();
  t=t/1000;
  velocity=(step_length*count)/(t*100);      //in m/s
  Serial.print("Speed : ");
  Serial.println(velocity);
}
lastState=state;
state=digitalRead(12);
delay(300);
}
