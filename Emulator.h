// Emulator.h

#pragma once

#include "main.h"
#include "emubase/Board.h"

//////////////////////////////////////////////////////////////////////


extern CMotherboard* g_pBoard;
extern BKConfiguration g_nEmulatorConfiguration;  // Current configuration
extern bool g_okEmulatorRunning;

extern quint8* g_pEmulatorRam;  // RAM values - for change tracking
extern quint8* g_pEmulatorChangedRam;  // RAM change flags
extern quint16 g_wEmulatorCpuPC;      // Current PC value
extern quint16 g_wEmulatorPrevCpuPC;  // Previous PC value
extern quint16 g_wEmulatorPpuPC;      // Current PC value
extern quint16 g_wEmulatorPrevPpuPC;  // Previous PC value


//////////////////////////////////////////////////////////////////////


bool Emulator_Init();
bool Emulator_InitConfiguration(BKConfiguration configuration);
void Emulator_Done();
void Emulator_SetCPUBreakpoint(quint16 address);
bool Emulator_IsBreakpoint();
//void Emulator_SetSound(bool soundOnOff);
//void Emulator_SetCovox(bool covoxOnOff);
void Emulator_Start();
void Emulator_Stop();
void Emulator_Reset();
int Emulator_SystemFrame();
float Emulator_GetUptime();  // BK uptime, in seconds

void Emulator_GetScreenSize(int scrmode, int* pwid, int* phei);
void Emulator_PrepareScreenRGB32(void* pBits, int screenMode);

void Emulator_KeyEvent(quint8 keyPressed, bool pressed, bool ctrl);
quint16 Emulator_GetKeyEventFromQueue();
void Emulator_ProcessKeyEvent();

// Update cached values after Run or Step
void Emulator_OnUpdate();
quint16 Emulator_GetChangeRamStatus(quint16 address);

bool Emulator_SaveImage(const QString &sFilePath);
bool Emulator_LoadImage(const QString &sFilePath);


//////////////////////////////////////////////////////////////////////
