#ifndef __MQTT_CLIENT_H__
#define __MQTT_CLIENT_H__

#include <mosquittopp.h>

#include "IClient.h"

class mqtt_client : public IClient, public mosqpp::mosquittopp
{
 public:
    mqtt_client(const char * id = "");
    virtual ~mqtt_client();

    void attach(IExecutor * executor);
    void detach(IExecutor * executor);
    void notify();

    void say_something(std::string message = "Empty");

 private:
    IExecutor * m_pExecutor;
    std::string m_sMessage;
};


#endif // __MQTT_CLIENT_H__
