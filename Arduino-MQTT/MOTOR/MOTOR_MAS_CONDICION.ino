#define posicion_manzana 0
#define posicion_naranja 120
#define posicion_pera 240

int GradoActual = 0;
int GradoDeseado = 0;

const int P_Step = 19;
const int P_Dir = 18;
const int led_estado = 5;

void setup() {
  pinMode(P_Step, OUTPUT);
  pinMode(P_Dir, OUTPUT);
  pinMode(led_estado, OUTPUT);
  digitalWrite(led_estado, 1);
  Serial.begin(9600);
}

void loop() {
  DetectarMensaje();
  ActualizarPosionMotores();
}

void ActualizarPosionMotores() {

  Serial.print(GradoActual);
  Serial.print("-");
  Serial.print(GradoDeseado);
  Serial.println();
  if (GradoActual < GradoDeseado) {
    SubirGrado();
  }
  else if ( GradoActual > GradoDeseado) {
    BajarGrado();
  }

}

void SubirGrado() {
  Serial.println("Moviendo Abajo");
  GradoActual++;
}

void BajarGrado() {
  Serial.println("Moviendo Abajo");
  GradoActual--;
}

void DetectarMensaje() {
  if (Serial.available()) {
    char Letra = Serial.read();
    digitalWrite(led_estado, 0);
    if (Letra == 'M') {
      GradoDeseado = posicion_manzana;
      Serial.println("Cambiando a Manzana");
    } else if (Letra == 'J') {
      GradoDeseado = posicion_naranja;
      Serial.println("Cambiando a Naranja");
    } else if (Letra == 'P') {
      GradoDeseado = posicion_pera;
      Serial.println("Cambiando a Pera");
    }
    digitalWrite(led_estado, 1);
  }
}
