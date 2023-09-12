
#include <ESP8266WiFi.h>
#include <ModbusMaster.h>
#include <FirebaseESP8266.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "DHT.h"

#define errorled 15
#define wifiled 14
#define powerled 2
#define  rs485led 13


///////////////////////////////////////////////////////Setup Modbus  identities//////////////////////////////////////////////////////////////////////////////////////////

#define MAX485_RE_NEG  12  
ModbusMaster node;



  int D120;



///////////////////////////////////////////////////////WiFi  identities////////////////////////////////////////////////////////////////////////////////////////////////

const char*  ssid  = "ofis";
const char* password = "kas*kkw-1970.";
unsigned long wifiledtimer;


/////////////////////////////////////////////////////// Setup Firebase identities/////////////////////////////////////////////////////////////////////////////////


#define API_KEY "AIzaSyDJbyKN_HLa4s__qa2-GS8tFjPOWBbyEc0"
#define DATABASE_URL "https://kasiiot-default-rtdb.firebaseio.com/" 
#define USER_EMAIL "esp82661@gmail.com"
#define USER_PASSWORD "esp82661"
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
String uid;

unsigned long firebasetimer;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

String currentHour;
String currentMinute;
String monthDay;
String currentMonth;
String currentYear;
String currentSecond;



unsigned long listentimer;
unsigned long modbustimer;



///////////////////////////////////////////////////////Temperature Sensor////////////////////////////////////////////////////////////////////////////////////////////////

#define DHTPIN 0
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float h;
float t;

void setup() {
    pinMode(errorled,OUTPUT);
  digitalWrite(errorled,LOW);
    pinMode(wifiled,OUTPUT);
  digitalWrite(wifiled,LOW);
    pinMode(powerled,OUTPUT);
  digitalWrite(powerled,HIGH);
    pinMode(rs485led,OUTPUT);
  digitalWrite(rs485led,LOW);
  Serial.begin(38400);
  setup_modbus();
  setup_wifi();
  setup_firebase();




  // Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(0);

  dht.begin();

}

void loop() {


/*
  if(millis() - firebasetimer > 7200000){
  Firebase.begin(&config, &auth);
  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.print(uid);

    firebasetimer = millis();
  }

*/

while (WiFi.status() != WL_CONNECTED) {

digitalWrite(errorled, HIGH);
if(millis() - wifiledtimer > 0 and  millis() - wifiledtimer < 1000 ){digitalWrite(wifiled ,HIGH);}
else if(millis() - wifiledtimer >= 1000 and  millis() - wifiledtimer <= 2000 ){digitalWrite(wifiled , LOW);}
delay(500);
if(millis() - wifiledtimer > 2000) {wifiledtimer = millis();}

}


digitalWrite(wifiled ,HIGH);


   ///////////////////////////////////////////////////////10 SN de bir Modbus üzerinden PLC' yi Dinle////////////////////////////////////////////
if(millis() - listentimer > 10000){
  digitalWrite(rs485led, HIGH);
get_testvalues();
delay(50);
listentimer = millis();
digitalWrite(rs485led, LOW);
}
}
