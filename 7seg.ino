int p1=13;
int p2=2;
int p3=3;
int p4=4;
int p5=5;
int p7=7;
int p10=10;
int p11=11;
int p6=6;
int p8=8;
int p9=9;
int p12=12;

int test [] ={1,5,8,9};
int pins [] ={p3,p5,p10,p1,p2,p4,p7,p11};

byte seg4 = B00000000;
byte seg3 = B00000000;
byte seg2 = B00000000;
byte seg1 = B00000000;

String data;
char data_char_array [3];

void setup() {
  
Serial.begin(9600);

pinMode(p12, OUTPUT);
  digitalWrite(p12, LOW);

pinMode(p9, OUTPUT);
  digitalWrite(p9, LOW);
  
  pinMode(p6, OUTPUT);
  digitalWrite(p6, LOW);

pinMode(p8, OUTPUT);
  digitalWrite(p8, LOW);
  
  pinMode(p1, OUTPUT);
  digitalWrite(p1, LOW);

   pinMode(p2, OUTPUT);
  digitalWrite(p2, LOW);

  pinMode(p3, OUTPUT);
  digitalWrite(p3, LOW);

  pinMode(p4, OUTPUT);
  digitalWrite(p4, LOW);

  pinMode(p5, OUTPUT);
  digitalWrite(p5, LOW);

  pinMode(p7, OUTPUT);
  digitalWrite(p7, LOW);

  pinMode(p10, OUTPUT);
  digitalWrite(p10, LOW);

  pinMode(p11, OUTPUT);
  digitalWrite(p11, LOW);

}

void loop() {

while (Serial.available()) {

 data = Serial.readStringUntil('\n'); 
// for testing with serial monitor

 data.toCharArray(data_char_array,data.length()+1);

 for (int i=0;i<=3;i++){
  if  (data_char_array[i]=='0') {
  fill_byte(i,B00000011);
}
else if (data_char_array[i]=='1'){
  fill_byte(i,B10011111);
}
else if (data_char_array[i]=='2'){
  fill_byte(i,B00100101);
}
else if (data_char_array[i]=='3'){
  fill_byte(i,B00001101);
}
else if (data_char_array[i]=='4'){
  fill_byte(i,B10011001);
}
else if (data_char_array[i]=='5'){
  fill_byte(i,B01001001);
}
else if (data_char_array[i]=='6'){
  fill_byte(i,B01000001);
}
else if (data_char_array[i]=='7'){
  fill_byte(i,B00011111);
}
else if (data_char_array[i]=='8'){
  fill_byte(i,B00000000);
}
else if (data_char_array[i]=='9'){
  fill_byte(i,B00001001);
}
 }
}
  ssdisplay(1); //displaying the numbers on each segment while switching between segments at speed of 1ms 
}





void ssdisplay (int period) {
 digitalWrite(p6, HIGH);digitalWrite(p8, LOW);digitalWrite(p9, LOW);digitalWrite(p12, LOW);


for (int i=0;i<=7;i++) {
  digitalWrite(pins[i],bitRead(seg4,i));
  }
  
  delay(period);

digitalWrite(p6, LOW);digitalWrite(p8, HIGH);digitalWrite(p9, LOW);digitalWrite(p12, LOW);


for (int i=0;i<=7;i++) {
  digitalWrite(pins[i],bitRead(seg3,i));
  }
  
  delay(period);

digitalWrite(p6, LOW);digitalWrite(p8, LOW);digitalWrite(p9, HIGH);digitalWrite(p12, LOW);   


for (int i=0;i<=7;i++) {
  digitalWrite(pins[i],bitRead(seg2,i));
  }
  
  delay(period);
digitalWrite(p6, LOW);digitalWrite(p8, LOW);digitalWrite(p9, LOW);digitalWrite(p12, HIGH);


for (int i=0;i<=7;i++) {
  digitalWrite(pins[i],bitRead(seg1,i));
  }
  
  delay(period);
}

void get_byte_eq (int inp []) {
 for (int i =0;i<=3;i++) {
  
  switch (inp [i]) {
    
    case 0 :
    fill_byte(i,B00000011); //eq is the binary byte that represent 0
    case 1 :
    fill_byte(i,B10011111); //eq is the binary byte that represent 1
    case 2 :
    fill_byte(i,B00100101); //eq is the binary byte that represent 2
    case 3 :
    fill_byte(i,B00001101) ;//eq is the binary byte that represent 3
    case 4 :
    fill_byte(i,B10011001) ;//eq is the binary byte that represent 4
    case 5 :
    fill_byte(i,B01001001) ;//eq is the binary byte that represent 5
    case 6 :
    fill_byte(i,B01000001) ;//eq is the binary byte that represent 6
    case 7 :
    fill_byte(i,B00011111) ;//eq is the binary byte that represent 7
    case 8 :
    fill_byte(i,B00000000) ;//eq is the binary byte that represent 8
    case 9 :
    fill_byte(i,B00001001) ;//eq is the binary byte that represent 9
    default :
    break;
  }
  }
    }


void fill_byte(int i,byte eq) {
 if (i == 0){
 seg1=eq;
 }
 else if (i == 1) {
 seg2=eq;
 } 
 else if (i == 2) {
 seg3=eq;
 }     
 else if (i == 3) {
 seg4=eq;
 }
      
    }
