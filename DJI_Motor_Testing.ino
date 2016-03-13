const int motorpin = 11;

void setup()
{
 pinMode(motorpin,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
 serialspeed();
}

void serialspeed()
{
 int speed;
 
 Serial.println("Please enter a speed ( 0 - 255)");
 Serial.println("Press enter");
 Serial.println();
 
 while(true)
 {
  while(Serial.available() > 0)
  {
   speed = Serial.parseInt();
   speed = constrain(speed, 0, 255);
   
   Serial.print("The speed has been set to ");
   Serial.println(speed);
   Serial.println();
   analogWrite(motorpin, speed);
  }
 }
}
