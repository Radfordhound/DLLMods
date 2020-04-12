#include "LWBindings.h"
#include "detours.h"
#include <string>
#include <cwctype>

#define ININSTALL_HOOK(orig, hook) \
    { \
        DetourTransactionBegin(); \
        DetourUpdateThread(GetCurrentThread()); \
        DetourAttach((void**)&orig, hook); \
        DetourTransactionCommit(); \
    }

#define INSTALL_HOOK(name) ININSTALL_HOOK(name##_original, name##_hook)
#define INSTALL_HOOK_MEMBER(className, name) \
    ININSTALL_HOOK(className::name##_original, className##_##name##_hook)

namespace app
{
namespace text
{
    static std::wstring Text;
    static CConverseCellString2 cell = {};

    static void ReplaceText(std::wstring& str, const wchar_t* origTxt,
        const wchar_t* newTxt)
    {
        std::size_t origLen = std::wcslen(origTxt);
        std::size_t newLen = std::wcslen(newTxt);

        for (std::size_t off = str.find(origTxt);
            off != std::wstring::npos; off = str.find(origTxt, off))
        {
            Text.replace(off, origLen, newTxt);
            off += newLen;
        }
    }

    static void ReplaceWord(std::wstring& str, const wchar_t* origTxt,
        const wchar_t* newTxt)
    {
        std::size_t origLen = std::wcslen(origTxt);
        std::size_t newLen = std::wcslen(newTxt);

        for (std::size_t off = str.find(origTxt);
            off != std::wstring::npos; off = str.find(origTxt, off))
        {
            if ((off == 0 || str[off - 1] == L' ') &&
                (str[off + origLen] == L' ' || str[off + origLen] == L'\0' ||
                str[off + origLen] == L'.' || str[off + origLen] == L'!' ||
                str[off + origLen] == L'?' || str[off + origLen] == L',' ||
                str[off + origLen] == L';' || str[off + origLen] == L':' ||
                str[off + origLen] == '~'))
            {
                Text.replace(off, origLen, newTxt);
                off += newLen;
            }
            else
            {
                off += origLen;
            }
        }
    }

    static const wchar_t* MakeFurry(const wchar_t* text)
    {
        Text = std::wstring(text);

        ReplaceWord(Text, L"love", L"wuv");
        ReplaceWord(Text, L"old", L"greymuzzle");
        ReplaceWord(Text, L"are", L"is");

        for (std::size_t i = 0; i < Text.size(); ++i)
        {
            if (Text[i] == L',' || Text[i] == L';') Text[i] = L'~';
            if (Text[i] == L'l' || Text[i] == L'r') Text[i] = L'w';
            if (Text[i] == L'L' || Text[i] == L'R') Text[i] = L'W';
        }

        ReplaceWord(Text, L"the", L"teh");
        ReplaceWord(Text, L"The", L"Teh");
        ReplaceWord(Text, L"this", L"dis");
        ReplaceWord(Text, L"This", L"Dis");
        ReplaceWord(Text, L"eat", L"vore");
        ReplaceWord(Text, L"bite", L"nom");
        ReplaceWord(Text, L"you", L"chu");
        ReplaceWord(Text, L"You", L"Chu");
        ReplaceWord(Text, L"fow", L"fur");
        ReplaceWord(Text, L"Fow", L"Fur");
        ReplaceWord(Text, L"hand", L"paw");
        ReplaceWord(Text, L"handwwiting", L"pawwriting");
        ReplaceWord(Text, L"pewsona", L"fursona");
        ReplaceWord(Text, L"disease", L"pathOwOgen");
        ReplaceWord(Text, L"not", L"knot");
        ReplaceWord(Text, L"computew", L"protogen");
        ReplaceWord(Text, L"wobot", L"protogen");
        ReplaceWord(Text, L"awesome", L"pawsome");
        ReplaceWord(Text, L"with", L"wif");
        ReplaceWord(Text, L"Taiws", L"Good boi Tawls c:");
        ReplaceWord(Text, L"sowwy", L"zowwy");
        ReplaceWord(Text, L"hawsh", L"rough");

        ReplaceText(Text, L"Homing Attack", L"Mid-Air Yiff Attack");
        ReplaceText(Text, L"Homing\nAttacks", L"Mid-Air Yiff\nAttacks");

        ReplaceWord(Text, L"shout", L"awoo");
        ReplaceText(Text, L"!", L" owo!");
        ReplaceText(Text, L"?", L" uwu?");
        ReplaceText(Text, L"  ", L" uwu ");

        ReplaceText(Text, L"na", L"nya");
        ReplaceText(Text, L"ne", L"nye");
        ReplaceText(Text, L"ni", L"nyi");
        ReplaceText(Text, L"no", L"nyo");
        ReplaceText(Text, L"nu", L"nyu");

        ReplaceWord(Text, L"omochao", L"oWochao");
        ReplaceWord(Text, L"Omochao", L"OWOchao");
        ReplaceWord(Text, L"Zavok", L"Daddy Dergok");
        ReplaceWord(Text, L"Zomom", L"Nom Nom");
        ReplaceWord(Text, L"Zazz", L"Zazztacular");
        ReplaceWord(Text, L"Zeena", L"Weenawoo");
        ReplaceWord(Text, L"Mastew Zik", L"Zikkin Miaz");
        ReplaceWord(Text, L"Zow", L"ZoWor");
        ReplaceWord(Text, L"Dw.", L"Doctowo");
        ReplaceText(Text, L"Eggman", L"Wobotnyic");

        return Text.data();
    }

    HB_HOOK_MEMBER(TextSystem, CConverseCellString2*, GetConverseData,
        const char* groupName, const char* cellName, unsigned int param_3)
    {
        CConverseCellString2* cellStr = HB_CALL_ORIGINAL(TextSystem::GetConverseData,
            thisPtr, groupName, cellName, param_3);

        cell = *cellStr;
        cell.Text = MakeFurry(cellStr->Text);
        return &cell;
    }

    HB_HOOK_MEMBER(TextSystem, CConverseCellString2*, GetConverseDataFromKey,
        unsigned int groupKey, unsigned int cellKey, unsigned int param_3)
    {
        CConverseCellString2* cellStr = HB_CALL_ORIGINAL(TextSystem::GetConverseDataFromKey,
            thisPtr, groupKey, cellKey, param_3);

        cell = *cellStr;
        cell.Text = MakeFurry(cellStr->Text);
        return &cell;
    }

    HB_HOOK_MEMBER(TextSystem, const wchar_t*, GetConverseDataText,
        const char* groupName, const char* cellName, unsigned int param_3)
    {
        const wchar_t* cellStr = HB_CALL_ORIGINAL(TextSystem::GetConverseDataText,
            thisPtr, groupName, cellName, param_3);

        return MakeFurry(cellStr);
    }
}

HB_HOOK_MEMBER(ApplicationWin, bool, CreateDevice)
{
    bool r = HB_CALL_ORIGINAL(ApplicationWin::CreateDevice, thisPtr);
    HWND hWnd = *reinterpret_cast<HWND*>((reinterpret_cast<std::uint8_t*>(thisPtr) + 228));
    SetWindowTextA(hWnd, "Sonyic Wost Wowwd");
    return r;
}
}

static void InstallHooks()
{
    using namespace app;
    using namespace text;

    INSTALL_HOOK_MEMBER(TextSystem, GetConverseData);
    INSTALL_HOOK_MEMBER(TextSystem, GetConverseDataFromKey);
    INSTALL_HOOK_MEMBER(TextSystem, GetConverseDataText);
    INSTALL_HOOK_MEMBER(ApplicationWin, CreateDevice);
}

extern "C"
{
    __declspec(dllexport) void Init(const char* path)
    {
        InstallHooks();
    }
}
