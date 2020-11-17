#ifndef POKEDIAMOND_UNK_02002C14_H
#define POKEDIAMOND_UNK_02002C14_H

struct MSG_PRINT_HEADER
{
    union
    {
        const u16 *msg;
        const void *strbuf;
    };
    void *bmpwin;
    u8 msg_index;
    u8 fnt_index;
    u8 width;
    u8 height;
    u8 unkB;
    u8 unkC;
    u8 font_space;
    u8 line_space;
    u8 type;
    u8 font_color;
    u8 back_color;
    u8 shadow_color;
    u16 unk14;
    u8 unk16;
    u8 fill;
};

struct FONT_DATA
{
    u8 fill[0x80];
    u8 unk81;
    u8 unk82;
};

struct FONT_TEMPLATE
{
    u8 width;
    u8 height;
    u8 font_space;
    u8 line_space;
    u8 type;
    u8 font_color;
    u8 back_color;
    u8 shadow_color;
};

struct MSG_PRINT_USER
{
    u8 unk1 : 4;
    u8 unk2 : 1;
    u8 unk3 : 3;
    u8 unk4 : 5;
    u8 unk5 : 2;
    u8 unk6 : 1;
    u8 unk7 : 8;
};

struct MSG_DATA
{
    struct MSG_PRINT_HEADER unkStruct;
    void *call_back;
    u8 unk0[7];
    u8 unk7;
    u8 unk8;
    u8 unk9_0 : 7;
    u8 unk9_1 : 1;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u16 unkE;
    void *unk10;
};

typedef enum {
	FONT_SYSTEM = 0,
	FONT_TALK,
	FONT_BUTTON,
	FONT_UNKNOWN,
	FONT_MAX,
}FONT_TYPE;

void FUN_02002C14(void);
void FUN_02002C50(FONT_TYPE font, u32 heapID);
void FUN_02002C84(FONT_TYPE font, u32 heapID);
void FUN_02002CF8(FONT_TYPE font);
void FUN_02002CC0(FONT_TYPE font);
u8 FontFunc(FONT_TYPE font, struct MSG_DATA *a0);
u8 FUN_02002E4C(u8 font_index, u8 param);
u32 FUN_02002E14(FONT_TYPE font, const void *str, u32 a2);
u32 FUN_02002DE0(FONT_TYPE font, const void *str, u32 a2);
const struct FONT_DATA *FUN_02002D94(FONT_TYPE font, u16 code);
void FUN_02002EEC(u32 type, u32 offs, u32 heap);
void FUN_02002ED0(u32 type, u32 offs, u32 heap);


#endif // POKEDIAMOND_UNK_02002C14_H