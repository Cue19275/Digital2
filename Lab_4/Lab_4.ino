int J1_1 = PB_5;
int J1_2 = PB_0;
int J1_3 = PB_1;
int J1_4 = PE_4;
int J1_5 = PE_5;
int J1_6 = PB_4;
int J1_7 = PA_5;
int J1_8 = PA_6;
int J2_1 = PD_0;
int J2_2 = PD_1;
int J2_3 = PD_2;
int J2_4 = PD_3;
int J2_5 = PE_1;
int J2_6 = PE_2;
int J2_7 = PE_3;
int J2_8 = PD_7;

int   estadoSalida;
int   estado;
int   estadoSalidaC2;
int   estadoC2;
int   enable_J = 0;
int   terminado = 0;
int   flagJ1 = 0;
int   flagJ2 = 0;
int   contaJ1 = 0;
int   contaJ2 = 0;

void semaforo (void);
void cont1 (void);
void cont2 (void);
void ganador (void);
void debounce (void);
void debounce2 (void);
void apagado(void);


void setup() {
  pinMode(J1_1, OUTPUT);
  pinMode(J1_2, OUTPUT);
  pinMode(J1_3, OUTPUT);
  pinMode(J1_4, OUTPUT);
  pinMode(J1_5, OUTPUT);
  pinMode(J1_6, OUTPUT);
  pinMode(J1_7, OUTPUT);
  pinMode(J1_8, OUTPUT);
  pinMode(J2_1, OUTPUT);
  pinMode(J2_2, OUTPUT);
  pinMode(J2_3, OUTPUT);
  pinMode(J2_4, OUTPUT);
  pinMode(J2_5, OUTPUT);
  pinMode(J2_6, OUTPUT);
  pinMode(J2_7, OUTPUT);
  pinMode(J2_8, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if (enable_J ==0){
    semaforo();
  }
  else if (enable_J == 1){
    cont1();
    cont2();
    if (terminado = 1){
      while(1){
             estado = digitalRead(PUSH1);
              if (estado == 1){
                  estadoSalida=1;
              }
              
              if (estadoSalida==1){
                  if (estado == 0){
                      estadoSalida =0;
                      flagJ1 = 1;
                      
                  }
              }
                    estadoC2 = digitalRead(PUSH2);
              if (estadoC2 == 1){
                  estadoSalidaC2=1;
              }
              
              if (estadoSalidaC2==1){
                  if (estadoC2 == 0){
                      estadoSalidaC2 =0;
                      flagJ2 = 1;
                  }
              }
              if (flagJ1 == 1 && flagJ2 == 1){
                flagJ2 = 0;
                flagJ1 = 0;
                enable_J = 0;
                terminado = 0;
                break
              }
      }
    }
  }
}

void semaforo(void){
        estado = digitalRead(PUSH1);
        if (estado == 1){
            estadoSalida=1;
        }
        
        if (estadoSalida==1){
            if (estado == 0){
                estadoSalida =0;
                apagado();
                enable_J = 1;
                digitalWrite(RED_LED, HIGH);
                digitalWrite(GREEN_LED, LOW);
                digitalWrite(BLUE_LED, LOW);
                delay(500);
                digitalWrite(BLUE_LED, LOW);
                digitalWrite(RED_LED, HIGH);
                digitalWrite(GREEN_LED, HIGH);
                delay(500);
                digitalWrite(GREEN_LED, HIGH);
                digitalWrite(RED_LED, LOW);
                digitalWrite(BLUE_LED, LOW);
            }
        }
}

void apagado (void){
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(J1_1, LOW);
  digitalWrite(J1_2, LOW);
  digitalWrite(J1_3, LOW);
  digitalWrite(J1_4, LOW);
  digitalWrite(J1_5, LOW);
  digitalWrite(J1_6, LOW);
  digitalWrite(J1_7, LOW);
  digitalWrite(J1_8, LOW);
  digitalWrite(J2_1, LOW);
  digitalWrite(J2_2, LOW);
  digitalWrite(J2_3, LOW);
  digitalWrite(J2_4, LOW);
  digitalWrite(J2_5, LOW);
  digitalWrite(J2_6, LOW);
  digitalWrite(J2_7, LOW);
  digitalWrite(J2_8, LOW);
  
}

void cont1 (void) {
  estado = digitalRead(PUSH1);
    if (estado == 1){
        estadoSalida=1;
    }
    
    if (estadoSalida==1){
        if (estado == 0){
            estadoSalida =0;
            contaJ1++;
            
        }
    }
}

void cont2 (void) {
        estadoC2 = digitalRead(PUSH2);
    if (estadoC2 == 1){
        estadoSalidaC2=1;
    }
    
    if (estadoSalidaC2==1){
        if (estadoC2 == 0){
            estadoSalidaC2 =0;
            contaJ2++;
            switch(contaJ2){
              case 1:
              digitalWrite(J2_1, HIGH);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, LOW);
              break;
              case 2:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, HIGH);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, LOW);
              break;
              case 3:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, HIGH);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, LOW);
              break;
              case 4:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, HIGH);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, LOW);
              break;
              case 5:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, HIGH);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, LOW);
              break;
              case 6:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, HIGH);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, LOW);
              break;
              case 7:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, HIGH);
              digitalWrite(J2_8, LOW);
              break;
              case 8:
              digitalWrite(J2_1, LOW);
              digitalWrite(J2_2, LOW);
              digitalWrite(J2_3, LOW);
              digitalWrite(J2_4, LOW);
              digitalWrite(J2_5, LOW);
              digitalWrite(J2_6, LOW);
              digitalWrite(J2_7, LOW);
              digitalWrite(J2_8, HIGH);
              contaJ2 = 0;
              terminado = 0;
              
              break;
              
            }
        }
    }
}

void debounce (void){
      estado = digitalRead(PUSH1);
    if (estado == 1){
        estadoSalida=1;
    }
    
    if (estadoSalida==1){
        if (estado == 0){
            estadoSalida =0;
        }
    }
}

void debounce2 (void){
      estadoC2 = digitalRead(PUSH2);
    if (estadoC2 == 1){
        estadoSalidaC2=1;
    }
    
    if (estadoSalidaC2==1){
        if (estadoC2 == 0){
            estadoSalidaC2 =0;
        }
    }
}
