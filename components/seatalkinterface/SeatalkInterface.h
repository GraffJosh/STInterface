
#include "esphome/core/component.h"
namespace esphome {
namespace seatalkinterface {

// public uart::UARTDevice, 
class SeatalkInterface : public Component {
public:
  
  SeatalkInterface();
  void setup();
  void loop();
private:  


};
}}