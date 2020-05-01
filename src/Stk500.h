#ifndef Stk500_h
#define Stk500_h

#include "Arduino.h"

class Stk500 {

  public:
    Stk500(Stream* serial, int resPin, Stream* log = nullptr);
    bool setupDevice();
    bool flashPage(byte* loadAddress, byte* data);
    int exitProgMode();

  protected:
    void resetMCU();
    int getSync();
    int enterProgMode();
    int loadAddress(byte adrHi, byte adrLo);
    int setProgParams();
    int setExtProgParams();

    byte execCmd(byte cmd);
    byte execParam(byte cmd, byte* params, int count);
    byte sendBytes(byte* bytes, int count);
    int waitForSerialData(int dataCount, int timeout);
    int getFlashPageCount(byte flashData[][131]);

    int _resetPin;
    Stream* _serial;
    Stream* _log;
};

#endif
