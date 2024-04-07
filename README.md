# HackOMania2024

Smart Power Monitoring for Residential Flats

## Introduction

The Smart Power Monitoring for Residential Flats (SPRF) is an IoT project aimed at providing real-time insights into the power usage of residential flats. By leveraging advanced IoT sensors and a robust backend infrastructure, SPCM enables residents to monitor their power consumption patterns, identify potential savings and perform preventive maintenance.

### Qualitative data
Real-time Power Consumption Tracking: Get instant readings of your power usage. Useful for troubleshooting and improving user understanding of power usage.

Historical Data Analysis: Review past consumption patterns for better insight and decision-making. SP group will obtain valuable data which can be used to analyse resident behavior and push relavent cost saving strategies.

Alerts and Notifications: Set custom alerts for unusual power usage. Show users if there are likely faults or devices with below expected performance.

Easy Integration: Easy to implement and manage during or after renovations.

## Getting Started
Prerequisites:
1) Non-invasive current sensor(s) compatible with SPCM. We are using SEN0211.
2) A esp32 or any IoT gateway compatible with ThingSpeak and your current sensor.
3) Internet connection.
4) Arduino IDE V2

### Installation
Set up your IoT sensors:

For the SEN0211, the data pin (blue) and Vin (red) is connected to GPIO13 and 5V respectively.
    
    git clone https://github.com/kingster121/unbreakable
    

### Install dependencies
Libraries are installed from the Arduino IDE library manager. The libraries used in this project are:

ThingSpeak

Wifi
        
## Usage
Flash the esp32 with kris_LED.ino and clamp the current sensor around the live wire of the AC circuit you want to measure. Data from the esp32 will be streamed via UART at a baudrate of 115209.

## Data Visualiztion:
This implementation uses the ThingSpeak platform, which is based on MQTT backend, to publish data to a dashboard. It can be accessed here:
https://thingspeak.com/channels/public?username=mwa0000033618310
