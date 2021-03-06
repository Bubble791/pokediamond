#include "global.h"
#include "MI_memory.h"
#include "bag.h"
#include "itemtool.h"
#include "heap.h"

#pragma thumb on

u32 Sav2_Bag_sizeof(void)
{
    return sizeof(struct Bag);
}

struct Bag * Sav2_Bag_new(u32 heap_id)
{
    struct Bag * ret = (struct Bag *)AllocFromHeap(heap_id, sizeof(struct Bag));
    Sav2_Bag_init(ret);
    return ret;
}

void Sav2_Bag_init(struct Bag * bag)
{
    MI_CpuClear16(bag, sizeof(struct Bag));
}

void Sav2_Bag_copy(const struct Bag * src, struct Bag * dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Bag));
}

u32 Bag_GetRegisteredItem(struct Bag * bag)
{
    return bag->registeredItem;
}

void Bag_SetRegisteredItem(struct Bag * bag, u32 item)
{
    bag->registeredItem = item;
}

u32 Bag_GetItemPocket(struct Bag * bag, u16 item_id, struct ItemSlot ** slot_p, u32 * count_p, u32 heap_id)
{
    u32 pocket = GetItemAttr(item_id, 5, heap_id);
    switch (pocket)
    {
    case POCKET_KEY_ITEMS:
        *slot_p = bag->keyItems;
        *count_p = NUM_BAG_KEY_ITEMS;
        break;
    case POCKET_ITEMS:
        *slot_p = bag->items;
        *count_p = NUM_BAG_ITEMS;
        break;
    case POCKET_BERRIES:
        *slot_p = bag->berries;
        *count_p = NUM_BAG_BERRIES;
        break;
    case POCKET_MEDICINE:
        *slot_p = bag->medicine;
        *count_p = NUM_BAG_MEDICINE;
        break;
    case POCKET_BALLS:
        *slot_p = bag->balls;
        *count_p = NUM_BAG_BALLS;
        break;
    case POCKET_BATTLE_ITEMS:
        *slot_p = bag->battleItems;
        *count_p = NUM_BAG_BATTLE_ITEMS;
        break;
    case POCKET_MAIL:
        *slot_p = bag->mail;
        *count_p = NUM_BAG_MAIL;
        break;
    case POCKET_TMHMS:
        *slot_p = bag->TMsHMs;
        *count_p = NUM_BAG_TMS_HMS;
        break;
    }
    return pocket;
}

struct ItemSlot * Pocket_GetItemSlotForAdd(struct ItemSlot * slots, u32 count, u16 item_id, u16 quantity, u16 maxquantity)
{
    int i;
    int found = -1;
    for (i = 0; i < count; i++)
    {
        if (slots[i].id == item_id)
        {
            if (quantity + slots[i].quantity > maxquantity)
                return NULL;
            return &slots[i];
        }
        if (found == -1 && slots[i].id == ITEM_NONE && slots[i].quantity == 0)
        {
            found = i;
        }
    }
    if (found == -1)
        return NULL;
    return &slots[found];
}

struct ItemSlot * Bag_GetItemSlotForAdd(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id)
{
    struct ItemSlot * slots;
    u32 count;
    u32 pocket = Bag_GetItemPocket(bag, item_id, &slots, &count, heap_id);
    if (pocket == POCKET_TMHMS)
    {
        return Pocket_GetItemSlotForAdd(slots, count, item_id, quantity, 99);
    }
    else
    {
        return Pocket_GetItemSlotForAdd(slots, count, item_id, quantity, 999);
    }
}

BOOL Bag_HasSpaceForItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id)
{
    return Bag_GetItemSlotForAdd(bag, item_id, quantity, heap_id) != NULL;
}

BOOL Bag_AddItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id)
{
    struct ItemSlot * slots = Bag_GetItemSlotForAdd(bag, item_id, quantity, heap_id);
    if (slots == NULL)
        return FALSE;
    slots->id = item_id;
    slots->quantity += quantity;
    u32 count;
    u32 pocket = Bag_GetItemPocket(bag, item_id, &slots, &count, heap_id);
    if (pocket == POCKET_TMHMS || pocket == POCKET_BERRIES)
    {
        SortPocket(slots, count);
    }
    return TRUE;
}

struct ItemSlot * Pocket_GetItemSlotForRemove(struct ItemSlot * slots, u32 count, u16 item_id, u16 quantity)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (slots[i].id == item_id)
        {
            if (slots[i].quantity >= quantity)
                return &slots[i];
            return NULL;
        }
    }
    return NULL;
}

struct ItemSlot * Bag_GetItemSlotForRemove(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id)
{
    struct ItemSlot * slots;
    u32 count;
    (void)Bag_GetItemPocket(bag, item_id, &slots, &count, heap_id);
    return Pocket_GetItemSlotForRemove(slots, count, item_id, quantity);
}

BOOL Bag_TakeItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id)
{
    struct ItemSlot * slots = Bag_GetItemSlotForRemove(bag, item_id, quantity, heap_id);
    if (slots == NULL)
        return FALSE;
    slots->quantity -= quantity;
    if (slots->quantity == 0)
        slots->id = ITEM_NONE;
    u32 count;
    (void)Bag_GetItemPocket(bag, item_id, &slots, &count, heap_id);
    PocketCompaction(slots, count);
    return TRUE;
}

BOOL Pocket_TakeItem(struct ItemSlot * slots, u32 count, u16 item_id, u16 quantity)
{
    struct ItemSlot * slot = Pocket_GetItemSlotForRemove(slots, count, item_id, quantity);
    if (slot == NULL)
        return FALSE;
    slot->quantity -= quantity;
    if (slot->quantity == 0)
        slot->id = ITEM_NONE;
    PocketCompaction(slots, count);
    return TRUE;
}

BOOL Bag_HasItem(struct Bag * bag, u16 item_id, u16 quantity, u32 heap_id)
{
    return Bag_GetItemSlotForRemove(bag, item_id, quantity, heap_id) != NULL;
}

BOOL Bag_PocketNotEmpty(struct Bag * bag, u32 pocket)
{
    struct ItemSlot * slots;
    u32 count;
    switch (pocket)
    {
    case POCKET_KEY_ITEMS:
        slots = bag->keyItems;
        count = NUM_BAG_KEY_ITEMS;
        break;
    case POCKET_ITEMS:
        slots = bag->items;
        count = NUM_BAG_ITEMS;
        break;
    case POCKET_BERRIES:
        slots = bag->berries;
        count = NUM_BAG_BERRIES;
        break;
    case POCKET_MEDICINE:
        slots = bag->medicine;
        count = NUM_BAG_MEDICINE;
        break;
    case POCKET_BALLS:
        slots = bag->balls;
        count = NUM_BAG_BALLS;
        break;
    case POCKET_BATTLE_ITEMS:
        slots = bag->battleItems;
        count = NUM_BAG_BATTLE_ITEMS;
        break;
    case POCKET_MAIL:
        slots = bag->mail;
        count = NUM_BAG_MAIL;
        break;
    case POCKET_TMHMS:
        slots = bag->TMsHMs;
        count = NUM_BAG_TMS_HMS;
        break;
    default:
        return FALSE;
    }
    int i;
    for (i = 0; i < count; i++)
    {
        if (slots[i].id != ITEM_NONE)
            return TRUE;
    }
    return FALSE;
}

u16 Bag_GetQuantity(struct Bag * bag, u16 item_id, u32 heap_id)
{
    struct ItemSlot * slot = Bag_GetItemSlotForRemove(bag, item_id, 1, heap_id);
    if (slot == NULL)
        return 0;
    return slot->quantity;
}

u16 Pocket_GetQuantity(struct ItemSlot * slots, u32 count, u16 item_id)
{
    struct ItemSlot * slot = Pocket_GetItemSlotForRemove(slots, count, item_id, 1);
    if (slot == NULL)
        return 0;
    return slot->quantity;
}

void SwapItemSlots(struct ItemSlot * a, struct ItemSlot * b)
{
    struct ItemSlot tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void PocketCompaction(struct ItemSlot * slots, u32 count)
{
    int i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (slots[i].quantity == 0)
            {
                SwapItemSlots(&slots[i], &slots[j]);
            }
        }
    }
}

void SortPocket(struct ItemSlot * slots, u32 count)
{
    int i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (slots[i].quantity == 0 || (slots[j].quantity != 0 && slots[i].id > slots[j].id))
            {
                SwapItemSlots(&slots[i], &slots[j]);
            }
        }
    }
}

extern struct BagView * BagView_new(u8 heap_id);
extern void BagView_setitem(struct BagView * view, struct ItemSlot * slot, u8 pocket, u8 idx);

struct BagView * CreateBagView(struct Bag * bag, const u8 * pockets, u32 heap_id)
{
    struct BagView * view = BagView_new((u8)heap_id);
    int i;
    for (i = 0; pockets[i] != 0xFF; i++)
    {
        switch (pockets[i])
        {
        case POCKET_KEY_ITEMS:
            BagView_setitem(view, bag->keyItems, POCKET_KEY_ITEMS, (u8)i);
            break;
        case POCKET_ITEMS:
            BagView_setitem(view, bag->items, POCKET_ITEMS, (u8)i);
            break;
        case POCKET_BERRIES:
            BagView_setitem(view, bag->berries, POCKET_BERRIES, (u8)i);
            break;
        case POCKET_MEDICINE:
            BagView_setitem(view, bag->medicine, POCKET_MEDICINE, (u8)i);
            break;
        case POCKET_BALLS:
            BagView_setitem(view, bag->balls, POCKET_BALLS, (u8)i);
            break;
        case POCKET_BATTLE_ITEMS:
            BagView_setitem(view, bag->battleItems, POCKET_BATTLE_ITEMS, (u8)i);
            break;
        case POCKET_MAIL:
            BagView_setitem(view, bag->mail, POCKET_MAIL, (u8)i);
            break;
        case POCKET_TMHMS:
            BagView_setitem(view, bag->TMsHMs, POCKET_TMHMS, (u8)i);
            break;
        }
    }
    return view;
}

struct ItemSlot * Bag_GetPocketSlotN(struct Bag * bag, u32 pocket, u32 slot)
{
    struct ItemSlot * slots;
    u32 count;
    switch (pocket)
    {
    case POCKET_KEY_ITEMS:
        slots = bag->keyItems;
        count = NUM_BAG_KEY_ITEMS;
        break;
    case POCKET_ITEMS:
        slots = bag->items;
        count = NUM_BAG_ITEMS;
        break;
    case POCKET_BERRIES:
        slots = bag->berries;
        count = NUM_BAG_BERRIES;
        break;
    case POCKET_MEDICINE:
        slots = bag->medicine;
        count = NUM_BAG_MEDICINE;
        break;
    case POCKET_BALLS:
        slots = bag->balls;
        count = NUM_BAG_BALLS;
        break;
    case POCKET_BATTLE_ITEMS:
        slots = bag->battleItems;
        count = NUM_BAG_BATTLE_ITEMS;
        break;
    case POCKET_MAIL:
        slots = bag->mail;
        count = NUM_BAG_MAIL;
        break;
    case POCKET_TMHMS:
        slots = bag->TMsHMs;
        count = NUM_BAG_TMS_HMS;
        break;
    }
    if (slot >= count)
        return NULL;
    return &slots[slot];
}

struct Bag * Sav2_Bag_get(struct SaveBlock2 * sav2)
{
    return (struct Bag *)SavArray_get(sav2, 3);
}

struct BagCursor * BagCursorAlloc(u32 heap_id)
{
    struct BagCursor * ret = (struct BagCursor *)AllocFromHeap(heap_id, sizeof(struct BagCursor));
    MI_CpuClear16(ret, sizeof(struct BagCursor));
    return ret;
}

void Bag_GetFieldCursor(struct BagCursor * a0, u32 a1, u8 * a2, u8 * a3)
{
    *a2 = a0->field_pos[a1];
    *a3 = a0->field_src[a1];
}

u16 Bag_GetFieldPocket(struct BagCursor * a0)
{
    return a0->field_pocket;
}

void Bag_SetFieldCursor(struct BagCursor * a0, u32 a1, u8 a2, u8 a3)
{
    a0->field_pos[a1] = a2;
    a0->field_src[a1] = a3;
}

void Bag_SetFieldPocket(struct BagCursor * a0, u16 a1)
{
    a0->field_pocket = a1;
}

void Bag_GetBattleCursor(struct BagCursor * a0, u32 a1, u8 * a2, u8 * a3)
{
    *a2 = a0->battle_pos[a1];
    *a3 = a0->battle_src[a1];
}

u16 Bag_GetBattleLastItem(struct BagCursor * a0)
{
    return a0->battle_item;
}

u16 Bag_GetBattleLastPage(struct BagCursor * a0)
{
    return a0->battle_page;
}

u16 Bag_GetBattleLastPocket(struct BagCursor * a0)
{
    return a0->battle_pocket;
}

void Bag_SetBattleCursor(struct BagCursor * a0, u32 a1, u8 a2, u8 a3)
{
    a0->battle_pos[a1] = a2;
    a0->battle_src[a1] = a3;
}

void Bag_InitBattleCursor(struct BagCursor * a0)
{
    u32 i;
    for (i = 0; i < 5; i++)
    {
        Bag_SetBattleCursor(a0, i, 0, 0);
    }
    Bag_SetBattleLastPocket(a0, 0);
}

void Bag_SetBattleLastItem(struct BagCursor * a0, u16 a1, u16 a2)
{
    a0->battle_item = a1;
    a0->battle_page = a2;
}

void Bag_SetBattleLastPocket(struct BagCursor * a0, u16 a1)
{
    a0->battle_pocket = a1;
}
