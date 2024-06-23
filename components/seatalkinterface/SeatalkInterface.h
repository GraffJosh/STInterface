
#include "esphome/core/component.h"
namespace esphome {
namespace seatalkinterface {

  class SeatalkInterface : public Component {
  public:
    
    SeatalkInterface();
    void readBus();
    void loop();
  private:  
    SeaTalk *_seaTalk = nullptr;
    SeaTalkData *_seaTalkData=nullptr;
    SignalManager *_signalManager = nullptr;
  };
}}