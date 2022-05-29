#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <SmoothThermistor.h>
#include <SimpleDHT.h>


//conexion de red (WIFI)
const char* ssid = "ceroday";
const char* password = "clavesita";
//ip del servidor al que nos conectaremos
const char* host = "192.168.1.71";
const uint16_t port = 80;
ESP8266WiFiMulti WiFiMulti;

//Variables para thermistor
SmoothThermistor smoothThermistor(A0);
int temt=0;

//Variables para dht11
int pinDHT11 = 4;
SimpleDHT11 dht11(pinDHT11);
int temd, hum; 


void setup(){
  Serial.begin(9600);
  delay(100);
  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
  Serial.println();
  Serial.print("Wait for WiFi... ");
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(500);
  //Para termistor
  smoothThermistor.useAREF(true);
  
  
}

void loop(){
     Serial.println("1");
     WiFiClient client;
     Serial.println("2");
     if (client.connect(host, 80)){ 

       //Para DHT11
        byte temperature = 0;
        byte humidity = 0;
        int err = SimpleDHTErrSuccess;
        if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
          Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
          Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
          return;
        }
         temt=smoothThermistor.temperature();
         temd=((int)temperature);
         hum=((int)humidity);
                    
         Serial.print("DHT11= ");
         Serial.print(temd);
          Serial.print(" *C");
         Serial.print(" = ");
         Serial.print("Thermistor= ");
         Serial.print(temt);
         Serial.print(" *C ");
         Serial.print("Humedad= ");
         Serial.print(hum);
          Serial.println(" %");
       
        client.print(String("GET /dth11/actualizar_temperatura.php?temd=") + temd + "&temt=" + temt + "&hum=" + hum +
        " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n" + "\r\n" );
        client.flush();
     }else{ Serial.println("no conectado");}
     delay(1000);
     
}
