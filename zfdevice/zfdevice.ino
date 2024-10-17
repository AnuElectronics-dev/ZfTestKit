#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int sensorPin = A0;   // select the input pin for the potentiometer
int sensorPin1 = A1;   // select the input pin for the potentiometer
int sensorPin2 = A2;   // select the input pin for the potentiometer
int BuzzerPin = 7;      // select the pin for the buzzer
int GreenLedPin = 6;
int RedLedPin = 5;
float sensorValue = 0;  // variable to store the value coming from the sensor
//y=-0.2138x+123.46
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(BuzzerPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);
  pinMode(RedLedPin, OUTPUT);
  Serial.begin(9600);
  // initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Clear the buffer.
  display.clearDisplay();
  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(3);
  display.println("ZF-Rane");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  Serial.print("Sensor1 :");
  Serial.println(analogRead(sensorPin));
  Serial.print("Sensor2 :");
  Serial.println(analogRead(sensorPin1));
  Serial.print("Sensor3 :");
  Serial.println(analogRead(sensorPin2));
  if(analogRead(sensorPin) < 565)
  {
  sensorValue = analogRead(sensorPin);
  sensorValue=(-0.2138*sensorValue)+123.46;
  Serial.print("Sensor  cal :");
  Serial.println(sensorValue-2);
  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(4);
  if(sensorValue < 0 || sensorValue > 20)
  {
    sensorValue = 0.0;
  }else{
    sensorValue = sensorValue;// - 2;
  }
  if(sensorValue > 12 && sensorValue < 15)
  {
    digitalWrite(BuzzerPin, HIGH);
    digitalWrite(GreenLedPin, HIGH);
    digitalWrite(RedLedPin, LOW);
  }else{
    digitalWrite(BuzzerPin, LOW);
    digitalWrite(GreenLedPin, LOW);
    digitalWrite(RedLedPin, HIGH);
  }
  display.println(sensorValue);
  display.display();
  delay(2000);
  display.clearDisplay();
  }
  else if(analogRead(sensorPin1) < 565)
  {
  sensorValue = analogRead(sensorPin1);
  sensorValue=(-0.2138*sensorValue)+123.46;
  Serial.print("Sensor 1 cal :");
  Serial.println(sensorValue-2);
  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(4);
  if(sensorValue < 0 || sensorValue > 20)
  {
    sensorValue = 0.0;
  }else{
    sensorValue = sensorValue;// - 2;
  }
  if(sensorValue > 12 && sensorValue < 15)
  {
    digitalWrite(BuzzerPin, HIGH);
    digitalWrite(GreenLedPin, HIGH);
    digitalWrite(RedLedPin, LOW);
  }else{
    digitalWrite(BuzzerPin, LOW);
    digitalWrite(GreenLedPin, LOW);
    digitalWrite(RedLedPin, HIGH);
  }
  display.println(sensorValue);
  display.display();
  delay(2000);
  display.clearDisplay();
  }
  else if(analogRead(sensorPin2) < 565)
  {
  sensorValue = analogRead(sensorPin2);
  sensorValue=(-0.2138*sensorValue)+123.46;
  Serial.print("Sensor 2 cal :");
  Serial.println(sensorValue-2);
  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(4);
  if(sensorValue < 0 || sensorValue > 20)
  {
    sensorValue = 0.0;
  }else{
    sensorValue = sensorValue;// - 2;
  }
  if(sensorValue > 12 && sensorValue < 15)
  {
    digitalWrite(BuzzerPin, HIGH);
    digitalWrite(GreenLedPin, HIGH);
    digitalWrite(RedLedPin, LOW);
  }else{
    digitalWrite(BuzzerPin, LOW);
    digitalWrite(GreenLedPin, LOW);
    digitalWrite(RedLedPin, HIGH);
  }
  display.println(sensorValue);
  display.display();
  delay(2000);
  display.clearDisplay();
  }
  else{
  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(4);
  display.println(0.00);
  display.display();
  delay(2000);
  display.clearDisplay();
  }
}
