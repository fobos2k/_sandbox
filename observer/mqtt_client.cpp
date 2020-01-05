#include "mqtt_client.h"

#include <iostream>

mqtt_client::mqtt_client(const char * id) : mosquittopp(id)
{
}

mqtt_client::~mqtt_client()
{
    std::cout << "Bye from MQTT client" << std::endl;
}

void mqtt_client::say_something(std::string message)
{
    m_sMessage = message;
    notify();
}

void mqtt_client::attach(IExecutor * executor)
{
    m_pExecutor = executor;
}

void mqtt_client::detach(IExecutor * executor)
{
    m_pExecutor = nullptr;
}

void mqtt_client::notify()
{
    if ( m_pExecutor )
        m_pExecutor->update(m_sMessage);
    else
        std::cout << "No executors... :(" << std::endl;
}
