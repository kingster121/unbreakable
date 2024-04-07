# HackOMania2024

Smart Power Monitoring for Residential Flats

## Introduction

The Smart Power Monitoring for Residential Flats (SPRF) is an IoT project aimed at providing real-time insights into the power usage of residential flats. By leveraging advanced IoT sensors and a robust backend infrastructure, SPCM enables residents to monitor their power consumption patterns, identify potential savings, perform preventive maintenance and save the environment.
Features

## Qualitative data
Real-time Power Consumption Tracking: Get instant readings of your power usage. Residents can see an immediate feedback to their actions.
Historical Data Analysis: Review past consumption patterns for better insight and decision-making. SP group will obtain valuable data which can be used to analyse resident behavior and push relavent cost saving strategies 
Alerts and Notifications: Set custom alerts for unusual power usage. Show users if there are likely faults or devices with below expected performance.
Easy Integration: Easy to implement and change in case 

## Getting Started
Prerequisites

Non-invasive current sensor(s) compatible with SPCM. We are using SEN0211.
A esp32 or any IoT gateway compatible with ThingSpeak and your current sensor.
Internet connection.
Arduino IDE V2

### Installation

Set up your IoT sensors:
    For the SEN0211, the data pin (blue) is connected to GPIO13. We connect it in parallel to V_{in} (5V) of our esp32. 
