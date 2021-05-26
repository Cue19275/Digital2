#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "Cuellar";  // Enter your SSID here
const char* password = "56328089";  //Enter your Password here
WebServer server(80);
char tiva[4];
int dispo=4;
int p1=0;
int p2=0;
int p3=0;
int p4=0;
void D7SEG(int a);
int trans(char b);
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  Serial.begin(115200);
//EMPIEZA
  Serial.println("Try Connecting to ");
  Serial.println(ssid);
  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);
  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial
  server.on("/", handle_OnConnect); // Directamente desde e.g. 192.168.0.8 
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);  
  pinMode(2, OUTPUT);//C
  pinMode(15, OUTPUT);//D
  pinMode(19, OUTPUT);//E
  pinMode(32, OUTPUT);//B
  pinMode(23, OUTPUT);//G
  pinMode(26, OUTPUT);//F
  pinMode(25, OUTPUT);//A
}

void loop() {
  dispo=4;
  if (Serial2.available() > 0) {
    Serial2.readBytesUntil(10, tiva, 4);
  }
  if(tiva[0]==48){
    p1=0;   
  }
  else{
    p1=1;
    dispo--;
  }
  if(tiva[1]==48){
    p2=0;   
  }
  else{
    p2=1;
    dispo--;
  }
  if(tiva[2]==48){
    p3=0;   
  }
  else{
    p3=1;
    dispo--;
  }
  if(tiva[3]==48){
    p4=0;   
  }
  else{
    p4=1;
    dispo--;
  }    
  D7SEG(dispo);  
  server.handleClient();  
}

void D7SEG(int a) {
  switch (a) {
    case 0:
      digitalWrite(2, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(19, HIGH);
      digitalWrite(32, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(23, LOW);
      break;
    case 1:
      digitalWrite(2, HIGH);
      digitalWrite(32, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(19, LOW);
      digitalWrite(23, LOW);
      digitalWrite(26, LOW);
      digitalWrite(25, LOW);
      break;
    case 2:
      digitalWrite(15, HIGH);
      digitalWrite(19, HIGH);
      digitalWrite(32, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(26, LOW);
      digitalWrite(2, LOW);
      break;
    case 3:
      digitalWrite(2, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(32, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, LOW);
      digitalWrite(19, LOW);
      break;
    case 4:
      digitalWrite(2, HIGH);
      digitalWrite(32, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(25, LOW);
      digitalWrite(19, LOW);
      digitalWrite(15, LOW);
      break;
  }
}
//************************************************************************************************
// Handler de Inicio página
//************************************************************************************************
void handle_OnConnect() {
  Serial.println("GPIO2 Status: OFF");
  server.send(200, "text/html", SendHTML());
}
//************************************************************************************************
// Handler de not found
//************************************************************************************************
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
//************************************************************************************************
// Procesador de HTML
//************************************************************************************************
String SendHTML(void) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #3498db;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server &#128664</h1>\n";
  ptr += "<h3>Ejemplo de Web Server</h3>\n";


    ptr += "<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
 


  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
