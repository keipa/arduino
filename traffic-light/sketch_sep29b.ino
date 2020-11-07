int redled =10; // initialize digital pin 8.
int yellowled =7; // initialize digital pin 7.
int greenled =4; // initialize digital pin 4.
void setup()
{
pinMode(redled, OUTPUT);// set the pin with red LED as “output”
pinMode(yellowled, OUTPUT); // set the pin with yellow LED as “output”
pinMode(greenled, OUTPUT); // set the pin with green LED as “output”
}
void loop()
{

digitalWrite(redled, HIGH);
delay(5000);
digitalWrite(yellowled, HIGH);
delay(1000);// wait 0.5 second
digitalWrite(redled, LOW);
digitalWrite(yellowled, LOW);
digitalWrite(greenled, HIGH);
delay(5000);
for(int i=0;i<3;i++)// blinks for 3 times
{
digitalWrite(greenled, LOW);
delay(500);// wait 0.5 second
digitalWrite(greenled, HIGH);
delay(500);// wait 0.5 second
} 
digitalWrite(greenled, LOW);
digitalWrite(yellowled, HIGH);
delay(2000);
digitalWrite(yellowled, LOW);
//digitalWrite(greenled, HIGH);//// turn on green LED
//delay(5000);// wait 5 seconds
//
//digitalWrite(greenled, LOW); // turn off green LED
//for(int i=0;i<3;i++)// blinks for 3 times
//{
//delay(500);// wait 0.5 second
//digitalWrite(yellowled, HIGH);// turn on yellow LED
//delay(500);// wait 0.5 second
//digitalWrite(yellowled, LOW);// turn off yellow LED
//} 
//delay(500);// wait 0.5 second
//digitalWrite(redled, HIGH);// turn on red LED
//delay(5000);// wait 5 second
//digitalWrite(redled, LOW);// turn off red LED
}
