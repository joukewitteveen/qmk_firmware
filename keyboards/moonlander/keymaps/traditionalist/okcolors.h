/*
 * red = srgb_to_okhsl(255,0,0);
 * green = srgb_to_okhsl(0,255,0);
 * blue = srgb_to_okhsl(0,0,255);
 * cyan = srgb_to_okhsl(...okhsv_to_srgb((green[0] + blue[0]) / 2, 1, 1));
 * magenta = srgb_to_okhsl(...okhsv_to_srgb((blue[0] + red[0] + 1) / 2, 1, 1));
 * yellow = srgb_to_okhsl(...okhsv_to_srgb((red[0] + green[0]) / 2, 1, 1));
 * red[2] = green[2] = blue[2] = Math.min(red[2], green[2], blue[2]);
 * cyan[2] = magenta[2] = yellow[2] = Math.min(cyan[2], magenta[2], yellow[2]);
 *
 * rgb_to_hsv(...okhsl_to_srgb(...COLOR)).map(x => x * 255)
 */
#define OK_RED        0, 255, 164
#define OK_GREEN     85, 255, 105
#define OK_BLUE     170, 255, 255
#define OK_DARK      29,   0,  86
#define OK_CYAN     130, 255, 188
#define OK_MAGENTA  211, 255, 255
#define OK_YELLOW    32, 255, 194
#define OK_LIGHT    156,   0, 155
#define OK_BASE0    156, 100, 255
#define OK_BASE1     29, 129, 220
#define OK_WHITE    HSV_WHITE
