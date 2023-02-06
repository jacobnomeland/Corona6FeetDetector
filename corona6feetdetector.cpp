
// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
const int red_pin1= 2;
const int red_pin2= 3;
const int yellow_pin1= 4;
const int yellow_pin2= 5;
const int green_pin= 6;
const int button= 7;

// defines variables
long duration;
float distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(red_pin1, OUTPUT); 
pinMode(red_pin2, OUTPUT); 
pinMode(yellow_pin1, OUTPUT); 
pinMode(yellow_pin2,OUTPUT);
pinMode(green_pin, OUTPUT); 
pinMode(button, INPUT);


Serial.begin(9600); // Starts the serial communication
}

void loop() {

//while(digitalRead(button)== 1){
//  // Clears the trigPin
//  
//  
  delay(200);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  //speed of sound =.00112533
  distance= duration*0.0011154856/2;
  
  
  if(distance <= 3){
    digitalWrite(red_pin1,HIGH);
    digitalWrite(red_pin2,LOW);
    digitalWrite(yellow_pin1,LOW);
    digitalWrite(yellow_pin2,LOW);
    digitalWrite(green_pin,LOW);
  }
  else if(distance <= 4){
    digitalWrite(red_pin1,LOW);
    digitalWrite(red_pin2,HIGH);
    digitalWrite(yellow_pin1,LOW);
    digitalWrite(yellow_pin2,LOW);
    digitalWrite(green_pin,LOW);
  }
  else if(distance <= 5){
    digitalWrite(red_pin1,LOW);
    digitalWrite(red_pin2,LOW);
    digitalWrite(yellow_pin1,HIGH);
    digitalWrite(yellow_pin2,LOW);
    digitalWrite(green_pin,LOW);
  }
  else if(distance <= 6){
    digitalWrite(red_pin1,LOW);
    digitalWrite(red_pin2,LOW);
    digitalWrite(yellow_pin1,LOW);
    digitalWrite(yellow_pin2,HIGH);
    digitalWrite(green_pin,LOW);
  }
  else {
    digitalWrite(red_pin1,LOW);
    digitalWrite(red_pin2,LOW);
    digitalWrite(yellow_pin1,LOW);
    digitalWrite(yellow_pin2,LOW);
    digitalWrite(green_pin,HIGH);
  }
  
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("\tButton:");
  Serial.println(digitalRead(button));  
//}
//
////Outside of while loop
//digitalWrite(red_pin,LOW);
//digitalWrite(yellow1_pin,LOW);
//digitalWrite(yellow2_pin,LOW);
//digitalWrite(green_pin,LOW);
//digitalWrite(yellow3_pin,LOW);
//  // Prints the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.print("\tButton:");
//  Serial.println(digitalRead(button));

}
