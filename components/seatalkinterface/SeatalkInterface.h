
#include "esphome/core/component.h"
#include "SeaTalk.h"
#include "SignalManager.h"
#include "CommandStack.h"
#include "Commands.h"

namespace esphome {
namespace seatalkinterface {

  class SeatalkInterface : public Component {
  public:
    
    SeatalkInterface();
    void readBus();
    void loop();
    SendCommand(String action);
    ProcessCommands();
  private:  
    SeaTalk *_seaTalk = nullptr;
    SeaTalkData *_seaTalkData=nullptr;
    SignalManager *_signalManager = nullptr;
    CommandStack _commandStack= CommandStack();
  };
}}