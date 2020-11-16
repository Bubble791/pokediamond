#ifndef POKEDIAMOND_UNK_020010A8_H
#define POKEDIAMOND_UNK_020010A8_H

#define	BMPLIST_NULL	(0xffffffff)
#define	BMPLIST_CANCEL	(0xfffffffe)
#define	BMPLIST_RABEL	(0xfffffffd)

struct BMPLIST_TMP
{
	u8	font_color:4;
	u8	back_color:4;
	u8	shadow_color:4;	
	u8	text_space:6;
	u8	fill:6;
	u8	font:7;	
	u8	switch_:1;
};

struct _BMP_MENULIST_DATA
{
	const void * str;
	u32	param;
};

struct BMPLIST_HEADER
{
	struct _BMP_MENULIST_DATA *list2;
	void (*call_back)(void*,u32,u8);
	void (*icon)(void*,u32,u8);
	u8 *win;
	u16 count;
	u16 line;
	u8 rabel_x;
	u8 data_x;	
	u8 cursor_x;
	u8 line_y:4;
	u8 font_color:4;
	u8 back_color:4;
	u8 shadow_color:4;
	u16 text_space:3;
	u16 line_space:4;
	u16 page_skip:2;
	u16 font:6;	
	u16 c_disp_f:1;
	void * work;
};

struct BMPLIST_WORK {

	struct BMPLIST_HEADER	hed;
	struct BMPLIST_TMP  tmp;
	u8 *cursor;
	u16	lp;	
	u16	cp;	
	u8	seq;
	u8	scrwork;
	u8	cur_actID;
	u8	work;
	u8	mode;
};

struct BMPLIST_WORK * FUN_020010A8(struct BMPLIST_HEADER * bmplist, u16 list_p, u16 cursor_p, u8 mode);
u32 FUN_02001204(struct BMPLIST_WORK * unk );
void FUN_02001300(struct BMPLIST_WORK * unk, u16 * list_bak, u16 * cursor_bak );
void FUN_02001328(struct BMPLIST_WORK * unk );
u32 FUN_02001354(struct BMPLIST_WORK *unk, struct BMPLIST_HEADER *bmplist,u16 list_p, u16 cursor_p, u16 print, u16 direct, u16 * list_bak, u16 * cursor_bak );
u32 FUN_020013C8(struct BMPLIST_WORK *unk, struct BMPLIST_HEADER *bmplist,u16 list_p, u16 cursor_p, u16 direct, u16 * list_bak, u16 * cursor_bak );
void FUN_020013E8(struct BMPLIST_WORK * unk, u8 f_col, u8 b_col, u8 s_col );
void FUN_0200143C(struct BMPLIST_WORK * unk, u16 * pos_bak );
void FUN_02001448(struct BMPLIST_WORK *unk, u16 *list_bak, u16 *cursor_bak);
u16 FUN_0200145C(struct BMPLIST_WORK *unk);
u32 FUN_02001464(struct BMPLIST_WORK *unk, u16 pos);
u32 FUN_02001470(struct BMPLIST_WORK *unk, u8 mode);
void FUN_02001538(struct BMPLIST_WORK *unk, u8 mode, u32 param);
void FUN_02001658(struct BMPLIST_WORK *unk, struct _BMP_MENULIST_DATA *pList);
//void FUN_0200165C(struct BMPLIST_WORK * unk, void * msg, u8 x, u8 y );
#endif //POKEDIAMOND_UNK_020010A8_H