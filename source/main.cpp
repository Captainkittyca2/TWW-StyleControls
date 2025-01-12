/**
 * @file main.cpp
 * @author Captain Kitty Cat (youtube.com/@captainkittyca2)
 * @brief
 * @version 0.3
 * @date 2025-01-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <display/console.h>     // Contains a very neat helper class to print to the console
#include <main.h>
#include <patch.h>     // Contains code for hooking into a function
#include <cstdio>
#include <tp/f_op_actor_mng.h>
#include <string.h>
#include <tp/m_do_audio.h>
#include <tp/d_menu_window.h>
#include <JSystem/JMath/JMATrigonometric.h>
#include <tp/f_op_actor_iter.h>
#include <tp/JFWSystem.h>
#include <tp/rel/ids.h>
#include <tp/d_meter_HIO.h>
#include <gc_wii/OSCache.h>
#include <tp/m_do_printf.h>
#include <gc_wii/dvd.h>
#include <tp/d_item_data.h>
#include <tp/d_camera.h>
#include <tp/d_kankyo.h>
#include <tp/d_item.h>

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
    daMidna_checkMetamorphoseEnableBase_Def daMidna_c__checkMetamorphoseEnableBase = nullptr;
    daE_ba_initAnm return_e_ba_initAnm = nullptr;
    daE_ba_attack return_e_ba_attack = nullptr;
    //daE_bu_initAnm return_e_bu_initAnm = nullptr;
    //daE_bu_attack return_e_bu_attack = nullptr;
    daE_dd_initAnm return_e_dd_initAnm = nullptr;
    daE_dd_attack return_e_dd_attack = nullptr;
    daE_dn_initAnm return_e_dn_initAnm = nullptr;
    daE_dn_attack return_e_dn_attack = nullptr;
    daE_dn_attackStab return_e_dn_attackStab = nullptr;
    daE_dn_attackSpin return_e_dn_attackSpin = nullptr;
    daE_kk_bckSet return_e_kk_bckSet = nullptr;
    daE_kk_attack return_e_kk_attack = nullptr;
    daE_mf_initAnm return_e_mf_initAnm = nullptr;
    daE_mf_attack return_e_mf_attack = nullptr;
    daE_mf_attackSpin return_e_mf_attackSpin = nullptr;
    daE_oc_attack return_e_oc_attack = nullptr;
    daE_rd_initAnm return_e_rd_initAnm = nullptr;
    daE_rd_attack return_e_rd_attack = nullptr;
    daE_sf_initAnm return_e_sf_initAnm = nullptr;
    daE_st_initAnm return_e_st_initAnm = nullptr;
    daE_st_attack return_e_st_attack = nullptr;
    daE_sw_attack return_e_sw_attack = nullptr;
    daE_tt_attack return_e_tt_attack = nullptr;
    daE_vt_attackOpaci return_e_vt_attackOpaci = nullptr;
    daE_ww_attack return_e_ww_attack = nullptr;
    daB_gnd_initAnm return_b_gnd_initAnm = nullptr;
    daB_gnd_attack return_b_gnd_attack = nullptr;
    daB_gg_anmSet return_b_gg_anmSet = nullptr;
    daB_gg_attackF return_b_gg_attackF = nullptr;
    daB_gg_attackG return_b_gg_attackG = nullptr;
    daB_tn_attackH return_b_tn_attackH = nullptr;
    daB_tn_attackL return_b_tn_attackL = nullptr;
#ifdef PLATFORM_WII
    uint16_t gg_b_address[3] = {0xCF4, 0x4A18, 0x7090};
    uint16_t gnd_b_address[2] = {0x1F0, 0x2E80};
    uint16_t tn_b_address[2] = {0x6048, 0x9c94};
    uint16_t ba_e_address[2] = {0x560, 0x14a0};
    //uint16_t bu_e_address[2] = {0x560, 0x145C};
    uint16_t dd_e_address[2] = {0x51C, 0x1E1C};
    uint16_t dn_e_address[4] = {0x620, 0x38D8, 0x3A4C, 0x3C84};
    uint16_t kk_e_address[2] = {0x4D0, 0x277C};
    uint16_t mf_e_address[3] = {0x308, 0x35C0, 0x3810};
    uint16_t oc_e_address = 0x3AE4;
    uint16_t rd_e_address[2] = {0x624, 0x2D10};
    uint16_t sf_e_address[2] = {0x2A4, 0x339C};
    uint16_t st_e_address[2] = {0x524, 0x4408};
    uint16_t sw_e_address[2] = {0x3FFC, 0x58EC};
    uint16_t tt_e_address = 0x1E68;
    uint16_t ww_e_address = 0x2034;
    uint16_t vt_e_address[2] = {0x9E94, 0x75EC};
    daE_oc_execute return_e_oc_execute = nullptr;
    daE_sf_execute return_e_sf_execute = nullptr;
    daE_vt_execute return_e_vt_execute = nullptr;
    daE_sw_execute return_e_sw_execute = nullptr;
    daE_ww_execute return_e_ww_execute = nullptr;
#else
    daB_tn_bckSet return_b_tn_bckSet = nullptr;
    daE_oc_bckSet return_e_oc_bckSet = nullptr;
    daE_sf_attack0 return_e_sf_attack0 = nullptr;
    daE_sf_attack return_e_sf_attack = nullptr;
    daE_sw_setBck return_e_sw_setBck = nullptr;
    daE_tt_bckSet return_e_tt_bckSet = nullptr;
    daE_ww_bckSet return_e_ww_bckSet = nullptr;
    daE_vt_bckSet return_e_vt_bckSet = nullptr;
    uint16_t gg_b_address[3] = {0xD18, 0x5CC0, 0x8BE4};
    uint16_t gnd_b_address[2] = {0x208, 0x35FC};
    uint16_t tn_b_address[2] = {0x6BC4, 0xA8CC};
    uint16_t ba_e_address[2] = {0x264, 0x123c};
    //uint16_t bu_e_address[2] = {0x264, 0x1240};
    uint16_t dd_e_address[2] = {0x220, 0x1EEC};
    uint16_t dn_e_address[4] = {0x2E4, 0x3DEC, 0x3F8C, 0x4368};
    uint16_t kk_e_address[2]= {0x51C, 0x26E8};
    uint16_t mf_e_address[3] = {0x2E0, 0x3E20, 0x4214};
    uint16_t oc_e_address = 0x41B4;
    uint16_t rd_e_address[2] = {0x328, 0x2F38};
    uint16_t sf_e_address[3] = {0x21C, 0x11E8, 0x13C0};
    uint16_t st_e_address[2] = {0x220, 0x50FC};
    uint16_t sw_e_address[2] = {0x214, 0x6C04};
    uint16_t tt_e_address = 0x2328;
    uint16_t ww_e_address = 0x26F0;
    uint16_t vt_e_address[2] = {0x13EC, 0x7F38};
#endif
    libtp::tp::jfw_system::SystemConsole* sysConsolePtr = libtp::tp::jfw_system::systemConsole;

    bool uiChecking = false;
    bool uiCheckingStart = false;
    uint8_t countDownMeter = 50;
    uint16_t pretendMeterValue = 0;
    uint32_t readIconsTex = reinterpret_cast<uint32_t>(libtp::tp::d_meter2_info::readItemTexture);
    uint32_t armorSilence2 = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::setDamagePoint);
    uint16_t theSkillsAreHidden[5] = {0x2A40, 0x2A80, 0x2901, 0x2902, 0x2908};

    // Saved mod info
    struct saveInfo
    {
        /* 0x00 */ uint8_t currentMeterValue;
        /* 0x01 */ uint8_t firstTimeCheck;
        /* 0x02 */ uint8_t armorVer;
        /* 0x03 */ uint8_t parryOnOff;
        /* 0x04 */ uint8_t dPadChoice;
        /* 0x05 */ uint8_t skillParams[5];
        uint8_t unk[69];
        /* 0x4f */ uint8_t TWWStyleControlsID;
    } __attribute__((__packed__));

    saveInfo* saveInfoPtr = reinterpret_cast<saveInfo*>(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.reserve);

#if defined(TP_WUS2) || defined(TP_WJP)
    float xPosition = libtp::tp::d_meter_hio::g_drawHIO.mLanternMeterPosX;
#else
    float xPosition = 8.0f;
#endif

    int32_t DiveNope(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        (void)linkActrPtr;
        return 0;
    }

    int16_t outlineR = 0xFF;
    int16_t outlineG = 0xFF;
    int16_t outlineB = 0xFF;
    bool switchTheDir = false;
    bool grabRemember = false;
    bool consumeTheMeter = false;
    bool gameplayStatus = false;
    char maruIconThing[28] = "tt_zelda_button_ab_maru.bti";
#ifdef PLATFORM_WII
    char maruIconDeluxe[] = "tt_zelda_revo_maru_button_64_8ia_01.bti";
    char somethingSpecial[] = "tt_zelda_button_x_base.bti";
    bool parryMiiPlease = false;
#endif
    char parryIconThing[12] = "font_12.bti";
    char parryIconMiddle[36] = "im_zelda_item_fishing_try_00_16.bti";
    bool dpaaadRight = false;
    bool dpaaadDown = false;

    void handleQuickTransform()
    {
        using namespace libtp::tp::d_com_inf_game;

        // Ensure that Link is loaded on the map.
        libtp::tp::d_a_alink::daAlink* linkMapPtr = dComIfG_gameInfo.play.mPlayer;
        if (!linkMapPtr)
        {
            return;
        }

        // Ensure that link is not in a cutscene.
        if (libtp::tp::d_a_alink::checkEventRun(linkMapPtr))
        {
            return;
        }

        // Check to see if Link has the ability to transform.
        if (!libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0xD04))
        {
            return;
        }

        // Make sure Link isn't riding anything (horse, boar, etc.)
        if (libtp::tp::d_camera::checkRide(linkMapPtr))
        {
            return;
        }

        // Make sure Link is not underwater or talking to someone.
        switch (linkMapPtr->mProcID)
        {
            case libtp::tp::d_a_alink::PROC_TALK:
            case libtp::tp::d_a_alink::PROC_SWIM_UP:
            case libtp::tp::d_a_alink::PROC_SWIM_DIVE:
            {
                return;
            }
            // If Link is targeting or pulling a chain, we don't want to remove the ability to use items in combat accidently.
            case libtp::tp::d_a_alink::PROC_ATN_ACTOR_MOVE:
            case libtp::tp::d_a_alink::PROC_ATN_ACTOR_WAIT:
            case libtp::tp::d_a_alink::PROC_WOLF_ATN_AC_MOVE:
            {
                break;
            }
            default:
            {
                // Disable the input that was just pressed, as sometimes it could cause items to be used or Wolf Link to dig.
#ifndef PLATFORM_WII
                libtp::tp::m_do_controller_pad::cpadInfo[libtp::tp::m_do_controller_pad::PAD_1].mPressedButtonFlags = 0;
#else
                libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags = 0;
#endif
                break;
            }
        }

        // Ensure there is a proper pointer to the mMeterClass and mpMeterDraw structs in g_meter2_info.
        const libtp::tp::d_meter2::dMeter2_c* meterClassPtr = libtp::tp::d_meter2_info::g_meter2_info.mMeterClass;
        if (!meterClassPtr)
        {
            return;
        }

        const libtp::tp::d_meter2_draw::dMeter2Draw_c* meterDrawPtr = meterClassPtr->mpMeterDraw;
        if (!meterDrawPtr)
        {
            return;
        }

#ifndef PLATFORM_WII
        // Ensure that the Z Button is not dimmed
        const float zButtonAlpha = meterDrawPtr->mZButtonAlpha;
#else
        const float zButtonAlpha = meterDrawPtr->field_0x7d4;
#endif
        if (zButtonAlpha != 1.f)
        {
            return;
        }

        // The game will crash if trying to quick transform while holding the Ball and Chain
        if (linkMapPtr->mEquipItem == libtp::data::items::Ball_and_Chain)
        {
            return;
        }

        // Use the game's default checks for if the player can currently transform
        if (!daMidna_c__checkMetamorphoseEnableBase(libtp::tp::d_a_player::m_midnaActor))
        {
            return;
        }

        // Check if the player has scared someone in the current area in wolf form
        if ((libtp::tp::d_kankyo::env_light.mEvilPacketEnabled & 0x80) != 0)
        {
            return;
        }

        libtp::tp::d_a_alink::procCoMetamorphoseInit(linkMapPtr);
    }

    void colorMMeter(libtp::tp::d_pane_class::CPaneMgr* panePtr, libtp::tp::JUtility::TColor* awesome, libtp::tp::JUtility::TColor* wholesome) {
        (void)panePtr;
        if (consumeTheMeter) {
            consumeTheMeter = false;
            if (!switchTheDir) {
                outlineR -= 17; outlineG -= 17; outlineB -= 17;
                if (outlineR < 0) {
                    outlineR = outlineG = outlineB = 0;
                    switchTheDir = true;
                }
            } else {
                outlineR += 17; outlineG += 17; outlineB += 17;
                if (outlineR > 0xFF) {
                    outlineR = outlineG = outlineB = 0xFF;
                    switchTheDir = false;
                }
            }
        } else {
            outlineR = outlineG = outlineB = 0;
            switchTheDir = false;
        }
        awesome->set(outlineR, outlineG, outlineB, 0xFF);
        wholesome = awesome;
        libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicBase, awesome, wholesome);
        libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicMeter->mInitBlack.a = 255;
        libtp::tp::d_pane_class::setBlackWhite(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicMeter, &libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicMeter->mInitBlack, &libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpMagicMeter->mInitWhite);
    }

    int32_t heavyArmor(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (libtp::tp::d_a_alink::checkMagicArmorWearAbility(linkActrPtr))
        {if ((!saveInfoPtr->armorVer && saveInfoPtr->currentMeterValue == 0) || (saveInfoPtr->armorVer && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees == 0)) return 1;}
        return 0;
    }

    bool shieldCrouch = false;
    uint8_t crouch = 0;
    bool parryTheEnemy = false;
    uint8_t paramCapture = 0;
#ifdef PLATFORM_WII
    bool attackCapture = false;
#endif

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
    
    int32_t crawlStuffStart(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (linkActrPtr->mEquipItem != 0xff) {
            return libtp::tp::d_a_alink::procPreActionUnequipInit(linkActrPtr, 0x35, NULL);
        }
        libtp::tp::d_a_alink::commonProcInit(linkActrPtr, libtp::tp::d_a_alink::PROC_CRAWL_START);
        linkActrPtr->field_0x3588 = libtp::tp::d_a_alink::l_waitBaseAnime;
        libtp::tp::d_a_alink::setSingleAnimeParam(linkActrPtr, libtp::tp::d_a_alink::ANM_CRAWL_START, &libtp::tp::d_a_alink::crouchVars.mCrawlStartAnm);
#ifdef PLATFORM_WII
        linkActrPtr->field_0x33d4 = 0.0f;
#else
        linkActrPtr->mNormalSpeed = 0.0f;
#endif
        linkActrPtr->mCurrent.mAngle.y = linkActrPtr->mCollisionRot.y;
        if (libtp::tp::d_a_alink::crouchVars.mCrawlStartAnm.mCheckFrame > libtp::tp::d_a_alink::crouchVars.mCrawlStartAnm.mEndFrame)
            linkActrPtr->field_0x347c = libtp::tp::d_a_alink::crouchVars.mCrawlStartAnm.mEndFrame;
        else linkActrPtr->field_0x347c = libtp::tp::d_a_alink::crouchVars.mCrawlStartAnm.mCheckFrame;
        linkActrPtr->field_0x3478 = 1.0f/(linkActrPtr->field_0x347c - libtp::tp::d_a_alink::crouchVars.mCrawlStartAnm.mStartFrame);
        linkActrPtr->field_0x33cc = 0.0f;
        return 1;
    }

    /*int32_t crawlMoveStuffStart(libtp::tp::d_a_alink::daAlink* linkActrPtr, int16_t param_0, int16_t param_1) {
        int32_t var_r29;
        int32_t var_r28 = 0;

        if (linkActrPtr->mProcID == libtp::tp::d_a_alink::PROC_CRAWL_AUTO_MOVE) {
            var_r29 = 0;
        } else {
            var_r29 = 1;
            if (linkActrPtr->mProcID == libtp::tp::d_a_alink::PROC_CRAWL_START) {
                var_r28 = 1;
            }
        }

        int32_t var_r27;
        if (libtp::tp::d_a_alink::checkPlayerStatus0(0, 0x2000)) {
            var_r27 = 1;
        } else {
            var_r27 = 0;
        }
        libtp::tp::d_a_alink::commonProcInit(linkActrPtr, libtp::tp::d_a_alink::PROC_CRAWL_MOVE);
        linkActrPtr->mProcVar3.field_0x300e = 0;

        if (var_r29 != 0) {
            float var_f31 = libtp::tp::d_a_alink::getCrawlMoveAnmSpeed(linkActrPtr);
            if (var_r28 != 0) {
                linkActrPtr->mProcVar3.field_0x300e = 1;
            } else if (libtp::tp::d_a_alink::getDirectionFromShapeAngle(linkActrPtr) == 1) {
                var_f31 *= -1.0f;
            }

            linkActrPtr->mCurrent.mAngle.y = linkActrPtr->mCollisionRot.y;
            libtp::tp::d_a_alink::setSingleAnimeBaseSpeed(linkActrPtr, libtp::tp::d_a_alink::ANM_CRAWL, var_f31, libtp::tp::d_a_alink::crouchVars.mCrawlInterpolation);
        }

        linkActrPtr->field_0x3198 = var_r29 ^ 1;
        linkActrPtr->mCollisionRot.x = param_0;
        linkActrPtr->mCollisionRot.z = param_1;
        linkActrPtr->field_0x33cc = 1.0f;
        linkActrPtr->field_0x2f99 = 0xC;

        if (var_r27 != 0) {
            libtp::tp::d_com_inf_game::setPlayerStatus(0, 0, 0x2000);
        }

        return 1;
    }*/

    int32_t Mod::crawlMoveStuff(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        //libtp::tp::d_a_player::daPy_frameCtrl_c* temp_r29 = &linkActrPtr->mUnderFrameCtrl[0];
        cXyz sp54; cXyz sp48; cXyz sp3C;

        linkActrPtr->field_0x2f99 = 0xC;
        libtp::tp::d_a_alink::decideCrawlDoStatus(linkActrPtr);

        libtp::tp::d_a_alink::PSMTXMultVec(linkActrPtr->mpLinkModel->mBaseTransformMtx, &libtp::tp::d_a_alink::l_crawlStandUpOffset, &sp48);
        libtp::tp::d_a_alink::PSMTXMultVec(linkActrPtr->mpLinkModel->mBaseTransformMtx, &libtp::tp::d_a_alink::l_crawlFrontUpOffset, &sp54);
        libtp::tp::d_a_alink::PSMTXMultVec(linkActrPtr->mpLinkModel->mBaseTransformMtx, &libtp::tp::d_a_alink::l_crawlBackUpOffset, &sp3C);

        cXyz sp24;
        libtp::tp::d_a_alink::PSMTXMultVecSR(linkActrPtr->mpLinkModel->mBaseTransformMtx, &libtp::tp::d_a_alink::l_crawlMinSideOffset, &sp24);

        int32_t temp_r25 = libtp::tp::d_a_alink::checkNotCrawlStand(linkActrPtr, &sp48);
        int32_t temp_r24 = libtp::tp::d_a_alink::checkNotCrawlStand(linkActrPtr, &sp54);
        int32_t temp_r23 = libtp::tp::d_a_alink::checkNotCrawlStand(linkActrPtr, &sp3C);
        int32_t var_r27;
        if (temp_r25 || temp_r24 || temp_r23 || libtp::tp::d_a_alink::checkNotCrawlStand2(linkActrPtr, &sp54, &sp24) || libtp::tp::d_a_alink::checkNotCrawlStand2(linkActrPtr, &sp3C, &sp24) || libtp::tp::d_a_alink::checkNotCrawlStand2(linkActrPtr, &sp48, &sp24)) {
            var_r27 = 0;
            libtp::tp::d_a_alink::onModeFlg(linkActrPtr, 0x04000000);
        } else {
            var_r27 = 1;
            libtp::tp::d_a_alink::offModeFlg(linkActrPtr, 0x04000000);
        }

        libtp::tp::J3DModel::cM3dGPla sp60;
#ifdef PLATFORM_WII
        if (((var_r27 != 0 && linkActrPtr->mProcVar3.field_0x300e == 0) || libtp::tp::d_a_alink::getSlidePolygon(linkActrPtr, &sp60) || libtp::tp::d_a_alink::checkCrawlWaterIn(linkActrPtr)) && (dpaaadDown) == false)
#else
        if (((var_r27 != 0 && linkActrPtr->mProcVar3.field_0x300e == 0) || libtp::tp::d_a_alink::getSlidePolygon(linkActrPtr, &sp60) || libtp::tp::d_a_alink::checkCrawlWaterIn(linkActrPtr)) && libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR == 0)
#endif
        {
            libtp::tp::d_a_alink::procCrawlEndInit(linkActrPtr, 1, linkActrPtr->mCollisionRot.x, linkActrPtr->mCollisionRot.z);
        } else {
            return crawllllMoveee(linkActrPtr);
        }

        return 1;
    }

    bool cuccoWait = false;
    libtp::tp::f_op_actor::fopAc_ac_c* sussy;

#ifndef PLATFORM_WII
    int32_t DownNope() {
        if (saveInfoPtr->dPadChoice == 2)
            return libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 4;
        return false;
    }

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

    char parryChars[] = "Parry";
    //uint64_t aaaaaaaaa = 0x6162746E5F6E;

    // Change A button Icon depending if parrying or not
    void parryToggle(bool parry) {
        if (parry) {
            parryTheEnemy = true;
#ifdef PLATFORM_WII
            static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x615f62746e5f6370))->smthgTesting2(parryIconThing, 0);
            libtp::tp::d_meter2_draw::drawButtonA(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw, 0x2b, 0.0f, 130.0f, 0.0f, 0.0f, 1.0f, 1, 0);
#else
            static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x615f62746e))->smthgTesting2(parryIconThing, 0);
            libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x615f62746e5f6c)->hideTex();
            libtp::tp::d_meter2_draw::drawButtonA(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw, 0x2b, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1, 0);
#endif
            libtp::tp::m_Do_Audio::mDoAud_seStart(0x9F, 0, 0, 0);
            for (uint8_t ravviiooo = 0; ravviiooo < 5; ravviiooo++)
                ((libtp::tp::J2DTextBox::J2DTextBox*)libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpAText[ravviiooo]->mWindow)->setString(parryChars);
            //((libtp::tp::J2DTextBox::J2DTextBox*)libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpAText[4]->mWindow)->setString("Parry");
            //((libtp::tp::J2DTextBox::J2DTextBox*)libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpButtonA->mWindow)->setString("Parry");
        }
        else {
            parryTheEnemy = false;
            paramCapture = 0;
#ifdef PLATFORM_WII
            parryMiiPlease = false;
            static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x615f62746e5f6370))->smthgTesting2(maruIconDeluxe, 0);
#else
            static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x615f62746e))->smthgTesting2(maruIconThing, 0);
            libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x615f62746e5f6c)->showTex();
#endif
            for (uint8_t ravviiooo = 0; ravviiooo < 5; ravviiooo++)
                ((libtp::tp::J2DTextBox::J2DTextBox*)libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpAText[ravviiooo]->mWindow)->setString("");
            if (libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton != NULL) {
#ifdef PLATFORM_WII
                static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpButtonScreen, 0x615F62746E5F6332))->smthgTesting2(maruIconThing, 0);
                libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpButtonScreen, 0x615f62746e)->showTex();
#else
                static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpButtonScreen, 0x615F62746E31))->smthgTesting2(maruIconThing, 0);
                libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpButtonScreen, 0x615f62746e5f6c31)->showTex();
#endif
            }
            //((libtp::tp::J2DTextBox::J2DTextBox*)libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpAText[4]->mWindow)->setString("");
        }
    }

    uint8_t dirRollParry = 0;
    // Parry attacks
    void parryAttack(libtp::tp::f_op_actor::fopEn_enemy_c* enemyPtr, uint8_t attackType) {
        if (saveInfoPtr->parryOnOff) {parryToggle(false); return;}
        if (attackType == 4) {parryToggle(false); return;}
        libtp::tp::d_a_alink::daAlink* linkActrPtr = libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer;
#ifdef PLATFORM_WII
        if (attackCapture && linkActrPtr->mTargetedActor != enemyPtr) return;
#endif
        if (parryTheEnemy && linkActrPtr->mTargetedActor == NULL) {parryToggle(false); return;}
        if (linkActrPtr->mEquipItem != 0x103 || (linkActrPtr->mProcID != 6 && linkActrPtr->mProcID != 7 && linkActrPtr->mProcID != 0x2f)) {parryToggle(false); return;}

        if (linkActrPtr->mTargetedActor == enemyPtr) {
            if (linkActrPtr->mProcID == 0x2f) linkActrPtr->mProcID = 6;
            if (linkActrPtr->mProcID == 6 || linkActrPtr->mProcID == 7) {
                if (!parryTheEnemy) parryToggle(true);
#ifndef PLATFORM_WII
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100)
#else
                if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x800)
#endif
                {
                    if (attackType == 1) {
                        if (enemyPtr->mProcName == 0x206 || enemyPtr->mProcName == 0x1bf) {
                            enemyPtr->mHeadLockPos.x = enemyPtr->mCurrent.mPosition.x;
                            enemyPtr->mHeadLockPos.y += 100.0f;
                            enemyPtr->mHeadLockPos.z = enemyPtr->mCurrent.mPosition.z;
                        }
                        libtp::tp::d_a_alink::procCutHeadInit(linkActrPtr);
                    }
                    else if (attackType == 0) {
                        if (enemyPtr->mProcName == 0x1b3 || enemyPtr->mProcName == 0x1b5) {libtp::tp::d_a_alink::procTurnMoveInit(linkActrPtr, 3); return;}
                        if (dirRollParry != 0) {libtp::tp::d_a_alink::procTurnMoveInit(linkActrPtr, dirRollParry); dirRollParry = 0;}
                        else libtp::tp::d_a_alink::procTurnMoveInit(linkActrPtr, static_cast<int32_t>(libtp::tp::d_a_alink::randVal(2.0f)) + 2);
                    }
                    else if (attackType == 2)
                        libtp::tp::d_a_alink::procCutFinishInit(linkActrPtr, 4);
                    else {
                        enemyPtr->mDownPos.x = enemyPtr->mCurrent.mPosition.x;
                        enemyPtr->mDownPos.z = enemyPtr->mCurrent.mPosition.z;
                        libtp::tp::d_a_alink::procCutDownInit(linkActrPtr);
                    }
                    parryToggle(false);
                }
            }
        }
    }

    void meterConsumption(int8_t ammoConsume, bool countDownn) {
        bool consumeNow = false;
        if (saveInfoPtr->currentMeterValue == 0) {consumeTheMeter = false; return;}

        if (countDownn) {
            countDownMeter--;
            if (countDownMeter == 0) {
                consumeNow = true;
                countDownMeter = 50; 
            }
        } else consumeNow = true;

        if (consumeNow) {
            if (saveInfoPtr->currentMeterValue - ammoConsume < 1) {
                saveInfoPtr->currentMeterValue = 0; libtp::tp::m_Do_Audio::mDoAud_seStart(0x24, 0, 0, 0);
                consumeTheMeter = false;
            } else {
                saveInfoPtr->currentMeterValue -= ammoConsume; libtp::tp::m_Do_Audio::mDoAud_seStart(0x23, 0, 0, 0);
            }
        }
    }
    
    void hiddenSkillMemories(bool param0) {
        if (param0) {
            for (uint8_t tempParam1 = 0; tempParam1 < 5; tempParam1++) {
                if (libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, theSkillsAreHidden[tempParam1])) {
                    saveInfoPtr->skillParams[tempParam1] = 1;
                    libtp::tp::d_save::offEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, theSkillsAreHidden[tempParam1]);
                }
            }
        } else {
            for (uint8_t tempParam1 = 0; tempParam1 < 5; tempParam1++) {
                if (saveInfoPtr->skillParams[tempParam1]) {
                    saveInfoPtr->skillParams[tempParam1] = 0;
                    libtp::tp::d_save::onEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, theSkillsAreHidden[tempParam1]);
                }
            }
        }
    }

//#ifndef PLATFORM_WII
    /*int32_t rodCorrect(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (linkActrPtr->mEquipItem == 0x46) return 1;
        return 0;
    }*/

    /*int32_t rodPorrect(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (!libtp::tp::d_a_alink::checkCopyRodAnime(linkActrPtr)) {
            libtp::tp::d_a_alink::setCopyRodControllAnime(linkActrPtr);
        }*/
        //if (linkActrPtr->mProcID != 4)
            //return libtp::tp::d_a_alink::procCopyRodSubjectInit(linkActrPtr);
        //return libtp::tp::d_a_alink::procCopyRodMoveInit(linkActrPtr);
    //}

    /*void rodOorrect(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        libtp::tp::d_a_alink::setUpperAnimeBaseSpeed(linkActrPtr, 0x202, 0.0f, 3.0f);
        linkActrPtr->field_0x2f96 = 2; linkActrPtr->field_0x2f97 = 5; linkActrPtr->field_0x33e8 = 0.0f;
    }*/
//#endif

    bool spinGreatPlease = false;

    int32_t cutLargeTurning(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifdef PLATFORM_WII
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth == ((libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.maxHealth/5) * 4) && saveInfoPtr->currentMeterValue != 0) spinGreatPlease = true;
#endif
        if (spinGreatPlease || (linkActrPtr->mDemo.mDemoMode == 0x24 && linkActrPtr->mDemo.mDemoMode == 0x33)) return 1;
        return 0;
    }

    void silentArmor() {}

    /*void meterArmor(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (saveInfoPtr->currentMeterValue != 0) {
            libtp::tp::d_a_alink::setMagicArmorBrk(linkActrPtr, 1);
        } else libtp::tp::d_a_alink::setMagicArmorBrk(linkActrPtr, 0);
    }*/

    void lineIsSetupSir(libtp::tp::d_save::dSv_player_item_c* itemPtrCMaybe) {
        (void)itemPtrCMaybe;

        using namespace libtp::tp::d_com_inf_game;

        static const uint8_t i_item_lst[24] = {0x0A, 0x08, 0x06, 0x02, 0x09, 0x04, 0x03, 0x00, 0x01, 0x17, 0x14, 0x05,
                                               0x0F, 0x10, 0x11, 0x0B, 0x0C, 0x0D, 0x0E, 0x13, 0x12, 0x16, 0x15, 0x7};
        int32_t i1 = 0;
        int32_t i2 = 0;
        libtp::tp::d_save::dSv_player_item_c* playerItemStructPtr = &dComIfG_gameInfo.save.save_file.player.player_item;
        uint8_t* playerItemSlots = &playerItemStructPtr->item_slots[0];

        for (; i1 < 24; i1++) // Clear all of the item slots.
        {
            playerItemSlots[i1] = 0xFF;
        }

        uint8_t* playerItem = &playerItemStructPtr->item[0];
        for (i1 = 0; i1 < 24; i1++) // Fill all of the item wheel slots with their respective items if gotten.
        {
            const uint32_t currentEntry = i_item_lst[i1];
            if (playerItem[currentEntry] != 0xFF)
            {
                playerItemSlots[i2] = static_cast<uint8_t>(currentEntry);
                i2++;
            }
        }
    }

    void Mod::init()
    {
        libtp::display::setConsole(true, 25);
        libtp::display::setConsoleColor(0, 0, 0, 0);
        gMod = this;

        uint32_t crawlingCheck = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procCrawlMove);
        uint32_t linkExecute = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::execute_);
        uint32_t kanterapoggy = reinterpret_cast<uint32_t>(libtp::tp::d_meter2_draw::drawKanteraScreen);
        uint32_t crawlingStarttInit = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procCrawlStartInit);
        uint32_t crawlingMoveeInit = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procCrawlMoveInit);
        //uint32_t linkDrawww = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::changeLink);
#ifdef TP_GUS
        uint32_t* patchMessageCalculation = reinterpret_cast<uint32_t*>(0x80238F58);
#elif defined TP_GEU
        uint32_t* patchMessageCalculation = reinterpret_cast<uint32_t*>(0x802395D8);
#elif defined TP_WUS2
        uint32_t* patchMessageCalculation = reinterpret_cast<uint32_t*>(0x80226318);
#endif

#ifdef PLATFORM_WII
        libtp::patch::writeBranch(crawlingCheck + 0x154, crawlingCheck + 0x1A4);
        libtp::patch::writeBranchBL(linkExecute + 0x20FC, silentArmor);
        libtp::patch::writeBranch(linkExecute + 0x210C, linkExecute + 0x21A4);
        performStaticASMReplacement(crawlingStarttInit + 0x70, ASM_NOP);
        performStaticASMReplacement(crawlingStarttInit + 0x74, ASM_NOP);
        libtp::patch::writeBranch(crawlingStarttInit + 0x7C, crawlingStarttInit + 0x8C);
        libtp::patch::writeBranch(crawlingStarttInit + 0x90, crawlingStarttInit + 0xA8);
        performStaticASMReplacement(crawlingStarttInit + 0x148, ASM_NOP);
        libtp::patch::writeBranch(crawlingStarttInit + 0xAc, crawlingStarttInit + 0x110);
        performStaticASMReplacement(crawlingMoveeInit + 0x110, ASM_NOP);
        libtp::patch::writeBranchBL(kanterapoggy + 0x74, colorMMeter);
#else
        uint32_t swingProcInitAddress = reinterpret_cast<uint32_t>(libtp::tp::d_a_alink::procCopyRodSwingInit);
        uint32_t littleBigLittlePlanet = reinterpret_cast<uint32_t>(libtp::tp::d_item_data::check_itemno);
        /*libtp::patch::writeBranch(swingProcInitAddress + 0x94, 0x38800179*/ //swingProcInitAddress + 0x90);
        libtp::patch::writeBranch(crawlingCheck + 0x158, crawlingCheck + 0x1A0);
        *reinterpret_cast<uint32_t*>(swingProcInitAddress + 0x28) = ASM_NOP;
        *reinterpret_cast<uint32_t*>(swingProcInitAddress + 0x20) = ASM_NOP;
        libtp::patch::writeBranchBL(linkExecute + 0x2034, silentArmor);
        libtp::patch::writeBranch(linkExecute + 0x2044, linkExecute + 0x20E0);
        libtp::patch::writeBranch(crawlingStarttInit + 0x70, crawlingStarttInit + 0x80);
        libtp::patch::writeBranch(crawlingStarttInit + 0x88, crawlingStarttInit + 0xD0);
        performStaticASMReplacement(crawlingStarttInit + 0x154, ASM_NOP);
        performStaticASMReplacement(crawlingMoveeInit + 0x108, ASM_NOP);
        performStaticASMReplacement(littleBigLittlePlanet + 0x2C, 0x2c1f0001);
        performStaticASMReplacement(littleBigLittlePlanet + 0x34, 0x2c1f0001);
        performStaticASMReplacement(littleBigLittlePlanet + 0x150, 0x2c1f0001);
        performStaticASMReplacement(littleBigLittlePlanet + 0x158, 0x2c1f0001);
        //libtp::patch::writeBranch(linkExecute + 0x2068, linkExecute + 0x20E0);
        libtp::patch::writeBranchBL(kanterapoggy + 0x78, colorMMeter);
        //libtp::patch::writeBranchBL(linkDrawww + 0x34C, meterArmor);
        //libtp::patch::writeBranch(linkDrawww + 0x34C, linkDrawww + 0x36C);
        performStaticASMReplacement(swingProcInitAddress + 0x10C, 0x38000400);
        //*reinterpret_cast<uint32_t*>(swingProcInitAddress + 0x10C) = ;
        //*reinterpret_cast<uint32_t*>(crawlingCheck + 0x19C) = ASM_NOP;
#endif
        libtp::tp::d_meter_hio::g_drawHIO.mLanternMeterPosY = 40.0f;
        libtp::tp::d_meter_hio::g_drawHIO.mOxygenMeterPosY = 40.0f;
        libtp::tp::d_item_data::field_item_res[8] = {"O_mD_gren", 0x0003, (int16_t)0xFFFF, (int16_t)0xFFFF, (uint8_t)0xFF, (uint8_t)NULL, (uint16_t)0x1000, (int16_t)NULL};
        libtp::tp::d_item_data::field_item_res[9] = {"O_mD_blue", 0x0003, (int16_t)0xFFFF, (int16_t)0xFFFF, (uint8_t)0xFF, (uint8_t)NULL, (uint16_t)0x1000, (int16_t)NULL};
        *patchMessageCalculation = 0x60000000;

        do_link_trampoline =
            libtp::patch::hookFunction(libtp::tp::dynamic_link::do_link ,[]( libtp::tp::dynamic_link::DynamicModuleControl* dmc ) {return gMod->procDoLink(dmc); } );
        return_fapGm_Execute =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::getMainBckData, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID) { return gMod->manualShield(linkActrPtr, i_anmID); } );

        unSheathShield =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::setShieldGuard, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->unSheathingShield(linkActrPtr); } );

        cuccoMoment =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::setItemActor, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cuccoCheckMoment(linkActrPtr); } );

        healthUIOn =
            libtp::patch::hookFunction( libtp::tp::d_meter2_draw::setAlphaLifeAnimeMax, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->UICheck(dMeterDrawPtr); } );
        
        healthUIOff =
            libtp::patch::hookFunction( libtp::tp::d_meter2_draw::setAlphaLifeAnimeMin, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->UIOff(dMeterDrawPtr); } );
        
        valueOfMeter =
            libtp::patch::hookFunction( libtp::tp::d_meter2::moveKantera, [](libtp::tp::d_meter2::dMeter2_c* dMeterPtr) { return gMod->meterValuee(dMeterPtr); } );
        
        return_drawMeter2 =
            libtp::patch::hookFunction( libtp::tp::d_meter2_draw::drawMeter, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->drawMeter2(dMeterDrawPtr); } );
#ifdef PLATFORM_WII
        return_itemNoChecking =
            libtp::patch::hookFunction( libtp::tp::d_item_data::check_itemno, [](int32_t itemNoNoNo) { return gMod->itemIsBeingChecked(itemNoNoNo); } );
#endif
        initMap =
            libtp::patch::hookFunction( libtp::tp::d_stage::dStage_playerInit, [](void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data) { return gMod->mapInitialized(stageDt, i_data, num, raw_data); } );

        turnMoveChecking =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::procTurnMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->checkTheTurnMove(linkActrPtr); } );

        crawllllMoveee =
            libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrawlMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->crawlMoveStuff(linkActrPtr); } );
        
        return_executee =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::execute_, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->executee(linkActrPtr); } );

        /*return_cutLargeJumpChargeInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutLargeJumpChargeInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutLargeJumpChargeInit(linkActrPtr); } );

        return_guardBattle =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGuardAttackInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->guardBattle(linkActrPtr); } );*/
        
        return_masterSwordLight =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::checkLightSwordMtrl, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->lightMasterSwordChecking(linkActrPtr); } );
        
        linkChanged =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::changeLink, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param_0) {return gMod->linkHasChanged(linkActrPtr, param_0); } );
        
        return_armorAppear =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::setMagicArmorBrk, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param_0) {return gMod->armorAppear(linkActrPtr, param_0); } );

        return_cutTurnMovee =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutTurnMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->turnCutTheMove(linkActrPtr); } );

        return_cutSpinChargeInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutTurnChargeInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutSpinChargeInit(linkActrPtr); } );
        
        return_cutspinInitialized =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutTurnInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aa, int32_t bb) { return gMod->cutSpinInit(linkActrPtr, aa, bb); } );
        
        /*return_sideRolling =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procSideRollInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t thinkOfAName) { return gMod->sideRollerDude(linkActrPtr, thinkOfAName); } );

        return_turnDudeComeOn =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procTurnMoveInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t thinkTHINK) { return gMod->turnMoveeDuude(linkActrPtr, thinkTHINK); } );

        return_cutHeadInit =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutHeadInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutHeadInit(linkActrPtr); } );*/
        
        elseOrSideStep =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procSideStepInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t sideStepSmthg) { return gMod->sideStepOrElse(linkActrPtr, sideStepSmthg); } );
        
        return_regularDamageHurts =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procDamageInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, void* objjjjj, int32_t unnnnnnk) { return gMod->dudeTheDamageHurts(linkActrPtr, objjjjj, unnnnnnk); } );
        
        return_largeCutDamage =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCoLargeDamageInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0,
                                int32_t param1, int16_t param2, int16_t param3, void* param4,
                                int32_t param5) { return gMod->DamageThrownDude(linkActrPtr, param0, param1, param2, param3, param4, param5); } );
        
        return_setModelMetamorph =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::setMetamorphoseModel, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0) { return gMod->modelMetaSomethingSet(linkActrPtr, param0); } );
        
        return_damageSetIt =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::setDamagePoint, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t a1, int32_t a2, int32_t a3, int32_t a4) { return gMod->damagetheSettingPointMaybe(linkActrPtr, a1, a2, a3, a4); } );
        
        return_finalCutdown =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutFinishInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgOrNot) { return gMod->finalCutdown(linkActrPtr, smthgOrNot); } );
        
        return_breakThatGuardNow =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procGuardBreakInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->guardHasBroke(linkActrPtr); } );
        
        //return_jumpCutJumpInit =
            //libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutFinishJumpUpInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->cutJumpInitialized(linkActrPtr); } );
        
        return_jumpAttackSomething =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::procCutJumpInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0) { return gMod->jumpAndAttackInit(linkActrPtr, param0); } );

        return_optionInitialize =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::optionInitialize, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {return gMod->initializeTheOption(optionsMenuPtr); } );

        return_attenStringSet =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::setAttenString, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {return gMod->stringAttentionDude(optionsMenuPtr); } );
        
        return_attenMovee =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::atten_move, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->attentionMoving(optionsMenuPtr); } );
#ifdef PLATFORM_WII
        return_constFrameThing =
            libtp::patch::hookFunction( libtp::tp::f_ap_game::fapGm_Execute, []() { return gMod->procNewFrame(); } );
        return_vibCamStringSet =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::setCameraString, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {return gMod->stringVibCamDude(optionsMenuPtr); } );

        return_soundPointerStringSet =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::setPointerString, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {return gMod->stringSoundPointerDude(optionsMenuPtr); } );

        return_vibCamMovee =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::camera_move, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->vibCamMoving(optionsMenuPtr); } );

        return_soundPointerMovee =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::pointer_move, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->soundPointerMoving(optionsMenuPtr); } );

        return_shortCutInitialization =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::shortcut_init, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->theShortCutInitializeed(optionsMenuPtr); } );
        
        return_calibrationInitialization =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::calibration_init, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->theCalibrationInitializeed(optionsMenuPtr); } );
        
        //return_nunButtonDrawn =
            //libtp::patch::hookFunction(libtp::tp::d_meter2_draw::drawButtonNun, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t param0) { return gMod->buttonNunWillDrawIt(dMeterDrawPtr, param0); } );

        return_resWiiHaveGot =
            libtp::patch::hookFunction(libtp::tp::d_resource::getResWii, [](const char* param1, int32_t param2, libtp::tp::d_resource::dRes_info_c* param3, int32_t param4) { return gMod->wiiHaveTheResEveryone(param1, param2, param3, param4); } );
#else
        return_vibCamStringSet =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::setVibString, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {return gMod->stringVibCamDude(optionsMenuPtr); } );

        return_soundPointerStringSet =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::setSoundString, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {return gMod->stringSoundPointerDude(optionsMenuPtr); } );

        return_vibCamMovee =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::vib_move, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->vibCamMoving(optionsMenuPtr); } );

        return_soundPointerMovee =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::sound_move, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->soundPointerMoving(optionsMenuPtr); } );
#endif

        return_closedConfirmation =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::deleteOptionsMenu, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->closingConfirmation(optionsMenuPtr); } );

        return_moveOptionsMenu =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::optionsMenuMove, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->moveInTheOptionsMenu(optionsMenuPtr); } );

        return_openConfirmation =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::confirm_open_init, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->openingConfirmation(optionsMenuPtr); } );
        
        return_meter2Drawn =
            libtp::patch::hookFunction(libtp::tp::d_meter2_draw::drawMeter2Init, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) { return gMod->drawMeter2drawDraw(dMeterDrawPtr); } );

        return_RDrawButton =
            libtp::patch::hookFunction(libtp::tp::d_meter2_draw::drawButtonR, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t unk1, uint8_t i_action, bool unk2, bool unk3) { return gMod->buttonRDrawn(dMeterDrawPtr, unk1, i_action, unk2, unk3); } );
        
        return_ADrawButton =
            libtp::patch::hookFunction(libtp::tp::d_meter2_draw::drawButtonA, [](libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t i_action, float i_posX, float i_posY, float i_textPosX, float i_textPosY, float i_scale, bool param_6, bool param_7) { return gMod->buttonADrawn(dMeterDrawPtr, i_action, i_posX, i_posY, i_textPosX, i_textPosY, i_scale, param_6, param_7); } );
        
        return_meterButtonString =
            libtp::patch::hookFunction(libtp::tp::d_meter_button::buttonMeterString, [](libtp::tp::d_meter_button::dMeterButton_c* buttonMeterPtr, char* characteristics, uint8_t param0, uint8_t param1, uint8_t param2) { return gMod->meterStringAndButton(buttonMeterPtr, characteristics, param0, param1, param2); } );
        
        return_theClosedConfirmation =
            libtp::patch::hookFunction(libtp::tp::d_menu_option::confirm_close_init, [](libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) { return gMod->theClosingConfirmation(optionsMenuPtr); } );
        
        return_getTheNextExe =
            libtp::patch::hookFunction(libtp::tp::d_a_obj_item::itemGetNextExecute, [](libtp::tp::d_a_obj_item::daItem_c* itemThingPtr) { return gMod->exeGetNextOne(itemThingPtr); } );
        
        return_initializingItemDrop =
            libtp::patch::hookFunction(libtp::tp::d_a_obj_item::CreateInitItem, [](libtp::tp::d_a_obj_item::daItem_c* itemThingPtr) { return gMod->itemDropIsInitialized(itemThingPtr); } );

        return_createActorFastPlease =
            libtp::patch::hookFunction(libtp::tp::f_op_actor_mng::fopAcM_fastCreateItem2, [](const cXyz* pos, int32_t itemNo, int32_t itemBitNo, int32_t roomNo, int32_t param5, const csXyz* actrRot, const cXyz* actrScale) { return gMod->actorMustMakeNOW(pos, itemNo, itemBitNo, roomNo, param5, actrRot, actrScale); } );
        
        return_gameSceneChanged =
            libtp::patch::hookFunction(libtp::tp::d_a_alink::changeGameScene, [](void* thingThing) { return gMod->gameSceneChanged(thingThing); } );
        
        return_eventBitWasOn =
            libtp::patch::hookFunction(libtp::tp::d_save::onEventBit, [](libtp::tp::d_save::dSv_event_c* dSavePtrThing, uint16_t param0) { return gMod->bitTheEventOnOn(dSavePtrThing, param0); } );

        return_itemTextureRead =
            libtp::patch::hookFunction(libtp::tp::d_meter2_info::readItemTexture, [](libtp::tp::d_meter2_info::G_Meter2_Info* g_meter2_info_ptr, uint8_t itemNo, void* param_1, 
                                libtp::tp::J2DPicture::J2DPicture* param_2, void* param_3, 
                                libtp::tp::J2DPicture::J2DPicture* param_4, void* param_5, 
                                libtp::tp::J2DPicture::J2DPicture* param_6, void* param_7, 
                                libtp::tp::J2DPicture::J2DPicture* param_8, int32_t param_9) { return gMod->reeadTheItemTexture(g_meter2_info_ptr, itemNo, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); } );
        
        //return_elimateReading =
            //libtp::patch::hookFunction(libtp::tp::d_meter2_draw::dMeter2Draw_dtt, [](void* abcdabcd) { return gMod->drawElimination(abcdabcd); } );

        //crawlFinale =
            //libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrawlEndInit, [](libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0, int16_t param1, int16_t param2) { return gMod->crawlingFinale(linkActrPtr, param0, param1, param2); } );

        //atnActorMoveTrampoline =
            //libtp::patch::hookFunction(libtp::tp::d_a_alink::procAtnActorMove, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->atnActorMove(linkActrPtr); } );

        //atnActorWaitTrampoline =
            //libtp::patch::hookFunction(libtp::tp::d_a_alink::procAtnActorWait, [](libtp::tp::d_a_alink::daAlink* linkActrPtr) { return gMod->atnActorWait(linkActrPtr); } );

        return_do_unlink = libtp::patch::hookFunction(libtp::tp::dynamic_link::do_unlink, [](libtp::tp::dynamic_link::DynamicModuleControl* dmc) {return gMod->handle_do_unlink(dmc); } );
        libtp::patch::hookFunction( libtp::tp::d_a_alink::procDiveJumpInit, DiveNope);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrouchInit, crouchStuff);
        //libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrawlStartInit, crawlStuffStart);
        //libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrawlMoveInit, crawlMoveStuffStart);
        //libtp::patch::hookFunction( libtp::tp::d_a_alink::checkItemActorPointer, rodCorrect);
        //libtp::patch::hookFunction( libtp::tp::d_a_alink::procCrawlMove, crawlMoveStuff);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::checkMagicArmorHeavy, heavyArmor);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::checkCutLargeTurnState, cutLargeTurning);
        libtp::patch::hookFunction( libtp::tp::d_save::setLineUpItem, lineIsSetupSir);
#ifndef PLATFORM_WII
        /*libtp::patch::hookFunction( libtp::tp::d_a_alink::checkNextActionCopyRod, rodPorrect);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::setCopyRodControllAnime, rodOorrect);*/
        libtp::patch::hookFunction( libtp::tp::d_menu_window::dMw_DOWN_TRIGGER, DownNope);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::spActionTrigger, RButtonThingy);
        libtp::patch::hookFunction( libtp::tp::d_a_alink::swordSwingTrigger, BButtonThingy);
#endif
    }

    bool firstTime = true;
    bool optionalRDetector = false;
    char titleMap[8] =  "F_SP102";
    char videoMap[8] =  "S_MV000";
    char option1[6] =   "Armor";
    char option2[14] =  "Parry Attacks";
#ifdef PLATFORM_WII
    char option3[12] =  "D-pad Right";
    // Use with getRes function
    char isItMiiOrNot[6] = "B_tn";
#else
    char option3[11] =  "D-pad Down";
#endif
    char option4[7] =   "TWW HD";
    char option5[8] =   "TWW GCN";
    char option6[14] =  "Armors Toggle";
    char option7[15] =  "Fast Transform";
    char option8[5] = "None";
    char option9[3] = "On";
    char option10[4] = "Off";
    char infoText1[23] = "Are these settings ok?";
    char infoText2[17] = "Cancel settings?";
    bool infoTextCheck = false;
    int8_t meterFuelTime = 0;

#ifdef PLATFORM_WII
    /*void Mod::buttonNunWillDrawIt(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t param0) {
        if (param0 == 0x3a) return;
        return return_nunButtonDrawn(dMeterDrawPtr, param0);
    }*/

    void* Mod::wiiHaveTheResEveryone(const char* param1, int32_t param2, libtp::tp::d_resource::dRes_info_c* param3, int32_t param4) {
        if (parryMiiPlease) {
            //sprintf(sysConsolePtr->consoleLine[15].line, "param1: %s", param1);
            if (strlen(param1) <= 6) {
                if (strcmp(isItMiiOrNot, param1) == 0) {
                    if (strcmp(isItMiiOrNot, "B_tn") == 0) {
                        if (param2 == 5 || param2 == 21) paramCapture = 2;
                        else if (param2 == 6 || param2 == 20) paramCapture = 1;
                        else {strcpy(isItMiiOrNot, ""); parryToggle(false);}
                    }
                    else if (strcmp(isItMiiOrNot, "E_TT") == 0) {
                        if (param2 == 3) paramCapture = 1;
                        else {strcpy(isItMiiOrNot, ""); parryToggle(false);}
                    }
                }
            }
        }
        return return_resWiiHaveGot(param1, param2, param3, param4);
    }

    uint8_t Mod::itemIsBeingChecked(int32_t itemNoNoNo) {
        if (itemNoNoNo == 8 || itemNoNoNo == 9) return itemNoNoNo;
        return return_itemNoChecking(itemNoNoNo);
    }
#endif

    int32_t Mod::mapInitialized(void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data) {
        gameplayStatus = false;
#ifdef PLATFORM_WII
        parryMiiPlease = false;
        attackCapture = false;
        strcpy(isItMiiOrNot, "");
#endif
        if (meterFuelTime != 0) {
            if (saveInfoPtr->currentMeterValue + meterFuelTime < 255) saveInfoPtr->currentMeterValue += meterFuelTime;
            else saveInfoPtr->currentMeterValue = 255;
            meterFuelTime = 0;
        }
        if (firstTime && strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, titleMap) != 0 && strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, videoMap) != 0 )
        {
            firstTime = false;
            if (!saveInfoPtr->armorVer)
#ifdef PLATFORM_WII
                libtp::patch::writeBranch(armorSilence2 + 0x120, armorSilence2 + 0x170);
            else performStaticASMReplacement(armorSilence2 + 0x120, 0x1C00000A);
#else
                libtp::patch::writeBranch(armorSilence2 + 0x100, armorSilence2 + 0x14c);
            else performStaticASMReplacement(armorSilence2 + 0x100, 0x1C00000A);
#endif
            if (saveInfoPtr->firstTimeCheck == 0) {
                libtp::tp::d_save::setItem(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_item, 7, 0xE3);
                saveInfoPtr->currentMeterValue = 255;
                saveInfoPtr->firstTimeCheck = 1;
                hiddenSkillMemories(true);
            }
            /*if (libtp::tp::d_save::getItem(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_item, 22, false) == 0xFF) {
                libtp::tp::d_save::setItem(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_item, 22, 0xE3);
            }*/
        }
        else if (strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, titleMap) == 0) {firstTime = true; uiCheckingStart = false; pretendMeterValue = 0; consumeTheMeter = false;}
        countDownMeter = 50;
        return initMap(stageDt, i_data, num, raw_data);
    }
    
    void Mod::gameSceneChanged(void* param0) {
        if (strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mNextStage.mStage, "F_SP108") == 0 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mNextStage.mPoint == 21 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mNextStage.mRoomNo == 1 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mNextStage.mLayer == 13) {
            saveInfoPtr->armorVer = 0; saveInfoPtr->dPadChoice = 0; saveInfoPtr->parryOnOff = 0;
            saveInfoPtr->firstTimeCheck = 0;
            for (uint8_t temppppppparam1111 = 0; temppppppparam1111 < 5; temppppppparam1111++) {
                saveInfoPtr->skillParams[temppppppparam1111] = 0;
            }
            // Might use in the future to check whether player played another mod in the save file
            saveInfoPtr->TWWStyleControlsID = 21;
        }
        return return_gameSceneChanged(param0);
    }

    void Mod::bitTheEventOnOn(libtp::tp::d_save::dSv_event_c* dSavePtrThing, uint16_t param0) {
        if (strcmp(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage, "F_SP200") == 0) {
            for (uint8_t tempParam1 = 0; tempParam1 < 5; tempParam1++) {
                if (param0 == theSkillsAreHidden[tempParam1]) {
                    if (libtp::tp::d_meter2_info::g_meter2_info.mMenuWindowClass->mpMenuOption != nullptr) return return_eventBitWasOn(dSavePtrThing, param0);
                    else saveInfoPtr->skillParams[tempParam1] = 1;
                    return;
                }
            }
        }
        return return_eventBitWasOn(dSavePtrThing, param0);
    }

    /*int32_t Mod::cutJumpInitialized(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (!saveInfoPtr->parryOnOff && linkActrPtr->mTargetedActor == NULL && linkActrPtr->mProcID != 0x20) {libtp::tp::d_a_alink::procWaitInit(linkActrPtr); return 0;}
        return return_jumpCutJumpInit(linkActrPtr);
    }*/

    int32_t Mod::jumpAndAttackInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0) {
        if (parryTheEnemy) return 0;
        return return_jumpAttackSomething(linkActrPtr, param0);
    }

    bool armorExpired = true;
    bool seStartArmor = false;
    bool bomba = false;
    bool bamba = false;

    int32_t Mod::executee(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        //const int32_t exeeeee = return_executee(linkActrPtr);
        //if (exeeeee) {
            if (libtp::tp::d_a_alink::checkMagicArmorWearAbility(linkActrPtr) && !bomba && !bamba) {
                if (!saveInfoPtr->armorVer) {
                    if (saveInfoPtr->currentMeterValue != 0 && !armorExpired) {
                        //sprintf(sysConsolePtr->consoleLine[6].line, "Meter Very Good!");
                        seStartArmor = true;
                        libtp::tp::d_a_alink::setMagicArmorBrk(linkActrPtr, 1);
                        armorExpired = true;
                    } else if (saveInfoPtr->currentMeterValue == 0 && armorExpired) {
                        //sprintf(sysConsolePtr->consoleLine[6].line, "Meter Not!");
                        seStartArmor = true;
                        libtp::tp::d_a_alink::setMagicArmorBrk(linkActrPtr, 0);
                        armorExpired = false;
                    }
                }
                else {
                    if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees != 0 && !armorExpired) {
                        //sprintf(sysConsolePtr->consoleLine[6].line, "Meter Very Good!");
                        seStartArmor = true;
                        libtp::tp::d_a_alink::setMagicArmorBrk(linkActrPtr, 1);
                        armorExpired = true;
                    } else if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees == 0 && armorExpired) {
                        //sprintf(sysConsolePtr->consoleLine[6].line, "Meter Not!");
                        seStartArmor = true;
                        libtp::tp::d_a_alink::setMagicArmorBrk(linkActrPtr, 0);
                        armorExpired = false;
                    }
                }
            }

            /*if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 4) {
                static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpButtonScreen, 0x615F62746E31))->smthgTesting2(parryIconMiddle, 0);
            }*/

            /*sprintf(sysConsolePtr->consoleLine[11].line, "spinGreatPlease: %d", spinGreatPlease);
            sprintf(sysConsolePtr->consoleLine[12].line, "parryTheEnemy: %d", parryTheEnemy);
            if (linkActrPtr->mTargetedActor != NULL) {
                sprintf(sysConsolePtr->consoleLine[13].line, "targetedActor: %x", linkActrPtr->mTargetedActor->mProcName);
            }*/
            //for (uint8_t ramamam = 0; ramamam < 10; ramamam++) {
                //sprintf(sysConsolePtr->consoleLine[ramamam+17].line, "AButtonText: %s", libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpTextBox[ramamam]->mStringPtr);
                //for (uint8_t dnjds = 0; dnjds < 5; dnjds++)
                //libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpEmpButton->mpTextBox[ramamam]->setString("Parry");
            //}
            //sprintf(sysConsolePtr->consoleLine[13].line, "AngleY: %d", linkActrPtr->mCurrent.mAngle.y);
            //sprintf(sysConsolePtr->consoleLine[8].line, "Jump Strike: %d, Mortal Draw: %d, Helm Splitter: %d", libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2a40), libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2a80), libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2901));
            //sprintf(sysConsolePtr->consoleLine[9].line, "Back  Slice: %d, Ending Blow: %d, Shield Attack: %d", libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2902), libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2904), libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0x2908));
            //sprintf(sysConsolePtr->consoleLine[10].line, "stage: %s", libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mStage);
            //sprintf(sysConsolePtr->consoleLine[12].line, "parryTheEnemy: %d", parryTheEnemy);
        //}
        return return_executee(linkActrPtr);
    }

    int32_t Mod::turnCutTheMove(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (linkActrPtr->m_nSwordBtk->mFrame >= 14.0f && saveInfoPtr->currentMeterValue != 0) {
            if (!spinGreatPlease) spinGreatPlease = true;
            consumeTheMeter = true;
        }
        return return_cutTurnMovee(linkActrPtr);
    }

    /*int32_t Mod::sideRollerDude(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t NamePleaseGive) {
        if (saveInfoPtr->parryOnOff || linkActrPtr->mTargetedActor == NULL) return return_sideRolling(linkActrPtr, NamePleaseGive);
        return 0;
    }

    int32_t Mod::turnMoveeDuude(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t ThinkDudee){
        if (saveInfoPtr->parryOnOff || parryTheEnemy) return return_turnDudeComeOn(linkActrPtr, ThinkDudee);
        return 0;
    }

    int32_t Mod::cutHeadInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (saveInfoPtr->parryOnOff || parryTheEnemy) {
            return return_cutHeadInit(linkActrPtr);
        }
        return 0;
    }*/

    bool mortalCapture = false;

    int32_t Mod::finalCutdown(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgOrNot) {
        if (!saveInfoPtr->parryOnOff) {
            if (smthgOrNot == 4) {
                //if (!parryTheEnemy) return 0;
                mortalCapture = true;
            }
        }
        return return_finalCutdown(linkActrPtr, smthgOrNot);
    }

    int32_t Mod::dudeTheDamageHurts(libtp::tp::d_a_alink::daAlink* linkActrPtr, void* objjjj, int32_t unnnnnk) {
#ifndef PLATFORM_WII
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20) crouch = 0;
#else
        if (dpaaadDown) crouch = 0;
#endif
        if (parryTheEnemy) parryToggle(false);
        return return_regularDamageHurts(linkActrPtr, objjjj, unnnnnk);
    }

    int32_t Mod::DamageThrownDude(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0, 
                                int32_t param1, int16_t param2, int16_t param3, void* param4, 
                                int32_t param5) {
        if (linkActrPtr->mProcID == 0x2D && !saveInfoPtr->parryOnOff) return 0;
#ifndef PLATFORM_WII
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20) crouch = 0;
#else
        if (dpaaadDown) crouch = 0;
#endif
        if (parryTheEnemy) parryToggle(false);
        return return_largeCutDamage(linkActrPtr, param0, param1, param2, param3, param4, param5);
    }

    int32_t Mod::guardHasBroke(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
#ifndef PLATFORM_WII
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mButtonFlags & 0x20) crouch = 0;
#else
        if (dpaaadDown) crouch = 0;
#endif
        if (parryTheEnemy) parryToggle(false);
        return return_breakThatGuardNow(linkActrPtr);
    }

    int32_t Mod::cutSpinChargeInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        linkActrPtr->mProcVar0.field_0x3008 = 14;
        return return_cutSpinChargeInit(linkActrPtr);
    }

    int32_t Mod::cutSpinInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aa, int32_t bb) {
/*#ifdef PLATFORM_WII
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].nunchuck_shake > 0.2f && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].wiimote_shake > 0.2f)
        {
            staminaConsumption(150, true, false);
            return return_cutSpinInit(linkActrPtr, aa, bb);
        }
        return 0;
#else*/
#ifdef PLATFORM_WII
        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentHealth == ((libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.maxHealth/5) * 4) && saveInfoPtr->currentMeterValue != 0)
#else
        if (spinGreatPlease)
#endif
            meterConsumption(32, false);
        return return_cutspinInitialized(linkActrPtr, aa, bb);
//#endif
    }

    int32_t Mod::sideStepOrElse(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t smthgAboutSideStepping) {
        if (parryTheEnemy) {dirRollParry = smthgAboutSideStepping; return 0;}
        return elseOrSideStep(linkActrPtr, smthgAboutSideStepping);
    }

    bool armorTimerFast = false;
    bool armorDamageTimeOrNo = false;

    // When TWW HD is toggled for Armor, this will be used when hit while wearing armor.
#ifndef PLATFORM_WII
    void armorRupeeLossHD(int16_t rupeeLostParam, cXyz LinkPosition, csXyz angle_positioned, cXyz theScale, int8_t theRoomCurrent) {
        uint8_t minussOrPlussWhichOneWillItBe;
        uint8_t HDHit = 0;
        if (rupeeLostParam > libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees)
            rupeeLostParam = libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees;
        while (rupeeLostParam > 0) {
            minussOrPlussWhichOneWillItBe = static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(2.0f));
            angle_positioned.y = static_cast<int16_t>(libtp::tp::d_a_alink::randVal(32767.0f));
            if (!minussOrPlussWhichOneWillItBe) angle_positioned.y = -angle_positioned.y;
            armorDamageTimeOrNo = true;
            armorTimerFast = true;
            if (rupeeLostParam > 100) {
                rupeeLostParam -= 100;
                HDHit = 6;
            } else if (rupeeLostParam > 50) {
                rupeeLostParam -= 50;
                HDHit =  5;
            } else if (rupeeLostParam > 20) {
                rupeeLostParam -= 20;
                HDHit = 4;
            } else if (rupeeLostParam > 10) {
                rupeeLostParam -= 10;
                HDHit = 3;
            } else if (rupeeLostParam > 5) {
                rupeeLostParam -= 5;
                HDHit = 2;
            } else {
                rupeeLostParam -= 1;
                HDHit = 1;
            }
                libtp::tp::f_op_actor_mng::fopAcM_fastCreateItem2(&LinkPosition, HDHit, -1, theRoomCurrent, -1, &angle_positioned, &theScale);
                HDHit = 0;
        }
    }
#endif

    int32_t Mod::damagetheSettingPointMaybe(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t a1, int32_t a2, int32_t a3, int32_t a4) {
        if (linkActrPtr->mProcID == 0x2D && !saveInfoPtr->parryOnOff) return 0;
#ifndef PLATFORM_WII
        if (libtp::tp::d_a_alink::checkMagicArmorNoDamage(linkActrPtr)) {
            if (saveInfoPtr->armorVer && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees != 0) {
                if (a1 > 0) {
                    float magnified_dmgF = static_cast<float>(a1) * libtp::tp::d_a_alink::damageMagnification(linkActrPtr, a2, a4);
                    int32_t magnified_dmg = magnified_dmgF;
                    if (static_cast<int32_t>(magnified_dmgF * 10.0f) % 10 != 0)
                        magnified_dmg++;
                    int16_t tempvarRupees = magnified_dmg*10;
                    //sprintf(sysConsolePtr->consoleLine[19].line, "rupeesLoss: %d", tempvarRupees);
                    cXyz create_pos = cXyzMultiply(cXyzAdd(linkActrPtr->mLeftHandPos, linkActrPtr->mRightHandPos), 0.5f);
                    csXyz angle_positioned = linkActrPtr->mCurrent.mAngle;
                    armorRupeeLossHD(tempvarRupees, create_pos, angle_positioned, linkActrPtr->mScale, libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mStartStage.mRoomNo);
                }
            }
        }
#endif
        return return_damageSetIt(linkActrPtr, a1, a2, a3, a4);
    }

    void Mod::lightMasterSwordChecking(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        bool lightVisualMoment = false;
        if (!saveInfoPtr->parryOnOff) {
            if (parryTheEnemy || linkActrPtr->mProcID == 0x20 || linkActrPtr->mProcID == 0x2D || mortalCapture || spinGreatPlease) {
                lightVisualMoment = true;
            }
        } else if (spinGreatPlease) lightVisualMoment = true;

        if (lightVisualMoment) {
            libtp::tp::d_a_player::onNoResetFlg3(linkActrPtr, libtp::tp::d_a_player::FLG3_UNK_100000);
            if (spinGreatPlease && linkActrPtr->mProcID != 0x2a) spinGreatPlease = false;
            if (mortalCapture && linkActrPtr->mProcID != 0x22) mortalCapture = false;
            if (linkActrPtr->mTargetedActor == NULL && parryTheEnemy) parryToggle(false);
            return;
        }

        return return_masterSwordLight(linkActrPtr);
    }

    void Mod::armorAppear(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0) {
        uint8_t tempThingy1;
        uint32_t tempThingy2;
        if (libtp::tp::d_a_alink::checkMagicArmorHeavy(linkActrPtr)) {
            param0 = 0;
            tempThingy1 = 5;
            tempThingy2 = 0x200D7;
        } else {
            param0 = 1;
            tempThingy1 = 4;
            tempThingy2 = 0x200BE;
        }
        if (seStartArmor) {
            libtp::tp::d_a_alink::seStartOnlyReverb(linkActrPtr, tempThingy2);
            libtp::tp::d_a_alink::setLinkState(&linkActrPtr->mZ2Link, tempThingy1);
            seStartArmor = false;
        }
        return return_armorAppear(linkActrPtr, param0);
    }

    void Mod::modelMetaSomethingSet(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0) {
#ifndef PLATFORM_WII
        if (saveInfoPtr->dPadChoice == 1 && libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0xD04)) {
            if (param0) static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531))->smthgTesting2("font_35.bti", 0);
            else static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531))->smthgTesting2("font_36.bti", 0);
        }
#endif
        return return_setModelMetamorph(linkActrPtr, param0);
    }

    uint8_t storeBuffer[3];

    void Mod::initializeTheOption(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
#ifndef PLATFORM_WII
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR)
#else
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x2000)
#endif
        {
            optionalRDetector = true;
            storeBuffer[0] = saveInfoPtr->armorVer; storeBuffer[1] = saveInfoPtr->parryOnOff; storeBuffer[2] = saveInfoPtr->dPadChoice;
            optionsMenuPtr->field_0x21c[0][0]->setString(option1);
            optionsMenuPtr->field_0x21c[0][1]->setString(option1);
            optionsMenuPtr->field_0x21c[1][0]->setString(option2);
            optionsMenuPtr->field_0x21c[1][1]->setString(option2);
            optionsMenuPtr->field_0x21c[2][0]->setString(option3);
            optionsMenuPtr->field_0x21c[2][1]->setString(option3);
            if (libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30335F6E)->checkVisible()) {
                libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30335F6E)->hideTex();
                libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30355F6E)->hideTex();
            }
        }

        return return_optionInitialize(optionsMenuPtr);
    }

    void Mod::stringAttentionDude(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (!optionalRDetector) return return_attenStringSet(optionsMenuPtr);

        if (saveInfoPtr->armorVer == 0) {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[0][0]->mWindow)->setString(option5);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[0][1]->mWindow)->setString(option5);
        }
        else {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[0][0]->mWindow)->setString(option4);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[0][1]->mWindow)->setString(option4);
        }
    }

    void Mod::stringVibCamDude(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (!optionalRDetector) return return_vibCamStringSet(optionsMenuPtr);

        if (saveInfoPtr->parryOnOff == 0) {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[1][0]->mWindow)->setString(option9);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[1][1]->mWindow)->setString(option9);
        }
        else {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[1][0]->mWindow)->setString(option10);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[1][1]->mWindow)->setString(option10);
        }
    }

    void Mod::stringSoundPointerDude(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (!optionalRDetector) return return_soundPointerStringSet(optionsMenuPtr);

        if (saveInfoPtr->dPadChoice == 0) {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[2][0]->mWindow)->setString(option6);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[2][1]->mWindow)->setString(option6);
        }
        else if (saveInfoPtr->dPadChoice == 1) {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[2][0]->mWindow)->setString(option7);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[2][1]->mWindow)->setString(option7);
        }
        else {
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[2][0]->mWindow)->setString(option8);
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[2][1]->mWindow)->setString(option8);
        }
    }

    void Mod::attentionMoving(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (!optionalRDetector) return return_attenMovee(optionsMenuPtr);
#ifndef PLATFORM_WII
        if ((libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x2000000) || (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x1000000))
#else
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick.x > 0.2f || libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick.x < -0.2f)
#endif
        {
            if (saveInfoPtr->armorVer == 1) saveInfoPtr->armorVer = 0;
            else saveInfoPtr->armorVer = 1;
        }

        return return_attenMovee(optionsMenuPtr);
    }

    void Mod::vibCamMoving(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (!optionalRDetector) return return_vibCamMovee(optionsMenuPtr);
#ifndef PLATFORM_WII
        if ((libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x2000000) || (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x1000000))
#else
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick.x > 0.2f || libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick.x < -0.2f)
#endif
        {
            if (saveInfoPtr->parryOnOff == 1) saveInfoPtr->parryOnOff = 0;
            else saveInfoPtr->parryOnOff = 1;
        }

        return return_vibCamMovee(optionsMenuPtr);
    }

    void Mod::soundPointerMoving(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (!optionalRDetector) return return_soundPointerMovee(optionsMenuPtr);
#ifndef PLATFORM_WII
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x2000000)
#else
        if (libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30335F6E)->checkVisible()) {
            libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30335F6E)->hideTex();
            libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30355F6E)->hideTex();
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[3][0]->mWindow)->setString("");
            ((libtp::tp::J2DTextBox::J2DTextBox*)optionsMenuPtr->mpMenuText[3][1]->mWindow)->setString("");
        }
        libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30335F6E)->hideTex();
        libtp::tp::J2DPane::searchhh(optionsMenuPtr->mpScreen, 0x6C65745F30355F6E)->hideTex();
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick.x > 0.2f)
#endif
        {
            if (saveInfoPtr->dPadChoice == 2) saveInfoPtr->dPadChoice = 0;
            else saveInfoPtr->dPadChoice++;
        }
#ifndef PLATFORM_WII
        else if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x1000000)
#else
        else if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick.x < -0.2f)
#endif
        {
            if (saveInfoPtr->dPadChoice == 0) saveInfoPtr->dPadChoice = 2;
            else saveInfoPtr->dPadChoice--;
        }

        return return_soundPointerMovee(optionsMenuPtr);
    }
#ifdef PLATFORM_WII
    void Mod::theShortCutInitializeed(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (optionalRDetector) {
            optionsMenuPtr->field_0x3ef = 2;
            libtp::tp::d_menu_option::pointer_init(optionsMenuPtr);
            return;
        }
        return return_shortCutInitialization(optionsMenuPtr);
    }

    void Mod::theCalibrationInitializeed(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (optionalRDetector) {
            optionsMenuPtr->field_0x3ef = 2;
            libtp::tp::d_menu_option::pointer_init(optionsMenuPtr);
            return;
        }
        return return_calibrationInitialization(optionsMenuPtr);
    }
#endif

    void Mod::closingConfirmation(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (optionalRDetector) {
            optionalRDetector = false;
            if (!infoTextCheck) {
                saveInfoPtr->armorVer = storeBuffer[0]; saveInfoPtr->parryOnOff = storeBuffer[1]; saveInfoPtr->dPadChoice = storeBuffer[2];
            } else {
#ifndef PLATFORM_WII
                if (saveInfoPtr->dPadChoice != storeBuffer[2]) {
                    if (saveInfoPtr->dPadChoice != 2) libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531)->showTex();
                    if (saveInfoPtr->dPadChoice == 0 && libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31))
                        static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531))->smthgTesting2("font_25.bti", 0);
                    else if (saveInfoPtr->dPadChoice == 1 && libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0xD04)) {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0) static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531))->smthgTesting2("font_36.bti", 0);
                        else static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531))->smthgTesting2("font_35.bti", 0);
                    }
                    else libtp::tp::J2DPane::searchhh(libtp::tp::d_meter2_info::g_meter2_info.mMeterClass->mpMeterDraw->mpScreen, 0x74737450616E6531)->hideTex();
                }
#endif
                if (saveInfoPtr->parryOnOff != storeBuffer[1]) {
                    if (!saveInfoPtr->parryOnOff) hiddenSkillMemories(true);
                    else hiddenSkillMemories(false);
                }
                if (saveInfoPtr->armorVer != storeBuffer[0]) {
                    if (!saveInfoPtr->armorVer)
#ifdef PLATFORM_WII
                        libtp::patch::writeBranch(armorSilence2 + 0x120, armorSilence2 + 0x170);
                    else performStaticASMReplacement(armorSilence2 + 0x120, 0x1C00000A);
#else
                        libtp::patch::writeBranch(armorSilence2 + 0x100, armorSilence2 + 0x14c);
                    else performStaticASMReplacement(armorSilence2 + 0x100, 0x1C00000A);
#endif
                }
            }
        }

        return return_closedConfirmation(optionsMenuPtr);
    }

    bool confirmationCheck = false;

    void Mod::moveInTheOptionsMenu(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        if (optionalRDetector) {
            if (!confirmationCheck) {
#ifndef PLATFORM_WII
                if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x100)
                {
                    libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags &= ~0x100;
                    libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags |= 0x200;
                    infoTextCheck = true;
                }
                else if (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x200)
#else
                if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x800)
                {
                    libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags &= ~0x800;
                    libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags |= 0x400;
                    infoTextCheck = true;
                }
                else if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 0x400)
#endif
                {
                    infoTextCheck = false;
                }
            }
        }

        return return_moveOptionsMenu(optionsMenuPtr);
    }

    void Mod::openingConfirmation(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        confirmationCheck = true;
        return_openConfirmation(optionsMenuPtr);
        if (optionalRDetector) {
            if (infoTextCheck) optionsMenuPtr->mpWarning->field_0x20->setString(infoText1);
            else optionsMenuPtr->mpWarning->field_0x20->setString(infoText2);
        }
    }

    void Mod::theClosingConfirmation(libtp::tp::d_menu_option::dMenu_Option_c* optionsMenuPtr) {
        confirmationCheck = false;
        return return_theClosedConfirmation(optionsMenuPtr);
    }

    void Mod::drawMeter2drawDraw(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) {
#ifndef PLATFORM_WII
        if (saveInfoPtr->dPadChoice == 1 && libtp::tp::d_save::isEventBit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.mEvent, 0xD04)) {
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0) static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(dMeterDrawPtr->mpScreen, 0x74737450616E6531))->smthgTesting2("font_36.bti", 0);
        }
        else if (saveInfoPtr->dPadChoice == 0 && libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31)) static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(dMeterDrawPtr->mpScreen, 0x74737450616E6531))->smthgTesting2("font_25.bti", 0);
        else libtp::tp::J2DPane::searchhh(dMeterDrawPtr->mpScreen, 0x74737450616E6531)->hideTex();
#endif
        return return_meter2Drawn(dMeterDrawPtr);
    }

    void Mod::buttonRDrawn(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t unk1, uint8_t i_action, bool unk2, bool unk3) {
        // prevent "Shield Attack" prompt from appearing on-screen since shield attack is with B button when parry off
        if (i_action == 58) return;
        return return_RDrawButton(dMeterDrawPtr, unk1, i_action, unk2, unk3);
    }

    void Mod::buttonADrawn(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t i_action, float i_posX, float i_posY, float i_textPosX, float i_textPosY, float i_scale, bool param_6, bool param_7) {
        /*if (!saveInfoPtr->parryOnOff) {
            if (i_action == 0x62) return;
        }*/
        if (parryTheEnemy && i_action != 0x2b) return;
        return return_ADrawButton(dMeterDrawPtr, i_action, i_posX, i_posY, i_textPosX, i_textPosY, i_scale, param_6, param_7);
    }

    void Mod::meterStringAndButton(libtp::tp::d_meter_button::dMeterButton_c* buttonMeterPtr, char* characteristics, uint8_t param0, uint8_t param1, uint8_t param2) {
        if (parryTheEnemy && param0 == 0)
#ifdef PLATFORM_WII
            {characteristics = parryChars; static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(buttonMeterPtr->mpButtonScreen, 0x615F62746E5F6332))->smthgTesting2(parryIconMiddle, 0); libtp::tp::J2DPane::searchhh(buttonMeterPtr->mpButtonScreen, 0x615f62746e)->hideTex();}
#else
            {characteristics = parryChars; static_cast<libtp::tp::J2DPicture::J2DPicture*>(libtp::tp::J2DPane::searchhh(buttonMeterPtr->mpButtonScreen, 0x615F62746E31))->smthgTesting2(parryIconMiddle, 0); libtp::tp::J2DPane::searchhh(buttonMeterPtr->mpButtonScreen, 0x615f62746e5f6c31)->hideTex();}
#endif
        return return_meterButtonString(buttonMeterPtr, characteristics, param0, param1, param2);
    }

    /*libtp::tp::d_meter2_draw::dMeter2Draw_c* Mod::drawElimination(void* abcdabcd) {
        libtp::tp::d_meter2_draw::dMeter2Draw_c* smthggggg = return_elimateReading(abcdabcd);

        if (smthggggg) {
            delete testSomethingComeOn;
            testSomethingComeOn = NULL;
            sprintf(sysConsolePtr->consoleLine[17].line, "AMONGUS");
        }
        return smthggggg;
    }*/

    /*int32_t Mod::cutLargeJumpChargeInit(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (saveInfoPtr->parryOnOff == 0 && !parryTheEnemy) return libtp::tp::d_a_alink::procCutJumpInit(linkActrPtr, 0);
        return return_cutLargeJumpChargeInit(linkActrPtr);
    }

    int32_t Mod::guardBattle(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (saveInfoPtr->parryOnOff == 0) return 0;
        return return_guardBattle(linkActrPtr);
    }*/

    void Mod::linkHasChanged(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0) {
        if ((!saveInfoPtr->armorVer && saveInfoPtr->currentMeterValue != 0) || (saveInfoPtr->armorVer && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees != 0)) armorExpired = false;
        else armorExpired = true;
        seStartArmor = false;
        /*if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 1) {
            sprintf(sysConsolePtr->consoleLine[8].line, "AAAAAAAA");
            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.equipment[0] == 0x30) libtp::tp::d_com_inf_game::setSelectEquipClothes(0x2f);
        }*/
        linkChanged(linkActrPtr, param0);
        if ((!saveInfoPtr->armorVer && saveInfoPtr->currentMeterValue != 0) || (saveInfoPtr->armorVer && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentRupees != 0)) armorExpired = true; else armorExpired = false;
    }

    /*int32_t Mod::crawllllingMove(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR)
        return crawllllMoveee(linkActrPtr);
        libtp::tp::d_a_alink::procCrawlEndInit(linkActrPtr, 1, linkActrPtr->mCollisionRot.x, linkActrPtr->mCollisionRot.z);
        return 0;
    }

    int32_t Mod::crawlingFinale(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0, int16_t param1, int16_t param2) {
        if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR)
        return 0;
        return crawlFinale(linkActrPtr, param0, param1, param2);
    }*/

    /*void recoverMeterFunc(uint8_t recoveryAmmmo) {
        if (save)
    }*/

    void Mod::exeGetNextOne(libtp::tp::d_a_obj_item::daItem_c* itemThingPtr) {
        //sprintf(sysConsolePtr->consoleLine[20].line, "waitTimer: %d", itemThingPtr->mWaitTimer);
#ifdef PLATFORM_WII
        if (itemThingPtr->field_0x92e == 0x801 || itemThingPtr->field_0x92e == 0x901)
#else
        if (itemThingPtr->m_itemNo == 8 || itemThingPtr->m_itemNo == 9)
#endif
        {
            meterFuelTime = 32;
            libtp::tp::d_a_obj_item::procInitSimpleGetDemo(itemThingPtr);
#ifdef PLATFORM_WII
            if (itemThingPtr->field_0x92e == 0x901)
#else
            if (itemThingPtr->m_itemNo == 9)
#endif
                meterFuelTime = 64;
            libtp::tp::m_Do_Audio::mDoAud_seStart(0x18, 0, 0, 0);
        }
        return return_getTheNextExe(itemThingPtr);
    }

    void Mod::itemDropIsInitialized(libtp::tp::d_a_obj_item::daItem_c* itemThingPtr) {
        return_initializingItemDrop(itemThingPtr);
        if (armorTimerFast) {itemThingPtr->mDisappearTimer = 45; itemThingPtr->mWaitTimer = 0; armorTimerFast = false;}
    }

    void* Mod::actorMustMakeNOW(const cXyz* pos, int32_t itemNo, int32_t itemBitNo, int32_t roomNo, int32_t param5, const csXyz* actrRot, const cXyz* actrScale) {
        //sprintf(sysConsolePtr->consoleLine[21].line, "%x, %x, %x, %d, %d, %d, %.1f, %.1f, %.1f",itemNo, itemBitNo, param5, actrRot->x, actrRot->y, actrRot->z, actrScale->x, actrScale->y, actrScale->z);
        if (!armorDamageTimeOrNo) {
            if (itemNo < 8 || (itemNo > 13 && itemNo < 19) || itemNo == 0x1f) {
                uint8_t whichOneGonnaBe = static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(3.0f));
                if (whichOneGonnaBe == 2) {
                    uint8_t whichOneGonnaBeRound2 = static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(3.0f));
                    if (whichOneGonnaBeRound2 < 2) itemNo = 8; else itemNo = 9;
                }
            }
        }
        else armorDamageTimeOrNo = false;
        return return_createActorFastPlease(pos, itemNo, itemBitNo, roomNo, param5, actrRot, actrScale);
    }

    void Mod::onRELUnlink(libtp::tp::dynamic_link::DynamicModuleControl* dmc) {
        using namespace libtp::tp::rel::relIDs;
        switch (dmc->mModule->id) {
            // Enemy Arrow
            /*case D_A_E_ARROW:
            {
                return_e_arrow_wait = libtp::patch::unhookFunction(return_e_arrow_wait);
                sprintf(sysConsolePtr->consoleLine[addressDetective].line, "AAAAAAAAAAAyy"); addressDetective++;
                break;
            }*/
            // Aeralfos
            case D_A_B_GG:
            {
                return_b_gg_anmSet = libtp::patch::unhookFunction(return_b_gg_anmSet);
                return_b_gg_attackF = libtp::patch::unhookFunction(return_b_gg_attackF);
                return_b_gg_attackG = libtp::patch::unhookFunction(return_b_gg_attackG);
                break;
            }
            // Ganondorf
            case D_A_B_GND:
            {
                return_b_gnd_initAnm = libtp::patch::unhookFunction(return_b_gnd_initAnm);
                return_b_gnd_attack = libtp::patch::unhookFunction(return_b_gnd_attack);
                break;
            }
            // Dark Nut
            case D_A_B_TN:
            {
#ifndef PLATFORM_WII
                return_b_tn_bckSet = libtp::patch::unhookFunction(return_b_tn_bckSet);
#endif
                return_b_tn_attackH = libtp::patch::unhookFunction(return_b_tn_attackH);
                return_b_tn_attackL = libtp::patch::unhookFunction(return_b_tn_attackL);
                break;
            }
            // Keese
            case D_A_E_BA:
            {
                return_e_ba_initAnm = libtp::patch::unhookFunction(return_e_ba_initAnm);
                return_e_ba_attack = libtp::patch::unhookFunction(return_e_ba_attack);
                break;
            }
            // Bubble
            /*case D_A_E_BU:
            {
                return_e_bu_initAnm = libtp::patch::unhookFunction(return_e_bu_initAnm);
                return_e_bu_attack = libtp::patch::unhookFunction(return_e_bu_attack);
                break;
            }*/
            // Dodongo
            case D_A_E_DD:
            {
                return_e_dd_initAnm = libtp::patch::unhookFunction(return_e_dd_initAnm);
                return_e_dd_attack = libtp::patch::unhookFunction(return_e_dd_attack);
                break;
            }
            // Lizalfos
            case D_A_E_DN:
            {
                return_e_dn_initAnm = libtp::patch::unhookFunction(return_e_dn_initAnm);
                return_e_dn_attack = libtp::patch::unhookFunction(return_e_dn_attack);
                return_e_dn_attackStab = libtp::patch::unhookFunction(return_e_dn_attackStab);
                return_e_dn_attackSpin = libtp::patch::unhookFunction(return_e_dn_attackSpin);
                break;
            }
            // Chilfos
            case D_A_E_KK:
            {
                return_e_kk_bckSet = libtp::patch::unhookFunction(return_e_kk_bckSet);
                return_e_kk_attack = libtp::patch::unhookFunction(return_e_kk_attack);
                break;
            }
            // Dynalfos
            case D_A_E_MF:
            {
                return_e_mf_initAnm = libtp::patch::unhookFunction(return_e_mf_initAnm);
                return_e_mf_attack = libtp::patch::unhookFunction(return_e_mf_attack);
                return_e_mf_attackSpin = libtp::patch::unhookFunction(return_e_mf_attackSpin);
                break;
            }
            // Bokoblin
            case D_A_E_OC:
            {
                return_e_oc_attack = libtp::patch::unhookFunction(return_e_oc_attack);
#ifndef PLATFORM_WII
                return_e_oc_bckSet = libtp::patch::unhookFunction(return_e_oc_bckSet);
#else
                return_e_oc_execute = libtp::patch::unhookFunction(return_e_oc_execute);
#endif
                //return_e_oc_actionSet = libtp::patch::unhookFunction(return_e_oc_actionSet);
                break;
            }
            // Bulblin
            case D_A_E_RD:
            {
                return_e_rd_initAnm = libtp::patch::unhookFunction(return_e_rd_initAnm);
                return_e_rd_attack = libtp::patch::unhookFunction(return_e_rd_attack);
                break;
            }
            // Stalfos
            case D_A_E_SF:
            {
                return_e_sf_initAnm = libtp::patch::unhookFunction(return_e_sf_initAnm);
#ifdef PLATFORM_WII
                return_e_sf_execute = libtp::patch::unhookFunction(return_e_sf_execute);
#else
                return_e_sf_attack0 = libtp::patch::unhookFunction(return_e_sf_attack0);
                return_e_sf_attack = libtp::patch::unhookFunction(return_e_sf_attack);
#endif
                break;
            }
            // Skulltula
            case D_A_E_ST:
            {
                return_e_st_initAnm = libtp::patch::unhookFunction(return_e_st_initAnm);
                return_e_st_attack = libtp::patch::unhookFunction(return_e_st_attack);
                break;
            }
            // Moldorm
            case D_A_E_SW:
            {
                return_e_sw_attack = libtp::patch::unhookFunction(return_e_sw_attack);
#ifdef PLATFORM_WII
                return_e_sw_execute = libtp::patch::unhookFunction(return_e_sw_execute);
#else
                return_e_sw_setBck = libtp::patch::unhookFunction(return_e_sw_setBck);
#endif
                break;
            }
            // Tektite
            case D_A_E_TT:
            {
#ifndef PLATFORM_WII
                return_e_tt_bckSet = libtp::patch::unhookFunction(return_e_tt_bckSet);
#endif
                return_e_tt_attack = libtp::patch::unhookFunction(return_e_tt_attack);
                break;
            }
            // Sword Guy
            case D_A_E_VT:
            {
                return_e_vt_attackOpaci = libtp::patch::unhookFunction(return_e_vt_attackOpaci);
#ifdef PLATFORM_WII
                return_e_vt_execute = libtp::patch::unhookFunction(return_e_vt_execute);
#else
                return_e_vt_bckSet = libtp::patch::unhookFunction(return_e_vt_bckSet);
#endif
                break;
            }
            // White Wolfos
            case D_A_E_WW:
            {
#ifndef PLATFORM_WII
                return_e_ww_bckSet = libtp::patch::unhookFunction(return_e_ww_bckSet);
#else
                return_e_ww_execute = libtp::patch::unhookFunction(return_e_ww_execute);
#endif
                return_e_ww_attack = libtp::patch::unhookFunction(return_e_ww_attack);
                break;
            }
            // Midna
            case D_A_MIDNA:
            {
                daMidna_c__checkMetamorphoseEnableBase = nullptr;
                break;
            }
        }
    }

    __attribute__((used, visibility("default"))) bool Mod::handle_do_unlink(libtp::tp::dynamic_link::DynamicModuleControl* dmc)
    {
        onRELUnlink(dmc);
        return return_do_unlink(dmc);
    }

    int32_t Mod::checkTheTurnMove(libtp::tp::d_a_alink::daAlink* linkActrPtr) {
        if (!saveInfoPtr->parryOnOff) {
            libtp::tp::d_a_player::daPy_frameCtrl_c* temp_r30 = &linkActrPtr->mUnderFrameCtrl[0];
            if (temp_r30->mFrame > libtp::tp::d_a_alink::turnMoveVars.mTwirlCutDelayF) {
                libtp::tp::d_a_alink::procCutFinishJumpUpInit(linkActrPtr);
                libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayerStatus[0][0] |= 4;
                return 1;
            }
        }
        return turnMoveChecking(linkActrPtr);
    }

    /*void* Mod::creatureVoiceEnemyy(void* enemySoundPtr, uint32_t* sfxID, int8_t smthgUnk) {
        sprintf(sysConsolePtr->consoleLine[9].line, "sfxID: %x", *sfxID);
        return return_creatureVoiceEnemy(enemySoundPtr, sfxID, smthgUnk);
    } */

    libtp::tp::f_op_actor::fopAc_ac_c* id;
    uint8_t tiimer = 0;
    uint8_t tiiimer = 0;
    uint8_t countyer = 0;
    uint8_t trimer = 0;
    uint8_t bombytimer = 0;
    bool greenLight = false;
    bool timestartt = false;
    uint8_t padingTimer = 0;

    void Mod::meterValuee(libtp::tp::d_meter2::dMeter2_c* dMeterPtr) {
        if ((dMeterPtr->mStatus & 0x40) == 0 && !gameplayStatus) gameplayStatus = true;
        else if ((dMeterPtr->mStatus & 0x40) != 0 && gameplayStatus) gameplayStatus = false;
        /*if (libtp::tp::d_meter2_info::g_meter2_info.mMenuWindowClass->mpMenuOption != nullptr) {
            strcpy(sysConsolePtr->consoleLine[3].line, "Waltuh");
        }
        else {
            strcpy(sysConsolePtr->consoleLine[3].line, "Jessie");
        }*/
        if (gameplayStatus) {
#ifdef PLATFORM_WII
            if (dpaaadDown && (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x2000) == 0 && (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5 || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C || (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID > 0x34 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 0x39) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x71))
#else
            if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR && libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockL == 0 && (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5 || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C || (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID > 0x34 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 0x39) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x71))
#endif
            {
                if (crouch == 0) {
                    libtp::tp::d_a_alink::procCrouchInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
                    crouch = 1;
                }
#ifdef PLATFORM_WII
                else if (shieldCrouch == false && crouch == 1 && libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].stick_amplitude > 0.2f)
#else
                else if (shieldCrouch == false && crouch == 1 && libtp::tp::m_do_controller_pad::cpadInfo[0].mMainStickValue > 0.2f)
#endif
                {
                    libtp::tp::d_a_alink::procCrawlStartInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
                    crouch = 2;
                }
            } else if (crouch != 0 && crouch != 2 && (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5 || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C)) {
                libtp::tp::d_a_alink::checkNextActionFromCrouch(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, 0);
                crouch = 0;
                shieldCrouch = false;
            } else if (crouch == 2 && (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID < 5 || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID == 0x1C)) crouch = 0;

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
                    if (dpaaadDown)
#else
                    if (libtp::tp::m_do_controller_pad::cpadInfo[0].mHoldLockR)
#endif
                    {
                        libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID = 0x1D;
                        libtp::tp::d_a_alink::procCrouchInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
                    }
                }
            }

            /*if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mEquipItem == 0x46 && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 0x400)) {
                libtp::tp::d_a_alink::procCopyRodSwingInit(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer);
            }*/
            if (!saveInfoPtr->armorVer) {
                if (libtp::tp::d_a_alink::checkMagicArmorNoDamage(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer) && uiChecking) {
                    consumeTheMeter = true;
                    meterConsumption(15, true);
                }
            }
        }

        return valueOfMeter(dMeterPtr);
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
        if ((libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 0x00004000) == 0 && !dpaaadDown)
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

        if (linkActrPtr->mEquipItem == 0xE3) {
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
                    if (libtp::tp::d_bg_s_acch::ChkGroundHit(&linkActrPtr->mLinkAcch) == false && saveInfoPtr->currentMeterValue >= 10) {
                        sussy = (libtp::tp::f_op_actor::fopAc_ac_c*)libtp::tp::f_op_actor_mng::fopAcM_fastCreate(temporar, 0, &create_pos, -1, NULL, NULL, 0xff, NULL, NULL);
                        cuccoWait = true;
                        grabRemember = true;
                        linkActrPtr->mProcID = 0xA;
                        libtp::tp::d_a_alink::procAutoJumpInit(linkActrPtr, 0);
                        saveInfoPtr->currentMeterValue -= 15;
                        countDownMeter = 50;
                    }
                    else {linkActrPtr->mEquipItem = 0xFF; return 0;}

                if (sussy != NULL) {
                    libtp::tp::d_a_alink::setGrabItemActor(linkActrPtr, sussy);
                    linkActrPtr->field_0x33e4 = 38.0f;
                    libtp::tp::d_a_alink::setGrabUpperAnime(linkActrPtr, libtp::tp::d_a_alink::something.m.mAnmBlendFactor);
                }
            }
            linkActrPtr->mEquipItem = 0xFF;
            return 1;
        }

        return cuccoMoment(linkActrPtr);
    }

    void Mod::UICheck(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) {

        if (sussy != NULL && grabRemember) {
            consumeTheMeter = true;
            meterConsumption(15, true);
            if (libtp::tp::d_bg_s_acch::ChkGroundHit(&libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mLinkAcch) || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mGrabItemAcKeep.mActor == NULL || saveInfoPtr->currentMeterValue == 0) {libtp::tp::f_op_actor_mng::fopAcM_delete(sussy); grabRemember = false;}
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
        
        if (saveInfoPtr->dPadChoice == 0) {
#ifdef PLATFORM_WII
            if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31) && bomba == false && dpaaadRight && countyer < 2 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0)
#else
            if (libtp::tp::d_com_inf_game::dComIfGs_isItemFirstBit(0x31) && bomba == false && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 4) && countyer < 2 && libtp::tp::d_com_inf_game::dComIfG_gameInfo.save.save_file.player.player_status_a.currentForm == 0)
#endif
            {
                bamba = true;
                countyer++;
            }
        }
#ifndef PLATFORM_WII
        else if (saveInfoPtr->dPadChoice == 1 && (libtp::tp::m_do_controller_pad::cpadInfo[0].mPressedButtonFlags & 4)) handleQuickTransform();
#else
        else if (saveInfoPtr->dPadChoice == 1 && dpaaadRight) handleQuickTransform();
#endif
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
        if (meterFuelTime) {
            if (saveInfoPtr->currentMeterValue + 5 > 255) {saveInfoPtr->currentMeterValue = 255; meterFuelTime = 0;}
            else {
                saveInfoPtr->currentMeterValue += 5;
                meterFuelTime -= 5;
                if (meterFuelTime < 0) meterFuelTime = 0;
                libtp::tp::m_Do_Audio::mDoAud_seStartLevel(0x22, NULL, 0, 0);
            }
        }
        //sprintf(sysConsolePtr->consoleLine[2].line, "mProcID: %x", libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mProcID);
        if (!uiChecking) uiChecking = true;
        return healthUIOn(dMeterDrawPtr);
    }
    
    void Mod::UIOff(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) {
        if (uiChecking) uiChecking = false;
        return healthUIOff(dMeterDrawPtr);
    }

    bool Mod::procDoLink(libtp::tp::dynamic_link::DynamicModuleControl* dmc)
    {
        using namespace libtp::tp::rel::relIDs;
        // Call the original function immediately, as the REL file needs to be linked before applying patches
        const bool result = do_link_trampoline(dmc);

        // Get the pointer to the current REL file
        libtp::gc_wii::os_module::OSModuleInfo* modulePtr = dmc->mModule;

        // Make sure a REL file is actually loaded, as do_link will clear the pointer if something goes wrong
        if (!modulePtr)
        {
            return result;
        }

        // Get the REL pointer as a raw u32, to use for overwrites
        uint32_t relPtrRaw = reinterpret_cast<uint32_t>(modulePtr);

        // Modify the current REL file
        switch (modulePtr->id)     // May want to set up enums or defines for the module ids
        {
            // Puppet Zelda
            //case D_A_E_HZELDA:
            //{
                //sprintf(sysConsolePtr->consoleLine[0].line, "relPtrRaw: %x", relPtrRaw+0xA94);
                // nop out the greater than branch so that Zelda will always throw a Ball if she is able to
                //performStaticASMReplacement(relPtrRaw + 0xA94, ASM_NOP); // Previous: bge

                // nop out the addition of f1 (the random number of frames) to f0 (the base number of frames) so that there is
                // always only 100 frames between each of Zelda's attacks.
                //performStaticASMReplacement(relPtrRaw + 0x8EC, ASM_NOP); // Previous: bfadds f0,f0,f1
                //break;
            //}
            // Treasure Chests
            //case D_A_TBOX:
            //{
                //sprintf(sysConsolePtr->consoleLine[0].line, "relPtrRaw: %x", relPtrRaw+0xA58);
                // Nop out the bne- that causes chests to play the cutscene for big items.
                //performStaticASMReplacement(relPtrRaw + 0xA58, ASM_NOP);
                //performStaticASMReplacement(relPtrRaw + 0xA5C, 0x38600001);
                //break;
            //}
            // Aeralfos
            case D_A_B_GG:
            {
                return_b_gg_anmSet =
                    libtp::patch::hookFunction(reinterpret_cast<daB_gg_anmSet>(relPtrRaw + gg_b_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* bGgPtr, int32_t param0, int32_t param1, float param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == bGgPtr) {
                            //sprintf(sysConsolePtr->consoleLine[16].line, "param0: %d", param0);
                            if (param0 == 16) paramCapture = 2;
                            else if (param0 == 15 || param0 == 17) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_b_gg_anmSet(bGgPtr, param0, param1, param2, param3);
                    });
                return_b_gg_attackF =
                    libtp::patch::hookFunction(reinterpret_cast<daB_gg_attackF>(relPtrRaw + gg_b_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* bGgPtr)
                    {
                        if (paramCapture)
                            parryAttack(bGgPtr, 1);
                        return_b_gg_attackF(bGgPtr);
                    });
                return_b_gg_attackG =
                    libtp::patch::hookFunction(reinterpret_cast<daB_gg_attackG>(relPtrRaw + gg_b_address[2]), [](libtp::tp::f_op_actor::fopEn_enemy_c* bGgPtr)
                    {
                        if (paramCapture)
                            parryAttack(bGgPtr, paramCapture-1);
                        return_b_gg_attackG(bGgPtr);
                    });
                break;
            }
            // Ganondorf
            case D_A_B_GND:
            {
                return_b_gnd_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daB_gnd_initAnm>(relPtrRaw + gnd_b_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eGndPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eGndPtr) {
                            //sprintf(sysConsolePtr->consoleLine[16].line, "param0: %d", param0);
                            if (param0 == 20) paramCapture = 1;
                            //else if (param0 == 31 || param0 == 30 || param0 == 25 || param0 == 19) paramCapture = 2;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_b_gnd_initAnm(eGndPtr, param0, param1, param2, param3);
                    });
                return_b_gnd_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daB_gnd_attack>(relPtrRaw + gnd_b_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eGndPtr)
                    {
                        if (paramCapture)
                            parryAttack(eGndPtr, paramCapture-1);
                        return_b_gnd_attack(eGndPtr);
                    });
                break;
            }
            // Dark Nut
            case D_A_B_TN:
            {
                return_b_tn_attackH =
                    libtp::patch::hookFunction(reinterpret_cast<daB_tn_attackH>(relPtrRaw + tn_b_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* bTnPtr)
                    {
                        //uint8_t randomParry = static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(2.0f));
                        //if (randomParry == 0) performStaticASMReplacement(relPtrRaw + 0x6CA0, ASM_NOP);
#ifdef PLATFORM_WII
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == bTnPtr) {
                            if (!parryMiiPlease) {parryMiiPlease = true; strcpy(isItMiiOrNot, "B_tn");}
                        }
#endif
                        if (paramCapture)
                            parryAttack(bTnPtr, paramCapture-1);
                        return_b_tn_attackH(bTnPtr);
                    });
                return_b_tn_attackL =
                    libtp::patch::hookFunction(reinterpret_cast<daB_tn_attackL>(relPtrRaw + tn_b_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* bTnPtr)
                    {
#ifdef PLATFORM_WII
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == bTnPtr) {
                            if (!parryMiiPlease) {parryMiiPlease = true; strcpy(isItMiiOrNot, "B_tn");}
                        }
#endif
                        if (paramCapture)
                            parryAttack(bTnPtr, paramCapture-1);
                        return_b_tn_attackL(bTnPtr);
                    });
#ifndef PLATFORM_WII
                return_b_tn_bckSet =
                    libtp::patch::hookFunction(reinterpret_cast<daB_tn_bckSet>(relPtrRaw + 0x1E9C), [](libtp::tp::f_op_actor::fopEn_enemy_c* bTnPtr, int32_t param_0, uint8_t param_1, float param_2, float param_3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == bTnPtr) {
                            //sprintf(sysConsolePtr->consoleLine[7].line, "param0: %d", param_0);
                            // horizontal/diagonal attack
                            if (param_0 == 5 || param_0 == 21) paramCapture = 2;
                            // vertical/forward attack
                            else if (param_0 == 6 || param_0 == 20) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        //parryAttack(libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer, bTnPtr, static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(2.0f)));
                        return_b_tn_bckSet(bTnPtr, param_0, param_1, param_2, param_3);
                    });
#endif
                // Modify armor amount that darknut loses per hit
                /*performStaticASMReplacement(relPtrRaw + 0x34AC, 0x38a0000c);
                performStaticASMReplacement(relPtrRaw + 0x36B4, 0x38a0000c);
                performStaticASMReplacement(relPtrRaw + 0x3708, 0x38a0000c);
                performStaticASMReplacement(relPtrRaw + 0x3880, 0x38a0000c);
                performStaticASMReplacement(relPtrRaw + 0x38EC, 0x38a0000c);*/
                break;
            }
            // Bokoblin
            case D_A_E_OC:
            {
                //sprintf(sysConsolePtr->consoleLine[5].line, "address: 0x%x", relPtrRaw + 0x3ae4);
                // Total Health
                //performStaticASMReplacement(relPtrRaw + 0x8D0C, 0x380001F4);
                return_e_oc_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_oc_attack>(relPtrRaw + oc_e_address), [](libtp::tp::f_op_actor::fopEn_enemy_c* eOcPtr)
                    {
#ifdef PLATFORM_WII
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eOcPtr) {
                            attackCapture = true;
                        }
                        if (attackCapture)
#else
                        if (paramCapture)
#endif
                            parryAttack(eOcPtr, paramCapture-1);
                        return_e_oc_attack(eOcPtr);
                    });
#ifndef PLATFORM_WII
                return_e_oc_bckSet =
                    libtp::patch::hookFunction(reinterpret_cast<daE_oc_bckSet>(relPtrRaw + 0x1E68), [](libtp::tp::f_op_actor::fopEn_enemy_c* eOcPtr, int32_t param0, uint8_t param1, float param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eOcPtr) {
                            // vertical attack
                            if (param0 == 5) paramCapture = 1;
                            // horizontal attack
                            else if (param0 == 6) paramCapture = 2;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_oc_bckSet(eOcPtr, param0, param1, param2, param3);
                    });
#else
                return_e_oc_execute =
                    libtp::patch::hookFunction(reinterpret_cast<daE_oc_execute>(relPtrRaw + 0x79D0), [](libtp::tp::f_op_actor::fopEn_enemy_c* eOcPtr)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eOcPtr) {
                            if (attackCapture) {attackCapture = false; paramCapture = static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(2.0f)) + 1;}
                            else if (parryTheEnemy) {
                                parryToggle(false);
                            }
                        }
                        return_e_oc_execute(eOcPtr);
                    });
#endif
                //performStaticASMReplacement(relPtrRaw + 0x364, 0x4BFFD949);
                // Damage when attacking
                //performStaticASMReplacement(relPtrRaw + 0x7FF8, 0x4BFFCD21);
                // Parry player's attack
                //performStaticASMReplacement(relPtrRaw + 0x8004, 0x4BFFC1B1);
                break;
            }
            // Bulblin
            case D_A_E_RD:
            {
                return_e_rd_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_rd_initAnm>(relPtrRaw + rd_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eRdPtr, int32_t param_0, float param_1, uint8_t param_2, float param_3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eRdPtr) {
                            //sprintf(sysConsolePtr->consoleLine[1].line, "param1: %f", param_1);
                            if (param_1 == 6.0f) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        return_e_rd_initAnm(eRdPtr, param_0, param_1, param_2, param_3);
                    });
                //sprintf(sysConsolePtr->consoleLine[1].line, "relPtrRaw: %x", relPtrRaw + 0x734);
                return_e_rd_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_rd_attack>(relPtrRaw + rd_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eRdPtr)
                    {
                        if (paramCapture)
                            parryAttack(eRdPtr, static_cast<uint8_t>(libtp::tp::d_a_alink::randVal(2.0f)));
                        return_e_rd_attack(eRdPtr);
                    });
                break;
            }
            // Dodongo
            case D_A_E_DD:
            {
                return_e_dd_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_dd_initAnm>(relPtrRaw + dd_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eDdPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eDdPtr) {
                            if (param0 == 14) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        return_e_dd_initAnm(eDdPtr, param0, param1, param2, param3);
                    });
                return_e_dd_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_dd_attack>(relPtrRaw + dd_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eDdPtr)
                    {
                        if (paramCapture)
                            parryAttack(eDdPtr, 0);
                        return_e_dd_attack(eDdPtr);
                    });
                break;
            }
            // Lizalfos
            case D_A_E_DN:
            {
                return_e_dn_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_dn_initAnm>(relPtrRaw + dn_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eDnPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eDnPtr) {
                            if (param0 == 4 || param0 == 5 || param0 == 8) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        return_e_dn_initAnm(eDnPtr, param0, param1, param2, param3);
                    });
                return_e_dn_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_dn_attack>(relPtrRaw + dn_e_address[2]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eDnPtr)
                    {
                        if (paramCapture)
                            parryAttack(eDnPtr, 0);
                        return_e_dn_attack(eDnPtr);
                    });
                return_e_dn_attackStab =
                    libtp::patch::hookFunction(reinterpret_cast<daE_dn_attackStab>(relPtrRaw + dn_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eDnPtr)
                    {
                        if (paramCapture)
                            parryAttack(eDnPtr, 0);
                        return_e_dn_attackStab(eDnPtr);
                    });
                return_e_dn_attackSpin =
                    libtp::patch::hookFunction(reinterpret_cast<daE_dn_attackSpin>(relPtrRaw + dn_e_address[3]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eDnPtr)
                    {
                        if (paramCapture)
                            parryAttack(eDnPtr, 1);
                        return_e_dn_attackSpin(eDnPtr);
                    });
                break;
            }
            // Chilfos
            case D_A_E_KK:
            {
                return_e_kk_bckSet =
                    libtp::patch::hookFunction(reinterpret_cast<daE_kk_bckSet>(relPtrRaw + kk_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eKkPtr, int32_t param0, uint8_t param1, float param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eKkPtr) {
                            if (param0 == 5) paramCapture = 2;
                            else if (param0 == 6) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_kk_bckSet(eKkPtr, param0, param1, param2, param3);
                    });
                return_e_kk_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_kk_attack>(relPtrRaw + kk_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eKkPtr)
                    {
                        if (paramCapture)
                            parryAttack(eKkPtr, paramCapture-1);
                        return_e_kk_attack(eKkPtr);
                    });
                break;
            }
            // Dynalfos
            case D_A_E_MF:
            {
                return_e_mf_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_mf_initAnm>(relPtrRaw + mf_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eMfPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eMfPtr) {
                            if (param0 == 5 || param0 == 8) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        return_e_mf_initAnm(eMfPtr, param0, param1, param2, param3);
                    });
                return_e_mf_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_mf_attack>(relPtrRaw + mf_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eMfPtr)
                    {
                        if (paramCapture)
                            parryAttack(eMfPtr, 0);
                        return_e_mf_attack(eMfPtr);
                    });
                return_e_mf_attackSpin =
                    libtp::patch::hookFunction(reinterpret_cast<daE_mf_attackSpin>(relPtrRaw + mf_e_address[2]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eMfPtr)
                    {
                        if (paramCapture)
                            parryAttack(eMfPtr, 1);
                        return_e_mf_attackSpin(eMfPtr);
                    });
                break;
            }
            // Keese
            case D_A_E_BA:
            {
                return_e_ba_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_ba_initAnm>(relPtrRaw + ba_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eBaPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eBaPtr) {
                            if (param0 == 6) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        return_e_ba_initAnm(eBaPtr, param0, param1, param2, param3);
                    });
                return_e_ba_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_ba_attack>(relPtrRaw + ba_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eBaPtr)
                    {
                        //if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eBaPtr)
                            //sprintf(sysConsolePtr->consoleLine[5].line, "keeseAnm: %d", eBaPtr->mAnm);
                        //sprintf(sysConsolePtr->consoleLine[6].line, "zpos: %f", eBaPtr->mHeadLockPos.z);
                        if (paramCapture)
                            parryAttack(eBaPtr, 2);
                        return_e_ba_attack(eBaPtr);
                    });
                break;
            }
            // Bubble
            /*case D_A_E_BU:
            {
                sprintf(sysConsolePtr->consoleLine[6].line, "address: %x", relPtrRaw+bu_e_address[0]);
                return_e_bu_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_bu_initAnm>(relPtrRaw + bu_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eBuPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eBuPtr) {
                            if (param0 == 7) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_bu_initAnm(eBuPtr, param0, param1, param2, param3);
                    });
                return_e_bu_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_bu_attack>(relPtrRaw + bu_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eBuPtr)
                    {
                        parryAttack(eBuPtr, 2);
                        return_e_bu_attack(eBuPtr);
                    });
                break;
            }*/
            // Stalfos
            case D_A_E_SF:
            {
                return_e_sf_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sf_initAnm>(relPtrRaw + sf_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSfPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eSfPtr) {
                            //sprintf(sysConsolePtr->consoleLine[17].line, "param0: %d", param0);
                            if (param0 == 4) paramCapture = 1;
                            else if (param0 == 5) paramCapture = 2;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_sf_initAnm(eSfPtr, param0, param1, param2, param3);
                    });
#ifdef PLATFORM_WII
                return_e_sf_execute =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sf_execute>(relPtrRaw + sf_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSfPtr)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eSfPtr) {
                            if (paramCapture)
                                parryAttack(eSfPtr, paramCapture-1);
                        }
                        return_e_sf_execute(eSfPtr);
                    });
#else
                return_e_sf_attack0 =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sf_attack0>(relPtrRaw + sf_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSfPtr)
                    {
                        if (paramCapture)
                            parryAttack(eSfPtr, 1);
                        return_e_sf_attack0(eSfPtr);
                    });
                return_e_sf_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sf_attack>(relPtrRaw + sf_e_address[2]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSfPtr)
                    {
                        if (paramCapture)
                            parryAttack(eSfPtr, 0);
                        return_e_sf_attack(eSfPtr);
                    });
#endif
                break;
            }
            // Skulltula
            case D_A_E_ST:
            {
                //sprintf(sysConsolePtr->consoleLine[16].line, "address: %x", relPtrRaw + 0x4408);
                return_e_st_initAnm =
                    libtp::patch::hookFunction(reinterpret_cast<daE_st_initAnm>(relPtrRaw + st_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eStPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eStPtr) {
                            if (param0 == 6) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_st_initAnm(eStPtr, param0, param1, param2, param3);
                    });
                return_e_st_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_st_attack>(relPtrRaw + st_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eStPtr)
                    {
                        //sprintf(sysConsolePtr->consoleLine[12].line, "spider: x: %.2f, y: %.2f, z: %.2f", eStPtr->mHeadLockPos.x, eStPtr->mHeadLockPos.y, eStPtr->mHeadLockPos.z);
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eStPtr) {
                            if (paramCapture)
                                parryAttack(eStPtr, 1);
                        }
                        return_e_st_attack(eStPtr);
                    });
                break;
            }
            // Moldorm
            case D_A_E_SW:
            {
                //sprintf(sysConsolePtr->consoleLine[15].line, "address: %x", relPtrRaw + 0xD4);
                return_e_sw_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sw_attack>(relPtrRaw + sw_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSwPtr)
                    {
#ifndef PLATFORM_WII
                        if (paramCapture)
#else
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eSwPtr) {
                            attackCapture = true;
                        }
                        if (attackCapture)
#endif
                            parryAttack(eSwPtr, 2);
                        return_e_sw_attack(eSwPtr);
                    });
#ifdef PLATFORM_WII
                return_e_sw_execute =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sw_execute>(relPtrRaw + sw_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSwPtr)
                    {
                        if (attackCapture) attackCapture = false;
                        else if (parryTheEnemy) {
                            if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eSwPtr || libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == NULL)
                                parryToggle(false);
                        }
                        return_e_sw_execute(eSwPtr);
                    });
#else
                return_e_sw_setBck =
                    libtp::patch::hookFunction(reinterpret_cast<daE_sw_setBck>(relPtrRaw + sw_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eSwPtr, int32_t param0, float param1, uint8_t param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eSwPtr) {
                            if (param0 == 6) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_sw_setBck(eSwPtr, param0, param1, param2, param3);
                    });
#endif
                break;
            }
            // Tektite
            case D_A_E_TT:
            {
#ifndef PLATFORM_WII
                return_e_tt_bckSet =
                    libtp::patch::hookFunction(reinterpret_cast<daE_tt_bckSet>(relPtrRaw + 0x4f4), [](libtp::tp::f_op_actor::fopEn_enemy_c* eTtPtr, int32_t param0, uint8_t param1, float param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eTtPtr) {
                            if (param0 == 3) paramCapture = 1;
                            else if (parryTheEnemy) {parryToggle(false);}
                        }
                        return_e_tt_bckSet(eTtPtr, param0, param1, param2, param3);
                    });
#endif
                return_e_tt_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_tt_attack>(relPtrRaw + tt_e_address), [](libtp::tp::f_op_actor::fopEn_enemy_c* eTtPtr)
                    {
                        //sprintf(sysConsolePtr->consoleLine[17].line, "procName: %x", eTtPtr->mProcName);
#ifdef PLATFORM_WII
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eTtPtr) {
                            if (!parryMiiPlease) {parryMiiPlease = true; strcpy(isItMiiOrNot, "E_TT");}
                        }
#endif
                        if (paramCapture)
                            parryAttack(eTtPtr, 1);
                        return_e_tt_attack(eTtPtr);
                    });
                break;
            }
            // Sword Guy
            case D_A_E_VT:
            {
                return_e_vt_attackOpaci =
                    libtp::patch::hookFunction(reinterpret_cast<daE_vt_attackOpaci>(relPtrRaw + vt_e_address[1]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eVtPtr)
                    {
#ifndef PLATFORM_WII
                        if (paramCapture)
#else
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eVtPtr) {
                            attackCapture = true;
                        }
                        if (attackCapture)
#endif
                            parryAttack(eVtPtr, 0);
                        return_e_vt_attackOpaci(eVtPtr);
                    });
#ifdef PLATFORM_WII
                return_e_vt_execute =
                    libtp::patch::hookFunction(reinterpret_cast<daE_vt_execute>(relPtrRaw + vt_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eVtPtr)
                    {
                        if (attackCapture) attackCapture = false;
                        else if (parryTheEnemy) parryToggle(false);
                        return_e_vt_execute(eVtPtr);
                    });
#else
                return_e_vt_bckSet =
                    libtp::patch::hookFunction(reinterpret_cast<daE_vt_bckSet>(relPtrRaw + vt_e_address[0]), [](libtp::tp::f_op_actor::fopEn_enemy_c* eVtPtr, int32_t param0, uint8_t param1, float param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eVtPtr) {
                            if (param0 == 18) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_vt_bckSet(eVtPtr, param0, param1, param2, param3);
                    });
#endif
                break;
            }
            // White Wolfos
            case D_A_E_WW:
            {
                //sprintf(sysConsolePtr->consoleLine[15].line, "address: %x", relPtrRaw + 0xDC);
#ifndef PLATFORM_WII
                return_e_ww_bckSet =
                    libtp::patch::hookFunction(reinterpret_cast<daE_ww_bckSet>(relPtrRaw + 0x5B0), [](libtp::tp::f_op_actor::fopEn_enemy_c* eWwPtr, int32_t param0, uint8_t param1, float param2, float param3)
                    {
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eWwPtr) {
                            if (param0 == 9) paramCapture = 1;
                            else if (parryTheEnemy) parryToggle(false);
                        }
                        return_e_ww_bckSet(eWwPtr, param0, param1, param2, param3);
                    });
#else
                return_e_ww_execute =
                    libtp::patch::hookFunction(reinterpret_cast<daE_ww_execute>(relPtrRaw + 0x530C), [](libtp::tp::f_op_actor::fopEn_enemy_c* eWwPtr)
                    {
                        //sprintf(sysConsolePtr->consoleLine[19].line, "attackCapture: %d", attackCapture);
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eWwPtr) {
                            if (attackCapture) attackCapture = false;
                            else if (parryTheEnemy) {
                                parryToggle(false);
                            }
                        }
                        return_e_ww_execute(eWwPtr);
                    });
#endif
                return_e_ww_attack =
                    libtp::patch::hookFunction(reinterpret_cast<daE_ww_attack>(relPtrRaw + ww_e_address), [](libtp::tp::f_op_actor::fopEn_enemy_c* eWwPtr)
                    {
#ifndef PLATFORM_WII
                        if (paramCapture)
#else
                        if (libtp::tp::d_com_inf_game::dComIfG_gameInfo.play.mPlayer->mTargetedActor == eWwPtr) {
                            attackCapture = true;
                        }
                        if (attackCapture)
#endif
                            parryAttack(eWwPtr, 2);
                        return_e_ww_attack(eWwPtr);
                    });
                break;
            }
            // Midna
            case D_A_MIDNA:
            {
#ifdef PLATFORM_WII
                daMidna_c__checkMetamorphoseEnableBase =
                    reinterpret_cast<daMidna_checkMetamorphoseEnableBase_Def>(relPtrRaw + 0x7A7C);
#else
                daMidna_c__checkMetamorphoseEnableBase =
                    reinterpret_cast<daMidna_checkMetamorphoseEnableBase_Def>(relPtrRaw + 0x8A0C);
#endif
                break;
            }
            default:
            {
                break;
            }
        }

        return result;
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
                mMeterDraw->mMeterAlphaRate[0] = 0.0f;
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
            if (uiCheckingStart)
                drawMMeter(dMeterDrawPtr, 255, saveInfoPtr->currentMeterValue, xPosition, 20.0f, true);
            else {
                pretendMeterValue += 5;
                if (pretendMeterValue >= saveInfoPtr->currentMeterValue) {
                    pretendMeterValue = saveInfoPtr->currentMeterValue;
                    uiCheckingStart = true;
                }
                drawMMeter(dMeterDrawPtr, 255, pretendMeterValue, xPosition, 20.0f, true);
                libtp::tp::m_Do_Audio::mDoAud_seStartLevel(0x22, NULL, 0, 0);
            }
        } else {
            drawMMeter(dMeterDrawPtr, 255, saveInfoPtr->currentMeterValue, xPosition, 20.0f, false);
        }
        libtp::tp::d_meter2_draw::drawKanteraScreen(dMeterDrawPtr, 0);
    }

    __attribute__((used, visibility("default"))) void Mod::performStaticASMReplacement(uint32_t memoryOffset, uint32_t value)
    {
        *reinterpret_cast<uint32_t*>(memoryOffset) = value;

        // Clear the cache for the modified value
        // Assembly instructions need to clear the instruction cache as well
        libtp::memory::clear_DC_IC_Cache(reinterpret_cast<uint32_t*>(memoryOffset), sizeof(uint32_t));
    }

    bool customItemOrNo = false;

    int32_t Mod::reeadTheItemTexture(libtp::tp::d_meter2_info::G_Meter2_Info* g_meter2_info_ptr, uint8_t itemNo, void* param_1, 
                                libtp::tp::J2DPicture::J2DPicture* param_2, void* param_3, 
                                libtp::tp::J2DPicture::J2DPicture* param_4, void* param_5, 
                                libtp::tp::J2DPicture::J2DPicture* param_6, void* param_7, 
                                libtp::tp::J2DPicture::J2DPicture* param_8, int32_t param_9) {

        //if (itemNo == 0xE3 && customItemOrNo == false)
        if (itemNo == 0xE3)
#ifdef PLATFORM_WII
        {
            if (!customItemOrNo) {
                customItemOrNo = true;
                //sprintf(sysConsolePtr->consoleLine[7].line, "Yes!");
                libtp::patch::writeBranch(readIconsTex + 0x54, readIconsTex + 0x78);
                performStaticASMReplacement(readIconsTex + 0x8C, 0x38c0001e);
            }
        } else if (customItemOrNo) {
            customItemOrNo = false;
            //sprintf(sysConsolePtr->consoleLine[7].line, "No!");
            performStaticASMReplacement(readIconsTex + 0x54, 0x28000048);
            performStaticASMReplacement(readIconsTex + 0x8C, 0x38c00023);
        }
#else
        {
            if (!customItemOrNo) {
                customItemOrNo = true;
                //sprintf(sysConsolePtr->consoleLine[7].line, "Yes!");
                libtp::patch::writeBranch(readIconsTex + 0x58, readIconsTex + 0x80);
                performStaticASMReplacement(readIconsTex + 0x94, 0x38c0001e);
            }
        } else if (customItemOrNo) {
            customItemOrNo = false;
            //sprintf(sysConsolePtr->consoleLine[7].line, "No!");
            performStaticASMReplacement(readIconsTex + 0x58, 0x28000048);
            performStaticASMReplacement(readIconsTex + 0x94, 0x38c00023);
        }
#endif

        return return_itemTextureRead(g_meter2_info_ptr, itemNo, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
    }
#ifdef PLATFORM_WII
    void Mod::procNewFrame() {
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags & 2) {
            if (saveInfoPtr->dPadChoice != 2) {
                libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags = 0;
                dpaaadRight = true;
            }
        } else if (dpaaadRight) dpaaadRight = false;
        
        if (libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags & 4) {
            libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mButtonFlags = 0;
            if (!dpaaadDown) {dpaaadDown = true; libtp::tp::m_re_controller_pad::mReCPd::m_pad[0].mPressedButtonFlags = 0;}
        } else if (dpaaadDown) dpaaadDown = false;
        return return_constFrameThing();
    }
#endif
}     // namespace mod