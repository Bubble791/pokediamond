#include "global.h"
#include "unk_02001B8C.h"
#include "heap.h"
#include "main.h"
#include "msgdata.h"
#include "unk_020010A8.h"

#pragma thumb on
static BOOL ChoiceMenuMoveCursor(struct UnkStruct_02001B80 *unkStruct, u8 move, u16 se);
static u8 CursorMoveCheck(struct UnkStruct_02001B80 *unkStruct, u8 move);
static u8 GetMaxStringLen(struct UnkStruct_02001B80 *buf);
static void MultiChoicePutString(struct UnkStruct_02001B80 *unkStruct);
static void MultiChoicePutCursor(struct UnkStruct_02001B80 *unkStruct);
static void GetCursorPos(struct UnkStruct_02001B80 *unkStruct, u8 *x, u8 *y, u8 pos);

extern void *FUN_02013690(u32);
extern u8 FUN_02002E4C(u8, u8);
extern void FUN_020136F8(void *, void *, u32, u32);
extern void FUN_020191D0(void *);
extern void FUN_02016A8C(u32, void *);
extern void FUN_020136C0(void *);
extern BOOL FUN_020054C8(u16);
extern void FUN_020196F4(void *, u8, u16, u16, u16, u16);
extern u32 FUN_02002E14(u8, void *, u32);
extern void FUN_02019620(void *, u8);
extern u8 AddTextPrinterParameterized(void *, u32, void *, u32, u32, u32, void *);
extern void *ListMenu_ctor(u32, u32);
extern void ListMenu_ItemFromMsgData(void *, void *, u32, u32);
extern void *FUN_02018FF4(u32, u8);
extern void FUN_02019150(void *, void *, void *);
extern void FUN_0200CCA4(void *, u8, u16, u8);
extern void FUN_0200CCF8(void *, u8);
extern void FUN_02019178(void *);
extern void ListMenu_dtor(void *);
extern void FUN_02019658(void*,void*,u16,u16,u16,u16,u16,u16,u16,u16);

struct UnkStruct_02001B80 *InitMultiChoiceMenu(
    struct UnkStruct_02001B82 *data, u8 x, u8 y, u8 pos, u8 mode, u32 cancel)
{
    struct UnkStruct_02001B80 *unkStruct = AllocFromHeap(mode, sizeof(struct UnkStruct_02001B80));

    unkStruct->data = *data;
    unkStruct->cursor = FUN_02013690(mode);
    unkStruct->cancel = cancel;
    unkStruct->cur_pos = pos;
    unkStruct->str_len = GetMaxStringLen(unkStruct);//Get the maximum number of characters
    unkStruct->mode = mode;

    unkStruct->x = x;
    unkStruct->y = y;
    unkStruct->font_x = FUN_02002E4C(data->font, 0) + FUN_02002E4C(data->font, 2);//font data
    unkStruct->font_y = FUN_02002E4C(data->font, 1) + FUN_02002E4C(data->font, 3);

    MultiChoicePutString(unkStruct);
    MultiChoicePutCursor(unkStruct);

    return unkStruct;
}

struct UnkStruct_02001B80 *MultiChoiceMenu(
    struct UnkStruct_02001B82 *data, u8 x, u8 y, u8 pos, u8 mode, u32 cancel)
{
    struct UnkStruct_02001B80 *unkStruct = InitMultiChoiceMenu(data, x, y, pos, mode, cancel);

    FUN_020191D0(unkStruct->data.win);

    return unkStruct;
}

struct UnkStruct_02001B80 *MultiChoiceMenu2(struct UnkStruct_02001B82 *data, u8 pos, u8 mode)
{
    return MultiChoiceMenu(data, FUN_02002E4C(data->font, 0), 0, pos, mode, 2);
}

void FUN_02001C5C(struct UnkStruct_02001B80 *unkStruct, u8 *a1)
{
    if (a1)
    {
        *a1 = unkStruct->cur_pos;
    }
    FUN_020136C0(unkStruct->cursor);
    FUN_02016A8C(unkStruct->mode, unkStruct);
}

u32 ChoiceMenu_HandleInput(struct UnkStruct_02001B80 *unkStruct)
{
    unkStruct->move_dir = 0;

    if (gMain.unk48 & 1)//Button A
    {
        FUN_020054C8(0x5dc);//se play
        return unkStruct->data.menu[unkStruct->cur_pos].param;
    }
    if (gMain.unk48 & unkStruct->cancel)
    {
        FUN_020054C8(0x5dc);
        return MULTICHOICEMENU_CANCEL;
    }
    if (gMain.unk48 & 0x40)//Button UP
    {
        if (ChoiceMenuMoveCursor(unkStruct, 0, 0x5dc)== TRUE)
        {
            unkStruct->move_dir = 1;
        }
        return MULTICHOICEMENU_NULL;
    }
    if (gMain.unk48 & 0x80)//Button DOWN
    {
        if (ChoiceMenuMoveCursor(unkStruct, 1, 0x5dc)== TRUE)
        {
            unkStruct->move_dir = 2;
        }
        return MULTICHOICEMENU_NULL;
    }
    if (gMain.unk48 & 0x20)//Button LEFT
    {
        if (ChoiceMenuMoveCursor(unkStruct, 2, 0x5dc)== TRUE)
        {
            unkStruct->move_dir = 3;
        }
        return MULTICHOICEMENU_NULL;
    }
    if (gMain.unk48 & 0x10)//Button RIGHT
    {
        if (ChoiceMenuMoveCursor(unkStruct, 3, 0x5dc)== TRUE)
        {
            unkStruct->move_dir = 4;
        }
        return MULTICHOICEMENU_NULL;
    }

    return MULTICHOICEMENU_NULL;
}

u32 ChoiceMenu_HandleInput_SE(struct UnkStruct_02001B80 *unkStruct, u16 se)
{
    unkStruct->move_dir = 0;

    if (gMain.unk48 & 1)
    {
        FUN_020054C8(0x5dc);
        return unkStruct->data.menu[unkStruct->cur_pos].param;
    }
    if (gMain.unk48 & unkStruct->cancel)
    {
        FUN_020054C8(0x5dc);
        return MULTICHOICEMENU_CANCEL;
    }
    if (gMain.unk48 & 0x40)
    {
        if (ChoiceMenuMoveCursor(unkStruct, 0, se)== TRUE)
        {
            unkStruct->move_dir = 1;
        }
        return MULTICHOICEMENU_NULL;
    }
    if (gMain.unk48 & 0x80)
    {
        if (ChoiceMenuMoveCursor(unkStruct, 1, se)== TRUE)
        {
            unkStruct->move_dir = 2;
        }
        return MULTICHOICEMENU_NULL;
    }
    if (gMain.unk48 & 0x20)
    {
        if (ChoiceMenuMoveCursor(unkStruct, 2, se)== TRUE)
        {
            unkStruct->move_dir = 3;
        }
        return MULTICHOICEMENU_NULL;
    }
    if (gMain.unk48 & 0x10)
    {
        if (ChoiceMenuMoveCursor(unkStruct, 3, se)== TRUE)
        {
            unkStruct->move_dir = 4;
        }
        return MULTICHOICEMENU_NULL;
    }

    return MULTICHOICEMENU_NULL;
}

u32 FUN_02001DDC(struct UnkStruct_02001B80 *unkStruct, u8 param)
{
    switch (param)
    {
    case 0:
        FUN_020054C8(0x5dc);
        return unkStruct->data.menu[unkStruct->cur_pos].param;

    case 1:
        FUN_020054C8(0x5dc);
        return MULTICHOICEMENU_CANCEL;

    case 2:
        ChoiceMenuMoveCursor(unkStruct, 0, 0x5dc);
        return MULTICHOICEMENU_NULL;

    case 3:
        ChoiceMenuMoveCursor(unkStruct, 1, 0x5dc);
        return MULTICHOICEMENU_NULL;

    case 4:
        ChoiceMenuMoveCursor(unkStruct, 2, 0x5dc);
        return MULTICHOICEMENU_NULL;

    case 5:
        ChoiceMenuMoveCursor(unkStruct, 3, 0x5dc);
        return MULTICHOICEMENU_NULL;
    }

    return MULTICHOICEMENU_NULL;
}

u8 ChoiceMenuGetCursor(struct UnkStruct_02001B80 *unkStruct)
{
    return unkStruct->cur_pos;
}

u8 ChoiceMenuGetMoveDirection(struct UnkStruct_02001B80 *unkStruct)
{
    return unkStruct->move_dir;
}

static BOOL ChoiceMenuMoveCursor(struct UnkStruct_02001B80 *unkStruct, u8 move, u16 se)
{
    u8 px, py,font_backcolor;
    u8 old = unkStruct->cur_pos;

    if (!CursorMoveCheck(unkStruct, move))
        return FALSE;

    font_backcolor = FUN_02002E4C(unkStruct->data.font, 6);
    GetCursorPos(unkStruct, &px, &py, old);
    FUN_020196F4(unkStruct->data.win, font_backcolor, px, py, 8, unkStruct->font_y);

    MultiChoicePutCursor(unkStruct);
    FUN_020054C8(se);

    return TRUE;
}

static u8 CursorMoveCheck(struct UnkStruct_02001B80 *unkStruct, u8 move)
{
    s8 new_pos;

    if (move == 0)
    {
        if (unkStruct->data.y_max <= 1)
        {
            return FALSE;
        }
        if ((unkStruct->cur_pos % unkStruct->data.y_max) == 0)
        {
            if (unkStruct->data.loop_flag == 0)
            {
                return FALSE;
            }

            new_pos = unkStruct->cur_pos + (unkStruct->data.y_max - 1);
        }
        else
        {

            new_pos = unkStruct->cur_pos - 1;
        }
    }
    else if (move == 1)
    {
        if (unkStruct->data.y_max <= 1)
        {
            return FALSE;
        }
        if ((unkStruct->cur_pos % unkStruct->data.y_max) == (unkStruct->data.y_max - 1))
        {
            if (unkStruct->data.loop_flag == 0)
            {
                return FALSE;
            }

            new_pos = unkStruct->cur_pos - (unkStruct->data.y_max - 1);
        }
        else
        {

            new_pos = unkStruct->cur_pos + 1;
        }
    }
    else if (move == 2)
    {
        if (unkStruct->data.x_max <= 1)
        {
            return FALSE;
        }
        if (unkStruct->cur_pos < unkStruct->data.y_max)
        {
            if (unkStruct->data.loop_flag == 0)
            {
                return FALSE;
            }

            new_pos = unkStruct->cur_pos + (unkStruct->data.y_max * (unkStruct->data.x_max - 1));
        }
        else
        {

            new_pos = unkStruct->cur_pos - unkStruct->data.y_max;
        }
    }
    else
    {
        if (unkStruct->data.x_max <= 1)
        {
            return FALSE;
        }
        if (unkStruct->cur_pos >= (unkStruct->data.y_max * (unkStruct->data.x_max - 1)))
        {
            if (unkStruct->data.loop_flag == 0)
            {
                return FALSE;
            }

            new_pos = unkStruct->cur_pos % unkStruct->data.y_max;
        }
        else
        {

            new_pos = unkStruct->cur_pos + unkStruct->data.y_max;
        }
    }

    if (unkStruct->data.menu[new_pos].param == MULTICHOICEMENU_DUMMY)
    {
        return FALSE;
    }
    unkStruct->cur_pos = new_pos;
    return TRUE;
}

static u8 GetMaxStringLen(struct UnkStruct_02001B80 *buff)
{
    u8 len = 0;
    u8 i, j;

    for (i = 0; i < buff->data.x_max * buff->data.y_max; i++)
    {
        j = FUN_02002E14(buff->data.font, buff->data.menu[i].str, 0);
        if (len < j)
        {
            len = j;
        }
    }

    return len;
}

static void MultiChoicePutString(struct UnkStruct_02001B80 *unkStruct)
{
    const void *string;
    u8 x, y, a0;
    u8 i, j;

    FUN_02019620(unkStruct->data.win, FUN_02002E4C(unkStruct->data.font, 6));

    x = unkStruct->x;
    a0 = unkStruct->str_len + unkStruct->font_x * 2;
    for (i = 0; i < unkStruct->data.x_max; i++)
    {
        for (j = 0; j < unkStruct->data.y_max; j++)
        {
            string = unkStruct->data.menu[i * unkStruct->data.y_max + j].str;
            y = (unkStruct->font_y + unkStruct->data.line_space) * j + unkStruct->y;
            AddTextPrinterParameterized(unkStruct->data.win, unkStruct->data.font, string, x, y, 0xff, NULL);
        }
        x += a0;
    }
}

static void MultiChoicePutCursor(struct UnkStruct_02001B80 *unkStruct)
{
    u8 px, py;

    if (unkStruct->data.flag == 1)
    {
        return;
    }

    GetCursorPos(unkStruct, &px, &py, unkStruct->cur_pos);
    FUN_020136F8(unkStruct->cursor, unkStruct->data.win, px, py);
}

static void GetCursorPos(struct UnkStruct_02001B80 *unkStruct, u8 *x, u8 *y, u8 pos)
{
    *x = (pos / unkStruct->data.y_max) * (unkStruct->str_len + unkStruct->font_x * 2);
    *y = (pos % unkStruct->data.y_max) * (unkStruct->font_y + unkStruct->data.line_space) + unkStruct->y;
}

struct UnkStruct_02001B80 *InitYesNoMenu2(void *a0, void *a1, u16 a2, u8 a3, u8 a4, u32 heap)
{
    struct UnkStruct_02001B82 data;
    struct MsgData *text;
    struct _BMP_MENULIST_DATA *ld;

    text = NewMsgDataFromNarc(1, 26, 0x141, heap);
    ld = ListMenu_ctor(2, heap);
    ListMenu_ItemFromMsgData(ld, text, 41, 0);
    ListMenu_ItemFromMsgData(ld, text, 42, MULTICHOICEMENU_CANCEL);
    DestroyMsgData(text);

    data.menu = ld;
    data.win = FUN_02018FF4(heap, 1);
    data.font = 0;
    data.x_max = 1;
    data.y_max = 2;
    data.line_space = 0;
    data.flag = 0;
    data.line_space = 0;

    FUN_02019150(a0, data.win, a1);
    FUN_0200CCA4(data.win, 1, a2, a3);
    return MultiChoiceMenu(&data, 8, 0, a4, heap, 2);
}

struct UnkStruct_02001B80 *InitYesNoMenu(void *a0, void *a1, u16 a2, u8 a3, u32 heap)
{
    return InitYesNoMenu2(a0, a1, a2, a3, 0, heap);
}

u32 FUN_020021AC(struct UnkStruct_02001B80 *unkStruct, u32 heap)
{
    u32 ret = ChoiceMenu_HandleInput(unkStruct);

    if (ret != MULTICHOICEMENU_NULL)
    {
        CloseYesNoMenu(unkStruct, heap);
    }
    return ret;
}

u32 FUN_020021CC(struct UnkStruct_02001B80 *unkStruct, u8 a1, u32 heap)
{
    u32 ret = FUN_02001DDC(unkStruct, a1);

    if (ret != MULTICHOICEMENU_NULL)
    {
        CloseYesNoMenu(unkStruct, heap);
    }
    return ret;
}

void CloseYesNoMenu(struct UnkStruct_02001B80 *unkStruct, u32 heap)
{
    FUN_0200CCF8(unkStruct->data.win, 0);
    FUN_02019178(unkStruct->data.win);
    FUN_02016A8C(heap, unkStruct->data.win);
    ListMenu_dtor((struct _BMP_MENULIST_DATA *)unkStruct->data.menu);
    FUN_02001C5C(unkStruct, NULL);
}

void FUN_02002218(void *a0, u32 a1, u32 a2)
{
    FUN_02019658(a0, (void *)0x020ECAC8, 0, 0, 8, 16, a1, a2, 8, 16);
}
