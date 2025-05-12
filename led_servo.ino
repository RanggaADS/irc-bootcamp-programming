#include <Servo.h>
Servo myservo;
const int buttonPin = 10;    // Pin untuk tombol
const int greenLedPin = 11;  // Pin untuk LED hijau
const int yellowLedPin = 12; // Pin untuk LED kuning
const int redLedPin = 13;    // Pin untuk LED merah

int ledstate = 0; // Variabel untuk melacak status LED

void setup() {
  pinMode(buttonPin, INPUT);         // Mengatur pin tombol sebagai input
  pinMode(greenLedPin, OUTPUT);      // Mengatur pin LED hijau sebagai output
  pinMode(yellowLedPin, OUTPUT);     // Mengatur pin LED kuning sebagai output
  pinMode(redLedPin, OUTPUT);        // Mengatur pin LED merah sebagai output
  myservo.attach(9);                 // Menghubungkan servo ke pin 9
}

void loop() {
  // Cek jika tombol ditekan
  if (digitalRead(buttonPin) == HIGH) {
    delay(100); // Debouncing sederhana dengan delay 100ms
    if (digitalRead(buttonPin) == HIGH) { // Pastikan tombol masih ditekan
      ledstate++; // Melakukan penambahan status LED
    }
  }

  if (ledstate > 2) {
    ledstate = 0; // Kembali ke status awal jika melewati tiga LED
  }

  // Mengganti status LED sesuai dengan urutan yang diminta
  switch (ledstate) {
    case 0:
      digitalWrite(greenLedPin, LOW);   // LED hijau mati
      digitalWrite(yellowLedPin, LOW); // LED kuning mati
      digitalWrite(redLedPin, HIGH);   // LED merah menyala
      break;
    case 1:
      digitalWrite(greenLedPin, LOW);   // LED hijau mati
      digitalWrite(yellowLedPin, HIGH); // LED kuning menyala
      digitalWrite(redLedPin, LOW);     // LED merah mati
      break;
    case 2:
      digitalWrite(greenLedPin, HIGH);  // LED hijau menyala
      digitalWrite(yellowLedPin, LOW);  // LED kuning mati
      digitalWrite(redLedPin, LOW);     // LED merah mati
      break;
  }

  // Menggerakkan servo
  myservo.write(0);
  delay(500); // Memberikan waktu untuk servo bergerak
  myservo.write(180);
  delay(500); // Memberikan waktu untuk servo bergerak
}
