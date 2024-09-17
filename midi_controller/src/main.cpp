#include <Arduino.h>
#include <MIDIUSB.h>

// Définir le pin du potentiomètre
const uint8_t POT_PIN = A0;

// Définir le numéro de contrôle CC
const uint8_t CC_NUMBER = 1;

// Variable pour stocker la valeur précédente du potentiomètre
uint8_t prevValue = 255; // Initialisé à une valeur hors de la plage 0-127

// Seuil de changement pour envoyer un message MIDI
const uint8_t THRESHOLD = 1;

// Constante de filtrage pour l'EMA (entre 0 et 1, ici 0.1)
const float ALPHA = 0.1;
float filteredValue = 0;

void setup() {
  pinMode(POT_PIN, INPUT);
  Serial.begin(9600); // Initialiser la communication série pour le débogage
}

midiEventPacket_t controlChange(uint8_t channel, uint8_t control, uint8_t value) {
  midiEventPacket_t event;
  event.byte1 = 0xB0 | (channel - 1); // Code d'état pour Control Change sur le canal spécifié
  event.byte2 = control;              // Numéro de contrôle CC
  event.byte3 = value;                // Valeur du contrôle CC
  return event;
}

void loop() {
  // Lire la valeur du potentiomètre
  int rawValue = analogRead(POT_PIN);

  // Appliquer le filtre Exponentiel Moyenne Mobile
  if (filteredValue == 0) {
    filteredValue = rawValue; // Initialiser avec la première lecture
  } else {
    filteredValue = ALPHA * rawValue + (1 - ALPHA) * filteredValue;
  }

  // Mapper la valeur filtrée de 0-1023 à 0-127 pour MIDI CC
  uint8_t midiValue = map((int)filteredValue, 0, 1023, 0, 127);

  // Afficher les valeurs pour le débogage
  printf("Raw: %d | Filtered: %d | MIDI Value: %d\n", rawValue, (int)filteredValue, midiValue);

  // Vérifier si la valeur a changé de plus que le seuil
  if (abs(midiValue - prevValue) >= THRESHOLD) {
    // Envoyer un message MIDI Control Change
    midiEventPacket_t event = controlChange(1, CC_NUMBER, midiValue);
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();

    // Mettre à jour la valeur précédente
    prevValue = midiValue;
  }

  // Petit délai pour éviter d'envoyer trop de messages
  delay(10);
}