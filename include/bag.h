#ifndef POKEDIAMOND_BAG_H
#define POKEDIAMOND_BAG_H

#include "itemtool.h"
#include "save_block_2.h"

struct Bag
{
    struct ItemSlot items[NUM_BAG_ITEMS];
    struct ItemSlot keyItems[NUM_BAG_KEY_ITEMS];
    struct ItemSlot TMsHMs[NUM_BAG_TMS_HMS];
    struct ItemSlot mail[NUM_BAG_MAIL];
    struct ItemSlot medicine[NUM_BAG_MEDICINE];
    struct ItemSlot berries[NUM_BAG_BERRIES];
    struct ItemSlot balls[NUM_BAG_BALLS];
    struct ItemSlot battleItems[NUM_BAG_BATTLE_ITEMS];
    u32 registeredItem;
};

struct BagView
{
    struct ItemSlot * slots;
    u32 count;
    u8 pocket;
};

struct BagCursor
{
    u8 field_src[8];
    u8 field_pos[8];
    u16 field_pocket;
    u8 filler_12[2];
    u8 battle_src[5];
    u8 battle_pos[5];
    u16 battle_item;
    u16 battle_page;
    u16 battle_pocket;
};

u32 Sav2_Bag_sizeof(void);
struct Bag * Sav2_Bag_new(u32 heap_id);
void Sav2_Bag_init(struct Bag * bag);
void Sav2_Bag_copy(const struct Bag * src, struct Bag * dest);
u32 Bag_GetRegisteredItem(struct Bag * bag);
void Bag_SetRegisteredItem(struct Bag * bag, u32 item);
u32 Bag_GetItemPocket(struct Bag * bag, u16 item_id, struct ItemSlot ** slot_p, u32 * count_p, u32 heap_id);
struct ItemSlot * Pocket_GetItemSlotForAdd(struct ItemSlot * slots, u32 count, u16 item_id, u16 quantity, u16 maxquantity);
struct ItemSlot * Bag_GetItemSlotForAdd(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id);
BOOL Bag_HasSpaceForItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id);
BOOL Bag_AddItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id);
struct ItemSlot * Pocket_GetItemSlotForRemove(struct ItemSlot * slots, u32 count, u16 item_id, u16 quantity);
struct ItemSlot * Bag_GetItemSlotForRemove(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id);
BOOL Bag_TakeItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id);
BOOL Pocket_TakeItem(struct ItemSlot * slots, u32 count, u16 item_id, u16 quantity);
BOOL Bag_HasItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id);
BOOL Bag_PocketNotEmpty(struct Bag * bag, u32 pocket);
u16 Bag_GetQuantity(struct Bag * bag, u16 item_id, u32 heap_id);
u16 Pocket_GetQuantity(struct ItemSlot * slots, u32 count, u16 item_id);
void SwapItemSlots(struct ItemSlot * a, struct ItemSlot * b);
void PocketCompaction(struct ItemSlot * slots, u32 count);
void SortPocket(struct ItemSlot * slots, u32 count);
struct BagView * CreateBagView(struct Bag * bag, const u8 * pockets, u32 heap_id);
struct ItemSlot * Bag_GetPocketSlotN(struct Bag * bag, u32 pocket, u32 slot);
struct Bag * Sav2_Bag_get(struct SaveBlock2 * sav2);
struct BagCursor * BagCursorAlloc(u32 heap_id);
void Bag_GetFieldCursor(struct BagCursor * a0, u32 a1, u8 * a2, u8 * a3);
u16 Bag_GetFieldPocket(struct BagCursor * a0);
void Bag_SetFieldCursor(struct BagCursor * a0, u32 a1, u8 a2, u8 a3);
void Bag_SetFieldPocket(struct BagCursor * a0, u16 a1);
void Bag_GetBattleCursor(struct BagCursor * a0, u32 a1, u8 * a2, u8 * a3);
u16 Bag_GetBattleLastItem(struct BagCursor * a0);
u16 Bag_GetBattleLastPage(struct BagCursor * a0);
u16 Bag_GetBattleLastPocket(struct BagCursor * a0);
void Bag_SetBattleCursor(struct BagCursor * a0, u32 a1, u8 a2, u8 a3);
void Bag_InitBattleCursor(struct BagCursor * a0);
void Bag_SetBattleLastItem(struct BagCursor * a0, u16 a1, u16 a2);
void Bag_SetBattleLastPocket(struct BagCursor * a0, u16 a1);

#endif //POKEDIAMOND_BAG_H
