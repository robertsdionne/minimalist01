//
//  gameobject.h
//  minimalist01
//
//  Created by Robert Dionne on 2/12/13.
//
//

#ifndef __minimalist01__gameobject__
#define __minimalist01__gameobject__

#include <iostream>

#include "ofMain.h"

class GameObject {
public:
  GameObject(float mass, ofVec2f position, ofVec2f velocity);
  
  virtual ~GameObject();
  
  void Draw();
};

#endif /* defined(__minimalist01__gameobject__) */
