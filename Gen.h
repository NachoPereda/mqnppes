#ifndef GEN_H
#define GEN_H

#include <vector>
#include "Picture.h"

std::vector<std::vector<int>> generateBinaryCombinations(int numBits);
std::vector<Picture> generateAllPictures(const Picture& originalPicture);

#endif // GEN_H
