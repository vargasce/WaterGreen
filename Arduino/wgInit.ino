#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266Ping.h>
#include "./lib/humidity/humidity.h";

//DEFINO PINES PARA MODULOS DE HUMEDAD, MAXIMO 3.
#define pin_humidity_01 1
#define pin_humidity_02 2
#define pin_humidity_03 3


//INSTANCIA DE HUMEDAD
Humidity humedad01( pin_humidity_01, "Humedad1" );
Humidity humedad02( pin_humidity_02, "Humedad2" );
Humidity humedad03( pin_humidity_03, "Humedad3" );

char *ssid = "Fibertel WiFi149 2.4GHz";
char *pass = "cristianvargas";

//Prototipe function
void sleepTime( int );
void getStatus( int );
int pingRun ( int , int , int , int );
void imprimir( String );
void connectToWifi();
bool verifyConection();

void setup() {
   Serial.begin(115200);
   connectToWifi();
}

void loop() {

   if(verifyConection()){ //VERIFICAMOS CORRECTA CONEXION PARA TRABAJAR

      //verico modulos de humedad conectados.
      if(humedad01.isAlive()){ imprimir("Modulo 1 vivo !!"); }
      if(humedad02.isAlive()){ imprimir("Modulo 2 vivo !!"); }
      if(humedad03.isAlive()){ imprimir("Modulo 3 vivo !!"); }

   }
   
}

/** GETSTATUS
 * @param statusNumber : int => numero de estatus retornado por la conexion.
 */
void getStatus( int statusNumber ){
   switch(statusNumber){
      case WL_CONNECTED :
        imprimir("WL_CONNECTED");
      break;
      case WL_NO_SHIELD :
        imprimir("WL_NO_SHIELD");
      break;
      case WL_IDLE_STATUS :
        imprimir("WL_IDLE_STATUS");
      break;
      case WL_NO_SSID_AVAIL :
        imprimir("WL_NO_SSID_AVAIL");
      break;
      case WL_SCAN_COMPLETED :
        imprimir("WL_SCAN_COMPLETED");
      break;
      case WL_CONNECT_FAILED :
        imprimir("WL_CONNECT_FAILED");    
      break;
      case WL_CONNECTION_LOST :
        imprimir("WL_CONNECTION_LOST"); 
      break;
      case WL_DISCONNECTED :
        imprimir("WL_DISCONNECTED"); 
      break;
   }
}

/** SLEEPTIME
 * @param mil : int => numero en milisegundos para realizar un delay en el loop.
 */
void sleepTime( int mil ){
  delay(mil);
}

/** PINGRUN
 * @param a, b, c, d : int => Numero de ip local para realizar un ping y detectar red.
 * @return ret : Boolean => returna true o false si logra realizar el ping a la ip indicada por parametro
 */
int pingRun ( int a, int b, int c, int d){
  IPAddress ip (a, b, c, d);
  int ret = Ping.ping(ip);
  return ret;
}

/** IMPRIMIR
 * @param menssage : String => mensage a imprimir por la consola
 */
void imprimir( String menssage ){
  Serial.println(menssage);
}

/** CONNECT TO WIFI
* @Observations :
*/
void connectToWifi(){

   WiFi.mode(WIFI_STA);
   sleepTime(10);        

   WiFi.begin(ssid, pass); 

   sleepTime(500);
   
   if (WiFi.status() == WL_NO_SHIELD) {
    imprimir("WiFi shield not present");
    while (true);
   }
   
  while (WiFi.status() != WL_CONNECTED){
    getStatus( WiFi.status() );
    sleepTime(1500);
  }
  
  imprimir("WiFi connected");
  Serial.println(WiFi.localIP());

}


/** VERIFY CONECTION
* @Observations : verifica que haya correcta conexion de red, se peude de alguna
* manera alertar con algun led para saber su estado actual.
*/
bool verifyConection(){
   bool estado = false;

   if(WiFi.status()== WL_CONNECTED){
      if( pingRun( 192, 168,0 ,187 ) > 0){
        imprimir("Logre hacer ping a la pc de escritorio");
      }

      String serverName = "https://httpbin.org/get";

      WiFiClient client;
      HTTPClient http;
   
      http.begin(client, serverName.c_str());
   
      int httpResponseCode = http.GET();
   
      if (httpResponseCode>0) {
         imprimir("HTTP Response code: ");
         Serial.println(httpResponseCode);
         String payload = http.getString();
         imprimir(payload);
      }else {
         imprimir("Error code: ");
         Serial.println(httpResponseCode);
      }

      http.end();

      sleepTime(500);
      estado = true;

   }else {
    imprimir("WiFi Disconnected");    
    estado = false;
   }
   
   return estado;
}
