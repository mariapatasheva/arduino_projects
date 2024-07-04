volatile long counter = 0;
unsigned long counter_nm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  attachInterrupt(0, btnIsr, CHANGE);
  attachInterrupt(1, btnIsr, CHANGE);
}

void btnIsr() {
  counter++;
}

void loop() {
  counter_nm = counter * 100;
  Serial.println("Пройденное расстояние: " + String(counter_nm) + " nm");
  delay(1000);
}
