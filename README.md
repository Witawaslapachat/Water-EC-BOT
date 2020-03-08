# Water-EC-BOT
LINE Nofity
www.ec-bot.com

#include <TridentTD_LineNotify.h>
#define SSID        "604"
#define PASSWORD    "1234567890"
#define LINE_TOKEN  "MqsuOmGBWfATDCI3TM370OxaLF1N6PM5IaTt6xjH45O"
int state = 0;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  int Water = analogRead(A0);
  Serial.println(Water);
  delay(100);

  if (state == 0) {
    if (Water < 400 ) {
      LINE.notify("เตือน!! น้ำขึ้นสูงถึงระดับเซ็นเซอร์แล้ว");
      state = 1;
    }
  }
  else if (state == 1) {
    delay(600000);
    state = 0;
  }
}
