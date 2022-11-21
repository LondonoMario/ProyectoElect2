// Illumination system
int Button = 2;
int Button2 = 3;
int Button3 = 4;
int Button4 = 5;
boolean ButtonPressed = false;
boolean ButtonPressed2 = false;
boolean ButtonPressed3 = false;
boolean ButtonPressed4 = false;
int led = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
boolean Toggle = false;
boolean Toggle2 = false;
boolean Toggle3 = false;
boolean Toggle4 = false;
int Debounce = 0;
int Debounce2 = 0;
int Debounce3 = 0;
int Debounce4 = 0;

String b1 = "O";
String b2 = "O";
String b3 = "O";
String b4 = "O";

// **

//Temperature
const int sensorPin = A0;
const int sensorPin2 = A1;
int buzzer = 9;
float celsius,celsius2;
int count=0;
// Display
#include "U8glib.h"
U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE);

//**

void setup() {

  //Illumantion
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(Button, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
// **
//Temperature
  pinMode(buzzer, OUTPUT);

}

void loop() {
// Illumination
  illumination();

//Temperature

count++;
if (count==30){
  temperature();
  count=0;
}
  
// Display
    oled.firstPage();
  do {
    page1();
  } while (oled.nextPage() );



}

float temperature(){
  int value = analogRead(sensorPin);
  int value2 = analogRead(sensorPin2);
  float millivolts = (value / 1023.0) * 5000;
  float millivolts2 = (value2 / 1023.0) * 5000;
  //float celsius = millivolts / 10;
  celsius = millivolts / 10; 
  //float celsius2 = millivolts2 / 10;
  celsius2 = millivolts2 / 10;
  //delay(1000);
  if (celsius >= 40 || celsius2 >=40){
    digitalWrite(buzzer, HIGH);

  }else{
    digitalWrite(buzzer, LOW);
  }

}

void illumination(){

  if (digitalRead(Button)==HIGH){
    Debounce++;
  }else{
    Debounce = 0;
    ButtonPressed = false;
    Toggle = false;
  }

  if(Debounce >= 2){ // How long I have to wait
    ButtonPressed = true;
  }

  if (ButtonPressed == true && Toggle == false){
    Toggle = true;
    digitalWrite(led, !digitalRead(led));
    if (digitalRead(led) == HIGH){
      b1 = "ON";
    }else{
      b1 = "OFF";
    }
  }
  // Button 1

  if (digitalRead(Button2)==HIGH){
    Debounce2++;
  }else{
    Debounce2 = 0;
    ButtonPressed2 = false;
    Toggle2 = false;
  }

  if(Debounce2 >= 2){ // How long I have to wait
    ButtonPressed2 = true;
  }

  if (ButtonPressed2 == true && Toggle2 == false){
    Toggle2 = true;
    digitalWrite(led2, !digitalRead(led2));
    if (digitalRead(led2) == HIGH){
      b2 = "ON";
    }else{
      b2 = "OFF";
    }
  }
  // Button 2

  if (digitalRead(Button3)==HIGH){
    Debounce3++;
  }else{
    Debounce3 = 0;
    ButtonPressed3 = false;
    Toggle3 = false;
  }

  if(Debounce3 >= 2){ // How long I have to wait
    ButtonPressed3 = true;
  }

  if (ButtonPressed3 == true && Toggle3 == false){
    Toggle3 = true;
    digitalWrite(led3, !digitalRead(led3));
    if (digitalRead(led3) == HIGH){
      b3 = "ON";
    }else{
      b3 = "OFF";
    }
  }
  // Button 3

    if (digitalRead(Button4)==HIGH){
    Debounce4++;
  }else{
    Debounce4 = 0;
    ButtonPressed4 = false;
    Toggle4 = false;
  }

  if(Debounce4 >= 2){ // How long I have to wait
    ButtonPressed4 = true;
  }

  if (ButtonPressed4 == true && Toggle4 == false){
    Toggle4 = true;
    digitalWrite(led4, !digitalRead(led4));
    if (digitalRead(led4) == HIGH){
      b4 = "ON";
    }else{
      b4 = "OFF";
    }
    
  }
  // Button 4
//***
}

// Display 
void page1(void) {
  oled.setFont(u8g_font_profont12);
  oled.setPrintPos(0, 10);
  oled.print((String) "Temperatura 1: " + celsius);
  oled.setPrintPos(0, 25);
  oled.print((String) "Temperatura 2: " + celsius2);
  oled.setPrintPos(0, 40);
  oled.print((String)"Btn 1:" + b1 +" Btn 2:"+ b2);
  oled.setPrintPos(0, 55);
  oled.print((String)"Btn 3:" + b3 + " Btn 3:" + b4);
}


