# Remote Control led through MQTT server
In this project, I will show how control instructions are sent to an IOT device.
I will implement remote control LED lights via NodeMCU(ESP8266), **MQTT lens** and Arduino IDE to program NodeMCU ESP8266. 
I have used MQTT protocol to send instructions to my application. It is a standards-based messaging protocol, or set of rules, 
used for machine-to-machine communication. This protocol allows one device(sender) to publish data to a MQTT  
broker with specified Topic, another device(receiver) which subscribes the same topic can easily get message from sending device.
