# IoT based Agriculture Automation system

This project presents a smart agriculture and security system implemented using an ESP8266 (NodeMCU) microcontroller and various sensors. The system is designed to monitor environmental conditions in agricultural settings, automate irrigation based on soil moisture levels, and enhance security through a current fencing unit. The project leverages the capabilities of the ThingSpeak platform for data logging and remote command execution.

ESP8266 (NodeMCU) is connected to the internet via the ESP-12F WIFI module present inside the MCU. It is interfaced with different sensors, such as the DHT11 sensor, for sensing the temperature and humidity of farmland. There are also different units interfaced with the MCU, such as the current fencing unit and the water supply pump motor.

# Working Methodology of the Project

The IFTTT Android Application installed on the farmers mobile will make the HTTP request to the ThingSpeak Server for specified audio command. when such audio command is executed  using Google Assistance, WEBHOOCK inside IFTTT app triggers the HTTP request this request updates the talkback command of the thingspeak talkback services. MCU is constantally fetching this commands from   










# Software
![Static Badge](https://img.shields.io/badge/ThingSpeak-green)![Static Badge](https://img.shields.io/badge/IFTTT-violet)![Static Badge](https://img.shields.io/badge/Google_Assistance-red)![Static Badge](https://img.shields.io/badge/Arduino_IDE-blue)![Static Badge](https://img.shields.io/badge/Postman-orange)



# Hardware
  
  ![Static Badge](https://img.shields.io/badge/ESP8266-blue)![Static Badge](https://img.shields.io/badge/DHT11-red)![Static Badge](https://img.shields.io/badge/Current_Fencing_Unit-yellow)



