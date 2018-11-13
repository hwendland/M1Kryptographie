#include "cbild.h"

/*!
 * @brief import image
 *
 * @param filename directory to the file
 */
void CBild::import(const string filename) {
    NBild image = NBild();
    image.import(filename);
    this->originalImage = image;
}

/*!
 * @brief writes image to the chosen file
 *
 * @param imageToWrite image that is going to be written
 * @param outfile directory to the outputfile
 */
void CBild::writeToFile(NBild imageToWrite, string outfile) {
    imageToWrite.writeToFile(outfile);
}

/*!
 * @brief encodes an image with a chosen key
 *
 * @param source_image image that is going to be encoded
 *
 * @return the endcoded image
 */
NBild CBild::encode(NBild source_image){
    // Matrix(row, cols)
    size_t ncols = source_image.ncols;
    size_t nrows = source_image.nrows;

    NBild encoded_image = NBild(nrows *2,ncols*2);

    for(size_t i_row = 0; i_row < nrows; i_row++){
        for(size_t i_col = 0; i_col < ncols; i_col++){
            if ((source_image(i_row, i_col) == 0)==(this->key == "A")){
                encoded_image(i_row*2, i_col*2) = 0;
                encoded_image(i_row*2+1, i_col*2+1) = 0;
                encoded_image(i_row*2+1, i_col*2) = 1;
                encoded_image(i_row*2, i_col*2+1) = 1;
            } else {
                encoded_image(i_row*2, i_col*2) = 1;
                encoded_image(i_row*2+1, i_col*2+1) = 1;
                encoded_image(i_row*2+1, i_col*2) = 0;
                encoded_image(i_row*2, i_col*2+1) = 0;
            }
           }
       }
    return(encoded_image);
}

/*!
 * @brief overlays two chosen images
 *
 * @param image1 one of the pictures which are going to be combined
 * @param image2 one of the pictures which are going to be combined
 *
 * @return result of the overlayed iamges
 */
NBild CBild::overlay(NBild image1, NBild image2){
    size_t ncols = image1.ncols;
    size_t nrows = image1.nrows;

    NBild result_image = NBild(nrows, ncols);

    for(size_t i_row = 0; i_row < nrows; i_row++){
        for(size_t i_col = 0; i_col < ncols; i_col++){
            if ((image1(i_row,i_col) == 1)&&(image2(i_row,i_col) == 1)){
                result_image(i_row,i_col) = 1;
            } else {
                result_image(i_row,i_col) = 0;
            }
        }
    }

    return(result_image);
}

/*!
 * @brief creates the enconding image
 *
 * @param ncols number of columns
 * @param nrows number of rows
 *
 * @return encoding image
 */
NBild CBild::create_enc_image(size_t ncols, size_t nrows){
    NBild result_image = NBild(2*nrows, 2*ncols);
    for(size_t i_row = 0; i_row < 2*nrows; i_row++){
        for(size_t i_col = 0; i_col < 2*ncols; i_col++){
            if ((i_row % 2 == 1) == (i_col % 2 == 1) == (this->key == "A")){
                result_image(i_row, i_col) = 1;
            } else {
                result_image(i_row, i_col) = 0;
            }
        }
    }
    return(result_image);
}

/*!
 * @brief decodes the given image
 *
 * @param source_image image that is going to be decoded
 *
 * @return decoded image
 */
NBild CBild::decode(NBild source_image){
    size_t ncols = source_image.ncols;
    size_t nrows = source_image.nrows;
    NBild result_image;

    NBild key_image = this->create_enc_image(ncols/2, nrows/2);

    result_image = this->overlay(source_image, key_image);

    return(result_image);
}






