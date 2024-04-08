#include <TM1637Display.h>
#include <cmath>
#include "driver/adc.h"
#include <iostream>
#include <FastLED.h>
#include <WiFi.h>
#include "ThingSpeak.h"

#define LCD_CLK  22 // The ESP32 pin GPIO22 connected to CLK
#define LCD_DIO  23 // The ESP32 pin GPIO23 connected to DIO
#define SENSOR   34 // Pin for the current sensor data

int i;
#define LED_PIN 13
#define NUM_LEDS 0

CRGB leds[NUM_LEDS];
TM1637Display display = TM1637Display(LCD_CLK, LCD_DIO);

const char* ssid = "***";   // your network SSID (name) 
const char* password = "*****";   // your network password
unsigned long myChannelNumber = *****;
const char * myWriteAPIKey = "**********";

// Timer for kWh and cost
float kWh;
float cost;
float totalkWh=0.0;
float totalCost = 0.0;
unsigned long prevTime;
unsigned long currentTime;
int counter = 0;

WiFiClient  client;

float analogToCurrent(int adcReading){
  // Empirical voltage to current calculation
  float current220V = adcReading/125.8250825;
  return current220V;
}

float power(float current220V){
  float watts = current220V * 220;
  float kWh = (watts/1000)/3600;
  return kWh;
}

void setup() {
  Serial.begin(115200);
  display.clear();
  display.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  // LEDs
  for (i = 0; i < NUM_LEDS; i += 1) { // Loop through odd-indexed LEDs only
    FastLED.setBrightness(25);
    leds[i] = CRGB(255, 255, 255); // Set the color for odd-indexed LED
    FastLED.show(); // Show the updated LEDs
  }
  FastLED.clear();
  
  // Setup Wifi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, password); 
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

  ThingSpeak.begin(client);  // Initialize ThingSpeak

  prevTime = millis();
}

void loop() {
  // Data from sensor
  float current220V = analogToCurrent(analogRead(SENSOR));
  Serial.println(current220V);
  display.showNumberDec(round(current220V));
  ThingSpeak.writeField(myChannelNumber, 1, current220V, myWriteAPIKey);

  // Calculations
  currentTime = millis();
  if (currentTime - prevTime < 5000){
    kWh = power(current220V);
    cost = 28.99 * kWh;
    totalkWh += kWh;
    totalCost += cost;
    counter +=1;
  }
  else{
    float averagekWh = totalkWh/counter;
    float averageCost = totalCost/counter;
    ThingSpeak.writeField(myChannelNumber, 2, averagekWh, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 3, averageCost, myWriteAPIKey);

    totalCost = 0;
    totalkWh = 0;
    counter = 0;

    prevTime = currentTime;
  }
}
