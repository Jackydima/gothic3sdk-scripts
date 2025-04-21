#pragma once

#include "proto/g3rc.pb.h"

#include <g3sdk/Engine.h>

class mCRequestHandler
{
  public:
    mCRequestHandler();
    void SetRequestContainer(g3rc::RequestContainer const &a_RequestContainer);
    void SetResponseContainer(g3rc::ResponseContainer &a_ResponseContainer);
    void virtual HandleRequest() = 0;
    void virtual Process(){};

  protected:
    static bCString FromUTF8(::std::string const &a_Source);
    static ::std::string ToUTF8(bCString const &a_Source);
    static eCEntity *GetEntityByName(::std::string const &a_Name,
                                     eEGetEntityTypeHint a_Type = eEGetEntityTypeHint_Entity);
    static eCEntity *GetTemplateEntityByName(::std::string const &a_Name);
    static eCEntity *GetEntityByGuid(::std::string const &a_Guid,
                                     eEGetEntityTypeHint a_Type = eEGetEntityTypeHint_Entity);
    static void SetEntityResponse(g3rc::EntityResponse &a_Response, eCEntity &a_Entity);

  protected:
    void Success();
    void Fail(bCString const &a_strMessage);
    void FailAndPrintMessage(bCString const &a_strMessage);

  protected:
    g3rc::RequestContainer const *m_RequestContainer;
    g3rc::ResponseContainer *m_ResponseContainer;
};
