# IoT based Agriculture Automation system

This project presents a smart agriculture and security system implemented using an ESP8266 (NodeMCU) microcontroller and various sensors. The system is designed to monitor environmental conditions in agricultural settings, automate irrigation based on soil moisture levels, and enhance security through a current fencing unit. The project leverages the capabilities of the ThingSpeak platform for data logging and remote command execution.

ESP8266 (NodeMCU) is connected to the internet via the ESP-12F WIFI module present inside the MCU. It is interfaced with different sensors, such as the DHT11 sensor, for sensing the temperature and humidity of farmland. There are also different units interfaced with the MCU, such as the current fencing unit and the water supply pump motor.

# Working Methodology of the Project

The IFTTT Android Application installed on the farmers mobile will make the HTTP request to the ThingSpeak Server for a specified audio command. When such an audio command is executed using Google Assistance, WEBHOOCK inside the IFTTT app triggers an HTTP request. This request updates the talkback command of the Thingspeak talkback services. MCU is constantly fetching these commands from the server by sending an HTTP GET request.

Depending on the command, the MCU performs the tasks of controlling the current fencing and water supply motor units and sending the data to the server. The Thingspeak server is programmed to perform the specific service task whenever any specified condition occurs. specific service, such as HTTPREQUEST, it will make an HTTP request to the IFTTT server, and then the IFTTT server will send the specified message to the Farmers Android application.

These messages give information about the on-off states of the farm's different units and the sensor data.

#Click on below buttons to jump to specific folders where the code are stored.

[![Static Badge](https://img.shields.io/badge/Code-blue)](code.c)



# Software
![Static Badge](https://img.shields.io/badge/ThingSpeak-green)![Static Badge](https://img.shields.io/badge/IFTTT-violet)![Static Badge](https://img.shields.io/badge/Google_Assistance-red)![Static Badge](https://img.shields.io/badge/Arduino_IDE-blue)![Static Badge](https://img.shields.io/badge/Postman-orange)



# Hardware
  
  ![Static Badge](https://img.shields.io/badge/ESP8266-blue)![Static Badge](https://img.shields.io/badge/DHT11-red)![Static Badge](https://img.shields.io/badge/Current_Fencing_Unit-yellow)



