# Iot-based-smart-agriculture-automation
its a embedded system project based on the idea of monitoring and controlling the basic farm activities over the internet. 

in these project the esp developent board is used specifically esp8266 a micrococontroller from expresife technologies which is integtrated with the wifi module that can be programed to provide the internet connectivity. sensors are interfaced with the controller module to collect the data of the farm  such as  dht11 temprature and humidity sensor rain sensor and these data is then sends to the thingspeak server using the rest api's then after further processing at the server side the server is program to take decision depending upon the result from the processing such as sending the alert message to the farmer via ifttt iot servises or to make any system on or off.
the farmer can make request to the server using the IFTTT application to controll the farm motors and other stuff's such as the fencing unit and sound system unit to protect the yield crops from the wild animals.

Hardware: ESP8266, temprature and humidity sensor, relay switches, indicator led's

Software: Arduino ide, IFTTT, thingspeak, postman api

