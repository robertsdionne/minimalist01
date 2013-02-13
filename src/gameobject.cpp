//
//  gameobject.cpp
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#include "gameobject.h"
#include "ofMain.h"

GameObject::GameObject(
    float mass, float size, float orientation, ofVec2f position, ofVec2f velocity)
: mass(mass), size(size), orientation(orientation), position(position), velocity(velocity), force() {}

GameObject::~GameObject() {}

void GameObject::Draw() const {
  ofPushMatrix();
  ofPushStyle();
  ofTranslate(position);
  ofSetLineWidth(size / 4.0);
  ofScale(size, size);
  ofRotateZ(180.0 / M_PI * orientation);
  DrawInternal();
  ofPopMatrix();
  ofPopStyle();
}

void GameObject::Update(float dt) {
  position += velocity * dt;
  velocity += force / mass * dt;
  force = ofVec2f();
}
