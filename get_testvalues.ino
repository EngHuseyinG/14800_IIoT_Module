void get_testvalues(){
 uint8_t result;


modbustimer = millis();
////////////////////D120 yi dinle///Eğer 10 yerine 100 değeri gelirse PLCDEN TEST DEĞERLERİNİ ALMAYA BAŞLA////////////////////////
  result = node.readHoldingRegisters(4216,1);
  D120 = node.getResponseBuffer(0);

if(millis() - modbustimer > 1500 ) { digitalWrite(errorled, HIGH);}
else{digitalWrite(errorled,LOW);}


/////////////////////////// PLC Ve HMI'ın modülün bağlı olup olmadığını anlaması için D150'ye 1 Değerini yaz////////////////////////////
result = node.writeSingleRegister(4246,1);


if(D120 == 100) {

  get_currenttime();
  read_temperature();
  write_firebase();

}
else if(D120 == 200) {

  get_currenttime();
  read_temperature();
  write_firebase2();

}



}




