//
//  gameobject.cpp
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#include <list>

#include "gameobject.h"
#include "ofMain.h"

GameObject::GameObject(
    float mass, float size, float orientation, ofVec2f position, ofVec2f velocity)
: mass(mass), size(size), orientation(orientation), position(position), velocity(velocity), force() {}

GameObject::~GameObject() {}

void GameObject::Draw() const {
  ofPushStyle();
  ofSetColor(color());
  ofSetLineWidth(size / 4.0);
  ofNoFill();
  ofPushMatrix();
  ofTranslate(position);
  ofScale(size, size);
  ofRotateZ(180.0 / M_PI * orientation);
  DrawInternal();
  ofPopMatrix();
  ofPopStyle();
}

void GameObject::MaybeReproduce(std::list<GameObject *> &population) {
  if (ofRandomuf() < reproductivity()) {
    size /= 2.0;
    velocity = size * ofVec2f(ofRandom(-10.0, 10.0), ofRandom(-10.0, 10.0));
    ReproduceInternal(-velocity, population);
  }
}

void GameObject::Update(float dt) {
  position += velocity * dt;
  velocity += force / mass * dt;
  force = ofVec2f();
  if (position.x < 0) {
    position.x += ofGetWidth();
  }
  if (position.x >= ofGetWidth()) {
    position.x -= ofGetWidth();
  }
  if (position.y < 0) {
    position.y += ofGetHeight();
  }
  if (position.y >= ofGetHeight()) {
    position.y -= ofGetHeight();
  }
}
