#include<DHT.h>
#include<ThingSpeak.h>
#include<ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>

WiFiClientClient;
HTTPClienthttp;
DHTdht(D1,DHT11);

Intfield1=1;
Intfield2=2;
Intfield3=3;
Intfield6=6;
Intctr1=0;
Intctr2=0;
Intctr3=0;
Intctr4=0;
StringcommandID;
Stringresult;
Stringresponse;
String
url=http://api.thingspeak.com/update?api_key=6UPLE80J6C5EV9LA&fie
ld;
StringurL;

urL=”http://api.thingspeak.com/talkbacks/44825/commands/26209469.
json?api_key=RFGE9MLL0NI0YJF5”;

voidconnectToWiFi(void);

voidsetup(){
Serial.begin(9600);
pinMode(D2,OUTPUT);//sumersiblepump
pinMode(D3,OUTPUT);//currentfencingunit
pinMode(D4,OUTPUT);//sirenunit
pinMode(D5,OUTPUT);//indicatorlightonoroff

connectToWiFi();

delay(200);
dht.begin();
delay(1000);

}

Voidloop(){
StringcommandID=GET_command();
Serial.println(commandID);
If(commandID==”L1”){
Ctr2=1;
Ctr3=1;

digitalWrite(D5,LOW);//INDICATINGSYSTEMISON
TEMP_HUMD();
}

If(commandID==”L2”){
Ctr1=1;
Ctr3=1;
digitalWrite(D5,LOW);//INDICATINGSYSTEMISON
wateringSystem();//wateringsystem
}

Elseif(commandID==”L3”){
Ctr1=1;
Ctr2=1;
digitalWrite(D5,LOW);//INDICATINGSYSTEMISON
currentFencing();//fencingunit
}

Else{
Serial.println(“######systemiscurrentlyoff######”);
Serial.println(“####stationiswaitingforcommand#####”);
Ctr1=1;
Ctr2=1;
Ctr3=1;
digitalWrite(D2,LOW);
digitalWrite(D3,LOW);

digitalWrite(D4,LOW);
digitalWrite(D5,high);//indicatingsystemisoff
delay(30000);
}
}

VoidTEMP_HUMD(){
intx=0;
digitalWrite(D3,LOW);
digitalWrite(D4,LOW);
digitalWrite(D2,LOW);
intfield1=1;
intfield2=2;
floath=dht.readHumidity();
floatt=dht.readTemperature();
Serial.println(“HUMIDITY:”+(String)h);
Serial.println(“TEMPERATURE:”+(String)t);
X=GET_request(field2,t);
If(x>0){
Serial.println(“*****tempraturedatasenntsuccusesfully”);
For(ctr1;ctr1<2;ctr1++){
Intfield5=5;
floatconfoData1=10;
GET_request(field5,confoData1);
Delay(500);
}
}

Else{Serial.println(“!!!!!errorinsendingtemp.data”);
}
Delay(1000);
}

VoidwateringSystem(){
inty=0;intfield3=3;
floatsoil_data;
digitalWrite(D3,LOW);
digitalWrite(D4,LOW);
digitalWrite(D2,HIGH);
soil_data=analogRead(A0);
delay(200);
y=GET_request(field3,soil_data);
delay(100);
if(y>0){
Serial.println(“*****soildatasentsuccesfully”);
Delay(3000);
For(ctr2;ctr2<2;ctr2++){
Intfield6=6;
floatconfoData2=50;
GET_request(field6,confoData2);
Delay(500);
}
}

Else{
Serial.println(“!!!!!errorinsendingthesoildata”);
}
Delay(1000);
}

VoidcurrentFencing(){
digitalWrite(D2,LOW);
digitalWrite(D3,HIGH);
digitalWrite(D4,HIGH);
for(ctr3;ctr3<2;ctr3++){
intfield6=6;
floatconfoData3=100;
GET_request(field6,confoData3);
}

Delay(1000);
}
StringGET_command(){
Inthttpcode;
Intindex_start;
http.begin(Client,urL);
httpcode=http.GET();
if(httpcode>0){
Serial.println(“datafromtalkbackreadedsuccesfully”);
Response=http.getString();
Serial.println(response);

Intindex_start=response.indexOf(“command_string\”:\””)+17;
Result=response.substring(index_start,index_start+2);
}

Else{
Serial.println(“failedtoconnecttoserver”);
}
http.end();
returnresult;
}
IntGET_request(intfldno,floatdata){
Inthttpcode1;
Intg;
url=url+fldno;
url=url+”=”;
url=url+data;
http.begin(Client,url);
Serial.println(“watingforresponse”);
Httpcode1=http.GET();
If(httpcode1>0){
G=1;
Serial.println(“GETreq.datasentsuccesfuly”);
}
Else{
G=0;
Serial.println(“errorinGETreq.updatedatamsg”);

}
http.end();
returng;
delay(1000);
}
VoidconnectToWiFi(){
WiFi.mode(WIFI_STA);
WiFi.begin(“shubham”,”87654321”);
Serial.println(“connectingtowifi”);
While(WiFi.status()!=WL_CONNECTED){
Serial.println(“.....searchingforinternet”);
}
Serial.println();
Serial.println(“nodemcuisconnectedtointernetsuccsesfully”);
Serial.println(WiFi.localIP());
Delay(1000);
}
