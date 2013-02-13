//
//  circle.cpp
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#include "circle.h"
#include "ofMain.h"

const ofColor Circle::kColor = ofColor(255.0, 0.0, 0.0);

Circle::Circle(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity)
: GameObject(mass, size, orientation, position, velocity) {}

Circle::~Circle() {}

void Circle::DrawInternal() const {
  ofSetColor(kColor);
  ofNoFill();
  ofBeginShape();
  for (unsigned int i = 0; i < 26; ++i) {
    ofVertex(cos(i * 2.0 *  M_PI / 25.0), sin(i * 2.0 * M_PI / 25.0));
  }
  ofEndShape();
}

GameObject *Circle::Reproduce() {
  size /= 2.0;
  ofVec2f impulse = ofVec2f(ofRandom(-100.0, 100.0), ofRandom(-100.0, 100.0));
  velocity = impulse;
  return new Circle(mass, size, orientation, position, -impulse);
}
