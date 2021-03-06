

#ifndef SerialportEventHandler_H
#define SerialportEventHandler_H

#include <toolkit/ReferenceCountObject.h>
#include <string>


using Services::Event::EventService;
using Services::Event::EventNotifyHandler;

namespace Services {
namespace SerialPort {


class SerialDevice;

class SerialportEventHandler :public toolkit::RefCountedObject, 
                              public ACE_Event_Handler,
                              public EventNotifyHandler
{
public:
    
    SerialportEventHandler(SerialDevice &device, EventService &eventQ);
    ~SerialportEventHandler();

    virtual int handleEvent(int id, const ACE_Message_Block &b);
    virtual ACE_HANDLE get_handle (void) const;
    virtual int handle_input (ACE_HANDLE fd);
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);


private:

    SerialDevice &_serialDevice;
    EventService &_eventQ;
};


}
}



#endif //SerialportEventHandler_H




