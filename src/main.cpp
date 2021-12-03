#include <service/Application.h>
#include <Arduino.h>
#include "MyProps.h"

class MyApplication : public Application {
public:
    MyApplication()
            : Application(logging::level::debug) {

    }

    void setup() override {
        auto props = getRegistry()->getProperties();
        // Wifi
        props->setStr(PROP_WIFI_SSID, WIFI_SSID);
        props->setStr(PROP_WIFI_PASS, WIFI_PASS);

        // Mqtt
        props->setStr(PROP_MQTT_SERVER_HOST, MQTT_HOST);
        props->setStr(PROP_MQTT_CLIENT_ID, MQTT_ID);
        props->setStr(PROP_MQTT_USER, MQTT_USER);
        props->setStr(PROP_MQTT_PASS, MQTT_PASS);

        Application::setup();
    }
};

MyApplication app;

void setup() {
    app.setup();
}

void loop() {
    app.loop();
    delay(0);
}