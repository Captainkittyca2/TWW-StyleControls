/**
 * @file main.cpp
 * @author Captain Kitty Cat (youtube.com/@captainkittyca2)
 * @brief Features several mechanics from Skyward Sword.
 * @version 0.5.3
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <display/console.h>     // Contains a very neat helper class to print to the console
#include <main.h>
#include <patch.h>     // Contains code for hooking into a function
#include <cstdio>
#include <tp/d_meter2.h>
#include <tp/d_meter_HIO.h>
#include <tp/d_com_inf_game.h>
#include <tp/m_do_audio.h>
#include <tp/d_menu_window.h>
#include <tp/JFWSystem.h>
#include <tp/processor.h>
#include <tp/JKRArchivePub.h>
#include <string.h>
#include <tp/d_meter2_info.h>
#include <tp/d_bomb.h>
#include <tp/d_item.h>
#include <tp/f_op_actor_iter.h>
#include <JSystem/JMath/JMATrigonometric.h>
#include <tools.h>

#ifdef PLATFORM_WII
#include <tp/m_re_controller_pad.h>
#else
#include <tp/m_do_controller_pad.h>
#endif

namespace mod
{
    Mod* gMod = nullptr;

    void main()
    {
        Mod* mod = new Mod();
        mod->init();
    }

    void exit() {}

    Mod::Mod(): c( 0 )
    {
    }
    bool shieldAttack = false;
    uint32_t oxygenVisible = reinterpret_cast<uint32_t>(libtp::tp::d_meter2::alphaAnimeOxygen);
    uint32_t greenClothesSwim1 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setWaterInAnmRate);
    uint32_t greenClothesSwim2 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::getSwimFrontMaxSpeed);
    uint32_t greenClothesSwim3 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::checkNextActionSwim);
    uint32_t greenClothesSwim4 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setSwimMoveAnime);
    //uint32_t guardAttackPrepare1 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procGuardAttackInit);
    //uint32_t guardAttackPrepare2 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procGuardAttack);
    //uint32_t fightingStance = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setBlendAtnMoveAnime);
    //uint32_t fightingStance2 =reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setBlendMoveAnime);
    uint32_t linkExecute = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::execute_);
    libtp::tp::jfw_system::SystemConsole* sysConsolePtr = libtp::tp::jfw_system::systemConsole;

    template <typename T>
    inline T cLib_minMaxLimit(T val, T min, T max) {
        T ret;
        T var_r30;

        if (val < min) {
            ret = min;
        } else {
            if (val > max) {
                var_r30 = max;
            } else {
                var_r30 = val;
            }

            ret = var_r30;
        }

        return (T)ret;
    }

    // Saved mod info
    struct saveInfo
    {
        /* 0x00 */ uint8_t woodShieldDurability;
        /* 0x01 */ uint8_t hylianShieldDurability;
        /* 0x02 */ uint8_t zoraArmorAcquired;
        /* 0x03 */ uint8_t padding1;
        /* 0x04 */ uint16_t objectStored;
        /* 0x06 */ uint16_t padding2;
        /* 0x08 */ uint32_t objectParams;
        uint8_t unk[68];
    } __attribute__((__packed__));

    saveInfo* saveInfoPtr = reinterpret_cast<saveInfo*>(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.reserve);

#if defined(TP_WUS2) || defined(TP_WJP)
    uint16_t shieldBurn1 = 0x1888;
    uint32_t shieldBurn1Vanilla = 0x3863ffff;
    uint32_t shieldBurn2Vanilla = 0x5460063f;
    uint16_t shieldBurn1Jump = 0x194C;
    //uint8_t tiredinitial = 0x5C;
    //uint32_t tiredinitialVanilla = 0x2c1f0001;
    float xPosition = libtp::tp::d_meter_hio::g_drawHIO.mLanternMeterPosX;
#else
    uint16_t shieldBurn1 = 0x1974;
    uint32_t shieldBurn1Vanilla = 0x3803FFFF;
    uint32_t shieldBurn2Vanilla = 0x981F2FCB;
    uint16_t shieldBurn1Jump = 0x1A1C;
    //uint8_t tiredinitial = 0x6C;
    //uint32_t tiredinitialVanilla = 0x2c1e0001;
    float xPosition = 8.0f;
#endif
    // Makes Link go into fighter stance
    /*void LTargetFighterMode(bool onOff) {
        if (onOff) {
            libtp::patch::writeBranch(fightingStance + 0x10C, fightingStance + 0x168);
            libtp::patch::writeBranch(fightingStance + 0x1A0, fightingStance + 0x1A4);
            libtp::patch::writeBranch(fightingStance + 0x1C8, fightingStance + 0x1DC);
            libtp::patch::writeBranch(fightingStance + 0x33C, fightingStance + 0x340);
            libtp::patch::writeBranch(fightingStance + 0x518, fightingStance + 0x51C);
            libtp::patch::writeBranch(fightingStance + 0x530, fightingStance + 0x534);
            libtp::patch::writeBranch(fightingStance + 0x490, fightingStance + 0x494);
            libtp::patch::writeBranch(fightingStance + 0x4B0, fightingStance + 0x4B4);
            libtp::patch::writeBranch(fightingStance + 0x3B8, fightingStance + 0x3BC);
            libtp::patch::writeBranch(fightingStance + 0x3D4, fightingStance + 0x3D8);
            libtp::patch::writeBranch(fightingStance + 0x594, fightingStance + 0x598);
            libtp::patch::writeBranch(fightingStance2 + 0x5F4, fightingStance2 + 0x5F8);
            libtp::patch::writeBranch(fightingStance2 + 0x5D4, fightingStance2 + 0x5D8);
            libtp::patch::writeBranch(fightingStance2 + 0x60C, fightingStance2 + 0x610);
        }
        else {
            *reinterpret_cast<uint32_t*>(fightingStance + 0x10C) = 0x4082005c;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x1A0) = 0x41820014;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x1C8) = 0x41820020;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x33C) = 0x41820024;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x518) = 0x4182000c;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x530) = 0x4182000c;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x490) = 0x41820010;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x3B8) = 0x4182000c;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x3D4) = 0x4182000c;
            *reinterpret_cast<uint32_t*>(fightingStance + 0x594) = 0x41820010;
            *reinterpret_cast<uint32_t*>(fightingStance2 + 0x5F4) = 0x4182000c;
            *reinterpret_cast<uint32_t*>(fightingStance2 + 0x5D4) = 0x4182000c;
            *reinterpret_cast<uint32_t*>(fightingStance2 + 0x60C) = 0x41820014;
        }
    }*/

    bool guardBattleAuthorized = false;

    void commenceGuardAttack(bool start) {
        guardBattleAuthorized = true;
        if (start) {
            libtp::tp::d_a_alink::guardVars.mAttackPosOffset = 80.0f;
            //libtp::patch::writeBranch(guardAttackPrepare1 + 0x8C, guardAttackPrepare1 + 0x94);
            //libtp::patch::writeBranch(guardAttackPrepare1 + 0x134, guardAttackPrepare1 + 0x160);
            //libtp::patch::writeBranch(guardAttackPrepare2 + 0xAC, guardAttackPrepare2 + 0x16C);
            //*reinterpret_cast<uint32_t*>(guardAttackPrepare2 + 0xC4) = 0x38000000;
            //*reinterpret_cast<uint32_t*>(guardAttackPrepare2 + 0x88) = 0x3ba00000;
            return;
        }
        libtp::tp::d_a_alink::guardVars.mAttackPosOffset = 2000.0f;
    }

    // Allows Link to swim with green clothes if Zora Armor is obtained
    void zoraArmorObtained(bool obtained) {
        if (obtained) {
            *reinterpret_cast<uint32_t*>(greenClothesSwim1 + 0x30) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim2 + 0x44) = 0x2c030001;
#ifdef PLATFORM_WII
            *reinterpret_cast<uint32_t*>(greenClothesSwim3 + 0x6C) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x284) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x3E8) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x448) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x6E0) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x810) = 0x2c030001;
#else
            *reinterpret_cast<uint32_t*>(greenClothesSwim3 + 0x40) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x280) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x3FC) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x464) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x6F4) = 0x2c030001;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x818) = 0x2c030001;
#endif

        }
        else {
            *reinterpret_cast<uint32_t*>(greenClothesSwim1 + 0x30) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim2 + 0x44) = 0x2c030000;
#ifdef PLATFORM_WII
            *reinterpret_cast<uint32_t*>(greenClothesSwim3 + 0x6C) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x284) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x3E8) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x448) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x6E0) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x810) = 0x2c030000;
#else
            *reinterpret_cast<uint32_t*>(greenClothesSwim3 + 0x40) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x280) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x3FC) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x464) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x6F4) = 0x2c030000;
            *reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x818) = 0x2c030000;
#endif
        }
    }

    uint8_t shieldWoodHealth = 255;
    uint8_t shieldHylianHealth = 255;
    uint8_t lastShield;

    // Shield durability. Returns false if shield breaks
    bool shieldDurability(uint8_t shieldType, bool strongAttack) {
        if (shieldAttack == false) return false;
        uint8_t attackPlus = 0;
        if (strongAttack) attackPlus = 30;
        if (shieldType == 2) {
            if (shieldHylianHealth - (50 + attackPlus) < 0) shieldHylianHealth = 0;
            else shieldHylianHealth -= (50 + attackPlus);
        } else if (shieldType == 0) {
            if (shieldWoodHealth - (80 + attackPlus) < 0) shieldWoodHealth = 0;
            else shieldWoodHealth -= (80 + attackPlus);
        } else {
            if (shieldWoodHealth - (100 + attackPlus) < 0) shieldWoodHealth = 0;
            else shieldWoodHealth -= (100 + attackPlus);
        }

        if (shieldWoodHealth == 0 || shieldHylianHealth == 0) {
            if (shieldHylianHealth == 0) {
                shieldHylianHealth = 255;
                saveInfoPtr->hylianShieldDurability = shieldHylianHealth;
            }
            else {
                shieldWoodHealth = 255;
                *reinterpret_cast<uint32_t*>(linkExecute + shieldBurn1) = shieldBurn1Vanilla;
                *reinterpret_cast<uint32_t*>(linkExecute + shieldBurn1+4) = shieldBurn2Vanilla;
                saveInfoPtr->woodShieldDurability = shieldWoodHealth;
            }
            libtp::tp::d_meter2_info::dMeter2Info_setShield(0xff, true);
            lastShield = 0xfe;
            libtp::tp::d_a_alink::dMeter2Info_setFloatingMessage(2047, 90, true);
            libtp::tp::m_Do_Audio::mDoAud_seStart(0x80095, 0, 0, 0);
            return false;
        }

        saveInfoPtr->woodShieldDurability = shieldWoodHealth;
        saveInfoPtr->hylianShieldDurability = shieldHylianHealth;
        return true;
    }

    uint8_t timeMove = 0;
    uint8_t timeMoveStart = false;
    uint8_t armorTimer = 10;

    // How much stamina to consume. Stamina consumption varies depending on the sword used. Also rupees are consumed when wearing a particular armor
    void staminaConsumption(uint16_t staminaVal, bool swordAttack, bool armorThing) {
        if (swordAttack) {
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[1] == 0x3F) {
                staminaVal *= 1.75;
            } else if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[1] == 0x28) {
                staminaVal *= 1.25;
            }
        }
#ifdef PLATFORM_WII
        if (libtp::tp::d_a_alink::checkMagicArmorWearAbility(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer) && !libtp::tp::d_a_alink::checkMagicArmorHeavy(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer))
#else
        if (libtp::tp::d_a_alink::checkMagicArmorNoDamage(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer))
#endif
        {
            if (armorThing) {
                armorTimer--;
                if (armorTimer == 0) {
                    armorTimer = 10;
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees - staminaVal < 0) libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees = 0;
                    else libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees -= staminaVal;
                }
            } else {
                if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees - (staminaVal/5) < 0) libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees = 0;
                else libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees -= (staminaVal/5);
            }
            return;
        }
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen < 151 && staminaVal > 1) staminaVal *= 0.5;
        libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen -= staminaVal;
        timeMove = 30;
        timeMoveStart = true;
    }

    // How many insects collected
    bool isItEnough(uint8_t shieldTypeee) {
        if (shieldTypeee == 0 || shieldTypeee == 1) {
            sprintf(sysConsolePtr->consoleLine[14].line, "Required bugs: %d", 6 + (shieldTypeee*6));
            return false;
        } else if (shieldTypeee == 0xff) {strcpy(sysConsolePtr->consoleLine[14].line, ""); return false;}
        uint8_t countCountCOUNT = 0;
        for (uint8_t bugCounting = 0; bugCounting < 24; bugCounting++) {
            if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(bugCounting + 192)) countCountCOUNT++;
        }
        if (shieldTypeee == 2 && countCountCOUNT >= 12) return true;
        else if (shieldTypeee == 3 && countCountCOUNT >= 6) return true;
        else if (shieldTypeee == 4) sprintf(sysConsolePtr->consoleLine[15].line, "Current bugs: %d", countCountCOUNT);
        return false;
    }

    uint8_t soundPadding = 0;

    void tiredSounds(uint8_t soundType) {
        soundPadding++;
        if (soundType == 2) {
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > 150) {
                if (soundPadding >= 25) {
                    soundPadding = 0;
                    libtp::tp::m_Do_Audio::mDoAud_seStart(0x10014, 0, 0, 0);
                }
            } else if (soundPadding >= 15) {
                soundPadding = 0;
                libtp::tp::m_Do_Audio::mDoAud_seStart(0x10014, 0, 0, 0);
            }
        } else if (soundType == 1) {
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > 150) {
                if (soundPadding >= 30) {
                    soundPadding = 0;
                    libtp::tp::m_Do_Audio::mDoAud_seStart(0x10015, 0, 0, 0);
                }
            } else if (soundPadding >= 15) {
                soundPadding = 0;
                libtp::tp::m_Do_Audio::mDoAud_seStart(0x10015, 0, 0, 0);
            }
        } else if (soundType == 0) {
            if (soundPadding >= 30) {
                    libtp::tp::m_Do_Audio::mDoAud_seStart(0x10014, 0, 0, 0);
                    soundPadding = 0;
                }
        } else {
            if (soundPadding >= 30) {
                libtp::tp::m_Do_Audio::mDoAud_seStart(0x10015, 0, 0, 0);
                soundPadding = 0;
            }
        }
    }

    libtp::tp::d_a_alink::ClimbVars* ClimbVaars = &libtp::tp::d_a_alink::climbVars;
    libtp::tp::d_a_alink::WallMoveVars* WallMooveVars = &libtp::tp::d_a_alink::wallMoveVars;
    libtp::tp::d_a_alink::daAlinkHIO_crouch_c0* crawlAdjustments = &libtp::tp::d_a_alink::crouchVars;
    float ladderClimbSpeedInitialized;
    float ladderReachTopClimb;
    float ladderTopStartClimb;
    float ladderBottomGetSpeed;
    float ladderClimbb;
    float wallHorizontalSpeed;
    float wallVerticalSpeed;
    float sidewaysStickNo;
    float sidewaysStickYes;
    float crawlRated;
    void climbRegularSpeed() {
        ladderClimbSpeedInitialized = ClimbVaars->ladderClimbInitSpeed;
        ladderReachTopClimb = ClimbVaars->ladderReachTopClimbUpSpeed;
        ladderTopStartClimb = ClimbVaars->ladderTopStartClimbDownSpeed;
        ladderBottomGetSpeed = ClimbVaars->ladderBottomGetOffSpeed;
        ladderClimbb = ClimbVaars->ladderClimbSpeed;
        wallHorizontalSpeed = ClimbVaars->wallClimbHorizontalSpeed;
        wallVerticalSpeed = ClimbVaars->wallClimbVerticalSpeed;
        sidewaysStickNo = WallMooveVars->moveSidewaysStickNotHeld;
        sidewaysStickYes = WallMooveVars->movesidewaysStickHeld;
        crawlRated = crawlAdjustments->mCrawlMoveRate;
        libtp::tp::d_a_alink::daAlinkHIO_cutTurn_c1* cutTurnAdjust = &libtp::tp::d_a_alink::cutTurnVars;
        libtp::tp::d_a_alink::daAlinkHIO_cutFnJU_c1* finalCut = &libtp::tp::d_a_alink::cutFinalJumpVars;
        libtp::tp::d_a_alink::daAlinkHIO_cutLargeJump_c1* largeCut = &libtp::tp::d_a_alink::cutLargeJumpVars;
        cutTurnAdjust->mChargeAnm.mSpeed = 2.0f;
        cutTurnAdjust->mLeftTurnAnm.mSpeed = 2.0f;
        cutTurnAdjust->mRightTurnAnm.mSpeed = 2.0f;
        largeCut->mChargeAnm.mSpeed = 4.0f;
        largeCut->mCutAnm.mSpeed = 2.0f;
        largeCut->mLandAnm.mSpeed = 4.0f;
        largeCut->mCutSpeedV = 24.0f;
        finalCut->mCutAnm.mSpeed = 1.7f;
        finalCut->mLandAnm.mSpeed = 2.0f;
    }

    // Adjust several of Link's movement speeds
    void increaseClimbSpeed(bool climbing)
    {
        if (climbing)
        {
#ifdef PLATFORM_WII
            if (!(libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x4000))
#else
            if (!(libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20))
#endif
            {
                ClimbVaars->ladderClimbInitSpeed = ladderClimbSpeedInitialized;
                ClimbVaars->ladderReachTopClimbUpSpeed = ladderReachTopClimb;
                ClimbVaars->ladderTopStartClimbDownSpeed = ladderTopStartClimb;
                ClimbVaars->ladderBottomGetOffSpeed = ladderBottomGetSpeed;
                ClimbVaars->ladderClimbSpeed = ladderClimbb;
                ClimbVaars->wallClimbHorizontalSpeed = wallHorizontalSpeed;
                ClimbVaars->wallClimbVerticalSpeed = wallVerticalSpeed;
                WallMooveVars->moveSidewaysStickNotHeld = sidewaysStickNo;
                WallMooveVars->movesidewaysStickHeld = sidewaysStickYes;
            } else {
                ClimbVaars->ladderClimbInitSpeed = 1.8;
                ClimbVaars->ladderReachTopClimbUpSpeed = 1.765;
                ClimbVaars->ladderTopStartClimbDownSpeed = 1.8;
                ClimbVaars->ladderBottomGetOffSpeed = 1.8;
                ClimbVaars->ladderClimbSpeed = 1.575;
                ClimbVaars->wallClimbHorizontalSpeed = 2.0;
                ClimbVaars->wallClimbVerticalSpeed = 1.875;
                WallMooveVars->moveSidewaysStickNotHeld = 2.0;
                WallMooveVars->movesidewaysStickHeld = 2.0;
            }
        }
        else
        {
#ifdef PLATFORM_WII
            if (!(libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x800))
#else
            if (!(libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x100))
#endif
            {
                crawlAdjustments->mCrawlMoveRate = crawlRated;
            } else {
                crawlAdjustments->mCrawlMoveRate = 20.0f;
            }
        }
    }

    //bool outlinePhase = false;
    bool depleted = false;
    //bool nearDepleteSwap = false;
    bool specialEffectOn = false;
    uint8_t nearDeplete = 0;
    uint8_t specialEffect = 0;
    int8_t outlineR = 0;
    uint8_t outlineG = 0;
    uint8_t outlineB = 0;
    uint8_t outlineA = 0;
    //uint8_t sfxPadding = 0;

    void colorOilMeter(libtp::tp::d_pane_class::CPaneMgr* panePtr, libtp::tp::JUtility::TColor* awesome, libtp::tp::JUtility::TColor* wholesome) {
#ifdef PLATFORM_WII
            if (!libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mShow2D)
#else
            if (!libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygenShowFlag)
#endif
            {
                if (!depleted) {
                    if (specialEffectOn && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen == libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen) {
                        specialEffect++;
                        if (specialEffect < 7) {
                            uint8_t outlineRCandidate = outlineR;
                            if (outlineRCandidate + 36 < 255) outlineR += 36;
                            else if (outlineRCandidate != 255) outlineR = 255;
                            if (outlineB + 26 < 255) outlineB += 26;
                            else if (outlineB != 255) outlineB = 255;
                            if (outlineRCandidate + 27 < 255 || outlineRCandidate - 27 > 0)
                            wholesome->set(outlineR + 27, 255, outlineB - 69, 255);
                        } else if (specialEffect < 14) {
                            if (outlineR - 36 > 0) outlineR -= 36;
                            else if (outlineR < 0) outlineR = 0;
                            if (outlineB - 26 > 69) outlineB -= 26;
                            else if (outlineB < 69) outlineB = 69;
                            if (outlineR + 27 >= 27)
                            wholesome->set(outlineR + 27, 255, outlineB - 69, 255);
                        } else if (specialEffect < 45) {
                            outlineR = 0; outlineB = 69;
                            wholesome->set(outlineR+27, 255, outlineB - 69, 255);
                        } else {
                            specialEffect = 0; specialEffectOn = false;
                        }
                        awesome->set(outlineR, 255, outlineB, 255);
                        //libtp::tp::d_pane_class::setBlackWhite(panePtr, awesome, wholesome);
                    } else if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > 187) {
                        awesome->set(92, 171, 84, 255);
                        wholesome->set(76, 179, 81, 255);
                        libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);
                        awesome->set(0, 255, 69, 255);
                        wholesome->set(27, 255, 0, 255);
                    } else {
                        /*sfxPadding++;
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > 75) {
                            if (sfxPadding >= 10) {
                                libtp::tp::m_Do_Audio::mDoAud_seStart(0x2b, 0, 0, 0);
                                sfxPadding = 0;
                            }
                        } else if (sfxPadding >= 8) {
                            libtp::tp::m_Do_Audio::mDoAud_seStart(0x2b, 0, 0, 0);
                            sfxPadding = 0;
                        }*/
                        if (outlineR > 92) outlineR -= 3;
                        else if (outlineR < 92) outlineR = 92;
                        if (outlineG < 171) outlineG += 5;
                        else if (outlineG > 171) outlineG = 171;
                        if (outlineB < 84) outlineB += 3;
                        else if (outlineB > 84) outlineB = 84;
                        if (outlineA + 6 < 255) outlineA += 6;
                        else if (outlineA != 255) outlineA = 255;
                        nearDeplete++;
                        if (nearDeplete >= 30) {
                            nearDeplete = 0;
                            outlineR = 0xAF; outlineG = 0x22; outlineB = 0; outlineA = 100;
                        }
                        awesome->set(outlineR, outlineG, outlineB + 3, 255);
                        wholesome->set(outlineR - 16, outlineG + 8, outlineB, 255);
                        libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);
                        awesome->set(0, 255, 69, outlineA);
                        wholesome->set(27, 255, 0, outlineA);
                    }
                } else {
                    //tiredSounds(3);
                    awesome->set(0xAF, 0x22, 00, 255);
                    wholesome->set(0x9F, 0x2A, 03, 255);
                    libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);
                    awesome->set(0, 255, 69, 100);
                    wholesome->set(27, 255, 0, 100);
                }
                libtp::tp::d_pane_class::setBlackWhite(panePtr, awesome, wholesome);
                /*awesome->set(0, 0, 0, 255);
                libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, awesome);
                awesome->set(0, 255, 69, 255);
                wholesome->set(27, 255, 0, 255);
                
                libtp::tp::d_pane_class::setBlackWhite(panePtr, awesome, wholesome);

                awesome->set(92, 171, 84, 255);
                wholesome->set(76, 179, 81, 255);
                libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);*/
            } else {
                /*if (!depleted) {
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > 187) {
                        awesome->set(200, 200, 255, 255);
                        wholesome->set(80, 180, 255, 255);
                    } else {
                        if (outlineR < 200) outlineR++;
                        if (outlineG < 200) outlineG += 7;
                        else if (outlineG > 200) outlineG = 200;
                        if (outlineB < 81) outlineB += 3;
                        else if (outlineB > 81) outlineB = 81;
                        nearDeplete++;
                        if (nearDeplete >= 30) {
                            nearDeplete = 0;
                            nearDepleteSwap = true;
                            outlineR = 0xAF; outlineG = 0x22; outlineB = 0;
                        }
                        awesome->set(outlineR, outlineG, outlineB + 3, 255);
                        wholesome->set(outlineR - 16, outlineG + 8, outlineB, 255);
                        libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);
                        awesome->set(200, 200, 255, 100);
                        wholesome->set(80, 180, 255, 100);
                    }
                } else {
                    awesome->set(0xAF, 0x22, 00, 255);
                    wholesome->set(0x9F, 0x2A, 03, 255);
                    libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);
                    awesome->set(200, 200, 255, 100);
                    wholesome->set(80, 180, 255, 100);
                }*/
                awesome->set(200, 200, 255, 255);
                wholesome->set(80, 180, 255, 255);
                libtp::tp::d_pane_class::setBlackWhite(panePtr, awesome, wholesome);
            }
        //}
        /*else {
            if (outlinePhase == false && (outlineR != 0xAF || outlineG != 0x22)) {
                if (outlineR < 0xAF) outlineR += 8;
                else if (outlineR > 0xAF) outlineR = 0xAF;
                if (outlineG < 0x22) outlineG += 4;
                else if (outlineG > 0x22) outlineG = 0x22;
                awesome->set(outlineR, outlineG, 0x00, 0xFF);
                if (outlineR == 0xAF && outlineG == 0x22) outlinePhase = true;
            } else if (outlinePhase && (outlineR != 0 || outlineG != 0)) {
                if (outlineR > 8) outlineR -= 8;
                else if (outlineR > 0xAF) outlineR = 0;
                if (outlineG > 4) outlineG -= 4;
                else if (outlineG > 0x22) outlineG = 0;
                awesome->set(outlineR, outlineG, 0x00, 0xFF);
                if (outlineR <= 0x08 && outlineG <= 0x08) outlinePhase = false;
            }

            libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, awesome);
        }*/
    }

    //void drawWindow(int32_t x, int32_t y, int32_t width, int32_t height, libtp::tp::J2DPicture::J2DPicture* shieldType) {
        // Make sure the icon exists
        /*libtp::tp::J2DPicture::J2DPicture* tempBgWindow = shieldType;
        if (!tempBgWindow)
        {
            sprintf(sysConsolePtr->consoleLine[6].line, "Rest In Pepperoni");
            return;
        }*/

        // Set the icon color
        //tempBgWindow->setWhiteColor(0x00000000);
        //tempBgWindow->setBlackColor(0xffffffff);

        // Convert x, y, width, and height to floats
        /*constexpr int32_t numValues = 4;
        const int32_t values[numValues] = {x, y, width, height};
        float valuesOut[numValues];

        for (int32_t i = 0; i < numValues; i++)
        {
            valuesOut[i] = static_cast<float>(values[i]);
        }*/

        // Draw the icon
        /*libtp::tp::J2DPicture::J2DPicture_draw(tempBgWindow,
                                               valuesOut[0],
                                               valuesOut[1],
                                               valuesOut[2],
                                               valuesOut[3],
                                               false,
                                               false,
                                               false);*/
    //}

    uint8_t replenish2ndShieldpadding = 10;

    void colorMMeter(libtp::tp::d_pane_class::CPaneMgr* panePtr, libtp::tp::JUtility::TColor* awesome, libtp::tp::JUtility::TColor* wholesome) {
        awesome->set(0, 0, 0, 255);
        libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, awesome);
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] == 0x2a || libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] == 0x2b) {
            awesome->set(195, 148, 60, 255);
            wholesome->set(242, 232, 213, 255);
            //drawWindow(40, 34, 48, 48, shieldIcon);
        } else {
            awesome->set(193, 168, 0, 255);
            wholesome->set(255, 231, 76, 255);
            //drawWindow(40, 34, 48, 48, shieldIcon3);
            if (shieldHylianHealth < 255) {
                replenish2ndShieldpadding--;
                if (replenish2ndShieldpadding == 0) {
                    replenish2ndShieldpadding = 10;
                    if (shieldHylianHealth + 2 <= 255) shieldHylianHealth += 1;
                    else shieldHylianHealth = 255;
                }
            }
        }
            
        libtp::tp::d_pane_class::setBlackWhite(panePtr, awesome, wholesome);
    }

    bool uiChecking = false;

    uint8_t meterType = 0;

    void meterVisibility(libtp::tp::d_meter2_draw::dMeter2Draw_c* boi) {
        if (uiChecking && (specialEffectOn || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen < libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen)) {
            //libtp::tp::d_meter2_draw::setAlphaMagicChange(boi, true);
            libtp::tp::d_meter2_draw::setAlphaOxygenAnimeMax(boi);
        }
        else
            libtp::tp::d_meter2_draw::setAlphaOxygenAnimeMin(boi);
    }

    bool speedRun = false;
    libtp::tp::d_a_alink::daAlink_ANM anmCheck;

    int32_t moveInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        //if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x40) { libtp::tp::d_a_alink::procAtnActorMoveInit(linkActrPtr); return 0;}
        if (!libtp::tp::d_a_alink::commonProcInitNotSameProc(linkActrPtr, libtp::tp::d_a_alink::PROC_MOVE)) return 0;
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x800 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick_amplitude > 0.2f && linkActrPtr->field_0x33d4 >= 23.0f && linkActrPtr->mGrabItemAcKeep.mActor == NULL)
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x100 && libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickValue > 0.2f && linkActrPtr->mNormalSpeed >= 23.0f && linkActrPtr->mGrabItemAcKeep.mActor == NULL)
#endif
        {
            shieldAttack = false;
            if (linkActrPtr->mEquipItem == 0x103) libtp::tp::d_a_alink::swordUnequip(linkActrPtr);
            libtp::tp::d_a_alink::setSingleAnimeBaseSpeed(linkActrPtr, libtp::tp::d_a_alink::ANM_RUN_B, 1.7f,
                                                          libtp::tp::d_a_alink::crouchVars.mCrouchInterpolation);
            anmCheck = libtp::tp::d_a_alink::ANM_RUN_B;
        }

        else {
            libtp::tp::d_a_alink::setBlendMoveAnime(linkActrPtr, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
            anmCheck = libtp::tp::d_a_alink::ANM_ATN_COW;
        }
        libtp::tp::d_a_alink::setFootEffectProcType(linkActrPtr, 3);
        return 1;
    }

    float shieldSpeedInspector = 0.0f;
    bool sprintFuel = false;
    bool rollFuel = false;
    bool gameplayStatus = false;
    uint8_t paddingForSword = 25;

    int32_t moveIt(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {
            if (libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr)) {libtp::tp::d_a_alink::procWaitInit(linkActrPtr); return 0;}
#ifdef PLATFORM_WII
            if (linkActrPtr->field_0x33d4 > 0.5f) linkActrPtr->field_0x33d4 = 0.0f;
#else
            if (linkActrPtr->mNormalSpeed > 0.5f) linkActrPtr->mNormalSpeed = 0.0f;
#endif
        }
#ifdef PLATFORM_WII
        if (gameplayStatus && libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr) && !libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mShow2D /*!libtp::tp::d_a_player::checkNoResetFlg0(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, libtp::tp::d_a_player::FLG0_UNDERWATER)*/)
#else
        if (gameplayStatus && libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr) && !libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygenShowFlag /*!libtp::tp::d_a_player::checkNoResetFlg0(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, libtp::tp::d_a_player::FLG0_UNDERWATER)*/)
#endif
        {
            staminaConsumption(1, false, true);
            tiredSounds(1);
#ifdef PLATFORM_WII
            if (!depleted && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x800 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick_amplitude > 0.2f && linkActrPtr->mGrabItemAcKeep.mActor == NULL) {
                linkActrPtr->field_0x33d4 = 16.0f;
                staminaConsumption(4, false, true);
            }
#else
            if (!depleted && libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x100 && libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickValue > 0.2f && linkActrPtr->mGrabItemAcKeep.mActor == NULL) {
                linkActrPtr->mNormalSpeed = 16.0f;
                staminaConsumption(4, false, true);
            }
#endif
        }
        libtp::tp::d_a_alink::setFootEffectProcType(linkActrPtr, 3);
        if (!libtp::tp::d_a_alink::checkNextAction(linkActrPtr, 0) && !libtp::tp::d_a_alink::checkFrontWallTypeAction(linkActrPtr)) {
#ifdef PLATFORM_WII
            if (linkActrPtr->mDemo.mDemoMode == 2 && linkActrPtr->field_0x33d4 > linkActrPtr->field_0x594 * libtp::tp::d_a_alink::moveVars.mWalkChangeRate) {
                linkActrPtr->field_0x33d4 = linkActrPtr->field_0x594 * libtp::tp::d_a_alink::moveVars.mWalkChangeRate;
            }
#else
            if (linkActrPtr->mDemo.mDemoMode == 2 && linkActrPtr->mNormalSpeed > linkActrPtr->field_0x594 * libtp::tp::d_a_alink::moveVars.mWalkChangeRate) {
                linkActrPtr->mNormalSpeed = linkActrPtr->field_0x594 * libtp::tp::d_a_alink::moveVars.mWalkChangeRate;
            }
#endif
#ifdef PLATFORM_WII
        if (gameplayStatus && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x800 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick_amplitude > 0.2f && linkActrPtr->mGrabItemAcKeep.mActor == NULL && (linkActrPtr->field_0x33d4 >= 23.0f || (libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr) && linkActrPtr->field_0x33d4 >= 2.0f)))
#else
        if (gameplayStatus && libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x100 && libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickValue > 0.2f && linkActrPtr->mGrabItemAcKeep.mActor == NULL && (linkActrPtr->mNormalSpeed >= 23.0f || (libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr) && linkActrPtr->mNormalSpeed >= 2.0f)))
#endif
            {
                if (anmCheck != libtp::tp::d_a_alink::ANM_RUN_B) {
                    shieldAttack = false;
                    if (linkActrPtr->mEquipItem == 0x103) {libtp::tp::d_a_alink::swordUnequip(linkActrPtr); paddingForSword = 25;}
                    libtp::tp::d_a_alink::setSingleAnimeBaseSpeed(linkActrPtr, libtp::tp::d_a_alink::ANM_RUN_B, 1.7f,
                                                            libtp::tp::d_a_alink::crouchVars.mCrouchInterpolation);
                    anmCheck = libtp::tp::d_a_alink::ANM_RUN_B;
                    libtp::tp::m_Do_Audio::mDoAud_seStart(0x10005, 0, 0, 0);
                }
#ifdef PLATFORM_WII
                else if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake > 0.2f)
#else
                else if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20)
#endif
                {libtp::tp::d_a_alink::procFrontRollInit(linkActrPtr); anmCheck = libtp::tp::d_a_alink::ANM_ROLL_CRASH; rollFuel = true;}
#ifdef PLATFORM_WII
                else if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].wiimote_shake > 0.2f)
#else
                else if ((libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x200))
#endif
                {
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[1] != 0xff && !libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr)) {
                        //libtp::tp::d_a_alink::swordEquip(linkActrPtr, 0);
                        //linkActrPtr->mEquipItem = 0x103;
                        anmCheck = libtp::tp::d_a_alink::ANM_COW_CATCH;
                        libtp::tp::d_a_alink::deleteEquipItem(linkActrPtr, 0, 0);
                        libtp::tp::d_a_alink::setSwordModel(linkActrPtr);
                        float tempEquippp = libtp::tp::d_a_alink::cutJumpVars.mBaseJumpSpeedH;
                        libtp::tp::d_a_alink::cutJumpVars.mBaseJumpSpeedH = libtp::tp::d_a_alink::cutJumpVars.mAirJumpSpeedH;
                        libtp::tp::d_a_alink::procCutJumpInit(linkActrPtr, 0);
                        libtp::tp::d_a_alink::cutJumpVars.mBaseJumpSpeedH = tempEquippp;
                        anmCheck = libtp::tp::d_a_alink::ANM_ATN_COW;
                        return 0;
                        //libtp::tp::d_a_alink::modelDraw(linkActrPtr, linkActrPtr->mpSwMModel, 1);
                    }
                }
                if (anmCheck != libtp::tp::d_a_alink::ANM_ROLL_CRASH && !libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr)) {
                    sprintFuel = true;
                    // uncomment line below and comment out line after it to make player sprint like Sonic when equipping sword right as he starts sprinting
                    //if (linkActrPtr->mEquipItem == 0x103) libtp::tp::d_a_alink::swordUnequip(linkActrPtr);
                    if (linkActrPtr->mEquipItem == 0x103) {if (paddingForSword == 0) libtp::tp::d_a_alink::deleteEquipItem(linkActrPtr, 0, 0); else paddingForSword--;}
#ifdef PLATFORM_WII
                    linkActrPtr->field_0x33d4 = 30.0f;
#else
                    linkActrPtr->mNormalSpeed = 30.0f;
#endif
                }
            }
            else {
                libtp::tp::d_a_alink::setBlendMoveAnime(linkActrPtr, 0.004999999888241291f);
                anmCheck = libtp::tp::d_a_alink::ANM_ATN_COW;
            }
            if (linkActrPtr->field_0x3174 != 8) {
                linkActrPtr->field_0x30a0 =
                    cLib_minMaxLimit((int16_t)(linkActrPtr->field_0x2ff0 >> 1), libtp::tp::d_a_alink::something.m.mNeckMaxUp,
                                            libtp::tp::d_a_alink::something.m.mNeckMaxDown);
            }
        }
        if (shieldAttack) {
#ifdef PLATFORM_WII
            shieldSpeedInspector = linkActrPtr->field_0x33d4;
            if (shieldSpeedInspector > 16.0f && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick_amplitude > 0.2f)
            {
                if (shieldSpeedInspector < 23.0f) linkActrPtr->field_0x33d4 = 23.0f;
            }
#else
            shieldSpeedInspector = linkActrPtr->mNormalSpeed;
            if (shieldSpeedInspector > 16.0f && libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickValue > 0.2f)
            {
                if (shieldSpeedInspector < 23.0f) linkActrPtr->mNormalSpeed = 23.0f;
            }
#endif
        }
        return 1;

    }

    void* getZel00BmgInf()
    {
        uint32_t infPtrRaw = reinterpret_cast<uint32_t>(libtp::tp::JKRArchivePub::JKRArchivePub_getGlbResource(
            0x524F4F54, // ROOT
            "zel_00.bmg",
            libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMsgDtArchive[0]));

        // getGlbResource gets a pointer to MESGbmg1, but we need a pointer to INF1, which is just past MESGbmg1, and MESGbmg1
        // has a size of 0x20
        return reinterpret_cast<void*>(infPtrRaw + 0x20);
    }

    void* getInf1Ptr(const char* file)
    {
        uint32_t infPtrRaw = reinterpret_cast<uint32_t>(
            libtp::tp::JKRArchivePub::JKRArchivePub_getGlbResource(/* ROOT */ 0x524F4F54, file, nullptr));

        // getGlbResource gets a pointer to MESGbmg1, but we need a pointer to INF1, which is just past MESGbmg1, and MESGbmg1
        // has a size of 0x20
        return reinterpret_cast<void*>(infPtrRaw + 0x20);
    }

    int32_t downNope() {
        return false;
    }

    void silentArmor() {}
    
#if defined(TP_WUS0) || defined(TP_WEU)
    int16_t temporar = 0x106;
#else
    int16_t temporar = 0x108;
#endif

    uint16_t temporarPart2 = 0;

    uint8_t burnShield = 0;

    // Burn wooden shield slowly if you have upgraded shield
    void shieldBurn() {
        if (shieldWoodHealth - 2 >= 0)
            shieldWoodHealth -= 2;
        else shieldWoodHealth = 0;
        burnShield++;
        if (burnShield == 30 || shieldWoodHealth == 0) {
            burnShield = 0;
            if (shieldWoodHealth == 0) {shieldWoodHealth = 255; *reinterpret_cast<uint32_t*>(linkExecute + shieldBurn1) = shieldBurn1Vanilla; *reinterpret_cast<uint32_t*>(linkExecute + shieldBurn1+4) = shieldBurn2Vanilla; saveInfoPtr->woodShieldDurability = shieldWoodHealth; libtp::tp::d_meter2_info::dMeter2Info_setShield(0xff, true); lastShield = 0xfe; libtp::tp::d_a_alink::dMeter2Info_setFloatingMessage(2047, 90, true);}
            libtp::tp::d_a_alink::setWoodShieldBurnOutEffect(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
        }
        saveInfoPtr->woodShieldDurability = shieldWoodHealth;
    }

    void swimDive() {
        libtp::tp::d_a_alink::procSwimDiveInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
    }

    void Mod::init()
    {
        libtp::display::setConsole(true, 25);
        libtp::display::setConsoleColor(0, 0, 0, 0);

        //uint32_t slipperyMovement = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::posMove);
        uint32_t kanterapoggy = reinterpret_cast<uint32_t>(libtp::tp::d_meter2_draw::drawKanteraScreen);
        uint32_t linkSwim1 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procSwimMove);
        uint32_t linkArmor = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setDamagePoint);
        uint32_t linkDraw = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::drawLink);
        uint32_t arrowShieldSomething = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setArrowShieldActor);
        uint32_t guardSeOrSmthg = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setGuardSe);
        uint32_t damageAct = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::checkDamageAction);
        //uint32_t linkSwim2 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::checkSwimUpAction);
#ifdef PLATFORM_WII
        libtp::patch::writeBranchBL(kanterapoggy + 0x190, colorOilMeter);
        libtp::patch::writeBranch(kanterapoggy + 0x1E0, kanterapoggy + 0x2EC);
        libtp::patch::writeBranchBL(kanterapoggy + 0x244, colorOilMeter);
        libtp::patch::writeBranch(kanterapoggy + 0x294, kanterapoggy + 0x2EC);
        libtp::patch::writeBranchBL(kanterapoggy + 0x2E8, colorOilMeter);
        libtp::patch::writeBranchBL(kanterapoggy + 0x74, colorMMeter);
        libtp::patch::writeBranch(linkSwim1 + 0x138, swimDive);
        libtp::patch::writeBranch(linkArmor + 0x110, linkArmor + 0x134);
        libtp::patch::writeBranchBL(linkExecute + 0x20FC, silentArmor);
        *reinterpret_cast<uint32_t*>(linkDraw + 0x374) = 0x3b400000;
        *reinterpret_cast<uint32_t*>(arrowShieldSomething + 0x154) = 0x60000000;
        *reinterpret_cast<uint32_t*>(guardSeOrSmthg + 0x64) = 0x60000000;
        *reinterpret_cast<uint32_t*>(damageAct + 0x458) = 0x3be00000;
#else
        libtp::patch::writeBranchBL(kanterapoggy + 0x19C, colorOilMeter);
        libtp::patch::writeBranch(kanterapoggy + 0x1EC, kanterapoggy + 0x2F8);
        libtp::patch::writeBranchBL(kanterapoggy + 0x250, colorOilMeter);
        libtp::patch::writeBranch(kanterapoggy + 0x2A0, kanterapoggy + 0x2F8);
        libtp::patch::writeBranchBL(kanterapoggy + 0x2F4, colorOilMeter);
        //libtp::patch::writeBranchBL(kanterapoggy + 0x2A0, colorOilMeter);
        libtp::patch::writeBranchBL(kanterapoggy + 0x78, colorMMeter);
        libtp::patch::writeBranch(linkSwim1 + 0x100, swimDive);
        libtp::patch::writeBranch(linkArmor + 0xEC, linkArmor + 0x110);
        libtp::patch::writeBranchBL(linkExecute + 0x2034, silentArmor);
        *reinterpret_cast<uint32_t*>(linkDraw + 0x2D0) = 0x60000000;
        *reinterpret_cast<uint32_t*>(arrowShieldSomething + 0x144) = 0x60000000;
        *reinterpret_cast<uint32_t*>(guardSeOrSmthg + 0x34) = 0x60000000;
        *reinterpret_cast<uint32_t*>(damageAct + 0x43C) = 0x3bc00000;
        //libtp::patch::writeBranch(linkSwim2 + 0x, linkSwim2 + 0x254)
#endif

        strcpy( sysConsolePtr->consoleLine[20].line, "Navigation: Press D-Pad Up or Down");
        strcpy( sysConsolePtr->consoleLine[21].line, "Select: Press A          Cancel: Press B");
        strcpy( sysConsolePtr->consoleLine[23].line, "youtube.com/@captainkittyca2");
        sysConsolePtr->consoleLine[6].showLine = false;
        climbRegularSpeed();

        initMap =
            libtp::patch::hookFunction( libtp::tp::d_stage::dStage_playerInit, [](void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data) { return gMod->mapInitialized(stageDt, i_data, num, raw_data);});
        shieldManually =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::getMainBckData, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID) { return gMod->manualShield(linkActrPtr, i_anmID); } );
        unSheathShield =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::setShieldGuard, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->unSheathingShield(linkActrPtr); } );
        onUI =
            libtp::patch::hookFunction(libtp::tp::d_meter2_draw::setAlphaLifeAnimeMax, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->UICheck(dMeterDrawPtr);});
        offUI =
            libtp::patch::hookFunction(libtp::tp::d_meter2_draw::setAlphaLifeAnimeMin ,[](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->UICheck2(dMeterDrawPtr);});
        return_executee =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::execute_, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->executee(linkActrPtr);});
        libtp::patch::hookFunction(libtp::tp::d_a_alink::procMoveInit, moveInit);
        libtp::patch::hookFunction(libtp::tp::d_a_alink::procMove, moveIt);
        //libtp::patch::hookFunction(libtp::tp::d_a_alink::checkZoraWearMaskDraw, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return divingMoment(linkActrPtr);});
        return_drawMeter2 =
            libtp::patch::hookFunction(libtp::tp::d_meter2_draw::drawMeter, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->drawMeter2(dMeterDrawPtr);});
        return_messageSmthg =
            libtp::patch::hookFunction(libtp::tp::control::setMessageCode_inSequence, [](libtp::tp::control::TControl* control, const void* TProcessor, uint16_t unk3, uint16_t msgID) { return gMod->customMessageCode(control, TProcessor, unk3, msgID);});
        return_checkLinkStatus =
            libtp::patch::hookFunction(libtp::tp::d_meter2::moveKantera, [](libtp::tp::d_meter2::dMeter2_c* dMeter2Ptr) { return gMod->checkLinkStatus(dMeter2Ptr);});
        return_rollFront =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procFrontRollInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->rollFront(linkActrPtr);});
        return_cutnormalInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutNormalInit, [](libtp::tp::d_a_alink::daAlink* linkactrPtr, int32_t parammmm) { return gMod->cutnormalInit(linkactrPtr, parammmm);});
        return_airCutInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutJumpInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t airCut) { return gMod->airCutInit(linkActrPtr, airCut);});
        return_guardSlipInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGuardSlipInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t abc, void* hi) { return gMod->guardSlipped(linkActrPtr, abc, hi);});
        return_swimWait =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procSwimWait, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->swimWaiting(linkActrPtr);});
        return_swimMove =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procSwimMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->swimMoving(linkActrPtr);});
        gotAnItem =
            libtp::patch::hookFunction(libtp::tp::d_item::execItemGet, [](uint8_t items) { return gMod->gotIt(items);});
        return_waitInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procWaitInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->waitingInit(linkActrPtr);});
        return_checkAtnWait =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkAtnWaitAnime, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->atnWaitChecking(linkActrPtr);});
        return_autoJumping =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procAutoJump, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->currentlyAutoJumping(linkActrPtr);});
        return_falling =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procFall, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->currentlyFalling(linkActrPtr);});
        return_breakingGuard =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGuardBreakInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->guardIsBreaking(linkActrPtr);});
        return_cutSpinInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutTurnInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aa, int32_t bb) { return gMod->cutSpinInit(linkActrPtr, aa, bb);});
        return_cutFinishInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutFinishInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t typeOfCut) { return gMod->cutFinishInit(linkActrPtr, typeOfCut);});
        return_cutSpinChargeInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutTurnChargeInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutSpinChargeInit(linkActrPtr);});
        return_cutLargeJumpChargeInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutLargeJumpChargeInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutLargeJumpChargeInit(linkActrPtr);});
        return_cutLargeJumpInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutLargeJumpInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutLargeJumpInit(linkActrPtr);});
        return_cutJumpUpInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutFinishJumpUpInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutJumpUpInit(linkActrPtr);});
        return_cutHeadInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutHeadInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutHeadInit(linkActrPtr);});
        return_sideStepInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procSideStepInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) { return gMod->sideSteppingInit(linkActrPtr, smthgSmthg);});
        return_atnMove =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procAtnMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->atnMoving(linkActrPtr);});
        return_backJumpInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procBackJumpInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) { return gMod->backJumpingInit(linkActrPtr, smthgSmthg);});
        return_atnActrMve =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procAtnActorMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->atnActrMve(linkActrPtr);});
        throwIron =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procIronBallThrowInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->ironThrower(linkActrPtr);});
        ironRepresentative =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkUpperItemActionIronBall, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->representingTheIron(linkActrPtr);});
        ironReturning =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procIronBallReturnInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->returningTheIron(linkActrPtr);});
        itemRent =
            libtp::patch::hookFunction(libtp::tp::f_ap_game::fapGm_Execute, []() { return gMod->rentAnItem();});
        expiredMeter =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkCastleTownUseItem, [](uint16_t item) { return gMod->meterExpiration(item);});
        return_climbMoveUpDownInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procClimbMoveUpDownInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) { return gMod->climbMoveUpDownInitialize(linkActrPtr, smthgSmthg);});
        return_climbMoveSideInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procClimbMoveSideInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->climbMoveSideInitialize(linkActrPtr);});
        return_climbWait =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procClimbWait, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->climbWait(linkActrPtr);});
        return_climbUpStartInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procClimbUpStartInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) { return gMod->climbUpStartInitialize(linkActrPtr, smthgSmthg);});
        return_hangWait =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procHangWait, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->yoHangWait(linkActrPtr);});
        return_hangMove =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procHangMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->yoHangMove(linkActrPtr);});
        return_hangFallStart =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procHangFallStart, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->yoHangFallStart(linkActrPtr);});
        shieldEquipped =
            libtp::patch::hookFunction(libtp::tp::d_com_inf_game::setSelectEquipShield, [](uint8_t shieldID) { return gMod->equippingTheShield(shieldID);});
        return_checkRestHP =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkRestHPAnime, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->restCheckPlease(linkActrPtr);});
        return_grabThrowInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGrabThrowInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSomething) { return gMod->grabThrowerInitialized(linkActrPtr, smthgSomething);});
        return_grabReadyInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGrabReadyInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->grabReadyInitialized(linkActrPtr);});
        return_ladderMove =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procLadderMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->moveLadderPlease(linkActrPtr);});
        return_sideRollCheck =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkSideRollAction, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t somethingSideRoll) { return gMod->sideRollChecking(linkActrPtr, somethingSideRoll);});
        return_guardBattle =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGuardAttackInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->guardBattle(linkActrPtr);});
        return_crawlMovement =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCrawlMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->crawlMovementContinue(linkActrPtr);});
        return_oxygenAndStamina =
            libtp::patch::hookFunction(libtp::tp::d_meter2::moveOxygen, [](libtp::tp::d_meter2::dMeter2_c* dMeter2Ptr) { return gMod->oxygenAndStamina(dMeter2Ptr);});
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkUpperGuardAnime, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->upperGuardChecking(linkActrPtr);});
            libtp::patch::hookFunction(libtp::tp::d_menu_window::dMw_DOWN_TRIGGER, downNope);
        libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosY = 60.0f;
        libtp::tp::d_meter_hio::g_drawHIO.mMagicMeterPosY = 40.0f;
        gMod = this;
    }

    char titleMap[8] = "F_SP102";
    char videoMap[8] = "S_MV000";
    bool firstTime = false;
    bool shieldOn = false;
    bool updatedShield = false;
    //bool getSwordWood = false;
    uint8_t dashPadding = 0;
    uint32_t paramsGrab = 0;

    int32_t Mod::mapInitialized(void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data) {
        depleted = false;
        shieldAttack = false;
        gameplayStatus = false;
        dashPadding = 0;
        specialEffectOn = false;
        specialEffect = 0;
        replenish2ndShieldpadding = 10;
        libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen;
        if (!shieldOn) lastShield = 0xfe;
        //sprintf(sysConsolePtr->consoleLine[4].line, "Room: %d", libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mRoomNo);
        //if (getSwordWood) {libtp::tp::d_a_alink::setClothesChange(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, 0); libtp::tp::d_com_inf_game::setSelectEquipClothes(0x2f); getSwordWood = false;}
        if (strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, titleMap) != 0 && strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, videoMap) != 0 && firstTime == false)
        {
            firstTime = true;
            shieldWoodHealth = saveInfoPtr->woodShieldDurability;
            shieldHylianHealth = saveInfoPtr->hylianShieldDurability;
            if (shieldWoodHealth == 0 && (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2a) || libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2b))) {
                shieldWoodHealth = 255;
            }
            if (shieldHylianHealth == 0 && libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2c)) shieldHylianHealth = 255;
            if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31)) {libtp::tp::d_save::offFirstBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_get_item, 0x31); saveInfoPtr->zoraArmorAcquired = 253; libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[0] = 0x2f;}
            if (saveInfoPtr->zoraArmorAcquired == 253) {
                zoraArmorObtained(true);
            } else {
                zoraArmorObtained(false);
            }
            if (/*!libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2908) || !libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2904) || !libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2902) || !libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2901) || !libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2a80) ||*/ !libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2a40)) {
                libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2908); libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2904); libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2902); libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2901); libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2a80); libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2a40); 
            }
            if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2a)) {
                libtp::patch::writeBranchBL(linkExecute + shieldBurn1, shieldBurn);
                libtp::patch::writeBranch(linkExecute + shieldBurn1+4, linkExecute + shieldBurn1Jump);
            } else {
                *reinterpret_cast<uint32_t*>(linkExecute + shieldBurn1) = shieldBurn1Vanilla;
                *reinterpret_cast<uint32_t*>(linkExecute + shieldBurn1+4) = shieldBurn2Vanilla;
            }
            lastShield = libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2]; if (lastShield == 0xff) {lastShield = 0xfe; shieldOn = false;} else shieldOn = true;
            if (saveInfoPtr->objectStored != 0) {
                temporarPart2 = saveInfoPtr->objectStored;
                paramsGrab = saveInfoPtr->objectParams;
            }
        } else if (strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, titleMap) == 0 || strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, videoMap) == 0) {
            firstTime = false;
            armorTimer = 10;
            temporarPart2 = 0;
            paramsGrab = 0;
        }
        return initMap(stageDt, i_data, num, raw_data);
    }

    void Mod::gotIt(uint8_t items) {
        if (strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, "F_SP103") != 0 || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mRoomNo != 1) {
            if (items == 0x2a || items == 0x2b || items == 0x2c) return;
        }
#ifdef PLATFORM_WII
        if (items == 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mShow2D /*(libtp::tp::d_a_player::checkNoResetFlg0(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, libtp::tp::d_a_player::FLG0_UNDERWATER) || (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID >= 0x79 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID <= 0x7f))*/)
#else
        if (items == 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygenShowFlag /*(libtp::tp::d_a_player::checkNoResetFlg0(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, libtp::tp::d_a_player::FLG0_UNDERWATER) || (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID >= 0x79 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID <= 0x7f))*/)
#endif
        {
            libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen;
            return;
        }
        if (items == 0x31) {
            zoraArmorObtained(true);
            saveInfoPtr->zoraArmorAcquired = 253;
            return;
        }
        return gotAnItem(items);
    }

    bool Mod::meterExpiration(uint16_t item) {
        if (depleted) {
            if (item == 0x42 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mEquipItem == 0x42) {
                libtp::tp::d_a_alink::itemUnequip(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, item, 1.0f);
                return false;
            }
        }

        return expiredMeter(item);
    }

    void drawMMeter( libtp::tp::d_meter2_draw::dMeter2Draw_c* mMeterDraw,
                             int32_t maxMeter,
                             int32_t currentMeter,
                             float posX,
                             float posY,
                             bool visible )
    {

        float var_f6 = ( mMeterDraw->mpMagicFrameR->getInitPosX() ) - ( mMeterDraw->mpMagicFrameL->getInitPosX() );
        float var_f7 = (float) currentMeter / (float) maxMeter;
        float var_f4 = 1.0f;
        mMeterDraw->field_0x584[0] = var_f7 * mMeterDraw->mpMagicMeter->getInitSizeX();
        mMeterDraw->field_0x590[0] = mMeterDraw->mpMagicMeter->getInitSizeY();
        mMeterDraw->field_0x59c[0] = ( var_f6 * var_f4 ) + mMeterDraw->mpMagicFrameL->getInitPosX();
        mMeterDraw->field_0x5a8[0] = mMeterDraw->mpMagicFrameL->getInitPosY();
        mMeterDraw->field_0x5b4[0] = var_f4 * mMeterDraw->mpMagicBase->getInitSizeX();
        mMeterDraw->field_0x5c0[0] = mMeterDraw->mpMagicBase->getInitSizeY();
        mMeterDraw->field_0x5cc[0] = libtp::tp::d_meter_hio::g_drawHIO.mMagicMeterScale;
        mMeterDraw->field_0x5d8[0] = libtp::tp::d_meter_hio::g_drawHIO.mMagicMeterScale;
        mMeterDraw->field_0x5e4[0] = posX;
        mMeterDraw->field_0x5f0[0] = posY;
        if ( visible )
        {
            if ( mMeterDraw->field_0x742[0] >= 5 )
            {
                mMeterDraw->mMeterAlphaRate[0] = libtp::tp::d_meter_hio::g_drawHIO.mHUDAlpha;
            }
            else
            {
                mMeterDraw->field_0x742[0]++;
                if ( mMeterDraw->field_0x742[0] > 5 )
                {
                    mMeterDraw->field_0x742[0] = 5;
                }

                mMeterDraw->mMeterAlphaRate[0] =
                    ( mMeterDraw->field_0x742[0] / 5.0f ) * libtp::tp::d_meter_hio::g_drawHIO.mHUDAlpha;
            }
        }
        else
        {
            if ( mMeterDraw->field_0x742[0] <= 0 )
            {
                mMeterDraw->mMeterAlphaRate[0] = 0;
            }
            else
            {
                mMeterDraw->field_0x742[0]--;
                if ( mMeterDraw->field_0x742[0] <= 0 )
                {
                    mMeterDraw->field_0x742[0] = 0;
                }

                mMeterDraw->mMeterAlphaRate[0] =
                    ( mMeterDraw->field_0x742[0] / 5.0f ) * libtp::tp::d_meter_hio::g_drawHIO.mHUDAlpha;
            }
        }

        libtp::tp::d_meter2_draw::setAlphaMagicChange( mMeterDraw, true );
    }

    void Mod::drawMeter2(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) {
        return_drawMeter2(dMeterDrawPtr);
        if (uiChecking) {
            uint8_t shieldUsed = 2;
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] == 0x2a || libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] == 0x2b) shieldUsed = shieldWoodHealth;
            else if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] == 0x2c) shieldUsed = shieldHylianHealth;
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] != 0xff) {
                drawMMeter(dMeterDrawPtr, 255, shieldUsed, xPosition, 40.0f, true);
                libtp::tp::d_meter2_draw::drawKanteraScreen(dMeterDrawPtr, 0);
                //sprintf(sysConsolePtr->consoleLine[5].line, "%d", shieldUsed);
            }
        }
    }

    bool shieldAttackReload = false;
    uint8_t shieldReloading = 0;
    uint8_t RButtonPadding = 0;
    bool RButtonTime = false;
    bool guardBattleAuthorized2 = false;
    //bool swordUneqipMoment = false;

    int32_t Mod::executee(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
//#ifdef PLATFORM_WII
        //sprintf(sysConsolePtr->consoleLine[0].line, "oxygenFlag: %d", libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mShow2D);
        //sprintf(sysConsolePtr->consoleLine[7].line, "stickAngle: %f", libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick_amplitude);
//#else
        //sprintf(sysConsolePtr->consoleLine[6].line, "speed: %f", linkActrPtr->mNormalSpeed);
        //sprintf(sysConsolePtr->consoleLine[7].line, "stickAngle: %f", libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickValue);
//#endif
        //sprintf(sysConsolePtr->consoleLine[8].line, "zoraArmor: %d", libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.unk31[2]);
        //sprintf(sysConsolePtr->consoleLine[4].line, "mProcID: %d", linkActrPtr->mProcID);
        //if (linkActrPtr->mGrabItemAcKeep.mActor != NULL) {
            //sprintf(sysConsolePtr->consoleLine[1].line, "parameters: %d", linkActrPtr->mGrabItemAcKeep.mActor->mParameters);
            //sprintf(sysConsolePtr->consoleLine[0].line, "specialEffect: %d", specialEffect);
            //sprintf(sysConsolePtr->consoleLine[1].line, "attackOffset: %f", libtp::tp::d_a_alink::guardVars.mAttackPosOffset);
            //sprintf(sysConsolePtr->consoleLine[1].line, "crawlRate: %f",libtp::tp::d_a_alink::crouchVars.mCrawlMoveRate);
            //sprintf(sysConsolePtr->consoleLine[2].line, "grabCarry: %d",linkActrPtr->mGrabItemAcKeep.mActor->mCarryType);
        //}
        //sprintf(sysConsolePtr->consoleLine[2].line, "temporarPart2: %d", temporarPart2);
        //sprintf(sysConsolePtr->consoleLine[2].line, "gameplayStatus: %d", gameplayStatus);
        //sprintf(sysConsolePtr->consoleLine[1].line, "currentSword: %d", );
        //sprintf(sysConsolePtr->consoleLine[13].line, "Ypos: %f", linkActrPtr->mCurrent.mPosition.y); sprintf(sysConsolePtr->consoleLine[14].line, "Xpos: %f", linkActrPtr->mCurrent.mPosition.x); sprintf(sysConsolePtr->consoleLine[15].line, "Zpos: %f", linkActrPtr->mCurrent.mPosition.z);
        //sprintf(sysConsolePtr->consoleLine[10].line, "mTargetedActor: %d", (uint32_t)linkActrPtr->mTargetedActor);
        /*if (libtp::tp::J3DModel::ChkTgHit(&linkActrPtr->field_0x850[2])) {
            libtp::tp::f_op_actor::fopAc_ac_c* hit_actor = libtp::tp::J3DModel::getAc(&linkActrPtr->field_0x850[2].mGobjTg);
            if (hit_actor != NULL && hit_actor->mProcName == 0x17b) libtp::tp::m_Do_Audio::mDoAud_seStart(0x4f, 0, 0, 0);
        }*/
        if (RButtonPadding > 0) {
            if (gameplayStatus) {
                RButtonPadding--;
                if (RButtonPadding == 0) {
                    RButtonTime = false;
                    if (!guardBattleAuthorized2)
                        {commenceGuardAttack(false); libtp::tp::d_a_alink::procGuardAttackInit(linkActrPtr);}
                    guardBattleAuthorized2 = false;
                }
            } else {RButtonPadding = 0; RButtonTime = false;}
        }

        const int32_t amoga = return_executee(linkActrPtr);

        //if (linkActrPtr->mEquipItem != 0x103 && shieldAttack) libtp::tp::d_a_alink::swordEquip(linkActrPtr, 0);

        if (amoga) {
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] == 0xff || (((linkActrPtr->mProcID > 9 || linkActrPtr->mProcID < 2) && (linkActrPtr->mProcID != 0x1e && linkActrPtr->mProcID != 0x1d && linkActrPtr->mProcID != 0x1f))/* && libtp::tp::d_a_player::checkNoResetFlg2(linkActrPtr, libtp::tp::d_a_player::FLG2_UNK_8000000) == 0*/)) {shieldAttack = false; shieldAttackReload = false; shieldReloading = 0;}
#ifdef PLATFORM_WII
            if (!depleted && (((linkActrPtr->mProcID >= 2 && linkActrPtr->mProcID <= 9) || linkActrPtr->mProcID == 0x1e || linkActrPtr->mProcID == 0x1d || linkActrPtr->mProcID == 0x1f))  && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake > 0.4f) && (shieldAttack == false || shieldAttackReload == false) && linkActrPtr->mGrabItemAcKeep.mActor == NULL && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] != 0xff)
#else
            if (!depleted && (((linkActrPtr->mProcID >= 2 && linkActrPtr->mProcID <= 9) || linkActrPtr->mProcID == 0x1e || linkActrPtr->mProcID == 0x1d || linkActrPtr->mProcID == 0x1f))  && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20) && (shieldAttack == false || shieldAttackReload == false) && linkActrPtr->mGrabItemAcKeep.mActor == NULL && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] != 0xff)
#endif
            {
                if (linkActrPtr->mEquipItem != 0x103) {
                    if (linkActrPtr->mEquipItem != 0xff)
                        libtp::tp::d_a_alink::deleteEquipItem(linkActrPtr, 0, 0);
                    float tempEquip = libtp::tp::d_a_alink::cutVars.mEquipAnm.mSpeed;
                    libtp::tp::d_a_alink::cutVars.mEquipAnm.mSpeed = 2.0f;
                    libtp::tp::d_a_alink::swordEquip(linkActrPtr, 1);
                    libtp::tp::d_a_alink::cutVars.mEquipAnm.mSpeed = tempEquip;
                    //libtp::tp::d_a_alink::setSwordModel(linkActrPtr);
                }
                //guardBattleAuthorized = true;
                //commenceGuardAttack(false);
                //libtp::tp::d_a_alink::procGuardAttackInit(linkActrPtr);
                shieldAttack = true; shieldAttackReload = true; shieldReloading = 0; RButtonPadding = 10; RButtonTime = true;
            }
#ifdef PLATFORM_WII
            else if (shieldAttack && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x800) && libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch))
#else
            else if (shieldAttack && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100) && libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch))
#endif
            {shieldAttack = false; shieldAttackReload = false; shieldReloading = 0;}
            if (shieldAttackReload) {
                shieldReloading++;
                if (shieldReloading == 25) {shieldReloading = 0; shieldAttackReload = false;}
            }
            /*if (libtp::tp::d_a_alink::getDirectionFromAngle(linkActrPtr, linkActrPtr->field_0x2fe2 - linkActrPtr->mCurrent.mAngle.y) == 0 && gameplayStatus) {
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockL && linkActrPtr->mEquipItem != 0x103 && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100) && libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch)) {shieldAttack = false; shieldAttackReload = false; manualShield(linkActrPtr, libtp::tp::d_a_alink::ANM_STEP_TURN); linkActrPtr->mLinkAcch.m_flags &= ~(1 << 5); libtp::tp::d_a_alink::procAutoJumpInit(linkActrPtr, 0);}
            }*/
        }
        return amoga;
    }

    int32_t Mod::cutnormalInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t parammm) {
        if (depleted) return 0;
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake > 0.2f && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].wiimote_shake > 0.2f) {
            shieldAttack = false; shieldAttackReload = false; shieldReloading = 0; RButtonPadding = 0; RButtonTime = false;
            libtp::tp::d_a_alink::procCutTurnInit(linkActrPtr, 0, 1); return 0;
        }
#endif
        shieldAttack = false;
        manualShield(linkActrPtr, libtp::tp::d_a_alink::ANM_STEP_TURN);
        return return_cutnormalInit(linkActrPtr, parammm);
    }

    int32_t Mod::guardBattle(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (guardBattleAuthorized && !depleted) {
            guardBattleAuthorized = false;
            return return_guardBattle(linkActrPtr);
        }
        return 0;
    }

    int32_t Mod::airCutInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t airCut) {
        shieldAttack = false;
        manualShield(linkActrPtr, libtp::tp::d_a_alink::ANM_STEP_TURN);
        if (anmCheck == libtp::tp::d_a_alink::ANM_COW_CATCH || !libtp::tp::d_bg_s_acch::ChkGroundHit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch) || libtp::tp::d_a_player::checkNoResetFlg0(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, libtp::tp::d_a_player::FLG0_UNDERWATER)) {
            return return_airCutInit(linkActrPtr, airCut);
        }

        const int32_t amonga = return_airCutInit(linkActrPtr, airCut);

        if (amonga) {
            libtp::tp::d_a_alink::procAutoJumpInit(linkActrPtr, 0);
        }
        return amonga;
    }

    bool timestartt = false;
    uint8_t padingTimer = 0;
    uint16_t newHealth;
    uint8_t healthCheck = 0;

    void Mod::UICheck(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDraw_c) {
        if (uiChecking == false) {
            #ifdef PLATFORM_WII
            libtp::patch::writeBranchBL(oxygenVisible + 0xE8, meterVisibility);
            #else
            libtp::patch::writeBranchBL(oxygenVisible + 0x11C, meterVisibility);
            #endif
            uiChecking = true;
        }
        if (healthCheck > 0) {
            healthCheck--;
            if (healthCheck == 0)
                libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth = newHealth;
        }
        return onUI(dMeterDraw_c);
    }

    void Mod::UICheck2(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) {
        if (uiChecking) {
            uiChecking = false;
            #ifdef PLATFORM_WII
            libtp::patch::writeBranchBL(oxygenVisible + 0xE8, meterVisibility);
            #else
            libtp::patch::writeBranchBL(oxygenVisible + 0x11C, meterVisibility);
            #endif
        }
        return offUI(dMeterDrawPtr);
    }

    libtp::tp::d_a_alink::daAlink_BckData* Mod::manualShield(libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID)
    {
//#ifndef PLATFORM_WII
        if (shieldAttack && i_anmID < 0x14 && libtp::tp::d_a_alink::checkUpperGuardAnime(linkActrPtr)) {
            return &libtp::tp::d_a_alink::m_mainBckShield[i_anmID];
        }
#ifdef PLATFORM_WII
        if ((i_anmID > 0x30 && i_anmID < 0x4e) || (i_anmID > 0x61 && i_anmID < 0xb6) || (i_anmID > 0xb7 && i_anmID < 0xc6) || (i_anmID > 0xc9 && i_anmID < 0xd9) || (linkActrPtr->mEquipItem == 0x103 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].wiimote_shake > 0.2f)) {shieldAttack = false; shieldAttackReload = false;}
#else
        if ((i_anmID > 0x30 && i_anmID < 0x4e) || (i_anmID > 0x61 && i_anmID < 0xb6) || (i_anmID > 0xb7 && i_anmID < 0xc6) || (i_anmID > 0xc9 && i_anmID < 0xd9) || (linkActrPtr->mEquipItem == 0x103 && libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x200)) {shieldAttack = false; shieldAttackReload = false;}
#endif
        if (linkActrPtr->mEquipItem == 0x103 && !shieldAttack) {
            if (i_anmID >= 0x12 && i_anmID < 0x15) return shieldManually(linkActrPtr, i_anmID);
            return &libtp::tp::d_a_alink::m_anmDataTable[i_anmID].field_0x0;
        }
/*#else
        if (libtp::tp::d_a_alink::checkUpperGuardAnime(linkActrPtr) && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00004000) == 0)
#endif
        {
            return &libtp::tp::d_a_alink::m_anmDataTable[i_anmID].field_0x0;
        }*/
        return shieldManually(linkActrPtr, i_anmID);
    }

    void Mod::unSheathingShield(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        /*if (shieldAttack || (linkActrPtr->mEquipItem == 0x103 && linkActrPtr->mProcID != 4 && swordUneqipMoment == false)) */ //return libtp::tp::d_a_player::onNoResetFlg2(linkActrPtr, libtp::tp::d_a_player::daPy_FLG2::FLG2_UNK_8000000);
        return libtp::tp::d_a_player::offNoResetFlg2(linkActrPtr, libtp::tp::d_a_player::daPy_FLG2::FLG2_UNK_8000000);
    }

    uint8_t somethingElse = 0;

    //Armors Quick-Toggle variables
    bool bomba = false;
    bool bamba = false;
#ifndef PLATFORM_WII
    uint8_t countyer = 0;
    uint8_t trimer = 0;
#endif
    uint8_t bombytimer = 0;
    libtp::tp::f_op_actor::fopAc_ac_c* id;
    libtp::tp::f_op_actor::fopAc_ac_c* id2;
    libtp::tp::f_op_actor::fopAc_ac_c* sussy2;
    uint8_t tiimer = 0;
    bool greenLight = false;
    bool rentingTime = false;

    void Mod::checkLinkStatus(libtp::tp::d_meter2::dMeter2_c* dMeter2Ptr) {
        //sprintf(sysConsolePtr->consoleLine[11].line, "mStatus & 0x40: %d", dMeter2Ptr->mStatus & 0x40);
        if ((dMeter2Ptr->mStatus & 0x40) == 0 && !gameplayStatus) gameplayStatus = true;
        else if ((dMeter2Ptr->mStatus & 0x40) != 0 && gameplayStatus) gameplayStatus = false;
#ifdef PLATFORM_WII
        if (updatedShield || (lastShield != 0xfe && bomba == false && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x00000002) && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0 && !rentingTime))
        {
            bamba = true;
        }
#else
        if (updatedShield || (bomba == false && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & libtp::tp::m_do_controller_pad::Button_DPad_Down) && countyer < 2 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0 && !rentingTime))

        {
            bamba = true;
            countyer++;
        }
#endif
        if (bamba) {
#ifndef PLATFORM_WII
            trimer++;
            if (trimer >= 15) {
#endif
                bamba = false;
                bomba = true;
                bombytimer = 0;
#ifndef PLATFORM_WII
                trimer = 0;
                if ((countyer == 1 && lastShield != 0xfe) || updatedShield) {
#endif
                    //libtp::tp::d_a_alink::setShieldChange(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
                    libtp::tp::m_Do_Audio::mDoAud_seStart(0x4f, 0, 0, 0);
                    //sprintf(sysConsolePtr->consoleLine[5].line, "%d", somethingElse);
                    if (shieldOn) {libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] = 0xff; shieldOn = false;} //libtp::tp::d_com_inf_game::setSelectEquipShield(0xff);}
                    else
                    {
                        if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(lastShield)) {
                            libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] = lastShield; shieldOn = true; //libtp::tp::d_com_inf_game::setSelectEquipShield(lastShield);
                        } /*else {
                            if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2a)) libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] = 0x2a;
                            else if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2b)) libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] = 0x2b;
                            else if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2c)) libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] = 0x2c;
                        }*/
                    }
                    if (updatedShield) {
                        updatedShield = false;
                        lastShield = 0xfe;
                    }
#ifndef PLATFORM_WII
                } else {
                    libtp::tp::d_a_alink::daAlink* actrReference = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer;
                    if (temporarPart2 != 0 && actrReference->mGrabItemAcKeep.mActor == NULL && gameplayStatus && uiChecking) {
                        if (libtp::tp::d_bg_s_acch::ChkGroundHit(&actrReference->mLinkAcch) || (temporarPart2 == 0x108 || temporarPart2 == 0x109)) {
                            cXyz create_pos = cXyzMultiply(cXyzAdd(actrReference->mLeftHandPos, actrReference->mRightHandPos), 0.5f);
                            // If stored actor is a cat, decrease the Y spawn position significantly to make cat touch ground and recalibrate on Link
                            if (temporarPart2 == 269) create_pos.y -= 80.0f;
                            sussy2 = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_fastCreate(temporarPart2, paramsGrab, &create_pos, -1, NULL, NULL, 0xff, NULL, NULL);
                            if (temporarPart2 == 0x108 || temporarPart2 == 0x109) {
                                if (!libtp::tp::d_bg_s_acch::ChkGroundHit(&actrReference->mLinkAcch) && !libtp::tp::d_bg_s_acch::ChkWaterIn(&actrReference->mLinkAcch)) {
                                    actrReference->mProcID = 0xA;
                                    libtp::tp::d_a_alink::procAutoJumpInit(actrReference, 0);
                                }
                            }
                            libtp::tp::d_a_alink::setGrabItemActor(actrReference, sussy2);
                            actrReference->field_0x33e4 = 38.0f;
                            libtp::tp::d_a_alink::setGrabUpperAnime(actrReference, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
                            temporarPart2 = 0;
                            paramsGrab = 0;
                            saveInfoPtr->objectStored = temporarPart2;
                            saveInfoPtr->objectParams = paramsGrab;
                            if (actrReference->mEquipItem != 0xff) libtp::tp::d_a_alink::deleteEquipItem(actrReference, 0, 0);
                        }
                    }
                }
                countyer = 0;
            }
#endif
        }
        if (bomba) {
            bombytimer++;
            if (bombytimer >= 20) {
                bomba = false;
                bombytimer = 0;
            }
        }
        if (greenLight == true) {
            tiimer++;
            if (tiimer == 20) {
                tiimer = 0;
                greenLight = false;
                cXyz actrPos;
                actrPos.x = 10000.0f; actrPos.y = -90000.0f; actrPos.z = 10000.0f;
                if ((libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_iter::fopAcIt_Judge(libtp::tp::f_op_actor_mng::fpcSch_JudgeForPName, &temporar) == NULL) {
                    id = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_create(temporar, 0, &actrPos, -1, NULL, NULL, 0xFF);
                }
                if (temporarPart2 != 0) {
                    if ((libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_iter::fopAcIt_Judge(libtp::tp::f_op_actor_mng::fpcSch_JudgeForPName, &temporarPart2) == NULL) {
                        id2 = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_create(temporarPart2, paramsGrab, &actrPos, -1, NULL, NULL, 0xFF);
                    }
                }
            }
        }
        if ((libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_iter::fopAcIt_Judge(libtp::tp::f_op_actor_mng::fpcSch_JudgeForPName, &temporar) == NULL || (temporarPart2 != 0 && (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_iter::fopAcIt_Judge(libtp::tp::f_op_actor_mng::fpcSch_JudgeForPName, &temporarPart2) == NULL)) {
            if (greenLight == false) {greenLight = true; tiimer = 0;}
        }
        return return_checkLinkStatus(dMeter2Ptr);
    }

   // __attribute__((used, visibility("default"))) void* Mod::dolbyMoment(void* dolbyDude, int16_t freeNitro) {
        //void* dolbyFreeTrial = return_dolbyMoment(dolbyDude, freeNitro);
        //libtp::tp::d_drawlist::dDlst_2D_c* dlist;
            //void* itemArchive = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mItemIconArchive;
            //if (!shieldIcon) {

                // Get the Ordon Shield Icon
                /*libtp::tp::JUTTexture::ResTIMG* oShield = (libtp::tp::JUTTexture::ResTIMG*)libtp::tp::d_resource::getRes("fileSel", 0x33, libtp::tp::d_com_inf_game::dComIfG_gameInfo.mResControl.mObjectInfo, 0x80);*/ 
                /*libtp::tp::JUTTexture::ResTIMG* oShield = (libtp::tp::JUTTexture::ResTIMG*)libtp::tp::JKRArchive::JKRArchive_getResource2(itemArchive,
                                                                        0x54494D47, // TIMG
                                                                        "ttdelunotate_s3_tc.bti");*/
                //libtp::tp::JUTTexture::ResTIMG* oShield = (libtp::tp::JUTTexture::ResTIMG*)libtp::tp::JKRArchive::readIdxResource(itemArchive, 0xC00, 0x33);
                // Get the Wooden Shield Icon
                //void* wShield = libtp::tp::JKRArchive::JKRArchive_getResource2(itemArchive,
                //                                                        0x54494D47, // TIMG
                //                                                        "ni_kinotate_48.bti");
                // Get the Hylian Shield Icon
                //void* hShield = libtp::tp::JKRArchive::JKRArchive_getResource2(itemArchive,
                 //                                                       0x54494D47, // TIMG
                 //                                                       "ni_hairianotate_48.bti");
                //if (oShield) dlist = new libtp::tp::d_drawlist::dDlst_2D_c(oShield, 28, 48, 128, 220, 200);
                //if (oShield) shieldIcon = new libtp::tp::J2DPicture::J2DPicture(oShield);
                //if (wShield) shieldIcon2 = new libtp::tp::J2DPicture::J2DPicture(wShield);
                //if (hShield) shieldIcon3 = new libtp::tp::J2DPicture::J2DPicture(hShield);
            //}
        //return dolbyFreeTrial;
    //}

    bool itemshopping[5];
    char bufferOrSmthgIdkIPreferPythonForStringsTbh[20];
    const char *shopSelections[5] = {"Wooden Shield", "Wooden Shield Upgrade", "Sacred Shield", "Repair Wooden Shield", "Repair Sacred Shield"};
    uint16_t rentingPrice[5] = {50, 100, 500, 10, 50};
    uint8_t itemHexValues[3] = {0x2b, 0x2a, 0x2c};
    int8_t nowLine = 0;
    int8_t java;

    void insertCustomMessage(libtp::tp::control::TControl* control, const void* TProcessor, uint16_t unk3, uint16_t msgID)
    {
        auto setMessageText = [=](const char* text)
        {
            if (text)
            {
                control->msg = text;
                control->wMsgRender = text;
            }
        };
        const void* unk = libtp::tp::processor::getResource_groupID(TProcessor, unk3);
        if (!unk) return;
        const void* currentInf1 = *reinterpret_cast<void**>(reinterpret_cast<uint32_t>(unk) + 0xC);

        if (currentInf1 == getZel00BmgInf())
        {

            uint16_t bowDescription = 0xbc0;

            if (msgID == bowDescription) {
                const char* newMessage;
                newMessage = "Your shield broke...";
                setMessageText(newMessage);
                return;
            }
        } else
        {
            auto checkForSpecificMsg =
                [=](uint32_t desiredMsgId, int32_t room, const char* stage, const void* currentInf1, const char* desiredFile)
            {
                // Check if the message ids are the same
                if (msgID != desiredMsgId)
                {
                    return false;
                }

                // Check if the stage and room are correct
                if (!libtp::tools::playerIsInRoomStage(room, stage))
                {
                    return false;
                }

                // Check if the desired file is being used
                return currentInf1 == getInf1Ptr(desiredFile);
            };

            constexpr uint32_t itemRevival = 0x658;
            if (checkForSpecificMsg(itemRevival, 1, "F_SP103", currentInf1, "zel_01.bmg")) {
                libtp::display::setConsoleColor(0, 0, 0, 180);
                for (uint8_t itm = 0x2a; itm < 0x2d; itm++) {
                    if (!libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(itm)) {
                        if (itm == 0x2a && libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2b)) itemshopping[1] = true;
                        else if (itm == 0x2b && !libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2a)) itemshopping[0] = true;
                        else if (itm == 0x2c) itemshopping[2] = true;
                    }
                } java = 7; sysConsolePtr->consoleLine[6].showLine = true;
                if (shieldWoodHealth < 255 && (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2b) || libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2a))) itemshopping[3] = true;
                if (shieldHylianHealth < 255 && libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x2c)) itemshopping[4] = true;
                for (uint8_t python = 0; python < 5; python++) {
                    if (itemshopping[python] == true) {strcpy( sysConsolePtr->consoleLine[java].line, shopSelections[python]); java++;}
                }
                if (java < 10) {
                    for (uint8_t varThatExist = java; varThatExist < 10; varThatExist++) strcpy(sysConsolePtr->consoleLine[varThatExist].line, "");
                }
                strcpy(bufferOrSmthgIdkIPreferPythonForStringsTbh, sysConsolePtr->consoleLine[7].line);
                sprintf(sysConsolePtr->consoleLine[7].line, "-> %s", bufferOrSmthgIdkIPreferPythonForStringsTbh);
                for (uint8_t pricePrinter = 0; pricePrinter < 5; pricePrinter++) {
                    if (strcmp(bufferOrSmthgIdkIPreferPythonForStringsTbh, shopSelections[pricePrinter]) == 0) {
                        sprintf(sysConsolePtr->consoleLine[6].line, "            Price: %d", rentingPrice[pricePrinter]); 
                        if (pricePrinter == 1 || pricePrinter == 2) isItEnough(pricePrinter-1);
                        else isItEnough(0xff);
                    }
                }
                isItEnough(4);

                nowLine = 7;
                rentingTime = true;
            }
        }
    }

    __attribute__((used, visibility("default"))) bool Mod::customMessageCode(libtp::tp::control::TControl* control, const void* TProcessor, uint16_t unk3, uint16_t msgID)
    {
        const bool ret = return_messageSmthg(control, TProcessor, unk3, msgID);

        if (ret) {
            insertCustomMessage(control, TProcessor, unk3, msgID);
        }
        return ret;
    }

    int32_t Mod::rollFront(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake <= 0.2f) && (linkActrPtr->mProcID < 0x15 || linkActrPtr->mProcID > 0x18))
#else
        if (!(libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20) && (linkActrPtr->mProcID < 0x15 || linkActrPtr->mProcID > 0x18))
#endif
        return 0;
        return return_rollFront(linkActrPtr);
    }

    bool brokeTheGuard = false;

    int32_t Mod::guardSlipped(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t abc, void* hi) {
        if (RButtonTime) {
            guardBattleAuthorized2 = true;
            commenceGuardAttack(true);
            libtp::tp::d_a_alink::procGuardAttackInit(linkActrPtr);
            return 0;
        }
        bool breakCheck = shieldDurability(libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] - 0x2a, false);

        if (breakCheck == false) {
            brokeTheGuard = true;
            libtp::tp::d_a_alink::procGuardBreakInit(linkActrPtr);
            return 0;
        }
        return return_guardSlipInit(linkActrPtr, abc, hi);
    }

    void Mod::equippingTheShield(uint8_t shieldID) {
            lastShield = shieldID;
            shieldOn = true;
        return shieldEquipped(shieldID);
    }

    int32_t Mod::swimWaiting(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x800)
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100)
#endif
            libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mDoStatus = 0x41;
        return return_swimWait(linkActrPtr);
    }

    int32_t Mod::swimMoving(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake > 0.2f && libtp::tp::d_bg_s_acch::ChkWaterIn(&linkActrPtr->mLinkAcch) && dashPadding == 0)
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20 && libtp::tp::d_bg_s_acch::ChkWaterIn(&linkActrPtr->mLinkAcch) && dashPadding == 0)
#endif
        {
            //*reinterpret_cast<uint32_t*>(greenClothesSwim4 + 0x6E4) = 0x2c1d00c6;
            //libtp::tp::d_a_alink::setSwimMoveAnime(linkActrPtr);
            dashPadding = 30;
            libtp::tp::d_a_player::onNoResetFlg1(linkActrPtr, libtp::tp::d_a_player::FLG1_DASH_MODE);
            linkActrPtr->field_0x30d0 = libtp::tp::d_a_alink::swimStuff.field_0x5c;
            libtp::tp::d_a_alink::setSingleAnimeParam(linkActrPtr, libtp::tp::d_a_alink::ANM_SWIM_DASH, &libtp::tp::d_a_alink::swimStuff.mDashAnm);
            staminaConsumption(75, false, false);
            linkActrPtr->field_0x3198 = 0xC8;
#ifdef PLATFORM_WII
            linkActrPtr->field_0x33d4 = 40.0f;
#else
            linkActrPtr->mNormalSpeed = 40.0f;
#endif
        }
        if (dashPadding > 0) {
            dashPadding--;
            libtp::tp::d_a_alink::cLib_addCalcAngleS(&linkActrPtr->field_0x3080, linkActrPtr->mProcVar3.field_0x300e.z, 5, 0x1000, 0x100);
            if (libtp::tp::d_bg_s_acch::ChkRoofHit(&linkActrPtr->mLinkAcch) || libtp::tp::d_bg_s_acch::ChkWallHit(&linkActrPtr->mLinkAcch)) {
                newHealth = libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth;
                cXyz create_pos = cXyzMultiply(cXyzAdd(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLeftHandPos, libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mRightHandPos), 0.5f);
                healthCheck = 2;
                if (dashPadding > 10) dashPadding = 10;
                libtp::tp::d_bomb::createWaterBombExplode(&create_pos);
            }
        }
        return return_swimMove(linkActrPtr);
    }

    int32_t Mod::waitingInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        /*if (depleted) {
            libtp::tp::d_a_alink::setTiredVoice(linkActrPtr, &linkActrPtr->mUpperFrameCtrl[2]);
            libtp::tp::d_a_alink::procTiredWaitInit(linkActrPtr);
            return 0;
        }*/
        if (libtp::tp::d_a_alink::checkAtnWaitAnime(linkActrPtr) && gameplayStatus) {
            libtp::tp::d_a_alink::procAtnActorWaitInit(linkActrPtr);
            return 0;
        }
        return return_waitInit(linkActrPtr);
    }

    int32_t Mod::atnWaitChecking(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if ((linkActrPtr->mEquipItem == 0x103 || (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x2000)) && !shieldAttack) return 1;
#else
        if ((linkActrPtr->mEquipItem == 0x103 || (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x40)) && !shieldAttack) return 1;
#endif
        return return_checkAtnWait(linkActrPtr);
    }

    int32_t Mod::upperGuardChecking(libtp::tp::d_a_alink::daAlink* linkActrPtr) {

        return shieldAttack == true && !libtp::tp::d_a_alink::checkEventRun(linkActrPtr) && 
        !libtp::tp::d_a_player::checkNoResetFlg0(linkActrPtr, libtp::tp::d_a_player::FLG0_UNK_2) && 
        linkActrPtr->mProcID != 0x1f && linkActrPtr->mProcID != 0x25 && linkActrPtr->mProcID != 0x1e;
    }

    bool Gliding = false;
    libtp::tp::f_op_actor::fopAc_ac_c* sussy;

    int32_t Mod::currentlyAutoJumping(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x400 && !libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch) && !libtp::tp::d_bg_s_acch::ChkWaterHit(&linkActrPtr->mLinkAcch))
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20 && !libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch) && !libtp::tp::d_bg_s_acch::ChkWaterHit(&linkActrPtr->mLinkAcch))
#endif
        {
#ifdef PLATFORM_WII
            if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x400 && gameplayStatus && linkActrPtr->mGrabItemAcKeep.mActor == NULL)
#else
            if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20 && gameplayStatus && linkActrPtr->mGrabItemAcKeep.mActor == NULL)
#endif
            {
                if (linkActrPtr->mEquipItem != 0xff) libtp::tp::d_a_alink::deleteEquipItem(linkActrPtr, 0, 0);
                cXyz create_pos = cXyzMultiply(cXyzAdd(linkActrPtr->mLeftHandPos, linkActrPtr->mRightHandPos), 0.5f);
                sussy = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_fastCreate(temporar, 0, &create_pos, -1, NULL, NULL, 0xff, NULL, NULL);
                libtp::tp::d_a_alink::setGrabItemActor(linkActrPtr, sussy);
                linkActrPtr->field_0x33e4 = 38.0f;
                libtp::tp::d_a_alink::setGrabUpperAnime(linkActrPtr, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
                linkActrPtr->mProcVar2.field_0x300c = 1;
                Gliding = true;
            }
#ifdef PLATFORM_WII
            if (linkActrPtr->field_0x33d4 != 0.0f) linkActrPtr->field_0x33d4 = 0.0f;
#else
            if (linkActrPtr->mNormalSpeed != 0.0f) linkActrPtr->mNormalSpeed = 0.0f;
#endif
        } else if (Gliding || !gameplayStatus) {
            Gliding = false;
            libtp::tp::f_op_actor_mng::fopAcM_delete(sussy);
        }
        return return_autoJumping(linkActrPtr);
    }

    int32_t Mod::currentlyFalling(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x400 && !libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch) && !libtp::tp::d_bg_s_acch::ChkWaterHit(&linkActrPtr->mLinkAcch))
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20 && !libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch) && !libtp::tp::d_bg_s_acch::ChkWaterHit(&linkActrPtr->mLinkAcch))
#endif
        {
#ifdef PLATFORM_WII
            if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x400 && gameplayStatus && linkActrPtr->mGrabItemAcKeep.mActor == NULL)
#else
            if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20 && gameplayStatus && linkActrPtr->mGrabItemAcKeep.mActor == NULL)
#endif
            {
                if (linkActrPtr->mEquipItem != 0xff) libtp::tp::d_a_alink::deleteEquipItem(linkActrPtr, 0, 0);
                cXyz create_pos = cXyzMultiply(cXyzAdd(linkActrPtr->mLeftHandPos, linkActrPtr->mRightHandPos), 0.5f);
                sussy = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_fastCreate(temporar, 0, &create_pos, -1, NULL, NULL, 0xff, NULL, NULL);
                libtp::tp::d_a_alink::setGrabItemActor(linkActrPtr, sussy);
                linkActrPtr->field_0x33e4 = 38.0f;
                libtp::tp::d_a_alink::setGrabUpperAnime(linkActrPtr, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
                linkActrPtr->field_0x594 = libtp::tp::d_a_alink::jumpStuff.m.mCuccoJumpMaxSpeed;
                int16_t angleee = libtp::tp::d_a_alink::jumpStuff.m.mCuccoJumpAngle;
                linkActrPtr->field_0x3478 = libtp::tp::d_a_alink::jumpStuff.m.mCuccoFallMaxSpeed;
#ifdef PLATFORM_WII
                linkActrPtr->mSpeed.y = linkActrPtr->field_0x33d4 * libtp::tp::sincosTable_.table[(uint16_t)angleee >> (16U)].first;
                linkActrPtr->field_0x33d4 = libtp::tp::d_a_alink::jumpStuff.m.mCuccoStartSpeed;
#else
                linkActrPtr->mSpeed.y = linkActrPtr->mNormalSpeed * libtp::tp::sincosTable_.table[(uint16_t)angleee >> (16U)].first;
                linkActrPtr->mNormalSpeed = libtp::tp::d_a_alink::jumpStuff.m.mCuccoStartSpeed;
#endif
                Gliding = true;
                libtp::tp::d_a_alink::procAutoJumpInit(linkActrPtr, 0);
                return 0;

            }
        }
        return return_falling(linkActrPtr);
    }

    int32_t Mod::guardIsBreaking(libtp::tp::d_a_alink::daAlink* linkActrPtr) {

        const int32_t guardWhere = return_breakingGuard(linkActrPtr);

        if (guardWhere) {
            if (brokeTheGuard == false && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] != 0xff) {
                shieldDurability(libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] - 0x2a, true);
            }
            brokeTheGuard = false;
        }
        return guardWhere;
    }

    int32_t Mod::cutSpinInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aa, int32_t bb) {
        if (depleted) return 0;
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake > 0.2f && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].wiimote_shake > 0.2f)
        {
            staminaConsumption(150, true, false);
            return return_cutSpinInit(linkActrPtr, aa, bb);
        }
        return 0;
#else
        staminaConsumption(150, true, false);
        return return_cutSpinInit(linkActrPtr, aa, bb);
#endif
    }

    int32_t Mod::cutSpinChargeInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) return 0;
        linkActrPtr->mProcVar0.field_0x3008 = 14;
        return return_cutSpinChargeInit(linkActrPtr);
    }

    int32_t Mod::cutFinishInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t cutOfType) {
        if (depleted) return 0;
        if (linkActrPtr->mProcID == 0x21) return 0;

        const int32_t cutThecut = return_cutFinishInit(linkActrPtr, cutOfType);

        if (cutThecut) {
#ifdef PLATFORM_WII
            if (linkActrPtr->unk_field0[2] == 0x1A || linkActrPtr->unk_field0[2] == 0x1F)
#else
            if (linkActrPtr->mCutType == 0x1A || linkActrPtr->mCutType == 0x1F)
#endif
            {
                staminaConsumption(300, true, false);
            }
        }
        return cutThecut;
    }

    int32_t Mod::cutLargeJumpChargeInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) return 0;
        linkActrPtr->mProcVar0.field_0x3008 = 14;
        return return_cutLargeJumpChargeInit(linkActrPtr);
    }

    int32_t Mod::cutLargeJumpInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        staminaConsumption(225, true, false);
        return return_cutLargeJumpInit(linkActrPtr);
    }

    int32_t Mod::cutJumpUpInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted || libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[1] == 0xff) return 0;

        const int32_t jumpingUpInit = return_cutJumpUpInit(linkActrPtr);
        if (jumpingUpInit) {
#ifdef PLATFORM_WII
            if (linkActrPtr->unk_field0[2] == 0x1E)
#else
            if (linkActrPtr->mCutType == 0x1E)
#endif
            {
                staminaConsumption(150, true, false);
            }
        }
        return jumpingUpInit;
    }

    int32_t Mod::cutHeadInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) return 0;

        const int32_t helmSplit = return_cutHeadInit(linkActrPtr);

        if (helmSplit) {
#ifdef PLATFORM_WII
            if (linkActrPtr->unk_field0[2] == 5)
#else
            if (linkActrPtr->mCutType == 5)
#endif
            {
                staminaConsumption(225, true, false);
            }
        }
        return helmSplit;
    }

    int32_t Mod::sideSteppingInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aaaaaaaaaa) {
        if (depleted) return 0;
        return return_sideStepInit(linkActrPtr, aaaaaaaaaa);
    }

    int32_t Mod::atnMoving(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {
            if (libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr)) {libtp::tp::d_a_alink::procWaitInit(linkActrPtr); return 0;}
#ifdef PLATFORM_WII
            if (linkActrPtr->field_0x33d4 > 0.5f) linkActrPtr->field_0x33d4 = 0.0f;
#else
            if (linkActrPtr->mNormalSpeed > 0.5f) linkActrPtr->mNormalSpeed = 0.0f;
#endif
        }
#ifdef PLATFORM_WII
        if (gameplayStatus && libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr) && !libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mShow2D)
#else
        if (gameplayStatus && libtp::tp::d_a_player::checkEquipHeavyBoots(linkActrPtr) && !libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygenShowFlag)
#endif
        {
            staminaConsumption(1, false, true);
            tiredSounds(1);
        }
        return return_atnMove(linkActrPtr);
    }

    int32_t Mod::backJumpingInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) {
        if (depleted) return 0;
        return return_backJumpInit(linkActrPtr, smthgSmthg);
    }

    int32_t Mod::atnActrMve(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {
#ifdef PLATFORM_WII
            if (linkActrPtr->field_0x33d4 > 0.5f) linkActrPtr->field_0x33d4 = 0.5f;
#else
            if (linkActrPtr->mNormalSpeed > 0.5f) linkActrPtr->mNormalSpeed = 0.5f;
#endif
        }
        return return_atnActrMve(linkActrPtr);
    }

    int32_t Mod::returningTheIron(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen <= 0) {
            int32_t healthMii = libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth;
            if (healthMii - 8 < 0) healthMii = 0;
            else healthMii -= 8;
            libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth = healthMii;
        } else {
            staminaConsumption(50, false, false);
        }
        return ironReturning(linkActrPtr);
    }

    int32_t Mod::representingTheIron(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        staminaConsumption(7, false, true);
        return ironRepresentative(linkActrPtr);
    }

    int32_t Mod::ironThrower(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        staminaConsumption(225, false, false);
        return throwIron(linkActrPtr);
    }

    int32_t Mod::climbMoveUpDownInitialize(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) {
        if (depleted) {libtp::tp::d_a_alink::procFallInit(linkActrPtr, 2, 1.0f); return 0;}
        return return_climbMoveUpDownInit(linkActrPtr, smthgSmthg);
    }

    int32_t Mod::climbMoveSideInitialize(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {libtp::tp::d_a_alink::procFallInit(linkActrPtr, 2, 1.0f); return 0;}
        return return_climbMoveSideInit(linkActrPtr);
    }

    int32_t Mod::climbWait(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {libtp::tp::d_a_alink::procFallInit(linkActrPtr, 2, 1.0f); return 0;}
        return return_climbWait(linkActrPtr);
    }

    int32_t Mod::climbUpStartInitialize(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgSmthg) {
        if (depleted) return 0;
        return return_climbUpStartInit(linkActrPtr, smthgSmthg);
    }

    int32_t Mod::yoHangWait(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {libtp::tp::d_a_alink::procFallInit(linkActrPtr, 2, 1.0f); return 0;}
        staminaConsumption(2, false, true);
        return return_hangWait(linkActrPtr);
    }

    bool buttonHolding = false;
    bool buttonHolding2 = false;

    int32_t Mod::yoHangMove(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {libtp::tp::d_a_alink::procFallInit(linkActrPtr, 2, 1.0f); return 0;}
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x4000)
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20)
#endif
        {
            staminaConsumption(4, false, true);
            if (!buttonHolding) {buttonHolding = true; increaseClimbSpeed(true);}
        }
#ifdef PLATFORM_WII
        else if (!(libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x4000))
#else
        else if (!(libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20))
#endif
        {
            staminaConsumption(2, false, true);
            if (buttonHolding) {buttonHolding = false; increaseClimbSpeed(true);}
        }
        //staminaConsumption(4, false, true);
        return return_hangMove(linkActrPtr);
    }

    int32_t Mod::yoHangFallStart(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) {libtp::tp::d_a_alink::procFallInit(linkActrPtr, 2, 1.0f); return 0;}
        staminaConsumption(2, false, false);
        return return_hangFallStart(linkActrPtr);
    }

    int32_t Mod::restCheckPlease(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) return 1;
        return return_checkRestHP(linkActrPtr);
    }

    bool throwInit = false;

    int32_t Mod::grabThrowerInitialized(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t somethingSmthg) {
        //if (somethingSmthg == 1) staminaConsumption(75, false);
        //sprintf(sysConsolePtr->consoleLine[0].line, "throwParam: %d", somethingSmthg);
        throwInit = true;
        return return_grabThrowInit(linkActrPtr, somethingSmthg);
    }

    int32_t Mod::grabReadyInitialized(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) return 0;
        return return_grabReadyInit(linkActrPtr);
    }

    int32_t Mod::moveLadderPlease(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (depleted) return 0;
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x4000)
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20)
#endif
        {
            staminaConsumption(2, false, true);
            if (!buttonHolding) {buttonHolding = true; increaseClimbSpeed(true);}
        }
        else {
            if (buttonHolding) {buttonHolding = false; increaseClimbSpeed(true);}
        }
        return return_ladderMove(linkActrPtr);
    }

    int32_t Mod::sideRollChecking(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t sideRollThing) {
        const int32_t sideRollHereWeGo = return_sideRollCheck(linkActrPtr, sideRollThing);

        if (sideRollHereWeGo) {
            if (linkActrPtr->mProcID == 0x11 || linkActrPtr->mProcID == 0x20) {
                staminaConsumption(75, false, false);
            }
        }
        return sideRollHereWeGo;
    }

    int32_t Mod::crawlMovementContinue(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x800 && !depleted)
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x100 && !depleted)
#endif
        {
            staminaConsumption(4, false, true);
            if (!buttonHolding2) {buttonHolding2 = true; increaseClimbSpeed(false);}
        }
        else {
            if (buttonHolding2) {buttonHolding2 = false; increaseClimbSpeed(false);}
        }
        return return_crawlMovement(linkActrPtr);
    }

    //uint32_t tiredMomentInit = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procTiredWaitInit);
    //uint32_t tiredMoment = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procTiredWait);
    uint8_t swimPadddddddding = 10;
    bool putAwayMoment = false;
    bool underwaterCherryPicking = false;

    void Mod::oxygenAndStamina(libtp::tp::d_meter2::dMeter2_c* dMeterPtr) {
        bool draw_oxygen;
#ifdef PLATFORM_WII
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mShow2D)
#else
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygenShowFlag) //{
#endif
            /*if */ 
            {
                if (uiChecking && gameplayStatus && libtp::tp::d_bg_s_acch::ChkWaterIn(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch))
                {
                    swimPadddddddding--; 
                    if (swimPadddddddding == 0) {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > 0)
                        {libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen -= 5; swimPadddddddding = 10;}
                        else {
                            libtp::tp::m_Do_Audio::mDoAud_seStart(0x4001C, 0, 0, 0);
                            uint16_t healthGoodOrBad = libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth;
                            if (healthGoodOrBad - 4 >= 0) healthGoodOrBad -= 4;
                            else healthGoodOrBad = 0;
                            libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth = healthGoodOrBad;
                            swimPadddddddding = 45;
                        }
                    }
                    if (!libtp::tp::d_a_player::checkEquipHeavyBoots(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer)) {
                        dMeterPtr->mNowOxygen = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen;
                        libtp::tp::d_meter2_draw::drawOxygen(dMeterPtr->mpMeterDraw, dMeterPtr->mMaxOxygen, dMeterPtr->mNowOxygen, libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosX, libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosY);
                        libtp::tp::d_meter2::alphaAnimeOxygen(dMeterPtr);
                        return;
                    }
                    else {
                        underwaterCherryPicking = true;
                        draw_oxygen = true;
                        rollFuel = sprintFuel = false;
                    }
                }
            }
        //}
        libtp::tp::d_a_alink::daAlink* actrReference = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer;
        if (putAwayMoment) {
            putAwayMoment = false;
            libtp::tp::d_a_alink::setUpperAnime(actrReference, 0x245, libtp::tp::d_a_alink::daAlink_UPPER::UPPER_2, libtp::tp::d_a_alink::itemVars.mTwoHandReleaseAnmSpeed, libtp::tp::d_a_alink::itemVars.mTwoHandEquipAnm.mStartFrame, libtp::tp::d_a_alink::itemVars.mTwoHandEquipAnm.mEndFrame, libtp::tp::d_a_alink::itemVars.mTwoHandEquipAnm.mInterpolation);
        }
        if (sprintFuel) {
            sprintFuel = false;
            staminaConsumption(5, false, true);
            tiredSounds(2);
        }
        else if (rollFuel) {
            rollFuel = false;
            staminaConsumption(75, false, false);
        }

        else if (actrReference->mEquipItem == 0x42 && actrReference->mProcID < 0xD8) {
            staminaConsumption(2, false, true);
            tiredSounds(1);
        }

        else if (actrReference->mProcID > 0x80 && actrReference->mProcID < 0x85) {
            if (actrReference->mProcID == 0x82 || actrReference->mProcID == 0x83) {
#ifdef PLATFORM_WII
                if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x4000)
#else
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20)
#endif
                {
                    staminaConsumption(2, false, true);
                    if (!buttonHolding) {buttonHolding = true; increaseClimbSpeed(true);}
                } else {
                    staminaConsumption(1, false, true);
                    if (buttonHolding) {buttonHolding = false; increaseClimbSpeed(true);}
                }
            } else {
                staminaConsumption(1, false, true);
            }
            tiredSounds(2);
        }

        else {
            if (actrReference->mGrabItemAcKeep.mActor != NULL) {
#ifdef PLATFORM_WII
                if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x4000 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x2000)
#else
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x20)
#endif
                {
                    if (temporarPart2 == 0 && libtp::tp::d_bg_s_acch::ChkGroundHit(&actrReference->mLinkAcch)) {
                        temporarPart2 = actrReference->mGrabItemAcKeep.mActor->mProcName;
                        if (libtp::tp::d_bomb::checkWaterBomb(actrReference->mGrabItemAcKeep.mActor)) paramsGrab = 9;
                        else paramsGrab = actrReference->mGrabItemAcKeep.mActor->mParameters;
                        if (temporarPart2 == 0x2FC) {
                            temporarPart2 = 0; paramsGrab = 0;
                        }
                        else {
                            libtp::tp::f_op_actor_mng::fopAcM_delete(actrReference->mGrabItemAcKeep.mActor);/*}*/
                            putAwayMoment = true;
                        }
                        saveInfoPtr->objectStored = temporarPart2; saveInfoPtr->objectParams = paramsGrab;
                    }
                }
                if ((actrReference->mGrabItemAcKeep.mActor->mProcName == 0x2FD && actrReference->mGrabItemAcKeep.mActor->mCarryType == 18) || (actrReference->mGrabItemAcKeep.mActor->mProcName == 0x2FC && (actrReference->mGrabItemAcKeep.mActor->mCarryType == 1 || actrReference->mGrabItemAcKeep.mActor->mCarryType == 2)) || (actrReference->mGrabItemAcKeep.mActor->mProcName == 0x198 && actrReference->mGrabItemAcKeep.mActor->mCarryType == 2)) {
                    staminaConsumption(2, false, true);
                    tiredSounds(2);
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen < 0) libtp::tp::d_a_alink::procGrabPutInit(actrReference);
                    if (actrReference->mProcID == 111 && throwInit) {staminaConsumption(75, false, false); throwInit = false;}
                }
            }
#ifdef PLATFORM_WII
            else if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x4000 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x2000) {
                if (temporarPart2 != 0 && gameplayStatus && uiChecking) {
                    if (libtp::tp::d_bg_s_acch::ChkGroundHit(&actrReference->mLinkAcch) || (temporarPart2 == 0x108 || temporarPart2 == 0x109)) {
                        cXyz create_pos = cXyzMultiply(cXyzAdd(actrReference->mLeftHandPos, actrReference->mRightHandPos), 0.5f);
                        sussy2 = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_fastCreate(temporarPart2, paramsGrab, &create_pos, -1, NULL, NULL, 0xff, NULL, NULL);
                        if (temporarPart2 == 0x108 || temporarPart2 == 0x109) {
                            if (!libtp::tp::d_bg_s_acch::ChkGroundHit(&actrReference->mLinkAcch) && !libtp::tp::d_bg_s_acch::ChkWaterIn(&actrReference->mLinkAcch)) {
                                actrReference->mProcID = 0xA;
                                libtp::tp::d_a_alink::procAutoJumpInit(actrReference, 0);
                            }
                        }
                        libtp::tp::d_a_alink::setGrabItemActor(actrReference, sussy2);
                        actrReference->field_0x33e4 = 38.0f;
                        libtp::tp::d_a_alink::setGrabUpperAnime(actrReference, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
                        temporarPart2 = 0;
                        paramsGrab = 0;
                        saveInfoPtr->objectStored = temporarPart2;
                        saveInfoPtr->objectParams = paramsGrab;
                        if (actrReference->mEquipItem != 0xff) libtp::tp::d_a_alink::deleteEquipItem(actrReference, 0, 0);
                    }
                }
            }
#endif
        }

        if (!underwaterCherryPicking) {
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen < 0) {
                libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen = 0;
                timeMove = 30;
                timeMoveStart = true;
                outlineR = 0xAF;
                outlineG = 0x22;
                outlineB = 0;
                outlineA = 100;
                depleted = true;
                //*reinterpret_cast<uint32_t*>(tiredMomentInit + tiredinitial) = tiredinitialVanilla;
                //libtp::patch::writeBranch(tiredMoment + 0x38, tiredMoment + 0x3C);
            }
            if (uiChecking && !(dMeterPtr->mStatus & 0x40)) {
                if (timeMoveStart) {
                    timeMove--;
                    if (timeMove == 0) {timeMoveStart = false; specialEffect = 0; specialEffectOn = true;}
                } else if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen < libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID != 218 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID != 219) {
#ifdef PLATFORM_WII
                    if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x2000 && !depleted) libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen += 3;
#else
                    if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockL && !depleted) libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen += 3;
#endif
                    else libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen += 5;
                    if (!depleted) tiredSounds(0);
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen > libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen) libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mMaxOxygen;
                } else if (depleted) {
                    outlineR = 0; outlineB = 69;
                    depleted = false;
                    //*reinterpret_cast<uint32_t*>(tiredMomentInit + tiredinitial) = tiredinitialVanilla-1;
                    //*reinterpret_cast<uint32_t*>(tiredMoment + 0x38) = 0x41820014;
                }
            }
        }

        if (dMeterPtr->field_0x248 != dMeterPtr->mMaxLife) {
            dMeterPtr->field_0x248 = dMeterPtr->mMaxLife;
            draw_oxygen = true;
        }

        if (dMeterPtr->mOxygenMeterScale != libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterScale) {
            dMeterPtr->mOxygenMeterScale = libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterScale;
            draw_oxygen = true;
        }

        if (dMeterPtr->mOxygenMeterPosX != libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosX) {
            dMeterPtr->mOxygenMeterPosX = libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosX;
            draw_oxygen = true;
        }

        if (dMeterPtr->mOxygenMeterPosY != libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosY) {
            dMeterPtr->mOxygenMeterPosY = libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosY;
            draw_oxygen = true;
        }

        if (draw_oxygen == true) {
            dMeterPtr->mNowOxygen = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mOxygen;
            libtp::tp::d_meter2_draw::drawOxygen(dMeterPtr->mpMeterDraw, dMeterPtr->mMaxOxygen, dMeterPtr->mNowOxygen, libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosX, libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosY);
            if (underwaterCherryPicking) underwaterCherryPicking = false;
        }
        libtp::tp::d_meter2::alphaAnimeOxygen(dMeterPtr);
    }

    void Mod::rentAnItem() {
        //if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x200) libtp::tp::d_a_alink::makeArrow(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
        if (rentingTime) {
#ifdef PLATFORM_WII
            if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x4) && nowLine < java-1)
#else
            if ((libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x4) && nowLine < java-1)
#endif
            {
                strcpy(sysConsolePtr->consoleLine[nowLine].line, bufferOrSmthgIdkIPreferPythonForStringsTbh);
                strcpy(bufferOrSmthgIdkIPreferPythonForStringsTbh, sysConsolePtr->consoleLine[nowLine+1].line);
                //strcat(sysConsolePtr->consoleLine[nowLine+1].line, "-> ", bufferOrSmthgIdkIPreferPythonForStringsTbh)
                sprintf(sysConsolePtr->consoleLine[nowLine+1].line, "-> %s", bufferOrSmthgIdkIPreferPythonForStringsTbh);
                libtp::tp::m_Do_Audio::mDoAud_seStart(0xA1, 0, 0, 0);
                for (uint8_t pricePrinter = 0; pricePrinter < 5; pricePrinter++) {
                    if (strcmp(bufferOrSmthgIdkIPreferPythonForStringsTbh, shopSelections[pricePrinter]) == 0) {
                        sprintf(sysConsolePtr->consoleLine[6].line, "            Price: %d", rentingPrice[pricePrinter]); 
                        if (pricePrinter == 1 || pricePrinter == 2) isItEnough(pricePrinter-1);
                        else isItEnough(0xff);
                    }
                }
                nowLine++;
            }
#ifdef PLATFORM_WII
            else if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x8) && nowLine > 7)
#else
            else if ((libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x8) && nowLine > 7)
#endif
            {
                strcpy(sysConsolePtr->consoleLine[nowLine].line, bufferOrSmthgIdkIPreferPythonForStringsTbh);
                strcpy(bufferOrSmthgIdkIPreferPythonForStringsTbh, sysConsolePtr->consoleLine[nowLine-1].line);
                sprintf(sysConsolePtr->consoleLine[nowLine-1].line, "-> %s", bufferOrSmthgIdkIPreferPythonForStringsTbh);
                libtp::tp::m_Do_Audio::mDoAud_seStart(0xA1, 0, 0, 0);
                for (uint8_t pricePrinter = 0; pricePrinter < 5; pricePrinter++) {
                    if (strcmp(bufferOrSmthgIdkIPreferPythonForStringsTbh, shopSelections[pricePrinter]) == 0) {
                        sprintf(sysConsolePtr->consoleLine[6].line, "            Price: %d", rentingPrice[pricePrinter]); 
                        if (pricePrinter == 1 || pricePrinter == 2) isItEnough(pricePrinter-1);
                        else isItEnough(0xff);
                    }
                }
                nowLine--;
            }
#ifdef PLATFORM_WII
            if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x800) || (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x400))
#else
            if ((libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100) || (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x200))
#endif
            {
#ifdef PLATFORM_WII
                if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x800)
#else
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100)
#endif
                {
                    /*for (int somethingsomething = 0; somethingsomething < 12; somethingsomething++) {
                        if (bufferOrSmthgIdkIPreferPythonForStringsTbh == shopSelections[somethingsomething] && )
                    }*/
                    //bool acquiredItem = false;
                    bool didYouGetIt = false;
                    for (uint8_t rentAffect = 0; rentAffect < 5; rentAffect++) {
                        if (strcmp(bufferOrSmthgIdkIPreferPythonForStringsTbh, shopSelections[rentAffect]) == 0 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees >= rentingPrice[rentAffect])
                        {
                            if (rentAffect == 1 || rentAffect == 2) {
                                bool checkItPlease;
                                if (rentAffect == 2)
                                    checkItPlease = isItEnough(2);
                                else if (rentAffect == 1) checkItPlease = isItEnough(3);
                                if (checkItPlease) didYouGetIt = true;
                            } else didYouGetIt = true;

                            if (didYouGetIt) {
                                libtp::tp::m_Do_Audio::mDoAud_seStart(0x18, 0, 0, 0);
//#ifdef PLATFORM_WII
//                                if (rentAffect < 3) {if (rentAffect == 1) {libtp::patch::writeBranchBL(linkExecute + shieldBurn1, shieldBurn); libtp::patch::writeBranch(linkExecute + shieldBurn1+4, linkExecute + shieldBurn1Jump); updatedShield = true; libtp::tp::d_save::offFirstBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_get_item, 0x2b);} libtp::tp::d_item::execItemGet(itemHexValues[rentAffect]);}
//#else
                                if (rentAffect < 3) {if (rentAffect == 1) {libtp::patch::writeBranchBL(linkExecute + shieldBurn1, shieldBurn); libtp::patch::writeBranch(linkExecute + shieldBurn1+4, linkExecute + shieldBurn1Jump); updatedShield = true; libtp::tp::d_save::offFirstBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_get_item, 0x2b);} libtp::tp::d_item::execItemGet(itemHexValues[rentAffect]);}
//#endif
                                if (rentAffect < 2 || rentAffect == 3) saveInfoPtr->woodShieldDurability = shieldWoodHealth = 255;
                                else if (rentAffect == 2 || rentAffect == 4) saveInfoPtr->hylianShieldDurability = shieldHylianHealth = 255;
                                libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees -= rentingPrice[rentAffect];
                            } else libtp::tp::m_Do_Audio::mDoAud_seStart(0x4A, 0, 0, 0);
                        }
                    }
                    if (didYouGetIt == false) libtp::tp::m_Do_Audio::mDoAud_seStart(0x4A, 0, 0, 0);
                }
                libtp::display::setConsoleColor(0, 0, 0, 0);
                strcpy(bufferOrSmthgIdkIPreferPythonForStringsTbh, "");
                //sysConsolePtr->consoleLine[java].showLine = true;
                sysConsolePtr->consoleLine[6].showLine = false;
                rentingTime = false;

                for (uint8_t thingything = 0; thingything < 5; thingything++) itemshopping[thingything] = false;
            }
        }
        return itemRent();
    }
}     // namespace mod
