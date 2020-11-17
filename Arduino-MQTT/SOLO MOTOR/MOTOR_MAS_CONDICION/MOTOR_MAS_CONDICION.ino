#define STEP 19      // pin STEP de A4988 a pin 4
#define DIR 18     // pin DIR de A4988 a pin 5
void setup() {
pinMode(STEP, OUTPUT);  // pin 4 como salida
pinMode(DIR, OUTPUT);   // pin 5 como salida
Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char Letra = Serial.read();
    if (Letra == 'M') { // MANZANA
      digitalWrite(DIR, HIGH);    // giro en un sentido
      for(int i = 0; i < 66; i++){     
      digitalWrite(STEP, HIGH);       // nivel alto
      delay(10);           //por 10 mseg
      digitalWrite(STEP, LOW);        // nivel bajo
      delay(10);          // por 10 mseg
    }
      delay(1000);          // demora de 2 segundos

       digitalWrite(DIR, LOW);     // giro en sentido opuesto
     for(int i = 0; i < 66; i++){
       digitalWrite(STEP, HIGH); 
       delay(10);
       digitalWrite(STEP, LOW);
       delay(10);
    }
      //delay(2000);
    }
    else if (Letra == 'J') { // NARANJA
      digitalWrite(DIR, HIGH);    // giro en un sentido
      for(int i = 0; i < 132; i++){     
      digitalWrite(STEP, HIGH);       // nivel alto
     // delay(10);          // por 10 mseg
      digitalWrite(STEP, LOW);        // nivel bajo
     // delay(10);          // por 10 mseg
    }
      //delay(2000);          // demora de 2 segundos

      //digitalWrite(DIR, LOW);     // giro en sentido opuesto
      //for(int i = 0; i < 132; i++){
       //digitalWrite(STEP, HIGH); 
       //delay(10);
       //digitalWrite(STEP, LOW);
       //delay(10);
    //}
      //delay(2000);
    }else if (Letra == 'P') { // PERA
     digitalWrite(DIR, HIGH);    // giro en un sentido
      for(int i = 0; i < 198; i++){     
      digitalWrite(STEP, HIGH);       // nivel alto
      delay(10);          // por 10 mseg
      digitalWrite(STEP, LOW);        // nivel bajo
      delay(10);          // por 10 mseg
    }
      delay(2000);          // demora de 2 segundos

      digitalWrite(DIR, LOW);     // giro en sentido opuesto
      for(int i = 0; i < 198; i++){
       digitalWrite(STEP, HIGH); 
       delay(10);
       digitalWrite(STEP, LOW);
       delay(10);
    }
      delay(2000);
    }else if (Letra == 'N') { //NADA
      //digitalWrite(DIR, HIGH);    // giro en un sentido
      //for(int i = 0; i < 200; i++){     
      //digitalWrite(STEP, HIGH);       // nivel alto
      //delay(10);          // por 10 mseg
      //digitalWrite(STEP, LOW);        // nivel bajo
      //delay(10);          // por 10 mseg
   // }
     // delay(2000);          // demora de 2 segundos

     digitalWrite(DIR, LOW);     // giro en sentido opuesto
     // for(int i = 0; i < 66; i++){
      // digitalWrite(STEP, HIGH); 
       //delay(10);
       digitalWrite(STEP, LOW);
       //delay(10);
    }
      delay(100);
    }
  }
//}
