//
// Created by leofa on 10/10/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include <Arduino.h>
#include <MIDIUSB.h>

inline void SendControlChange(uint8_t control, uint8_t value, uint8_t channel) {
    midiEventPacket_t event;
    event.header = 0x0B; // CIN pour Control Change
    event.byte1 = 0xB0 | (channel & 0x0F); // Status byte pour Control Change sur le canal spécifié (0-15)
    event.byte2 = control; // Numéro de contrôle CC
    event.byte3 = value;   // Valeur de contrôle CC
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}

inline void SendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) {
    midiEventPacket_t event;
    event.header = 0x09; // CIN pour Note On
    event.byte1 = 0x90 | (channel & 0x0F); // Status byte pour Note On sur le canal spécifié (0-15)
    event.byte2 = note;    // Numéro de la note
    event.byte3 = velocity; // Vélocité
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}

inline void SendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) {
    midiEventPacket_t event;
    event.header = 0x08; // CIN pour Note Off
    event.byte1 = 0x80 | (channel & 0x0F); // Status byte pour Note Off sur le canal spécifié (0-15)
    event.byte2 = note;    // Numéro de la note
    event.byte3 = velocity; // Vélocité
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}



inline uint8_t mapPotValueToMidiValue(const int potValue){
  return map(potValue, 0, 1023, 0, 127);
}
#endif //UTILS_H
