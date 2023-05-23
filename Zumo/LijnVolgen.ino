#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() {}

void LijnVolgen::init() {
  //lijnSensor setup
  lijnsensor.sensoren_initialiseren();
  lijnsensor.sensoren_kalibreren(motoren);
}

void LijnVolgen::volg() {
  if (lijnsensor.lijn_error() < -100) {
    motoren.rijRechts(200);
  }
  else if (lijnsensor.lijn_error() > 100) {
    motoren.rijLinks(200);
  }
  else {
    motoren.rechtdoor(200);
  }
}

void LijnVolgen::kiesBocht() {}
