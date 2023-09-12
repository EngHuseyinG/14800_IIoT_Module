void setup_firebase() {

    
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  
   config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

  Firebase.reconnectWiFi(true);

  // required for large file data, increase Rx size as needed.
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);



  Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

  Serial.println("Getting User UID");
 


  /*
  while ((auth.token.uid) == "") {
    mySerial.print('.');
    delay(1000);
  }
  */

  
  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.print(uid);
  delay(500);


  if (Firebase.setInt(fbdo, "/flex_test/module1/command", 10)){}
  else{
    Serial.println("Yazamadim");
    ESP.reset();}
}