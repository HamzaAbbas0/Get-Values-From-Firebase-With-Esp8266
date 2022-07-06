#include <ESP8266WiFi.h>                                                    // esp8266 library                                             // firebase library
#include <FirebaseESP8266.h>
#define FIREBASE_HOST //Enter your Firebase Host
#define FIREBASE_AUTH //Enter your Firebase Auth
#define WIFI_SSID //enter your wifi name
#define WIFI_PASSWORD //enter your wifi passoward
#define USER_EMAIL //Enter your email id 
#define USER_PASSWORD //Enter your passoward
// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

FirebaseConfig config;
FirebaseData fbdo;
FirebaseJson json;
FirebaseAuth auth;
int a;
const char* b;
int c;
void setup() {
  Serial.begin(115200);
  Serial.println("esp8266 serial initialize");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
    /* Assign the api key (required) */
  config.api_key = FIREBASE_AUTH;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = FIREBASE_HOST;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  //Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  delay(1000);

}
void loop() {
  
a=Firebase.getInt(fbdo,"/ledoff");
a=fbdo.to<int>();
Serial.println(int(a));
Firebase.getString(fbdo,"/ledon");
b=fbdo.to<const char *>();
Serial.println((b));
//c=Firebase.getString(fbdo,"/THRESHOLD VALUE/THRESHOLD");
//Serial.println(String(c));
//delay(1000);  
}
