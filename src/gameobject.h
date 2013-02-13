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
  GameObject(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity);
  
  virtual ~GameObject();
  
  void Draw() const;
  
  virtual void DrawInternal() const = 0;
  
  virtual GameObject *Reproduce() = 0;
  
  void Update(float dt);
  
public:
  float mass;
  float size;
  float orientation;
  ofVec2f position;
  ofVec2f velocity;
  ofVec2f force;
};

#endif /* defined(__minimalist01__gameobject__) */
