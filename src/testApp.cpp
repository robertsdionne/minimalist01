#include "circle.h"
#include "gameobject.h"
#include "square.h"
#include "testApp.h"
#include "triangle.h"

const unsigned int testApp::kNumGameObjects = 25;

//--------------------------------------------------------------
void testApp::setup() {
  ofEnableSmoothing();
  for (unsigned int i = 0; i < kNumGameObjects; ++i) {
    float choice = ofRandomuf();
    if (choice < 0.333) {
      objects.push_back(new Triangle(1.0, ofRandom(5.0, 15.0),
          ofRandom(2.0f * M_PI), ofVec2f(ofRandomWidth(), ofRandomHeight()), ofVec2f()));
    } else if (choice < 0.666) {
      objects.push_back(new Square(1.0, ofRandom(5.0, 15.0),
          ofRandom(2.0f * M_PI), ofVec2f(ofRandomWidth(), ofRandomHeight()), ofVec2f()));
    } else {
      objects.push_back(new Circle(1.0, ofRandom(5.0, 15.0),
          ofRandom(2.0f * M_PI), ofVec2f(ofRandomWidth(), ofRandomHeight()), ofVec2f()));
    }
  }
}

//--------------------------------------------------------------
void testApp::update() {
  for (auto object : objects) {
    object->orientation += ofRandomf() * M_PI / 180.0;
    object->size += ofRandomf();
    object->force = -0.5 * object->velocity;
    object->Update(1.0 / 60.0);
    object->MaybeReproduce(objects);
  }
  objects.remove_if([] (const GameObject *const object) -> bool {
    if (object->size <= 0) {
      delete object;
      return true;
    } else {
      return false;
    }
  });
}

//--------------------------------------------------------------
void testApp::draw() {
  ofBackground(0.0, 0.0, 0.0);
  for (auto object : objects) {
    object->Draw();
  }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int width, int height) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) { 

}