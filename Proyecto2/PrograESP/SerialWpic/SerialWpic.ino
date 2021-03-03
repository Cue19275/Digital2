  int cont = 0;
  int cont2 = 0;
  String lectura;
  char tiempo[17];
  int bandada = 0;
  #include "config.h"
  AdafruitIO_Feed *serialm = io.feed("serialm");
  
void setup(){
  Serial.begin(9600); //Inicio la comunicación serial con la compu, este seria el Serial 0 de mi ESP
                      //El único argumento de la función es el baudrate que quiero usar
  Serial2.begin(9600, SERIAL_8N1, 16, 17); //Estoy activando el pin 16 y 17 para usar su función serial
                                               //Los argumentos son baudrate, protocolo y pines.
 io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
}
}

void loop(){
  io.run();

  if(Serial2.available()>0){ //Aquí digo que cuando el buffer del puerto serial tenga almacenada alguna cantidad de bytes
                               //Se procede a hacer la lectura del puerto
    /*Serial.print(char(Serial2.read())); //Se leen los bytes del puerto serial en forma de char, luego se imprimen en el monitor
       
    tiempo[cont]= Serial2.read();
    cont++;*/
    Serial2.readBytesUntil(10, tiempo, 17);
    Serial.println(tiempo);

  }
  /*
  if (cont == 18){
    cont = 0;
    cont2++;
    Serial.print(tiempo[0]);
    Serial.print(tiempo[1]);
    Serial.print(tiempo[2]);
    Serial.print(tiempo[3]);
    Serial.print(tiempo[4]);
    Serial.print(tiempo[5]);
    Serial.print(tiempo[6]);
    Serial.print(tiempo[7]);
    Serial.print(tiempo[8]);
    Serial.print(tiempo[9]);
    Serial.print(tiempo[10]);
    Serial.print(tiempo[11]);
    Serial.print(tiempo[12]);
    Serial.print(tiempo[13]);
    Serial.print(tiempo[14]);
    Serial.print(tiempo[15]);
    Serial.print(tiempo[16]);
    Serial.print(tiempo[17]);

  }*/
  
  /*if (tiempo[17) == 13){
   cont = 0;
   for (int i = 0; i <=17; i++){
    Serial.print(char(Serial2.read()));
   }
  }*/
  

    serialm->save(tiempo);
    delay(3000);
 
}
