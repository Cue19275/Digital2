  int cont = 0;
  int cont2 = 0;
  int sw = 0;
  String lectura;
  char tiempo[17];
  char tiempo2[17];
  String fecha;
  String basura;
  String hora;
  String fecha2;
  char sep [] = " ";
  char *ptr;
  char *ptr2;
  int bandLED = 0;
  #include "config.h"
  
  AdafruitIO_Feed *serialm = io.feed("serialm");
  AdafruitIO_Feed *serialh = io.feed("serialh");
  AdafruitIO_Feed *sld = io.feed("sld");
  
void setup(){
  Serial.begin(9600); //Inicio la comunicación serial con la compu, este seria el Serial 0 de mi ESP
                      //El único argumento de la función es el baudrate que quiero usar
  Serial2.begin(9600, SERIAL_8N1, 16, 17); //Estoy activando el pin 16 y 17 para usar su función serial
                                               //Los argumentos son baudrate, protocolo y pines.
 io.connect();
  sld->onMessage(handleMessage);
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
}
sld->get();
}

void loop(){
  io.run();
  Serial2.write(1);
  if(Serial2.available()>0){ //Aquí digo que cuando el buffer del puerto serial tenga almacenada alguna cantidad de bytes
                               //Se procede a hacer la lectura del puerto
    /*Serial.print(char(Serial2.read())); //Se leen los bytes del puerto serial en forma de char, luego se imprimen en el monitor
       
    tiempo[cont]= Serial2.read();
    cont++;*/
    
    
    Serial2.readBytesUntil(10, tiempo, 17);


    Serial2.write(0);
    
   

  }
  

  //sscanf(tiempo, "%s %s", basura, hora);
  ptr = strtok(tiempo, sep);
  fecha2 = ptr;
  ptr2 = strtok(NULL, sep);
  hora = ptr2;
  Serial.println(fecha2);
  Serial.println(hora);
  Serial.println(bandLED);
  Serial2.write(bandLED);

if (hora != NULL){
    serialm->save(hora);
}
if (fecha2 != NULL){
    serialh->save(fecha2);
}
    delay(4000);
    
 
}
void handleMessage(AdafruitIO_Data *data) {

  sw = data->toInt();
  switch (sw){
    case 0:
    bandLED = 2;
    break;
    case 1:
    bandLED = 3;
    break;
    case 2:
    bandLED = 4;
    break;
    case 3:
    bandLED = 5;
    break;
  }

}
