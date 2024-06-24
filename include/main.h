/**
 * @file main.h
 * @author Captain Kitty Cat (youtube.com/@captainkittyca2)
 * @brief
 * @version 0.2
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include <display/console.h>
#include <tp/f_ap_game.h>
#include <tp/d_a_alink.h>
#include <tp/d_meter2.h>
#include <tp/d_bg_s_acch.h>
#include <tp/d_stage.h>

#include <cinttypes>

namespace mod
{
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
        void ( *buttonRBigMad)(libtp::tp::d_meter2_draw::dMeter2Draw_c* thingy, uint8_t, uint8_t, bool, bool) = nullptr;
        bool ( *cuccoMoment)(libtp::tp::d_a_alink::daAlink* linkActrPtr) = nullptr;
        int32_t ( *buttonRRRRR)(void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data) = nullptr;

        libtp::tp::d_a_alink::daAlink_BckData* manualShield(libtp::tp::d_a_alink::daAlink* linkActrPtr, libtp::tp::d_a_alink::daAlink_ANM i_anmID);
        /**
         * @brief checks if heart UI is on for first frame
         * 
         * @param dMeterPtr A pointer to the current dMeter2 structure.
        */
        void UICheck(libtp::tp::d_meter2_draw::dMeter2Draw_c* dMeterDrawPtr);
        void unSheathingShield(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        void buttonRWhy(libtp::tp::d_meter2_draw::dMeter2Draw_c* thingy, uint8_t, uint8_t, bool, bool);
        bool cuccoCheckMoment(libtp::tp::d_a_alink::daAlink* linkActrPtr);
        int32_t buttonRExists(void* stageDt, libtp::tp::d_stage::stage_dzr_header_entry* i_data, int32_t num, void* raw_data);
    };
}     // namespace mod
