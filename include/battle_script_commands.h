#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#include "constants/pokemon.h"

#define WINDOW_CLEAR            0x1
#define WINDOW_x80              0x80

s32 CalcCritChanceStage(u8 battlerAtk, u8 battlerDef, u32 move, bool32 recordAbility);
u32 GetTotalAccuracy(u32 battlerAtk, u32 battlerDef, u32 move);
u8 GetBattlerTurnOrderNum(u8 battlerId);
bool32 NoAliveMonsForEitherParty(void);
void SetMoveEffect(bool32 primary, u32 certain);
bool32 CanBattlerSwitch(u32 battlerId);
void BattleDestroyYesNoCursorAt(u8 cursorPosition);
void BattleCreateYesNoCursorAt(u8 cursorPosition);
void BufferMoveToLearnIntoBattleTextBuff2(void);
void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
bool8 UproarWakeUpCheck(u8 battlerId);
bool32 DoesSubstituteBlockMove(u8 battlerAtk, u8 battlerDef, u32 move);
bool32 DoesDisguiseBlockMove(u8 battlerAtk, u8 battlerDef, u32 move);
bool32 CanPoisonType(u8 battlerAttacker, u8 battlerTarget);
bool32 CanParalyzeType(u8 battlerAttacker, u8 battlerTarget);
bool32 CanUseLastResort(u8 battlerId);
u32 IsFlowerVeilProtected(u32 battler);
u32 IsLeafGuardProtected(u32 battler);
bool32 IsShieldsDownProtected(u32 battler);
u32 IsAbilityStatusProtected(u32 battler);
struct Party GetBattlerParty(u32 battlerId, bool32 checkDoubles);
bool32 AnyDragonFainted(u32 battlerId);
bool32 AnyOtherAlive(u32 battlerId);
void StealTargetItem(u8 battlerStealer, u8 battlerItem);

extern void (* const gBattleScriptingCommandsTable[])(void);
extern const u8 gBattlePalaceNatureToMoveGroupLikelihood[NUM_NATURES][4];

struct Party
{
    struct Pokemon *mons;
    u8 maxSize;
};

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H
