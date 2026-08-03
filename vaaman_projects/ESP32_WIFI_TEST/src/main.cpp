#include <Arduino.h>
#include <WiFi.h>

// Replace with your Wi-Fi details
const char* ssid = "vamsi";
const char* password = "123456789";

void setup()
{
    Serial.begin(115200);

    delay(3000);

    Serial.println();
    Serial.println("==================================");
    Serial.println("ESP32 WiFi Test Started");
    Serial.println("==================================");

    WiFi.mode(WIFI_STA);

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    int retry = 0;

    while (WiFi.status() != WL_CONNECTED && retry < 20)
    {
        Serial.print(".");
        delay(500);
        retry++;
    }

    Serial.println();

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println("WiFi Connection Failed!");
        Serial.print("Status Code: ");
        Serial.println(WiFi.status());
    }
}

void loop()
{
    Serial.println("ESP32 is running...");
    delay(2000);
}

