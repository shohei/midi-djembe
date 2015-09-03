#include <MIDI.h>

int kick = 8;
int snare = 5;
int hihat = 7;

int led = 13;

int dtime = 30;

void HandleNoteOn(byte channel, byte note, byte velocity) { 
  // handle only rhythm track
  if(channel==10){
      if(note==36){
      playKick();
//      if (velocity == 0) {
//      //This acts like a NoteOff.
//      }
    } else if(note==38){
      playSnare();
    } else if(note==42){
      playHihat();
    }
  }
}

void setup() {
  pinMode(kick,OUTPUT);
  pinMode(snare,OUTPUT);
  pinMode(hihat,OUTPUT);

  pinMode(led,OUTPUT);

  MIDI.begin(MIDI_CHANNEL_OMNI);    
  MIDI.setHandleNoteOn(HandleNoteOn);
}


void loop() {
 MIDI.read();  
}

void flash(){
  digitalWrite(led,HIGH);
  delay(dtime);
  digitalWrite(led,LOW);
}

void playKick(){
  digitalWrite(kick,HIGH);
  delay(dtime);
  digitalWrite(kick,LOW);
}

void playSnare(){
  digitalWrite(snare,HIGH);
  delay(dtime);
  digitalWrite(snare,LOW);  
}

void playHihat(){
  digitalWrite(hihat,HIGH);
  delay(dtime);
  digitalWrite(hihat,LOW);      
}

