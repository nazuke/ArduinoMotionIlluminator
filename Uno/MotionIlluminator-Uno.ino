/** Motion Illuminator LED ****************************************************/

#define DEBUG_MODE
//#undef DEBUG_MODE

#ifdef DEBUG_MODE
#include <SPI.h>
#endif

#define SENSE_PIN 7 // Input pin for HC-SR501
#define LED_PIN 13 // Output LED pin
#define EXTERNAL_LED_PIN 12 // Output LED pin

#define DELAY_BOOT 1000
#define DELAY_WAIT 1000

/******************************************************************************/

int SenseValue;

/******************************************************************************/

void setup() {

  #ifdef DEBUG_MODE
  Serial.begin( 9600 );
  while ( !Serial );
  Serial.println( "" );
  Serial.println( "Initializing..." );
  #endif
  
  pinMode( SENSE_PIN, INPUT );
  pinMode( LED_PIN, OUTPUT );
  pinMode( EXTERNAL_LED_PIN, OUTPUT );

  digitalWrite( LED_PIN, LOW );
  digitalWrite( EXTERNAL_LED_PIN, LOW );

  SenseValue = 0;

  delay( DELAY_BOOT );

  #ifdef DEBUG_MODE
  Serial.println( "Ready." );
  #endif
  
}

/******************************************************************************/

void loop() {

  SenseValue = digitalRead( SENSE_PIN );

  if ( SenseValue == 1 ) {

    #ifdef DEBUG_MODE
    debug_message( "SenseValue", SenseValue );
    #endif

    digitalWrite( LED_PIN, HIGH );
    digitalWrite( EXTERNAL_LED_PIN, HIGH );

    delay( DELAY_WAIT );

  } else {
    
    #ifdef DEBUG_MODE
    debug_message( "SenseValue", SenseValue );
    #endif
    
    digitalWrite( LED_PIN, LOW );
    digitalWrite( EXTERNAL_LED_PIN, LOW );

  }

  SenseValue = 0;

}

/******************************************************************************/

#ifdef DEBUG_MODE
void debug_message( char Label[], int Value ) {
  Serial.print( Label );
  Serial.print( ": " );
  Serial.println( Value );
}
#endif

/******************************************************************************/

