

//This will hold custom images that can be displayed on the LED Matrix
//The Adafruit library has 4 build in images (HEART, EMPTYHEART, NO, YES)
//to use them invoke the adafruit library, and call.
// microbit.show(microbit.HEART);
// Adafruit also provides drawing functions, see example sketch for more info.

const uint8_t smile_bmp[] =
{B00000,
B01010,
B00000,
B10001,
B01110};

const uint8_t small_heart[] =
{B00000,
B01010,
B01110,
B00100,
B00000};

const uint8_t sad[] =
{B00000,
B01010,
B00000,
B01110,
B10001};

const uint8_t confused[] =
{B00000,
B01010,
B00000,
B01010,
B10101};

const uint8_t up_arrow[] =
{B00100,
B01110,
B00100,
B00100,
B00100};

const uint8_t down_arrow[] =
{B00100,
B00100,
B00100,
B01110,
B00100}; //sword on makecode.microbit.org

const uint8_t left_arrow[] =
{B00000,
B01000,
B11111,
B01000,
B00000};

const uint8_t right_arrow[] =
{B00000,
B00010,
B11111,
B00010,
B00000};

const uint8_t ghost[] =
{B01110,
B10101,
B11111,
B11111,
B10101};

const uint8_t skull[] =
{B01110,
B10101,
B11111,
B01110,
B01110};

