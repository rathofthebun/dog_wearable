int buttonPin = 4;
int photoresistor= 0;
int counter = 0;

int red_light_pin= 9;
int green_light_pin = 10;
int blue_light_pin = 11;



const int threshold= 300;

void setup() {
//  Serial.begin(9600); 
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(photoresistor, INPUT);
//  pinMode (ledPin, OUTPUT); //sets digital pin 13 as output
  Serial.begin(9600); //sets the baud rate at 9600 so we can check the values the sensor is obtaining on the Serial Monitor
}

void loop() {

  photoresistor = analogRead(A0); //the sensor takes readings from analog pin A0
  
//  Serial.println(photoresistor);
  Serial.println(analogRead(A0));
  

 //the sensor takes readings from analog pin A0
 int buttonState;
  buttonState = digitalRead(A4);
  
  Serial.println(buttonState);
  Serial.println(counter);
  
  if (buttonState == 0) {
    counter++;
  }
  
   if (photoresistor < threshold){
    if (counter == 0) {
     RGB_color(255, 0, 255); // Magenta
    }
    else if (counter  == 1) {
      RGB_color(0, 255, 255); // Magenta
    }
    else if (counter == 2) {
      RGB_color(0, 0, 255); // Magenta
    }
   else if (counter == 3) {
      RGB_color(255, 255, 0); // Magenta
    } else if(counter > 3) {
      counter = 0;
    }
    }
    else{
      RGB_color(255, 255, 255); //off
    }
  
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
