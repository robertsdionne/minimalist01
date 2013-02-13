//
//  circle.h
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#ifndef __minimalist01__circle__
#define __minimalist01__circle__

#include <iostream>

#include "gameobject.h"
#include "ofMain.h"

class Circle : public GameObject {
public:
  Circle(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity);
  
  virtual ~Circle();
  
  virtual void DrawInternal() const;
  
  virtual GameObject *Reproduce();
  
private:
  static const ofColor kColor;
};

#endif /* defined(__minimalist01__circle__) */
