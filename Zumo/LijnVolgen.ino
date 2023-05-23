#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() {}

void LijnVolgen::init() {
  //lijnSensor setup
  lijnsensoren.sensoren_initialiseren();
  lijnsensoren.sensoren_kalibreren(motoren);
}

void LijnVolgen::volg() {
  while (lijnsensoren.lijn_error() < -100) {
    motoren.rijRechts(200);
  }
  while (lijnsensoren.lijn_error() > 100) {
    motoren.rijLinks(200);
  }
  while (lijnsensoren.lijn_error() > -100 && lijnsensoren.lijn_error() < 100) {
    motoren.rechtdoor(200);
  }
}
