// CRYPTOGRAPHICALLY SECURE PASSWORD GENERATOR
//
// Modified code from the Entropy library
//
// The goal of this project is to create a secure hardware
// password generator with high entropy.
//
// Password examples / ~140 bits entropy:
// c@?n9oaZduUvrdSKMUH5EMaIU
// gt9ZkMC5Z7Wi?WI9hoLVPP19k
// w9W74yvShSHNLS2ue5wEwZiGE
// dgjPKgrS7RgeCuD3DauGxrNcC
// jIFW8Y0hOxBVbhVE9PRi?7IO6
// dCvXKWUJVncBf1?sx15gn04UD
// jaNBdSRNj?FWdDksLpfj9chAQ
// xmTNrsHTpX1mvfYoKCYOSnrDA
// DJnjZ7ZMIKaNayINefCi9Ufzq
// N?Htb2Z?WexXecOMxWIfwFzyv
//

#include <Entropy.h> // Include Entropy library

#define PW_LENGTH 25 // Password length

// This routine will convert a 6 bit value (0-63) to an acceptible password character
char mapChar(uint32_t parm)
{
  char retval;
  if (parm < 10)           // map 0..9 to ascii 0..9
    retval = char(48 + parm);
  else if (parm < 38)      // map 12 to 37 to ascii A..Z
    retval = char(53 + parm);
  else if (parm < 64)      // map 38 to 63 to ascii a..z
    retval = char(59 + parm);
  else
    retval = 0;            // if parm is invalid return null
  return (retval);
}

// This routine uses the Entropy library to obtain truly random 6 bit values
// and to map that to an eight character cryptographically secure password
char *getPassword(char *pw)
{
  char ch;
  int indx;
//  init NUM_PASS;
  uint32_t tmp;

  for (indx = 0; indx < PW_LENGTH; indx++)
  {
    tmp = mapChar(Entropy.random(64));
    pw[indx] = (char) tmp;
  }
  pw[PW_LENGTH] = 0;
  return (pw);
}

void setup()
{
  char pw[PW_LENGTH + 1];

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  Entropy.initialize();
  //Generate cryptographically secure passwords
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
  Serial.println(getPassword(pw));
}

void loop() // Leave this section blank
{
}
// END /////
