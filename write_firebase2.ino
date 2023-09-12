void write_firebase2() {

int D121;
int D122;
int D123;
int D124;
int D125;
int D126;
int D127;
int D128;
int D129;
int D130;
int D131;
int D132;
int D133;
int D134;
int D135;
int D136;
int D137;
int D138;
int D139;
int D140;
int D141;
int D142;
int D143;
int D144;
int D145;
int D146;
int D147;


 uint8_t result;


  result = node.readHoldingRegisters(4217,27);
  D121 = node.getResponseBuffer(0);
  D122 = node.getResponseBuffer(1);
  D123 = node.getResponseBuffer(2);
  D124 = node.getResponseBuffer(3);
  D125 = node.getResponseBuffer(4);
  D126 = node.getResponseBuffer(5);
  D127 = node.getResponseBuffer(6);
  D128 = node.getResponseBuffer(7);
  D129 = node.getResponseBuffer(8);
  D130 = node.getResponseBuffer(9);
  D131 = node.getResponseBuffer(10);
  D132 = node.getResponseBuffer(11);
  D133 = node.getResponseBuffer(12);
  D134 = node.getResponseBuffer(13);
  D135 = node.getResponseBuffer(14);
  D136 = node.getResponseBuffer(15);
  D137 = node.getResponseBuffer(16);
  D138 = node.getResponseBuffer(17);
  D139 = node.getResponseBuffer(18);
  D140 = node.getResponseBuffer(19);
  D141 = node.getResponseBuffer(20);
  D142 = node.getResponseBuffer(21);
  D143 = node.getResponseBuffer(22);
  D144 = node.getResponseBuffer(23);
  D145 = node.getResponseBuffer(24);
  D146 = node.getResponseBuffer(25);
  D147 = node.getResponseBuffer(26);


String uid = currentSecond + currentMinute + currentHour + monthDay + currentMonth + currentYear ;
String orderid = currentYear + currentMonth + monthDay + currentHour + currentMinute ;
int t1 = t*10;
int h1 = h*10;

/////////////////////////////////////////////////////JSON DOSYASI HAZIRLA/////////////////////////////////////////////
  FirebaseJson json;


  json.set("D121", D121);json.set("D122", D122);json.set("D123", D123);json.set("D124", D124);json.set("D125", D125);json.set("D126", D126);json.set("D127", D127);json.set("D128", D128);

  json.set("D130", D130);json.set("D131", D131);

  json.set("D133", D133);json.set("D134", D134);


  json.set("D136", D136);json.set("D137", D137);


  json.set("D139", D139);json.set("D140", D140);

  json.set("D142", D142);json.set("D144", D144);json.set("D145", D145);

  json.set("orderid", orderid);json.set("uid", uid);

  json.set("t", t1);json.set("h", h1);

  json.set("min", currentMinute.toInt());json.set("hour", currentHour.toInt());json.set("day", monthDay.toInt());json.set("month", currentMonth.toInt());json.set("year", currentYear.toInt());


  if (Firebase.ready()) {
    if(Firebase.setJSON(fbdo, "/14800/tekrar_sonuclar/" + monthDay + "/" + uid  ,json)) {
            uint8_t result;

          result = node.writeSingleRegister(4216,10);

    }
  }

}


/*


D120 = Test Sonucu var mı yok mu dinleme
D121/D122 = Reçetede ki Urun Kodu
D123 = Adlema Ön dolum Süresi
D124 = Adlema Doldurma Süresi
D125 = Adlema Stabilizasyon Süresi
D126 = Adlema Ön Dolum Basıncı
D127 = Test Basıncı 
D128/D129 = Reçete Max Kaçak Değeri*100
D130 = Adlema 1 Sonuc
D131/ D132 = Adlema 1 Kaçan Değer
D133 = Adlema 2 Sonuc
D134/D135 = Adlema 2 Kaçan Değer
D136 = Adlema 3 Sonuc
D137/D138 = Adlema 3 Kaçan Değer
D139 = Adlema 4 Sonuc 
D140/D141 = Adlema 4 Kaçan Değer
D142/D143 = Urun Boyu 
D144 = Test Süresi 
D145 =  Reçete Grup No
D146/D147 = Reserv

*/