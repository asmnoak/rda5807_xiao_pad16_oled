//**********************************************************************************************************
//*    rda5807_xiao_pad16_oled -- DSP FM Radio with 4x4 Keypad which is controlled by Seeeduino XIAO
//*
//  2022/10/6 created by asmaro

#include <RDA5807.h>
#include <Keypad_MC17.h>
#include <Wire.h>
#include <Keypad.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2CADDR 0x20    // keypad IC
#define MIN_ELAPSED_TIME 100

#define OLED_I2C_ADDRESS 0x3C   // Check the I2C bus of your OLED device
#define SCREEN_WIDTH 128        // OLED display width, in pixels
#define SCREEN_HEIGHT 64        // OLED display height, in pixels
#define OLED_RESET -1           // Reset pin # (or -1 if sharing Arduino reset pin)

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad 
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad 

//Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Keypad_MC17 keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS, I2CADDR );
//OLED
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

long elapsedButton = millis();
long elapsedPull = millis();
char lastKey;
int  vol;
int  stnIdx;
int  stnFreq[] = {8040, 8250, 8520, 9040, 9150, 7620, 7810, 7860}; // frequency of radio station
String  stnName[] = {"AirG", "NW", "NHK", "STV", "HBC", "sanka", "karos", "nosut"}; // name of radio station max 5 char
bool bassOnOff = false;
uint32_t currentFrequency;

// The array sizes below can be optimized. 
char oldFreq[15];
char oldMode[15];
char oldUnit[15];
char oldStep[15];
char oldRssi[15];
char oldVolume[15];
char oldStereo[15];
char oldBW[15];


RDA5807 radio;
void setup() {
    Serial.begin(9600);
    delay(100);
    Serial.println("start");
    Wire.begin(); //
    keypad.begin( );
    Serial.println("wire begin ok");
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS);
    
    oled.clearDisplay();
    oled.setTextColor(SSD1306_WHITE);
    Serial.println("oled OK");
    splash();
    Serial.println("splash");

    radio.setup(); // Stats the receiver with default valuses. Normal operation
    delay(500);
    radio.setBand(2); // 76MHz - 108MHz
    radio.setSpace(0); // 100KHz
    delay(300);
    
    radio.setVolume(2);
    vol=2;
    stnIdx = 3;
    radio.setFrequency(9040);  // default tune on 90.4 MHz  
    showStatus();
}

void splash()
{
  oled.setTextSize(2); // Draw 2X-scale text
  oled.setCursor(30, 10);
  oled.print("HELLOW!");
  oled.display();
  delay(300);
  oled.setCursor(30, 35);
  oled.print("FM RADIO");
  oled.display();
  delay(100);
}

void resetBuffer()
{
  oldFreq[0] = '\0';
  oldMode[0] = '\0';
  oldUnit[0] = '\0';
  oldStep[0] = '\0';
  oldRssi[0] = '\0';
  oldVolume[0] = '\0';
  oldStereo[0] = '\0';
  oldBW[0] = '\0';
}

void printValue(int col, int line, char *oldValue, char *newValue, int space, int textSize)
{
  int c = col;
  char *pOld;
  char *pNew;

  pOld = oldValue;
  pNew = newValue;

  oled.setTextSize(textSize);

  // prints just changed digits
  while (*pOld && *pNew)
  {
    if (*pOld != *pNew)
    {
      oled.setTextColor(SSD1306_BLACK);
      oled.setCursor(c, line);
      oled.write(*pOld);
      oled.setTextColor(SSD1306_WHITE);
      oled.setCursor(c, line);
      oled.write(*pNew);
    }
    pOld++;
    pNew++;
    c += space;
  }
  // Is there anything else to erase?
  oled.setTextColor(SSD1306_BLACK);
  while (*pOld)
  {
    oled.setCursor(c, line);
    oled.write(*pOld);
    pOld++;
    c += space;
  }
  // Is there anything else to print?
  oled.setTextColor(SSD1306_WHITE);
  while (*pNew)
  {
    oled.setCursor(c, line);
    oled.write(*pNew);
    pNew++;
    c += space;
  }

  // Save the current content to be tested next time
  strcpy(oldValue, newValue);
}

void showFrequency()
{
  char freq[15];
  char tmp[15];
  char *unit;
  char *bandMode;
  
  currentFrequency = radio.getFrequency()*10;

    sprintf(tmp, "%6.6lu", currentFrequency);
     
    freq[0] = tmp[0];
    freq[1] = tmp[1];
    freq[2] = tmp[2];
    freq[3] = '.';
    freq[4] = tmp[3];
    freq[5] = '\0';
    unit = (char *) "MHz";
    bandMode =  (char *) "FM";
   
  printValue(25, 0, oldFreq, freq, 12, 2); //
  printValue(0, 0, oldMode, bandMode, 12, 2); //
  printValue(89, 0, oldUnit, unit, 12, 2); //
  //showRSSI();

  oled.display();
}

void showVolume()
{
  char sVolume[15];
  sprintf(sVolume, "Vol:%2.2u", radio.getVolume());
  printValue(64, 32, oldVolume, sVolume, 10, 2); //
  oled.display();
}
void showRSSI()
{
  char sR[15];

  sprintf(sR,"S:%2.2i", radio.getRssi());
  //#### dBuV -> dB RSSI -> RS
  printValue(0, 32, oldRssi, sR, 12, 2); //
  oled.display();
}

void showStatus()
{
  oled.clearDisplay();
  resetBuffer();

  oled.drawLine(0, 17, 130, 17, SSD1306_WHITE);
  //oled.drawLine(0, 33, 130, 33, SSD1306_WHITE);

  showFrequency();

  showVolume();
  showRSSI();
  //showBandwidth();
  
  oled.display();
}

void loop() {
  //char customKey = customKeypad.getKey();
  char customKey = keypad.getKey();
  // Check button commands
  if ((millis() - elapsedButton) > MIN_ELAPSED_TIME)
  {
    // check if some button is pressed
    if (customKey){
      Serial.println(customKey);
      if (customKey == 'D') {
        if (lastKey == 'D') vol=vol+2;
        else vol++;
        if (vol > 15) vol = 15;
        radio.setVolume(vol);
        showVolume();
      }
      else if (customKey == '#') {
         if (lastKey == '#') vol=vol-2;
         else vol--;
        if (vol <=0) vol = 0;
        radio.setVolume(vol);
        showVolume();        
      }
      else if  (customKey == '0') {
        bassOnOff = ~bassOnOff;
        radio.setBass(bassOnOff);  // Bass boost ON/OFF
      }
      else if  (customKey == '*')
        ;  // 
      else {
         if  (customKey == '1') 
           stnIdx = 0;   
         else if  (customKey == '2') 
           stnIdx = 1;  
         else if  (customKey == '3') 
           stnIdx = 2;  
         else if  (customKey == 'A') 
           stnIdx = 3;
         else if  (customKey == '4') 
           stnIdx = 4;
         else if  (customKey == '5') 
           stnIdx = 5;
         else if  (customKey == '6') 
           stnIdx = 6;
         else if  (customKey == 'B') 
           stnIdx = 7;
          else if  (customKey == '7') 
           stnIdx = 1;
         else if  (customKey == '8') 
           stnIdx = 2;
         else if  (customKey == '9') 
           stnIdx = 3;
         else if  (customKey == 'C') 
           stnIdx = 4;
        else stnIdx = 1;
         //band[lastIdx].default_frequency = currentFrequency;
        radio.setFrequency(stnFreq[stnIdx]); 
        showStatus();   
        lastKey = customKey;
        elapsedButton = millis();
      }  
    }
  }
  delay(10);
}
