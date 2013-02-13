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
    float choice = ofRandom(1.0);
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
    object->orientation += ofRandom(-1.0, 1.0) * M_PI / 180.0;
    object->size += ofRandom(-1.0, 1.0);
    object->force = -0.5 * object->velocity;
    object->Update(1.0 / 60.0);
    if (object->position.x < 0) {
      object->position.x += ofGetWidth();
    }
    if (object->position.x >= ofGetWidth()) {
      object->position.x -= ofGetWidth();
    }
    if (object->position.y < 0) {
      object->position.y += ofGetHeight();
    }
    if (object->position.y >= ofGetHeight()) {
      object->position.y -= ofGetHeight();
    }
    if (ofRandom(1.0) < 0.001) {
      objects.push_back(object->Reproduce());
    }
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
  std::list<GameObject *>::iterator i;
  for (i = objects.begin(); i != objects.end(); ++i) {
    (*i)->Draw();
  }
  std::cout << objects.size() << std::endl;
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