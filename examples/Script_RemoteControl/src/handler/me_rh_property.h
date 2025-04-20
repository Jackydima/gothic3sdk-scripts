#pragma once

#include "me_requesthandler.h"

class mCPropertyRequestHandler : public mCRequestHandler
{
  public:
    virtual void HandleRequest();

  private:
    void GetProperty(eCEntity *a_pEntity, g3rc::PropertyIdentifier const &a_Identifier,
                     g3rc::PropertySerialized &a_ResponseProperty);
    void SetProperty(eCEntity *pEntity, g3rc::PropertySerialized const &a_Property);
};
