bool a_new_clock;
bool a_old_clock;
bool b_new_clock;
bool b_old_clock;
bool z_new_clock;
bool z_old_clock;

long a_up = 0;
long time_var = 0;
long a_down = 0;
long b_up = 0;
long b_down = 0;
long z_up = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(2, INPUT); //Канал A
  pinMode(3, INPUT); //Канал B
  pinMode(4, INPUT); //Канал Z
  Serial.println ("Вас приветствует парсер оптической линейки DC13-100mm 0.1um");
  Serial.println ("Программа подсчитывает фронты и спады каналов A и B, а также фронты канала Z");
  Serial.println ("По принципу - все че мог, козЕл");

  a_old_clock = digitalRead(2);
  b_old_clock = digitalRead(3);
  z_old_clock = digitalRead(4);
}

void loop() {

  if (digitalRead(2) == 0) {
    a_new_clock = 0;
    if (a_old_clock > a_new_clock) a_down++; //спад канала a
    a_old_clock = 0;
    time_var ++;
  } else {
    a_new_clock = 1;
    if (a_new_clock > a_old_clock) a_up++; //фронт канала a
    a_old_clock = 1;
    time_var ++;
  }

  if (digitalRead(3) == 0) {
    b_new_clock = 0;
    if (b_old_clock > b_new_clock) b_down++; //спад канала b
    b_old_clock = 0;
  } else {
    b_new_clock = 1;
    if (b_new_clock > b_old_clock) b_up++; //фронт канала b
    b_old_clock = 1;
  }

   if (digitalRead(4) == 0) {
    z_new_clock = 0;
    z_old_clock = 0;
   } else {
     z_new_clock = 1;
     if (z_new_clock > z_old_clock) z_up++; //фронт канала z
     z_old_clock = 1;
   }
      if (time_var > 100000)
      {
        Serial.println ("Фронты канала A:" + String(a_up));
        Serial.println ("Спады канала A:" + String(a_down)); 
        Serial.println ("Фронты канала B:" + String(b_up));
        Serial.println ("Спады канала B:" + String(b_down)); 
        Serial.println ("Фронты канала Z:" + String(z_up));
        time_var = 0;
      }
}
