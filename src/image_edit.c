#include "image_edit.h"

#include <stdlib.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) {
    // NOT_IMPLEMENTED;
    // UNUSED(img);

    pixel_t* new_img = malloc (img->w * img->h * sizeof(pixel_t));
    int new_width = img->h;
    int new_height = img->w;

    for (int i = 0; i < img->h; ++i) {
        
        for (int j = 0; j < img->w; ++j) {
            
            new_img [((img->w - 1 - j)*(new_width)) + i] = img->img[(i*(img->w)) + j];

        }

    }

    free(img->img);
    img->w = new_width;
    img->h = new_height;
    img->img = new_img;

}

void rotate_clockwise(image_t *img) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);

    pixel_t* new_img = malloc (img->w * img->h * sizeof(pixel_t));
    int new_width = img->h;
    int new_height = img->w;

    for (int i = 0; i < img->h; ++i) {
        
        for (int j = 0; j < img->w; ++j) {
            
            new_img [ (j*(new_width)) + (img->h - 1 - i)] = img->img[(i*(img->w)) + j];

        }

    }

    free(img->img);
    img->w = new_width;
    img->h = new_height;
    img->img = new_img;

}

void mirror_horizontal(image_t *img) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);

    pixel_t* new_img = malloc (img->w * img->h * sizeof(pixel_t));
    int new_width = img->w;
    int new_height = img->h;

    for (int i = 0; i < img->h; ++i) {
        
        for (int j = 0; j < img->w; ++j) {
            
            new_img [ (i*(new_width)) + (new_width - 1 - j)] = img->img[(i*(img->w)) + j];

        }

    }

    free(img->img);
    img->w = new_width;
    img->h = new_height;
    img->img = new_img;
    
}

void mirror_vertical(image_t *img) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);

    pixel_t* new_img = malloc (img->w * img->h * sizeof(pixel_t));
    int new_width = img->w;
    int new_height = img->h;

    for (int i = 0; i < img->h; ++i) {
        
        for (int j = 0; j < img->w; ++j) {
            
            new_img [ ((new_height - 1 - i)*(new_width)) + j] = img->img[(i*(img->w)) + j];

        }

    }

    free(img->img);
    img->w = new_width;
    img->h = new_height;
    img->img = new_img;
}

void resize(image_t *img, int new_width, int new_height) {

    //NOT_IMPLEMENTED;
    //UNUSED(img);
    //UNUSED(new_width);
    //UNUSED(new_height);
    pixel_t black;
    black.r = 0;
    black.g = 0;
    black.b = 0;

    pixel_t* new_img = malloc (new_width * new_height * sizeof(pixel_t));

    for (int i = 0; i < new_height; ++i) {
        
        for (int j = 0; j < new_width; ++j) {
            
            if ( j > ((img->w) -1) || i > ((img->w) -1)) {

                new_img[(i*(new_width)) + j] = black;

            }

            else {

                new_img[(i*(new_width)) + j] =  img->img[(i*(img->w)) + j];

            }
            

        }

    }

    free(img->img);
    img->w = new_width;
    img->h = new_height;
    img->img = new_img;

}
