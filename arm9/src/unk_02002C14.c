#include "global.h"
#include "heap.h"
#include "main.h"
#include "msgdata.h"
#include "unk_02002C14.h"

#pragma thumb on

static const struct
{
    u16 index;
    u16 flag;
}FontDataTable[] = {
    {
        0,
        FALSE,
    },
    {
        1,
        FALSE,
    },
    {
        2,
        FALSE,
    },
    {
        3,
        FALSE,
    },
};

struct FONT
{
    struct FONT_DATA unk0;
    void *fontData[NELEMS(FontDataTable)];
    void *fontMsg[NELEMS(FontDataTable)];
};

static const struct FONT_TEMPLATE font_template[] = {
    { 11, 16, 0, 0, 0, 1, 15, 2 },
    { 11, 16, 0, 0, 0, 1, 15, 2 },
    { 11, 16, 0, 0, 0, 1, 15, 2 },
    { 11, 16, 0, 0, 0, 1, 15, 2 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

struct FONT *UNK_02106FC8 = NULL;
static struct FONT UNK_02106FCC = {0};

extern void FUN_0201BCBC(void *);
extern void *FUN_02021590(u32, u32, u8, BOOL, u32);
extern void FUN_020215E0(void *, u8, u32);
extern void FUN_020215C8(void *);
extern void FUN_02021750(void *, u16, void *);
extern u8 RenderText(void *);
extern u32 FUN_020218D8(void *, void *, u32);
extern void FUN_02006930(u32, u32, u32, u32, u32, u32);

void FUN_02002C14(void)
{
    u32 i;

    UNK_02106FC8 = &UNK_02106FCC;

    for (i = 0; i < NELEMS(FontDataTable); i++)
    {
        UNK_02106FC8->fontData[i] = NULL;
        UNK_02106FC8->fontMsg[i] = NULL;
    }

    FUN_0201BCBC(font_template);
}

void FUN_02002C50(FONT_TYPE font, u32 heapID)
{
    UNK_02106FC8->fontMsg[font] =
        FUN_02021590(14, FontDataTable[font].index, 1, FontDataTable[font].flag, heapID);
}

void FUN_02002C84(FONT_TYPE font, u32 heapID)
{
    GF_ASSERT(font < FONT_MAX);
    GF_ASSERT(UNK_02106FC8->fontMsg[font]);

    FUN_020215E0(UNK_02106FC8->fontMsg[font], 0, heapID);
}

void FUN_02002CC0(FONT_TYPE font)
{
    GF_ASSERT(font < FONT_MAX);
    GF_ASSERT(UNK_02106FC8->fontMsg[font]);

    FUN_020215E0(UNK_02106FC8->fontMsg[font], 1, 0);
}

void FUN_02002CF8(FONT_TYPE font)
{
    GF_ASSERT(font < FONT_MAX);

    if (UNK_02106FC8->fontData[font])
    {
        int i;
        for (i = 0; i < NELEMS(FontDataTable); i++)
        {
            if (i == font)
            {
                continue;
            }
            if ((FontDataTable[i].index == FontDataTable[font].index) &&
                (UNK_02106FC8->fontMsg[i]))
            {
                UNK_02106FC8->fontData[i] = UNK_02106FC8->fontData[font];
                break;
            }
        }
        if (i == NELEMS(FontDataTable))
        {
            FreeToHeap(UNK_02106FC8->fontData[font]);
            UNK_02106FC8->fontData[font] = NULL;
        }
    }

    if (UNK_02106FC8->fontMsg[font])
    {
        FUN_020215C8(UNK_02106FC8->fontMsg[font]);
        UNK_02106FC8->fontMsg[font] = NULL;
    }
}

const struct FONT_DATA *FUN_02002D94(FONT_TYPE font, u16 code)
{
    FUN_02021750(UNK_02106FC8->fontMsg[font], code, &UNK_02106FC8->unk0);
    return &(UNK_02106FC8->unk0);
}

u8 FontFunc(FONT_TYPE font, struct MSG_DATA *a0)
{
    struct MSG_PRINT_USER *a1;

    a1 = (struct MSG_PRINT_USER *)&(a0->unk0[0]);
    if (!a1->unk6)
    {
        a1->unk1 = font;
        a1->unk6 = 1;
    }
    return RenderText(a0);
}

u32 FUN_02002DE0(FONT_TYPE font, const void *str, u32 a2)
{
    GF_ASSERT(UNK_02106FC8->fontMsg[font]);
    return FUN_020218D8(UNK_02106FC8->fontMsg[font], str, a2);
}

u32 FUN_02002E14(FONT_TYPE font, const void *str, u32 a2)
{
    GF_ASSERT(UNK_02106FC8->fontMsg[font]);
    return FUN_020218D8(UNK_02106FC8->fontMsg[font], String_c_str(str), a2);
}

u8 FUN_02002E4C(u8 font_index, u8 param)
{
    u8 ret = 0;

    switch (param)
    {
    case 0:
        ret = font_template[font_index].width;
        break;
    case 1:
        ret = font_template[font_index].height;
        break;
    case 2:
        ret = font_template[font_index].font_space;
        break;
    case 3:
        ret = font_template[font_index].line_space;
        break;
    case 4:
        ret = font_template[font_index].type;
        break;
    case 5:
        ret = font_template[font_index].font_color;
        break;
    case 6:
        ret = font_template[font_index].back_color;
        break;
    case 7:
        ret = font_template[font_index].shadow_color;
        break;
    }

    return ret;
}
void FUN_02002ED0(u32 type, u32 offs, u32 heap)
{
    FUN_02006930(14, 6, type, offs, 0x20, heap);
}

void FUN_02002EEC(u32 type, u32 offs, u32 heap)
{
    FUN_02006930(14, 7, type, offs, 0x20, heap);
}
