
#include "esphome/core/component.h"
namespace esphome {
namespace seatalkinterface {

// public uart::UARTDevice, 
class Epson : public Component {
public:
  
  void SeatalkInterface();
  void setup();
  void loop();
private:  


};
}}