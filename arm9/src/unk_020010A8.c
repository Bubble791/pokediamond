#include "global.h"
#include "main.h"
#include "heap.h"
#include "unk_020010A8.h"

#pragma thumb on
#define  GF_PRINTCOLOR_MASK			(0xff)
#define  GF_PRINTCOLOR_LETTER_SHIFT	(16)
#define  GF_PRINTCOLOR_SHADOW_SHIFT	(8)
#define  GF_PRINTCOLOR_GROUND_SHIFT	(0)
#define  GF_PRINTCOLOR_MAKE(letter, shadow, ground)	(u32)((((letter)&GF_PRINTCOLOR_MASK) << GF_PRINTCOLOR_LETTER_SHIFT)|\
																		(((shadow)&GF_PRINTCOLOR_MASK) << GF_PRINTCOLOR_SHADOW_SHIFT)|\
																		(((ground)&GF_PRINTCOLOR_MASK) << GF_PRINTCOLOR_GROUND_SHIFT))

static void FUN_0200165C(struct BMPLIST_WORK *unk, void * msg, u8 x, u8 y);
static void FUN_02001714(struct BMPLIST_WORK *unk, u16 print_p, u16 line, u16 len);
static void FUN_020017AC(struct BMPLIST_WORK *unk);
static void FUN_02001804(struct BMPLIST_WORK *unk, u16 p);
static u8 FUN_0200186C(struct BMPLIST_WORK * unk, u8 mode);
static void FUN_0200198C(struct BMPLIST_WORK *unk, u8 len, u8 mode);
static u8 FUN_02001AA4(struct BMPLIST_WORK * unk, u8 print_f, u8 req_line, u8 mode);
static void FUN_02001B64(struct BMPLIST_WORK * unk, u8 mode);

extern u8* FUN_02013690(u8);
extern void FUN_020136E0(void*,u32);
extern void FUN_02019620(void*,u8);
extern void FUN_020136F8(void*,void*,u32,u32);
extern void FUN_020191D0(void*);
extern void FUN_020136C0(void*);
extern void FUN_02016A8C(u32,void*);
extern u8 FUN_02002E4C(u8,u8);
extern u8 AddTextPrinterParameterized3(void*,u32,void*,u32,u32,u32,u32,u32,u32,void*);
extern u8 FUN_020196F4(void*,u8,u16,u16,u16,u16);
extern void FUN_0201A8C8(void*,u8,u8,u8);
extern u8 FUN_0201AB0C(void*);
extern u8 FUN_0201AB10(void*);

struct BMPLIST_WORK * FUN_020010A8(struct BMPLIST_HEADER * bglist, u16 list_pos, u16 cursor_pos, u8 mode)
{
    struct BMPLIST_WORK * unk = AllocFromHeap(mode,sizeof(struct BMPLIST_WORK));
    unk->hed       = *bglist;
	unk->cursor    = FUN_02013690(mode);
	unk->lp        = list_pos;
	unk->cp        = cursor_pos;
	unk->seq       = 0;
	unk->scrwork   = 0;
	unk->cur_actID = 0xff;
	unk->work      = 0;
	unk->mode      = mode;
	unk->tmp.font_color   = unk->hed.font_color;
	unk->tmp.back_color   = unk->hed.back_color;
	unk->tmp.shadow_color   = unk->hed.shadow_color;
	unk->tmp.text_space = unk->hed.text_space;
	unk->tmp.font    = unk->hed.font;	
	unk->tmp.switch_      = 0;	

	if( unk->hed.count < unk->hed.line )
    {
		unk->hed.line = unk->hed.count;
	}

	FUN_020136E0(unk->cursor, GF_PRINTCOLOR_MAKE(unk->hed.font_color,unk->hed.shadow_color,unk->hed.back_color));

	FUN_02019620(unk->hed.win, unk->hed.back_color );
	FUN_02001714(unk, unk->lp, 0, unk->hed.line );
	FUN_020017AC(unk);

	FUN_02001B64(unk, 1);

	FUN_020191D0(bglist->win);

	return unk;
}

u32 FUN_02001204(struct BMPLIST_WORK * unk )
{
    u16 skip_u, skip_d;

    unk->work = 0;

    if (gMain.unk48 & 1)
    {
        return unk->hed.list2[unk->lp + unk->cp].param;
    }
    if (gMain.unk48 & 2)
    {
        return BMPLIST_CANCEL;
    }
    if (gMain.unk4C & 0x40)
    {
        if (!FUN_02001AA4(unk, 1, 1, 0))
            unk->work = 1;
        return BMPLIST_NULL;
    }
    if (gMain.unk4C & 0x80)
    {
        if (!FUN_02001AA4(unk, 1, 1, 1))
            unk->work = 2;
        return BMPLIST_NULL; // BMPLIST_NULL
    }

    switch (unk->hed.page_skip)
    {
    default:
	case 0:
		skip_u = 0;
		skip_d = 0;
		break;
	case 1:
		skip_u = (u16)(gMain.unk4C & 0x20);
		skip_d = (u16)(gMain.unk4C & 0x10);
		break;
	case 2:
		skip_u = (u16)(gMain.unk4C & 0x200);
		skip_d = (u16)(gMain.unk4C & 0x100);
		break;
    }
    if (skip_u)
    {
        if (!FUN_02001AA4(unk, 1, (u8)unk->hed.line, 0))
        {
            unk->work = 3;
        }
        return BMPLIST_NULL;
    }
    if (skip_d)
    {
        if (!FUN_02001AA4(unk, 1, (u8)unk->hed.line, 1))
        {
            unk->work = 4;
        }
        return BMPLIST_NULL;
    }

    return BMPLIST_NULL;
}

void FUN_02001300(struct BMPLIST_WORK * unk, u16 * list_bak, u16 * cursor_bak )
{
    if (list_bak)
        *list_bak = unk->lp;
    if (cursor_bak)
        *cursor_bak = unk->cp;
    FUN_020136C0(unk->cursor);
    FUN_02016A8C(unk->mode, unk);
}

void FUN_02001328(struct BMPLIST_WORK * unk )
{
    FUN_02019620(unk->hed.win, unk->hed.back_color);
	FUN_02001714(unk, unk->lp, 0, unk->hed.line);
	FUN_020017AC(unk);
	FUN_020191D0(unk->hed.win);
}

u32 FUN_02001354(struct BMPLIST_WORK *unk, struct BMPLIST_HEADER *bmplist,u16 list_p, u16 cursor_p, u16 print, u16 direct, u16 * list_bak, u16 * cursor_bak )
{
    if (bmplist)
        unk->hed = *bmplist;
    unk->lp = list_p;
    unk->cp = cursor_p;
    unk->seq = 0;
    unk->scrwork = 0;

    if (direct == 0x40)
        FUN_02001AA4(unk, print, 1, 0);
    else if (direct == 0x80)
        FUN_02001AA4(unk, print, 1, 1);
    if (list_bak)
        *list_bak = unk->lp;
    if (cursor_bak)
        *cursor_bak = unk->cp;

    return BMPLIST_NULL;
}

u32 FUN_020013C8(struct BMPLIST_WORK *unk, struct BMPLIST_HEADER *bmplist,u16 list_p, u16 cursor_p, u16 direct, u16 * list_bak, u16 * cursor_bak )
{
    return FUN_02001354(unk,bmplist,list_p,cursor_p,0,direct,list_bak,cursor_bak);
}

void FUN_020013E8(struct BMPLIST_WORK * unk, u8 f_col, u8 b_col, u8 s_col)
{
    unk->tmp.font_color = f_col;
	unk->tmp.back_color = b_col;
	unk->tmp.shadow_color = s_col;
	unk->tmp.switch_ = 1;	
}

void FUN_0200143C(struct BMPLIST_WORK * unk, u16 * pos_bak)
{
    *pos_bak = (u16)(unk->lp + unk->cp);
}

void FUN_02001448(struct BMPLIST_WORK * unk, u16 * list_bak, u16 * cursor_bak)
{
    if(list_bak)
		*list_bak = unk->lp;
	if(cursor_bak)
		*cursor_bak = unk->cp;
}

u16 FUN_0200145C(struct BMPLIST_WORK * unk)
{
    return unk->work;//0x33
}

u32 FUN_02001464(struct BMPLIST_WORK * unk, u16 pos)
{
    return unk->hed.list2[pos].param;
}

u32	FUN_02001470(struct BMPLIST_WORK * unk, u8 mode)
{
	u32	ret;

	switch(mode)
    {
	case 0:	
		ret = (u32)unk->hed.call_back;
		break;
	case 1:
		ret = (u32)unk->hed.icon;
		break;
	case 2:
		ret = (u32)unk->hed.count;
		break;
	case 3:	
		ret = (u32)unk->hed.line;
		break;
	case 5:
		ret = (u32)unk->hed.rabel_x;
		break;
	case 6:	
		ret = (u32)unk->hed.data_x;
		break;
	case 7:	
		ret = (u32)unk->hed.cursor_x;
		break;
	case 8:	
		ret = (u32)unk->hed.line_y;
		break;
	case 9:	
		ret = (u32)(FUN_02002E4C( unk->hed.font, 1 ) + unk->hed.line_space);
		break;
	case 10:
		ret = (u32)unk->hed.font_color;
		break;
	case 11:
		ret = (u32)unk->hed.back_color;
		break;
	case 12:
		ret = (u32)unk->hed.shadow_color;
		break;
	case 13:
		ret = (u32)unk->hed.text_space;
		break;
	case 14:
		ret = (u32)unk->hed.line_space;
		break;
	case 15:
		ret = (u32)unk->hed.page_skip;
		break;
	case 16:
		ret = (u32)unk->hed.font;
		break;
	case 17:
		ret = (u32)unk->hed.c_disp_f;
		break;
	case 18:
		ret = (u32)unk->hed.win;
		break;
	case 19:
		ret = (u32)unk->hed.work;
		break;

	default:
		ret = 0xffffffff;
	}
	return ret;
}

void FUN_02001538(struct BMPLIST_WORK * unk, u8 mode, u32 param)
{
	switch(mode){
	case 0:	
		unk->hed.call_back = (void *)param;
		break;
	case 1:	
		unk->hed.icon = (void *)param;
		break;
	case 2:	
		unk->hed.count = (u16)param;
		break;
	case 3:	
		unk->hed.line = (u16)param;
		break;
	case 5:	
		unk->hed.rabel_x = (u8)param;
		break;
	case 6:	
		unk->hed.data_x = (u8)param;
		break;
	case 7:	
		unk->hed.cursor_x = (u8)param;
		break;
	case 8:	
		unk->hed.line_y = (u8)param;
		break;
	case 10:
		unk->hed.font_color = (u8)param;
		break;
	case 11:
		unk->hed.back_color = (u8)param;
		break;
	case 12:
		unk->hed.shadow_color = (u8)param;
		break;
	case 13:
		unk->hed.text_space = (u8)param;
		break;
	case 14:
		unk->hed.line_space = (u8)param;
		break;
	case 15:
		unk->hed.page_skip = (u8)param;
		break;
	case 16:
		unk->hed.font = (u8)param;
		break;
	case 17:
		unk->hed.c_disp_f = (u8)param;
		break;
	case 18:
		unk->hed.win = (void *)param;
		break;
	case 19:
		unk->hed.work = (void *)param;
		break;
	}
}

void FUN_02001658(struct BMPLIST_WORK * unk, struct _BMP_MENULIST_DATA* pList)
{
    unk->hed.list2 = pList;
}

static void FUN_0200165C(struct BMPLIST_WORK * unk, void * msg, u8 x, u8 y)
{
    if(!msg)
        return;
    if(unk->tmp.switch_)
        AddTextPrinterParameterized3(unk->hed.win,
            unk->tmp.font,
            msg,
            x,
            y,
            0xff,
            GF_PRINTCOLOR_MAKE(unk->tmp.font_color, unk->tmp.shadow_color, unk->tmp.back_color),
            unk->tmp.text_space,
            0,
            NULL);
    else
        AddTextPrinterParameterized3(unk->hed.win,
            unk->hed.font,
            msg,
            x,
            y,
            0xff,
            GF_PRINTCOLOR_MAKE(unk->hed.font_color, unk->hed.shadow_color, unk->hed.back_color),
            unk->hed.text_space,
            0,
            NULL);
}

static void FUN_02001714(struct BMPLIST_WORK * unk, u16 print_p, u16 line, u16 len)
{
    int	i;
	u8	x,y,yblk;

	yblk = FUN_02002E4C(unk->hed.font,1) + unk->hed.line_space;

	for( i=0; i<len ;i++ )
    {
		if(unk->hed.list2[print_p].param != BMPLIST_RABEL)
			x = unk->hed.data_x;
        else
			x = unk->hed.rabel_x;
		y = (u8)(((i + line) * yblk) + unk->hed.line_y);
		if( unk->hed.icon != NULL )
			unk->hed.icon(unk, unk->hed.list2[print_p].param,y );
		FUN_0200165C( unk, (void*)unk->hed.list2[print_p].str, x, y );
		print_p++;
	}
}

static void FUN_020017AC(struct BMPLIST_WORK * unk)
{
    u8	x,y,yblk;

	yblk = FUN_02002E4C(unk->hed.font,1) + unk->hed.line_space;
	x = unk->hed.cursor_x;
	y = (u8)((unk->cp * yblk) + unk->hed.line_y);

	switch(unk->hed.c_disp_f){
	case 0:
		FUN_020136F8( unk->cursor, unk->hed.win, x, y );
		break;
	case 1:
	case 2:
	case 3:
		break;
	}
}

static void FUN_02001804(struct BMPLIST_WORK * unk, u16 p)
{
	u8	yblk;

	switch(unk->hed.c_disp_f)
    {
	case 0:
		yblk = FUN_02002E4C(unk->hed.font,1) + unk->hed.line_space;

        FUN_020196F4(unk->hed.win,
            (u8)unk->hed.back_color,
            unk->hed.cursor_x,
            (u16)(p * yblk + unk->hed.line_y),
            8,
            16);
        break;
	case 1:
	case 2:
	case 3:
		break;
	}
}

static u8 FUN_0200186C(struct BMPLIST_WORK * unk, u8 mode)
{
	u16	list_p,cursor_p,check_p;

	cursor_p	= unk->cp;
	list_p		= unk->lp;

	if(mode == 0)
    {
		if(unk->hed.line == 1)
			check_p = 0;
		else
			check_p = (u16)(unk->hed.line - ((unk->hed.line / 2) + (unk->hed.line % 2)) - 1);

		if(list_p == 0)
        {
			while(cursor_p > 0)
            {
				cursor_p--;
				if(unk->hed.list2[list_p + cursor_p].param != BMPLIST_RABEL)
                {
					unk->cp = cursor_p;
					return 1;
				}
			}
			return 0;
		}
		while(cursor_p > check_p)
        {
			cursor_p--;
			if(unk->hed.list2[list_p + cursor_p].param != BMPLIST_RABEL)
            {
				unk->cp = cursor_p;
				return 1;
			}
		}
		list_p--;
		unk->cp = check_p;
		unk->lp = list_p;

	}
    else
    {
		if(unk->hed.line == 1)
			check_p = 0;
		else
			check_p = (u16)((unk->hed.line / 2) + (unk->hed.line % 2));

		if(list_p == (unk->hed.count - unk->hed.line))
        {
			while(cursor_p < (unk->hed.line - 1))
            {
				cursor_p++;
				if(unk->hed.list2[list_p + cursor_p].param != BMPLIST_RABEL)
                {
					unk->cp = cursor_p;
					return 1;
				}
			}
			return 0;
		}
		while(cursor_p < check_p)
        {
			cursor_p++;
			if(unk->hed.list2[list_p + cursor_p].param != BMPLIST_RABEL)
            {
				unk->cp = cursor_p;
				return 1;
			}
		}
		list_p++;
		unk->cp = check_p;
		unk->lp = list_p;
	}
	return 2;
}

static void FUN_0200198C(struct BMPLIST_WORK *unk, u8 len, u8 mode )
{
	u8	yblk;
	u16	ypos;

	if(len >= unk->hed.line)
    {
		FUN_02019620(unk->hed.win, unk->hed.back_color);
		FUN_02001714(unk, unk->lp, 0, unk->hed.line);
		return;
	}
	yblk = FUN_02002E4C(unk->hed.font, 1) + unk->hed.line_space;

	if(!mode)
    {
		FUN_0201A8C8(unk->hed.win, 1,(u8)(len * yblk), (u8)((unk->hed.back_color<<4)|unk->hed.back_color));
		FUN_02001714( unk, unk->lp, 0, len );
		ypos = (u16)( unk->hed.line * yblk + unk->hed.line_y );
        FUN_020196F4(unk->hed.win,
            (u8)unk->hed.back_color,
            0,
            ypos,
            (u16)(FUN_0201AB0C(unk->hed.win) * 8),
            (u16)(FUN_0201AB10(unk->hed.win) * 8 - ypos));
    }
    else
    {
		FUN_0201A8C8(unk->hed.win, 0,(u8)(len * yblk), (u8)((unk->hed.back_color<<4)|unk->hed.back_color) );
		FUN_02001714(unk, (u16)(unk->lp + (unk->hed.line-len)), (u16)(unk->hed.line - len), (u16)len );
		FUN_020196F4(unk->hed.win,(u8)unk->hed.back_color,0, 0,(u16)(FUN_0201AB0C( unk->hed.win ) * 8),(u16)unk->hed.line_y );
	}
}

static u8 FUN_02001AA4(struct BMPLIST_WORK * unk, u8 print_f, u8 req_line, u8 mode )
{
    u16 cursor_bak;
    u8 write_flg, write_req;
    u8 reqcount, linecount;

    cursor_bak = unk->cp;
    linecount = 0;
    write_req = 0;

    for (reqcount = 0; reqcount < req_line; reqcount++)
    {
        do
        {
            write_flg = FUN_0200186C(unk, mode);
            write_req |= write_flg;
            if (write_flg != 2)
            {
                break;
            }
            linecount++;
        } while (unk->hed.list2[unk->lp + unk->cp].param == BMPLIST_RABEL);
    }

    if (print_f)
    {
        switch (write_req)
        {
        default:
        case 0:
            return 1;
            break;
        case 1:
            FUN_02001804(unk, cursor_bak);
            FUN_020017AC(unk);
            FUN_02001B64(unk, 0);
            FUN_020191D0(unk->hed.win);
            break;
        case 2:
        case 3:
            FUN_02001804(unk, cursor_bak);
            FUN_0200198C(unk, linecount, mode);
            FUN_020017AC(unk);
            FUN_02001B64(unk, 0);
            FUN_020191D0(unk->hed.win);
            break;
        }
    }

    return 0;
}

static void FUN_02001B64(struct BMPLIST_WORK * unk, u8 mode)
{
	if(unk->hed.call_back)
		unk->hed.call_back(unk, unk->hed.list2[unk->lp + unk->cp].param, mode);
}