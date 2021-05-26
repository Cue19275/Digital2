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
  String ptr = "</<!DOCTYPE html>";
ptr+="<html lang=\"en\" dir=\"ltr\">";
ptr+="  <head>";
ptr+="  <script type=\"text/javascript\">";
ptr+="  setTimeout(function(){";
ptr+="     window.location.reload(1);";
ptr+="  }, 5000);";
ptr+="  </script>";

ptr+="    <meta http-equiv=\"refresh\" content=\"10\">";
ptr+="    <meta charset=\"utf-8\">";
ptr+="    <script src=\"script.js\"></script>";
ptr+="    <title>Proyecto Parqueos</title>";
ptr+="";
ptr+="    <style media=\"screen\">";
ptr+="";
ptr+="      body{background-color:black;}";;
ptr+="      h1{";
ptr+="        text-align:center;";
ptr+="        font-size: 50px;";
ptr+="      }";
ptr+="      h1 span{";
ptr+="        background:white;";
ptr+="        color:black<";
ptr+="      }";
ptr+="      .carro1{";
ptr+="        font-size: 100px;";
ptr+="        position: absolute;";
ptr+="        top: 25px;";
ptr+="        left: 30px;";
ptr+="      }";
ptr+="      .carro2{";
ptr+="        font-size: 100px;";
ptr+="        position: absolute;";
ptr+="        top: 25px;";
ptr+="        left: 210px;";
ptr+="      }";
ptr+="      .carro3{";
ptr+="        font-size: 100px;";
ptr+="        position: absolute;";
ptr+="        top: 25px;";
ptr+="        left: 385px;";
ptr+="      }";
ptr+="      .carro4{";
ptr+="        font-size: 100px;";
ptr+="        position: absolute;";
ptr+="        top: 25px;";
ptr+="        left: 560px;";
ptr+="      }";
ptr+="      .flag_parq{";
ptr+="        position:absolute;";
ptr+="        top: 345px;";
ptr+="        left: 255px;";
ptr+="        font-size: 20px;";
ptr+="        font-family: Arial, Helvetica, sans-serif;";
ptr+="        font-weight:bold";
ptr+="      }";
ptr+="      .rectangulo1{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 367px;";
ptr+="        left: 350px;";
ptr+="        transform: rotate(90deg);";
ptr+="      }";
ptr+="      .rectangulo2{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 425px;";
ptr+="        left: 290px;";
ptr+="";
ptr+="      }";
ptr+="      .rectangulo3{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 480px;";
ptr+="        left: 350px;";
ptr+="        transform: rotate(90deg);";
ptr+="      }";
ptr+="      .rectangulo4{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 425px;";
ptr+="        left: 410px;";
ptr+="      }";
ptr+="      .rectangulo5{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 595px;";
ptr+="        left: 350px;";
ptr+="        transform: rotate(90deg);";
ptr+="      }";
ptr+="      .rectangulo6{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 535px;";
ptr+="        left: 290px;";
ptr+="      }";
ptr+="      .rectangulo7{";
ptr+="        height: 100px;";
ptr+="        width: 15px;";
ptr+="        background-color: #990000;";
ptr+="        border-radius: 9999px;";
ptr+="        box-shadow: 0px 0px 25px #990000;";
ptr+="        position: absolute;";
ptr+="        top: 535px;";
ptr+="        left: 410px;";
ptr+="      }";
ptr+="      .fondo_parqueo{";
ptr+="        height:250px;";
ptr+="        width:700px;";
ptr+="        background-color:grey;";
ptr+="        position: absolute;";
ptr+="        top: 90px;";
ptr+="        left: 10px;";
ptr+="        z-index: -1;";
ptr+="      }";
ptr+="      .divisor1_parqueo{";
ptr+="        height:220px;";
ptr+="        width:10px;";
ptr+="        background-color:yellow;";
ptr+="        position: absolute;";
ptr+="        top: 100px;";
ptr+="        left: 185px;";
ptr+="      }";
ptr+="      .divisor2_parqueo{";
ptr+="        height:220px;";
ptr+="        width:10px;";
ptr+="        background-color:yellow;";
ptr+="        position: absolute;";
ptr+="        top: 100px;";
ptr+="        left: 360px;";
ptr+="      }";
ptr+="      .divisor3_parqueo{";
ptr+="        height:220px;";
ptr+="        width:10px;";
ptr+="        background-color:yellow;";
ptr+="        position: absolute;";
ptr+="        top: 100px;";
ptr+="        left: 535px;";
ptr+="      }";
ptr+="    </style>";
ptr+="  </head>";
ptr+="";
ptr+="  <body>";
ptr+="    <h1><span>Parque-o-Matic</span></h1>";
ptr+="    <div class=\"flag_parq\">";
ptr+="      <p style=\"color:white\">Parqueos Disponibles</p>";
ptr+="    </div>";
if(p1==1){
ptr+="    <div class=\"carro1\"><p>&#128664;</p></div>";
}
if(p2==1){
ptr+="    <div class=\"carro2\"><p>&#128664;</p></div>";
}
if(p3==1){
ptr+="    <div class=\"carro3\"><p>&#128664;</p></div>";
}
if(p4==1){
ptr+="    <div class=\"carro4\"><p>&#128664;</p></div>";
}
if(dispo==4){

ptr+="    <div class=\"rectangulo2\"></div>";
ptr+="    <div class=\"rectangulo3\"></div>";
ptr+="    <div class=\"rectangulo4\"></div>";

ptr+="    <div class=\"rectangulo7\"></div>"; 
}
else if(dispo==3){
ptr+="    <div class=\"rectangulo1\"></div>";

ptr+="    <div class=\"rectangulo3\"></div>";
ptr+="    <div class=\"rectangulo4\"></div>";
ptr+="    <div class=\"rectangulo5\"></div>";//Abajo

ptr+="    <div class=\"rectangulo7\"></div>";  
}
else if(dispo==2){
ptr+="    <div class=\"rectangulo1\"></div>";
ptr+="    <div class=\"rectangulo3\"></div>";
ptr+="    <div class=\"rectangulo4\"></div>";
ptr+="    <div class=\"rectangulo5\"></div>";//Abajo
ptr+="    <div class=\"rectangulo6\"></div>";
}
else if(dispo==1){
  ptr+="    <div class=\"rectangulo7\"></div>";
  ptr+="    <div class=\"rectangulo4\"></div>";
}
else if(dispo==0){
  ptr+="    <div class=\"rectangulo1\"></div>";
ptr+="    <div class=\"rectangulo2\"></div>";
ptr+="    <div class=\"rectangulo4\"></div>";
ptr+="    <div class=\"rectangulo5\"></div>";//Abajo
ptr+="    <div class=\"rectangulo6\"></div>";
ptr+="    <div class=\"rectangulo7\"></div>";
}
ptr+="    <div class=\"fondo_parqueo\"></div>";
ptr+="    <div class=\"divisor1_parqueo\"></div>";
ptr+="    <div class=\"divisor2_parqueo\"></div>";
ptr+="    <div class=\"divisor3_parqueo\"></div>";
ptr+="";
ptr+="  </body>";
ptr+="</html>";

  return ptr;
}
