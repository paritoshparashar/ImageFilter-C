#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"


void fill(image_t *img , int x , int y , pixel_t start_color , pixel_t target_colour){

    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;

    pixel_t present_colour = img->img[y * img->w + x];
    
    if (!(present_colour.r == (start_color).r && present_colour.g == (start_color).g && present_colour.b == (start_color).b))  return; //check whether present node colour and original colour are different

    img->img[y * img->w + x] = target_colour;

    //south of the node
    fill(img, x, y+1, start_color, target_colour); 

    //north of the node
    fill(img, x, y-1, start_color, target_colour); 

    //east of the node
    fill(img, x+1, y, start_color, target_colour); 

    //west of the node
    fill(img, x-1, y, start_color, target_colour); 
    
}

void flood(image_t *img, int x, int y ,pixel_t *target_color) {
    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;

    // NOT_IMPLEMENTED;
    // UNUSED(img);
    // UNUSED(x);
    // UNUSED(y);
    // UNUSED(target_color);

    //get the original colour
    pixel_t nodeColour = img->img[y * img->w + x];

    //if original colour and target colour are same then stop
    if (nodeColour.r == (*target_color).r && nodeColour.g == (*target_color).g && nodeColour.b == (*target_color).b)  return;

    fill(img, x , y, nodeColour, *target_color );

}
