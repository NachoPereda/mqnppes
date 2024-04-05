#ifndef GEN_H
#define GEN_H

#include "Network.h"
#include <vector>
#include "../Picture.h"

class Gen : public Network
{
private:
    std::vector<std::vector<int>> generateBinaryCombinations(int numBits);

public:
    std::vector<Picture> generateAllPictures(Picture &originalPicture);
};

#endif // GEN_H
