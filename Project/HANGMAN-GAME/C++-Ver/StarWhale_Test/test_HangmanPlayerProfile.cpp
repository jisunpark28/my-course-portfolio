/* Citation and Sources...
Hangman C++ Version: Star Whale
Module: Test
Purpose: PlayerProfile unit/integration/acceptance tests using MSVC framework.
Filename: test_HangmanPlayerProfile.cpp
Version 0.2
Author: Jisun Park, Email: jisunpark28@gmail.com
Revision History
-----------------------------------------------------------
Date        Reason
2026/04/07  Initial File
2026/04/07  Add PlayerProfile Module Unit Test Cases
-----------------------------------------------------------*/

#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <memory>
#include "HangmanPlayerProfile.h"
#include "IHangmanSkill.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// [Mock Object] Dummy skill for Integration Testing
class DummySkill : public ISkill {
public:
    std::string getName() const override { return "Dummy"; }
    void use(PlayerProfile& player) override { /* Do nothing for test */ }
};

namespace BlackBoxTests
{
    // ID           Description                     Steps                                   Test Data                       Expected Result
    // 
    // BT_PRF001    Valid initialization            Initialize with "Jisun"                 PlayerName: "Jisun"             Return: Name "Jisun", Score 0, HP 6
    // BT_PRF002    Score increment                 Add 10 star pieces                      Amount: 10                      Return: Score 10
    // BT_PRF003    Energy decrease                 Decrease energy twice                   Current HP: 6 -> 4              Return: HP 4, Alive: true
    TEST_CLASS(PlayerProfileBlackBox)
    {
    public:
        TEST_METHOD(BT_PRF001)
        {
            PlayerProfile player("Jisun");  // 1. Initialize a PlayerProfile.
            Assert::AreEqual(std::string("Jisun"), player.getName());   // 2. Verify all initial values using getters.
            Assert::AreEqual(0, player.getStarPieces());
            Assert::AreEqual(6, player.getBridgeEnergy());
            Assert::IsTrue(player.isAlive());
        }
        TEST_METHOD(BT_PRF002)
        {
            PlayerProfile player("Jisun");  // 1. Initialize a PlayerProfile.
            player.addStarPiece(10);    // 2. Call addStarPiece with 10.
            Assert::AreEqual(10, player.getStarPieces());   // 3. Verify the score is updated correctly.
        }
        TEST_METHOD(BT_PRF003)
        {
            PlayerProfile player("Jisun");  // 1. Initialize a PlayerProfile (HP 6).
            player.decreaseEnergy();    // 2. Call decreaseEnergy twice.
            player.decreaseEnergy();
            Assert::AreEqual(4, player.getBridgeEnergy());  // 3. Verify HP drops to 4.
            Assert::IsTrue(player.isAlive());
        }
    };
}

namespace WhiteBoxTests
{
    // ID           Description                     Steps                                   Test Data                       Expected Result
    // 
    // WT_PRF001    Max HP limit boundary           Decrease by 1, heal by 10               Amount: 10                      Return: HP capped at 6
    // WT_PRF002    Min HP limit boundary           Decrease energy 10 times                N/A                             Return: HP capped at 0, Alive: false
    TEST_CLASS(PlayerProfileWhiteBox)
    {
    public:
        TEST_METHOD(WT_PRF001)
        {
            PlayerProfile player("Jisun");  // 1. Initialize a PlayerProfile.
            player.decreaseEnergy();    // 2. Call decreaseEnergy to drop HP to 5.
            player.healEnergy(10);  // 3. Call healEnergy with a large number (10) that exceeds max HP limit.
            Assert::AreEqual(6, player.getBridgeEnergy());  // 4. Verify HP is capped at 6.
        }
        TEST_METHOD(WT_PRF002)
        {
            PlayerProfile player("Jisun");  // 1. Initialize a PlayerProfile.
            for (int i = 0; i < 10; i++) {  // 2. Loop decreaseEnergy 10 times to force HP below 0.
                player.decreaseEnergy();
            }
            Assert::AreEqual(0, player.getBridgeEnergy());  // 3. Verify HP does not go negative and player is marked dead.
            Assert::IsFalse(player.isAlive());
        }
    };
}

namespace IntegrationTests
{
    // ID           Description                     Steps                                   Test Data                       Expected Result
    // 
    // IT_PRF001    Inventory System Integration    Add DummySkill via unique_ptr           Mock Object: DummySkill         Return: Success (No memory leak/crash)
    TEST_CLASS(PlayerProfileIntegration)
    {
    public:
        TEST_METHOD(IT_PRF001)
        {
            PlayerProfile player("Jisun");  // 1. Initialize a PlayerProfile.
            player.addSkill(std::make_unique<DummySkill>());    // 2. Create a Mock DummySkill.
            // 3. Call addSkill transferring ownership via std::move / make_unique.
            // Reaching this point without exception implies successful integration of the pointer
            Assert::IsTrue(true);   // 4. Verify system accepts the object without crashing.

            //template<typename T>
            //unique_ptr<T> make_unique() {     // <memory> - make_unique() : Dynamically allocated, automatically deallocated.
            //    return unique_ptr<T>(new T()); 
            //}
        }
    };
}

namespace AcceptanceTests
{
    // ID           Description                     Steps                                   Test Data                       Expected Result
    // 
    // ACPT_P001    Full Player Lifecycle Logic     Init -> Score -> Dmg -> Heal -> Die     Various inputs                  Final state matches business rules
    TEST_CLASS(PlayerProfileAcceptance)
    {
    public:
        TEST_METHOD(ACPT_P001)
        {
            PlayerProfile player("Jisun");
            player.addStarPiece(5);        // Score: 5   1. Simulate a full player flow based on business requirements.
            player.decreaseEnergy();       // HP: 5
            player.decreaseEnergy();       // HP: 4
            player.healEnergy(1);          // HP: 5
            for (int i = 0; i < 5; i++) {   // Fatal damage scenario
                player.decreaseEnergy();
            } // HP: 0
            Assert::AreEqual(5, player.getStarPieces());    // 2. Verify final state.
            Assert::AreEqual(0, player.getBridgeEnergy());
            Assert::IsFalse(player.isAlive());
        }
    };
}