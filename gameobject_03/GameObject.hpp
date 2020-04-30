
#ifndef __GameObject_HPP__
#define __GameObject_HPP__

//------------------------------------------------------
// Class: GameObject
// Description: Abstract class that serves as an interface
//              to all "game" objects
//------------------------------------------------------
class GameObject {
public:
   GameObject()          =default;
   virtual ~GameObject() =default;

   virtual void update(const float dt) =0;
   virtual void render() =0;
};

#endif

