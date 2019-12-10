char lettera;
int statoEntrata = 0;
int  statoCucina = 0;
int  statoStanza = 0;
int statoSoffitta = 0;
int statoStudio = 0;

const int pinSoffitta = 9;
const int pinStanza = 12;
const int pinEntrata = 10;
const int pinStudio = 11;
const int pinCucina = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinEntrata, OUTPUT);    digitalWrite(pinEntrata, LOW);
  pinMode(pinCucina, OUTPUT);     digitalWrite(pinCucina, LOW);
  pinMode(pinStanza, OUTPUT);     digitalWrite(pinStanza, LOW);
  pinMode(pinSoffitta, OUTPUT);   digitalWrite(pinSoffitta, LOW);
  pinMode(pinStudio, OUTPUT);     digitalWrite(pinStudio, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available() > 0) {
    lettera = Serial.read();
    Serial.println(lettera);
    Serial.println("Entrata: " + (String)statoEntrata);
    Serial.println("Cucina: " + (String)statoCucina);
    Serial.println("Stanza: " + (String)statoStanza);
    Serial.println("soffitta: " + (String)statoSoffitta);
    Serial.println("Studio: " + (String)statoStudio);
  }

  if (lettera == 'A') {
    lettera=' ';
    if (statoEntrata == 0) {
      digitalWrite(pinEntrata, HIGH);
      statoEntrata = 1;
      Serial.println("Entrata: " + (String)statoEntrata);
    } else {
      digitalWrite(pinEntrata, LOW);
      statoEntrata = 0;
      Serial.println("Entrata: " + (String)statoEntrata);
    }
    Serial.flush();
  }



  if (lettera == 'B') {
    lettera=' ';
    if (statoCucina == 0) {
      digitalWrite(pinCucina, HIGH);
      statoCucina = 1;
    } else {
      digitalWrite(pinCucina, LOW);
      statoCucina = 0;

    }
    Serial.flush();
  }


  if (lettera == 'C') {
    lettera=' ';
    if (statoStanza == 0) {
      digitalWrite(pinStanza, HIGH);
      statoStanza = 1;
    }

    else {
      digitalWrite(pinStanza, LOW);
      statoStanza = 0;
    }
    Serial.flush();
  }


  if (lettera == 'D') {
    lettera=' ';
    if (statoSoffitta == 0) {
      digitalWrite(pinSoffitta, HIGH);
      statoSoffitta = 1;
    } else {
      digitalWrite(pinSoffitta, LOW);
      statoSoffitta = 0;
    }
    Serial.flush();
  }


  if (lettera == 'E') {
    lettera=' ';
    if ( statoStudio == 0) {
      digitalWrite(pinStudio, HIGH);
      statoStudio = 1;
    } else {
      digitalWrite(pinStudio, LOW);
      statoStudio = 0;
    }
    Serial.flush();
  }
}
