#!/bin/bash

g++ -c -I${MOSQUITTO_LIB_CPP_PATH} -I${MOSQUITTO_LIB_PATH} mqtt_client.cpp
g++ -c -I${MOSQUITTO_LIB_CPP_PATH} -I${MOSQUITTO_LIB_PATH} onvif_executor.cpp
g++ -o test_observer main.cpp mqtt_client.o onvif_executor.o -I${MOSQUITTO_LIB_CPP_PATH} -I${MOSQUITTO_LIB_PATH} -L ${MOSQUITTO_LIB_CPP_PATH} -l:libmosquittopp.so.1
