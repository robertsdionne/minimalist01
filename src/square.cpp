//
//  square.cpp
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#include "ofMain.h"
#include "square.h"

const ofColor Square::kColor = ofColor(255.0, 192.0, 203.0);

Square::Square(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity)
: GameObject(mass, size, orientation, position, velocity) {}

Square::~Square() {}

void Square::DrawInternal() const {
  ofSetColor(kColor);
  ofNoFill();
  ofBeginShape();
  for (unsigned int i = 0; i < 5; ++i) {
    ofVertex(cos(i * 2.0 *  M_PI / 4.0), sin(i * 2.0 * M_PI / 4.0));
  }
  ofEndShape();
}

GameObject *Square::Reproduce() {
  size /= 2.0;
  ofVec2f impulse = ofVec2f(ofRandom(-100.0, 100.0), ofRandom(-100.0, 100.0));
  velocity = impulse;
  return new Square(mass, size, orientation, position, -impulse);
}
