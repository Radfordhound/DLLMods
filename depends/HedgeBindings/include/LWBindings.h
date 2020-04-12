#pragma once
#define HB_BASE_ADDRESS 0x400000
#include "INHedgeBindings.h"
#include <cstdint>

namespace csl
{
    namespace math
    {
        __declspec(align(16)) struct Vector3
        {
            float X, Y, Z, W;
            // TODO
        };

        __declspec(align(16)) struct Quaternion
        {
            float X, Y, Z, W;
            // TODO
        };
    }
}

namespace app
{
    struct Application
    {
        HB_MEMBER_FUNC(HB_ASLR(0x004ab360), Application, void, InitializeCommon);

        inline void InitializeCommon()
        {
            InitializeCommon_ptr(this);
        }
    };

    struct ApplicationWin
    {
        HB_MEMBER_FUNC(HB_ASLR(0x00401c80), ApplicationWin, bool, CreateDevice);

        inline bool CreateDevice()
        {
            return CreateDevice_ptr(this);
        }
    };

    struct GameDocument; // TODO

    class CObjInfo
    {
        // TODO
    };

    namespace fnd
    {
        struct Message;
    }

    struct GameObject;
    struct GameDocument
    {
        // TODO

        HB_MEMBER_FUNC(HB_ASLR(0x0090b3c0), GameDocument, void*, AddGameObject,
            GameObject* obj);

        HB_MEMBER_FUNC(HB_ASLR(0x00962ee0), GameDocument, void, SetLayerName,
            unsigned int layerIndex, const char* layerName);

        inline void* AddGameObject(GameObject* obj)
        {
            return AddGameObject_ptr(this, obj);
        }

        inline void SetLayerName(unsigned int layerIndex, const char* layerName)
        {
            SetLayerName_ptr(this, layerIndex, layerName);
        }
    };

    struct GameObject
    {
        // TODO

        HB_FUNC_PTR(HB_ASLR(0x0049cad0), __cdecl, void*, New, std::size_t size);
    };

    namespace xgame
    {
        struct MsgTakeObject;
    }

    namespace Player
    {
        class CStateGOC;

        enum class PlayerState
        {
            //PLAYER_STATE_DASH = 0x55,
            //PLAYER_STATE_DIE = 0x21

            CStateSleep = 0,

            // PlayerStateGround
            CStateRun = 3,
            CStateBrake = 4,
            //CStateDead = 5,
            //CStatePressDead = 6,
            //CStateWallCrashDead = 7,

            // PlayerStateJump
            //CStateJump = 6, // TODO: Crashes the game?!
            CStateDoubleJump = 7,
            //CStateJumpSpring = 8, // Actually CStateJump?!?!?
            //CStateJumpSpringHeadLand = 9, // TODO: Crashes the game?!

            // ? [TODO]
            CStateDamageUk1 = 0x1A,

            // PlayerStateGroundDamage
            CStateDamage = 0x1B,
            CStateDamageRunning = 0x1C,
            CStateDamageFromRC = 0x1D,
            CStateDamageElectric = 0x1E,
            CStateDamageMagma = 0x1F,
            CStateDamageQuake = 0x20,
            // TODO

            // PlayerStateInWater
            CStateWaterBreath = 0x38,
            CStateWaterBreathAir = 0x39,
            CStateWaterDead = 0x3A,
            CStateWaterDeadAir = 0x3B, // ??

            // PlayerStateDiving
            //CStateDivingRoot = 0x3b, // ??
            CStateDiving = 0x3c,
            CStateDivingFall = 0x3d,
            CStateDivingDamage = 0x3f,
            CStateDivingBound = 0x40,

            // PlayerStateBallMove
            CStateBallMove = 0x54
        };

        enum class BodyMode
        {
            Human,
            Spin,
            SuperSonic,
            PhantomSpin,
            PhantomLaser,
            PhantomRocket,
            PhantomAsteroid,
            PhantomEagle,
            Unknown1,
            PhantomRhythm,
            PhantomBomb,
            PhantomHover,
            PhantomQuake
        };

        class CPlayerVehicle
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x005c6680), CPlayerVehicle, void, SetTransformation,
                const csl::math::Vector3& pos, const csl::math::Quaternion& rot);

            inline void SetTransformation(const csl::math::Vector3& pos,
                const csl::math::Quaternion& rot)
            {
                SetTransformation_ptr(this, pos, rot);
            }
        };

        class CPhysics
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x004cf110), CPhysics, void, SetVelocity,
                const csl::math::Vector3& velocity);

            inline void SetVelocity(const csl::math::Vector3& velocity)
            {
                SetVelocity_ptr(this, velocity);
            }
        };

        class CPlayer
        {
            // TODO
        };

        class CSnowBall : public CPlayerVehicle, public GameObject
        {
            // TODO
        public:
            HB_MEMBER_FUNC(HB_ASLR(0x008e4280), CSnowBall, CSnowBall*, __ct,
                CPlayer* plr);

            inline CSnowBall(CPlayer* plr)
            {
                __ct_ptr(this, plr);
            }
        };

        class CStateActionBase
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x00898660), CStateActionBase, bool, ProcessMessage,
                CStateGOC& goc, fnd::Message& msg);

            inline bool ProcessMessage(CStateGOC& goc, fnd::Message& msg)
            {
                return ProcessMessage_ptr(this, goc, msg);
            }
        };

        class CStateBase
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x008947b0), CStateBase, bool, ProcMsgTakeObject,
                CStateGOC& goc, xgame::MsgTakeObject& msg);

            inline bool ProcMsgTakeObject(CStateGOC& goc, xgame::MsgTakeObject& msg)
            {
                return ProcMsgTakeObject_ptr(this, goc, msg);
            }
        };

        class CStateGOC
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x0085b7b0), CStateGOC, void, ChangeAnimation,
                const char* animName, float param_2);

            HB_MEMBER_FUNC(HB_ASLR(0x0085b400), CStateGOC, unsigned int, ChangeState,
                PlayerState state);

            HB_MEMBER_FUNC(HB_ASLR(0x0085c5f0), CStateGOC, void, ChangeVisual,
                BodyMode bodyMode);

            HB_MEMBER_FUNC(HB_ASLR(0x0085b490), CStateGOC, CPhysics*, GetPhysics);

            inline void ChangeAnimation(const char* animName, float param_2)
            {
                ChangeAnimation_ptr(this, animName, param_2);
            }

            inline unsigned int ChangeState(PlayerState state)
            {
                return ChangeState_ptr(this, state);
            }

            inline void ChangeVisual(BodyMode bodyMode)
            {
                ChangeVisual_ptr(this, bodyMode);
            }

            inline CPhysics* GetPhysics()
            {
                return GetPhysics_ptr(this);
            }

            // TODO
        };

        class CStateEdit
        {
            char data[0x100]; // TODO
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x008c8230), CStateEdit, void, OnEnter,
                CStateGOC& goc, int param_2);

            HB_MEMBER_FUNC(HB_ASLR(0x008c9110), CStateEdit, void, OnLeave,
                CStateGOC& goc, int param_2);

            HB_MEMBER_FUNC(HB_ASLR(0x008c9250), CStateEdit, unsigned int, Step,
                CStateGOC& goc, float param_2);

            inline void OnEnter(CStateGOC& goc, int param_2)
            {
                OnEnter_ptr(this, goc, param_2);
            }

            inline void OnLeave(CStateGOC& goc, int param_2)
            {
                OnLeave_ptr(this, goc, param_2);
            }

            inline unsigned int Step(CStateGOC& goc, float param_2)
            {
                return Step_ptr(this, goc, param_2);
            }
            // TODO
        };

        class CStateRun
        {
            // TODO
            char data[0x50]; // TODO: Is this size right??

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x008a3b70), CStateRun, unsigned int, Step,
                CStateGOC& goc, float param_2);

            HB_MEMBER_FUNC(HB_ASLR(0x008a3120), CStateRun, void, UpdateAnimation,
                CStateGOC& goc, float param_2);

            inline unsigned int Step(CStateGOC& goc, float param_2)
            {
                return Step_ptr(this, goc, param_2);
            }

            inline void UpdateAnimation(CStateGOC& goc, float param_2)
            {
                UpdateAnimation_ptr(this, goc, param_2);
            }

            // TODO
        };

        class CStateJump
        {
            // TODO
            char data[0x50]; // TODO: Is this size right??

        public:

            HB_MEMBER_FUNC(HB_ASLR(0x008ac960), CStateJump, unsigned int, Step,
                CStateGOC& goc, float param_2);

            inline void Step(CStateGOC& goc, float param_2)
            {
                Step_ptr(this, goc, param_2);
            }
            
            // TODO
        };

        namespace StateUtil
        {
            HB_FUNC_PTR(HB_ASLR(0x008d6600), __cdecl, bool, IsButtonPressDash,
                CStateGOC& goc);

            HB_FUNC_PTR(HB_ASLR(0x008df830), __cdecl, void, SetDrawJumpBall,
                CStateGOC& goc, bool hasJumpBall);

            HB_FUNC_PTR(HB_ASLR(0x008d9ed0), __cdecl, void, SetInvincible,
                CStateGOC& goc, bool isInvincible);

            HB_FUNC_PTR(HB_ASLR(0x008d6d40), __cdecl, void*, SetRingNum,
                CStateGOC& goc, int ringNum, bool param_3);

            HB_FUNC_PTR(HB_ASLR(0x008DAAA0), __cdecl, void, StartParkourEffect,
                CStateGOC& goc, float duration);
        }

        struct PluginStateAutoRun
        {
            HB_MEMBER_FUNC(HB_ASLR(0x008d1840), PluginStateAutoRun, void, Setup,
                CStateGOC& goc, unsigned int param_2, float param_3);

            inline void Setup(CStateGOC& goc, unsigned int param_2, float param_3)
            {
                Setup_ptr(this, goc, param_2, param_3);
            }
        };
    }

    namespace text
    {
        class CConverseCellString2
        {
        public:
            const char* CellName;
            const wchar_t* Text;

            void** RemappingsOffset; // Points to an array of pointers to remappings. **Can be null!!**
            unsigned int RemappingsCapacity; // ??
            unsigned int RemappingSize; // ??
            unsigned int RemappingBegin; // ??

            unsigned long long Unknown1 = 0; // Always 0??
            unsigned long long Unknown2 = 0; // Always 0??

            unsigned short Unknown3 = 0; // ??
            unsigned short LastCharIndex;
            unsigned int Unknown4 = 2; // ??
            int Unknown5 = -1; // ??

            unsigned short Unknown6 = 0; // ??
            unsigned short LastCharIndex2 = LastCharIndex;
            unsigned int Unknown7 = 1; // ??
            unsigned int Unknown8 = 0x16; // Can also be 0x14? Layout type??

            unsigned short Unknown9 = 0; // ??
            unsigned short LastCharIndex3 = LastCharIndex;
            unsigned int Unknown10 = 0; // ??
            unsigned int Unknown11 = 1; // ??

            unsigned short Unknown12 = 0; // ??
            unsigned short LastCharIndex4 = LastCharIndex;
            unsigned int Unknown13 = 3; // ??
            unsigned int Unknown14 = 0; // ??
            // TODO

        public:
            // TODO
        };

        class TextSystem
        {
        public:
            HB_MEMBER_FUNC(HB_ASLR(0x004a9bb0), TextSystem, CConverseCellString2*, GetConverseData,
                const char* groupName, const char* cellName, unsigned int param_3);

            HB_MEMBER_FUNC(HB_ASLR(0x004a9b60), TextSystem, CConverseCellString2*, GetConverseDataFromKey,
                unsigned int groupKey, unsigned int cellKey, unsigned int param_3);

            HB_MEMBER_FUNC(HB_ASLR(0x004a9c20), TextSystem, const wchar_t*, GetConverseDataText,
                const char* groupName, const char* cellName, unsigned int param_3);

            inline CConverseCellString2* GetConverseData(const char* groupName,
                const char* cellName, unsigned int param_3)
            {
                return GetConverseData_ptr(this, groupName, cellName, param_3);
            }

            inline CConverseCellString2* GetConverseDataFromKey(unsigned int groupKey,
                unsigned int cellKey, unsigned int param_3)
            {
                return GetConverseDataFromKey_ptr(this, groupKey, cellKey, param_3);
            }

            inline const wchar_t* GetConverseDataText(const char* groupName,
                const char* cellName, unsigned int param_3)
            {
                return GetConverseDataText_ptr(this, groupName, cellName, param_3);
            }
        };
    }

    namespace HUD
    {
        class CHudGeneralWindow;
    }

    namespace GeneralWindow
    {
        enum class WindowType
        {
            /* @brief A window shows for a period of time, then disappears. */
            Timed = 0,
            /* @brief A window which has an "OK" button. */
            OK = 1,
            /* @brief A window which has a "Yes" button and a "No" button. */
            YesNo = 2
            // TODO: 3 seems to be used as well??
        };

        struct AppearInfo
        {
            WindowType WindowType;
            unsigned int Uk1;
            const char* GroupKey;
            const char* CellKey;
            char Uk2;
            char Uk3;

            HB_MEMBER_FUNC(HB_ASLR(0x0095e3b0), AppearInfo, AppearInfo*, __ct);

            inline AppearInfo()
            {
                __ct_ptr(this);
            }
        };

        inline static HUD::CHudGeneralWindow** Instance =
            reinterpret_cast<HUD::CHudGeneralWindow**>(HB_ASLR(0x00fefef8));

        HB_FUNC_PTR(HB_ASLR(0x0095e530), __cdecl, void, Appear,
            const AppearInfo& appearInfo);
    }

    namespace HUD
    {
        class CHudSegalogo
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x00522ab0), CHudSegalogo, void, AddCallback,
                GameDocument* param_1);

            // TODO

            inline void AddCallback(GameDocument* param_1)
            {
                AddCallback_ptr(this, param_1);
            }
        };

        class CHudSegalogoSub
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x00522910), CHudSegalogoSub, void, AddCallback,
                GameDocument* param_1);

            // TODO

            inline void AddCallback(GameDocument* param_1)
            {
                AddCallback_ptr(this, param_1);
            }
        };

        class CHudGeneralWindow
        {
            // TODO

        public:
            HB_MEMBER_FUNC(HB_ASLR(0x005087d0), CHudGeneralWindow, void, SetText,
                const text::CConverseCellString2* text);

            inline void SetText(const text::CConverseCellString2* text)
            {
                SetText_ptr(this, text);
            }
        };

        HB_FUNC_PTR(HB_ASLR(0x0050a7d0), __cdecl, void, OpenGeneralWindow,
            const char* groupKey, const char* cellKey,
            GeneralWindow::WindowType windowType);
    }
}
