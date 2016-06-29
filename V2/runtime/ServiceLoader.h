
#ifndef ServiceLoader_H
#define ServiceLoader_H

#include <toolkit/ReferenceCountObject.h>
#include <toolkit/AutoPtr.h>


namespace GWSP {

class Service;

class ServiceLoader : public toolkit::RefCountedObject
{

public:
    ServiceLoader();
    virtual ~ServiceLoader();

    bool initialize();
    bool unInitialize();

    int count();
    Service *get(int index);

private:

    ServiceLoader(ServiceLoader &other);
    ServiceLoader &operator=(ServiceLoader &other);

};



}



#endif //ServiceLoader_H