#include "SeatalkInterface.h"
#include <Arduino.h>

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
    _seaTalk->processMessages();
  }

  void SeatalkInterface::loop()
  {
    _seaTalk->processMessages();
    // _remoteControl->processRemote();
    // _boxWebServer->ProcessCommands();
  }

  int SeatalkInterface::SendCommand(String* action)
  {
    Serial.println("Action Received");

    Serial.println(*action);
    if (*action == "minus1")
    {
        _commandStack.push(minus_1);

        Serial.println("Minus one Web");
    }
    else if (*action == "plus1")
    {
        _commandStack.push(plus_1);
        Serial.println("Plus one Web");
    }
    else if (*action == "minus10")
    {
        _commandStack.push(minus_10);
        Serial.println("minus ten Web");
    }
    else if (*action == "plus10")
    {
        _commandStack.push(plus_10);
        Serial.println("plus ten Web");
    }
    else if (*action == "auto")
    {
        _commandStack.push(auto_but);
        Serial.println("auto");
    }
    else if (*action == "standby")
    {
        _commandStack.push(standby_but);
        Serial.println("standby");
    }
    else if (*action == "starttimer")
    {
        _commandStack.push(start_timer);
        Serial.println("Start Timer");
    }
    else if (*action == "wind")
    {
        _commandStack.push(wind_mode);
        Serial.println("Wind Mode");
    }
    return 0;
}

// Process Commands On Main Thread
int SeatalkInterface::ProcessCommands()
{
    while (!_commandStack.isEmpty())
    {
        commands nextCommand= (commands)_commandStack.pop();
        _seaTalk->sendCommand(nextCommand);
    }
    return 0;
}
}}