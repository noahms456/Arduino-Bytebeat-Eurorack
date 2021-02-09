// one-line algorithmic music for eurorack
// see viznut's blog http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
// and http://www.youtube.com/watch?v=GtQdIYUtAHg&feature=related

// ported to arduino by stimmer
// adapted for my Arduino Nano-based Eurorack Module 
// Audio out on pin 10
// Inputs for pots on A1,A2
// Input for button on A3

 long t;
 int X=1;
 int Y=1;
 int Z=0;
 int Press=1;
 int button=0;

void setup() {
 TCCR1B = (TCCR1B & 0xf8) | 1;
 analogWrite(10,1);// sets digital pin 10 as analog output
 pinMode(A1, INPUT);// sets the analog pin 1 as input for pot
 pinMode(A2, INPUT);// sets the analog pin 2 as input for pot
 pinMode(7, INPUT);// sets the digital pin 7 as input
 Serial.begin(9600); // open the serial port at 9600 bps
}

void putb(byte b)
{
 static long m;
 long t;
while((t=micros())-m < 125);
 m=t;
 OCR1B=b;
 button==LOW;
 X=(analogRead(A1)/4);// X axis potentiometer 5k 0-255
 Y=(analogRead(A2)/4);// Y axis potentiometer 5k 0-255
 button=(digitalRead(7));// can't get this to do anything, yet. probably not grasping something
 if (button==HIGH) {Press++;t=0;}; 
}

void loop() {
  switch (Press) {
  case 1:
    // by viznut, modified by me for testing
    for(long t=0;;t++)
	  putb((t*((t>>12|t>>8)&X&t>>Y)));   
	break;
  
  case 2:
    // by tejeez
    for(long t=0;;t++)
	  putb(((-t&4095)*(255&t*(t&t>>13))>>12)+(127&t*(234&t>>8&t>>3)>>(3&t>>14)));
    
	break;
  
  case 3:
    // by tejeez
    
    for(long t=0;;t++)
    putb(t*(t>>11&t>>8&123&t>>3));
    
  break;
  
  case 4:
    // by visy (this one is not great!)
    
    for(long t=0;;t++)
    putb(t*((t>>9|t>>13)&25&t>>6));
    
  break;
  
  case 5:
    // by tejeez
    
    for(long t=0;;t++)
    putb((t*(t>>5|t>>8))>>(t>>16));
    
  break;
  
  case 6:
    // by xpansive
    
    for(long t=0;;t++)
    putb(((t*(t>>8|t>>9)&46&t>>8))^(t&t>>13|t>>6));
    
  break;
  
  case 7:
    // this one rocks by skurk (raer's version)
    
    for(long t=0;;t++)
    putb(((t&4096)?((t*(t^t%255)|(t>>4))>>1):(t>>3)|((t&8192)?t<<2:t)));
    
  break;
  
  case 8:
    // by viznut, xpansive, varjohukka
    
    for(long t=0;;t++)
    putb((t>>7|t|t>>6)*10+4*(t&t>>13|t>>6));
    
  break;
  
  case 9:
    // by miiro
    
    for(long t=0;;t++)
    putb(t*5&(t>>7)|t*3&(t*4>>10));
    
  break;
  
  case 10:
    // by red this one pretty good, also
    
    for(long t=0;;t++)
    putb((t|(t>>9|t>>7))*t&(t>>11|t>>9));
    
  break;
  
  case 11:
    // by viznut
    
    for(long t=0;;t++)
    putb((t>>6|t|t>>(t>>16))*10+((t>>11)&7));
    
  break;
  
  case 12:
    // by stimmer
    
    for(long t=0;;t++)
    putb((t*(4|7&t>>13)>>((~t>>11)&1)&128) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&127));
    
  break; 
  
  case 13:
    // statements
    
    for(long t=0;;t++)
    putb(((t&t>>8)+50)-((t&t>>23)));
    
  break;
  
  case 14:
    // ominous! edited from above by Me
    
    for(long t=0;;t++)
    putb((t>>7|t|t>>6)*10+4*(t&t>>13|t>>6)>>3);
    
  break;
  
  case 15:
    // by Me
  
    for(long t=0;;t++)
    putb(((t&t>>8)+50)-((t&t>>23)));
    
  break;
  
  case 16:
    // back to start
    Press=1;
 }
}
 

 // this collection came with the original code, with some mods by me
 // 1. t*((t>>12|t>>8)&63&t>>4)   // by viznut
 // 2. ((-t&4095)*(255&t*(t&t>>13))>>12)+(127&t*(234&t>>8&t>>3)>>(3&t>>14)) // by tejeez
 // 3. t*(t>>11&t>>8&123&t>>3)    // by tejeez
 // 4. t*((t>>9|t>>13)&25&t>>6)   // by visy (this one is not great!)
 // 5. (t*(t>>5|t>>8))>>(t>>16)   // by tejeez
 // 6. ((t*(t>>8|t>>9)&46&t>>8))^(t&t>>13|t>>6) // by xpansive
 // 7. ((t&4096)?((t*(t^t%255)|(t>>4))>>1):(t>>3)|((t&8192)?t<<2:t)) // this one rocks by skurk (raer's version)
 // 8. (t>>7|t|t>>6)*10+4*(t&t>>13|t>>6) // by viznut, xpansive, varjohukka
 // 9. t*5&(t>>7)|t*3&(t*4>>10) // by miiro
 // 10. (t|(t>>9|t>>7))*t&(t>>11|t>>9) // by red this one pretty good, also
 // 11. v=(v>>1)+(v>>4)+t*(((t>>16)|(t>>6))&(69&(t>>9))) // by pyryp (not added so I don't need to initiate more variables)
 // 12. (t>>6|t|t>>(t>>16))*10+((t>>11)&7)  //by viznut
 // 13. (t*(4|7&t>>13)>>((~t>>11)&1)&128) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&127) // by stimmer
 // 14. (t>>7|t|t>>6)*10+4*(t&t>>13|t>>6)>>3 // ominous! edited from above by me
 // 15. ((t&t>>8)+50)-((t&t>>23)) by me
 //
 // seems like if you add >>3 to any of these they just get better!
