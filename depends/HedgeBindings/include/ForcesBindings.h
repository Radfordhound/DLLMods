#include "INHedgeBindings.h"

namespace app
{
    class GeneralWindow
    {
        class AppearInfo
        {
            // TODO
        };
    };

    // TODO: Is this correct?
    // void app::Appear(app::HUD::GeneralWindow::AppearInfo* appearInfo)
    // 0x14017170A
    HB_FUNC_PTR(0x140171250, __fastcall, void*, Update,
        void* param_1, void* param_2, void* param_3);

    namespace HUD
    {
        class HudGeneralWindow
        {
        public:
            //MFuncPtr<0x1405ac1d0, void, CHudGeneralWindow, const char*> t;
            // void app::HUD::CHudGeneralWindow::SetText(const char* cellName)
            HB_MEMBER_FUNC(0x1405ac1d0, HudGeneralWindow, void, SetText,
                const char* cellName);

            inline void SetText(const char* cellName)
            {
                SetText_ptr(this, cellName);
            }

            // 0x140171250 might be CHudGeneralWindow::Update??
        };
    }
}
