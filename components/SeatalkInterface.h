
#include "esphome/core/component.h"
namespace esphome {
namespace seatalkinterface {

// public uart::UARTDevice, 
class Epson : public Component {
public:
  
  SeatalkInterface();
  setup();
  loop();
private:  


};
}}