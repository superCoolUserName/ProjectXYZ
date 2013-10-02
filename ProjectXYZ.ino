/*
  LiquidCrystal
 * LCD Pin 1 to Ground
 * LCD Pin 2 to +5V
 * LCD VO pin 3 to wiper
 * LCD RS(pin 4) to digital pin 12 
 * LCD R/W (pin 5) to ground
 * LCD Enable(pin 6) to digital pin 13
 * LCD D4 pin to digital pin 8
 * LCD D5 pin to digital pin 7
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 5
 * LCD D15 to Ground
 * LCD D16 to Red Pin
 * LCD D17 to Green
 * LCD D18 to Blue
 * 10K resistor:
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 https://www.sparkfun.com/products/10862 
*/
// LCD include the library code:
#include <LiquidCrystal.h>

// LCD initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 13, 8, 7, 6, 5);

//Push Button this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to

//LED Pins used for PWM
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

//Pins used for 10K pots
const int redPotPin = A2;
const int greenPotPin = A3;
const int bluePotPin = A4;

//Int of Pot Value changed into RGB 0-255
int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;

//Button
int val = LOW; // variable to read button pin value
int sequence = 0; // variable to hold current sequence

//crossFader
int RedVal=1;
int BlueVal=1;
int GreenVal=1;
int i=1;

void setup() {
//LCD set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

//Main led out
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

//button setup
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);   // view serial output to debug button counter

//Begin Hello Message
 analogWrite(bluePin, 200);  //color LCD
 analogWrite(redPin, 200);   
 analogWrite(greenPin, 200);
 lcd.setCursor(0,0);
 lcd.print("Created By Joe");
 delay(500);
 lcd.setCursor(0,1);
 lcd.print("Hello");
 delay(2000);
}

void loop() {
      val = digitalRead(buttonPin);
        if(val == HIGH)
        {
            if(sequence == 11) // if sequence is at 11 already, make it 1 again
            {
               sequence = 1;
            } else
                {
                  sequence++; // otherwise go to the next sequence
                }
          Serial.print(val);
      
                delay(300);  // we need this here to ensure that only one button press is registered
                             // otherwise sequence is very quickly incremented and the circuit doesn't work
                             // if you don't understand what I mean, remove this delay and try it...
      
        
      }

         switch(sequence)
                 {                   
                     case 1:
                     //Manual Mode
                     manualControl();
                     
                     break;
                     
                     case 2:
                     crossFader();
                     break;
                     
                     case 3:
                     colorOn();
                     break;
                     
                     case 4:
                     colorYellow();
                     break;
                     
                     case 5:
                     colorAmber();
                     break;
                     
                     case 6:
                     colorRed();
                     break;
                     
                     case 7:
                     colorViolet();
                     break;
                     
                     case 8:
                     colorBlue();
                     break;
                     
                     case 9:
                     colorTeal();
                     break;
                     
                     case 10:
                     colorGreen();
                     break;
                     
                     case 11:
                     colorPink();
                     break;
                 }
}

void colorOn(){
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 200);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Cold White");
  delay(200);
  Serial.print("Color On");
  Serial.println("");
}
void colorRed(){
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Racing Red");
  delay(200);
  Serial.print("Running Red");
  Serial.println("");
}
void colorGreen(){
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Grassy Green");
  delay(200);
  Serial.print("Gia Green");
  Serial.println("");
}
void colorBlue(){
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Blazing Blue");
  delay(200);
  Serial.print("Blue");
  Serial.println("");
}
void colorPink(){
 analogWrite(redPin, 255);
  analogWrite(greenPin, 25);
  analogWrite(bluePin, 45);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Powerful Pink");
  delay(200);
  Serial.print("Power Pink");
  Serial.println("");
  
}  
void colorViolet(){
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Pretty Purple");
  delay(200);
  Serial.print("Purple Nurple");
  Serial.println("");
}
void colorTeal(){
  analogWrite(redPin, 0);
  analogWrite(greenPin, 230);
  analogWrite(bluePin, 230);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Real Teal");
  delay(200);
  Serial.print("Teal");
  Serial.println("");
}

void colorYellow(){
  analogWrite(redPin, 95);
  analogWrite(greenPin, 55);
  analogWrite(bluePin, 0);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Yelling Yellow");
  delay(200);
  Serial.print("Yellow");
  Serial.println("");
}
void colorAmber(){
  analogWrite(redPin, 250);
  analogWrite(greenPin, 50);
  analogWrite(bluePin, 0);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preset:");
  lcd.setCursor(1, 1);
  lcd.print("Awesome Amber");
  delay(200);
  Serial.print("Teal");
  Serial.println("");
}

void manualControl() {
// Read the voltage on each analog pin then scale down to 0-255 and inverting the value for common anode
  currentColorValueRed = (255 - map( analogRead(redPotPin), 0, 1024, 0, 255 ) );
  currentColorValueBlue = (255 - map( analogRead(bluePotPin), 0, 1024, 0, 255 ) );
  currentColorValueGreen = (255 - map( analogRead(greenPotPin), 0, 1024, 0, 255 ) );

// Write the color to each pin using PWM and the value gathered above
  analogWrite(redPin, currentColorValueRed);
  analogWrite(bluePin, currentColorValueBlue);
  analogWrite(greenPin, currentColorValueGreen);

// set the cursor to column 0, line 1
  lcd.setCursor(0, 0);
  lcd.print("Manual:");
  lcd.setCursor(0, 1);
  lcd.print ("Mode  :");

// set the cursor to column 5, line 1
  lcd.setCursor(7, 0);
  lcd.print("R");
  lcd.setCursor(7, 1);
  lcd.print(currentColorValueRed);

// set the cursor to column 11, line 1
  lcd.setCursor(10,0);
  lcd.print("G");
  lcd.setCursor(10, 1);
  lcd.print(currentColorValueGreen);
// set the cursor to column 11, line 1
  lcd.setCursor(13,0);
  lcd.print("B");
  lcd.setCursor(13, 1);
  lcd.print(currentColorValueBlue);
  delay(50);
  lcd.clear();
  
  Serial.print("Manual");
      Serial.println("");
}

void crossFader() {
  
  analogWrite(redPin,255-RedVal);
  analogWrite(bluePin,255-BlueVal);
  analogWrite(greenPin,255-GreenVal);
  
  RedVal =((i<255)*i)+((i>=255)*255)+((i>511)*(512-i))+((i>766)*(i-766))+((i>=1276)*(i-1276))+((i>1530)*(1530-i))+((i>1786)*(1786-i));
  GreenVal =(i<256)*(1)+(i>255)*(i-255)+(i>510)*(510-i)+(i>1020)*(1020-i)+(i>1274)*(i-1274)+(i>1530)*(i-1531)+(i>1785)*(3571-(2*i));
  BlueVal =(i<764)*(1)+(i>765)*(i-765)+(i>1020)*(1020-i)+(i>1786)*(1786-i);

  if(i>2040){
   i = 1;
  }
  
  i++;
    Serial.print("crossFader");
    Serial.println("");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Crossfader:");
  lcd.setCursor(0, 1);
  lcd.print(">--->--->--->--->");
  delay(20);
 }
