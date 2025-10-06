#include "Arduino.h"

#define Vin  12   // GPIO 12 as Vin (PWM)
#define Vout 27   // GPIO 27 as Vout (ADC)
// #define Cal  14 // GPIO 14 as current-sense node (not used in Task 1)

// ---- ADC constants (ESP32 12-bit) ----
const float VREF    = 3.3f;        // board IO/ADC reference voltage
const float ADC_MAX = 4095.0f;     // 12-bit max count

float x; // duty cycle (%)
float y; // Vout (V)

void setup() {
  Serial.begin(115200);
  pinMode(Vin, OUTPUT);
  pinMode(Vout, INPUT);
  // pinMode(Cal, INPUT);

  // Make sure ADC covers ~0–3.3 V on ESP32:
  analogSetPinAttenuation(Vout, ADC_11db); // optional but recommended

  delay(100);

  Serial.println("Duty(%),Vout(V)");

  for (int onPeriod = 0; onPeriod < 256; onPeriod++) {
    analogWrite(Vin, onPeriod);   // PWM output
    delay(2);                     // small settle time

    // --- Convert ADC reading to volts (0.00–3.30 V) ---
    int   raw   = analogRead(Vout);                // 0..4095
    float volts = (raw * VREF) / ADC_MAX;          // 0..3.3 V

    x = (onPeriod / 255.0f) * 100.0f;  // duty in %
    y = volts;                         // measured Vout in volts

    Serial.print(x, 1);
    Serial.print(",");
    Serial.println(y, 3);   // print 3 decimals (e.g., 1.650)
  }
}

void loop() {
  // empty for one-time sweep
}