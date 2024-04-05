/**
 * Project TFG Ignacio Pereda
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include "../Picture.h"

class Network
{
public:
    void SetPictures(std::vector<Picture> received_pictures);
    virtual void setMask();
    void unmask();

protected:
    std::vector<Picture> pictures;
    int mask;
};

#endif //_NETWORK_H