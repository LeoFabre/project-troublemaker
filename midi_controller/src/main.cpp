#include <Arduino.h>
#include <MIDIUSB.h>

// Classe Potentiometer
class Potentiometer {
  public:
    Potentiometer(uint8_t pin, uint8_t ccNumber, uint8_t threshold = 1, float alpha = 0.1, uint8_t channel = 1)
      : potPin(pin), ccNum(ccNumber), thresh(threshold), alpha(alpha), midiChannel(channel),
        prevVal(255), filteredVal(0) {}

    void initialize() {
      pinMode(potPin, INPUT);
      filteredVal = analogRead(potPin); // Initialisation avec la première lecture
      prevVal = map(filteredVal, 0, 1023, 0, 127);
    }

    void update() {
      int raw = analogRead(potPin);
      applyFilter(raw);
      uint8_t midiVal = mapValue();

      // Affichage pour le débogage
      printf("RawA: %d | Filtered: %d | MIDI Value: %d\n", raw, (int)filteredVal, midiVal);

      // Vérification du seuil et envoi MIDI si nécessaire
      if (abs(midiVal - prevVal) >= thresh) {
        sendMIDI(midiVal);
        prevVal = midiVal;
      }
    }

  private:
    uint8_t potPin;
    uint8_t ccNum;
    uint8_t thresh;
    float alpha;
    uint8_t midiChannel;
    uint8_t prevVal;
    float filteredVal;

    void applyFilter(int rawValue) {
      filteredVal = alpha * rawValue + (1 - alpha) * filteredVal;
    }

    uint8_t mapValue() {
      return map((int)filteredVal, 0, 1023, 0, 127);
    }

    void sendMIDI(uint8_t value) {
      midiEventPacket_t event = controlChange(midiChannel, ccNum, value);
      MidiUSB.sendMIDI(event);
      MidiUSB.flush();
    }

    // Fonction pour créer un message Control Change
    midiEventPacket_t controlChange(uint8_t channel, uint8_t control, uint8_t value) {
      midiEventPacket_t event;
      event.byte1 = 0xB0 | (channel - 1); // Code d'état pour Control Change sur le canal spécifié
      event.byte2 = control;              // Numéro de contrôle CC
      event.byte3 = value;                // Valeur du contrôle CC
      return event;
    }
};

 // Définir le pin du potentiomètre
const uint8_t POT_PIN = A0;

// Définir le numéro de contrôle CC
const uint8_t CC_NUMBER = 1;

// Créer une instance de Potentiometer
Potentiometer pot(POT_PIN, CC_NUMBER, 1, 0.1, 1);

void setup() {
  Serial.begin(9600); // Initialiser la communication série pour le débogage
  pot.initialize();
}

void loop() {
  pot.update();
  delay(10); // Petit délai pour éviter d'envoyer trop de messages
}
