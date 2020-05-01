
#ifndef __Instrument_HPP__
#define __Instrument_HPP__

class Instrument
{
public:
   Instrument()=default;
   virtual ~Instrument() =default;

   virtual void update(const float dt) =0;
   virtual void render()               =0;
};

#endif


