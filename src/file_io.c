#include "file_io.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"

int image_read(image_t *img, FILE *fin) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);
    //UNUSED(fin);

    if (fin == NULL) {
        return -1;
    }

    int width = 0;
    int height = 0;
    int check = 0;


    check = fscanf(fin, "P3 %d %d 255" , &width , &height);

    if (check != 2 || width<0 || height<0) {
        return -1;
    }

    
    pixel_t* pixels = malloc(width*height*sizeof(pixel_t));

    for (int i=0; i<width*height; i++) {

            check = fscanf(fin, "%d %d %d ", &pixels[i].r , &pixels[i].g , &pixels[i].b);

            if (check !=3 ) {
                free(pixels);
                return -1;
            }

            if (pixels[i].r <0 || pixels[i].r>255){
                free(pixels);
                return -1;
            }
            if (pixels[i].g <0 || pixels[i].g>255){
                free(pixels);
                return -1;
            }
            if (pixels[i].b <0 || pixels[i].b>255){
                free(pixels);
                return -1;
            }

            
    
    }
    img->w = width;
    img->h = height;
    img->img = pixels;

    return 0;
}

void image_write(const image_t *img, FILE *fout) {
    //NOT_IMPLEMENTED;
    //UNUSED(img);
    //UNUSED(fout);
    fprintf(fout, "P3 %d %d 255\n" , img->w , img->h);

    for (int i=0; i < ((img->w)*(img->h)) ; i++) {

        fprintf(fout, "%d %d %d\n", img->img[i].r , img->img[i].g , img->img[i].b);
        
    }
    
    return ;
}

void image_free(image_t *img) {
    if (img->img != NULL) {
        free(img->img);
    }
    img->w = img->h = 0;
    img->img = NULL;
}
