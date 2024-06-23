#include "SeatalkInterface.h"
#include <Arduino.h>
// #include "RemoteControl.h"
#include "SeaTalk.h"
// #include "BoxWifi.h"
// #include "BoxWebServer.h"
// #include "Options.h"
#include "SignalManager.h"
// #include <SPIFFS.h>

// RemoteControl *_remoteControl = nullptr;
SeaTalk *_seaTalk = nullptr;
// BoxWifi *_boxWifi = nullptr;
// Options *_options = nullptr;
SeaTalkData *_seaTalkData=nullptr;
SignalManager *_signalManager = nullptr;
// BoxWebServer *_boxWebServer = nullptr;

namespace esphome {
namespace seatalkinterface {
  static const char *TAG = "seatalkinterface.component";
  SeatalkInterface::SeatalkInterface()
  {
    // Serial1 = HardwareSerial::HardwareSerial(0);
    Serial1.begin( 115200, SERIAL_8N1, 20, 21, true );
    // this->_rxPin = rxPin;
    // this->_txPin = txPin;
    this->setup();
    this->loop();
  }

  void SeatalkInterface::setup()
  {

    Serial.begin(9600); // Serial out put for function checks with PC
                        // Initialize SPIFFS
    // if (!SPIFFS.begin(true))
    // {
    //   Serial.println("An Error has occurred while mounting SPIFFS");
    //   return;
    // }
    // _boxWifi = new BoxWifi();
    _seaTalkData= new SeaTalkData();
    // _options = new Options();
    _signalManager= new SignalManager(_seaTalkData);
    _seaTalk = new SeaTalk(_signalManager);
    // _remoteControl = new RemoteControl(_seaTalk, _options);
    // _boxWebServer = new BoxWebServer(_seaTalk, _options);
  }

  void SeatalkInterface::loop()
  {
    _seaTalk->processMessages();
    // _remoteControl->processRemote();
    // _boxWebServer->ProcessCommands();
  }
}}