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
#include <list>

#include "ofMain.h"

class GameObject {
public:
  GameObject(float mass, float size, float orientation, ofVec2f position, ofVec2f velocity);
  
  virtual ~GameObject();
  
  virtual ofColor color() const = 0;
  
  virtual float reproductivity() const = 0;
  
  void Draw() const;
  
  virtual void DrawInternal() const = 0;
  
  virtual void MaybeReproduce(std::list<GameObject *> &population);
  
  virtual void ReproduceInternal(ofVec2f velocity, std::list<GameObject *> &population) = 0;
  
  void Update(float dt);
  
public:
  float mass;
  float size;
  float orientation;
  ofVec2f position;
  ofVec2f velocity;
  ofVec2f force;
  
private:
  static constexpr float kChildScaleFactor = 0.5;
  static constexpr float kLineWidthScaleFactor = 0.25;
  static constexpr float kMaxComponentOfVelocity = 10.0;
};

#endif /* defined(__minimalist01__gameobject__) */
