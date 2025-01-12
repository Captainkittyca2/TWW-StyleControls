/**
 * @file main.h
 * @author Captain Kitty Cat (youtube.com/@captainkittyca2)
 * @brief
 * @version 0.3
 * @date 2025-01-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <display/console.h>
#include <tp/d_a_obj_item.h>
#include <tp/f_ap_game.h>
#include <tp/dynamic_link.h>
#include <tp/d_meter2_info.h>
#include <tp/d_bg_s_acch.h>
#include <tp/d_stage.h>

#include <cinttypes>

#define ASM_NOP (0x60000000)

namespace mod
{
    typedef bool (*daMidna_checkMetamorphoseEnableBase_Def)(void*);
#ifndef PLATFORM_WII
    typedef void (*daB_tn_bckSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, uint8_t, float, float);
    typedef void (*daE_oc_bckSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, uint8_t, float, float);
    typedef void (*daE_tt_bckSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, uint8_t, float, float);
    typedef void (*daE_ww_bckSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, uint8_t, float, float);
    typedef void (*daE_sf_attack0)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_sf_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_sw_setBck)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_vt_bckSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, uint8_t, float, float);
#else
    typedef void (*daE_oc_execute)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_sf_execute)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_sw_execute)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_vt_execute)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_ww_execute)(libtp::tp::f_op_actor::fopEn_enemy_c*);
#endif
    typedef void (*daB_gnd_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daB_gnd_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daB_gg_anmSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, int32_t, float, float);
    typedef void (*daB_gg_attackF)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daB_gg_attackG)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daB_tn_attackH)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daB_tn_attackL)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_ba_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_ba_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    //typedef void (*daE_bu_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    //typedef void (*daE_bu_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_dd_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_dd_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_dn_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_dn_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_dn_attackStab)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_dn_attackSpin)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_kk_bckSet)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, uint8_t, float, float);
    typedef void (*daE_kk_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_mf_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_mf_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_mf_attackSpin)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_oc_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_rd_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_rd_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_sf_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_st_initAnm)(libtp::tp::f_op_actor::fopEn_enemy_c*, int32_t, float, uint8_t, float);
    typedef void (*daE_st_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_sw_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_tt_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_vt_attackOpaci)(libtp::tp::f_op_actor::fopEn_enemy_c*);
    typedef void (*daE_ww_attack)(libtp::tp::f_op_actor::fopEn_enemy_c*);

    void main();
    class Mod
    {
       public:
        Mod();
        void init();

       private:
        // Console
        libtp::display::Console c;
        // "trampoline/return" function to the original function that we hook in order to proc our NewFrame function
        libtp::tp::d_a_alink::daAlink_BckData* ( *return_fapGm_Execute )(libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID) = nullptr;
        void ( *healthUIOn)(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) = nullptr;
        void ( *unSheathShield)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        //void ( *buttonRBigMad)(libtp::tp::d_meter2_draw::dMeter2Draw_c* thingy, uint8_t, uint8_t, bool, bool) = nullptr;
        void ( *valueOfMeter)(libtp::tp::d_meter2::dMeter2_c* dMeterPtr) = nullptr;
        void ( *return_drawMeter2)(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) = nullptr;
        void ( *healthUIOff)(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr) = nullptr;
        void ( *linkChanged)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param_0) = nullptr;
        void ( *return_armorAppear)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t) = nullptr;
        void ( *return_masterSwordLight)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        void ( *return_optionInitialize)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_attenStringSet)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_vibCamStringSet)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_soundPointerStringSet)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_attenMovee)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_vibCamMovee)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_soundPointerMovee)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_closedConfirmation)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_moveOptionsMenu)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_theClosedConfirmation)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_openConfirmation)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_meter2Drawn)(libtp::tp::d_meter2_draw::dMeter2Draw_c*) = nullptr;
        void ( *return_RDrawButton)(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t unk1, uint8_t i_action, bool unk2, bool unk3) = nullptr;
        void ( *return_ADrawButton)(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t, float, float, float, float, float, bool, bool) = nullptr;
        void ( *return_meterButtonString)(libtp::tp::d_meter_button::dMeterButton_c*, char*, uint8_t, uint8_t, uint8_t) = nullptr;
        void ( *return_setModelMetamorph)(libtp::tp::d_a_alink::daAlink*, int32_t) = nullptr;
        void ( *return_getTheNextExe)(libtp::tp::d_a_obj_item::daItem_c*) = nullptr;
        void ( *return_initializingItemDrop)(libtp::tp::d_a_obj_item::daItem_c*) = nullptr;
        void ( *return_eventBitWasOn)(libtp::tp::d_save::dSv_event_c*, uint16_t) = nullptr;
        void* ( *return_createActorFastPlease)(const cXyz*, int32_t, int32_t, int32_t, int32_t, const csXyz*, const cXyz*) = nullptr;
        void ( *return_gameSceneChanged)(void*) = nullptr;
        bool ( *cuccoMoment)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *initMap)(void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data) = nullptr;
        int32_t ( *crawlFinale)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param_0, int16_t param_1, int16_t param_2) = nullptr;
        int32_t ( *turnMoveChecking)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *atnActorMoveTrampoline)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        //int32_t ( *atnActorWaitTrampoline)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *crawllllMoveee)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *return_executee)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        //int32_t ( *return_cutLargeJumpChargeInit)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *return_cutTurnMovee)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        //int32_t ( *return_guardBattle)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *return_cutSpinChargeInit)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *return_cutspinInitialized)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aa, int32_t bb) = nullptr;
        //int32_t ( *return_sideRolling)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t) = nullptr;
        //int32_t ( *return_turnDudeComeOn)(libtp::tp::d_a_alink::daAlink*, int32_t) = nullptr;
        //int32_t ( *return_cutHeadInit)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        //int32_t ( *return_cutHead)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *return_regularDamageHurts)(libtp::tp::d_a_alink::daAlink* linkActrPtr, void*, int32_t) = nullptr;
        int32_t ( *return_largeCutDamage)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0,
                                int32_t param1, int16_t param2, int16_t param3, void* param4,
                                int32_t param5) = nullptr;
        int32_t ( *return_damageSetIt)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t a1, int32_t a2, int32_t a3, int32_t a4) = nullptr;
        int32_t ( *elseOrSideStep)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t) = nullptr;
        int32_t ( *return_finalCutdown)(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t) = nullptr;
        //int32_t ( *return_jumpCutJumpInit)(libtp::tp::d_a_alink::daAlink*) = nullptr;
        int32_t ( *return_breakThatGuardNow)(libtp::tp::d_a_alink::daAlink*) = nullptr;
        int32_t ( *return_jumpAttackSomething)(libtp::tp::d_a_alink::daAlink*, int32_t) = nullptr;
        int32_t ( *return_itemTextureRead)(libtp::tp::d_meter2_info::G_Meter2_Info*, uint8_t itemNo, void* param_1, 
                                libtp::tp::J2DPicture::J2DPicture* param_2, void* param_3, 
                                libtp::tp::J2DPicture::J2DPicture* param_4, void* param_5, 
                                libtp::tp::J2DPicture::J2DPicture* param_6, void* param_7, 
                                libtp::tp::J2DPicture::J2DPicture* param_8, int32_t param_9) = nullptr;
        //libtp::tp::d_meter2_draw::dMeter2Draw_c* ( *return_elimateReading)(void*) = nullptr;
        bool ( *return_do_unlink)(libtp::tp::dynamic_link::DynamicModuleControl* dmc) = nullptr;
        bool ( *do_link_trampoline)(libtp::tp::dynamic_link::DynamicModuleControl* dmc) = nullptr;

        libtp::tp::d_a_alink::daAlink_BckData* manualShield(libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID);
        /**
         * @brief checks if heart UI is on for first frame
         * 
         * @param dMeterPtr A pointer to the current dMeter2 structure.
        */
        void UICheck(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr);
        void UIOff(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr);
        void unSheathingShield(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        void buttonRWhy(libtp::tp::d_meter2_draw::dMeter2Draw_c* thingy, uint8_t, uint8_t, bool, bool);
        void performStaticASMReplacement(uint32_t memoryOffset, uint32_t value);
        void onRELUnlink(libtp::tp::dynamic_link::DynamicModuleControl* dmc);
        void meterValuee(libtp::tp::d_meter2::dMeter2_c* dMeterPtr);
        void drawMeter2( libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr);
        void linkHasChanged(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param_0);
        void armorAppear(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t);
        void lightMasterSwordChecking(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        void initializeTheOption(libtp::tp::d_menu_option::dMenu_Option_c*);
        void stringAttentionDude(libtp::tp::d_menu_option::dMenu_Option_c*);
        void stringVibCamDude(libtp::tp::d_menu_option::dMenu_Option_c*);
        void stringSoundPointerDude(libtp::tp::d_menu_option::dMenu_Option_c*);
        void attentionMoving(libtp::tp::d_menu_option::dMenu_Option_c*);
        void vibCamMoving(libtp::tp::d_menu_option::dMenu_Option_c*);
        void soundPointerMoving(libtp::tp::d_menu_option::dMenu_Option_c*);
#ifdef PLATFORM_WII
        void ( *return_constFrameThing)() = nullptr;
        void ( *return_shortCutInitialization)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        void ( *return_calibrationInitialization)(libtp::tp::d_menu_option::dMenu_Option_c*) = nullptr;
        //void ( *return_nunButtonDrawn)(libtp::tp::d_meter2_draw::dMeter2Draw_c*, uint8_t) = nullptr;
        void* ( *return_resWiiHaveGot)(const char*, int32_t, libtp::tp::d_resource::dRes_info_c*, int32_t) = nullptr;
        uint8_t ( *return_itemNoChecking)(int32_t) = nullptr;
        void procNewFrame();
        void theShortCutInitializeed(libtp::tp::d_menu_option::dMenu_Option_c*);
        void theCalibrationInitializeed(libtp::tp::d_menu_option::dMenu_Option_c*);
        //void buttonNunWillDrawIt(libtp::tp::d_meter2_draw::dMeter2Draw_c*, uint8_t);
        void* wiiHaveTheResEveryone(const char*, int32_t, libtp::tp::d_resource::dRes_info_c*, int32_t);
        uint8_t itemIsBeingChecked(int32_t);
#endif
        void closingConfirmation(libtp::tp::d_menu_option::dMenu_Option_c*);
        void moveInTheOptionsMenu(libtp::tp::d_menu_option::dMenu_Option_c*);
        void theClosingConfirmation(libtp::tp::d_menu_option::dMenu_Option_c*);
        void openingConfirmation(libtp::tp::d_menu_option::dMenu_Option_c*);
        void drawMeter2drawDraw(libtp::tp::d_meter2_draw::dMeter2Draw_c*);
        void buttonRDrawn(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr, uint8_t unk1, uint8_t i_action, bool unk2, bool unk3);
        void buttonADrawn(libtp::tp::d_meter2_draw::dMeter2Draw_c*, uint8_t, float, float, float, float, float, bool, bool);
        void meterStringAndButton(libtp::tp::d_meter_button::dMeterButton_c*, char*, uint8_t, uint8_t, uint8_t);
        void modelMetaSomethingSet(libtp::tp::d_a_alink::daAlink*, int32_t);
        void exeGetNextOne(libtp::tp::d_a_obj_item::daItem_c*);
        void itemDropIsInitialized(libtp::tp::d_a_obj_item::daItem_c*);
        void bitTheEventOnOn(libtp::tp::d_save::dSv_event_c*, uint16_t);
        void* actorMustMakeNOW(const cXyz*, int32_t, int32_t, int32_t, int32_t, const csXyz*, const cXyz*);
        void gameSceneChanged(void*);
        bool handle_do_unlink(libtp::tp::dynamic_link::DynamicModuleControl* dmc);
        bool procDoLink(libtp::tp::dynamic_link::DynamicModuleControl* dmc );
        bool cuccoCheckMoment(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t mapInitialized(void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data);
        int32_t crawlingFinale(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param_0, int16_t param_1, int16_t param_2);
        int32_t checkTheTurnMove(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t atnActorMove(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        //int32_t atnActorWait(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t crawllllingMove(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t crawlMoveStuff(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t executee(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        //int32_t cutLargeJumpChargeInit(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t turnCutTheMove(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        //int32_t guardBattle(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t cutSpinChargeInit(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t cutSpinInit(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t aa, int32_t bb);
        //int32_t sideRollerDude(libtp::tp::d_a_alink::daAlink*, int32_t);
        //int32_t turnMoveeDuude(libtp::tp::d_a_alink::daAlink*, int32_t);
        //int32_t cutHeadInit(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t cutHead(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t dudeTheDamageHurts(libtp::tp::d_a_alink::daAlink* linkActrPtr, void*, int32_t);
        int32_t DamageThrownDude(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t param0, 
                                int32_t param1, int16_t param2, int16_t param3, void* param4, 
                                int32_t param5);
        int32_t damagetheSettingPointMaybe(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t a1, int32_t a2, int32_t a3, int32_t a4);
        int32_t sideStepOrElse(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t);
        int32_t finalCutdown(libtp::tp::d_a_alink::daAlink* linkActrPtr, int32_t);
        //int32_t cutJumpInitialized(libtp::tp::d_a_alink::daAlink*);
        int32_t jumpAndAttackInit(libtp::tp::d_a_alink::daAlink*, int32_t);
        int32_t guardHasBroke(libtp::tp::d_a_alink::daAlink*);
        int32_t reeadTheItemTexture(libtp::tp::d_meter2_info::G_Meter2_Info*, uint8_t itemNo, void* param_1, 
                                libtp::tp::J2DPicture::J2DPicture* param_2, void* param_3, 
                                libtp::tp::J2DPicture::J2DPicture* param_4, void* param_5, 
                                libtp::tp::J2DPicture::J2DPicture* param_6, void* param_7, 
                                libtp::tp::J2DPicture::J2DPicture* param_8, int32_t param_9);
        //libtp::tp::d_meter2_draw::dMeter2Draw_c* drawElimination(void*);
    };
}     // namespace mod