# Smart Dustbin Project

## About the Project

This project is an Arduino-based smart dustbin designed to automatically control the lid and monitor the waste level inside the bin.

A push button is used to open the lid. The lid remains open for about 3 seconds and then automatically closes.

An ultrasonic sensor is used to detect the waste level. LEDs and a buzzer indicate the current bin status.

## Features

* Automatic lid opening and closing
* 3-second lid opening time
* Ultrasonic waste-level detection
* Red, yellow, and green LED indicators
* Buzzer alert when the bin is full
* Serial Monitor distance display

## Components Used

* Arduino
* Servo Motor
* Push Button
* Ultrasonic Sensor
* Red LED
* Yellow LED
* Green LED
* Buzzer
* Jumper Wires

## System Working

**Push Button → Servo Motor → Lid Opens → 3 Seconds → Lid Closes**

**Ultrasonic Sensor → Waste Level Detection → LED/Buzzer Indication**

## Bin Status

* 🔴 Red LED + Buzzer → Bin Full
* 🟡 Yellow LED → Bin Almost Full
* 🟢 Green LED → Space Available

## Pin Connections

| Component |
