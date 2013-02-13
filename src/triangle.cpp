//
//  triangle.cpp
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#include "ofMain.h"
#include "triangle.h"

const ofColor Triangle::kColor = ofColor(0.0, 128.0, 128.0);

Triangle::Triangle(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity)
: GameObject(mass, size, orientation, position, velocity) {}

Triangle::~Triangle() {}

void Triangle::DrawInternal() const {
  ofSetColor(kColor);
  ofNoFill();
  ofBeginShape();
  for (unsigned int i = 0; i < 4; ++i) {
    ofVertex(cos(i * 2.0 *  M_PI / 3.0), sin(i * 2.0 * M_PI / 3.0));
  }
  ofEndShape();
}

GameObject *Triangle::Reproduce() {
  size /= 2.0;
  ofVec2f impulse = ofVec2f(ofRandom(-100.0, 100.0), ofRandom(-100.0, 100.0));
  velocity = impulse;
  return new Triangle(mass, size, orientation, position, -impulse);
}
