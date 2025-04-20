#pragma once

#include "me_requesthandler.h"

class mCGotoRequestHandler : public mCRequestHandler
{
  public:
    mCGotoRequestHandler();
    virtual void HandleRequest();
    virtual void Process();

  private:
    bCVector m_PutToGroundLocation;
    GEUInt m_uPutToGroundTries;
};
