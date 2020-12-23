#include <time.h>
#include "WiFi.h"
#include <NTPClient.h>    // for accessing NTP real time API data


#include "Config.h"
//#ifndef WIFI_CONFIG_H
//#define xWiFi_ssid "YOUR_WIFI_SSID"
//#define xWiFi_sspw "YOUR_WIFI_PASSWD"
//#endif // !WIFI_CONFIG_H

WiFiClient client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 0, 60000);
//........................
struct tm data;//Cria a estrutura que contem as informacoes da data.
char data_formatada[64];

//========================================================
void setup() {
  //............................. WiFi
  WiFi.begin(xWiFi_ssid, xWiFi_sspw);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); Serial.println(F("Connecting to WiFi..")); }
  Serial.println(WiFi.localIP());

  updateTimeFromNTP();
  
}
//========================================================
void loop() {
  readTimeDate();
  printf("Data formatada: %s\n", data_formatada);//Mostra na Serial a data formatada
  delay(1000);
}
