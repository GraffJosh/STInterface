
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
    int SendCommand(String action);
    int ProcessCommands();
  private:  
    SeaTalk *_seaTalk = nullptr;
    SeaTalkData *_seaTalkData=nullptr;
    SignalManager *_signalManager = nullptr;
    CommandStack _commandStack= CommandStack();
  };
}}