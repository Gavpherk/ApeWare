// MemPatch.h

#ifndef MEMPATCH_H
#define MEMPATCH_H

#include <Windows.h>

class MemPatch {
private:
    uintptr_t address;
    const char* byteSignature;
    int size;
    BYTE* originalBytes;

public:
    MemPatch();
    MemPatch(uintptr_t addr, const char* signature, int patchSize);
    MemPatch(const MemPatch& other); // Copy constructor
    MemPatch& operator=(const MemPatch& other); // Assignment operator
    ~MemPatch();

    bool Activate();
    bool Deactivate();

private:
    bool ReadMemory(BYTE* buffer, int size);
    bool WriteMemory(const void* data, int size);
};

#endif // MEMPATCH_H

/*
MemPatch UnlimitedJumpsPatch;
MemPatch UnlimitedJumpsPatch2;

MemPatch pUnlimitedJumpsPatch((uintptr_t)Globals::Game::CallFunction::oDoJump + 0x6A, "\x90\x90\x90\x90", 4);
MemPatch pUnlimitedJumpsPatch2((uintptr_t)Globals::Game::CallFunction::oDoJump + 0x78, "\x90\x90\x90\x90", 4);

UnlimitedJumpsPatch = pUnlimitedJumpsPatch;
UnlimitedJumpsPatch2 = pUnlimitedJumpsPatch2;
*/