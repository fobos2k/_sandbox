#ifndef __ONVIF_EXECUTOR_H__
#define __ONVIF_EXECUTOR_H__

#include "IExecutor.h"
#include "mqtt_client.h"

class OnvifExecutor : public IExecutor
{
 public:
    OnvifExecutor(mqtt_client &client);
    virtual ~OnvifExecutor();

    void update(const std::string &message);
    void removeMe();
    void execute();

 private:
    std::string m_sMessage;
    mqtt_client & m_Client;
};


#endif // __ONVIF_EXECUTOR_H__
