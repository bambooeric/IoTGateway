
#ifndef COAPRD_SERVICE_H
#define COAPRD_SERVICE_H

#include <runtime/Service.h>
#include <toolkit/CoAP_Wrapper.h>


using toolkit::CoAPWrapper;
using Services::Conf::ConfService;
using Services::Reactor::ReactorService;


namespace Services {
namespace CoAPRD {

class CoAP_RD_Resource;
class CoAPRDLookUpResource;

class CoAPRDService : public GWSP::Service, public ACE_Event_Handler
{

public:
    typedef toolkit::AutoPtr<CoAPRDService> Ptr;
    
    CoAPRDService(GWSP::ServiceContext &context);
    ~CoAPRDService();
    
    virtual std::string &name();
    virtual bool initialize();
    virtual bool unInitialize();
    virtual bool start();
    virtual bool stop();

    
    virtual int handle_input (ACE_HANDLE fd);
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
    
    virtual ACE_HANDLE get_handle (void) const;


private:
    typedef toolkit::AutoPtr<CoAPWrapper> CoAPWrapperPtr;
    typedef toolkit::AutoPtr<CoAP_RD_Resource> CoAP_RD_ResourcePtr;
    typedef toolkit::AutoPtr<CoAPRDLookUpResource> CoAPRDLookUpResourcePtr;
    typedef toolkit::AutoPtr<ConfService> ConfServicePtr;
    typedef toolkit::AutoPtr<ReactorService> ReactorServicePtr;
    
    
    CoAPWrapperPtr _coapWrapperPtr;
    CoAP_RD_ResourcePtr _rdRes;
    CoAPRDLookUpResourcePtr _rdLookup;
    ConfServicePtr _confPtr;
    ReactorServicePtr _reactorPtr;
    
    
    
};

GWSP::Service *instance(GWSP::ServiceContext &context);

}
}

#endif //COAPRD_SERVICE_H

