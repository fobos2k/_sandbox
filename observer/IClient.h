#ifndef __ICLIENT_H__
#define __ICLIENT_H__

#include "IExecutor.h"

class IClient
{
 public:
    virtual ~IClient() {};

    virtual void attach(IExecutor * executor) = 0;
    virtual void detach(IExecutor * executor) = 0;
    virtual void notify() = 0;
};


#endif // __ICLIENT_H__
