
char c;

int to_NIDAQ = 8;

#define STX '@'
#define ETX '\n'
#define SEP '_'

int tot = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);

  pinMode(to_NIDAQ, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s1 = "";
  String s2 = "";
  bool rec = false;
  bool S1received = false;
  if (Serial1.available() > 30) {
    //Serial.println(Serial1.available());
    
    int it = 0;
    while(Serial1.available() > 0  && !S1received && it < 30){
      c = Serial1.read();
      it++;
      if (rec){
        if (c == ETX) {
          S1received = true;
        }
        else if (c == SEP){
          s1 += '\t';
        }
        else{
          s1 += c;
        }
      }
      if (c == STX){
        rec = true;
      }
    }
  }
  
  rec = false;
  bool S2received = false;
  if (Serial2.available() > 30) {
    //Serial.println(Serial1.available());
    
    int it = 0;
    while(Serial2.available() > 0  && !S2received && it < 30){
      c = Serial2.read();
      it++;
      if (rec){
        if (c == ETX) {
          S2received = true;
        }
        else if (c == SEP){
          s2 += '\t';
        }
        else{
          s2 += c;
        }
      }
      if (c == STX){
        rec = true;
      }
    }
  }
  if(!S1received){
    s1 = "0\t0";
  }
  if(!S2received){
    s2 = "0\t0";
  }
  String xy = s1 + '\t' + s2;
  //Serial.println(xy);

  int x0 = getValue(xy, '\t', 0).toInt();
  int y0 = getValue(xy, '\t', 1).toInt();
  int x1 = getValue(xy, '\t', 2).toInt();
  int y1 = getValue(xy, '\t', 3).toInt();
  
  int yaw = (x0 + x1)/2;
  int pitch = (y0 + y1)/2;
  int roll = (y0 - y1)/2;

  int speed = 125;//0-255
  analogWrite(to_NIDAQ, speed);
  tot = tot + pitch;
  Serial.println(String(yaw) + '\t' + String(pitch) + '\t' + String(roll)+ '\t' + String(tot));
  delay(10);
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
