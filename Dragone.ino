/**
 * (c) 2018 - 7kasper - MIT
 * -=== Dragone! ===-
 * Simple app for dragon stuff
 */

#include <IRremote.h>
#include <toneAC.h>

//IR Codes.
#define VOL_UP 0x10
#define VOL_DOWN 0x11
#define CHAN_UP 0x39
#define CHAN_DOWN 0x38
#define MUTE 0x0D
#define ARROWDOT 0x1E
#define SPEW 0x3E
#define POWER 0x0C

// Pins
#define RECV_PIN 2
#define FIRE_01 3
#define FIRE_02 4
#define FIRE_03 5
#define FIRE_04 6
#define EYE_01 7
#define EYE_02 8
#define BUZZER 9

// Notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Melodies:
// TUTUTUTUTU
int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
//SUNSHINE
int melody2[] = {  
  NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, 0, 
  NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_C4, 0,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_A4, 0,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, 0,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_A4, 0,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, 0,
  NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 0,
  NOTE_D4, NOTE_D4, NOTE_E4, NOTE_C4, 0
};
int noteDurations2[] = { 
  4, 4, 4, 8, 4, 16,
  4, 4, 4, 8, 4, 16,
  4, 4, 4, 8, 4, 16,
  4, 4, 4, 8, 16,
  4, 4, 4, 8, 4, 16,
  4, 4, 4, 8, 4, 16,
  4, 4, 4, 8, 4, 16,
  4, 4, 4, 8, 16
};
//MARIO
int melody3[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
int noteDurations3[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//PIRATES
int melody4[] = {
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4, 
   //Repeat of first part
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,
   //End of Repeat

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};
int noteDurations4[] = {
  10, 10, 5, 10, 10, 
  10, 10, 5, 10, 10,
  10, 10, 5, 10, 10,
  10, 10, 3, 10, 
  
  10, 10, 5, 10, 10, 
  10, 10, 5, 10, 10,
  10, 10, 5, 10, 10,
  10, 10, 3, 10, 
  
  10, 10, 5, 10, 10, 
  10, 10, 5, 10, 10,
  10, 10, 5, 10, 10,
  10, 10, 10, 5, 10,

  10, 10, 5, 10, 10, 
  5, 10, 5, 10, 
  10, 10, 5, 10, 10,
  10, 10, 3, 3,

  5, 10,
  //Rpeat of First Part
  10, 10, 5, 10, 10,
  10, 10, 5, 10, 10,
  10, 10, 3, 10, 
  
  10, 10, 5, 10, 10, 
  10, 10, 5, 10, 10,
  10, 10, 5, 10, 10,
  10, 10, 3, 10, 
  
  10, 10, 5, 10, 10, 
  10, 10, 5, 10, 10,
  10, 10, 5, 10, 10,
  10, 10, 10, 5, 10,

  10, 10, 5, 10, 10, 
  5, 10, 5, 10, 
  10, 10, 5, 10, 10,
  10, 10, 3, 3,
  //End of Repeat
  
  5, 10, 3, 5, 10, 3,
  10, 10, 10, 10, 10, 10, 10, 10, 3,
  5, 10, 3, 5, 10, 3,
  10, 10, 10, 10, 10, 2,

  5, 10, 3, 5, 10, 3,
  10, 10, 10, 10, 10, 10, 10, 10, 3,
  5, 10, 3, 5, 10, 3,
  10, 10, 10, 10, 10, 2
};

// Toggle values
bool burn = false;
bool look = false;
bool beep = false;

// Other settings
int volume = 5;

//Ir stuff
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  //Pins
  pinMode(FIRE_01, OUTPUT);
  pinMode(FIRE_02, OUTPUT);
  pinMode(FIRE_03, OUTPUT);
  pinMode(FIRE_04, OUTPUT);
  pinMode(EYE_01, OUTPUT);
  pinMode(EYE_02, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  //For Dragone readout.
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Dragone Started!");
}

void loop() {
  if (irrecv.decode(&results)) {
    int res = results.value & 0xFF;
    switch(res) {
      case POWER: {
        burnOff();
        eyesOff();
        break;
      }
      case 1: {
        playMelody(8, melody1, noteDurations1);
        break;
      }
      case 2: {
        playMelody(47, melody2, noteDurations2);
        break;
      }
      case 3: {
        playMelody(78, melody3, noteDurations3);
        break;
      }
      case 4: {
        playMelody(203, melody4, noteDurations4);
        break;
      }
      case SPEW: {
        bool wasBurning = burn;
        spew(random(45) + 5, 60);
        if (wasBurning) {
          burnOn();
        }
        break;
      }
      case VOL_UP: {
        if (volume < 9) {
          volume++;
          Serial.print("Volume increased to: ");
          Serial.println(volume);
          toneAC(1000, volume, 100);
        } else {
          toneAC(1000, volume, 100);
          delay(100);
          toneAC(1000, volume, 100);
        }
        break;
      }
      case VOL_DOWN: {
        if (volume > 1) {
          volume--;
          Serial.print("Volume decreased to: ");
          Serial.println(volume);
          toneAC(1000, volume, 100);
        } else {
          toneAC(1000, volume, 100);
          delay(100);
          toneAC(1000, volume, 100);
        }
        break;
      }
      case MUTE: {
        toneAC(500, 5, 100);
        delay(100);
        toneAC(500, 5, 100);
        volume = 0;
        break;
      }
      case CHAN_UP: {
         toggleEyes();
         break;
      }
      // Blink!
      case CHAN_DOWN: {
        bool wasLooking = look;
        eyesOff();
        delay(500);
        toneAC(500, volume);
        delay(600);
        noToneAC();
        delay(100);
        digitalWrite(EYE_02, HIGH);
        toneAC(1000, volume);
        delay(100);
        digitalWrite(EYE_02, LOW);
        noToneAC();
        delay(500);
        if (wasLooking) {
          eyesOn();
        }
        break;
      }
      case ARROWDOT: {
        burn = !burn;
        if (burn) {    
          digitalWrite(FIRE_01, HIGH);
          digitalWrite(FIRE_02, HIGH);
          digitalWrite(FIRE_03, HIGH);
          digitalWrite(FIRE_04, HIGH);
        } else {
          digitalWrite(FIRE_01, LOW);
          digitalWrite(FIRE_02, LOW);
          digitalWrite(FIRE_03, LOW);
          digitalWrite(FIRE_04, LOW);
        }
        break;
      }
      default: {
        break;
      }
    }
    Serial.println(res, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(400);
}

void spew(int flames, int timeForFlame) {
   for(int i = 0; i < flames; i++) {
    toneAC(200+random(50), volume);
    int firePatern1 = random(50);
    int firePatern2 = random(50);
    int firePatern3 = random(50);
    int firePatern4 = random(50);
    burnOff();
    for(int k = 0; k < timeForFlame; k++) {
      if(k == firePatern1) {
        digitalWrite(FIRE_01, HIGH);
      }
      if(k == firePatern2) {
        digitalWrite(FIRE_02, HIGH);
      }
      if(k == firePatern3) {
        digitalWrite(FIRE_03, HIGH);
      }
      if(k == firePatern4) {
        digitalWrite(FIRE_04, HIGH);
      }
      delay(1);
    }
  }
  burnOff();
  noToneAC();
}

void toggleEyes() {
  if(look) {
    eyesOff();
  } else {
    eyesOn();
  }
}

void toggleBurn() {
  if(burn) {
    burnOff();
  } else {
    burnOn();
  }
}

void playMelody(int melodyLength, int melody[], int durations[]) {
   for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
      int noteDuration = 1000/durations[thisNote];
      toneAC(melody[thisNote], volume, noteDuration, true);
      delay(noteDuration * 4 / 3);
   }
}

void burnOn() {
  burn = true;
  digitalWrite(FIRE_01, HIGH);
  digitalWrite(FIRE_02, HIGH);
  digitalWrite(FIRE_03, HIGH);
  digitalWrite(FIRE_04, HIGH);
}

void burnOff() {
  burn = false;
  digitalWrite(FIRE_01, LOW);
  digitalWrite(FIRE_02, LOW);
  digitalWrite(FIRE_03, LOW);
  digitalWrite(FIRE_04, LOW);
}

void eyesOn() {
  look = true;
  digitalWrite(EYE_01, HIGH);
  digitalWrite(EYE_02, HIGH);
}

void eyesOff() {
  look = false;
  digitalWrite(EYE_01, LOW);
  digitalWrite(EYE_02, LOW);
}
