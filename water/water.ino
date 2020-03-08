
#include <TridentTD_LineNotify.h>
#define SSID        "********" //Name WIFI
#define PASSWORD    "********" //Password WiFi
#define LINE_TOKEN  "***************************" // Token Line Notify
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
