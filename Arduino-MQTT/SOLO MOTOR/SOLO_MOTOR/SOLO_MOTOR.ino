#define STEP 19     // pin STEP de A4988 a pin 4
#define DIR 18     // pin DIR de A4988 a pin 5

void setup() 
{
  pinMode(STEP, OUTPUT);  // pin 4 como salida
  pinMode(DIR, OUTPUT);   // pin 5 como salida
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(DIR, HIGH);    // giro en un sentido
  for(int i = 0; i < 66; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
    digitalWrite(STEP, HIGH);       // nivel alto
    delay(10);          // por 10 mseg
    digitalWrite(STEP, LOW);        // nivel bajo
    delay(10);          // por 10 mseg
  }
  delay(2000);          // demora de 2 segundos

  digitalWrite(DIR, LOW);     // giro en sentido opuesto
  for(int i = 0; i < 66; i++){
    digitalWrite(STEP, HIGH); 
    delay(10);
    digitalWrite(STEP, LOW);
    delay(10);
  }
  delay(2000);          // demora de 2 segundos

digitalWrite(DIR, HIGH);    // giro en un sentido
  for(int i = 0; i < 132 ; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
    digitalWrite(STEP, HIGH);       // nivel alto
    delay(10);          // por 10 mseg
    digitalWrite(STEP, LOW);        // nivel bajo
    delay(10);          // por 10 mseg
  }
  delay(2000);          // demora de 2 segundos

  digitalWrite(DIR, LOW);     // giro en sentido opuesto
  for(int i = 0; i < 132; i++){
    digitalWrite(STEP, HIGH); 
    delay(10);
    digitalWrite(STEP, LOW);
    delay(10);
  }
  delay(2000);          // demora de 2 segundos

digitalWrite(DIR, HIGH);    // giro en un sentido
  for(int i = 0; i < 198; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
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
  delay(2000);          // demora de 2 segundos
}
