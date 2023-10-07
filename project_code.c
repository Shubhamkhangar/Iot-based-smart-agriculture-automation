/*
author : Shubham Anil Khangar
std    : Third year B.Sc in Electronics Science 
college: fergusson College Pune
date   : 05 jan 2022 
*/


#include<DHT.h>
#include<ThingSpeak.h>
#include<ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>

WiFiClient Client;
HTTPClient http;
DHT dht(D1,DHT11);

int field1=1;
int field2=2;
int field3=3;
int field6=6;
int ctr1=0;
int ctr2=0;
int ctr3=0;
int ctr4=0;
String commandID;
String result;
String response;
String url="http://api.thingspeak.com/update?api_key=6UPLE80J6C5EV9LA&field";
String urL="http://api.thingspeak.com/talkbacks/44825/commands/26209469.json?api_key=RFGE9MLL0NI0YJF5";

void connectToWiFi(void);

void setup()
{
Serial.begin(9600);
pinMode(D2,OUTPUT);//sumersiblepump
pinMode(D3,OUTPUT);//currentfencingunit
pinMode(D4,OUTPUT);//sirenunit
pinMode(D5,OUTPUT);//indicatorlightonoroff
connectToWiFi();   //function to connect to wifi
delay(200);
dht.begin();
delay(1000);
}

void loop()
{
String commandID = GET_command();
Serial.println(commandID);
if(commandID == "L1")
{
ctr2=1;
ctr3=1;
digitalWrite(D5,LOW);//INDICATING SYSTEM IS ON
TEMP_HUMD();
}

else if(commandID == "L2")
{
ctr1=1;
ctr3=1;
digitalWrite(D5,LOW);//INDICATINGSYSTEMISON
wateringSystem();//wateringsystem
}

else if(commandID == "L3")
{
ctr1=1;
ctr2=1;
digitalWrite(D5,LOW);//INDICATING SYSTEM IS ON
currentFencing();//fencing unit
}

else
{
Serial.println("system is currently off");
Serial.println("station is waiting for command");
ctr1=1;
ctr2=1;
ctr3=1;
digitalWrite(D2,LOW);
digitalWrite(D3,LOW);
digitalWrite(D4,LOW);
digitalWrite(D5,HIGH);//indicating system is off
delay(30000);
}

}

void TEMP_HUMD()
{
int x=0;
digitalWrite(D3,LOW);
digitalWrite(D4,LOW);
digitalWrite(D2,LOW);
int field1=1;
int field2=2;
float h=dht.readHumidity();
float t=dht.readTemperature();
Serial.println("HUMIDITY:"+(String)h);
Serial.println("TEMPERATURE:"+(String)t);
x=GET_request(field2,t);
if(x>0){
Serial.println("temprature data sent succusesfully");
for(ctr1;ctr1<2;ctr1++){
int field5=5;
float confoData1=10;
GET_request(field5,confoData1);
delay(500);
}
}
else{Serial.println("errorinsendingtemp.data");
}
delay(1000);
}

void wateringSystem()
{
int y=0; int field3=3;
float soil_data;
digitalWrite(D3,LOW);
digitalWrite(D4,LOW);
digitalWrite(D2,HIGH);
soil_data=analogRead(A0);
delay(200);
y=GET_request(field3,soil_data);
delay(100);
if(y>0){
Serial.println("soildatasentsuccesfully");
delay(3000);
for(ctr2;ctr2<2;ctr2++){
int field6=6;
float confoData2=50;
GET_request(field6,confoData2);
delay(500);
}
}

else{
Serial.println("error in sending the soil data");
}
delay(1000);
}

void currentFencing()
{
digitalWrite(D2,LOW);
digitalWrite(D3,HIGH);
digitalWrite(D4,HIGH);
for(ctr3;ctr3<2;ctr3++){
int field6=6;
float confoData3=100;
GET_request(field6,confoData3);
}
delay(1000);
}

//function to get talkback id
String GET_command()
{
int httpcode;
int index_start;
http.begin(Client,urL);
httpcode=http.GET();
if(httpcode>0){
Serial.println("data from talk back readed succesfully");
response=http.getString();
Serial.println(response);

int index_start=response.indexOf("command_string\":\"")+17;
result=response.substring(index_start,index_start+2);
}

else{
Serial.println("failed to connect to server");
}
http.end();
return result;
}

int GET_request(int fldno,float data){
int httpcode1;
int G;
url=url+fldno;
url=url+"=";
url=url+data;
http.begin(Client,url);
Serial.println("wating for response");
httpcode1=http.GET();
if(httpcode1>0){
G=1;
Serial.println("GETreq. data sent succesfuly");
}
else{
G=0;
Serial.println("error in GETreq. update data");
}
http.end();
return G;
delay(1000);
}

void connectToWiFi(){
WiFi.mode(WIFI_STA);
WiFi.begin("shubham","87654321");
Serial.println("connecting to wifi");
while(WiFi.status()!=WL_CONNECTED){
Serial.println(".....searching for internet");
}
Serial.println();
Serial.println("nodemcu is connected to internet succsesfully");
Serial.println(WiFi.localIP());
delay(1000);
}
