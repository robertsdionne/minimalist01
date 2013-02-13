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
    CreateRandomShape(ofVec2f(ofRandomWidth(), ofRandomHeight()));
  }
}

//--------------------------------------------------------------
void testApp::update() {
  for (auto object : objects) {
    object->Update(1.0 / ofGetFrameRate());
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
  CreateRandomShape(ofVec2f(x, y));
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

void testApp::CreateRandomShape(ofVec2f at) {
  constexpr float mass = 1.0;
  const float choice = ofRandomuf();
  const float size = ofRandom(5.0, 15.0);
  const float orientation = 2.0 * M_PI * ofRandomuf();
  const ofVec2f velocity = ofVec2f();
  if (choice < 1.0 / 3.0) {
    objects.push_back(new Triangle(mass, size, orientation, at, velocity));
  } else if (choice < 2.0 / 3.0) {
    objects.push_back(new Square(mass, size, orientation, at, velocity));
  } else {
    objects.push_back(new Circle(mass, size, orientation, at, velocity));
  }
}
