#include "mqtt_client.h"
#include "onvif_executor.h"

#include <iostream>
#include <memory>

int main()
{
    try {
        std::unique_ptr<mqtt_client> client;
        std::cout << "PTR: " << client.get() << std::endl;

        client.reset(new mqtt_client("OBSERVER_TEST"));
        std::cout << "PTR: " << client.get() << std::endl;

        std::unique_ptr<OnvifExecutor> executor(new OnvifExecutor(* client));

        std::string msg = "bla-bla-bla";

        std::cout << "Saying: " << msg << " -> ";
        client->say_something(msg);

        executor->removeMe();

        msg = "xxxxxxxxxxxxxxxx";
        std::cout << "Saying: " << msg << " -> ";
        client->say_something(msg);

        // delete(executor);
        // delete(client);
    } catch (const std::exception &ex) {
        std::cerr << "ERROR: " << ex.what() << std::endl;
    }

    return 0;
}
