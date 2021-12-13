  /**
 ******************************************************************************
 * @file     SparkPixels.ino:
 * @author   Kevin Carlborg
 * @version  V2.3.1
 * @date     Augudy-2017
 *           Fixed compile error with PI
 * 
 * @file     SparkPixels.ino:
 * @author   Kevin Carlborg
 * @version  V2.3
 * @date     November-2016
 *      New Mode: Just in time for Christmas. Ported over LedStripXmas from pololu.com
 *           https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
 * 
 * @file    SparkPixels.ino:
 * @author   Kevin Carlborg
 * @version  V2.2.2
 * @date     June-2016
 *      New Feature: Added deviceInfo Particle Cloud String - this info will be displayed
 *                   in the Spark Pixels app starting version 0.2.9.
 * 
 * @file    SparkPixels.ino:
 * @author   Kevin Carlborg
 * @version  V2.2.1
 * @date     23-March-2016 ~ 25-March-2016
 *      New Feature: Added deviceInfo Particle Cloud String
 * 
 * @file    SparkPixels.ino:
 *		New mode: CHEERLIGHTS, DIGI, COLORPULSE, ACIDDREAM, IFTTT WEATHER
 *		New setting: AUX Switches
 *		New Functions: transitionALl, transitionOne, transitionHelper, getTransitionStep, 
 *                     clamp, updateAuxSwitches, getAuxSwitchIndexFromID, makeAuxSwitchList,
 *                     resetVariables, hexToInt, randomPixelFill, getColorFromInteger, 
 *                     getHighestValFromRGB, lerpColor, randomPixelFill, cheerlights, 
 *                     iftttWeather
 *      Updated Cloud Function: Renamed the local "cloud" function *Function* to *FnRouter*
 *      New Feature: Added AUX Switches used to turn things on or off or switch between two 
 *                   options, i.e. switch between using a light sensor or the app to set 
 *                   LED brightness. The Auto Shut Off has migrated to use this function.
 *      New Funtion Description:
 *                   IFTTT WEATHER - search for the Spark Pixels recipe on ifttt.com or
 *                      create your own. Just setup your device to call the SetMode 
 *                      function with this input: M:IFTTT WEATHER,C6:0000FF,
 *                      Where 0000FF is the hex value for blue. Color must be in hex format
 *                      Oh, and Don't forget the ending comma,
 *                   CHEERLIGHTS - go to http://cheerlights.com/ 
 * @author   Kevin Carlborg
 * @version  V2.1.0
 * @date     01-Januray-2016 ~ 7-March-2016
 * 
 * @file    SparkPixels.ino:
 *      New Feature: Added REBOOT option in FnRouter. This is selectable in the app.
 *                   In the app, Just open the Particle Cloud Panel from the menu.
 *  * @author   Kevin Carlborg
 * @version  V2.2.0
 * @date     23-March-2016 ~ 25-March-2016
 * 
 * @file    SparkPixels.ino:
 *		New mode: CHEERLIGHTS, DIGI, COLORPULSE, ACIDDREAM, IFTTT WEATHER
 *		New setting: AUX Switches
 *		New Functions: transitionALl, transitionOne, transitionHelper, getTransitionStep, 
 *                     clamp, updateAuxSwitches, getAuxSwitchIndexFromID, makeAuxSwitchList,
 *                     resetVariables, hexToInt, randomPixelFill, getColorFromInteger, 
 *                     getHighestValFromRGB, lerpColor, randomPixelFill, cheerlights, 
 *                     iftttWeather
 *      Updated Cloud Function: Renamed the local "cloud" function *Function* to *FnRouter*
 *      New Feature: Added AUX Switches used to turn things on or off or switch between two 
 *                   options, i.e. switch between using a light sensor or the app to set 
 *                   LED brightness. The Auto Shut Off has migrated to use this function.
 *      New Funtion Description:
 *                   IFTTT WEATHER - search for the Spark Pixels recipe on ifttt.com or
 *                      create your own. Just setup your device to call the SetMode 
 *                      function with this input: M:IFTTT WEATHER,C6:0000FF,
 *                      Where 0000FF is the hex value for blue. Color must be in hex format
 *                      Oh, and Don't forget the ending comma,
 *                   CHEERLIGHTS - go to http://cheerlights.com/ 
 * @author   Kevin Carlborg
 * @version  V2.1.0
 * @date     01-Januray-2016 ~ 7-March-2016
 * 
 * @file    SparkPixels.ino:
 *		New mode: FLICKER
 *		New setting: Auto Shut Off enable/disable (through cloud function)
 *		New Functions: demo(), runMode(), setASO() 
 *      New Feature: Expanded modeStruct[] array to support up to 4 boolean switches
 *                  and a text input. Obviously text input is only good for Neopixel arrays. 
 *                  The switches can be used to turn mode options on and off.
 *                  Added switchTitleStruct[] array to define the switch titles in the app.
 *                  Added cloud controlled switch1, switch2, switch3, and switch4
 * @author   Kevin Carlborg
 * @version  V2.0.0
 * @date     18-November-2015 ~ 20-December-2015
 * 
 * @file     SparkPixels.ino
 *                  Added Demo Mode - Cycles through selected dynamic modes.
 *                  Restructured loop by adding runMode() function to handle
 *                  primary mode launches in the switch statement. This supports 
 *                  the Demo Mode.
 *                  Updated to Particle API calls instead of the depreciated 
 *                  Spark calls.
 *                  Removed the "&" from the STRING cloud variables - this fixes
 *                  the compiler Error: no matching function for call to 
 *                  ‘CloudClass::variable.
 *                  Other bew modes: CYCLECHASER, COLORCHASE, CHRISTMASTREE
 * @author   Kevin Carlborg
 * @version  V1.0.1
 * @date     06-August-2015 ~ 09-October-2015
 * 
 * @file     SparkPixels.ino
 * @authors  Kevin Carlborg
 * @version  V1.0.0
 * @date     14-July-2015
 * @brief    Neopixel strip Powered by the Spark Core
 *
 * @extended extra-examples.cpp from NEOPIXEL Library
 * @functions: colorAll,colorWipe,rainbow,rainbowCycle,theaterChase,Wheel 
 * @author   Phil Burgess
 * @version  V0.0.6
 * @date     NA
 ******************************************************************************
 Copyright (c) 2015 Kevin Carlborg  All rights reserved.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this program; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/
 
//#include "HttpClient/HttpClient.h"
#include "neopixel/neopixel.h"
#include "math.h"

//Global Defines
#define BUILD_FILE_NAME             "Spark Pixels"
#define BUILD_REVISION              "2.3.1"
#define MAX_PUBLISHED_STRING_SIZE   622    //defined by Particle Industries
#define GET_TEMP_ENABLED            FALSE   //Should we measure a temp sensor?
#define TIME_ZONE_OFFSET	        -5		//The offset to set your region's time correctly  -6
#define CLAMP_255(v) (v > 255 ? 255 : (v < 0 ? 0 : v))

#ifndef PI
#define PI  3.1415926535
#endif

//NEOPIXEL Defines
#define PIXEL_CNT 268 //268  //353 total
#define PIXEL_PIN D7
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_CNT, PIXEL_PIN, PIXEL_TYPE);


//EEPROM examples: https://github.com/wgbartley/word-clock-v2/blob/master/word-clock.ino
//https://community.particle.io/t/best-way-to-store-preference-in-flash/15016/15
//flash memory: https://community.particle.io/t/lets-get-non-volatile/2200/3
//#define EEPROM_

//EEPROM Address Defines
/*
#define EEPROM_ADDR_HAS_DATA        0
#define EEPROM_ADDR_TIME_ZONE_SIGN  1
#define EEPROM_ADDR_TIME_ZONE       2
#define EEPROM_ADDR_NUM_LEDS_HIGH   3
#define EEPROM_ADDR_NUM_LEDS_LOW    4
#define EEPROM_ADDR_PIXEL_PIN       5
*/
//#define EEPROM_ADDR_


/* ======================= ADD NEW MODE ID HERE. ======================= */
// Mode ID Defines
const uint8_t OFF             = 0;
const uint8_t NORMAL          = 1;      //credit: Kevin Carlborg
const uint8_t COLORALL        = 2;      //credit: Neopixel Library
const uint8_t CHASER          = 3;      //credit: Neopixel Library
const uint8_t ZONE            = 4;      //credit: Kevin Carlborg
const uint8_t COLORWIPE       = 5;      //credit: Neopixel Library
const uint8_t CYCLEWIPE       = 6;      //credit: Kevin Carlborg
const uint8_t STROBE          = 7;      //credit: Kevin Carlborg
const uint8_t RAINBOW         = 8;      //credit: Neopixel Library
const uint8_t THEATERCHASE    = 9;      //credit: Neopixel Library
const uint8_t FROZEN          = 10;     //credit: Kevin Carlborg
const uint8_t COLLIDE         = 11;     //credit: Kevin Carlborg
const uint8_t DEMO            = 12;     //credit: Kevin Carlborg
const uint8_t COLORFADE       = 13;     //credit: Kevin Carlborg
const uint8_t WARMFADE        = 14;     //credit: David Verlee
const uint8_t CYCLECHASER     = 15;     //credit: Kevin Carlborg
const uint8_t COLORCHASE      = 16;     //credit: Kevin Carlborg
const uint8_t CHRISTMASLIGHTS = 17;     //credit: Kevin Carlborg
const uint8_t CHRISTMASWREATH = 18;     //credit: Kevin Carlborg
const uint8_t FLICKER         = 19;     //credit: David Verlee
const uint8_t CHEERLIGHTS     = 20;     //credit: Werner Moecke
const uint8_t DIGI            = 21;     //credit: Kevin Carlborg
const uint8_t COLORPULSE      = 22;     //credit: Werner Moecke
const uint8_t ACIDDREAM       = 23;     //credit: Werner Moecke
const uint8_t IFTTTWEATHER    = 24;     //credit: Kevin Carlborg
const uint8_t CHRISTMASLOOP   = 25;		//credit: pololu.com
const uint8_t STOP            = 99;		//Pauses the LEDs for troubleshooting

typedef struct modeParams {
   uint8_t 	 modeId;
   char      modeName[20];      //Tell the android app what the mode title is
   uint8_t   numOfColors;       //Tell the android app home many colors to expect. Max number is 6
   uint8_t   numOfSwitches;     //Tell the android app home many switches to expect. Max number is 4
   bool      textInput;         //Tell the android app if a text input is needed
} modeParams;

const uint8_t MAX_NUM_COLORS = 6;
const uint8_t MAX_NUM_SWITCHES = 4;

/* ======================= ADD NEW MODE STRUCT HERE. ======================= */
//modeId and modeName should be the same name to prevent confusion
//Use this struct array to neatly organize and correlate Mode name with number of colors neede d,
//  the number of switches needed, and whether a text input is needed or not
//The Android app uses these parameters to help populate the view 
//and to know how many colors and switches and text input to ask to update
modeParams modeStruct[] =
{ 
    /*     modeId           modeName 	   #Colors #Switches  textInput
     *     -------------    -------------  ------- ---------  ----- */
        {  OFF,             "OFF",             0,      0,      FALSE  },
        {  NORMAL,          "NORMAL",          0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  ACIDDREAM,       "ACID DREAM",      0,      0,      FALSE  },  //credit: Werner Moecke
        {  CHASER,          "CHASER",          1,      0,      FALSE  },  //credit: Kevin Carlborg  
        {  CHEERLIGHTS,     "CHEERLIGHTS",     0,      0,      FALSE  },  //credit: Werner Moecke
        {  CHRISTMASLIGHTS, "CHRISTMASLIGHTS", 0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  CHRISTMASLOOP,   "CHRISTMASLOOP",   0,      0,      FALSE  },  //credit: pololu.com
        {  CHRISTMASWREATH, "CHRISTMASWREATH", 0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  CYCLECHASER,     "CYCLE CHASER",    0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  COLLIDE,         "COLLIDE",         0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  COLORALL,        "COLOR ALL",       1,      0,      FALSE  },  //credit: Neopixel Library
        {  COLORCHASE,      "COLOR CHASE",     2,      0,      FALSE  },  //credit: Kevin Carlborg
        {  COLORFADE,       "COLOR FADE",      0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  COLORWIPE,       "COLOR WIPE",      1,      0,      FALSE  },  //credit: Neopixel Library
        {  CYCLEWIPE,       "CYCLE WIPE",      0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  DEMO,            "DEMO",            0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  DIGI,            "DIGI",            0,      2,      FALSE  },  //credit: Kevin Carlborg
        {  FLICKER,         "FLICKER",         0,      0,      FALSE  },  //credit: David Verlee
        {  FROZEN,          "FROZEN",          0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  IFTTTWEATHER ,   "IFTTT WEATHER",   0,      0,      FALSE  },  //credit: Kevin Carlborg
        {  COLORPULSE,      "PULSE",           0,      0,      FALSE  },  //credit: Werner Moecke
        {  RAINBOW,         "RAINBOW",         0,      0,      FALSE  },  //credit: Neopixel Library
        //{  STROBE, 	    "STROBE",          1,      0,      FALSE  }, //intense, use at your own risk, uncomment code below
        {  THEATERCHASE,    "THEATERCHASE",    0,      0,      FALSE  },  //credit: Neopixel Library
	    {  WARMFADE,        "WARMFADE",        0,      0,      FALSE  },  //credit: David Verlee
	    {  ZONE,            "ZONE",            4,      0,      FALSE  },  //credit: Kevin Carlborg
	    {  STOP,            "STOP",            0,      0,      FALSE  },  //credit: Kevin Carlborg
    
};

typedef struct switchParams {
   uint8_t   modeId;
   char      switch1Title[20];
   char      switch2Title[20];
   char      switch3Title[20];
   char      switch4Title[20];
} switchParams;

/* ======================= ADD ANY REQUIRED SWITCH TITLES HERE ======================= */
// The Android app needs to know what the titles of the switches are
// The modeID MUST be the same as the modeID used up in the modeStruct[] array
// i.e. - If you declare a mode to have 3 switches in the modeStruct[] array above,
//          you should then have 3 titles declared here. 
switchParams switchTitleStruct[] = 
{ 
    /*     modeId           S1Title                S2Title                S3Title                S4Title 
     *     ---------------  ---------------------- ---------------------- ---------------------- ---------------------- */
	      {  DIGI,          "Random Fill",         "Fade In",         "",                    ""  },  //Don't forget the comma here for more than one mode
	   // {  TEST,            "Switch Title 1",      "Switch Title 2",      "Switch Title 3",      "Switch Title 4"  }
};


/* ======================= ADD NEW AUX SWITCH ID HERE. ======================= */
// AUX SWITCH ID Defines
const uint8_t ASO         = 0;
const uint8_t LIGHTSENSOR = 1;

typedef struct auxSwitchParams {
    uint8_t  auxSwitchId;
    bool     auxSwitchState;
    char     auxSwitchTitle[20];
    char     auxSwitchOnName[20];
    char     auxSwitchOffName[20];
} auxSwitchParams;

/** ======================= ADD NEW AUX SWITCH STRUCT HERE. =======================
 * Use these switches to turn things on and off or toggle bewteen two options
 * @Param auxSwitchId        The ID of the switch     
 * @Param auxSwitchState     set the default switch state here
 * @Param auxSwitchTitle     Title/Description of the switch read in by the app
 * @Param auxSwitchOnTitle   Title of the ON/TRUE state of the switch read in by the app
 * @Param auxSwitchOffTitle  Title of the OFF/FALSE state of the switch read in by the app
 */
auxSwitchParams auxSwitchStruct[] = 
{ 
     /*    auxSwitchId      auxSwitchState  auxSwitchTitle         auxSwitchOnName       auxSwitchOffName    
     *     ---------------  --------------  ---------------------- ---------------------- ----------------------*/
	    {  ASO,             TRUE,          "Auto Shut Off",       "ON",                  "OFF"                }, 
	    {  LIGHTSENSOR,     FALSE,         "Brightness Control",  "Light Sensor",        "App Controlled"     },
};

/* ========================= Local Aux Switch Flags =========================== */

bool autoShutOff;   //Should we shut off the lights at certain times? This is toggled from the app
                    //Configure the Auto Shut Off times in the loop() function 
bool brightnessControl;

/** An RGB color. */
typedef struct Color {
  unsigned char red, green, blue;

  Color(int r, int g, int b) : red(r), green(g), blue(b) {}
  Color() : red(0), green(0), blue(0) {}
} Color;


/** Overloaded != operator. */
bool operator!= (const Color& a, const Color& b) {
    if(a.red != b.red) return true;
    if(a.green != b.green) return true;
    if(a.blue != b.blue) return true;
    return false;
}

/** Overloaded == operator. */
bool operator== (const Color& a, const Color& b) {
    if(a.red != b.red) return false;
    if(a.green != b.green) return false;
    if(a.blue != b.blue) return false;
    return true;
}

//Preset speed constants
const int speedPresets[] = { 120, 100, 80, 70, 50, 30, 20, 10, 1};  //in mSec, slow to fast       

//Temp Sensor constants	
const double refVoltage = 3.3;    //Voltage used as reference for analogRead
const double MINFANTEMP = 100.0;  //Min Temp to turn fan on low speed in Deg Fahrenheit
const double MAXFANTEMP = 115.0;  //Max Temp to turn fan on max speed in Deg Fahrenheit
const double MAXTEMP = 140.0;     //Shut Off Temp in Deg Fahrenheit


//Time Interval constants          hh*mm*ss*ms    
unsigned long oneMinuteInterval =      1*60*1000;	//Read temp every minute
unsigned long oneHourInterval =     1*60*60*1000;  //auto off in 1 hr when night time
unsigned long oneDayInterval = 	   24*60*60*1000;  //time sync interval - 24 hours=
unsigned long iftttWeatherInterval =  10*60*1000;  //revert back to last mode for IFTTT Weather

//Program Flags
int currentModeID;	//This is the ID of the current mode selected - used in the case statement
int lastModeID;
int run;    	//Use this for modes that don't need to loop. Set the color, then stop sending commands to the pixels
int stop;   	//Use this to break out of sequence loops when changing to a new mode
bool firstLap;
bool resetFlag;

//Misc variables
int speed;	//not to be confused with speedIndex below, this is the local speed (delay) value
int timeZone = TIME_ZONE_OFFSET;
unsigned long previousMillis = 0;
unsigned long lastCommandReceived = 0;
unsigned long lastSync = 0;
uint32_t defaultColor;	//The NORMAL mode color
uint32_t color1;
uint32_t color2;
uint32_t color3;
uint32_t color4;
uint32_t color5;
uint32_t color6;
uint32_t c1, c2;
bool switch1;
bool switch2;
bool switch3;
bool switch4;
float redPrev;
float greenPrev;
float bluePrev;

/** Common colors */
const Color black          = Color(0x00, 0x00, 0x00);
const Color grey            = Color(0x92, 0x95, 0x91);
const Color yellow          = Color(0xff, 0xff, 0x14);
const Color incandescent    = Color(0xfd, 0xf5, 0xe6);  //This seems closer to incandescent color
const Color magenta         = Color(0xc2, 0x00, 0x78);  //#FF00FF
const Color orange          = Color(0xf9, 0x73, 0x06);  //#FFA500
const Color teal            = Color(0x02, 0x93, 0x86);
const Color cyan            = Color(0x02, 0xff, 0xff);
const Color red             = Color(0xe5, 0x00, 0x00);
const Color brown           = Color(0x65, 0x37, 0x00);
const Color pink            = Color(0xff, 0x81, 0xc0);
const Color lightpink       = Color(0xff, 0xc0, 0xcb);
const Color blue            = Color(0x03, 0x43, 0xdf);
const Color green           = Color(0x15, 0xb0, 0x1a);
const Color purple          = Color(0x7e, 0x1e, 0x9c);  //#800080
const Color white           = Color(0xff, 0xff, 0xff);

//Spark Pin Defines
const int FAN_PIN = A0;           //There is a fan in the project box in case it gets too hot in there
const int TEMP_SENSOR_PIN = A7;   //TMP36 sensor on this pin.
const int LIGHT_SENSOR_PIN = A6;  //Photo Resistor

//Spark Cloud Variables
int wifi = 0;   //used for general info and setup
int tHour=0;    //used for general info and setup
int speedIndex;     				//Let the cloud know what speed preset we are using
int brightness;                     //How bright do we want these things anyway
double measuredTemperature = 0.0;   //Let's see how hot our project box is getting since is has the power supply in there
char modeNameList[MAX_PUBLISHED_STRING_SIZE] = "None";        //Holds all mode info comma delimited. Use this to populate the android app
char modeParamList[MAX_PUBLISHED_STRING_SIZE] = "None";
char auxSwitchList[MAX_PUBLISHED_STRING_SIZE] = "None";
char deviceInfo[MAX_PUBLISHED_STRING_SIZE] = "";
char currentModeName[64] = "None";  //Holds current selected mode
char textInputString[64];           //Holds the Text for any mode needing a test input - only useful for a Neopixel Matrix
char debug[MAX_PUBLISHED_STRING_SIZE];                    //We might want some debug text for development
   
/* ======================= mode Specific Defines ======================= */
//ZONE mode Start and End Pixels
int zone1Start = 0;
int zone1End   = 59;
int zone2Start = 60;
int zone2End   = 141;
int zone3Start = 142;
int zone3End   = 219;
int zone4Start = 220;
int zone4End   = 267;

//CHASER mode specific Start and End Pixels, re-use some from ZONE mode
int ChaserZone3Section1End   = 177;
int chaserZone3Section2Start = 189;
#define CHASER_LENGTH   256

//Color Defines
#define RED   0xFF0000
#define GREEN 0x00FF00
#define PINK  0xFF00FF


/* ============ SetMode return  Defines  ====================== */
#define NO_CHANGE           1000
#define BRIGHTNESS_SET      1001
#define SPEED_SET           1002

/* ============ AUTO SHUT OFF (ASO) Defines for Cloud Function: Function ====================== */
#define ASO_CMD_ON        "ASO_ON"
#define ASO_CMD_OFF       "ASO_OFF"
#define ASO_CMD_STATUS    "ASO_STATUS"
#define ASO_STATUS_OFF          2000
#define ASO_STATUS_ON           2001

//FROZEN mode defines
int randomFlakes[(int)(PIXEL_CNT*0.1)]; // holds the snowflake positions no more than10% of total number of pixels

/* ========================= CHEERLIGHTS mode defines ======================== */
#define POLLING_INTERVAL 3000   // how often the photon polls the cheerlights API
#define RESPONSE_TIMEOUT 500	// the timeout (in ms) to wait for a response from the cheerlights API
TCPClient client;       // a TCP instance to let us query the cheerlights API over TCP
String hostname, path;  // the URL and path to cheerlights' thingspeak directory
String response;        // the response read from querying cheerlights' thingspeak directory
uint32_t lastCol;
bool connected;         // flag if we have a solid TCP connection
int requestTime, pollTime;

/* ========================= CHRISTMAS Stuff mode defines ======================== */
#define NUM_STATES  7  // number of patterns to cycle through
unsigned char pattern;
bool firstTime;
int randomPixel = 0;
Color colors[1];
unsigned int loopCount;
void christmasLoop(void);
void fade(unsigned char *val, unsigned char fadeTime);
void randomWalk(unsigned char val, unsigned char maxVal, unsigned char changeAmount, unsigned char directions);
void warmWhiteShimmer(unsigned char dimOnly);
void randomColorWalk(unsigned char initializeColors, unsigned char dimOnly);
void brightTwinkleColorAdjust(unsigned char *color);
void colorExplosionColorAdjust(unsigned char *color, unsigned char propChance, unsigned char *leftColor, unsigned char *rightColor);
void colorExplosion(unsigned char noNewBursts);
void gradient();
void brightTwinkle(unsigned char minColor, unsigned char numColors, unsigned char noNewBursts);
unsigned char collision(unsigned char numCollisions);

/* ========================= Transition function defines ======================== */
#define LINEAR  0
#define POLAR   1

/* ======================= Required Mode Prototypes =============================== */
void makeModeList(void);
void setZone1(uint32_t c);
void setZone2(uint32_t c);
void setZone3(uint32_t c);
void setZone4(uint32_t c);
void resetVariables(int modeIndex);
void setRandomSnowFlakes(int numFlakes);
void findRandomSnowFlakesPositions(int numFlakes);
void transitionAll(Color endColor, uint16_t method);
void arrayShuffle(int arrayToShuffle[], int arraySize);
void transitionOne(Color endColor, uint16_t index, uint16_t method);
void transitionHelper(Color startColor, Color endColor, uint16_t index, uint16_t method, int16_t numSteps, int16_t step);
int showPixels(void);
int hexToInt(char val);
int getTemperature(void);
int setNewMode(int newMode);
int updateAuxSwitches(int id);
int getModeIndexFromID(int id);
int isValidMode(String newMode);
int randomPixelFill(uint32_t c);
int getModeIndexFromName(String name);
int getSwitchTitleStructIndex(int modeId);
uint8_t fadeSqRt(float value);
uint8_t fadeSquare(float value);
uint8_t fadeLinear(float value);
uint8_t clamp(unsigned value, unsigned lowClamp, unsigned highClamp);
int16_t getTransitionStep(Color startColor, Color endColor, uint16_t method, int16_t numSteps, int16_t step, Color whichColor);
uint32_t Wheel(byte WheelPos);
uint32_t getHighestValFromRGB(Color col);
uint32_t lerpColor(uint32_t c1, uint32_t c2, uint32_t val, uint32_t minVal, uint32_t maxVal);
Color getColorFromInteger(uint32_t col);

/* ======================= Spark Pixel Mode Prototypes =============================== */
void cheerlights(void);
void christmasLights(void);
void christmasWreath(void);
void collide(void);
void colorPulse(void);
void cycleChaser(void);
void cycleLerp(void);
void cycleWipe(void);
void demo(uint32_t c);
void digi(void);
void fade(void);
void flicker(void);
void frozen(void);
void iftttWeather(uint32_t c);
void rainbow(void);
void rainbowCycle(void) ;
void strobe(uint32_t color);
void theaterChaseRainbow(void);
void warmFade(void);
int colorAll(uint32_t c);
int colorWipe(uint32_t c);
int colorChaser(uint32_t c);
int colorChase(uint32_t c1, uint32_t c2);
int colorZone(uint32_t c1, uint32_t c2, uint32_t c3, uint32_t c4);

//Don't connect to the cloud first so we can turn on the lights right away
SYSTEM_MODE(SEMI_AUTOMATIC);   

void setup() {
    Particle.function("SetMode",       SetMode);            // Completely Necessary, Do Not Delete
    Particle.function("SetText",       SetText);            // Completely Necessary, Do Not Delete
    Particle.function("Function",      FnRouter);           // Completely Necessary, Do Not Delete

    Particle.variable("debug",         debug);              // Completely Necessary, Do Not Delete
    Particle.variable("wifi",          wifi);              // Expendable
    Particle.variable("hour",          tHour);              // Expendable   
    Particle.variable("speed",         speedIndex);         // Completely Necessary, Do Not Delete
    Particle.variable("brightness",    brightness);         // Completely Necessary, Do Not Delete
    Particle.variable("temp",          measuredTemperature);// Needed if "Show Control Box Temp" is selected in the app
	Particle.variable("modeList",      modeNameList);       // Completely Necessary, Do Not Delete
	Particle.variable("modeParmList",  modeParamList);      // Completely Necessary, Do Not Delete
	Particle.variable("mode",          currentModeName);    // Completely Necessary, Do Not Delete
	Particle.variable("auxSwtchList",  auxSwitchList);      // Completely Necessary, Do Not Delete
	Particle.variable("deviceInfo",    deviceInfo);         // Completely Necessary, Do Not Delete
   
    
    pinMode(TEMP_SENSOR_PIN,INPUT);
    pinMode(LIGHT_SENSOR_PIN,INPUT);
    pinMode(PIXEL_PIN, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);
    
    analogWrite(FAN_PIN, 0); //Turn Fan off
    
    Serial.begin(9600);
    
	//Initialize
    color1 = color2 = color3 = color4 = color5 = color6 = 0;
    switch1 = switch2 = switch3 = switch4 = false;
    redPrev = greenPrev = bluePrev = 0;
    speedIndex = 5;
    speed = speedPresets[speedIndex];
    brightness = 250;
    run = false;
    stop = false;
    autoShutOff = false;
    resetFlag = false;
	setNewMode(getModeIndexFromID(NORMAL));
	//setNewMode(getModeIndexFromID(OFF));
	defaultColor = strip.Color(255,255,60);  // This seems close to incandescent color 
	lastSync = lastCommandReceived = previousMillis = millis();	//Take a time stamp
    c1 = Wheel(random(random(2, 256), random(2, 256)));
    c2 = Wheel(random(random(2, 256), random(2, 256)));

	strip.begin();     			//Start up the Neopixels     	
    //colorAll(defaultColor);     //Turn on the NORMAL Mode
    transitionAll(black,LINEAR);
    transitionAll(getColorFromInteger(defaultColor),LINEAR);
    Particle.connect();         //Now connect to the cloud
    Time.zone(timeZone);  //set time zone 
    
    //Clear the cloud list variables
	sprintf(modeNameList,"");
	sprintf(modeParamList,"");
    sprintf(auxSwitchList,"");

	getTemperature();
    tHour = Time.hour();	//used to check for correct time zone
    wifi = WiFi.RSSI();    //Sometime I want to see how good the wifi signal is
    
    //Assemble Spark Cloud available modes variable
    makeModeList();
    makeAuxSwitchList();
    makeDeviceInfo();
    
   // WiFi.selectAntenna(ANT_EXTERNAL);
   // WiFi.selectAntenna(ANT_AUTO);
}

void makeDeviceInfo(void) {
    char cBuff[60];
    
    IPAddress myIp = WiFi.localIP();
    sprintf(deviceInfo,"Local IP Address:\"%d.%d.%d.%d\",",myIp[0], myIp[1], myIp[2], myIp[3]);

    sprintf(cBuff,"SSID:\"%s\",",WiFi.SSID());
    strcat(deviceInfo,cBuff);

    sprintf(cBuff,"WiFi Strength:\"%i\",",wifi);
    strcat(deviceInfo,cBuff);

    sprintf(cBuff,"Firmware ID:\"%s\",",BUILD_FILE_NAME);
    strcat(deviceInfo,cBuff);
    
    sprintf(cBuff,"Firmware Rev:\"%s\",",BUILD_REVISION);
    strcat(deviceInfo,cBuff);
        
    sprintf(cBuff,"Particle Build Version:\"%s\",",System.version().c_str());
    strcat(deviceInfo,cBuff);
    
    sprintf(cBuff,"Free Memory (bytes):\"%i\",",System.freeMemory());
    strcat(deviceInfo,cBuff);
    
    sprintf(cBuff,"Current Time On Device:\"%i:%i:%i %s %s %i %i\",",Time.hour(),Time.minute(),Time.second(),getWeekDay(),getMonth(),Time.day(),Time.year());
    //sprintf(cBuff,"Current Time On Device:\"%s\",",Time.timeStr().c_str());
    strcat(deviceInfo,cBuff);
}

char* getWeekDay(void) {
    int weekDay = Time.weekday();   
    
    switch(weekDay) {
        case 1: return "Sun";
        case 2: return "Mon";
        case 3: return "Tue";
        case 4: return "Wed";
        case 5: return "Thu";
        case 6: return "Fri";
        case 7: return "Sat";
    }
    return "Not Found";
}

char* getMonth(void) {
    int month = Time.month();
    
    switch(month) {
        case 1: return "Jan";
        case 2: return "Feb";
        case 3: return "Mar";
        case 4: return "Apr";
        case 5: return "May";
        case 6: return "Jun";
        case 7: return "Jul";
        case 8: return "Aug";
        case 9: return "Sep";
        case 10: return "Oct";
        case 11: return "Nov";
        case 12: return "Dec";
    }
    return "Not Found";
}

void makeModeList(void) {
    for(int i=0;i<sizeof modeStruct / sizeof modeStruct[0];i++) {
        char cNameBuff[20];
		char cParamBuff[60];
		if(strlen(modeNameList)+strlen(modeStruct[i].modeName)+1 <= MAX_PUBLISHED_STRING_SIZE) {
            sprintf(cNameBuff,"%s;",modeStruct[i].modeName );
		    strcat(modeNameList,cNameBuff);
		}
		else {
		    sprintf(debug,"Error: modeNameList has reached max size limit");
		}
		
		if(modeStruct[i].numOfColors==0 && modeStruct[i].numOfSwitches==0 && modeStruct[i].textInput == FALSE) {
		    if(isThereEnoughRoomInModeParamList(2)) {
			    strcat(modeParamList,"N;");
		    } else { return; }
		}
		else {
			if(modeStruct[i].numOfColors > 0) {
				if(modeStruct[i].numOfColors > MAX_NUM_COLORS) {
					modeStruct[i].numOfColors = MAX_NUM_COLORS;
				}
				if(isThereEnoughRoomInModeParamList(4)) {
    				sprintf(cParamBuff,"C:%i",modeStruct[i].numOfColors);
    				strcat(modeParamList,cParamBuff);
    				if(modeStruct[i].numOfSwitches == 0 && modeStruct[i].textInput == FALSE) {
    					strcat(modeParamList,";");
    				}
    				else{
    					strcat(modeParamList,",");
    				}
				} else { return; }
			}
			if(modeStruct[i].numOfSwitches > 0) {
			    int switchTitleStructIdx = getSwitchTitleStructIndex(modeStruct[i].modeId);
			    //if(switchTitleStructIdx == -1)
			    //       break;
			    if(switchTitleStructIdx != -1) {
    				if(modeStruct[i].numOfSwitches > MAX_NUM_SWITCHES) {
    					modeStruct[i].numOfSwitches = MAX_NUM_SWITCHES;
    				}
    				if(modeStruct[i].numOfSwitches >= 1) {
    				    sprintf(cParamBuff,"S:%i,\"%s\"",modeStruct[i].numOfSwitches,switchTitleStruct[switchTitleStructIdx].switch1Title);
    				    //consider this instead: strncat(modeParamList,cParamBuff,MAX_PUBLISHED_STRING_SIZE-strlen(modeParamList)-1);
    				    if(isThereEnoughRoomInModeParamList(strlen(cParamBuff)+1)) {
    					    strcat(modeParamList,cParamBuff);
    				    } else { return; }    
    				}
    				if(modeStruct[i].numOfSwitches >= 2) {
    					sprintf(cParamBuff,"\"%s\"",switchTitleStruct[switchTitleStructIdx].switch2Title);
    					if(isThereEnoughRoomInModeParamList(strlen(cParamBuff)+1)) {
    					    strcat(modeParamList,cParamBuff);
    					} else { return; }    
    				}
    				if(modeStruct[i].numOfSwitches >= 3) {
    					sprintf(cParamBuff,"\"%s\"",switchTitleStruct[switchTitleStructIdx].switch3Title);
    					if(isThereEnoughRoomInModeParamList(strlen(cParamBuff)+1)) {
    					    strcat(modeParamList,cParamBuff);
    					} else { return; }    
    				}
    				if(modeStruct[i].numOfSwitches >= 4) {
    					sprintf(cParamBuff,"\"%s\"",switchTitleStruct[switchTitleStructIdx].switch4Title);
    					if(isThereEnoughRoomInModeParamList(strlen(cParamBuff)+1)) {
    					    strcat(modeParamList,cParamBuff);
    					} else { return; }    
    				}
    			    if(modeStruct[i].textInput == FALSE) {
    					strcat(modeParamList,";");
    				}
    				else{
    					strcat(modeParamList,",");
    				}
			    } else {
			        sprintf(cParamBuff,"S:E;");
    			    if(isThereEnoughRoomInModeParamList(strlen(cParamBuff)+1)) {
    				    strcat(modeParamList,cParamBuff);
    				} else { return; }    
			    }
			}
			if(modeStruct[i].textInput == TRUE) {
			    if(isThereEnoughRoomInModeParamList(3)) {
				    strcat(modeParamList,"T:;");
			    } else { return; }    
			}
		} 
    }
}

bool isThereEnoughRoomInModeParamList(int textSize) {
    if(strlen(modeParamList) + textSize + 1 <= MAX_PUBLISHED_STRING_SIZE) {
        return true;
    }
    int idx = strlen(modeParamList)-1;
	while(modeParamList[idx] != ',' && modeParamList[idx] != ';') {
		idx--;
	}
	modeParamList[idx] = ';';

    sprintf(debug,"Error: modeParamList has reached max size limit");
    
    return false;
}

int getSwitchTitleStructIndex(int modeId) {
    uint16_t i;
    for(i=0;i<sizeof switchTitleStruct / sizeof switchTitleStruct[0];i++) {
        if(switchTitleStruct[i].modeId == modeId)
            return i;
    }
    sprintf(debug,"Error: Missing Switch Titles for mode %s", modeStruct[getModeIndexFromID(modeId)].modeName);
    return -1;
}

// Uses the auxSwitchStruct to assemble the cloud attainable auxSwtchList variable
// Switch param order: "id,title,onName,offName,switchState;"
void makeAuxSwitchList(void) {
    sprintf(auxSwitchList,"");
    for(uint16_t i=0;i<sizeof auxSwitchStruct / sizeof auxSwitchStruct[0];i++) {
        char cNameBuff[62];
		if(strlen(auxSwitchList)+strlen(auxSwitchStruct[i].auxSwitchTitle)+strlen(auxSwitchStruct[i].auxSwitchOnName)+strlen(auxSwitchStruct[i].auxSwitchOffName)+9 <= MAX_PUBLISHED_STRING_SIZE) {
            sprintf(cNameBuff,"%i,%s,%s,%s,%i;",auxSwitchStruct[i].auxSwitchId,
                                                auxSwitchStruct[i].auxSwitchTitle,
                                                auxSwitchStruct[i].auxSwitchOnName,
                                                auxSwitchStruct[i].auxSwitchOffName,
                                                auxSwitchStruct[i].auxSwitchState ? 1 : 0 );
		    strcat(auxSwitchList,cNameBuff);
		}
		else {
		    sprintf(debug,"Error: auxSwitchList has reached max size limit");
		}
		
		//Update local Aux Switch variables
		if(-1 == updateAuxSwitches(auxSwitchStruct[i].auxSwitchId))
		    sprintf(debug,"Error: auxSwitch failed to update local variable");
    }
}

//delay (or speed) is passed 
void loop() {

    if(run)
    {
		stop = FALSE;
        if(currentModeID == DEMO) {
    	    demo();
        }
        else {
            runMode(currentModeID);
        }
    }
    
    if(resetFlag) {
        resetFlag = false;
        delay(200); //Need this here otherwise the Cloud Function returned response is null
        System.reset();
    }
    unsigned long currentMillis = millis();
 
 //sprintf(debug,"ASO %i",(int)auxSwitchStruct[getAuxSwitchIndexFromID(ASO)].auxSwitchState);
    //if(currentMillis - previousMillis > oneMinuteInterval) {
    if(currentMillis - previousMillis > 10000) {
        previousMillis = currentMillis;
        tHour = Time.hour();
        wifi = WiFi.RSSI(); 
        makeDeviceInfo();  	//Keep up to date with my Device Info

        if(GET_TEMP_ENABLED) {
            getTemperature();
            if(measuredTemperature < MINFANTEMP) {
    			//Turn fan Off
                analogWrite(FAN_PIN, 0); 
            }
            else if(measuredTemperature > MINFANTEMP && measuredTemperature <  MAXFANTEMP) {
    			//Turn fan on at low speed
                analogWrite(FAN_PIN, 100); 
            }
            else if(measuredTemperature >  MAXFANTEMP) {
    			//Turn fan on at full speed
                analogWrite(FAN_PIN, 255); 
            }
            if(measuredTemperature > MAXTEMP) {
    			//Turn fan on at full speed and turn Off the lights
                analogWrite(FAN_PIN, 255); 
    			setNewMode(getModeIndexFromID(OFF));
            }  
        }
    //Put other timing stuff in here to speed up main loop
        if (currentMillis - lastSync > oneDayInterval) {
            // Request time time synchronization from the Spark Cloud
           // sprintf(debug,"Last sync time = %i,", (int)(currentMillis - lastSync));
			Particle.syncTime();
            lastSync = currentMillis;
        }
        
       if(autoShutOff && (currentMillis - lastCommandReceived > oneHourInterval)) {
            //Auto Off Criteria
            //If it's Monday through Friday between 8am and 4pm or between 10pm and 5am any day, turn Off the lights
            if(((Time.weekday() >= 2 && Time.weekday() <=6) && (Time.hour() >= 8 && Time.hour() <= 16)) || (Time.hour() >= 23) || (Time.hour() <= 5)) {
                //No one is home or everyone is sleeping. So shut it down
   				lastCommandReceived = currentMillis;
   				setNewMode(getModeIndexFromID(OFF));
                run = TRUE;
            }
        }
    }
}

/*
void initializeEEPROM(void) {
    // See if this EEPROM has saved data
    if(EEPROM.read(0)==117) {
        // Set the time zone
        if(EEPROM.read(1)==0)
            timeZone = EEPROM.read(2)*-1;
        else
            timeZone = EEPROM.read(2);

        // Set the hour format
        if(EEPROM.read(3)==12)
            time12Hour = true;
        else
            time12Hour = false;

        EFFECT_MODE = EEPROM.read(4);
        LAST_EFFECT_MODE = EFFECT_MODE;

        color[0] = EEPROM.read(5);
        color[1] = EEPROM.read(6);
        color[2] = EEPROM.read(7);

        RAINBOW_DELAY = EEPROM.read(8);

    // If data has not been saved, "initialize" the EEPROM
    } else {
        // Initialize
        EEPROM.write(0, 117);
        // Time zone +/-
        EEPROM.write(1, 0);
        // Time zone
        EEPROM.write(2, 0);
        // Hour format
        EEPROM.write(3, 24);
        // Effect mode
        EEPROM.write(4, 0);
        // Red
        EEPROM.write(5, 0);
        // Green
        EEPROM.write(6, 255);
        // Blue
        EEPROM.write(7, 128);
        // Rainbow delay
        EEPROM.write(8, RAINBOW_DELAY);
    }
}
*/

/**Update local Aux Switch variables
 *  @id the Aux Switch ID to update
 *  @return current state of the switch (0 or 1)
 *  @return -1 if Switch ID was not found
 */
int updateAuxSwitches(int id) {
    switch(id) {
        case ASO:
            return autoShutOff = auxSwitchStruct[getAuxSwitchIndexFromID(id)].auxSwitchState;
        case LIGHTSENSOR:
            return brightnessControl = auxSwitchStruct[getAuxSwitchIndexFromID(id)].auxSwitchState;
    }
    return -1;
}

int runMode(int modeID) {
    
    switch (modeID) {
        case OFF:
    	    transitionAll(black,LINEAR);
    		break;
        case ACIDDREAM:
		    cycleLerp();
		    break;  
        case CHASER:
    	    colorChaser(color1);
    		break;
    	case CHEERLIGHTS:
		    cheerlights();
			break;
		case CHRISTMASLIGHTS:
    	    christmasLights();
    	    break;
    	case CHRISTMASLOOP:
    	    christmasLoop();
    	    break;
		case CHRISTMASWREATH:
    	    christmasWreath();
    	    break;
        case COLLIDE:
    	    collide();
    	    break;
        case COLORALL:
    	    //colorAll(color1);
    	    transitionAll(getColorFromInteger(color1),POLAR);
    	    break;
    	case COLORCHASE:    
    	    colorChase(color1, color2);
    	    break;
    	case COLORFADE:
    	    fade();
    	    break;
    	case COLORPULSE:
		    colorPulse();
		    break;
    	case COLORWIPE:
    	    colorWipe(color1);
    	    break;
    	case CYCLEWIPE:
    	    cycleWipe();
    	    break;    
        case DIGI:
		    digi();
		    break;
        case FROZEN:
    	    frozen();
    	    break;
    	case FLICKER:
    	    flicker();
    	    break;
    	case IFTTTWEATHER:
		    iftttWeather(color6);
    	    break;
    	case RAINBOW:
    	    rainbowCycle();
    	    break;
/*    	case STROBE:
    	    strobe(color1);
    	    break;*/    	
        case THEATERCHASE:
    	    theaterChaseRainbow();
    	    break;
    	case WARMFADE:    
    	    warmFade();
    	    break;
    	case ZONE:
    	    colorZone(color1, color2, color3, color4); 
    	    break;
    	case STOP:
    	    run = FALSE;
    	    break;
    	case NORMAL:
    	default:
		    //colorAll(defaultColor);
		    transitionAll(getColorFromInteger(defaultColor),LINEAR);
    		break;
    }
    return 1;
}


void resetVariables(int modeIndex) {
    switch (modeIndex) {
		case CHEERLIGHTS:
        	hostname = "api.thingspeak.com";
		    path = "/channels/1417/field/2/last.txt";
		    response = "";
		    pollTime = millis() + POLLING_INTERVAL;
		    lastCol = 0;
        	client.stop();
		    connected = client.connect(hostname, 80);
		    break;
		case CHRISTMASLOOP:
		    loopCount = 0;
		    brightness = 255;
		    pattern = 0;
		    //firstTime = false;
		    transitionAll(black, LINEAR);
		    break;
	    case IFTTTWEATHER:
	        transitionAll(black, LINEAR);
	        break;
		default:
			break;
    }    
}
void demo(void) {
    int mode;
    //Add the dynamic modes you want to cycle through in this array
    int modes2Cycle[] = {COLORFADE,COLORWIPE,RAINBOW,CYCLEWIPE,THEATERCHASE,FROZEN,COLLIDE,COLORFADE,WARMFADE,CHRISTMASLIGHTS,CHRISTMASWREATH,CHEERLIGHTS,DIGI,COLORPULSE, ACIDDREAM};
    const unsigned long modeInterval =  2*60*1000; //Adjust the lifespan for each mode to perform
    unsigned long lastTime =  millis();
    arrayShuffle(modes2Cycle, sizeof modes2Cycle / sizeof modes2Cycle[0]);
    for(mode=0;mode<sizeof modes2Cycle / sizeof modes2Cycle[0];mode++) {
        color1 = Wheel(random(255));
        color2 = Wheel(random(255));
        color3 = Wheel(random(255));
        color4 = Wheel(random(255));
        //sprintf(debug,"DemoInsideLoop-ArraySize=%i-ModeIndex=%i-Mode=%i",sizeof modes2Cycle / sizeof modes2Cycle[0], mode,modes2Cycle[mode]);
        while(millis() - lastTime < modeInterval) {
            runMode(modes2Cycle[mode]);
            if(stop == TRUE) {return;}
        }
        lastTime = millis();
    }
    
    //sprintf(debug,"DemoOutOfLoop-Mode=%i", mode);
    run = true; //in case it's off, let's turn it back on
}

int getTemperature(void){
    double measuredVoltage = refVoltage * analogRead(TEMP_SENSOR_PIN) / 4095.0;
    measuredTemperature = (measuredVoltage - 0.5) * 100.0;          //Celcius Temp
    measuredTemperature = (measuredTemperature * 9.0 / 5.0) + 32.0; //Convert to Fahrenheit

    return 1;
}

void arrayShuffle(int arrayToShuffle[], int arraySize) {
    uint16_t i; 
    char cbuff[20];

    for(i=0;i<arraySize;i++) {
        int r = random(0,arraySize);  // generate a random position
        int temp = arrayToShuffle[i]; 
        arrayToShuffle[i] = arrayToShuffle[r]; 
        arrayToShuffle[r] = temp;
        //sprintf(cbuff,"%i %i %s ", arraySize,r,modeStruct[getModeIndexFromID(arrayToShuffle[i])].modeName);
        //strcat(debug,cbuff);
    }
}

//Used in all modes to set the brightness, show the lights, process Spark events and delay
int showPixels(void) {
    if(brightnessControl) {
		int lightSensorValue = analogRead(LIGHT_SENSOR_PIN);
		brightness = map(lightSensorValue,0,2500,0,255); // takes the value and scales it from 0-2500 to 0-255
	}
	strip.setBrightness(brightness);
    strip.show();
    Particle.process();    //process Spark events
	return 1;
}


// Set all pixels in the strip to a solid color
int colorAll(uint32_t c) {
    uint16_t i; 
    run = FALSE;
  
    for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
    }
    showPixels();
    if(stop == TRUE) {return 0;}
 
    return 1;
}


void christmasLoop(void) {
   enum Pattern {
      WarmWhiteShimmer = 0,
      RandomColorWalk = 1,
      TraditionalColors = 2,
      ColorExplosion = 3,
      Gradient = 4,
      BrightTwinkle = 5,
      Collision = 6,
    };
    
    unsigned int maxLoops;  // go to next state when loopCount >= maxLoops
    unsigned int seed = random(30000);  // used to initialize random number generator


  if (loopCount == 0)
  {
    // whenever timer resets, clear the LED colors array (all off)
    /*for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, 0);
    }*/
    transitionAll(black, LINEAR);
  }
  
  if (pattern == WarmWhiteShimmer || pattern == RandomColorWalk)
  {
    // for these two patterns, we want to make sure we get the same
    // random sequence six times in a row (this provides smoother
    // random fluctuations in brightness/color)
    if (loopCount % 6 == 0)
    {
      seed = random(30000);
    }
    randomSeed(seed);
  }
  
  // call the appropriate pattern routine based on state; these
  // routines just set the colors in the colors array
  switch (pattern)
  {
    case WarmWhiteShimmer:
      // warm white shimmer for 300 loopCounts, fading over last 70
      maxLoops = 300;
      warmWhiteShimmer(loopCount > maxLoops - 70);
      break;
      
    case RandomColorWalk:
      // start with alternating red and green colors that randomly walk
      // to other colors for 400 loopCounts, fading over last 80
      maxLoops = 400;
      randomColorWalk(loopCount == 0 ? 1 : 0, loopCount > maxLoops - 80);
      break;
      
    case TraditionalColors:
      // repeating pattern of red, green, orange, blue, magenta that
      // slowly moves for 400 loopCounts
      maxLoops = 400;
      traditionalColors();
      break;
      
    case ColorExplosion:
      // bursts of random color that radiate outwards from random points
      // for 630 loop counts; no burst generation for the last 70 counts
      // of every 200 count cycle or over the over final 100 counts
      // (this creates a repeating bloom/decay effect)
      brightness = 255;
      maxLoops = 630; //630;
      colorExplosion((loopCount % 200 > 130) || (loopCount > maxLoops - 100));
      break;
      
    case Gradient:
      // red -> white -> green -> white -> red ... gradiant that scrolls
      // across the strips for 250 counts; this pattern is overlaid with
      // waves of dimness that also scroll (at twice the speed)
      maxLoops = 250;
      gradient();
      delay(6);  // add an extra 6ms delay to slow things down
      break;
      
    case BrightTwinkle:
      // random LEDs light up brightly and fade away; it is a very similar
      // algorithm to colorExplosion (just no radiating outward from the
      // LEDs that light up); as time goes on, allow progressively more
      // colors, halting generation of new twinkles for last 100 counts.
      maxLoops = 1200;
      if (loopCount < 400)
      {
        brightTwinkle(0, 1, 0);  // only white for first 400 loopCounts
      }
      else if (loopCount < 650)//650)
      {
        brightTwinkle(0, 2, 0);  // white and red for next 250 counts
      }
      else if (loopCount < 950)//950)
      {
        brightTwinkle(1, 2, 0);  // red, and green for next 250 counts
      }
      else
      {
        // red, green, blue, cyan, magenta, yellow for the rest of the time
        brightTwinkle(1, 6, loopCount > maxLoops - 100);
      }
      break;
      
    case Collision:
      // colors grow towards each other from the two ends of the strips,
      // accelerating until they collide and the whole strip flashes
      // white and fades; this repeats until the function indicates it
      // is done by returning 1, at which point we stop keeping maxLoops
      // just ahead of loopCount
      unsigned char numLoops = 8;
      if (!collision(numLoops)) {
        maxLoops = loopCount + 2;
        //sprintf(debug,"maxLoops:%i, loopCount=%i",maxLoops,loopCount);
      } else {
        maxLoops = loopCount - 2;
      }
      break;
  } 

  // update the LED strips with the colors in the colors array
  showPixels();
  if(stop == TRUE) {return; }
  run = true;
  delay(speed);
  loopCount++;  // increment our loop counter/timer.
  if(loopCount >= maxLoops) {
    loopCount = 0;
    pattern = ((unsigned char)(pattern+1))%NUM_STATES;  // advance to next pattern
  }
  //sprintf(debug,"loopcount:%i, pattern=%i",loopCount,pattern);
    
}


// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function fades val by decreasing it by an amount proportional
// to its current value.  The fadeTime argument determines the
// how quickly the value fades.  The new value of val will be:
//   val = val - val*2^(-fadeTime)
// So a smaller fadeTime value leads to a quicker fade.
// If val is greater than zero, val will always be decreased by
// at least 1.
// val is a pointer to the byte to be faded.
void fade(unsigned char *val, unsigned char fadeTime)
{
  if (*val != 0)
  {
    unsigned char subAmt = *val >> fadeTime;  // val * 2^-fadeTime
    if (subAmt < 1)
      subAmt = 1;  // make sure we always decrease by at least 1
    *val -= subAmt;  // decrease value of byte pointed to by val
  }
}


// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function applies a random walk to val by increasing or
// decreasing it by changeAmount or by leaving it unchanged.
// val is a pointer to the byte to be randomly changed.
// The new value of val will always be within [0, maxVal].
// A walk direction of 0 decreases val and a walk direction of 1
// increases val.  The directions argument specifies the number of
// possible walk directions to choose from, so when directions is 1, val
// will always decrease; when directions is 2, val will have a 50% chance
// of increasing and a 50% chance of decreasing; when directions is 3,
// val has an equal chance of increasing, decreasing, or staying the same.
void randomWalk(unsigned char *val, unsigned char maxVal, unsigned char changeAmount, unsigned char directions)
{
  //sprintf(debug,"loopCount:%i, col=%x",loopCount,val);
  unsigned char walk = random(directions);  // direction of random walk
  if (walk == 0)
  {
    // decrease val by changeAmount down to a min of 0
    if (*val >= changeAmount)
    {
      *val -= changeAmount;
    }
    else
    {
      *val = 0;
    }
  }
  else if (walk == 1)
  {
    // increase val by changeAmount up to a max of maxVal
    if (*val <= maxVal - changeAmount)
    {
      *val += changeAmount;
    }
    else
    {
      *val = maxVal;
    }
  }
}


// ***** PATTERN WarmWhiteShimmer *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function randomly increases or decreases the brightness of the 
// even red LEDs by changeAmount, capped at maxBrightness.  The green
// and blue LED values are set proportional to the red value so that
// the LED color is warm white.  Each odd LED is set to a quarter the
// brightness of the preceding even LEDs.  The dimOnly argument
// disables the random increase option when it is true, causing
// all the LEDs to get dimmer by changeAmount; this can be used for a
// fade-out effect.
void warmWhiteShimmer(unsigned char dimOnly)
{
  const unsigned char maxBrightness = 255;//120;  // cap on LED brighness
  const unsigned char changeAmount = 10;//2;   // size of random walk step

  for (int i = 0; i < strip.numPixels(); i += 2)
  {
    Color col = getColorFromInteger(strip.getPixelColor(i));
    // randomly walk the brightness of every even LED
    randomWalk(&col.red, maxBrightness, changeAmount, dimOnly ? 1 : 2);
    
    // warm white: red = x, green = 0.8x, blue = 0.125x
    col.green = col.red*4/5;  // green = 80% of red
    col.blue = col.red >> 3;  // blue = red/8
    strip.setPixelColor(i, strip.Color(col.red, col.green, col.blue));
    // every odd LED gets set to a quarter the brighness of the preceding even LED
    if (i + 1 < strip.numPixels())
    {
        strip.setPixelColor(i+1, strip.Color(col.red >> 2, col.green >> 2, col.blue >> 2));
    }
  }
}


// ***** PATTERN RandomColorWalk *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function randomly changes the color of every seventh LED by
// randomly increasing or decreasing the red, green, and blue components
// by changeAmount (capped at maxBrightness) or leaving them unchanged.
// The two preceding and following LEDs are set to progressively dimmer
// versions of the central color.  The initializeColors argument
// determines how the colors are initialized:
//   0: randomly walk the existing colors
//   1: set the LEDs to alternating red and green segments
//   2: set the LEDs to random colors
// When true, the dimOnly argument changes the random walk into a 100%
// chance of LEDs getting dimmer by changeAmount; this can be used for
// a fade-out effect.
void randomColorWalk(unsigned char initializeColors, unsigned char dimOnly)
{
  const unsigned char maxBrightness = 255;//180;  // cap on LED brightness
  const unsigned char changeAmount = 3;  // size of random walk step
  
  // pick a good starting point for our pattern so the entire strip
  // is lit well (if we pick wrong, the last four LEDs could be off)
  unsigned char start;
  switch (strip.numPixels() % 7)
  {
    case 0:
      start = 3;
      break;
    case 1:
      start = 0;
      break;
    case 2:
      start = 1;
      break;
    default:
      start = 2;
  }

  for (int i = start; i < strip.numPixels(); i+=7)
  {
    Color col = getColorFromInteger(strip.getPixelColor(i));
    if (initializeColors == 0)
    {
        //sprintf(debug,"loopCount:%i, i:%i, col=%i",loopCount,i,strip.getPixelColor(i));
      // randomly walk existing colors of every seventh LED
      // (neighboring LEDs to these will be dimmer versions of the same color)
      randomWalk(&col.red, maxBrightness, changeAmount, dimOnly ? 1 : 3);
      randomWalk(&col.green, maxBrightness, changeAmount, dimOnly ? 1 : 3);
      randomWalk(&col.blue, maxBrightness, changeAmount, dimOnly ? 1 : 3);
      strip.setPixelColor(i, strip.Color(col.red, col.green, col.blue));
      //delay(10000);
    }
    else if (initializeColors == 1)
    {
      // initialize LEDs to alternating red and green
      if (i % 2)
      {
        strip.setPixelColor(i, maxBrightness, 0, 0);
      }
      else
      {
        strip.setPixelColor(i, 0, maxBrightness, 0);
      }
    }
    else
    {
      // initialize LEDs to a string of random colors
     strip.setPixelColor(i, random(maxBrightness), random(maxBrightness), random(maxBrightness));
    }
    
   // col = getColorFromInteger(strip.getPixelColor(i));
    // set neighboring LEDs to be progressively dimmer versions of the color we just set
    if (i >= 1)
    {
      strip.setPixelColor(i-1, col.red >> 2, col.green >> 2, col.blue >> 2);  
    }
    if (i >= 2)
    {
      strip.setPixelColor(i-2, col.red >> 3, col.green >> 3, col.blue >> 3);
    }
    if (i + 1 < strip.numPixels())
    {
      strip.setPixelColor(i+1,strip.getPixelColor(i-1));
    }
    if (i + 2 < strip.numPixels())
    {
      strip.setPixelColor(i+2,strip.getPixelColor(i-2));
    }
  }
}


// ***** PATTERN TraditionalColors *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function creates a repeating patern of traditional Christmas
// light colors: red, green, orange, blue, magenta.
// Every fourth LED is colored, and the pattern slowly moves by fading
// out the current set of lit LEDs while gradually brightening a new
// set shifted over one LED.
void traditionalColors()
{
  // loop counts to leave strip initially dark
  const unsigned char initialDarkCycles = 10;
  // loop counts it takes to go from full off to fully bright
  const unsigned char brighteningCycles = 20;
  
  if (loopCount < initialDarkCycles)  // leave strip fully off for 20 cycles
  {
    return;
  }

  // if LED_COUNT is not an exact multiple of our repeating pattern size,
  // it will not wrap around properly, so we pick the closest LED count
  // that is an exact multiple of the pattern period (20) and is not smaller
  // than the actual LED count.
  unsigned int extendedLEDCount = (((strip.numPixels()-1)/20)+1)*20;

  for (int i = 0; i < extendedLEDCount; i++)
  {
    unsigned char brightness = (loopCount - initialDarkCycles)%brighteningCycles + 1;
    unsigned char cycle = (loopCount - initialDarkCycles)/brighteningCycles;

    // transform i into a moving idx space that translates one step per
    // brightening cycle and wraps around
    unsigned int idx = (i + cycle)%extendedLEDCount;
    if (idx < strip.numPixels())  // if our transformed index exists
    {
      if (i % 4 == 0)
      {
         int brightnessRed = 0;
         int brightnessGreen = 0;
         int brightnessBlue = 0;
        // if this is an LED that we are coloring, set the color based
        // on the LED and the brightness based on where we are in the
        // brightening cycle
        switch ((i/4)%5)
        {
           case 0:  // red
             //colors[idx].red = 200 * brightness/brighteningCycles; 
             //colors[idx].green = 10 * brightness/brighteningCycles; 
             //colors[idx].blue = 10 * brightness/brighteningCycles;  
             brightnessRed = 200 * brightness/brighteningCycles;
             brightnessGreen = 10 * brightness/brighteningCycles;
             brightnessBlue = 10 * brightness/brighteningCycles;
             break;
           case 1:  // green
             //colors[idx].red = 10 * brightness/brighteningCycles; 
             //colors[idx].green = 200 * brightness/brighteningCycles;  
             //colors[idx].blue = 10 * brightness/brighteningCycles; 
             brightnessRed = 10 * brightness/brighteningCycles;
             brightnessGreen = 200 * brightness/brighteningCycles;
             brightnessBlue = 10 * brightness/brighteningCycles;
             break;
           case 2:  // orange
             //colors[idx].red = 200 * brightness/brighteningCycles;  
             //colors[idx].green = 120 * brightness/brighteningCycles; 
             //colors[idx].blue = 0 * brightness/brighteningCycles; 
             brightnessRed = 200* brightness/brighteningCycles;
             brightnessGreen = 120 * brightness/brighteningCycles;
             brightnessBlue = 0 * brightness/brighteningCycles;
             break;
           case 3:  // blue
             //colors[idx].red = 10 * brightness/brighteningCycles; 
             //colors[idx].green = 10 * brightness/brighteningCycles; 
             //colors[idx].blue = 200 * brightness/brighteningCycles; 
             brightnessRed = 10 * brightness/brighteningCycles;
             brightnessGreen = 10 * brightness/brighteningCycles;
             brightnessBlue = 200 * brightness/brighteningCycles;
             break;
           case 4:  // magenta
             //colors[idx].red = 200 * brightness/brighteningCycles; 
             //colors[idx].green = 64 * brightness/brighteningCycles;  
             //colors[idx].blue = 145 * brightness/brighteningCycles; 
             brightnessRed = 200 * brightness/brighteningCycles;
             brightnessGreen = 64 * brightness/brighteningCycles;
             brightnessBlue = 145 * brightness/brighteningCycles;
             break;
        }
        strip.setPixelColor(idx, strip.Color(brightnessRed, brightnessGreen, brightnessBlue));
      }
      else
      {
        // fade the 3/4 of LEDs that we are not currently brightening
        Color colidx = getColorFromInteger(strip.getPixelColor(idx));
        fade(&colidx.red, 3);
        fade(&colidx.green, 3);
        fade(&colidx.blue, 3);
        strip.setPixelColor(idx, strip.Color(colidx.red, colidx.green, colidx.blue));
      }
    }
  }
}


// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// Helper function for adjusting the colors for the BrightTwinkle
// and ColorExplosion patterns.  Odd colors get brighter and even
// colors get dimmer.
void brightTwinkleColorAdjust(unsigned char *color)
{
    
  if (*color == 255)
  {
    // if reached max brightness, set to an even value to start fade
    *color = 254;
  }
  else if (*color % 2)
  {
    // if odd, approximately double the brightness
    // you should only use odd values that are of the form 2^n-1,
    // which then gets a new value of 2^(n+1)-1
    // using other odd values will break things
    *color = *color * 2 + 1;
    
  }
  else if (*color > 0)
  {
    fade(color, 4);
    if (*color % 2)
    {
      (*color)--;  // if faded color is odd, subtract one to keep it even
    }
  }
}


// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// Helper function for adjusting the colors for the ColorExplosion
// pattern.  Odd colors get brighter and even colors get dimmer.
// The propChance argument determines the likelihood that neighboring
// LEDs are put into the brightening stage when the central LED color
// is 31 (chance is: 1 - 1/(propChance+1)).  The neighboring LED colors
// are pointed to by leftColor and rightColor (it is not important that
// the leftColor LED actually be on the "left" in your setup).
void colorExplosionColorAdjust(unsigned char *color, unsigned char propChance, unsigned char *leftColor, unsigned char *rightColor)
{
    /*if(firstTime == false){
        firstTime = true;
        char cBuff[50];
        sprintf(cBuff," color2=%x, leftcolor2=%x, rightcolor2=%x",*color,*leftColor,*rightColor);
        strcat(debug,cBuff);

    }*/
  if (*color == 31 && random(propChance+1) != 0)
  {
    if (leftColor != 0 && *leftColor == 0)
    {
      *leftColor = 1;  // if left LED exists and color is zero, propagate
    }
    if (rightColor != 0 && *rightColor == 0)
    {
      *rightColor = 1;  // if right LED exists and color is zero, propagate
    }
  }
  brightTwinkleColorAdjust(color);
}


// ***** PATTERN ColorExplosion *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function creates bursts of expanding, overlapping colors by
// randomly picking LEDs to brighten and then fade away.  As these LEDs
// brighten, they have a chance to trigger the same process in
// neighboring LEDs.  The color of the burst is randomly chosen from
// among red, green, blue, and white.  If a red burst meets a green
// burst, for example, the overlapping portion will be a shade of yellow
// or orange.
// When true, the noNewBursts argument changes prevents the generation
// of new bursts; this can be used for a fade-out effect.
// This function uses a very similar algorithm to the BrightTwinkle
// pattern.  The main difference is that the random twinkling LEDs of
// the BrightTwinkle pattern do not propagate to neighboring LEDs.
void colorExplosion(unsigned char noNewBursts)
{
  Color coli;
  Color col0 = getColorFromInteger(strip.getPixelColor(0));;
  Color col1 = getColorFromInteger(strip.getPixelColor(1));;
  //if(firstTime == false){
//        sprintf(debug,"color1=%x, leftcolor1=%x, rightcolor1=%x,",col0.red,0,col1.red);
  //  }
  
  // adjust the colors of the first LED
  colorExplosionColorAdjust(&col0.red, 9, (unsigned char*)0, &col1.red);
  colorExplosionColorAdjust(&col0.green, 9, (unsigned char*)0, &col1.green);
  colorExplosionColorAdjust(&col0.blue, 9, (unsigned char*)0, &col1.blue);

  strip.setPixelColor(0, strip.Color(col0.red, col0.green, col0.blue));
  strip.setPixelColor(1, strip.Color(col1.red, col1.green, col1.blue));
  
  for (int i = 1; i < strip.numPixels() - 1; i++)
  {
    //  if(randomPixel == i)
     //   firstTime = false;
    // adjust the colors of second through second-to-last LEDs
    col0 = getColorFromInteger(strip.getPixelColor(i-1));
    coli = getColorFromInteger(strip.getPixelColor(i));
    col1 = getColorFromInteger(strip.getPixelColor(i+1));
   /* if(randomPixel == i && firstTime == false){
           //firstTime = true;
           char cBuff[50];
         sprintf(cBuff," i=%i, red=%x, green=%x, blue=%x,",i,coli.red, coli.green, coli.blue);
        strcat(debug,cBuff);
    }*/
    colorExplosionColorAdjust(&coli.red, 9, &col0.red, &col1.red);
    colorExplosionColorAdjust(&coli.green, 9, &col0.green, &col1.green);
    colorExplosionColorAdjust(&coli.blue, 9, &col0.blue, &col1.blue);
    /*if(randomPixel == i && firstTime == false){
           firstTime = true;
           char cBuff[50];
         sprintf(cBuff," i=%i, red=%x, green=%x, blue=%x,",i,coli.red, coli.green, coli.blue);
        strcat(debug,cBuff);
    }*/
    strip.setPixelColor(i-1, strip.Color(col0.red, col0.green, col0.blue));
    strip.setPixelColor(i, strip.Color(coli.red, coli.green, coli.blue));
    strip.setPixelColor(i+1, strip.Color(col1.red, col1.green, col1.blue));
  }
  
  // adjust the colors of the last LED
  col0 = getColorFromInteger(strip.getPixelColor(strip.numPixels()-1));
  col1 = getColorFromInteger(strip.getPixelColor(strip.numPixels()-2));
  colorExplosionColorAdjust(&col0.red, 9, &col1.red, (unsigned char*)0);
  colorExplosionColorAdjust(&col0.green, 9, &col1.green, (unsigned char*)0);
  colorExplosionColorAdjust(&col0.blue, 9, &col1.blue, (unsigned char*)0);
  
  strip.setPixelColor(strip.numPixels()-1, strip.Color(col0.red, col0.green, col0.blue));

  if (!noNewBursts)
  {
    // if we are generating new bursts, randomly pick one new LED
    // to light up
    for (int i = 0; i < 1; i++)
    {
      int j = random(strip.numPixels());  // randomly pick an LED
      Color colj = black;
      int rndCol = random(7);
       randomPixel = j;
      //switch(random(7))  // randomly pick a color
      switch(rndCol)  // randomly pick a color
      {
        // 2/7 chance we will spawn a red burst here (if LED has no red component)
        case 0:
        case 1:
          if (colj.red == 0)
          {
            colj.red = 1;
          }
          break;
        
        // 2/7 chance we will spawn a green burst here (if LED has no green component)
        case 2:
        case 3:
          if (colj.green == 0)
          {
            colj.green = 1;
          }
          break;

        // 2/7 chance we will spawn a white burst here (if LED is all off)
        case 4:
        case 5:
          if ((colj.red == 0) && (colj.green == 0) && (colj.blue == 0))
          {
            colj = (Color){1, 1, 1};
          }
          break;
        
        // 1/7 chance we will spawn a blue burst here (if LED has no blue component)
        case 6:
          if (colj.blue == 0)
          {
            colj.blue = 1;
          }
          break;
          
        default:
          break;
      }
      strip.setPixelColor(j, strip.Color(colj.red, colj.green, colj.blue));
      delay(50);
       /*if(firstTime == false){
           //firstTime = true;
           //randomPixel = j;
        sprintf(debug,"j\=%i, red=%x, green=%x, blue=%x,",j, colj.red, colj.green, colj.blue);
        }*/
    }
  }
}


// ***** PATTERN Gradient *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function creates a scrolling color gradient that smoothly
// transforms from red to white to green back to white back to red.
// This pattern is overlaid with waves of brightness and dimness that
// scroll at twice the speed of the color gradient.
void gradient()
{
  unsigned int j = 0;
  
  // populate colors array with full-brightness gradient colors
  // (since the array indices are a function of loopCount, the gradient
  // colors scroll over time)
  while (j < strip.numPixels())
  {
    // transition from red to green over 8 LEDs
    for (int i = 0; i < 8; i++)
    {
      if (j >= strip.numPixels()){ break; }
      //colors[(loopCount/2 + j + strip.numPixels())%strip.numPixels()] = (Color){160 - 20*i, 20*i, (160 - 20*i)*20*i/160};
      strip.setPixelColor((loopCount/2 + j + strip.numPixels())%strip.numPixels(), strip.Color(160 - 20*i, 20*i, (160 - 20*i)*20*i/160));
      j++;
    }
    // transition from green to red over 8 LEDs
    for (int i = 0; i < 8; i++)
    {
      if (j >= strip.numPixels()){ break; }
      //colors[(loopCount/2 + j + strip.numPixels())%strip.numPixels()] = (Color){20*i, 160 - 20*i, (160 - 20*i)*20*i/160};
      strip.setPixelColor((loopCount/2 + j + strip.numPixels())%strip.numPixels(), strip.Color(20*i, 160 - 20*i, (160 - 20*i)*20*i/160));
      j++;
    }
  }
  
  // modify the colors array to overlay the waves of dimness
  // (since the array indices are a function of loopCount, the waves
  // of dimness scroll over time)
  const unsigned char fullDarkLEDs = 5;//10;  // number of LEDs to leave fully off
  const unsigned char fullBrightLEDs = 5;  // number of LEDs to leave fully bright
  const unsigned char cyclePeriod = 14 + fullDarkLEDs + fullBrightLEDs;
  
  // if LED_COUNT is not an exact multiple of our repeating pattern size,
  // it will not wrap around properly, so we pick the closest LED count
  // that is an exact multiple of the pattern period (cyclePeriod) and is not
  // smaller than the actual LED count.
  unsigned int extendedLEDCount = (((strip.numPixels()-1)/cyclePeriod)+1)*cyclePeriod;

  j = 0;
  while (j < extendedLEDCount)
  {
    unsigned int idx;
    
    // progressively dim the LEDs
    for (int i = 1; i < 8; i++)
    {
      idx = (j + loopCount) % extendedLEDCount;
      if (j++ >= extendedLEDCount){ return; }
      if (idx >= strip.numPixels()){ continue; }
  
      //colors[idx].red >>= i;
      //colors[idx].green >>= i;
      //colors[idx].blue >>= i;      
      Color colidx = getColorFromInteger(strip.getPixelColor(idx));
      strip.setPixelColor(idx, strip.Color(colidx.red >>= i, colidx.green >>= i, colidx.blue >>= i));
    }
    
    // turn off these LEDs
    for (int i = 0; i < fullDarkLEDs; i++)
    {
      idx = (j + loopCount) % extendedLEDCount;
      if (j++ >= extendedLEDCount){ return; }
      if (idx >= strip.numPixels()){ continue; }
  
      //colors[idx].red = 0;
      //colors[idx].green = 0;
      //colors[idx].blue = 0;
      strip.setPixelColor(idx, strip.Color(0,0,0));
    }
    
    // progressively bring these LEDs back
    for (int i = 0; i < 7; i++)
    {
      idx = (j + loopCount) % extendedLEDCount;
      if (j++ >= extendedLEDCount){ return; }
      if (idx >= strip.numPixels()){ continue; }
  
      //colors[idx].red >>= (7 - i);
      //colors[idx].green >>= (7 - i);
      //colors[idx].blue >>= (7 - i);   
      Color colidx = getColorFromInteger(strip.getPixelColor(idx));
      strip.setPixelColor(idx, strip.Color(colidx.red >>= (7 - i), colidx.green >>= (7 - i), colidx.blue >>= (7 - i)));
    }
    
    // skip over these LEDs to leave them at full brightness
    j += fullBrightLEDs;
  }
}


// ***** PATTERN BrightTwinkle *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function creates a sparkling/twinkling effect by randomly
// picking LEDs to brighten and then fade away.  Possible colors are:
//   white, red, green, blue, yellow, cyan, and magenta
// numColors is the number of colors to generate, and minColor
// indicates the starting point (white is 0, red is 1, ..., and
// magenta is 6), so colors generated are all of those from minColor
// to minColor+numColors-1.  For example, calling brightTwinkle(2, 2, 0)
// will produce green and blue twinkles only.
// When true, the noNewBursts argument changes prevents the generation
// of new twinkles; this can be used for a fade-out effect.
// This function uses a very similar algorithm to the ColorExplosion
// pattern.  The main difference is that the random twinkling LEDs of
// this BrightTwinkle pattern do not propagate to neighboring LEDs.
void brightTwinkle(unsigned char minColor, unsigned char numColors, unsigned char noNewBursts)
{
  // Note: the colors themselves are used to encode additional state
  // information.  If the color is one less than a power of two
  // (but not 255), the color will get approximately twice as bright.
  // If the color is even, it will fade.  The sequence goes as follows:
  // * Randomly pick an LED.
  // * Set the color(s) you want to flash to 1.
  // * It will automatically grow through 3, 7, 15, 31, 63, 127, 255.
  // * When it reaches 255, it gets set to 254, which starts the fade
  //   (the fade process always keeps the color even).
  for (int i = 0; i < strip.numPixels(); i++)
  {
    Color coli = getColorFromInteger(strip.getPixelColor(i));
    brightTwinkleColorAdjust(&coli.red);
    brightTwinkleColorAdjust(&coli.green);
    brightTwinkleColorAdjust(&coli.blue);
    strip.setPixelColor(i, strip.Color(coli.red, coli.green, coli.blue));
  }
  
  if (!noNewBursts)
  {
    // if we are generating new twinkles, randomly pick four new LEDs
    // to light up
    for (int i = 0; i < 4; i++)
    {
      int j = random(strip.numPixels());
      //if (colors[j].red == 0 && colors[j].green == 0 && colors[j].blue == 0)
      if(strip.getPixelColor(j) == 0)
      {
        // if the LED we picked is not already lit, pick a random
        // color for it and seed it so that it will start getting
        // brighter in that color
        switch (random(numColors) + minColor)
        {
          case 0:
            //colors[j] = (Color){1, 1, 1};  // white
            strip.setPixelColor(j, strip.Color(1, 1, 1));
            break;
          case 1:
            //colors[j] = (Color){1, 0, 0};  // red
            strip.setPixelColor(j, strip.Color(1, 0, 0));
            break;
          case 2:
            //colors[j] = (Color){0, 1, 0};  // green
            strip.setPixelColor(j, strip.Color(0, 1, 0));
            break;
          case 3:
            //colors[j] = (Color){0, 0, 1};  // blue
            strip.setPixelColor(j, strip.Color(0, 0, 1));
            break;
          case 4:
            //colors[j] = (Color){1, 1, 0};  // yellow
            strip.setPixelColor(j, strip.Color(1, 1, 0));
            break;
          case 5:
            //colors[j] = (Color){0, 1, 1};  // cyan
            strip.setPixelColor(j, strip.Color(0, 1, 1));
            break;
          case 6:
            //colors[j] = (Color){1, 0, 1};  // magenta
            strip.setPixelColor(j, strip.Color(1, 0, 1));
            break;
          default:
            //colors[j] = (Color){1, 1, 1};  // white
            strip.setPixelColor(j, strip.Color(1, 1, 1));
        }
      }
    }
  }
}


// ***** PATTERN Collision *****
// Credit: https://github.com/pololu/pololu-led-strip-arduino/blob/master/examples/LedStripXmas/LedStripXmas.ino
// This function spawns streams of color from each end of the strip
// that collide, at which point the entire strip flashes bright white
// briefly and then fades.  Unlike the other patterns, this function
// maintains a lot of complicated state data and tells the main loop
// when it is done by returning 1 (a return value of 0 means it is
// still in progress).
unsigned char collision(unsigned char numCollisions)
{
  const unsigned char maxBrightness = brightness;//180;  // max brightness for the colors
  //const unsigned char numCollisions = 5;  // # of collisions before pattern ends
  static unsigned char state = 0;  // pattern state
  static unsigned int count = 0;  // counter used by pattern
  
  if (loopCount == 0)
  {
    state = 0;
  }
  
  if (state % 3 == 0)
  {
    // initialization state
    switch (state/3)
    {
      case 0:  // first collision: red streams
       // colors[0] = (Color){maxBrightness, 0, 0};
        strip.setPixelColor(0, strip.Color(maxBrightness,0,0));
        break;
      case 1:  // second collision: green streams
       // colors[0] = (Color){0, maxBrightness, 0};
        strip.setPixelColor(0, strip.Color(0,maxBrightness,0));
        break;
      case 2:  // third collision: blue streams
       // colors[0] = (Color){0, 0, maxBrightness};
        strip.setPixelColor(0, strip.Color(0,0,maxBrightness));
        break;
      case 3:  // fourth collision: warm white streams
        //colors[0] = (Color){maxBrightness, maxBrightness*4/5, maxBrightness>>3};
        strip.setPixelColor(0, strip.Color(maxBrightness, maxBrightness*4/5, maxBrightness>>3));
        break;
      default:  // fifth collision and beyond: random-color streams
       // colors[0] = (Color){random(maxBrightness), random(maxBrightness), random(maxBrightness)};
        strip.setPixelColor(0, strip.Color(random(maxBrightness), random(maxBrightness), random(maxBrightness)));
    }
    
    // stream is led by two full-white LEDs
    //colors[1] = colors[2] = (Color){255, 255, 255};
    strip.setPixelColor(1, strip.Color(255,255,255));
    strip.setPixelColor(2, strip.Color(255,255,255));
    // make other side of the strip a mirror image of this side
   // colors[strip.numPixels() - 1] = colors[0];
    //colors[strip.numPixels() - 2] = colors[1];
    //colors[strip.numPixels() - 3] = colors[2];
    strip.setPixelColor(strip.numPixels() - 1, strip.getPixelColor(0));
    strip.setPixelColor(strip.numPixels() - 2, strip.getPixelColor(1));
    strip.setPixelColor(strip.numPixels() - 3, strip.getPixelColor(3));
    
    state++;  // advance to next state
    count = 8;  // pick the first value of count that results in a startIdx of 1 (see below)
    return 0;
  }
  
  if (state % 3 == 1)
  {
    // stream-generation state; streams accelerate towards each other
    unsigned int startIdx = count*(count + 1) >> 6;
    unsigned int stopIdx = startIdx + (count >> 5);
    count++;
    if (startIdx < (strip.numPixels() + 1)/2)
    {
      // if streams have not crossed the half-way point, keep them growing
      for (int i = 0; i < startIdx-1; i++)
      {
        // start fading previously generated parts of the stream
        Color coli = getColorFromInteger(strip.getPixelColor(i));
        Color colj = getColorFromInteger(strip.getPixelColor(strip.numPixels() - i - 1));
        fade(&coli.red, 5);
        fade(&coli.green, 5);
        fade(&coli.blue, 5);
        fade(&colj.red, 5);
        fade(&colj.green, 5);
        fade(&colj.blue, 5);
        strip.setPixelColor(i, strip.Color(coli.red, coli.green, coli.blue));
        strip.setPixelColor(strip.numPixels() - i - 1, strip.Color(colj.red, colj.green, colj.blue));
      }
      for (int i = startIdx; i <= stopIdx; i++)
      {
        // generate new parts of the stream
        if (i >= (strip.numPixels() + 1) / 2)
        {
          // anything past the halfway point is white
          //colors[i] = (Color){255, 255, 255};
          strip.setPixelColor(i, strip.Color(255, 255, 255));
        }
        else
        {
          //colors[i] = colors[i-1];
          strip.setPixelColor(i, strip.getPixelColor(i - 1));
        }
        // make other side of the strip a mirror image of this side
        //colors[strip.numPixels() - i - 1] = colors[i];
        strip.setPixelColor(strip.numPixels() - i - 1, strip.getPixelColor(i));
      }
      // stream is led by two full-white LEDs
      //colors[stopIdx + 1] = colors[stopIdx + 2] = (Color){255, 255, 255};
      strip.setPixelColor(stopIdx + 1, strip.Color(255, 255, 255));
      strip.setPixelColor(stopIdx + 2, strip.Color(255, 255, 255));
      
      // make other side of the strip a mirror image of this side
      //colors[strip.numPixels() - stopIdx - 2] = colors[stopIdx + 1];
      //colors[strip.numPixels() - stopIdx - 3] = colors[stopIdx + 2];
      strip.setPixelColor(strip.numPixels() - stopIdx - 2, strip.getPixelColor(stopIdx + 1));
      strip.setPixelColor(strip.numPixels() - stopIdx - 3, strip.getPixelColor(stopIdx + 2));
    }
    else
    {
      // streams have crossed the half-way point of the strip;
      // flash the entire strip full-brightness white (ignores maxBrightness limits)
      /*for (int i = 0; i < strip.numPixels(); i++)
      {
        //colors[i] = (Color){255, 255, 255};
        strip.setPixelColor(i, strip.Color(255, 255, 255));
      }*/
      transitionAll(white,LINEAR);
      state++;  // advance to next state
    }
    return 0;
  }
  
  if (state % 3 == 2)
  {
    // fade state
    //if (colors[0].red == 0 && colors[0].green == 0 && colors[0].blue == 0)
    if(strip.getPixelColor(0) == 0)
    {
      // if first LED is fully off, advance to next state
      state++;
      
      // after numCollisions collisions, this pattern is done
      sprintf(debug,"state=%i, numCollisions=%i",state,numCollisions);
      return state >= 3*numCollisions;
    }
    
    // fade the LEDs at different rates based on the state
    for (int i = 0; i < strip.numPixels(); i++)
    {
        int fadeRed = 0;
        int fadeGreen = 0;
        int fadeBlue = 0;
        
      switch (state/3)
      {
        case 0:  // fade through green
          //fade(&colors[i].red, 3);
          //fade(&colors[i].green, 4);
          //fade(&colors[i].blue, 2);
          fadeRed = 3;
          fadeGreen = 4;
          fadeBlue = 2;
          break;
        case 1:  // fade through red
          //fade(&colors[i].red, 4);
          //fade(&colors[i].green, 3);
          //fade(&colors[i].blue, 2);
          fadeRed = 4;
          fadeGreen = 3;
          fadeBlue = 2;
          break;
        case 2:  // fade through yellow
          //fade(&colors[i].red, 4);
          //fade(&colors[i].green, 4);
          //fade(&colors[i].blue, 3);
          fadeRed = 4;
          fadeGreen = 4;
          fadeBlue = 3;
          break;
        case 3:  // fade through blue
          //fade(&colors[i].red, 3);
          //fade(&colors[i].green, 2);
          //fade(&colors[i].blue, 4);
          fadeRed = 3;
          fadeGreen = 2;
          fadeBlue = 4;
          break;
        default:  // stay white through entire fade
          //fade(&colors[i].red, 4);
          //fade(&colors[i].green, 4);
          //fade(&colors[i].blue, 4);
          fadeRed = 4;
          fadeGreen = 4;
          fadeBlue = 4;
        }
        Color coli = getColorFromInteger(strip.getPixelColor(i));
        fade(&coli.red, fadeRed);
        fade(&coli.green, fadeGreen);
        fade(&coli.blue, fadeBlue);
        strip.setPixelColor(i, strip.Color(coli.red, coli.green, coli.blue));
    }
  }
  
  return 0;
}


/**
 * Pick a random color, then randomly fill the whole strip with that color
 * But make sure the next color has some contrast from the current color
 * @randomPixelFill(): helper function to do the dirty work
 * @switch1 = Random Color Fill: Used in randomPixelFill() to fill the strip with random colors
 * @switch2 = Slow Transition: 
 */
void digi(void) {
    uint16_t i; 
    uint32_t nextCol;
    
    //Lets just assume all of the colors in the strip are the same color
    //This will be true on the second lap and if we aren't doing Random Fill
    uint32_t curCol = nextCol = strip.getPixelColor(0);  
    
    //Next color should have some contrast from the current color
    while(abs(nextCol - curCol) <= 45 ) {
       nextCol = Wheel(random(random(2, 256), random(2, 256)));
    }
    
    randomPixelFill(nextCol);
    //randomPixelFill(Wheel(random(random(2, 256), random(2, 256))))
    //randomPixelFill(Wheel(random(2, 256)));
     run = TRUE;
}

/**
 * digi() helper function
 * Randomly fills the whole strip with a selected color or a random color
 * @param c: Next Color to populate
 * @switch1 = Random Color Fill: Ignore the passed color and choose random colors for each pixel
 */
int randomPixelFill(uint32_t c) {
    uint16_t i; 
    uint32_t pulseRate;
    int pixelFillOrder[strip.numPixels()];
    
    for(i=0; i<strip.numPixels(); i++) {
        pixelFillOrder[i]=i;
    }
    arrayShuffle(pixelFillOrder, sizeof pixelFillOrder / sizeof pixelFillOrder[0]);
    for(i=0; i<strip.numPixels(); i++) {
        if(stop == TRUE) {return 0;}
        if(switch1) {c = Wheel(random(random(2, 256), random(2, 256)));}
        if(switch2) {
            transitionOne(getColorFromInteger(c),pixelFillOrder[i],POLAR);
        }
        else {
            strip.setPixelColor(pixelFillOrder[i], c);
            showPixels();
            delay(speed);
        }
    }
    return 1;
}

//breathing LED credit: http://sean.voisen.org/blog/2011/10/breathing-led-with-arduino/
void iftttWeather(uint32_t c) {
    if((millis() - lastCommandReceived) < iftttWeatherInterval) {
        int oldBrightness = brightness;
        float val = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;  //set "breathing" brightness level
        brightness = (int)val;
        colorAll(c);
        brightness = oldBrightness;
    }
    else {
        currentModeID = lastModeID;
        setNewMode(getModeIndexFromID(currentModeID));
    }
    run = true;
}
    	    
    	    
//Turn off all pixels then run a single color down the strip 
//One pixel at a time

int colorChaser(uint32_t c) {
    uint16_t i;
    run = FALSE;
    
    //Turn Off all pixels
    for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, 0);
    }
    strip.show();

    //Forward
    for(i=zone1Start; i<=ChaserZone3Section1End; i++) {
        strip.setPixelColor(i, c);
        if(i > zone1Start) {
            strip.setPixelColor(i-1, 0);
        }
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
    strip.setPixelColor(ChaserZone3Section1End, 0);
    for(i=zone4Start; i<=zone4End; i++) {
        strip.setPixelColor(i, c);
        strip.setPixelColor(i-1, 0);
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
    strip.setPixelColor(zone4End, 0);
    for(i=chaserZone3Section2Start; i<=zone3End; i++) {
        strip.setPixelColor(i, c);
        strip.setPixelColor(i-1, 0);
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
	
    //Reverse
    strip.setPixelColor(zone3End, 0);
	for(i=zone3End-1; i>=chaserZone3Section2Start; i--) {
        strip.setPixelColor(i, c);
        strip.setPixelColor(i+1, 0);
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
    strip.setPixelColor(chaserZone3Section2Start, 0);
    for(i=zone4End; i>=zone4Start; i--) {
        strip.setPixelColor(i, c);
        strip.setPixelColor(i+1, 0);
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
    strip.setPixelColor(zone4Start, 0);
    for(i=ChaserZone3Section1End; i>zone1Start; i--) {
        strip.setPixelColor(i, c);
        strip.setPixelColor(i+1, 0);
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
    return 1;
}

//Similar to THEATERCHASE but with only 2 selected colors 
//that alternate back and forth
int colorChase(uint32_t c1, uint32_t c2) {
    run = true;
    /* The number of pixels to turn on of each color in a row
    * i.e. pixNum=3 will turn the first 3 pixels c1 and then
    * then next 3 pixels c2, and the next 3 pixels c1, etc.  */
    uint8_t pixNum = 3; 
    uint16_t i;
    int speedfactor = 3;    //increase the delay time
    for (i=0; i < strip.numPixels(); i++) { 
      if(i%(pixNum*2)>=0 && i%(pixNum*2)<=(pixNum-1)) {
        strip.setPixelColor(i, c1 );
      }
      if(i%(pixNum*2)>=pixNum && i%(pixNum*2)<=((pixNum*2)-1)) {
        strip.setPixelColor(i, c2 );
      }
    }
    showPixels();
    if(stop == TRUE) {return 0;}
	delay(speed*speedfactor);
    for (i=0; i < strip.numPixels(); i++) {
      if(i%(pixNum*2)>=0 && i%(pixNum*2)<=(pixNum-1)) {
        strip.setPixelColor(i, c2 );
      }
      if(i%(pixNum*2)>=pixNum && i%(pixNum*2)<=((pixNum*2)-1)) {
        strip.setPixelColor(i, c1 );
      }
    }
    showPixels();
    if(stop == TRUE) {return 0;}
	delay(speed*speedfactor);
	return 1;
}

//A colored Christmas light string that twinkles
void christmasLights(void) {
    uint16_t i, f;
    run = true;
    int speedfactor = 12;    //increase the delay time
    for (f=0; f < 6; f++) {
        for (i=0; i < strip.numPixels(); i++) {
          if(i%6==0) {
            strip.setPixelColor(i, 255,0,0 );
          }
          if(i%6==1) {
            strip.setPixelColor(i, 255,255,0 );
          }
          if(i%6==2) {
            strip.setPixelColor(i, 0,255,0 );
          }
          if(i%6==3) {
            strip.setPixelColor(i, 0,255,255 );
          }
          if(i%6==4) {
            strip.setPixelColor(i, 0,0,255 );
          }
          if(i%6==5) {
            strip.setPixelColor(i, 255,0,255 );
          }
        }
        showPixels();
        if(stop == TRUE) {return;}
        delay(speed*speedfactor);
        for (int i=0; i < strip.numPixels(); i++) {
            if(i%6==f) {
                strip.setPixelColor(i, 0,0,0 );
            }
        }
        showPixels();
        delay(speed*speedfactor);
        if(stop == TRUE) {return;}
    }
}

/* I have my neopixles installed under my kitchen cabinets.
*  I have 4 specific cabinets (zones) and each cabinet can be 
*  a different color. Feel free to expand the number of zones.
*  the Android app supports a max of 6 zones
*/
int colorZone(uint32_t c1, uint32_t c2, uint32_t c3, uint32_t c4) {
    run = FALSE;
    
	setZone1(c1);
	setZone2(c2);
	setZone3(c3);
	setZone4(c4);
    showPixels();
    return 1;
}

void setZone1(uint32_t c) {
    uint16_t i;
    run = FALSE;
    
    for(i=zone1Start; i<=zone1End; i++) {
        strip.setPixelColor(i, c);
	}
}

void setZone2(uint32_t c) {
    uint16_t i;
    run = FALSE;
    
    for(i=zone2Start; i<=zone2End; i++) {
		strip.setPixelColor(i, c);
	}
}

void setZone3(uint32_t c) {
    uint16_t i;
    run = FALSE;
    
    for(i=zone3Start; i<=zone3End; i++) {
		strip.setPixelColor(i, c);
	}
}

void setZone4(uint32_t c) {
    uint16_t i;
    run = FALSE;
    
    for(i=zone4Start; i<=zone4End; i++) {
        strip.setPixelColor(i, c);
	}
}

//Pulse all dots with pseudo-random colors
void colorPulse() {
    uint32_t pulseRate;
	run = TRUE;

    for(int j=0; j<=c2; j++) {
        for(int i=0; i<strip.numPixels(); i++) {
            pulseRate = abs(255-(speed+j));
            strip.setPixelColor(i, Wheel(lerpColor(j, speed, pulseRate, 0, 255)));
        }
        if(pulseRate > 3840) {return;}  //Too fast - bail out.
        if(stop) {return;}
        showPixels();
		delay(speed);
    }
}

//ACID DREAM mode
//Fill the dots with patterns from colors interpolated between 2 random colors
void cycleLerp() {
    uint32_t rate;
	run = TRUE;

    for(int j=0; j<=c2; j++) {
        for(int i=0; i<strip.numPixels(); i++) {
            rate = abs(i-(speed+j));
            strip.setPixelColor(i, Wheel(lerpColor(j, c1, rate, 0, 255)));
        }
        if(rate > 7680) {return;}   //Gettin' weird - bail out.
        if(stop) {return;}
        showPixels();
		delay(speed);
    }
}

void christmasWreath(void) {
    double i;
    int speedFactor = 16;    //increase the delay time
    int currentBrightness = brightness;
    /*
    setZone1(RED); 
    setZone2(GREEN);
    setZone3(RED);
    setZone4(GREEN);
    if(fadeIn(speed*speedFactor) == 0) {return 0;}
    delay(speed*speedFactor);
    if(fadeOut(speed*speedFactor) == 0) {return 0;}
    setZone1(GREEN); 
    setZone2(RED);
    setZone3(GREEN);
    setZone4(RED);
    if(fadeIn(speed*speedFactor) == 0) {return 0;}
    delay(speed*speedFactor);
    if(fadeOut(speed*speedFactor) == 0) {return 0;}
*/    
    //fade in
    for (i=0; i < currentBrightness; i++) {
    //for (i=4.712; i < 10.995*currentBrightness/255; i+=0.001) {
        setZone1(RED); 
    	setZone2(GREEN);
    	setZone3(RED);
    	setZone4(GREEN);
    	brightness = i; // sin(i) * 127.5 + 127.5;
    	showPixels();
    	if(stop == TRUE) {return;}
    	delay(speedFactor*speed);
    }

    //fade out
	for (i=currentBrightness; i > 0; i-=2) {
        setZone1(RED); 
    	setZone2(GREEN);
    	setZone3(RED);
    	setZone4(GREEN);
    	brightness = i;
    	showPixels();
    	if(stop == TRUE) {return;}
    	delay(speedFactor*speed);
    }
    
    //alternator colors, fade in
    for (i=0; i < currentBrightness; i++) {
    //for (i=4.712; i < 10.995*currentBrightness/255; i+=0.001) {
        setZone1(GREEN); 
    	setZone2(RED);
    	setZone3(GREEN);
    	setZone4(RED);
    	brightness = i; // sin(i) * 127.5 + 127.5;
    	showPixels();
    	if(stop == TRUE) {return;}
    	delay(speedFactor*speed);
     }
    showPixels();
    
    //fade out
	for (i=currentBrightness; i > 0; i-=2) {
        setZone1(GREEN); 
    	setZone2(RED);
    	setZone3(GREEN);
    	setZone4(RED);
    	brightness = i;
    	showPixels();
    	if(stop == TRUE) {return;}
    	delay(speedFactor*speed);
    }

    brightness = currentBrightness;
	run = true;
}

void flicker(void) {
    uint16_t j;
    int flickerBrightness = random(127, 255);
    int flickerTime = random(1, 50);
    float flickerScale = (float)flickerBrightness / 255;
    float red = flickerScale * 255;
    float green = flickerScale * 80;
    float blue = flickerScale * 0;

   for (float i = 0; i < flickerTime; i++) {
        for (j=0; j < strip.numPixels(); j++) {
            strip.setPixelColor(j, (byte)(redPrev + (red-redPrev)/flickerTime*i), (byte)(greenPrev + (green-greenPrev)/flickerTime*i), (byte)(bluePrev + (blue-bluePrev)/flickerTime*i));
        }
        showPixels();
        if(stop == TRUE) {return;}
        delay(1);
    }
    redPrev = red;
    greenPrev = green;
    bluePrev = blue;
}


//Fill the dots one after the other with a color, wait (ms) after each one
int colorWipe(uint32_t c) {
    uint16_t i;
    run = FALSE;
  
    for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        showPixels();
        if(stop == TRUE) {return 0;}
		delay(speed);
    }
    return 1;
}

//use colorWipe to cycle through all the colors 
void cycleWipe(void) {
    uint16_t j;
    int returnValue=1;

    for(j=0; j<256; j+=15) {
        if(j%2==0) {
            returnValue = colorWipe(Wheel(j & 0xFF));
        }
        else {
            returnValue = colorWipe(Wheel((j+80) & 0xFF));
        }
        if(stop == TRUE || returnValue == 0) {return;}
		delay(speed);
    }
    //colorWipe turns off the run loop, so let's turn it back on
    run = true; 
}

//Dance Party Techno??
void strobe(uint32_t color) {
    int returnValue=1;

    returnValue = colorAll(color);				//Turn On all Pixels
    if(stop == TRUE || returnValue == 0) {return;}
	delay(speed);
    returnValue = colorAll(strip.Color(0,0,0));	//Turn Off all Pixels
    if(stop == TRUE || returnValue == 0) {return;}
	delay(speed);
    run = true;
}


void cheerlights(void) {
    int red, green, blue;
    bool headers;
    char lastChar;
    
    if((millis()-pollTime)<=POLLING_INTERVAL) {
        if(stop) {client.stop(); return;}
	    if(!Particle.connected) {
	        Particle.connect();
	        waitFor(Particle.connected, 1000);
	    }
	    else {
            //In order to allow changing the brightness at any moment
            strip.setBrightness(brightness);
            strip.show();
            //process Spark events
            Particle.process();
            delay(100);
	    }
	    //sprintf(debug, "pollinterval:%i, polltime:%i",POLLING_INTERVAL,millis()-pollTime);
    }
    else {
        if(connected) {
            pollTime=millis();
            client.print("GET ");
            client.print(path);
            client.println(" HTTP/1.0");
            client.print("Host: ");
            client.println(hostname);
            client.println("Content-Length: 0");
            client.println();
          	/*** DEBUG ***/
            //sprintf(debug, "connected");
        }
        else {
          	/*** DEBUG ***/
            //sprintf(debug, "not connected");
          
            if(stop) {client.stop(); return;}
            client.stop();
		    response = "";
		    if(!Particle.connected) {
		        Particle.connect();
		        waitFor(Particle.connected, 1000);
		    }
		    else {connected = client.connect(hostname, 80);}
        }
    
        requestTime=millis();
        while((client.available()==0)&&((millis()-requestTime)<RESPONSE_TIMEOUT)) {
            if(stop) {client.stop(); return;}
            Particle.process();    //process Spark events
        };
        
        headers=TRUE;
        lastChar='\n';
        response="";
    	while(client.available()>0) {
            if(stop) {client.stop(); return;}
    		char thisChar=client.read();
    		if(!headers)
    		    response.concat(String(thisChar));
    		else {
    			if((thisChar=='\r')&&(lastChar=='\n')) {
        			headers=FALSE;
        			client.read();  //kill that last \n
    			}
    			lastChar=thisChar;  
    		}
          	/*** DEBUG ***/
            //itoa(client.available(), debug, 10);
    	}

        //if there's a valid hex color string from Cheerlights, update the color
        if(response.length()==7) {
            //convert the hex values from the response.body string into byte values
    		red=hexToInt(response.charAt(1))*16+hexToInt(response.charAt(2));
    		green=hexToInt(response.charAt(3))*16+hexToInt(response.charAt(4));
    		blue=hexToInt(response.charAt(5))*16+hexToInt(response.charAt(6));
        	int col = strip.Color(red, green, blue);
        	Color color=Color(red, green, blue);
        	//actually update the color on the cube, with a cute animation
        	 if(col != lastCol) {
            	lastCol = col;
        	    int which = random(0, 3);
        	    if(stop) {client.stop(); return;}
        	    switch(which) {
        	        case 0:
        	            transitionAll(color,POLAR);
        	            break;
        	        case 1:
        	            colorWipe(col);
        	            break;
        	        case 2:
        	            randomPixelFill(col);
        	            break;
        	        case 3:
        	            
        	            break;
        	        case 4:
        	            //fillZ(col);
        	            break;
        	    }
        	 }
          	/*** DEBUG ***/
            //sprintf(debug, response);
            
        }
        else {
          	/*** DEBUG ***/
           //sprintf(debug, "no reply from host");
          	
            if(stop) {client.stop(); return;}
            client.stop();
		    response = "";
		    if(!Particle.connected) {
		        Particle.connect();
		        waitFor(Particle.connected, 1000);
		    }
		    else {connected = client.connect(hostname, 80);}
        }
    }
    //In order to allow changing the brightness at any moment
    strip.setBrightness(brightness);
    strip.show();
    Particle.process();    //process Spark events
    run = TRUE;
}

/** Convert a given hex color value (e.g., 'FF') to integer (e.g., 255)*/
int hexToInt(char val) {
    int v = (val > '9')? (val &~ 0x20) - 'A' + 10: (val - '0');
    return v;
}

void rainbow(void) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    showPixels();
    if(stop == TRUE) {return;}
	delay(speed);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout, then wait (ms)
void rainbowCycle(void) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 1 cycle of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    showPixels();
    if(stop == TRUE) {return;}
	delay(speed);
  }
}

//Theatre-style crawling lights with rai j, q, i;nbow effect
void theaterChaseRainbow(void) {
    uint16_t j, q, i;
  for (j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (q=0; q < 3; q++) {
        for (i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        showPixels();
        if(stop == TRUE) {return;}
		delay(speed);
        for (i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

//Fade from teal to blue to purple then back to blue then teal, repeat
//Random snowflakes twinkle white for random amounts of time 
//The snowflakes will hang around no faster than MIN_DELAY and no slower than MAX_DELAY
void frozen(void) {
  uint16_t i, j;
  uint16_t startColor = 140;    //Hue for teal
  uint16_t stopColor  = 210;    //Hue for purple
  const int MIN_DELAY = 400;	//in ms
  const int MAX_DELAY = 700;	//in ms
  const int MIN_FLAKES = strip.numPixels()*0.01;	//  1% of total number of pixels
  const int MAX_FLAKES = strip.numPixels()*0.1;	// 10% of total number of pixels
  int numSnowFlakes = random(MIN_FLAKES, MAX_FLAKES);	//How many flakes should we have at a time
  unsigned long previousMillis = millis();
  unsigned long flakeLifeSpan = random(MIN_DELAY, MAX_DELAY); //How long will a snowflake last

  //forwards
  for(j=startColor; j<stopColor; j++) { 	//cycle through the colors
    for(i=0; i< strip.numPixels(); i++) {	
        strip.setPixelColor(i, Wheel(j));	//first set all pixels to the same color
        if(millis() - previousMillis > flakeLifeSpan) {
			previousMillis = millis();						//reset time interval
			flakeLifeSpan = random(MIN_DELAY, MAX_DELAY);	//set new lifespan	
			numSnowFlakes = random(MIN_FLAKES, MAX_FLAKES); //set new number of flakes
            findRandomSnowFlakesPositions(numSnowFlakes);	//get the list of flake positions
        }
    }
	setRandomSnowFlakes(numSnowFlakes);	//now set the snowflake positions
	showPixels();
    if(stop == TRUE) {return;}
	delay(speed);
  }
  
  //backwards
  for(j=stopColor; j>startColor; j--) { 	//cycle through the colors
    for(i=0; i< strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(j));	//first set all pixels to the same color
        if(millis() - previousMillis > flakeLifeSpan) {
			previousMillis = millis();						//reset time interval
			flakeLifeSpan = random(MIN_DELAY, MAX_DELAY);	//set new lifespan	
			numSnowFlakes = random(MIN_FLAKES, MAX_FLAKES); //set new number of flakes
            findRandomSnowFlakesPositions(numSnowFlakes);	//get the list of flake positions
        }
    }
	setRandomSnowFlakes(numSnowFlakes);	//now set the snowflake positions
    showPixels();
    if(stop == TRUE) {return;}
	delay(speed);
  }
}

void setRandomSnowFlakes(int numFlakes)
{
    for(uint16_t i=0;i<numFlakes;i++) {
        strip.setPixelColor(randomFlakes[i], 0xFFFFFF); //Set snowflake
    }
}

void findRandomSnowFlakesPositions(int numFlakes)
{
    for(uint16_t i=0;i<numFlakes;i++) {
        randomFlakes[i] = random(strip.numPixels());
        if(i > 0) {
            for(int j=0;j<i;j++) {
				//make sure we didn't already set that position
                if(randomFlakes[i] == randomFlakes[j]){
                    do {
                        randomFlakes[i] = random(strip.numPixels());
                    }while(randomFlakes[i] != randomFlakes[j]);
                }
            }
        }
    }
}

//Color Blender
//Red starts at 1 end and green at the other. They increment towards each other. 
//When they meet, they eplode into the combined color
void collide(void) {
	uint16_t i, j, color1, color2;
	//uint16_t startColor = 0;    
	
	for(color1=0; color1<=255; color1+=85) {
	//for(color1=0; color1<=255; color1+=170) {
	    for(color2=color1+42; color2<=color1+85; color2+=43) {
	    //for(color2=color1+85; color2<=color1+170; color2+=85) {
    		for(i=0; i<=strip.numPixels()/2; i++) { 
    			if(i*2 >= strip.numPixels()) {
    				//Explode the colors
    				for(j=0; j<strip.numPixels(); j++) {
    					strip.setPixelColor(j, Wheel((((color2-color1)/2)+color1)&0xFF));
    					if(j%5==0)
    					    showPixels();
    				}
    				showPixels();
    				if(stop == TRUE) {return;}
					delay(speed);
    				break;
    			}
    			else {
    				//Grow the two colors from either end of the strip
    				strip.setPixelColor(i, Wheel(color1));
    				strip.setPixelColor(strip.numPixels()-i, Wheel((color2)&0xFF));
    				showPixels();
    				if(stop == TRUE) {return;}
					delay(speed);
    			}
    		}
	    }
	}
}

/* Should probably break this into two functions, but here it is as is
*  Cycle through the major color hues and fade each color in and out.
*  Fade In = Start dim and get brighter
*  Fade Out = Start bright and get dimmer
*/
void fade(void) {
    uint16_t i, j;
    uint16_t brightnessStep = 5;
    int returnValue = 1;
    int originalBrightness = brightness;    //store the original brightness

    //pick the color
    for(j=0; j<256; j+=15) {
        //Fade In
        for(i=0; i<256; i+=brightnessStep) {
            brightness = i;
            if(j%2==0) {
                returnValue = colorAll(Wheel(j & 0xFF));
            }
            else {
                returnValue = colorAll(Wheel((j+80) & 0xFF));
            }
            if(stop == TRUE || returnValue == 0) {return;}
    		delay(speed);
        }
         //Fade Out
        for(i=255-brightnessStep; i>0; i-=brightnessStep) {
            brightness = i;
            if(j%2==0) {
                returnValue = colorAll(Wheel(j & 0xFF));
            }
            else {
                returnValue = colorAll(Wheel((j+80) & 0xFF));
            }
            if(stop == TRUE || returnValue == 0) {return;}
    		delay(speed);
        }
    }
    brightness = originalBrightness;
    run = true; //in case it's off, let's turn it back on
}

// Lets use the colorChaser mode and cycle through all of the major color hues

void cycleChaser(void) {
    uint16_t j;
    int returnValue = 1;

    //pick the color
    for(j=0; j<256; j+=15) {
        if(j%2==0) {
            returnValue = colorChaser(Wheel(j & 0xFF));
        }
        else {
            returnValue = colorChaser(Wheel((j+80) & 0xFF));
        }
        if(stop == TRUE || returnValue == 0) {return;}
		delay(speed);
    }
    run = true; //in case it's off, let's turn it back on
}


/* Inspired by my musically inclined work neighbor
*  This mode simulates halogen stage lights turning On and then Off
*  They start off redish-orange and warm up to bright white
*/
void warmFade(void) {
    float i; 
    int returnValue = 1;
    
    for(i=0; i<256; i++) {
        returnValue = colorAll(strip.Color(fadeSqRt(i),fadeLinear(i),fadeSquare(i)));
        if(stop == TRUE || returnValue == 0) {return;}
        delay(speed);
    }
    for(i=255; i>0; i--) {
        returnValue = colorAll(strip.Color(fadeSqRt(i),fadeLinear(i),fadeSquare(i)));
        if(stop == TRUE || returnValue == 0) {return;}
        delay(speed);
    }
   run = true; //in case it's off, let's turn it back on
}

// warmFade helper function
uint8_t fadeSquare(float value) {
    return (uint8_t)(255*pow(value/255,2));
}

// warmFade helper function
uint8_t fadeSqRt(float value) {
    return (uint8_t)(255*sqrt(value/255));
}

// warmFade helper function
uint8_t fadeLinear(float value) {
    return (uint8_t) value;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

/** Return the highest value among the 3 rgb components for the given Color
  @param col The Color to be evaluated.
  @return The highest value, be it r, g or b, from the given Color.*/
uint32_t getHighestValFromRGB(Color col) {
    if(col.red-col.green > 0)
        if(col.red-col.blue > 0)
            return col.red; 
        else 
            return col.blue;
    else if(col.green-col.blue > 0) 
        return col.green;
    else 
        return col.blue;
}

/** 
 * Used to make linear transitions between colors by drawing a linear line from
 * the current color to the end color in the HSV model.
 * Assumes every pixel is at a different color value.
 * If the current color is blue and the next color is yellow, it will pass 
 * through the white spectrum to get there.
 * If the current color is red and the next color is blue, it will pass 
 * through pink/purple to get there.
 */
void transitionAll(Color endColor, uint16_t method) {
    uint32_t startColor[strip.numPixels()];
    int numSteps = 8;   //This could be an input param to this function
    run = FALSE;
    
    //Save the start color for each pixel - yeah, I know this is using a lot of memory, but I'm not smart enough to do it a better way
    for(int index = 0; index < strip.numPixels(); index++) {
        startColor[index] = strip.getPixelColor(index);
    }

    for(int i=1; i<=numSteps; i++) {
        for(int index = 0; index < strip.numPixels(); index++) {
            transitionHelper(getColorFromInteger(startColor[index]), endColor, index, method, numSteps, i); 
            if(stop) {return;}
        }
        showPixels();
        delay(speed);
    }
}

//Same as transitionAll but only for one pixel
void transitionOne(Color endColor, uint16_t index, uint16_t method) {
    int numSteps = 8;   //This could be an input param to this function
    Color startColor = getColorFromInteger(strip.getPixelColor(index));

    for(int i=1; i<=numSteps; i++) {
        transitionHelper(startColor, endColor, index, method, numSteps, i);
        if(stop) {return;}
        showPixels();
        delay(speed);
    }
}

uint8_t clamp(unsigned value, unsigned lowClamp, unsigned highClamp) {
	return ((value<lowClamp) ? lowClamp : (value>highClamp) ? highClamp : value);
}

//Used to set the next color step for transitionAll and transitionOne
void transitionHelper(Color startColor, Color endColor, uint16_t index, uint16_t method, int16_t numSteps, int16_t step) {
    Color col2;
    
    //Find the increment
    int16_t redStep   = getTransitionStep(startColor, endColor, method, numSteps, step, red);
    int16_t greenStep = getTransitionStep(startColor, endColor, method, numSteps, step, green);
    int16_t blueStep  = getTransitionStep(startColor, endColor, method, numSteps, step, blue);
    
    //Add the increment to get the next color segments
    //If new color is a higher value, set the high clamp to the new color
    //If new color is a smaller value, set the low clamp to the new color
    if(endColor.red   > startColor.red)   col2.red   = clamp(startColor.red   + redStep,  0,             endColor.red);
	else                                  col2.red   = clamp(startColor.red   + redStep,  endColor.red,  0xFF);
	if(endColor.green > startColor.green) col2.green = clamp(startColor.green + greenStep,0,             endColor.green);
	else                                  col2.green = clamp(startColor.green + greenStep,endColor.green,0xFF);
	if(endColor.blue  > startColor.blue)  col2.blue  = clamp(startColor.blue  + blueStep, 0,             endColor.blue);
	else                                  col2.blue  = clamp(startColor.blue  + blueStep, endColor.blue, 0xFF);
	
    //Let's make sure we hit the target
    if(step == numSteps) {
        col2.red   = endColor.red;
        col2.green = endColor.green;
        col2.blue  = endColor.blue;
    }
    strip.setPixelColor(index, strip.Color(col2.red, col2.green, col2.blue));
}


int16_t getTransitionStep(Color startColor, Color endColor, uint16_t method, int16_t numSteps, int16_t step, Color whichColor) {
	int16_t increment=0;

    if(method == LINEAR) {
        if(whichColor == red) {
            increment = step * ((endColor.red-startColor.red)/numSteps);
        }
        else if(whichColor == green) {
            increment = step * ((endColor.green-startColor.green)/numSteps);
        }
        else if(whichColor == blue) {
            increment = step * ((endColor.blue-startColor.blue)/numSteps);
        }
    }
	else { // (Not Quite) POLAR      
	    if(whichColor == red) {
	        if(endColor.red < startColor.red)
	            increment = sqrt(float(step)/numSteps) * float(endColor.red-startColor.red);
	        else
	            increment = (float(step)/numSteps) * (float(step)/numSteps) * float(endColor.red-startColor.red);
	    }
	    else if(whichColor == green) {
	        if(endColor.green < startColor.green)
	            increment = sqrt(float(step)/numSteps) * float(endColor.green-startColor.green);
	        else
	            increment = (float(step)/numSteps) * (float(step)/numSteps) * float(endColor.green-startColor.green);
	    }
	    else if(whichColor == blue) {
	        if(endColor.blue < startColor.blue)
	            increment = sqrt(float(step)/numSteps) * float(endColor.blue-startColor.blue);
	        else 
	            increment = (float(step)/numSteps) * (float(step)/numSteps) * float(endColor.blue-startColor.blue);
	    }
	}

    return increment;
}


/** Linear interpolation between colors.
 * @param a, b The colors to interpolate between.
 * @param val Position on the line between color a and color b.
 * When equal to min the output is color a, and when equal to max the output is color b.
 * @param minVal Minimum value that val will take.
 * @param maxVal Maximum value that val will take.
 * @return Color between colors a and b.
 */
uint32_t lerpColor(uint32_t c1, uint32_t c2, uint32_t val, uint32_t minVal, uint32_t maxVal) {
    Color a = getColorFromInteger(c1);
    Color b = getColorFromInteger(c2);
    int red = a.red + (b.red-a.red) * (val-minVal) / (maxVal-minVal);
    int green = a.green + (b.green-a.green) * (val-minVal) / (maxVal-minVal);
    int blue = a.blue + (b.blue-a.blue) * (val-minVal) / (maxVal-minVal);
    
    return strip.Color(red, green, blue);
}

/** Break down an int color into its 3 rgb components for the given integer
  @param col The color value, represented by an integer
  @return The rgb Color for the given integer.*/
Color getColorFromInteger(uint32_t col) {
    Color retVal;
    
    retVal.red   = (uint8_t)(col >> 16),
    retVal.green = (uint8_t)(col >>  8),
    retVal.blue  = (uint8_t)col;
    return retVal;
}

// ************************************************************************************
// You must **NEVER** change any values below this line! Unless you know what you are doing
// ************************************************************************************

//Spark Cloud Mode
//Expect a string like this to change the mode Mode: M:ZONE,D:30,B:120,C1:002BFF,C2:FF00DB,C3:FF4600,C4:23FF00,
//Or simply this to just update speed or brightness:        D:30,B:120,
//Received command should have an ending comma, it makes this code easier
//Argument (command) length is limited to a max of 63 characters
//All colors are in hex format
//If the mode Mode is changing, return the enum value of the mode
//Else if only the speed or brightness is being updated return the following:
//returnValue = 1000 - command was received to update speed or brightness, but new values  are == to old values
//returnValue = 1001 - Brightness has been updated
//returnValue = 1002 - Speed has been updated
int SetMode(String command) {
	int beginIdx = 0;
	int returnValue = -1;
	int idx = command.indexOf(',');
    bool isNewMode = false;
	bool isNewSpeed = false;
	bool isNewBrightness = false;
    switch1 = switch2 = switch3 = switch4 = FALSE;
    // Trim extra spaces
    command.trim();
    // Convert it to upper-case for easier matching
    command.toUpperCase();
    
    //keep track or the last command received for the auto off feature
    lastCommandReceived = millis();
    
//    sprintf(debug,"%s", command.c_str());

	while(idx != -1) {
		if(command.charAt(beginIdx) == 'M') {   //Mode name
			//set the new mode from modeStruct array index
			returnValue = setNewMode(getModeIndexFromName(command.substring(beginIdx+2, idx).c_str())); 
			isNewMode = true;
			// sprintf(debug,"Mode Idx %i. Mode %s", returnValue, command.substring(beginIdx+2, idx).c_str());
		}
		else if(command.charAt(beginIdx) == 'S') {  //Speed (Delay) value index
		    int receivedSpeedValue = command.substring(beginIdx+2, idx).toInt();
		    if(receivedSpeedValue > (int)(sizeof(speedPresets)/sizeof(int)))
		        receivedSpeedValue = sizeof(speedPresets)/sizeof(int) - 1;
			//int newSpeed = speedPresets[receivedSpeedValue];
		    if (speedIndex != receivedSpeedValue) {
				isNewSpeed = true;
			}
			//speedIndex = newSpeed;
			speedIndex = receivedSpeedValue;
			speed = speedPresets[speedIndex];
		}
		else if(command.charAt(beginIdx) == 'B') {  //Scaled Brightness value
		    int newBrightness = command.substring(beginIdx+2, idx).toInt() * 255 / 100;	//Scale 0-100 to 0-255
			if(brightness != newBrightness) {
				isNewBrightness = true;
			}
			brightness = newBrightness;
		}
        else if(command.charAt(beginIdx) == 'C') {  //Color values are comming in
            char * p;
            switch(command.charAt(beginIdx+1)) {
                case '1':
                    color1 = strtoul( command.substring(beginIdx+3, idx).c_str(), & p, 16 );  //Convert hex string to int
                    break;
                case '2':
                    color2 = strtoul( command.substring(beginIdx+3, idx).c_str(), & p, 16 );  //Convert hex string to int
                    break;
                case '3':
                    color3 = strtoul( command.substring(beginIdx+3, idx).c_str(), & p, 16 );  //Convert hex string to int
                    break;
                case '4':
                    color4 = strtoul( command.substring(beginIdx+3, idx).c_str(), & p, 16 );  //Convert hex string to int
                    break;
                case '5':
                    color5 = strtoul( command.substring(beginIdx+3, idx).c_str(), & p, 16 );  //Convert hex string to int
                    break;
                case '6':
                    color6 = strtoul( command.substring(beginIdx+3, idx).c_str(), & p, 16 );  //Convert hex string to int
                    break;
                    
            }
		}
		// T for Toggle switch - expect 0 or 1 for false or true
		// S for Switch would have made more sense, but want to keep this backwards compatible and S is alreay Speed
		else if(command.charAt(beginIdx) == 'T') { 
            switch(command.charAt(beginIdx+1)) {
                case '1':
                    switch1 = command.substring(beginIdx+3, idx).toInt() & 1;
                    break;
                case '2':
                    switch2 = command.substring(beginIdx+3, idx).toInt() & 1;
                    break;
                case '3':
                    switch3 = command.substring(beginIdx+3, idx).toInt() & 1;
                    break;
                case '4':
                    switch4 = command.substring(beginIdx+3, idx).toInt() & 1;
                    break;
            }
		}

		beginIdx = idx + 1;
		idx = command.indexOf(',', beginIdx);
	}
    //Set the flags if it's a new mode
	//Need this when just updating speed and brightness so a currently running mode doesn't start over
    if(isNewMode==true) {
        run = TRUE;
	    stop = TRUE;    
    }
    else {
		//I guess we're updating only the speed or brightness, so let's update the Pixels
		showPixels();
		if(isNewBrightness==true) {
			//Let the sender know we got the new brightness command
			returnValue = BRIGHTNESS_SET;
		}
		else if(isNewSpeed==true) {
			//Let the sender know we got the new speed command
			returnValue = SPEED_SET;
		}
		else {
			//If we got here, it's possible that a command was set to update speed or brightness
			//But neither one was a new value. The new values, equal the current values
			returnValue = NO_CHANGE;
		}
    }

	// still here, so everything must be fine
	return returnValue;
}

int SetText(String command) {

    sprintf(textInputString,"%s", command.c_str());

	return 1;
}

/** 
 * Miscellaneous Cloud Function Router
 * Expect a string with a single function identifier 
 * followed by a colon followed by parameters
 **/
int FnRouter(String command) {
	// Trim extra spaces
    command.trim();
    // Convert it to upper-case for easier matching
    command.toUpperCase();
	
    int beginIdx = 0;
	int colonIdx = command.indexOf(':');
	
	// Set time zone offset
    if(command.substring(beginIdx, colonIdx)=="SETTIMEZONE") {
		//Expect a string like this: SETTIMEZONE:-6
        timeZone = command.substring(colonIdx+1).toInt();
        Time.zone(timeZone);
        return timeZone;
    }
	else if(command.substring(beginIdx, colonIdx)=="SETAUXSWITCH") {
		//Expect a string like this: SETAUXSWITCH:1,0;
		//That breaks down to: SwitchID,state;
		//State must be 0 or 1
		beginIdx = colonIdx+1;
		int commaIdx = command.indexOf(',');
		int semiColonIdx = command.indexOf(';');
		int id = 0;
		while(semiColonIdx != -1) {
			id = (int) command.substring(beginIdx, commaIdx).toInt();
			bool state = command.substring(commaIdx+1,semiColonIdx).equals("1") ? true : false;
			auxSwitchStruct[getAuxSwitchIndexFromID(id)].auxSwitchState = state;
			
			beginIdx = semiColonIdx + 1;
			commaIdx = command.indexOf(',', beginIdx);
			semiColonIdx = command.indexOf(';', commaIdx);
		}
		
		//Update the list
		makeAuxSwitchList();
		
		//Update Switch flags
		return updateAuxSwitches(id);
	}
	else if(command.equals("REBOOT")) {
        resetFlag = true;
        stop = TRUE;
        return 1;
    }
    
    return -1;  
 }
 

//Change Mode based on the modeStruct array index
int setNewMode(int newModeIndex) {
    lastModeID = currentModeID;
    if(newModeIndex < 0) newModeIndex = 0;
    currentModeID = modeStruct[newModeIndex].modeId;
    sprintf(currentModeName,"%s", modeStruct[newModeIndex].modeName);
    resetVariables(modeStruct[newModeIndex].modeId);
	return newModeIndex;
}

int getModeIndexFromName(String name) {
    for(uint16_t i=0;i<(int)(sizeof modeStruct / sizeof modeStruct[0]);i++) {
        if(name.equals(String(modeStruct[i].modeName))) {
            return i;
        }
    }
    return -1;
}

int getModeIndexFromID(int id) {
    for(uint16_t i=0;i<(int)(sizeof modeStruct / sizeof modeStruct[0]);i++) {
        if(id == modeStruct[i].modeId) {
            return i;
        }
    }
    return -1;
}

int getAuxSwitchIndexFromID(int id) {
    for(uint16_t i=0;i<(int)(sizeof auxSwitchStruct / sizeof auxSwitchStruct[0]);i++) {
        if(id == auxSwitchStruct[i].auxSwitchId) {
            return i;
        }
    }
    return -1;
}
