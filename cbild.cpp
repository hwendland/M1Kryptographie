#include "cbild.h"

void CBild::import(const string filename) {
    NBild image = NBild();
    image.import(filename);
    this->originalImage = image;
}

void CBild::writeToFile(NBild imageToWrite, string outfile) {
    imageToWrite.writeToFile(outfile);
}

void CBild::encode() {
    NBild encodedImage = NBild();
    //do something with this->originalImage based on this->key and save result in this->encodedImage?
    this->encodedImage = encodedImage;
}

void CBild::decode() {
    NBild decodedImage = NBild();
    //do something with this->encodedImage based on this->key
}
