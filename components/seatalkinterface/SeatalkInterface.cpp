#include "SeatalkInterface.h"
#include <Arduino.h>
#include "SeaTalk.h"
#include "SignalManager.h"

namespace esphome {
namespace seatalkinterface {
  static const char *TAG = "seatalkinterface.component";
  SeatalkInterface::SeatalkInterface()
  {
    Serial.begin(9600); // Serial out put for function checks with PC
    _seaTalkData= new SeaTalkData();
    _signalManager= new SignalManager(_seaTalkData);
    _seaTalk = new SeaTalk(_signalManager,  20, 21);
  }

  void SeatalkInterface::readBus()
  {
    _seaTalk->checkBus();
  }

  void SeatalkInterface::loop()
  {
    _seaTalk->processMessages();
    // _remoteControl->processRemote();
    // _boxWebServer->ProcessCommands();
  }
}}