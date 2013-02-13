//
//  triangle.h
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#ifndef __minimalist01__triangle__
#define __minimalist01__triangle__

#include <iostream>
#include <list>

#include "gameobject.h"
#include "ofMain.h"

class Triangle : public GameObject {
public:
  Triangle(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity);
  
  virtual ~Triangle();
  
  virtual float reproductivity() const;
  
  virtual void DrawInternal() const;
  
  virtual void ReproduceInternal(ofVec2f velocity, std::list<GameObject *> &population);
  
private:
  static const float kReproductivity;
  static const ofColor kColor;
};

#endif /* defined(__minimalist01__triangle__) */
