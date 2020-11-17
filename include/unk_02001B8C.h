#ifndef POKEDIAMOND_UNK_02001B8C_H
#define POKEDIAMOND_UNK_02001B8C_H

#define	MULTICHOICEMENU_NULL	( 0xffffffff )
#define	MULTICHOICEMENU_CANCEL	( 0xfffffffe )
#define	MULTICHOICEMENU_DUMMY	( 0xfffffffd )

struct UnkStruct_02001B82
{
    struct _BMP_MENULIST_DATA *menu;
    void *win;
    u8 font;
    u8 x_max;
    u8 y_max;
    u8 line_space : 4;
    u8 flag : 2;
    u8 loop_flag: 2;
};

struct UnkStruct_02001B94
{
    u32 color;
    void *strbuf;
};

struct UnkStruct_02001B80
{
    struct UnkStruct_02001B82 data;
    struct UnkStruct_02001B94 *cursor;
    u32 cancel;
    u8 index;
    u8 cur_pos;
    u8 str_len;
    u8 x;
    u8 y;
    u8 font_x;//string_x
    u8 font_y;
    u8 move_dir;
    u8 mode;
};

struct UnkStruct_02001B80 *InitMultiChoiceMenu(struct UnkStruct_02001B82 *data, u8 x, u8 y, u8 pos, u8 mode, u32 cancel);
struct UnkStruct_02001B80 *MultiChoiceMenu(struct UnkStruct_02001B82 *data, u8 x, u8 y, u8 pos, u8 mode, u32 cancel);
struct UnkStruct_02001B80 *MultiChoiceMenu2(struct UnkStruct_02001B82 *data, u8 pos, u8 mode);
void FUN_02001C5C(struct UnkStruct_02001B80 *unkStruct, u8 *backup);
u32 ChoiceMenu_HandleInput(struct UnkStruct_02001B80 *unkStruct);
u32 ChoiceMenu_HandleInput_SE(struct UnkStruct_02001B80 *unkStruct, u16 se);
u32 FUN_02001DDC(struct UnkStruct_02001B80 *unkStruct, u8 param);
u8 ChoiceMenuGetCursor(struct UnkStruct_02001B80 *unkStruct);
u8 ChoiceMenuGetMoveDirection(struct UnkStruct_02001B80 *unkStruct);
struct UnkStruct_02001B80 *InitYesNoMenu2(void *a0, void *a1, u16 a2, u8 a3, u8 a4, u32 heap);
struct UnkStruct_02001B80 *InitYesNoMenu(void *a0, void *a1, u16 a2, u8 a3, u32 heap);
u32 FUN_020021AC( struct UnkStruct_02001B80 * unkStruct, u32 heap );
u32 FUN_020021CC( struct UnkStruct_02001B80 * unkStruct, u8 a1, u32 heap );
void CloseYesNoMenu(struct UnkStruct_02001B80 * unkStruct, u32 heap );
void FUN_02002218(void *a0, u32 a1, u32 a2);
#endif // POKEDIAMOND_UNK_02001B8C_H