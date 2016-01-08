int strobe   = 9;
int clock   = 8;
int data    = 7;
int buttons = 0;

void setup() {
    Serial.begin(115200);
    pinMode(strobe, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(data,  INPUT);

    digitalWrite(strobe, LOW);
    digitalWrite(clock, LOW);
}

void loop() {
    buttons = 0;

    digitalWrite(strobe, HIGH);
    digitalWrite(strobe, LOW);

    buttons = digitalRead(data);

    for (int i = 0 ; i < 12 ; i++) {
        digitalWrite(clock, HIGH);
        buttons = buttons << 1;
        buttons = buttons + digitalRead(data) ;
        digitalWrite(clock, LOW);
    }

    Serial.println(buttons, BIN);
}


