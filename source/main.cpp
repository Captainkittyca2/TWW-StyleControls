/**
 * @file main.cpp
 * @author Captain Kitty Cat (youtube.com/@captainkittyca2)
 * @brief
 * @version 0.2
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <display/console.h>     // Contains a very neat helper class to print to the console
#include <main.h>
#include <patch.h>     // Contains code for hooking into a function
#include <tp/f_ap_game.h>
#include <tp/f_op_actor_mng.h>
#include <tp/d_a_alink.h>
#include <tp/d_meter2.h>
#include <tp/d_com_inf_game.h>
#include <tp/d_bg_s_acch.h>
#include <tp/m_do_audio.h>
#include <tp/d_menu_window.h>
#include <JSystem/JMath/JMATrigonometric.h>
#include <tp/f_op_actor_iter.h>

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

    int32_t DownNope() {
        return false;
    }

    int32_t DiveNope(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        (void)linkActrPtr;
        return 0;
    }

    bool shieldCrouch = false;
    bool crawlCrouch = false;
    uint8_t crouch = 0;

    int32_t crouchStuff(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (!libtp::tp::d_a_alink::commonProcInitNotSameProc(linkActrPtr, libtp::tp::d_a_alink::PROC_CROUCH)) return 0;

        if (crouch == 1) libtp::tp::d_a_alink::setSingleAnimeBaseSpeed(linkActrPtr, libtp::tp::d_a_alink::ANM_CROUCH_DEF, libtp::tp::d_a_alink::crouchVars.mCrouchAnmSpeed,
                                                    libtp::tp::d_a_alink::crouchVars.mCrouchInterpolation);
        else {
            if (linkActrPtr->mEquipItem != 0xFF && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[2] != 0xFF) {
                shieldCrouch = true; libtp::tp::d_a_alink::setSingleAnimeBaseSpeed(linkActrPtr, libtp::tp::d_a_alink::ANM_CROUCH_START, libtp::tp::d_a_alink::crouchVars.mCrouchAnmSpeed,
                                                    libtp::tp::d_a_alink::crouchVars.mCrouchInterpolation);}
            else {libtp::tp::d_a_alink::setSingleAnimeBaseSpeed(linkActrPtr, libtp::tp::d_a_alink::ANM_CROUCH, libtp::tp::d_a_alink::crouchVars.mCrouchAnmSpeed,
                                                    libtp::tp::d_a_alink::crouchVars.mCrouchInterpolation);}
        }
        linkActrPtr->mCurrent.mAngle.y = linkActrPtr->mCollisionRot.y;
        return 1;
    }

    bool grabRemember = false;
    bool cuccoWait = false;
    libtp::tp::f_op_actor::fopAc_ac_c* sussy;

#ifndef PLATFORM_WII
    int32_t RButtonThingy(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR && linkActrPtr->mEquipItem != 0x40)
            return libtp::tp::d_a_alink::itemTriggerCheck(linkActrPtr, 8);
        else if (linkActrPtr->mEquipItem == 0x40)
            return libtp::tp::d_a_alink::itemTriggerCheck(linkActrPtr, 0x40);
        return false;
    }

    int32_t BButtonThingy(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR == 0)
            return libtp::tp::d_a_alink::itemTriggerCheck(linkActrPtr, 8);
        return false;
    }
#endif

    void Mod::init()
    {
        libtp::display::setConsole(false, 25);

        gMod = this;
        return_fapGm_Execute =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::getMainBckData, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID) { return gMod->manualShield(linkActrPtr, i_anmID); } );

        unSheathShield =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::setShieldGuard, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->unSheathingShield(linkActrPtr); } );

        cuccoMoment =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::setItemActor, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cuccoCheckMoment(linkActrPtr); } );

        healthUIOn =
            libtp::patch::hookFunction( libtp::tp::d_meter2_draw::setAlphaLifeAnimeMax, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->UICheck(dMeterDrawPtr); } );
        
        libtp::patch::hookFunction( libtp::tp::d_menu_window::dMw_DOWN_TRIGGER, DownNope);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::procDiveJumpInit, DiveNope);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrouchInit, crouchStuff);
#ifndef PLATFORM_WII
        libtp::patch::hookFunction( libtp::tp::d_a_alink::spActionTrigger, RButtonThingy);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::swordSwingTrigger, BButtonThingy);
#endif
    }

    libtp::tp::d_a_alink::daAlink_BckData* Mod::manualShield(libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID)
    {
#ifndef PLATFORM_WII
        if (libtp::tp::d_a_alink::checkUpperGuardAnime(linkActrPtr) && libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR == 0)
#else
        if (libtp::tp::d_a_alink::checkUpperGuardAnime(linkActrPtr) && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00004000) == 0)
#endif
        {
            return &libtp::tp::d_a_alink::m_anmDataTable[i_anmID].field_0x0;
        }
        return return_fapGm_Execute(linkActrPtr, i_anmID);
    }

    void Mod::unSheathingShield(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifndef PLATFORM_WII

        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR == 0)
#else
        if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00004000) == 0 && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00000004) == 0)
#endif
        {
            return libtp::tp::d_a_player::offNoResetFlg2(linkActrPtr, libtp::tp::d_a_player::daPy_FLG2::FLG2_UNK_8000000);
        }
        else if (shieldCrouch) return libtp::tp::d_a_player::onNoResetFlg2(linkActrPtr, libtp::tp::d_a_player::daPy_FLG2::FLG2_UNK_8000000);
        return unSheathShield(linkActrPtr);
    }

#if defined(TP_WUS0) || defined(TP_WEU)
    int16_t temporar = 0x106;
#else
    int16_t temporar = 0x108;
#endif

    bool Mod::cuccoCheckMoment(libtp::tp::d_a_alink::daAlink* linkActrPtr) {

        if (libtp::tp::d_a_player::checkBombItem(linkActrPtr->mEquipItem)) {
            if (libtp::tp::d_a_alink::checkHorseRide(linkActrPtr)) {
                return cuccoMoment(linkActrPtr);
            }
            cXyz create_pos = cXyzMultiply(cXyzAdd(linkActrPtr->mLeftHandPos, linkActrPtr->mRightHandPos), 0.5f);
#ifdef PLATFORM_WII
            if (linkActrPtr->mEquipItem != 0xFF && libtp::tp::d_com_inf_game::dComIfGp_getSelectItem(linkActrPtr->mSelectItemId) && cuccoWait == false)
#else
            if (libtp::tp::d_a_alink::checkReadyItem(linkActrPtr) && cuccoWait == false)
#endif
            {
                if (linkActrPtr->mEquipItem == 0x70) {
                    if (libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch) == false) {
                        sussy = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_fastCreate(temporar, 0, &create_pos, -1, NULL, NULL, 0xff, NULL, NULL);
                        cuccoWait = true;
                        grabRemember = true;
                        linkActrPtr->mProcID = 0xA;
                        libtp::tp::d_a_alink::procAutoJumpInit(linkActrPtr, 0);
                    }
                    else return cuccoMoment(linkActrPtr);
                } else {return cuccoMoment(linkActrPtr);}

                if (sussy != NULL) {
                    libtp::tp::d_a_alink::setGrabItemActor(linkActrPtr, sussy);
                    libtp::tp::d_com_inf_game::dComIfGp_addSelectItemNum(linkActrPtr->mSelectItemId, -1);
                    linkActrPtr->field_0x33e4 = 38.0f;
                    libtp::tp::d_a_alink::setGrabUpperAnime(linkActrPtr, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
                }
            }
            linkActrPtr->mEquipItem = 0xFF;
            return 1;
        }

        return cuccoMoment(linkActrPtr);
    }
    libtp::tp::f_op_actor::fopAc_ac_c* id;
    uint8_t tiimer = 0;
    uint8_t tiiimer = 0;
    uint8_t countyer = 0;
    uint8_t trimer = 0;
    uint8_t bombytimer = 0;
    bool greenLight = false;
    bool bomba = false;
    bool bamba = false;
    bool timestartt = false;
    uint8_t padingTimer = 0;

    void Mod::UICheck(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) {
#ifdef PLATFORM_WII
        if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00000004) != 0 && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00002000) == 0 && ((libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID > 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C) && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0 && libtp::tp::d_bg_s_acch::ChkGroundHit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch))
#else
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR && libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockL == 0 && ((libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID > 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C) && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0 && libtp::tp::d_bg_s_acch::ChkGroundHit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch))
#endif
        {
            if (crouch == 0) {
                libtp::tp::d_a_alink::procCrouchInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
                crouch = 1;
            }
#ifdef PLATFORM_WII
            else if (shieldCrouch == false && crouch == 1 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x200)
#else
            else if (shieldCrouch == false && crouch == 1 && (libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickPosX || libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickPosY))
#endif
            {
                libtp::tp::d_a_alink::procCrawlMoveInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mCollisionRot.x, libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mCollisionRot.z);
                crawlCrouch = true;
                crouch = 2;
            }
        } else if (crouch != 0 && crawlCrouch == false && ((libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID > 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C)) {
            libtp::tp::d_a_alink::checkNextActionFromCrouch(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, 0);
            crouch = 0;
            shieldCrouch = false;
        } else if (crawlCrouch && ((libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID > 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C)) {
            crawlCrouch = false;
            crouch = 0;
        }

        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1D && shieldCrouch) {
            libtp::tp::d_a_alink::procCrouchInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
            timestartt = true;
        } else if (timestartt) {
            padingTimer++;
            if (padingTimer == 15) {
                padingTimer = 0;
                crouch = 0;
                shieldCrouch = false;
                timestartt = false;
#ifdef PLATFORM_WII
                if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00000004)
#else
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR)
#endif
                {
                    libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID = 0x1D;
                    libtp::tp::d_a_alink::procCrouchInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
                }
            }
        }

        if (sussy != NULL && grabRemember) {
            if (libtp::tp::d_bg_s_acch::ChkGroundHit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mGrabItemAcKeep.mActor == NULL) {libtp::tp::f_op_actor_mng::fopAcM_delete(sussy); grabRemember = false;}
        }
        if (greenLight == true) {
            tiimer++;
            if (tiimer == 10) {
                tiimer = 0;
                greenLight = false;
                if ((libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_iter::fopAcIt_Judge(libtp::tp::f_op_actor_mng::fpcSch_JudgeForPName, &temporar) == NULL) {
                    id = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_create(temporar, 0, NULL, -1, NULL, NULL, 0xFF);
                }
            }
        }
        if ((libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_iter::fopAcIt_Judge(libtp::tp::f_op_actor_mng::fpcSch_JudgeForPName, &temporar) == NULL) {
            if (greenLight == false) {greenLight = true; tiimer = 0;}
        }
        if (cuccoWait == true && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mGrabItemAcKeep.mActor == NULL) {
            if (libtp::tp::d_bg_s_acch::ChkGroundHit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch) == false) {
                tiiimer++;
                if (tiiimer >= 15) {
                    tiiimer = 0;
                    cuccoWait = false;
                }
            } else {cuccoWait = false; tiiimer = 0;}
        }
        
#ifdef PLATFORM_WII
        if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31) && bomba == false && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x00000002) && countyer < 2 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0)
#else
        if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31) && bomba == false && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & libtp::tp::m_do_controller_pad::Button_DPad_Down) && countyer < 2 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0)
#endif
        {
            bamba = true;
            countyer++;
        }

        if (bamba) {
            trimer++;
            if (trimer >= 15) {
                bamba = false;
                bomba = true;
                trimer = 0;
                bombytimer = 0;
                libtp::tp::d_a_alink::setClothesChange(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, 0);
                libtp::tp::m_Do_Audio::mDoAud_seStart(0x4f, 0, 0, 0);
                if (countyer == 1) {
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[0] != 0x31) libtp::tp::d_com_inf_game::setSelectEquipClothes(0x31);
                    else libtp::tp::d_com_inf_game::setSelectEquipClothes(0x2f);
                } else if (countyer == 2 && libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x30)) {
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[0] != 0x30) libtp::tp::d_com_inf_game::setSelectEquipClothes(0x30);
                    else libtp::tp::d_com_inf_game::setSelectEquipClothes(0x2f);
                }
                countyer = 0;
            }
        }
        if (bomba == true) {
            bombytimer++;
            if (bombytimer >= 20) {
                bomba = false;
                bombytimer = 0;
            }
        }
        return healthUIOn(dMeterDrawPtr);
    }
}     // namespace mod