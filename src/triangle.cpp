//
//  triangle.cpp
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#include <list>

#include "ofMain.h"
#include "triangle.h"

const ofColor Triangle::kColor = ofColor(0.0, 128.0, 128.0);

Triangle::Triangle(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity)
: GameObject(mass, size, orientation, position, velocity) {}

Triangle::~Triangle() {}

ofColor Triangle::color() const {
  return kColor;
}

float Triangle::reproductivity() const {
  return kReproductivity;
}

void Triangle::DrawInternal() const {
  ofBeginShape();
  for (unsigned int i = 0; i < 4; ++i) {
    ofVertex(cos(i * 2.0 *  M_PI / 3.0), sin(i * 2.0 * M_PI / 3.0));
  }
  ofEndShape();
}

void Triangle::ReproduceInternal(ofVec2f velocity, std::list<GameObject *> &population) {
  population.push_back(new Triangle(mass, size, orientation, position, velocity));
}
