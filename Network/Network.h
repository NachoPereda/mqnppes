/**
 * Project TFG Ignacio Pereda
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include "../Picture.h"

class Network
{
public:
    std::vector<Picture> pictures;
    int mask;

    void setMask();

    void unmask();
};

#endif //_NETWORK_H