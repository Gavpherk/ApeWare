#include "MemPatch.h"
#include <iostream>

// Default constructor
MemPatch::MemPatch()
    : address(0), byteSignature(nullptr), size(0), originalBytes(nullptr) {}

// Parameterized constructor
MemPatch::MemPatch(uintptr_t addr, const char* signature, int patchSize)
    : address(addr), byteSignature(signature), size(patchSize), originalBytes(nullptr) {}

// Copy constructor
MemPatch::MemPatch(const MemPatch& other)
    : address(other.address), byteSignature(other.byteSignature), size(other.size), originalBytes(nullptr) {
    if (other.originalBytes != nullptr) {
        originalBytes = new BYTE[size];
        memcpy(originalBytes, other.originalBytes, size);
    }
}

// Assignment operator
MemPatch& MemPatch::operator=(const MemPatch& other) {
    if (this != &other) { // Avoid self-assignment
        // Cleanup existing resources
        delete[] originalBytes;

        // Copy data from the other object
        address = other.address;
        byteSignature = other.byteSignature;
        size = other.size;

        // Allocate and copy originalBytes
        if (other.originalBytes != nullptr) {
            originalBytes = new BYTE[size];
            memcpy(originalBytes, other.originalBytes, size);
        } else {
            originalBytes = nullptr;
        }
    }
    return *this;
}

// Destructor
MemPatch::~MemPatch() {
    delete[] originalBytes;
}