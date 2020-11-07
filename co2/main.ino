#include <SoftwareSerial.h>

SoftwareSerial mySerial(A0, A1); // A0 - к TX сенсора, A1 - к RX

byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
unsigned char response[9];
int pinOffset = 3;
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  int i;
  for (i = 0; i < 5; i++) {
    digitalWrite(i + pinOffset, HIGH);
    if (i == 4) {
      delay(900);
    }
    delay(50);
  }

  for (i = 0; i < 5; i++) {
    digitalWrite(5 - i + pinOffset, LOW);
    delay(50);
  }
}

void setLed(int level) {
  for (int i = 0; i < 5; i++) {
    if (i < level) {
      digitalWrite(i + pinOffset, HIGH);
      Serial.println("Turning ON input:" + String(i + pinOffset));
    }
    else
    {
      digitalWrite(i + pinOffset, LOW);
      Serial.println("Turning OFF input:" + String(i + pinOffset));
    }
  }
}

void rangerFor(int ppm) {
  if (ppm < 500)
  {
    setLed(0); // off
  }
  else if (ppm >= 500 && ppm < 800)
  {
    setLed(1); // room
  }
  else if (ppm >= 800 && ppm < 1000)
  {
    setLed(2); // normal
  }
  else if (ppm >= 1000 && ppm < 1200)
  {
    setLed(3); // tired
  }
  else if (ppm >= 1200 && ppm < 1400)
  {
    setLed(4); // super tired
  }
  else if (ppm >= 1400)
  {
    setLed(5); // critical
  }
}

void loop()
{
  mySerial.write(cmd, 9);
  memset(response, 0, 9);
  mySerial.readBytes(response, 9);
  int i;
  byte crc = 0;
  for (i = 1; i < 8; i++) crc += response[i];
  crc = 255 - crc;
  crc++;

  if ( !(response[0] == 0xFF && response[1] == 0x86 && response[8] == crc) ) {
    Serial.println("CRC error: " + String(crc) + " / " + String(response[8]));
  } else {
    unsigned int responseHigh = (unsigned int) response[2];
    unsigned int responseLow = (unsigned int) response[3];
    unsigned int ppm = (256 * responseHigh) + responseLow;
    Serial.println(ppm);
    rangerFor(ppm);
  }
  delay(10000);
}
