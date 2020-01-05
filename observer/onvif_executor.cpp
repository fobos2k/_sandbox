#include "onvif_executor.h"

#include <iostream>

OnvifExecutor::OnvifExecutor(mqtt_client & client) : m_Client(client)
{
    m_Client.attach(this);
    std::cout << "Hi, i'm ONVIF Executor." << std::endl;
}

OnvifExecutor::~OnvifExecutor()
{
    std::cout << "Bye from ONVIF Executor." << std::endl;
}

void OnvifExecutor::removeMe()
{
    m_Client.detach(this);
}

void OnvifExecutor::update(const std::string &message)
{
    m_sMessage = message;
    execute();
}

void OnvifExecutor::execute()
{
    std::cout << "Executing: " << m_sMessage << std::endl;
}
