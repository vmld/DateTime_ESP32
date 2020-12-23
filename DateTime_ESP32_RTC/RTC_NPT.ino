#include <time.h>
#include "WiFi.h"
#include <NTPClient.h>    // for accessing NTP real time API data


/**************************************
 * https://portal.vidadesilicio.com.br/esp32-utilizando-o-rtc-interno-para-datas/
 **************************************/



//========================================================
//............................. 
uint32_t readNTPTimeDate() {
  int count = 0;
  /*  This function is used to read the time form NTP API
   *  Returns: epoch timestamp from NTP API
   */
  while (!timeClient.update()) {
    ++count;
    timeClient.forceUpdate();
    if (count>10){break;}
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
