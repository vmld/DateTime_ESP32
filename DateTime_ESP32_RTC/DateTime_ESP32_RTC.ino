<<<<<<< HEAD
#include <time.h>
#include <sys/time.h>
#include "WiFi.h"
#include <NTPClient.h>    // for accessing NTP real time API data

/**************************************
 * https://portal.vidadesilicio.com.br/esp32-utilizando-o-rtc-interno-para-datas/
 **************************************/


WiFiClient client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 0, 60000);
char* ssid  = "VMLOD";
char* sspw  = "9917509533";
//........................
struct tm data;//Cria a estrutura que contem as informacoes da data.
char data_formatada[64];

//========================================================
//............................. 
uint32_t readNTPTimeDate() {
  /*  This function is used to read the time form NTP API
   *  Returns: epoch timestamp from NTP API
   */
  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }
  return timeClient.getEpochTime();
}
//............................. Date Time From NTP
void updateTimeFromNTP() {
  /*  This function is used to update local clock
   */
  timeval tv;//Cria a estrutura temporaria para funcao abaixo.
  tv.tv_sec = readNTPTimeDate();
  settimeofday(&tv, NULL);//Configura o RTC para manter a data atribuida atualizada.
}
//............................. 
void readTimeDate() {
  /*  This function is used to local clock
   */
  time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
  data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura
  strftime(data_formatada, 64, "%d/%m/%Y %H:%M:%S", &data);//Cria uma String formatada da estrutura "data"
}
//========================================================
void setup() {
  //............................. WiFi
  WiFi.begin(ssid, sspw);
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
=======
#include <time.h>
#include <sys/time.h>
#include "WiFi.h"
#include <NTPClient.h>    // for accessing NTP real time API data

/**************************************
 * https://portal.vidadesilicio.com.br/esp32-utilizando-o-rtc-interno-para-datas/
 **************************************/


WiFiClient client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 0, 60000);
char* ssid  = "VMLOD";
char* sspw  = "9917509533";
//........................
struct tm data;//Cria a estrutura que contem as informacoes da data.
char data_formatada[64];

//========================================================
//............................. 
uint32_t readNTPTimeDate() {
  /*  This function is used to read the time form NTP API
   *  Returns: epoch timestamp from NTP API
   */
  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }
  return timeClient.getEpochTime();
}
//............................. Date Time From NTP
void updateTimeFromNTP() {
  /*  This function is used to update local clock
   */
  timeval tv;//Cria a estrutura temporaria para funcao abaixo.
  tv.tv_sec = readNTPTimeDate();
  settimeofday(&tv, NULL);//Configura o RTC para manter a data atribuida atualizada.
}
//............................. 
void readTimeDate() {
  /*  This function is used to local clock
   */
  time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
  data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura
  strftime(data_formatada, 64, "%d/%m/%Y %H:%M:%S", &data);//Cria uma String formatada da estrutura "data"
}
//========================================================
void setup() {
  //............................. WiFi
  WiFi.begin(ssid, sspw);
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
>>>>>>> 2508969772d72413b7b61cd27ae0720379fda849
