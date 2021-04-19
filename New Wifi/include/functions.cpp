#include "functions.hpp"

void sendData(String str);
boolean find(String string, String value);
String readSerialMessage();
String readWifiSerialMessage();
String sendToWifi(String command, const int timeout, boolean debug);
String sendToUno(String command, const int timeout, boolean debug);
