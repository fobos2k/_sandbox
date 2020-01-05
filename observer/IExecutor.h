#ifndef __IEXECUTOR_H__
#define __IEXECUTOR_H__

#include <string>

class IExecutor
{
 public:
    virtual ~IExecutor() {};
    virtual void update(const std::string &message) = 0;
};


#endif // __IEXECUTOR_H__
