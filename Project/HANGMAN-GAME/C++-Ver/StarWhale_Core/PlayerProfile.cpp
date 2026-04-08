/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Data & State
Purpose: Implements the PlayerProfile class logic and state encapsulation.
Filename: PlayerProfile.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add Function Implementations
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "PlayerProfile.h"

PlayerProfile::PlayerProfile(const char* playerName)
    : m_name(nullptr), m_starPieces(0), m_bridgeEnergy(6),
    m_inventory(nullptr), m_skillCount(0), m_maxSkills(5) {

    const char* safeName = (playerName && playerName[0] != '\0') ? playerName : "Player";
    m_name = new char[std::strlen(safeName) + 1];
    std::strcpy(m_name, safeName);

    m_inventory = new SkillSlot[m_maxSkills];
    for (int i = 0; i < m_maxSkills; i++) {
        m_inventory[i].m_skillPtr = nullptr;
    }
}

PlayerProfile::~PlayerProfile() {
    cleanup();
}

void PlayerProfile::cleanup() {
    delete[] m_name;
    m_name = nullptr;

    if (m_inventory) {
        for (int i = 0; i < m_skillCount; i++) {
            delete m_inventory[i].m_skillPtr;
            m_inventory[i].m_skillPtr = nullptr;
        }
        delete[] m_inventory;
    }

    m_inventory = nullptr;
    m_skillCount = 0;
}

const char* PlayerProfile::getName() const {
    return m_name ? m_name : "";
}

int PlayerProfile::getStarPieces() const {
    return m_starPieces;
}

int PlayerProfile::getBridgeEnergy() const {
    return m_bridgeEnergy;
}

void PlayerProfile::addStarPiece(int amount) {
    if (amount > 0) {
        m_starPieces += amount;
    }
}

void PlayerProfile::decreaseEnergy() {
    if (m_bridgeEnergy > 0) {
        m_bridgeEnergy--;
    }
}

void PlayerProfile::healEnergy(int amount) {
    if (amount <= 0) return;

    m_bridgeEnergy += amount;
    if (m_bridgeEnergy > 6) {
        m_bridgeEnergy = 6;
    }
}

void PlayerProfile::useEnergy(int amount) {
    if (amount <= 0) return;

    if (amount >= m_bridgeEnergy) {
        m_bridgeEnergy = 0;
    }
    else {
        m_bridgeEnergy -= amount;
    }
}

bool PlayerProfile::isAlive() const {
    return m_bridgeEnergy > 0;
}

void PlayerProfile::addSkill(ISkill* newSkill) {
    if (!newSkill) return;

    if (m_skillCount < m_maxSkills) {
        m_inventory[m_skillCount].m_skillPtr = newSkill;
        m_skillCount++;
    }
    else {
        // Prevent leak when inventory is full
        delete newSkill;
    }
}

int PlayerProfile::getSkillCount() const {
    return m_skillCount;
}

ISkill* PlayerProfile::getSkill(int index) const {
    if (index < 0 || index >= m_skillCount) return nullptr;
    return m_inventory[index].m_skillPtr;
}